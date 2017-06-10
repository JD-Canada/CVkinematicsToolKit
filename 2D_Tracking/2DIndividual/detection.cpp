#include "detection.h"
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QLabel>
#include <string>

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
              cv::Point(-1,-1),iterations,1,1);
}

void Detection::updateSettings(double* settings){
    // [ErosionIterations]
    threshold = settings[1];
    iterations = settings[0];

    qDebug() << "Settings updated on worker thread";
    qDebug() << settings;

}

void Detection::loadVideo(std::string filename){
    video.open(filename);

    // Load first frame and show in ui
    frameCurrent = 0;
    loadFrame(true,MainWindow::Frame_NORMAL);
}

void Detection::requestFrame(int frame, MainWindow::uiDisplay view){
    frameCurrent = frame;
    loadFrame(true, view);
}

void Detection::loadFrame(bool display, MainWindow::uiDisplay view){
    // Skip if video not loaded
    if(frameCurrent == -1){return;}


    // Load frame from video and convert to grayscale
    video.set(cv::CAP_PROP_POS_FRAMES,frameCurrent); // move to new frame
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
        emit showFrame(frameCurrent, pixFrame);
    }
}

/**********************************
 * **********************************
 * Slots
 * **********************************
 * ********************************/
void Detection::setBackground(double *backgroundClicks, int backgroundRefFrame){
    // Move to first background frame and save as background
    frameReference = frameCurrent;
    frameCurrent = backgroundRefFrame;
    display = false;
    loadFrame(display, MainWindow::Frame_SKIP);
    matBackground = matFrame.clone();
// Remove fish from reference image
    // Load current frame again
    frameCurrent = frameReference;
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
    emit refreshBackgroundImage(pixBackground);
}
