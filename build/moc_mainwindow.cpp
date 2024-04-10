/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[16];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainwindow"
QT_MOC_LITERAL(1, 11, 11), // "recive_text"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "size_t"
QT_MOC_LITERAL(4, 31, 11), // "std::string"
QT_MOC_LITERAL(5, 43, 3), // "pos"
QT_MOC_LITERAL(6, 47, 3), // "Run"
QT_MOC_LITERAL(7, 51, 4), // "exit"
QT_MOC_LITERAL(8, 56, 7), // "browser"
QT_MOC_LITERAL(9, 64, 11), // "modbus_mode"
QT_MOC_LITERAL(10, 76, 18), // "modbus_connect_rtu"
QT_MOC_LITERAL(11, 95, 21), // "modbus_disconnect_rtu"
QT_MOC_LITERAL(12, 117, 7), // "Monitor"
QT_MOC_LITERAL(13, 125, 21), // "Modbus_read_registers"
QT_MOC_LITERAL(14, 147, 14), // "enable_browser"
QT_MOC_LITERAL(15, 162, 5) // "About"

    },
    "mainwindow\0recive_text\0\0size_t\0"
    "std::string\0pos\0Run\0exit\0browser\0"
    "modbus_mode\0modbus_connect_rtu\0"
    "modbus_disconnect_rtu\0Monitor\0"
    "Modbus_read_registers\0enable_browser\0"
    "About"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x0a /* Public */,
       1,    2,   81,    2, 0x2a /* Public | MethodCloned */,
       6,    0,   86,    2, 0x0a /* Public */,
       7,    0,   87,    2, 0x0a /* Public */,
       8,    0,   88,    2, 0x0a /* Public */,
       9,    1,   89,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    1,   95,    2, 0x0a /* Public */,
      14,    1,   98,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, QMetaType::Int,    2,    2,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recive_text((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->recive_text((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 2: _t->Run(); break;
        case 3: _t->exit(); break;
        case 4: _t->browser(); break;
        case 5: _t->modbus_mode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->modbus_connect_rtu(); break;
        case 7: _t->modbus_disconnect_rtu(); break;
        case 8: _t->Monitor(); break;
        case 9: _t->Modbus_read_registers((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->enable_browser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->About(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainwindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_mainwindow.data,
    qt_meta_data_mainwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
