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
    const uint offsetsAndSize[36];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__SideWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__SideWidget_t qt_meta_stringdata_cagd__SideWidget = {
    {
QT_MOC_LITERAL(0, 16), // "cagd::SideWidget"
QT_MOC_LITERAL(17, 11), // "setArcAlpha"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 11), // "setArcScale"
QT_MOC_LITERAL(42, 14), // "setArcDivCount"
QT_MOC_LITERAL(57, 7), // "setArcX"
QT_MOC_LITERAL(65, 7), // "setArcY"
QT_MOC_LITERAL(73, 7), // "setArcZ"
QT_MOC_LITERAL(81, 14), // "setPatchAlphaU"
QT_MOC_LITERAL(96, 14), // "setPatchAlphaV"
QT_MOC_LITERAL(111, 13), // "setPatchScale"
QT_MOC_LITERAL(125, 17), // "setPatchDivCountU"
QT_MOC_LITERAL(143, 17), // "setPatchDivCountV"
QT_MOC_LITERAL(161, 18), // "setPatchLineCountU"
QT_MOC_LITERAL(180, 18), // "setPatchLineCountV"
QT_MOC_LITERAL(199, 9), // "setPatchX"
QT_MOC_LITERAL(209, 9), // "setPatchY"
QT_MOC_LITERAL(219, 9) // "setPatchZ"

    },
    "cagd::SideWidget\0setArcAlpha\0\0setArcScale\0"
    "setArcDivCount\0setArcX\0setArcY\0setArcZ\0"
    "setPatchAlphaU\0setPatchAlphaV\0"
    "setPatchScale\0setPatchDivCountU\0"
    "setPatchDivCountV\0setPatchLineCountU\0"
    "setPatchLineCountV\0setPatchX\0setPatchY\0"
    "setPatchZ"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__SideWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x0a,    1 /* Public */,
       3,    1,  113,    2, 0x0a,    3 /* Public */,
       4,    1,  116,    2, 0x0a,    5 /* Public */,
       5,    1,  119,    2, 0x0a,    7 /* Public */,
       6,    1,  122,    2, 0x0a,    9 /* Public */,
       7,    1,  125,    2, 0x0a,   11 /* Public */,
       8,    1,  128,    2, 0x0a,   13 /* Public */,
       9,    1,  131,    2, 0x0a,   15 /* Public */,
      10,    1,  134,    2, 0x0a,   17 /* Public */,
      11,    1,  137,    2, 0x0a,   19 /* Public */,
      12,    1,  140,    2, 0x0a,   21 /* Public */,
      13,    1,  143,    2, 0x0a,   23 /* Public */,
      14,    1,  146,    2, 0x0a,   25 /* Public */,
      15,    1,  149,    2, 0x0a,   27 /* Public */,
      16,    1,  152,    2, 0x0a,   29 /* Public */,
      17,    1,  155,    2, 0x0a,   31 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void cagd::SideWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SideWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setArcAlpha((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setArcScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setArcDivCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setArcX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setArcY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setArcZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setPatchAlphaU((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setPatchAlphaV((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setPatchScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setPatchDivCountU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setPatchDivCountV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setPatchLineCountU((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setPatchLineCountV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setPatchX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setPatchY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->setPatchZ((*reinterpret_cast< double(*)>(_a[1]))); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
