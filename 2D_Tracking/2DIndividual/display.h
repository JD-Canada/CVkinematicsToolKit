#ifndef DISPLAY_H
#define DISPLAY_H
#include <QThread>



class Display  : public QThread //inherit from QThread
{


public:
    Display();
    explicit plotThread(QObject *parent = 0);
    void plot();
public slots:

};

#endif // DISPLAY_H
