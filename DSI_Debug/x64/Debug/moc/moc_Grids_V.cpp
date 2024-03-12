/****************************************************************************
** Meta object code from reading C++ file 'Grids_V.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Grids_V.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Grids_V.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Grids_V_t {
    QByteArrayData data[14];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Grids_V_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Grids_V_t qt_meta_stringdata_Grids_V = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Grids_V"
QT_MOC_LITERAL(1, 8, 15), // "on_open_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "on_close_clicked"
QT_MOC_LITERAL(4, 42, 16), // "on_clear_clicked"
QT_MOC_LITERAL(5, 59, 14), // "on_IDW_clicked"
QT_MOC_LITERAL(6, 74, 12), // "Showpointset"
QT_MOC_LITERAL(7, 87, 9), // "Creatbody"
QT_MOC_LITERAL(8, 97, 11), // "CreateGrids"
QT_MOC_LITERAL(9, 109, 12), // "CreateGrids1"
QT_MOC_LITERAL(10, 122, 9), // "G_IN_Poly"
QT_MOC_LITERAL(11, 132, 3), // "MMM"
QT_MOC_LITERAL(12, 136, 10), // "paintEvent"
QT_MOC_LITERAL(13, 147, 12) // "QPaintEvent*"

    },
    "Grids_V\0on_open_clicked\0\0on_close_clicked\0"
    "on_clear_clicked\0on_IDW_clicked\0"
    "Showpointset\0Creatbody\0CreateGrids\0"
    "CreateGrids1\0G_IN_Poly\0MMM\0paintEvent\0"
    "QPaintEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grids_V[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 13,    2,

       0        // eod
};

void Grids_V::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Grids_V *_t = static_cast<Grids_V *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_open_clicked(); break;
        case 1: _t->on_close_clicked(); break;
        case 2: _t->on_clear_clicked(); break;
        case 3: _t->on_IDW_clicked(); break;
        case 4: _t->Showpointset(); break;
        case 5: _t->Creatbody(); break;
        case 6: _t->CreateGrids(); break;
        case 7: _t->CreateGrids1(); break;
        case 8: _t->G_IN_Poly(); break;
        case 9: _t->MMM(); break;
        case 10: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Grids_V::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Grids_V.data,
      qt_meta_data_Grids_V,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Grids_V::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Grids_V::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Grids_V.stringdata0))
        return static_cast<void*>(const_cast< Grids_V*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Grids_V::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
