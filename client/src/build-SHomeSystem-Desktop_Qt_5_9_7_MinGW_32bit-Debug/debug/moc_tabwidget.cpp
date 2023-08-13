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
    QByteArrayData data[52];
    char stringdata0[1164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabWidget_t qt_meta_stringdata_TabWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TabWidget"
QT_MOC_LITERAL(1, 10, 19), // "sendAirDataToServer"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "Device::State"
QT_MOC_LITERAL(4, 45, 5), // "state"
QT_MOC_LITERAL(5, 51, 11), // "temperature"
QT_MOC_LITERAL(6, 63, 10), // "QDateTime&"
QT_MOC_LITERAL(7, 74, 9), // "timestamp"
QT_MOC_LITERAL(8, 84, 23), // "AirConditioner::AirMode"
QT_MOC_LITERAL(9, 108, 4), // "mode"
QT_MOC_LITERAL(10, 113, 21), // "sendLightDataToServer"
QT_MOC_LITERAL(11, 135, 16), // "Light::LightMode"
QT_MOC_LITERAL(12, 152, 24), // "sendHumidityDataToServer"
QT_MOC_LITERAL(13, 177, 8), // "humidity"
QT_MOC_LITERAL(14, 186, 28), // "onHostAirEditEditingFinished"
QT_MOC_LITERAL(15, 215, 30), // "onLivingAirEditEditingFinished"
QT_MOC_LITERAL(16, 246, 30), // "onSecondAirEditEditingFinished"
QT_MOC_LITERAL(17, 277, 28), // "onLivingAirTimeButtonClicked"
QT_MOC_LITERAL(18, 306, 26), // "onHostAirTimeButtonClicked"
QT_MOC_LITERAL(19, 333, 28), // "onSecondAirTimeButtonClicked"
QT_MOC_LITERAL(20, 362, 27), // "onHostAirPowerButtonClicked"
QT_MOC_LITERAL(21, 390, 29), // "onLivingAirPowerButtonClicked"
QT_MOC_LITERAL(22, 420, 29), // "onSecondAirPowerButtonClicked"
QT_MOC_LITERAL(23, 450, 20), // "onHostAirModeChanged"
QT_MOC_LITERAL(24, 471, 5), // "index"
QT_MOC_LITERAL(25, 477, 22), // "onLivingAirModeChanged"
QT_MOC_LITERAL(26, 500, 22), // "onSecondAirModeChanged"
QT_MOC_LITERAL(27, 523, 24), // "updateHostAirStatusLabel"
QT_MOC_LITERAL(28, 548, 26), // "updateLivingAirStatusLabel"
QT_MOC_LITERAL(29, 575, 26), // "updateSecondAirStatusLabel"
QT_MOC_LITERAL(30, 602, 29), // "updateHostHumidityStatusLabel"
QT_MOC_LITERAL(31, 632, 31), // "updateLivingHumidityStatusLabel"
QT_MOC_LITERAL(32, 664, 24), // "onHostHumidityBtnClicked"
QT_MOC_LITERAL(33, 689, 26), // "onLivingHumidityBtnClicked"
QT_MOC_LITERAL(34, 716, 27), // "onHostHumiditySliderChanged"
QT_MOC_LITERAL(35, 744, 5), // "value"
QT_MOC_LITERAL(36, 750, 29), // "onLivingHumiditySliderChanged"
QT_MOC_LITERAL(37, 780, 25), // "onHostHumiditySpinChanged"
QT_MOC_LITERAL(38, 806, 27), // "onLivingHumiditySpinChanged"
QT_MOC_LITERAL(39, 834, 29), // "onLivingLightTimerTimeChanged"
QT_MOC_LITERAL(40, 864, 4), // "time"
QT_MOC_LITERAL(41, 869, 27), // "onHostLightTimerTimeChanged"
QT_MOC_LITERAL(42, 897, 29), // "onSecondLightTimerTimeChanged"
QT_MOC_LITERAL(43, 927, 26), // "updateHostLightStatusLabel"
QT_MOC_LITERAL(44, 954, 28), // "updateLivingLightStatusLabel"
QT_MOC_LITERAL(45, 983, 28), // "updateSecondLightStatusLabel"
QT_MOC_LITERAL(46, 1012, 22), // "onHostLightModeChanged"
QT_MOC_LITERAL(47, 1035, 24), // "onLivingLightModeChanged"
QT_MOC_LITERAL(48, 1060, 24), // "onSecondLightModeChanged"
QT_MOC_LITERAL(49, 1085, 24), // "onHostLightButtonClicked"
QT_MOC_LITERAL(50, 1110, 26), // "onLivingLightButtonClicked"
QT_MOC_LITERAL(51, 1137, 26) // "onSecondLightButtonClicked"

    },
    "TabWidget\0sendAirDataToServer\0\0"
    "Device::State\0state\0temperature\0"
    "QDateTime&\0timestamp\0AirConditioner::AirMode\0"
    "mode\0sendLightDataToServer\0Light::LightMode\0"
    "sendHumidityDataToServer\0humidity\0"
    "onHostAirEditEditingFinished\0"
    "onLivingAirEditEditingFinished\0"
    "onSecondAirEditEditingFinished\0"
    "onLivingAirTimeButtonClicked\0"
    "onHostAirTimeButtonClicked\0"
    "onSecondAirTimeButtonClicked\0"
    "onHostAirPowerButtonClicked\0"
    "onLivingAirPowerButtonClicked\0"
    "onSecondAirPowerButtonClicked\0"
    "onHostAirModeChanged\0index\0"
    "onLivingAirModeChanged\0onSecondAirModeChanged\0"
    "updateHostAirStatusLabel\0"
    "updateLivingAirStatusLabel\0"
    "updateSecondAirStatusLabel\0"
    "updateHostHumidityStatusLabel\0"
    "updateLivingHumidityStatusLabel\0"
    "onHostHumidityBtnClicked\0"
    "onLivingHumidityBtnClicked\0"
    "onHostHumiditySliderChanged\0value\0"
    "onLivingHumiditySliderChanged\0"
    "onHostHumiditySpinChanged\0"
    "onLivingHumiditySpinChanged\0"
    "onLivingLightTimerTimeChanged\0time\0"
    "onHostLightTimerTimeChanged\0"
    "onSecondLightTimerTimeChanged\0"
    "updateHostLightStatusLabel\0"
    "updateLivingLightStatusLabel\0"
    "updateSecondLightStatusLabel\0"
    "onHostLightModeChanged\0onLivingLightModeChanged\0"
    "onSecondLightModeChanged\0"
    "onHostLightButtonClicked\0"
    "onLivingLightButtonClicked\0"
    "onSecondLightButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,  204,    2, 0x0a /* Public */,
      10,    3,  213,    2, 0x0a /* Public */,
      12,    3,  220,    2, 0x0a /* Public */,
      14,    0,  227,    2, 0x0a /* Public */,
      15,    0,  228,    2, 0x0a /* Public */,
      16,    0,  229,    2, 0x0a /* Public */,
      17,    0,  230,    2, 0x0a /* Public */,
      18,    0,  231,    2, 0x0a /* Public */,
      19,    0,  232,    2, 0x0a /* Public */,
      20,    0,  233,    2, 0x0a /* Public */,
      21,    0,  234,    2, 0x0a /* Public */,
      22,    0,  235,    2, 0x0a /* Public */,
      23,    1,  236,    2, 0x0a /* Public */,
      25,    1,  239,    2, 0x0a /* Public */,
      26,    1,  242,    2, 0x0a /* Public */,
      27,    0,  245,    2, 0x0a /* Public */,
      28,    0,  246,    2, 0x0a /* Public */,
      29,    0,  247,    2, 0x0a /* Public */,
      30,    0,  248,    2, 0x0a /* Public */,
      31,    0,  249,    2, 0x0a /* Public */,
      32,    0,  250,    2, 0x0a /* Public */,
      33,    0,  251,    2, 0x0a /* Public */,
      34,    1,  252,    2, 0x0a /* Public */,
      36,    1,  255,    2, 0x0a /* Public */,
      37,    1,  258,    2, 0x0a /* Public */,
      38,    1,  261,    2, 0x0a /* Public */,
      39,    1,  264,    2, 0x0a /* Public */,
      41,    1,  267,    2, 0x0a /* Public */,
      42,    1,  270,    2, 0x0a /* Public */,
      43,    0,  273,    2, 0x0a /* Public */,
      44,    0,  274,    2, 0x0a /* Public */,
      45,    0,  275,    2, 0x0a /* Public */,
      46,    1,  276,    2, 0x0a /* Public */,
      47,    1,  279,    2, 0x0a /* Public */,
      48,    1,  282,    2, 0x0a /* Public */,
      49,    0,  285,    2, 0x0a /* Public */,
      50,    0,  286,    2, 0x0a /* Public */,
      51,    0,  287,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, 0x80000000 | 6, 0x80000000 | 8,    4,    5,    7,    9,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6, 0x80000000 | 11,    4,    7,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, 0x80000000 | 6,    4,   13,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::QTime,   40,
    QMetaType::Void, QMetaType::QTime,   40,
    QMetaType::Void, QMetaType::QTime,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabWidget *_t = static_cast<TabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAirDataToServer((*reinterpret_cast< Device::State(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< AirConditioner::AirMode(*)>(_a[4]))); break;
        case 1: _t->sendLightDataToServer((*reinterpret_cast< Device::State(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< Light::LightMode(*)>(_a[3]))); break;
        case 2: _t->sendHumidityDataToServer((*reinterpret_cast< Device::State(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 3: _t->onHostAirEditEditingFinished(); break;
        case 4: _t->onLivingAirEditEditingFinished(); break;
        case 5: _t->onSecondAirEditEditingFinished(); break;
        case 6: _t->onLivingAirTimeButtonClicked(); break;
        case 7: _t->onHostAirTimeButtonClicked(); break;
        case 8: _t->onSecondAirTimeButtonClicked(); break;
        case 9: _t->onHostAirPowerButtonClicked(); break;
        case 10: _t->onLivingAirPowerButtonClicked(); break;
        case 11: _t->onSecondAirPowerButtonClicked(); break;
        case 12: _t->onHostAirModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->onLivingAirModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->onSecondAirModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->updateHostAirStatusLabel(); break;
        case 16: _t->updateLivingAirStatusLabel(); break;
        case 17: _t->updateSecondAirStatusLabel(); break;
        case 18: _t->updateHostHumidityStatusLabel(); break;
        case 19: _t->updateLivingHumidityStatusLabel(); break;
        case 20: _t->onHostHumidityBtnClicked(); break;
        case 21: _t->onLivingHumidityBtnClicked(); break;
        case 22: _t->onHostHumiditySliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->onLivingHumiditySliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->onHostHumiditySpinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->onLivingHumiditySpinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->onLivingLightTimerTimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 27: _t->onHostLightTimerTimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 28: _t->onSecondLightTimerTimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 29: _t->updateHostLightStatusLabel(); break;
        case 30: _t->updateLivingLightStatusLabel(); break;
        case 31: _t->updateSecondLightStatusLabel(); break;
        case 32: _t->onHostLightModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->onLivingLightModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->onSecondLightModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->onHostLightButtonClicked(); break;
        case 36: _t->onLivingLightButtonClicked(); break;
        case 37: _t->onSecondLightButtonClicked(); break;
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
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 38;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
