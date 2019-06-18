/****************************************************************************
** Meta object code from reading C++ file 'lab10.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab10.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lab10.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lab10_t {
    QByteArrayData data[15];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lab10_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lab10_t qt_meta_stringdata_lab10 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "lab10"
QT_MOC_LITERAL(1, 6, 11), // "enableModeA"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "enableModeB"
QT_MOC_LITERAL(4, 31, 18), // "moveTapeToPlaylist"
QT_MOC_LITERAL(5, 50, 10), // "deleteTape"
QT_MOC_LITERAL(6, 61, 10), // "updateTape"
QT_MOC_LITERAL(7, 72, 4), // "undo"
QT_MOC_LITERAL(8, 77, 4), // "redo"
QT_MOC_LITERAL(9, 82, 11), // "filterTapes"
QT_MOC_LITERAL(10, 94, 16), // "populatePlaylist"
QT_MOC_LITERAL(11, 111, 7), // "addTape"
QT_MOC_LITERAL(12, 119, 8), // "nextTape"
QT_MOC_LITERAL(13, 128, 9), // "playTapes"
QT_MOC_LITERAL(14, 138, 4) // "exit"

    },
    "lab10\0enableModeA\0\0enableModeB\0"
    "moveTapeToPlaylist\0deleteTape\0updateTape\0"
    "undo\0redo\0filterTapes\0populatePlaylist\0"
    "addTape\0nextTape\0playTapes\0exit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lab10[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lab10::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lab10 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enableModeA(); break;
        case 1: _t->enableModeB(); break;
        case 2: _t->moveTapeToPlaylist(); break;
        case 3: _t->deleteTape(); break;
        case 4: _t->updateTape(); break;
        case 5: _t->undo(); break;
        case 6: _t->redo(); break;
        case 7: _t->filterTapes(); break;
        case 8: _t->populatePlaylist(); break;
        case 9: _t->addTape(); break;
        case 10: _t->nextTape(); break;
        case 11: _t->playTapes(); break;
        case 12: _t->exit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject lab10::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_lab10.data,
    qt_meta_data_lab10,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lab10::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lab10::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lab10.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int lab10::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
