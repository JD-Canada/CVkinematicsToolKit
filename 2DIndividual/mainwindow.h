#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QThread>

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
    // Controls what data is printed on frame image
    enum MODE_DISPLAY {Frame_NORMAL, Frame_SUBTRACTION, Frame_BINARY, Frame_SKIP};
    // Controls UI options
    enum MODE_UI {Mode_NAVIGATE, Mode_ANALYSIS, Mode_BACKGROUND, Mode_DIMENTIONS};

    // Showframe on UI
    void loadFrame(bool load = true);

protected:
    // Capture user input (Override default action)
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *) override;
    int frameCurrent, frameMax, backgroundRefFrame, console_output_length;
    MODE_DISPLAY mode_display;
    QThread* workerThread;

    void checkCurrentFrame();
    void changeSettings();

    // UI & Modes
    MODE_UI mode_ui;
    QPixmap displayFrame, displayBackground;
    bool backgroundDefined, dimentionsDefined;
    std::string fileName;
    QString console_output;

    //Statusbar
    QLabel* status_mouse_x, * status_mouse_y, * status_mode;

    // Background mode
    double background_definition [5];

    // Settings
    double settings_threshold, settings_erode_iterations;

signals:
    void frameRequest(int, MainWindow::MODE_DISPLAY);
    void backgroundSet(double *, int);
    void videoLoad(std::string);
    void videoPlay(bool); // bool true = analysis, false = playback
    void videoStop(); // stop video playback/analysis
    void settingsUpdate(double*); // Pass UI options to worker thread

private slots:
    // UI slots
    void on_loadVideo_clicked();
    void on_pushButton_clicked();
    void on_ViewMode_currentIndexChanged(int index);
    void showFrame(int, QPixmap);
    void backgroundRefresh(QPixmap);

    void on_Track_B_clicked();

    void on_threshold_textChanged();
    void on_erosionIterations_textChanged();
    void on_playButton_clicked();
    void consoleOutput(QString);
};

Q_DECLARE_METATYPE(std::string);
Q_DECLARE_METATYPE(MainWindow::MODE_DISPLAY); // This must be after class declaration
Q_DECLARE_METATYPE(QString);

#endif // MAINWINDOW_H
