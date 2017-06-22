#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T12:51:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2DIndividual
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#use in Ubuntu
#INCLUDEPATH += -I/usr/local/include/opencv
#LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_viz -lopencv_core

#use on Windows (ctrl+/ to toggle)
INCLUDEPATH += C:\cv3\opencv\build\include
LIBS += -LC:\opencv-build\lib \
    -lopencv_core320.dll \
    -lopencv_highgui320.dll \
    -lopencv_imgcodecs320.dll \
    -lopencv_imgproc320.dll \
    -lopencv_features2d320.dll \
    -lopencv_calib3d320.dll \
    -lopencv_stitching320.dll \
    -lopencv_objdetect320.dll \
    -lopencv_superres320.dll \
    -lopencv_videostab320.dll \
    -lopencv_shape320.dll \
    -lopencv_video320.dll \
    -lopencv_photo320.dll \
    -lopencv_ml320.dll \
    -lopencv_imgproc320.dll \
    -lopencv_flann320.dll \
    -lopencv_videoio320.dll

SOURCES += main.cpp\
        mainwindow.cpp \
    detection.cpp

HEADERS  += mainwindow.h \
    detection.h

FORMS    += mainwindow.ui
