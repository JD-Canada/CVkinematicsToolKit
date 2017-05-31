// Local resources
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detection.h"

// OpenCV
#include <opencv2/opencv.hpp>

// Qt libs
#include <QFileDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <QImage>
#include <typeinfo>
#include <QLabel>
#include <QThread>

// c++ std libs
#include <string>

Detection * worker;

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
// Initialize UI
    ui->setupUi(this);

// Initialize new logData object
    worker = new Detection(this);
// Move to worker thread
    QThread* workerThread = new QThread;
    worker->moveToThread(workerThread);

// Link singal/slots between threads
    QObject::connect(this ,
                     SIGNAL(loadVideo(string)),
                     worker,
                     SLOT(videoLoad(short, unsigned long, short,
                                                unsigned long, unsigned long,
                                       short, PicoLogger*,
                                       short, short, short, short)));
    QObject::connect(worker ,SIGNAL(stopLogging(QString)), this,
                     SLOT(stopLogging(QString)));
    QObject::connect(worker,SIGNAL(loggingTimer(QString)), this,
                     SLOT(loggingTimer(QString)));

// Add statusbar widgets
    statusMouseX = new QLabel(this);
    statusMouseX->setText(QString("x: "));
    statusMouseX->setObjectName(QString("mouseX"));
    statusBar()->addPermanentWidget(statusMouseX);
    statusMouseY = new QLabel(this);
    statusMouseY->setText(QString("y: "));
    statusMouseY->setObjectName(QString("mouseY"));
    statusBar()->addPermanentWidget(statusMouseY);
    statusMode= new QLabel(this);
    statusMode->setText(QString("Mode: Navigate"));
    statusBar()->addPermanentWidget(statusMode);

    // Set up event filters for user input (capture key presses and clicks)
    ui->jumpFrame->installEventFilter(this);
    ui->frame->installEventFilter(this);

    // Set mode
    Mode = Mode_NAVIGATE;
}

// Deconstructor
MainWindow::~MainWindow()
{
   emit shutdown();
}

void MainWindow::on_loadVideo_clicked()
{
    // Get video location
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Video"), "/home/", tr("Video Files (*.mp4 *.avi)")).toStdString();

    // Load first frame
    frameCurrent= 0;

    // Load dummy background
    backgroundClicks[4] = 0;
    backgroundDefined = false;
}

