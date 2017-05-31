#ifndef DETECTION_H
#define DETECTION_H

#include<QtCore>
#include "mainwindow.h"
#include <opencv2/opencv.hpp>

//Must inherit QObject class so this can be used in QThreads
class Detection : public QObject
{
public:
    MainWindow* parent; // A pointer to the parent MainWindow object
    Detection(MainWindow*); // Constructor

    // Variables
    long currentFrame ;
    bool backgroundDefined;


private:
    /******************
     * Private Variables
     * ***************/
    cv::Mat matFrame, matBackground, matDiff, matBw, matDisplay;
    MainWindow::uiMode viewmode;
    int frameCurrent, frameMax, threshold, iterations;
    QPixmap pixFrame, pixBackground;
    cv::VideoCapture video;


    /******************
     * Private Functions
     * ***************/
    void videoLoad(std::string filename);
    void checkCurrentFrame();
    void loadFrame(bool load);
    void analyseFrame();
};


#endif // DETECTION_H
