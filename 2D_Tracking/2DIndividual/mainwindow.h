#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QThread>

#include "display.h"

#include <opencv2/opencv.hpp>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT // This macro is necessary to load signal/slot functions

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum uiMode {Mode_NAVIGATE, Mode_ANALYSIS, Mode_BACKGROUND, Mode_DIMENTIONS};
    enum uiDisplay {Frame_NORMAL, Frame_SUBTRACTION, Frame_BINARY, Frame_SKIP};

    // Showframe on UI
    void loadFrame(bool load = true);

protected:
    // Capture user input (Override default action)
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *) override;
    int frameCurrent, frameMax, backgroundRefFrame;
    uiDisplay displayMode;
    QThread* workerThread;

    void checkCurrentFrame();
    void changeSettings();

    // UI & Modes
    uiMode Mode;
    QPixmap displayFrame, displayBackground;
    bool backgroundDefined, dimentionsDefined;
    std::string fileName;

    //Statusbar
    QLabel* status_mouse_x, * status_mouse_y, * status_mode;

    // Background mode
    double backgroundClicks [5];
    // [x1, y1, x2, y2, clicks], scaled units (0,1) for mouse clicks

    // Settings
    double settings_threshold, settings_erode_iterations;

signals:
    void shutdown();
    void requestFrame(int, MainWindow::uiDisplay);
    void setBackground(double *, int);
    void loadVideo(std::string);
    void updateSettings(double*); // Pass UI options to worker thread

private slots:
    // UI slots
    void on_loadVideo_clicked();
    void on_pushButton_clicked();
    void on_ViewMode_currentIndexChanged(int index);
    void showFrame(int, QPixmap);
    void refreshBackgroundImage(QPixmap);

    void on_Track_B_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_threshold_textChanged();
    void on_erosionIterations_textChanged();
    void on_playButton_clicked();
    void on_plotPB_clicked();
};

Q_DECLARE_METATYPE(std::string);
Q_DECLARE_METATYPE(MainWindow::uiDisplay); // This must be after class declaration

#endif // MAINWINDOW_H
