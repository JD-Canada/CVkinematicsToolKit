#ifndef DETECTION_H
#define DETECTION_H

//Qt
#include <QtCore>
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPixmap>

//uncomment for Windows
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//Must inherit QObject class so this can be used in QThreads
class Detection : public QObject
{
    Q_OBJECT

public:
    MainWindow* parent; // A pointer to the parent MainWindow object
    Detection(); // Constructor
    ~Detection(); // Deconstructor

    // Variables
    long currentFrame ;

    /******************
     * Public Functions
     * ***************/
    QPixmap pixFrame, pixBackground;

private:
    /******************
     * Private Variables
     * ***************/
    cv::Mat matFrame, matBackground, matDiff, matBw, matDisplay;
    cv::VideoCapture video;
    cv::Rect ROI; // Rectangle holding fish for background image creation

    int frameReference, frameCurrent, frameMax, backgroundRefFrame;
    double threshold, iterations;

    bool backgroundDefined, display;

    /******************
     * Private Functions
     * ***************/
    void checkCurrentFrame();
    void loadFrame(bool,MainWindow::uiDisplay);
    void analyseFrame();
    void playVideo();

signals:
    void showFrame(int, QPixmap);
    void refreshBackgroundImage(QPixmap);

private slots:
    void requestFrame(int, MainWindow::uiDisplay);
    void loadVideo(std::string);
    void setBackground(double *, int);
    void updateSettings(double*); // Pass UI options to worker thread
};

Q_DECLARE_METATYPE(QPixmap);

#endif // DETECTION_H
