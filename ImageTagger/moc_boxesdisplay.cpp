/****************************************************************************
** Meta object code from reading C++ file 'boxesdisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "boxesdisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boxesdisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoxesDisplay_t {
    QByteArrayData data[14];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoxesDisplay_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoxesDisplay_t qt_meta_stringdata_BoxesDisplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BoxesDisplay"
QT_MOC_LITERAL(1, 13, 5), // "rmBox"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "selectBox"
QT_MOC_LITERAL(4, 30, 3), // "num"
QT_MOC_LITERAL(5, 34, 9), // "modifyBox"
QT_MOC_LITERAL(6, 44, 2), // "x1"
QT_MOC_LITERAL(7, 47, 2), // "y1"
QT_MOC_LITERAL(8, 50, 2), // "x2"
QT_MOC_LITERAL(9, 53, 2), // "y2"
QT_MOC_LITERAL(10, 56, 12), // "boxHighlight"
QT_MOC_LITERAL(11, 69, 1), // "p"
QT_MOC_LITERAL(12, 71, 14), // "boxUnhighlight"
QT_MOC_LITERAL(13, 86, 6) // "delBox"

    },
    "BoxesDisplay\0rmBox\0\0selectBox\0num\0"
    "modifyBox\0x1\0y1\0x2\0y2\0boxHighlight\0p\0"
    "boxUnhighlight\0delBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoxesDisplay[] = {

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
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    4,   48,    2, 0x0a /* Public */,
      10,    1,   57,    2, 0x0a /* Public */,
      12,    1,   60,    2, 0x0a /* Public */,
      13,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void BoxesDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoxesDisplay *_t = static_cast<BoxesDisplay *>(_o);
        switch (_id) {
        case 0: _t->rmBox(); break;
        case 1: _t->selectBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->modifyBox((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->boxHighlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->boxUnhighlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->delBox(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BoxesDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoxesDisplay::rmBox)) {
                *result = 0;
            }
        }
        {
            typedef void (BoxesDisplay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoxesDisplay::selectBox)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject BoxesDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BoxesDisplay.data,
      qt_meta_data_BoxesDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BoxesDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoxesDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BoxesDisplay.stringdata))
        return static_cast<void*>(const_cast< BoxesDisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int BoxesDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BoxesDisplay::rmBox()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BoxesDisplay::selectBox(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
