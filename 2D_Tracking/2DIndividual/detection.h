#ifndef DETECTION_H
#define DETECTION_H

#include "mainwindow.h"
#include <opencv2/opencv.hpp>


class Detection
{
public:
    MainWindow* parent; // A pointer to the parent MainWindow object
    Detection(MainWindow*);
    void analyseFrame();

private:
    cv::Mat diff, bw, result;
};


#endif // DETECTION_H
