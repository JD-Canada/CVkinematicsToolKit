#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadFrame(bool load = true); // Showframe on UI
    void checkCurrentFrame(); // Make sure currentFrame is within video range

    int currentFrame;
    std::string fileName;
    cv::VideoCapture video;
    cv::Mat frame, background, diff, bw, display;
    enum uiMode {Mode_NAVIGATE, Mode_ANALYSIS, Mode_BACKGROUND, Mode_DIMENTIONS};
    uiMode Mode;
    double threshold, iterations;
    QPixmap frame_pix, background_pix;
    bool backgroundDefined, dimentionsDefined;


protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *) override;
    QLabel* mouseX;
    QLabel* mouseY;
    QLabel* mode_status;

    double backgroundClicks [5];
    // {x1, y1, x2, y2, Click Counter}


private slots:
    void on_loadVideo_clicked();
    void on_pushButton_clicked();
    void on_Track_B_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
