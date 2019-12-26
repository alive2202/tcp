/****************************************************************************
** Meta object code from reading C++ file 'tcp_server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcp_server/tcp_server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tcp_server_t {
    QByteArrayData data[7];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tcp_server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tcp_server_t qt_meta_stringdata_tcp_server = {
    {
QT_MOC_LITERAL(0, 0, 10), // "tcp_server"
QT_MOC_LITERAL(1, 11, 11), // "startServer"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "readSocket"
QT_MOC_LITERAL(4, 35, 18), // "incomingConnection"
QT_MOC_LITERAL(5, 54, 16), // "socketDescriptor"
QT_MOC_LITERAL(6, 71, 14) // "justDisconnect"

    },
    "tcp_server\0startServer\0\0readSocket\0"
    "incomingConnection\0socketDescriptor\0"
    "justDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tcp_server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void tcp_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tcp_server *_t = static_cast<tcp_server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startServer(); break;
        case 1: _t->readSocket(); break;
        case 2: _t->incomingConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->justDisconnect(); break;
        default: ;
        }
    }
}

const QMetaObject tcp_server::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_tcp_server.data,
      qt_meta_data_tcp_server,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tcp_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcp_server::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tcp_server.stringdata0))
        return static_cast<void*>(const_cast< tcp_server*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int tcp_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
