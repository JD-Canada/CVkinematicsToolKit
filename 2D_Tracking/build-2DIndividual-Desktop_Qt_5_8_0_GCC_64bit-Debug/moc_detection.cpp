/****************************************************************************
** Meta object code from reading C++ file 'detection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../2DIndividual/detection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Detection_t {
    QByteArrayData data[11];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Detection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Detection_t qt_meta_stringdata_Detection = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Detection"
QT_MOC_LITERAL(1, 10, 9), // "showFrame"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 22), // "refreshBackgroundImage"
QT_MOC_LITERAL(4, 44, 12), // "requestFrame"
QT_MOC_LITERAL(5, 57, 21), // "MainWindow::uiDisplay"
QT_MOC_LITERAL(6, 79, 9), // "loadVideo"
QT_MOC_LITERAL(7, 89, 11), // "std::string"
QT_MOC_LITERAL(8, 101, 13), // "setBackground"
QT_MOC_LITERAL(9, 115, 7), // "double*"
QT_MOC_LITERAL(10, 123, 14) // "updateSettings"

    },
    "Detection\0showFrame\0\0refreshBackgroundImage\0"
    "requestFrame\0MainWindow::uiDisplay\0"
    "loadVideo\0std::string\0setBackground\0"
    "double*\0updateSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Detection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       3,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   52,    2, 0x08 /* Private */,
       6,    1,   57,    2, 0x08 /* Private */,
       8,    2,   60,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    2,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void Detection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Detection *_t = static_cast<Detection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        case 1: _t->refreshBackgroundImage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 2: _t->requestFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< MainWindow::uiDisplay(*)>(_a[2]))); break;
        case 3: _t->loadVideo((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->setBackground((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateSettings((*reinterpret_cast< double*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            typedef void (Detection::*_t)(int , QPixmap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Detection::showFrame)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Detection::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Detection::refreshBackgroundImage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Detection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Detection.data,
      qt_meta_data_Detection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Detection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Detection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Detection.stringdata0))
        return static_cast<void*>(const_cast< Detection*>(this));
    return QObject::qt_metacast(_clname);
}

int Detection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Detection::showFrame(int _t1, QPixmap _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Detection::refreshBackgroundImage(QPixmap _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
