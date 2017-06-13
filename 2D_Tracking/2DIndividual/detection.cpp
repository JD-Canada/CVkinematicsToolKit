#include "detection.h"
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QLabel>
#include <string>
#include <QEventLoop>

Detection::Detection()
{
    // Constructor
    // Initialize current frame to -1
    // Indicates that video is not yet loaded
    currentFrame = -1;
    backgroundDefined = false;
}

Detection::~Detection()
{
    // Delete any objects from memory when this function is destroyed
    video.release();
}

void Detection::analyseFrame(){
    /**********************************
     * Appy image subtraction
     * *******************************/
    // Subtract images;
    cv::absdiff(matBackground,matFrame,matDiff);
    // Convert to binary image
    cv::threshold(matDiff,matBw,threshold,
                          255,cv::THRESH_BINARY);
    // Erode uses default 3x3 mat pattern wne Mat() is used
    cv::erode(matBw,matBw,cv::Mat(),
              cv::Point(-1,-1),int(iterations),1,1);
}

void Detection::settingsUpdate(double* settings){
    // [ErosionIterations]
    threshold = settings[0];
    iterations = settings[1];
}

void Detection::videoLoad(std::string filename){
    video.open(filename);
    if (!video.isOpened()) {
        emit consoleOutput(QString("Error reading video file"));
    }

    if (video.get(CV_CAP_PROP_FRAME_COUNT) < 1) {
        emit consoleOutput(QString("error: video file must have at least one frame"));
    }
    // Load first frame and show in ui
    currentFrame = 0;
    loadFrame(true,MainWindow::Frame_NORMAL);
}

void Detection::frameRequest(int frame, MainWindow::MODE_DISPLAY view){
    currentFrame = frame;
    loadFrame(true, view);
}

void Detection::loadFrame(bool display, MainWindow::MODE_DISPLAY view){
    // Skip if video not loaded
    if(currentFrame == -1){return;}

    // Load frame from video and convert to grayscale
    video.set(cv::CAP_PROP_POS_FRAMES,currentFrame); // move to new frame
    video.read(matFrame); // load frame
    cv::cvtColor(matFrame,matFrame,CV_RGB2GRAY); // convert to greyscale

    // Convert to PixMap for displaying
    if(display == true && view != MainWindow::Frame_SKIP){
        if (backgroundDefined == false){
            matDisplay = matFrame;
        }else{
            // Analyse frame
            this->analyseFrame();
            // Select display mode
            switch(view){
            case MainWindow::Frame_NORMAL: matDisplay = matFrame; break;
            case MainWindow::Frame_SUBTRACTION: matDisplay = matDiff; break;
            case MainWindow::Frame_BINARY: matDisplay = matBw; break;
            }
        }
        // Convert frame into QPixMat for displaying in UI
        pixFrame = QPixmap::fromImage(
                    QImage(matDisplay.data,
                           matDisplay.cols,
                           matDisplay.rows,
                           int(matDisplay.step),
                           QImage::Format_Grayscale8));
        // Push the loaded frame to the UI to display
        emit showFrame(currentFrame, pixFrame);
    }
}

/**********************************
 * **********************************
 * Slots
 * **********************************
 * ********************************/
void Detection::backgroundSet(double *backgroundClicks, int backgroundRefFrame){
    // Move to first background frame and save as background
    frameReference = currentFrame;
    currentFrame = backgroundRefFrame;
    display = false;
    loadFrame(display, MainWindow::Frame_SKIP);
    matBackground = matFrame.clone();
// Remove fish from reference image
    // Load current frame again
    currentFrame = frameReference;
    loadFrame(display, MainWindow::Frame_SKIP);
    // Draw a box around fish using mouse clicks from ui
    cv::Rect ROI(
                cv::Point(int(backgroundClicks[0]* double(matFrame.cols)),
                int(backgroundClicks[1]*double(matFrame.rows))),
            cv::Size(int((backgroundClicks[2]- backgroundClicks[0])*double(matFrame.cols)),
            int((backgroundClicks[3] - backgroundClicks[1])*double(matFrame.rows))));
    // Paste ROI into new image (remove fish from that image)
    matFrame(ROI).copyTo(matBackground(ROI));
    // Convert matrix to Pixmap for display
    pixBackground = QPixmap::fromImage(
                QImage(matBackground.data,
                       matBackground.cols,
                       matBackground.rows,
                       int(matBackground.step),
                       QImage::Format_Grayscale8));
    // Push new background to UI
    backgroundDefined = true;
    emit backgroundRefresh(pixBackground);
}

void Detection::videoPlay(bool analyze) {

    if(currentFrame == -1){
        // Exit if no video loaded
        return;
    }

    if(analyze == true){
        mode_playback = playback_ANALYZE;
    }else{
        mode_playback = playback_PLAY;
    }

    int frameMax = int(video.get(CV_CAP_PROP_FRAME_COUNT));

    while (mode_playback != playback_STOP) {
        if (currentFrame + 1  < frameMax) {
            loadFrame(true,MainWindow::Frame_NORMAL);
            currentFrame = currentFrame + 1;
        } else {
            emit consoleOutput(QString("end of video"));
            break;
        }
        // Process UI signals
        qApp->processEvents(QEventLoop::AllEvents);

    }
}

void Detection::videoStop(){
    mode_playback = playback_STOP;
}
