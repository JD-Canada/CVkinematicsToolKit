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
    connect(this, SIGNAL(videoLoad(std::string)),
                     worker, SLOT(videoLoad(std::string)));
    connect(this,SIGNAL(frameRequest(int, MainWindow::MODE_DISPLAY)),
                     worker, SLOT(frameRequest(int, MainWindow::MODE_DISPLAY)));
    connect(this,SIGNAL(backgroundSet(double *, int)),
            worker, SLOT(backgroundSet(double *, int)));
    connect(this,SIGNAL(settingsUpdate(double *)),
            worker, SLOT(settingsUpdate(double *)));
    connect(this,SIGNAL(videoPlay(bool)),
            worker, SLOT(videoPlay(bool)));
    connect(this,SIGNAL(videoStop()),
            worker, SLOT(videoStop()));

    // Recieving
    connect(worker,SIGNAL(showFrame(int, QPixmap)),
                     this, SLOT(showFrame(int, QPixmap)));
    connect(worker,SIGNAL(backgroundRefresh(QPixmap)),
                     this, SLOT(backgroundRefresh(QPixmap)));
    connect(worker,SIGNAL(consoleOutput(QString)),
                     this, SLOT(consoleOutput(QString)));

    // Name and start thread
    workerThread->setObjectName(QString("CVKinematics"));
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
    mode_ui = Mode_NAVIGATE;
    status_mode->setText(QString("Mode: NAVIGATE"));

    //Initialize console output
    console_output_length = 1000;
    console_output = QString("");  // initalize empty console
    console_output.reserve(console_output_length);

    // First console messages
    consoleOutput(QString("Fish tracker alpha"));
    consoleOutput(QString("Load a video to start tracking..."));
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
    background_definition[4] = 0;
    backgroundDefined = false;

    // Open video object and pass to worker thread
    cv::VideoCapture video;
    video = cv::VideoCapture(fileName);
    frameMax = int(video.get(cv::CAP_PROP_FRAME_COUNT));
    video.release();
    emit videoLoad(fileName);
}

