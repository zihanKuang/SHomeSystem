/****************************************************************************
** Meta object code from reading C++ file 'tabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SHomeSystem/tabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TabWidget_t {
    QByteArrayData data[15];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabWidget_t qt_meta_stringdata_TabWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TabWidget"
QT_MOC_LITERAL(1, 10, 28), // "onHostAirEditEditingFinished"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 30), // "onLivingAirEditEditingFinished"
QT_MOC_LITERAL(4, 71, 30), // "onSecondAirEditEditingFinished"
QT_MOC_LITERAL(5, 102, 27), // "onHostAirTimerButtonClicked"
QT_MOC_LITERAL(6, 130, 29), // "onLivingAirTimerButtonClicked"
QT_MOC_LITERAL(7, 160, 29), // "onSecondAirTimerButtonClicked"
QT_MOC_LITERAL(8, 190, 27), // "onHostAirPowerButtonClicked"
QT_MOC_LITERAL(9, 218, 29), // "onLivingAirPowerButtonClicked"
QT_MOC_LITERAL(10, 248, 29), // "onSecondAirPowerButtonClicked"
QT_MOC_LITERAL(11, 278, 20), // "onHostAirModeChanged"
QT_MOC_LITERAL(12, 299, 5), // "index"
QT_MOC_LITERAL(13, 305, 22), // "onLivingAirModeChanged"
QT_MOC_LITERAL(14, 328, 22) // "onSecondAirModeChanged"

    },
    "TabWidget\0onHostAirEditEditingFinished\0"
    "\0onLivingAirEditEditingFinished\0"
    "onSecondAirEditEditingFinished\0"
    "onHostAirTimerButtonClicked\0"
    "onLivingAirTimerButtonClicked\0"
    "onSecondAirTimerButtonClicked\0"
    "onHostAirPowerButtonClicked\0"
    "onLivingAirPowerButtonClicked\0"
    "onSecondAirPowerButtonClicked\0"
    "onHostAirModeChanged\0index\0"
    "onLivingAirModeChanged\0onSecondAirModeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      13,    1,   86,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void TabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabWidget *_t = static_cast<TabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onHostAirEditEditingFinished(); break;
        case 1: _t->onLivingAirEditEditingFinished(); break;
        case 2: _t->onSecondAirEditEditingFinished(); break;
        case 3: _t->onHostAirTimerButtonClicked(); break;
        case 4: _t->onLivingAirTimerButtonClicked(); break;
        case 5: _t->onSecondAirTimerButtonClicked(); break;
        case 6: _t->onHostAirPowerButtonClicked(); break;
        case 7: _t->onLivingAirPowerButtonClicked(); break;
        case 8: _t->onSecondAirPowerButtonClicked(); break;
        case 9: _t->onHostAirModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onLivingAirModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onSecondAirModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabWidget.data,
      qt_meta_data_TabWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TabWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
