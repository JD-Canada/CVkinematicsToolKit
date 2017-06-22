// Local resources
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detection.h"

// OpenCV
#include <opencv2/opencv.hpp>

//OpenCV - uncomment for Windows
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

// Qt libs
#include <QFileDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <QImage>
#include <typeinfo>
#include <QLabel>
#include <QThread>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>

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
    worker = new Detection();
// Move to worker thread
    workerThread = new QThread;
    worker->moveToThread(workerThread);

// Link singal/slots between threads
    // Sending
    connect(this, SIGNAL(loadVideo(std::string)),
                     worker, SLOT(loadVideo(std::string)));
    connect(this,SIGNAL(requestFrame(int, MainWindow::uiDisplay)),
                     worker, SLOT(requestFrame(int, MainWindow::uiDisplay)));
    connect(this,SIGNAL(setBackground(double *, int)),
            worker, SLOT(setBackground(double*, int)));
    connect(this,SIGNAL(updateSettings(double *)),
            worker, SLOT(updateSettings(double*)));

    // Recieving
    connect(worker,SIGNAL(showFrame(int, QPixmap)),
                     this, SLOT(showFrame(int, QPixmap)));
    connect(worker,SIGNAL(refreshBackgroundImage(QPixmap)),
                     this, SLOT(refreshBackgroundImage(QPixmap)));
    workerThread->start();

// Add statusbar widgets
    status_mouse_x = new QLabel(this);
    status_mouse_x->setText(QString("x: "));
    status_mouse_x->setObjectName(QString("mouseX"));
    statusBar()->addPermanentWidget(status_mouse_x);
    status_mouse_y = new QLabel(this);
    status_mouse_y->setText(QString("y: "));
    status_mouse_y->setObjectName(QString("mouseY"));
    statusBar()->addPermanentWidget(status_mouse_y);
    status_mode= new QLabel(this);
    status_mode->setText(QString("Mode: Navigate"));
    statusBar()->addPermanentWidget(status_mode);

    // Set up event filters for user input (capture key presses and clicks)
    ui->jumpFrame->installEventFilter(this);
    ui->frame->installEventFilter(this);

    //add example plot to Plots tab
    setupQuadraticDemo(ui->customPlot);


    // Set mode
    Mode = Mode_NAVIGATE;
}

// Deconstructor
MainWindow::~MainWindow()
{
    // Close worker thread
   workerThread->quit();
}

void MainWindow::on_loadVideo_clicked()
{
    // Get video location
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Video"), "/home/", tr("Video Files (*.mp4 *.avi *.h264)")).toStdString();

    // Load first frame
    frameCurrent= 0;

    // Load dummy background
    backgroundClicks[4] = 0;
    backgroundDefined = false;

    // Open video object and pass to worker thread
    cv::VideoCapture video;
    video = cv::VideoCapture(fileName);
    frameMax = int(video.get(cv::CAP_PROP_FRAME_COUNT));
    video.release();
    emit loadVideo(fileName);
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
        case Qt::Key_Z: frameCurrent  = frameCurrent - 1;break;
        case Qt::Key_X: frameCurrent  = frameCurrent + 1;break;
        case Qt::Key_A:  frameCurrent  = frameCurrent - 10;break;
        case Qt::Key_S:  frameCurrent  = frameCurrent + 10;break;
        case Qt::Key_Q:  frameCurrent  = frameCurrent - 100;break;
        case Qt::Key_W:  frameCurrent  = frameCurrent + 100;break;
        case Qt::Key_1:  frameCurrent  = frameCurrent - 1000;break;
        case Qt::Key_2:  frameCurrent  = frameCurrent + 1000;break;
        }
        checkCurrentFrame();
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
        checkCurrentFrame();
        break;
    case Mode_DIMENTIONS:
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
        checkCurrentFrame();
        break;
    case Mode_ANALYSIS:
        // No keybaord commands in analysis mode
        break;
    }
}