void MainWindow::checkCurrentFrame(){
    // Check frame is within video range
    if(frameCurrent + 1 > frameMax){
        frameCurrent = frameMax;
    }else if(frameCurrent < 0){
        frameCurrent = 0;
    }
    // Add new frame number to statusbar
    emit frameRequest(frameCurrent, mode_display);
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

void MainWindow::backgroundRefresh(QPixmap pixFrame){
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
    settingsUpdate(settings);

}

void MainWindow::consoleOutput(QString text){

    // Start with new line break
    console_output.append(QString("\n"));
    console_output.append(text);

    // Trim output if exceeds output length - 100
    if (console_output.size() > console_output_length - 100){
        console_output.remove(0,console_output.size() - (console_output_length - 100));
    }

    ui->messageOutput->setText(console_output);
}

/********************************
 * UI callback functions
 * *****************************/
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // Capture key press events on top level
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
                emit frameRequest(frameCurrent, mode_display);
                return(true);
            }
        }
        // Pass event to parent
        return QMainWindow::eventFilter(obj, event);
    }else if(obj == ui->frame){
        switch(mode_ui){
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
                    switch(int(background_definition[4])){
                    // Background click positions are saved as scaled x,y, coords x = (0,1), y = (0,1)
                    // This avoids the error due to the mouse grabbing the position in the scaled display image, as opposed to the
                    // position of the full size video frame.
                    case 0:
                        background_definition[0] = double(point.x()) /double(ui->frame->size().width());
                        background_definition[1] = double(point.y())/double(ui->frame->size().height());
                        background_definition[4] = 1;
                        backgroundRefFrame = frameCurrent;
                        break;
                    case 1:
                        background_definition[2] = double(point.x()) / double(ui->frame->size().width());
                        background_definition[3] = double(point.y()) / double(ui->frame->size().height());
                        background_definition[4] = 2;
                        ui->frame->setCursor(Qt::ArrowCursor);
                        consoleOutput(QString("Move to a frame where the fish has left the box, the define your second background image..."));
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
void MainWindow::keyPressEvent(QKeyEvent * event){
    if (frameCurrent == -1){
        ui->statusBar->showMessage(QString("No video loaded!"));
        return;
    }
    /**********************************************************
     * Keyboard controls are different depending on UI mode
     **********************************************************/
    switch(mode_ui){
    case Mode_NAVIGATE:
        switch(event->key()){
        case Qt::Key_Z: frameCurrent  = frameCurrent - 1;
                    checkCurrentFrame();break;
        case Qt::Key_X: frameCurrent  = frameCurrent + 1;
                    checkCurrentFrame();break;
        case Qt::Key_A:  frameCurrent  = frameCurrent - 10;
                    checkCurrentFrame();break;
        case Qt::Key_S:  frameCurrent  = frameCurrent + 10;
                    checkCurrentFrame();break;
        case Qt::Key_Q:  frameCurrent  = frameCurrent - 100;
                    checkCurrentFrame();break;
        case Qt::Key_W:  frameCurrent  = frameCurrent + 100;
                    checkCurrentFrame();break;
        case Qt::Key_1:  frameCurrent  = frameCurrent - 1000;
                    checkCurrentFrame();break;
        case Qt::Key_2:  frameCurrent  = frameCurrent + 1000;
                    checkCurrentFrame();break;
        case Qt::Key_Space: // Playback
            status_mode->setText(QString("Mode: ANALYSIS"));
            mode_ui = Mode_ANALYSIS;
            emit videoPlay(false);
            break;
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
        switch(event->key()){
        case Qt::Key_Space:
            mode_ui = Mode_NAVIGATE;
            status_mode->setText(QString("Mode: NAVIGATE"));
            emit videoStop();
            break;
        }
        break;
    }
}

void MainWindow::on_pushButton_clicked(){
    switch(mode_ui){
    case Mode_NAVIGATE:
        /*********************************
         * Start background definition
         *********************************/
        status_mode->setText(QString("Mode: BACKGROUND"));
        mode_ui = Mode_BACKGROUND;
        consoleOutput("Click a box around fish...\nThe upper left bound, followed by the lower right.");
        ui->frame->setCursor(Qt::CrossCursor);
        backgroundDefined = false;
        break;
    case Mode_BACKGROUND:
        /*********************************
         * Finish background definition
         *********************************/
        if(int(background_definition[4]) == 2){
            mode_ui = Mode_NAVIGATE;
            status_mode->setText(QString("Mode: NAVIGATE"));
            backgroundDefined = true;
            background_definition[4] = 0;
            emit backgroundSet(background_definition,backgroundRefFrame);
            consoleOutput("background image defined!");
        }else{
            consoleOutput("Click box around fish before defining second image...");
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

void MainWindow::on_ViewMode_currentIndexChanged(int index)
{
    // Save display mode type after update (Grayscale, subtraction, binary)
    mode_display = MODE_DISPLAY(index);
}


void MainWindow::on_playButton_clicked()
{
    switch(mode_ui){
    case Mode_NAVIGATE:
        emit videoPlay(false);
        mode_ui = Mode_ANALYSIS;
        status_mode->setText(QString("Mode: ANALYSIS"));
        break;
    case Mode_ANALYSIS:
        worker->mode_playback = Detection::playback_STOP;
        mode_ui = Mode_NAVIGATE;
        status_mode->setText(QString("Mode: NAVIGATE"));
        break;
    }
}

void MainWindow::on_threshold_textChanged()
{
    MainWindow::changeSettings();
}

void MainWindow::on_erosionIterations_textChanged()
{

    MainWindow::changeSettings();
}

void MainWindow::on_Track_B_clicked()
{
    switch(mode_ui){
    case Mode_NAVIGATE:
        emit videoPlay(true);
        mode_ui = Mode_ANALYSIS;
        status_mode->setText(QString("Mode: ANALYSIS"));
        break;
    case Mode_ANALYSIS:
        emit videoStop();
        mode_ui = Mode_NAVIGATE;
        status_mode->setText(QString("Mode: NAVIGATE"));
        break;
    }
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

