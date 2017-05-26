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

// c++ std libs
#include <string>

Detection *AnalyseFrame;

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Initialize UI
    ui->setupUi(this);

    // Initialize current frame to -1
    // Indicates that video is not yet loaded
    currentFrame = -1;

    // Set up event filters for user input (capture key presses and clicks)
    ui->jumpFrame->installEventFilter(this);
    ui->frame->installEventFilter(this);

    // Set mode
    Mode = Mode_NAVIGATE;

    // Add statusbar widgets
    mouseX = new QLabel(this);
    mouseX->setText(QString("x: "));
    mouseX->setObjectName(QString("mouseX"));
    statusBar()->addPermanentWidget(mouseX);

    mouseY = new QLabel(this);
    mouseY->setText(QString("y: "));
    mouseY->setObjectName(QString("mouseY"));
    statusBar()->addPermanentWidget(mouseY);

    mode_status = new QLabel(this);
    mode_status->setText(QString("Mode: Navigate"));
    statusBar()->addPermanentWidget(mode_status);

    AnalyseFrame = new Detection(this);
    backgroundDefined = false;

}

// Deconstructor
MainWindow::~MainWindow()
{
    // Close video file (if previously opened)
    if(currentFrame == -1){
        video.release();
    }

    delete ui;
}

void MainWindow::on_loadVideo_clicked()
{
    // Get video location
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Video"), "/home/", tr("Video Files (*.mp4 *.avi)")).toStdString();

    // Load first frame
    video = cv::VideoCapture(fileName);
    currentFrame = 0;
    MainWindow::loadFrame();
    ui->tabWidget->setCurrentIndex(0);

    // Load dummy background
    background = frame;
    backgroundClicks[4] = 0;
}

void MainWindow::keyPressEvent(QKeyEvent * event){
    if (currentFrame == -1){
        ui->statusBar->showMessage(QString("No video loaded!"));
        return;
    }

    /**********************************************************
     * Keyboard controls are different depending on UI mode
     **********************************************************/

    switch(Mode){
    case Mode_NAVIGATE:
        switch(event->key()){
        case Qt::Key_Z: currentFrame  = currentFrame - 1;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_X: currentFrame  = currentFrame + 1;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_A:  currentFrame  = currentFrame - 10;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_S:  currentFrame  = currentFrame + 10;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_Q:  currentFrame  = currentFrame - 100;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_W:  currentFrame  = currentFrame + 100;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_1:  currentFrame  = currentFrame - 1000;
            checkCurrentFrame();loadFrame();break;
        case Qt::Key_2:  currentFrame  = currentFrame + 1000;
            checkCurrentFrame();loadFrame();break;
        }
        break;
    case Mode_BACKGROUND:
        switch(event->key()){
        case Qt::Key_Z: currentFrame  = currentFrame - 1;break;
        case Qt::Key_X: currentFrame  = currentFrame + 1;break;
        case Qt::Key_A:  currentFrame  = currentFrame - 10;break;
        case Qt::Key_S:  currentFrame  = currentFrame + 10;break;
        case Qt::Key_Q:  currentFrame  = currentFrame - 100;break;
        case Qt::Key_W:  currentFrame  = currentFrame + 100;break;
        case Qt::Key_1:  currentFrame  = currentFrame - 1000;break;
        case Qt::Key_2:  currentFrame  = currentFrame + 1000;break;
        }
        checkCurrentFrame();loadFrame();break;
    }
}

void MainWindow::checkCurrentFrame(){
    // Check frame is within video range
    if(currentFrame + 1 > video.get(cv::CAP_PROP_FRAME_COUNT)){
        currentFrame = video.get(cv::CAP_PROP_FRAME_COUNT) - 1;
    }else if(currentFrame < 0){
        currentFrame = 0;
    }

    // Add new frame number to statusbar
    ui->statusBar->showMessage(
                QString("Frame: " +
                        QString::number(currentFrame) +
                        '/' +
                        QString::number(video.get(cv::CAP_PROP_FRAME_COUNT)))
                );
}

void MainWindow::loadFrame(bool load){
    if(currentFrame == -1){return;}

    // Load frame from video
    video.set(cv::CAP_PROP_POS_FRAMES,currentFrame);
    video.read(frame);
    cv::cvtColor(frame,frame,CV_RGB2GRAY);

    if (backgroundDefined == false){
        display = frame;
    }else{
        // Analyse frame
        threshold = ui->threshold->toPlainText().toDouble();
        iterations = ui->erosionIterations->toPlainText().toDouble();
        AnalyseFrame->analyseFrame();
        // Select display mode
        switch(ui->ViewMode->currentIndex()){
        case 0: display = frame; break;
        case 1: display = diff; break;
        case 2: display = bw; break;
        }
    }

    frame_pix = QPixmap::fromImage(
                QImage(display.data,
                       display.cols,
                       display.rows,
                       display.step,
                       QImage::Format_Grayscale8));


    // Scale and push image to UI
    ui->frame->setPixmap(
                frame_pix.scaled(QSize(1,ui->previewHeight->toPlainText().toLong()),
                                 Qt::KeepAspectRatioByExpanding,Qt::FastTransformation)
                );
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
                    currentFrame = ui->jumpFrame->toPlainText().toLong();
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
                        mouseX->setText("x: " + QString::number(point.x()));
                        mouseY->setText("y: " + QString::number(point.y()));
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
                        mouseX->setText("x: " + QString::number(point.x()));
                        mouseY->setText("y: " + QString::number(point.y()));
                        // Log points in memory
                        switch(static_cast<int>(backgroundClicks[4])){
                        case 0:
                            backgroundClicks[0] = (double) point.x() / (double) ui->frame->size().width();
                            backgroundClicks[1] = (double) point.y() / (double) ui->frame->size().height();
                            backgroundClicks[4] = 1;
                            break;
                        case 1:
                            backgroundClicks[2] = (double)point.x() / (double) ui->frame->size().width();
                            backgroundClicks[3] = (double) point.y() / (double) ui->frame->size().height();
                            backgroundClicks[4] = 0;
                            ui->frame->setCursor(Qt::ArrowCursor);
                            statusBar()->showMessage(QString("Select second background image..."));
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
        background = frame.clone();
        Mode = Mode_BACKGROUND;
        mode_status->setText(QString("Mode: Background"));
        statusBar()->showMessage(QString("Click box around fish..."));
        ui->frame->setCursor(Qt::CrossCursor);
        break;
    case Mode_BACKGROUND:
        /*********************************
         * Finish background definition
         * *********************************/
        cv::Rect ROI(cv::Point(backgroundClicks[0]*(double) frame.cols, backgroundClicks[1]*(double)frame.rows),
                cv::Size(backgroundClicks[2]* (double) frame.cols - backgroundClicks[0]*(double)frame.cols,
                backgroundClicks[3]*(double) frame.rows - backgroundClicks[1]*(double) frame.rows));
        frame(ROI).copyTo(background(ROI));
        background_pix = QPixmap::fromImage(
                    QImage(background.data,
                           background.cols,
                           background.rows,
                           background.step,
                           QImage::Format_Grayscale8));
        // Display background image
        ui->background->setPixmap(
                    background_pix.scaled(
                        QSize(1,
                              ui->previewHeight->toPlainText().toLong()),
                        Qt::KeepAspectRatioByExpanding,
                        Qt::FastTransformation));
        ui->tabWidget->setCurrentIndex(2);
        Mode = Mode_NAVIGATE;
        mode_status->setText(QString("Mode: Navigate"));
        backgroundDefined = true;
        break;
    }
}
