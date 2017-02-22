/****************************************************************************
** Meta object code from reading C++ file 'imagedisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imagedisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagedisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageDisplay_t {
    QByteArrayData data[8];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageDisplay_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageDisplay_t qt_meta_stringdata_ImageDisplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ImageDisplay"
QT_MOC_LITERAL(1, 13, 9), // "modifyBox"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "boxHighlight"
QT_MOC_LITERAL(4, 37, 14), // "boxUnhighlight"
QT_MOC_LITERAL(5, 52, 6), // "delBox"
QT_MOC_LITERAL(6, 59, 9), // "selectBox"
QT_MOC_LITERAL(7, 69, 3) // "num"

    },
    "ImageDisplay\0modifyBox\0\0boxHighlight\0"
    "boxUnhighlight\0delBox\0selectBox\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       3,    1,   48,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   54,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void ImageDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageDisplay *_t = static_cast<ImageDisplay *>(_o);
        switch (_id) {
        case 0: _t->modifyBox((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->boxHighlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->boxUnhighlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->delBox(); break;
        case 4: _t->selectBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageDisplay::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageDisplay::modifyBox)) {
                *result = 0;
            }
        }
        {
            typedef void (ImageDisplay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageDisplay::boxHighlight)) {
                *result = 1;
            }
        }
        {
            typedef void (ImageDisplay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageDisplay::boxUnhighlight)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ImageDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageDisplay.data,
      qt_meta_data_ImageDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageDisplay.stringdata))
        return static_cast<void*>(const_cast< ImageDisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ImageDisplay::modifyBox(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageDisplay::boxHighlight(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageDisplay::boxUnhighlight(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
