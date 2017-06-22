/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../2DIndividual/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "frameRequest"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 24), // "MainWindow::MODE_DISPLAY"
QT_MOC_LITERAL(4, 50, 13), // "backgroundSet"
QT_MOC_LITERAL(5, 64, 7), // "double*"
QT_MOC_LITERAL(6, 72, 9), // "videoLoad"
QT_MOC_LITERAL(7, 82, 11), // "std::string"
QT_MOC_LITERAL(8, 94, 9), // "videoPlay"
QT_MOC_LITERAL(9, 104, 9), // "videoStop"
QT_MOC_LITERAL(10, 114, 14), // "settingsUpdate"
QT_MOC_LITERAL(11, 129, 20), // "on_loadVideo_clicked"
QT_MOC_LITERAL(12, 150, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 172, 31), // "on_ViewMode_currentIndexChanged"
QT_MOC_LITERAL(14, 204, 5), // "index"
QT_MOC_LITERAL(15, 210, 9), // "showFrame"
QT_MOC_LITERAL(16, 220, 17), // "backgroundRefresh"
QT_MOC_LITERAL(17, 238, 18), // "on_Track_B_clicked"
QT_MOC_LITERAL(18, 257, 24), // "on_threshold_textChanged"
QT_MOC_LITERAL(19, 282, 32), // "on_erosionIterations_textChanged"
QT_MOC_LITERAL(20, 315, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(21, 337, 13) // "consoleOutput"

    },
    "MainWindow\0frameRequest\0\0"
    "MainWindow::MODE_DISPLAY\0backgroundSet\0"
    "double*\0videoLoad\0std::string\0videoPlay\0"
    "videoStop\0settingsUpdate\0on_loadVideo_clicked\0"
    "on_pushButton_clicked\0"
    "on_ViewMode_currentIndexChanged\0index\0"
    "showFrame\0backgroundRefresh\0"
    "on_Track_B_clicked\0on_threshold_textChanged\0"
    "on_erosionIterations_textChanged\0"
    "on_playButton_clicked\0consoleOutput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       4,    2,   99,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       8,    1,  107,    2, 0x06 /* Public */,
       9,    0,  110,    2, 0x06 /* Public */,
      10,    1,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  114,    2, 0x08 /* Private */,
      12,    0,  115,    2, 0x08 /* Private */,
      13,    1,  116,    2, 0x08 /* Private */,
      15,    2,  119,    2, 0x08 /* Private */,
      16,    1,  124,    2, 0x08 /* Private */,
      17,    0,  127,    2, 0x08 /* Private */,
      18,    0,  128,    2, 0x08 /* Private */,
      19,    0,  129,    2, 0x08 /* Private */,
      20,    0,  130,    2, 0x08 /* Private */,
      21,    1,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    2,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MainWindow::MODE_DISPLAY(*)>(_a[2]))); break;
        case 1: _t->backgroundSet((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->videoLoad((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->videoPlay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->videoStop(); break;
        case 5: _t->settingsUpdate((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 6: _t->on_loadVideo_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_ViewMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->showFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        case 10: _t->backgroundRefresh((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 11: _t->on_Track_B_clicked(); break;
        case 12: _t->on_threshold_textChanged(); break;
        case 13: _t->on_erosionIterations_textChanged(); break;
        case 14: _t->on_playButton_clicked(); break;
        case 15: _t->consoleOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MainWindow::MODE_DISPLAY >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::string >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int , MainWindow::MODE_DISPLAY );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::frameRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(double * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::backgroundSet)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::videoLoad)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::videoPlay)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::videoStop)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::settingsUpdate)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::frameRequest(int _t1, MainWindow::MODE_DISPLAY _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::backgroundSet(double * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::videoLoad(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::videoPlay(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::videoStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::settingsUpdate(double * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
