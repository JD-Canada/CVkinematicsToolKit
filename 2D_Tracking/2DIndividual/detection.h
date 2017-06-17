#ifndef DETECTION_H
#define DETECTION_H

#include <QtCore>
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <mainwindow.h>

//Must inherit QObject class so this can be used in QThreads
class Detection : public QObject
{
    Q_OBJECT

public:
    MainWindow* parent; // A pointer to the parent MainWindow object
    Detection(); // Constructor
    ~Detection(); // Deconstructor

    /******************
     * Public Functions
     * ***************/
    QPixmap pixFrame, pixBackground;
    enum MODE_PLAYBACK {playback_STOP, playback_PLAY, playback_ANALYZE};
    MODE_PLAYBACK mode_playback;


private:
    /******************
     * Private Variables
     * ***************/

    cv::Mat matFrame, matBackground, matDiff, matBw, matDisplay;
    cv::VideoCapture video;
    cv::Rect ROI; // Rectangle holding fish for background image creation

    int frameReference, currentFrame, frameMax, backgroundRefFrame;
    std::vector<int> threshold, erosion, dilation;
    QStringList files;
    QList<double*> data;
    QString filePath, fileName;
    int fileNumber;

    bool backgroundDefined, display;


    /******************
     * Private Functions
     * ***************/
    void checkCurrentFrame();
    void loadFrame(bool,MainWindow::MODE_DISPLAY);
    void analyseFrame();

signals:
    void showFrame(int, QPixmap);
    void backgroundRefresh(QPixmap);
    void consoleOutput(QString);

private slots:
    void frameRequest(int, MainWindow::MODE_DISPLAY);
    void videoLoad(std::string);
    void videoPlay(bool);
    void videoStop();
    void backgroundSet(double *, int);
    void settingsUpdate(double*); // Pass UI options to worker thread
    void settingsUpdate(std::vector<int>,std::vector<int>,std::vector<int>); // Pass UI options to worker thread
    void filesUpdate(QStringList); // Pass new file names to worker thread
};

//The Q_DECLATE macro is required for non-standard variables passed through signals
Q_DECLARE_METATYPE(QPixmap);

#endif // DETECTION_H
