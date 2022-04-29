/****************************************************************************
** Meta object code from reading C++ file 'SideWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Labor/GUI/SideWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SideWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cagd__SideWidget_t {
    const uint offsetsAndSize[40];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__SideWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__SideWidget_t qt_meta_stringdata_cagd__SideWidget = {
    {
QT_MOC_LITERAL(0, 16), // "cagd::SideWidget"
QT_MOC_LITERAL(17, 12), // "set_cc_limit"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 5), // "limit"
QT_MOC_LITERAL(37, 25), // "set_cc_controlPoint_limit"
QT_MOC_LITERAL(63, 26), // "set_cc_controlPoint_values"
QT_MOC_LITERAL(90, 1), // "x"
QT_MOC_LITERAL(92, 1), // "y"
QT_MOC_LITERAL(94, 1), // "z"
QT_MOC_LITERAL(96, 11), // "set_e_value"
QT_MOC_LITERAL(108, 1), // "e"
QT_MOC_LITERAL(110, 15), // "set_speed_value"
QT_MOC_LITERAL(126, 5), // "speed"
QT_MOC_LITERAL(132, 16), // "set_speed2_value"
QT_MOC_LITERAL(149, 6), // "speed2"
QT_MOC_LITERAL(156, 9), // "set_point"
QT_MOC_LITERAL(166, 5), // "value"
QT_MOC_LITERAL(172, 21), // "set_zeroth_derivative"
QT_MOC_LITERAL(194, 20), // "set_first_derivative"
QT_MOC_LITERAL(215, 21) // "set_second_derivative"

    },
    "cagd::SideWidget\0set_cc_limit\0\0limit\0"
    "set_cc_controlPoint_limit\0"
    "set_cc_controlPoint_values\0x\0y\0z\0"
    "set_e_value\0e\0set_speed_value\0speed\0"
    "set_speed2_value\0speed2\0set_point\0"
    "value\0set_zeroth_derivative\0"
    "set_first_derivative\0set_second_derivative"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__SideWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x0a,    1 /* Public */,
       4,    1,   77,    2, 0x0a,    3 /* Public */,
       5,    3,   80,    2, 0x0a,    5 /* Public */,
       9,    1,   87,    2, 0x0a,    9 /* Public */,
      11,    1,   90,    2, 0x0a,   11 /* Public */,
      13,    1,   93,    2, 0x0a,   13 /* Public */,
      15,    1,   96,    2, 0x0a,   15 /* Public */,
      17,    1,   99,    2, 0x0a,   17 /* Public */,
      18,    1,  102,    2, 0x0a,   19 /* Public */,
      19,    1,  105,    2, 0x0a,   21 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,

       0        // eod
};

void cagd::SideWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SideWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->set_cc_limit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_cc_controlPoint_limit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_cc_controlPoint_values((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->set_e_value((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_speed_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_speed2_value((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->set_point((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->set_zeroth_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->set_first_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->set_second_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cagd::SideWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_cagd__SideWidget.offsetsAndSize,
    qt_meta_data_cagd__SideWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cagd__SideWidget_t
, QtPrivate::TypeAndForceComplete<SideWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *cagd::SideWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cagd::SideWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cagd__SideWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::SideWidget"))
        return static_cast< Ui::SideWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int cagd::SideWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
