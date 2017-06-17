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
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QDir>

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
    connect(this,SIGNAL(settingsUpdate(std::vector<int>,std::vector<int>,std::vector<int>)),
            worker, SLOT(settingsUpdate(std::vector<int>,std::vector<int>,std::vector<int>)));
    connect(this,SIGNAL(videoPlay(bool)),
            worker, SLOT(videoPlay(bool)));
    connect(this,SIGNAL(videoStop()),
            worker, SLOT(videoStop()));
    connect(this,SIGNAL(fileUpdate(QStringList)),
            worker, SLOT(fileUpdate(QStringList)));

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
    std::string input = QFileDialog::getOpenFileName(this,
        tr("Open Video"), "/home/", tr("Video Files (*.mp4 *.avi *.h264)")).toStdString();

    // Save vidoe name and path
    size_t found = input.find_last_of("/\\");
    fileName = QString::fromStdString(std::string(input.substr(found = 1, input.length())));
    filePath = QString::fromStdString(std::string(input.substr(0, found)));

    // Load first frame
    frameCurrent= 0;

    // Load dummy background
    background_definition[4] = 0;
    backgroundDefined = false;

    // Open video object and pass to worker thread
    cv::VideoCapture video;
    video = cv::VideoCapture(filePath.toStdString() + fileName.toStdString());
    frameMax = int(video.get(cv::CAP_PROP_FRAME_COUNT));
    fps = video.get(cv::CAP_PROP_FPS);
    video.release();
    emit videoLoad(filePath.toStdString() + fileName.toStdString());

    // Load files associated with video
    on_bRefreshFileList_clicked();
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
    // Load tracking settings for each file from UI
    // then push to worker thread

    // Get ui settings from files table
    ulong tanks = ulong(ui->table_FileList->rowCount());
    std::vector<int> threshold(tanks);
    std::vector<int> erosion(tanks);
    std::vector<int> dilation(tanks);

    for(ulong j = 0;j < tanks;j++){ // Loop table files
        threshold[j] = ui->table_FileList->item(int(j),2)->text().toInt();
        erosion[j] = ui->table_FileList->item(int(j),3)->text().toInt();
        dilation[j] = ui->table_FileList->item(int(j),4)->text().toInt();
    }

    emit settingsUpdate(threshold, erosion, dilation);
}

void MainWindow::changeFiles(){
    // Load tracking files for each file from UI
    // then push to worker thread

    // Get ui settings from files table
    int tanks = ui->table_FileList->rowCount();
    QStringList files;

    for(int j = 0;j < tanks;j++){ // Loop table files
        files.append(ui->table_FileList->item(j,1)->text());
    }

    emit filesUpdate(files);
}


QStringList MainWindow::getTrackingFiles()
{
    // Get path from video file name
    QDir directory(filePath);
    // Set filter for files named videoName*.dat
    QString nameFilter = fileName;
    nameFilter.append("*.dat");
    directory.setNameFilters(QStringList(nameFilter));
    directory.setFilter(QDir::Files);
    // Read filtered files from directory
    QStringList files = directory.entryList();
    return(files);
}

void MainWindow::consoleOutput(QString text){
    // Slot for appending test to ui console output

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

void MainWindow::on_bDeleteFile_clicked()
{
    ui->table_FileList->removeRow(ui->table_FileList->currentRow());
    changeSettings();
    changeFiles();
}

void MainWindow::on_bAddFile_clicked()
{
    //Create file for new tank
    on_bRefreshFileList_clicked(); // refresh file list

    QStringList files = getTrackingFiles();
    QString newFile;
    int i = 0;
    //Generate file name (check for already existing files of same name)
    do{
        newFile = QString::fromStdString(filePath.toStdString() + fileName.toStdString() + "_Tank" + std::to_string(i) + ".dat");
    }while(files.contains(newFile));

    //Get file type from user
    QMessageBox msgBox;
    msgBox.setText("Select analysis type.");
    QAbstractButton* pButton2D = msgBox.addButton(tr("2D Tracking"), QMessageBox::NoRole);
    QAbstractButton* pButton3D = msgBox.addButton(tr("3D Tracking"), QMessageBox::NoRole);
    msgBox.exec();
    int type, multiplier;
    if (msgBox.clickedButton()==pButton2D) {
        type = 1;
        multiplier = 1;
    }else if (msgBox.clickedButton()==pButton3D){
        type = 2;
        multiplier = 2; //3D tracking has double file size
        // Needs front and back tank walls, and 2 xy positions for each point
    }

    // Initialze file on disk
    QFile newData(newFile);
    newData.open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream out(&newData);
    out.setByteOrder(QDataStream::LittleEndian);
    out<<double(type);
    out<<double(0);
    out<<double(0);
    out<<double(fps);
    for(i=1;i<= ((frameMax*2) + 8)*multiplier;i++){
        out<<double(0);
    }
    newData.close();

    on_bRefreshFileList_clicked(); // refresh file list
}

void MainWindow::on_bRefreshFileList_clicked()
{
    // Get tracking files for video
    QStringList files = getTrackingFiles();

    // Temp variables for comparing file names
    QString valueTable;
    QString valueDir;

    // Add missing files to table
    QStringList tableFiles;
    for(int j = 0;j < ui->table_FileList->rowCount();j++){ // Make QSTringList from table
        tableFiles.append(ui->table_FileList->item(j,1)->text());
    }
    for(int j = 0;j < files.count();j++){ // Loop dir files
        valueDir = files.takeAt(j);
        if(!tableFiles.contains(valueDir)){
            ui->table_FileList->insertRow(0);
            ui->table_FileList->setItem(0,1,new QTableWidgetItem(valueDir,0));
            ui->table_FileList->setItem(0,2,new QTableWidgetItem(0,0));
            ui->table_FileList->setItem(0,3,new QTableWidgetItem(0,0));
            ui->table_FileList->setItem(0,4,new QTableWidgetItem(0,0));
        }
    }

    // Remove missing files from table
    for(int j = 0;j < ui->table_FileList->rowCount();j++){ // Loop table files
        valueTable = ui->table_FileList->item(j,1)->text();
        if(!files.contains(valueTable)){
            // Remove item if does not exist in directory
            ui->table_FileList->removeRow(j);
        }
    }

    ui->table_FileList->sortItems(1); // Sort table items
    changeSettings();
    changeFiles();
}
