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
    char stringdata0[376];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "shutdown"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "requestFrame"
QT_MOC_LITERAL(4, 34, 21), // "MainWindow::uiDisplay"
QT_MOC_LITERAL(5, 56, 13), // "setBackground"
QT_MOC_LITERAL(6, 70, 7), // "double*"
QT_MOC_LITERAL(7, 78, 9), // "loadVideo"
QT_MOC_LITERAL(8, 88, 11), // "std::string"
QT_MOC_LITERAL(9, 100, 14), // "updateSettings"
QT_MOC_LITERAL(10, 115, 20), // "on_loadVideo_clicked"
QT_MOC_LITERAL(11, 136, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 158, 31), // "on_ViewMode_currentIndexChanged"
QT_MOC_LITERAL(13, 190, 5), // "index"
QT_MOC_LITERAL(14, 196, 9), // "showFrame"
QT_MOC_LITERAL(15, 206, 22), // "refreshBackgroundImage"
QT_MOC_LITERAL(16, 229, 18), // "on_Track_B_clicked"
QT_MOC_LITERAL(17, 248, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(18, 272, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(19, 296, 24), // "on_threshold_textChanged"
QT_MOC_LITERAL(20, 321, 32), // "on_erosionIterations_textChanged"
QT_MOC_LITERAL(21, 354, 21) // "on_playButton_clicked"

    },
    "MainWindow\0shutdown\0\0requestFrame\0"
    "MainWindow::uiDisplay\0setBackground\0"
    "double*\0loadVideo\0std::string\0"
    "updateSettings\0on_loadVideo_clicked\0"
    "on_pushButton_clicked\0"
    "on_ViewMode_currentIndexChanged\0index\0"
    "showFrame\0refreshBackgroundImage\0"
    "on_Track_B_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_2_clicked\0"
    "on_threshold_textChanged\0"
    "on_erosionIterations_textChanged\0"
    "on_playButton_clicked"
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
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    2,   95,    2, 0x06 /* Public */,
       5,    2,  100,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
       9,    1,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  111,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    1,  113,    2, 0x08 /* Private */,
      14,    2,  116,    2, 0x08 /* Private */,
      15,    1,  121,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    0,  126,    2, 0x08 /* Private */,
      19,    0,  127,    2, 0x08 /* Private */,
      20,    0,  128,    2, 0x08 /* Private */,
      21,    0,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    2,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shutdown(); break;
        case 1: _t->requestFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MainWindow::uiDisplay(*)>(_a[2]))); break;
        case 2: _t->setBackground((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->loadVideo((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->updateSettings((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 5: _t->on_loadVideo_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_ViewMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->showFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        case 9: _t->refreshBackgroundImage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 10: _t->on_Track_B_clicked(); break;
        case 11: _t->on_pushButton_3_clicked(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        case 13: _t->on_threshold_textChanged(); break;
        case 14: _t->on_erosionIterations_textChanged(); break;
        case 15: _t->on_playButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MainWindow::uiDisplay >(); break;
            }
            break;
        case 3:
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
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::shutdown)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , MainWindow::uiDisplay );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::requestFrame)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(double * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::setBackground)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::loadVideo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::updateSettings)) {
                *result = 4;
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
void MainWindow::shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::requestFrame(int _t1, MainWindow::uiDisplay _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::setBackground(double * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::loadVideo(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::updateSettings(double * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
