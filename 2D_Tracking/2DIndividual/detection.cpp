#include "detection.h"
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPixmap>

Detection::Detection(MainWindow* obj)
{
    parent = obj;
}

void Detection::analyseFrame(){
    /**********************************
     * Updates image subtraction frames in MainWindow class
     * *******************************/
    // Subtract images;
    cv::absdiff(parent->background,parent->frame,parent->diff);
    // Convert to binary image
    cv::threshold(parent->diff,parent->bw,parent->threshold,
                          255,cv::THRESH_BINARY);
    cv::erode(parent->bw,parent->bw,cv::Mat(),
              cv::Point(-1,-1),parent->iterations,1,1);


//    namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
//    imshow( "Display window", parent->frame);

}
