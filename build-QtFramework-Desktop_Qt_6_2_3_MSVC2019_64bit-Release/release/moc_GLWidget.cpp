/****************************************************************************
** Meta object code from reading C++ file 'GLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Labor/GUI/GLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cagd__GLWidget_t {
    const uint offsetsAndSize[34];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__GLWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__GLWidget_t qt_meta_stringdata_cagd__GLWidget = {
    {
QT_MOC_LITERAL(0, 14), // "cagd::GLWidget"
QT_MOC_LITERAL(15, 11), // "set_angle_x"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 5), // "value"
QT_MOC_LITERAL(34, 11), // "set_angle_y"
QT_MOC_LITERAL(46, 11), // "set_angle_z"
QT_MOC_LITERAL(58, 15), // "set_zoom_factor"
QT_MOC_LITERAL(74, 11), // "set_trans_x"
QT_MOC_LITERAL(86, 11), // "set_trans_y"
QT_MOC_LITERAL(98, 11), // "set_trans_z"
QT_MOC_LITERAL(110, 17), // "set_selected_page"
QT_MOC_LITERAL(128, 10), // "shader_set"
QT_MOC_LITERAL(139, 9), // "shader_do"
QT_MOC_LITERAL(149, 16), // "shader_intensity"
QT_MOC_LITERAL(166, 12), // "shader_scale"
QT_MOC_LITERAL(179, 14), // "shader_shading"
QT_MOC_LITERAL(194, 16) // "shader_smoothing"

    },
    "cagd::GLWidget\0set_angle_x\0\0value\0"
    "set_angle_y\0set_angle_z\0set_zoom_factor\0"
    "set_trans_x\0set_trans_y\0set_trans_z\0"
    "set_selected_page\0shader_set\0shader_do\0"
    "shader_intensity\0shader_scale\0"
    "shader_shading\0shader_smoothing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__GLWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x0a,    1 /* Public */,
       4,    1,  101,    2, 0x0a,    3 /* Public */,
       5,    1,  104,    2, 0x0a,    5 /* Public */,
       6,    1,  107,    2, 0x0a,    7 /* Public */,
       7,    1,  110,    2, 0x0a,    9 /* Public */,
       8,    1,  113,    2, 0x0a,   11 /* Public */,
       9,    1,  116,    2, 0x0a,   13 /* Public */,
      10,    1,  119,    2, 0x0a,   15 /* Public */,
      11,    1,  122,    2, 0x0a,   17 /* Public */,
      12,    1,  125,    2, 0x0a,   19 /* Public */,
      13,    1,  128,    2, 0x0a,   21 /* Public */,
      14,    1,  131,    2, 0x0a,   23 /* Public */,
      15,    1,  134,    2, 0x0a,   25 /* Public */,
      16,    1,  137,    2, 0x0a,   27 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,

       0        // eod
};

void cagd::GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->set_angle_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_angle_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_angle_z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->set_zoom_factor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_trans_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->set_trans_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->set_trans_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->set_selected_page((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->shader_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->shader_do((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->shader_intensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->shader_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->shader_shading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->shader_smoothing((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cagd::GLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_cagd__GLWidget.offsetsAndSize,
    qt_meta_data_cagd__GLWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cagd__GLWidget_t
, QtPrivate::TypeAndForceComplete<GLWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


>,
    nullptr
} };


const QMetaObject *cagd::GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cagd::GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cagd__GLWidget.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int cagd::GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
