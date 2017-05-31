#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include <QLabel>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum uiMode {Mode_NAVIGATE, Mode_ANALYSIS, Mode_BACKGROUND, Mode_DIMENTIONS};

    // Showframe on UI
    void loadFrame(bool load = true);

    // Make sure currentFrame is within video range
    void checkCurrentFrame();

protected:
    // Capture user input (Override default action)
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *) override;
    int frameCurrent, frameMax;

    // UI & Modes

    uiMode Mode;
    QPixmap displayFrame, displayBackground;
    bool backgroundDefined, dimentionsDefined;
    std::string fileName;

    //Statusbar
    QLabel* statusMouseX, * statusMouseY, * statusMode;

    // Background mode
    double backgroundClicks [5];

    // Settings
    double settingsThreshold, settingsIterations;

signals:
    void shutdown();
    void loadFrame(int);
    void setBackground(int,int, int);

private slots:
    void on_loadVideo_clicked();
    void on_pushButton_clicked();
    void loadFrame(QPixmap,int,int);
    void on_Track_B_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
