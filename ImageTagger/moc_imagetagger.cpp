/****************************************************************************
** Meta object code from reading C++ file 'imagetagger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imagetagger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagetagger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageTagger_t {
    QByteArrayData data[7];
    char stringdata[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageTagger_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageTagger_t qt_meta_stringdata_ImageTagger = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageTagger"
QT_MOC_LITERAL(1, 12, 8), // "saveTags"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "resetSkltn"
QT_MOC_LITERAL(4, 33, 9), // "prevImage"
QT_MOC_LITERAL(5, 43, 9), // "nextImage"
QT_MOC_LITERAL(6, 53, 10) // "cancelMove"

    },
    "ImageTagger\0saveTags\0\0resetSkltn\0"
    "prevImage\0nextImage\0cancelMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageTagger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageTagger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageTagger *_t = static_cast<ImageTagger *>(_o);
        switch (_id) {
        case 0: _t->saveTags(); break;
        case 1: _t->resetSkltn(); break;
        case 2: _t->prevImage(); break;
        case 3: _t->nextImage(); break;
        case 4: _t->cancelMove(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ImageTagger::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageTagger.data,
      qt_meta_data_ImageTagger,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageTagger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageTagger::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageTagger.stringdata))
        return static_cast<void*>(const_cast< ImageTagger*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImageTagger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
