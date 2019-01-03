/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "on_directionUp_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 25), // "on_directionRight_clicked"
QT_MOC_LITERAL(4, 61, 24), // "on_directionDown_clicked"
QT_MOC_LITERAL(5, 86, 24), // "on_directionLeft_clicked"
QT_MOC_LITERAL(6, 111, 24), // "on_removeCommand_clicked"
QT_MOC_LITERAL(7, 136, 21), // "on_playerWait_clicked"
QT_MOC_LITERAL(8, 158, 23), // "on_missionStart_clicked"
QT_MOC_LITERAL(9, 182, 24), // "on_missionCancel_clicked"
QT_MOC_LITERAL(10, 207, 22), // "on_missionStep_clicked"
QT_MOC_LITERAL(11, 230, 27), // "on_missionAutomatic_clicked"
QT_MOC_LITERAL(12, 258, 23), // "on_missionPause_clicked"
QT_MOC_LITERAL(13, 282, 23), // "on_changeColony_clicked"
QT_MOC_LITERAL(14, 306, 19), // "repititions_changed"
QT_MOC_LITERAL(15, 326, 10), // "p_new_text"
QT_MOC_LITERAL(16, 337, 8), // "scroll_x"
QT_MOC_LITERAL(17, 346, 11), // "p_new_value"
QT_MOC_LITERAL(18, 358, 8), // "scroll_y"
QT_MOC_LITERAL(19, 367, 14), // "scroll_program"
QT_MOC_LITERAL(20, 382, 19) // "automatic_mode_step"

    },
    "MainWindow\0on_directionUp_clicked\0\0"
    "on_directionRight_clicked\0"
    "on_directionDown_clicked\0"
    "on_directionLeft_clicked\0"
    "on_removeCommand_clicked\0on_playerWait_clicked\0"
    "on_missionStart_clicked\0"
    "on_missionCancel_clicked\0"
    "on_missionStep_clicked\0"
    "on_missionAutomatic_clicked\0"
    "on_missionPause_clicked\0on_changeColony_clicked\0"
    "repititions_changed\0p_new_text\0scroll_x\0"
    "p_new_value\0scroll_y\0scroll_program\0"
    "automatic_mode_step"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      18,    1,  117,    2, 0x08 /* Private */,
      19,    1,  120,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_directionUp_clicked(); break;
        case 1: _t->on_directionRight_clicked(); break;
        case 2: _t->on_directionDown_clicked(); break;
        case 3: _t->on_directionLeft_clicked(); break;
        case 4: _t->on_removeCommand_clicked(); break;
        case 5: _t->on_playerWait_clicked(); break;
        case 6: _t->on_missionStart_clicked(); break;
        case 7: _t->on_missionCancel_clicked(); break;
        case 8: _t->on_missionStep_clicked(); break;
        case 9: _t->on_missionAutomatic_clicked(); break;
        case 10: _t->on_missionPause_clicked(); break;
        case 11: _t->on_changeColony_clicked(); break;
        case 12: _t->repititions_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->scroll_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->scroll_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->scroll_program((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->automatic_mode_step(); break;
        default: ;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