void MainWindow::keyPressEvent(QKeyEvent * event){
    if (frameCurrent == -1){
        ui->statusBar->showMessage(QString("No video loaded!"));
        return;
    }

    /**********************************************************
     * Keyboard controls are different depending on UI mode
     **********************************************************/

    switch(Mode){
    case Mode_NAVIGATE:
        switch(event->key()){
        case Qt::Key_Z: frameCurrent  = frameCurrent - 1;
            loadFrame(frameCurrent);break;
        case Qt::Key_X: frameCurrent  = frameCurrent + 1;
            loadFrame(frameCurrent);break;
        case Qt::Key_A:  frameCurrent  = frameCurrent - 10;
            loadFrame(frameCurrent);break;
        case Qt::Key_S:  frameCurrent  = frameCurrent + 10;
            loadFrame(frameCurrent);break;
        case Qt::Key_Q:  frameCurrent  = frameCurrent - 100;
            loadFrame(frameCurrent);break;
        case Qt::Key_W:  frameCurrent  = frameCurrent + 100;
            loadFrame(frameCurrent);break;
        case Qt::Key_1:  frameCurrent  = frameCurrent - 1000;
            loadFrame(frameCurrent);break;
        case Qt::Key_2:  frameCurrent  = frameCurrent + 1000;
            loadFrame(frameCurrent);break;
        }
        break;
    case Mode_BACKGROUND:
        switch(event->key()){
        case Qt::Key_Z: frameCurrent  = frameCurrent - 1;break;
        case Qt::Key_X: frameCurrent  = frameCurrent + 1;break;
        case Qt::Key_A:  frameCurrent  = frameCurrent - 10;break;
        case Qt::Key_S:  frameCurrent  = frameCurrent + 10;break;
        case Qt::Key_Q:  frameCurrent  = frameCurrent - 100;break;
        case Qt::Key_W:  frameCurrent  = frameCurrent + 100;break;
        case Qt::Key_1:  frameCurrent  = frameCurrent - 1000;break;
        case Qt::Key_2:  frameCurrent  = frameCurrent + 1000;break;
        }
        loadFrame(frameCurrent);break;
    }
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
        if (obj == ui->jumpFrame) {
            // Check if key press
            if (event->type() == QEvent::KeyPress) {
                QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
                // Check that ENTER is pressed
                if(keyEvent->key() == Qt::Key_Enter){
                    // Save value, and clear and unfocus jumpToFrame EditText
                    frameCurrent = ui->jumpFrame->toPlainText().toLong();
                    ui->jumpFrame->setText(QString());
                    this->focusWidget()->clearFocus();
                    // Load new frame
                    checkCurrentFrame();
                    loadFrame();
                    return(true);
                }
            }
            // Pass event to parent
            return QMainWindow::eventFilter(obj, event);
        }else if(obj == ui->frame){
            switch(Mode){
            case Mode_NAVIGATE:
                if (event->type() == QEvent::MouseButtonPress) {
                    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                    // Check that Mouse button 1 is pressed
                    if(mouseEvent->button() == Qt::LeftButton){
                        // Show position in status bar
                        QPoint point = mouseEvent->pos();
                        statusMouseX->setText("x: " + QString::number(point.x()));
                        statusMouseY->setText("y: " + QString::number(point.y()));
                        return(true);
                    }
                }
                // Pass event to parent
                return QMainWindow::eventFilter(obj, event);
                break;
            case Mode_BACKGROUND:
                if (event->type() == QEvent::MouseButtonPress) {
                    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                    // Check that Mouse button 1 is pressed
                    if(mouseEvent->button() == Qt::LeftButton){
                        // Show position in status bar
                        QPoint point = mouseEvent->pos();
                        statusMouseX->setText("x: " + QString::number(point.x()));
                        statusMouseY->setText("y: " + QString::number(point.y()));
                        // Log points in memory
                        switch(static_cast<int>(backgroundClicks[4])){
                        // Background click positions are saved as scaled x,y, coords x = (0,1), y = (0,1)
                        // This avoids the error due to the mouse grabbing the position in the scaled display image, as opposed to the
                        // position of the full size video frame.
                        case 0:
                            backgroundClicks[0] = (double) point.x() / (double) ui->frame->size().width();
                            backgroundClicks[1] = (double) point.y() / (double) ui->frame->size().height();
                            backgroundClicks[2] = 1;
                            break;
                        case 1:
                            backgroundClicks[0] = (double)point.x() / (double) ui->frame->size().width();
                            backgroundClicks[1] = (double) point.y() / (double) ui->frame->size().height();
                            backgroundClicks[2] = 0;
                            ui->frame->setCursor(Qt::ArrowCursor);
                            setBackground(backgroundClicks[0],backgroundClicks[1],backgroundClicks[4]);
                            statusBar()->showMessage(QString("Move until the fish is out the box..."));
                            break;
                        }
                        return(true);
                    }
                }
                // Pass event to parent
                return QMainWindow::eventFilter(obj, event);
                break;
            }
        }
}

void MainWindow::on_pushButton_clicked(){
    switch(Mode){
    case Mode_NAVIGATE:
        /*********************************
         * Start background definition
         * *********************************/
        statusMode->setText(QString("Mode: Background"));
        Mode = Mode_BACKGROUND;
        statusBar()->showMessage(QString("Click box around fish..."));
        ui->frame->setCursor(Qt::CrossCursor);
        break;
    case Mode_BACKGROUND:
        /*********************************
         * Finish background definition
         * *********************************/
        Mode = Mode_NAVIGATE;
        statusMode->setText(QString("Mode: Navigate"));
        backgroundDefined = true;
        //Show background image
        ui->tabWidget->setCurrentIndex(2);
        ui->background->setPixmap(
                    displayBackground.scaled(
                        QSize(1,
                              ui->previewHeight->toPlainText().toLong()),
                        Qt::KeepAspectRatioByExpanding,
                        Qt::FastTransformation));
        break;
    }
}

void MainWindow::loadFrame(QPixmap pixFrame,int frameCurrent,int frameMax){

    // Update statusbar
    ui->statusBar->showMessage(
                QString("Frame: " +
                        QString::number(frameCurrent) +
                        '/' +
                        QString::number(frameMax))
                );
    // Scale and push pixmap to UI
    ui->frame->setPixmap(
                pixFrame.scaled(QSize(1,ui->previewHeight->toPlainText().toLong()),
                                 Qt::KeepAspectRatioByExpanding,Qt::FastTransformation)
                );
}

void MainWindow::on_Track_B_clicked()
{
    //empty slot for Track_B
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{

}