void MainWindow::checkCurrentFrame(){
    // Check frame is within video range
    if(frameCurrent + 1 > frameMax){
        frameCurrent = frameMax;
    }else if(frameCurrent < 0){
        frameCurrent = 0;
    }
    // Add new frame number to statusbar
    emit requestFrame(frameCurrent, displayMode);
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
                frameCurrent = ui->jumpFrame->toPlainText().toInt();
                ui->jumpFrame->setText(QString());
                this->focusWidget()->clearFocus();
                // Load new frame
                emit requestFrame(frameCurrent, displayMode);
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
                    status_mouse_x->setText("x: " + QString::number(point.x()));
                    status_mouse_y->setText("y: " + QString::number(point.y()));
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
                    status_mouse_x->setText("x: " + QString::number(point.x()));
                    status_mouse_y->setText("y: " + QString::number(point.y()));
                    // Log points in memory
                    switch(static_cast<int>(backgroundClicks[4])){
                    // Background click positions are saved as scaled x,y, coords x = (0,1), y = (0,1)
                    // This avoids the error due to the mouse grabbing the position in the scaled display image, as opposed to the
                    // position of the full size video frame.
                    case 0:
                        backgroundClicks[0] = double(point.x()) /double(ui->frame->size().width());
                        backgroundClicks[1] = double(point.y())/double(ui->frame->size().height());
                        backgroundClicks[4] = 1;
                        backgroundRefFrame = frameCurrent;
                        break;
                    case 1:
                        backgroundClicks[2] = double(point.x()) / double(ui->frame->size().width());
                        backgroundClicks[3] = double(point.y()) / double(ui->frame->size().height());
                        backgroundClicks[4] = 2;
                        ui->frame->setCursor(Qt::ArrowCursor);
                        statusBar()->showMessage(QString("Move until the fish is out the box..."));
                        break;
                    }
                    return(true);
                }
            }
            // Pass event to parent
            return QMainWindow::eventFilter(obj, event);
            case Mode_DIMENTIONS:
            //set tank dimentions with mouse clicks here
            break;
            case Mode_ANALYSIS:
            // Do nothing
            break;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_pushButton_clicked(){
    switch(Mode){
    case Mode_NAVIGATE:
        /*********************************
         * Start background definition
         *********************************/
        status_mode->setText(QString("Mode: Background"));
        Mode = Mode_BACKGROUND;
        statusBar()->showMessage(QString("Click box around fish..."));
        ui->frame->setCursor(Qt::CrossCursor);
        backgroundDefined = false;
        break;
    case Mode_BACKGROUND:
        /*********************************
         * Finish background definition
         *********************************/
        if(backgroundClicks[4] == 2){
            Mode = Mode_NAVIGATE;
            status_mode->setText(QString("Mode: Navigate"));
            backgroundDefined = true;
            backgroundClicks[4] = 0;
            emit setBackground(backgroundClicks,backgroundRefFrame);
        }else{
            statusBar()->showMessage(QString("Click box around fish before defining second image..."));
        }
        break;
    case Mode_DIMENTIONS:
        // Do nothing
        break;
    case Mode_ANALYSIS:
        // Do nothing
        break;
    }
}

void MainWindow::showFrame(int frame, QPixmap pixFrame){
    // Update current frame
    frameCurrent = frame;
    // Update statusbar
    ui->statusBar->showMessage(
                QString("Frame: " +
                        QString::number(frameCurrent) +
                        '/' +
                        QString::number(frameMax)));
    // Scale and push pixmap to UI
    ui->frame->setPixmap(
                pixFrame.scaled(QSize(1,ui->previewHeight->toPlainText().toInt()),
                                 Qt::KeepAspectRatioByExpanding,Qt::FastTransformation)
                );
    qDebug() << "Frame updated";
}

void MainWindow::refreshBackgroundImage(QPixmap pixFrame){
    // Load new background image
    ui->background->setPixmap(
                pixFrame.scaled(QSize(1,ui->previewHeight->toPlainText().toInt()),
                                 Qt::KeepAspectRatioByExpanding,Qt::FastTransformation)
                );
}

void MainWindow::changeSettings(){
    // Get ui settings
    settings_threshold = {ui->threshold->toPlainText().toDouble()};
    settings_erode_iterations = {ui->erosionIterations->toPlainText().toDouble()};
    double settings [2] = {settings_threshold, settings_erode_iterations};
    updateSettings(settings);

}

void MainWindow::on_ViewMode_currentIndexChanged(int index)
{
    // Save display mdoe type after update (Grayscale, subtraction, binary)
    displayMode = uiDisplay(index);
}

void MainWindow::on_Track_B_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_playButton_clicked()
{
    std::cout << fileName << endl;

        cv::VideoCapture capVideo;
        cv::Mat imgFrame;

        capVideo.open(fileName);

        if (!capVideo.isOpened()) {
            std::cout << "\nerror reading video file" << std::endl << std::endl;
        }

        if (capVideo.get(CV_CAP_PROP_FRAME_COUNT) < 1) {
            std::cout << "\nerror: video file must have at least one frame";
        }
        capVideo.read(imgFrame);

        char chCheckForEscKey = 0;

        while (capVideo.isOpened() && chCheckForEscKey != 27) {

            cv::imshow("imgFrame", imgFrame);
            if ((capVideo.get(CV_CAP_PROP_POS_FRAMES) + 1) < capVideo.get(CV_CAP_PROP_FRAME_COUNT)) {
                capVideo.read(imgFrame);
            }
            else {
                std::cout << "end of video\n";
                break;
            }
            chCheckForEscKey = cv::waitKey(1);
        }

        if (chCheckForEscKey != 27) {
            cv::waitKey(0);
        }
    }

/************************************************
// Functions for updating anaysis params
************************************************/
void MainWindow::on_threshold_textChanged()
{
    MainWindow::changeSettings();
}

void MainWindow::on_erosionIterations_textChanged()
{

    MainWindow::changeSettings();
}

/************************************************
// Experimental functions for plotting
************************************************/
void MainWindow::setupQuadraticDemo(QCustomPlot *customPlot)
{
  //demoName = "Quadratic Demo";
  // generate some data:
  QVector<double> x(101), y(101); // initialize with entries 0..100
  for (int i=0; i<101; ++i)
  {
    x[i] = i/50.0 - 1; // x goes from -1 to 1
    y[i] = x[i]*x[i];  // let's plot a quadratic function
  }
  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(x, y);
  // give the axes some labels:
  customPlot->xAxis->setLabel("x");
  customPlot->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  customPlot->xAxis->setRange(-1, 1);
  customPlot->yAxis->setRange(0, 1);
}
