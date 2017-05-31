#include "detection.h"
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QLabel>
#include <string>

Detection::Detection(MainWindow* obj)
{
    // Pointer to object holding ui
    parent = obj;

    // Initialize current frame to -1
    // Indicates that video is not yet loaded
    currentFrame = -1;

    backgroundDefined = false;
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
    // Erode uses default 3x3 mat pattern
    cv::erode(matBw,matBw,cv::Mat(),
              cv::Point(-1,-1),iterations,1,1);
}

void Detection::videoLoad(std::string filename){
    video = cv::VideoCapture(filename);
}

void Detection::checkCurrentFrame(){
    // Check frame is within video range
    if(frameCurrent + 1 > video.get(cv::CAP_PROP_FRAME_COUNT)){
        frameCurrent= video.get(cv::CAP_PROP_FRAME_COUNT) - 1;
    }else if(frameCurrent < 0){
        frameCurrent = 0;
    }

    // Add new frame number to statusbar
    
}

void Detection::loadFrame(bool load){
    if(currentFrame == -1){return;}

    // Load frame from video and convert to grayscale
    video.set(cv::CAP_PROP_POS_FRAMES,currentFrame);
    video.read(matFrame);
    cv::cvtColor(matFrame,matFrame,CV_RGB2GRAY);

    if (backgroundDefined == false){
        matDisplay = matFrame;
    }else{
        // Analyse frame
        this->analyseFrame();
        // Select display mode
        switch(viewmode){
        case 0: matDisplay = matFrame; break;
        case 1: matDisplay = matDiff; break;
        case 2: matDisplay = matBw; break;
        }
    }

    pixFrame = QPixmap::fromImage(
                QImage(matDisplay.data,
                       matDisplay.cols,
                       matDisplay.rows,
                       matDisplay.step,
                       QImage::Format_Grayscale8));

    emit

}

/**********************************
 * **********************************
 * Slots
 * **********************************
 * ********************************/

QPixmap Detection::setBackground(int step){
    switch(step){
    case 0:
        // Grab frame as reference image
        frameBackground= frame.clone();
        break;
    case 1:
        // Remove fish from reference image
        cv::Rect ROI(cv::Point(backgroundClicks[0]*(double) frame.cols, backgroundClicks[1]*(double)frame.rows),
                cv::Size((backgroundClicks[2]- backgroundClicks[0])*(double)frame.cols,
                (backgroundClicks[3] - backgroundClicks[1])*(double) frame.rows));
        frame(ROI).copyTo(background(ROI));
        pixBackground = QPixmap::fromImage(
                    QImage(pixBackground.data,
                           pixBackground.cols,
                           pixBackground.rows,
                           pixBackground.step,
                           QImage::Format_Grayscale8));
        // Display background image

        break;
    }
    }
}

