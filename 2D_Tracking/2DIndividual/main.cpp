#include "mainwindow.h"
#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qRegisterMetaType<MainWindow::uiDisplay>();
    qRegisterMetaType<std::string>();


    return a.exec();
}
