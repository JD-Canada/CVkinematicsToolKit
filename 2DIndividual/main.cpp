#include "mainwindow.h"
#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Register QMATAAYPES before declaring in header files
    // Necessary to do this with non-standard objects we use in signals
    qRegisterMetaType<MainWindow::MODE_DISPLAY>();
    qRegisterMetaType<std::string>();


    return a.exec();
}
