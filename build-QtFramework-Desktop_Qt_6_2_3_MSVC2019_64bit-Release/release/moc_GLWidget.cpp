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
    const uint offsetsAndSize[144];
    char stringdata0[1198];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__GLWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__GLWidget_t qt_meta_stringdata_cagd__GLWidget = {
    {
QT_MOC_LITERAL(0, 14), // "cagd::GLWidget"
QT_MOC_LITERAL(15, 15), // "set_cc_maxLimit"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 18), // "set_cc_cp_maxLimit"
QT_MOC_LITERAL(51, 16), // "set_cc_cp_values"
QT_MOC_LITERAL(68, 5), // "set_e"
QT_MOC_LITERAL(74, 9), // "set_speed"
QT_MOC_LITERAL(84, 10), // "set_speed2"
QT_MOC_LITERAL(95, 10), // "set_points"
QT_MOC_LITERAL(106, 21), // "set_zeroth_derivative"
QT_MOC_LITERAL(128, 20), // "set_first_derivative"
QT_MOC_LITERAL(149, 21), // "set_second_derivative"
QT_MOC_LITERAL(171, 19), // "surface_set_texture"
QT_MOC_LITERAL(191, 20), // "surface_set_material"
QT_MOC_LITERAL(212, 9), // "_animate0"
QT_MOC_LITERAL(222, 9), // "_animate1"
QT_MOC_LITERAL(232, 9), // "_animate2"
QT_MOC_LITERAL(242, 9), // "_animate3"
QT_MOC_LITERAL(252, 18), // "_animatePassanger0"
QT_MOC_LITERAL(271, 18), // "_animatePassanger1"
QT_MOC_LITERAL(290, 18), // "_animatePassanger2"
QT_MOC_LITERAL(309, 18), // "_animatePassanger3"
QT_MOC_LITERAL(328, 15), // "_animateSurface"
QT_MOC_LITERAL(344, 11), // "set_angle_x"
QT_MOC_LITERAL(356, 5), // "value"
QT_MOC_LITERAL(362, 11), // "set_angle_y"
QT_MOC_LITERAL(374, 11), // "set_angle_z"
QT_MOC_LITERAL(386, 15), // "set_zoom_factor"
QT_MOC_LITERAL(402, 11), // "set_trans_x"
QT_MOC_LITERAL(414, 11), // "set_trans_y"
QT_MOC_LITERAL(426, 11), // "set_trans_z"
QT_MOC_LITERAL(438, 17), // "set_selected_page"
QT_MOC_LITERAL(456, 38), // "pc_set_selected_parametric_cu..."
QT_MOC_LITERAL(495, 22), // "pc_set_div_point_count"
QT_MOC_LITERAL(518, 23), // "pc_set_derivative_scale"
QT_MOC_LITERAL(542, 24), // "pc_set_zeroth_derivative"
QT_MOC_LITERAL(567, 23), // "pc_set_first_derivative"
QT_MOC_LITERAL(591, 24), // "pc_set_second_derivative"
QT_MOC_LITERAL(616, 36), // "race_set_selected_cyclic_curv..."
QT_MOC_LITERAL(653, 31), // "race_set_selected_control_point"
QT_MOC_LITERAL(685, 11), // "race_move_X"
QT_MOC_LITERAL(697, 11), // "race_move_Y"
QT_MOC_LITERAL(709, 11), // "race_move_Z"
QT_MOC_LITERAL(721, 6), // "edit_e"
QT_MOC_LITERAL(728, 10), // "edit_speed"
QT_MOC_LITERAL(739, 11), // "edit_speed2"
QT_MOC_LITERAL(751, 13), // "cc_set_points"
QT_MOC_LITERAL(765, 24), // "cc_set_zeroth_derivative"
QT_MOC_LITERAL(790, 23), // "cc_set_first_derivative"
QT_MOC_LITERAL(814, 24), // "cc_set_second_derivative"
QT_MOC_LITERAL(839, 40), // "ps_set_selected_parametric_su..."
QT_MOC_LITERAL(880, 20), // "ps_set_texture_state"
QT_MOC_LITERAL(901, 14), // "ps_set_texture"
QT_MOC_LITERAL(916, 15), // "ps_set_material"
QT_MOC_LITERAL(932, 16), // "patch_set_before"
QT_MOC_LITERAL(949, 15), // "patch_set_after"
QT_MOC_LITERAL(965, 15), // "patch_set_uip_0"
QT_MOC_LITERAL(981, 15), // "patch_set_uip_1"
QT_MOC_LITERAL(997, 15), // "patch_set_uip_2"
QT_MOC_LITERAL(1013, 15), // "patch_set_vip_0"
QT_MOC_LITERAL(1029, 15), // "patch_set_vip_1"
QT_MOC_LITERAL(1045, 15), // "patch_set_vip_2"
QT_MOC_LITERAL(1061, 11), // "arc_set_arc"
QT_MOC_LITERAL(1073, 13), // "arc_set_arc_0"
QT_MOC_LITERAL(1087, 13), // "arc_set_arc_1"
QT_MOC_LITERAL(1101, 13), // "arc_set_arc_2"
QT_MOC_LITERAL(1115, 10), // "shader_set"
QT_MOC_LITERAL(1126, 9), // "shader_do"
QT_MOC_LITERAL(1136, 16), // "shader_intensity"
QT_MOC_LITERAL(1153, 12), // "shader_scale"
QT_MOC_LITERAL(1166, 14), // "shader_shading"
QT_MOC_LITERAL(1181, 16) // "shader_smoothing"

    },
    "cagd::GLWidget\0set_cc_maxLimit\0\0"
    "set_cc_cp_maxLimit\0set_cc_cp_values\0"
    "set_e\0set_speed\0set_speed2\0set_points\0"
    "set_zeroth_derivative\0set_first_derivative\0"
    "set_second_derivative\0surface_set_texture\0"
    "surface_set_material\0_animate0\0_animate1\0"
    "_animate2\0_animate3\0_animatePassanger0\0"
    "_animatePassanger1\0_animatePassanger2\0"
    "_animatePassanger3\0_animateSurface\0"
    "set_angle_x\0value\0set_angle_y\0set_angle_z\0"
    "set_zoom_factor\0set_trans_x\0set_trans_y\0"
    "set_trans_z\0set_selected_page\0"
    "pc_set_selected_parametric_curve_index\0"
    "pc_set_div_point_count\0pc_set_derivative_scale\0"
    "pc_set_zeroth_derivative\0"
    "pc_set_first_derivative\0"
    "pc_set_second_derivative\0"
    "race_set_selected_cyclic_curve_index\0"
    "race_set_selected_control_point\0"
    "race_move_X\0race_move_Y\0race_move_Z\0"
    "edit_e\0edit_speed\0edit_speed2\0"
    "cc_set_points\0cc_set_zeroth_derivative\0"
    "cc_set_first_derivative\0"
    "cc_set_second_derivative\0"
    "ps_set_selected_parametric_surface_index\0"
    "ps_set_texture_state\0ps_set_texture\0"
    "ps_set_material\0patch_set_before\0"
    "patch_set_after\0patch_set_uip_0\0"
    "patch_set_uip_1\0patch_set_uip_2\0"
    "patch_set_vip_0\0patch_set_vip_1\0"
    "patch_set_vip_2\0arc_set_arc\0arc_set_arc_0\0"
    "arc_set_arc_1\0arc_set_arc_2\0shader_set\0"
    "shader_do\0shader_intensity\0shader_scale\0"
    "shader_shading\0shader_smoothing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__GLWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      69,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  428,    2, 0x06,    1 /* Public */,
       3,    1,  431,    2, 0x06,    3 /* Public */,
       4,    3,  434,    2, 0x06,    5 /* Public */,
       5,    1,  441,    2, 0x06,    9 /* Public */,
       6,    1,  444,    2, 0x06,   11 /* Public */,
       7,    1,  447,    2, 0x06,   13 /* Public */,
       8,    1,  450,    2, 0x06,   15 /* Public */,
       9,    1,  453,    2, 0x06,   17 /* Public */,
      10,    1,  456,    2, 0x06,   19 /* Public */,
      11,    1,  459,    2, 0x06,   21 /* Public */,
      12,    1,  462,    2, 0x06,   23 /* Public */,
      13,    1,  465,    2, 0x06,   25 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  468,    2, 0x08,   27 /* Private */,
      15,    0,  469,    2, 0x08,   28 /* Private */,
      16,    0,  470,    2, 0x08,   29 /* Private */,
      17,    0,  471,    2, 0x08,   30 /* Private */,
      18,    0,  472,    2, 0x08,   31 /* Private */,
      19,    0,  473,    2, 0x08,   32 /* Private */,
      20,    0,  474,    2, 0x08,   33 /* Private */,
      21,    0,  475,    2, 0x08,   34 /* Private */,
      22,    0,  476,    2, 0x08,   35 /* Private */,
      23,    1,  477,    2, 0x0a,   36 /* Public */,
      25,    1,  480,    2, 0x0a,   38 /* Public */,
      26,    1,  483,    2, 0x0a,   40 /* Public */,
      27,    1,  486,    2, 0x0a,   42 /* Public */,
      28,    1,  489,    2, 0x0a,   44 /* Public */,
      29,    1,  492,    2, 0x0a,   46 /* Public */,
      30,    1,  495,    2, 0x0a,   48 /* Public */,
      31,    1,  498,    2, 0x0a,   50 /* Public */,
      32,    1,  501,    2, 0x0a,   52 /* Public */,
      33,    1,  504,    2, 0x0a,   54 /* Public */,
      34,    1,  507,    2, 0x0a,   56 /* Public */,
      35,    1,  510,    2, 0x0a,   58 /* Public */,
      36,    1,  513,    2, 0x0a,   60 /* Public */,
      37,    1,  516,    2, 0x0a,   62 /* Public */,
      38,    1,  519,    2, 0x0a,   64 /* Public */,
      39,    1,  522,    2, 0x0a,   66 /* Public */,
      40,    1,  525,    2, 0x0a,   68 /* Public */,
      41,    1,  528,    2, 0x0a,   70 /* Public */,
      42,    1,  531,    2, 0x0a,   72 /* Public */,
      43,    1,  534,    2, 0x0a,   74 /* Public */,
      44,    1,  537,    2, 0x0a,   76 /* Public */,
      45,    1,  540,    2, 0x0a,   78 /* Public */,
      46,    1,  543,    2, 0x0a,   80 /* Public */,
      47,    1,  546,    2, 0x0a,   82 /* Public */,
      48,    1,  549,    2, 0x0a,   84 /* Public */,
      49,    1,  552,    2, 0x0a,   86 /* Public */,
      50,    1,  555,    2, 0x0a,   88 /* Public */,
      51,    1,  558,    2, 0x0a,   90 /* Public */,
      52,    1,  561,    2, 0x0a,   92 /* Public */,
      53,    1,  564,    2, 0x0a,   94 /* Public */,
      54,    1,  567,    2, 0x0a,   96 /* Public */,
      55,    1,  570,    2, 0x0a,   98 /* Public */,
      56,    1,  573,    2, 0x0a,  100 /* Public */,
      57,    1,  576,    2, 0x0a,  102 /* Public */,
      58,    1,  579,    2, 0x0a,  104 /* Public */,
      59,    1,  582,    2, 0x0a,  106 /* Public */,
      60,    1,  585,    2, 0x0a,  108 /* Public */,
      61,    1,  588,    2, 0x0a,  110 /* Public */,
      62,    1,  591,    2, 0x0a,  112 /* Public */,
      63,    1,  594,    2, 0x0a,  114 /* Public */,
      64,    1,  597,    2, 0x0a,  116 /* Public */,
      65,    1,  600,    2, 0x0a,  118 /* Public */,
      66,    1,  603,    2, 0x0a,  120 /* Public */,
      67,    1,  606,    2, 0x0a,  122 /* Public */,
      68,    1,  609,    2, 0x0a,  124 /* Public */,
      69,    1,  612,    2, 0x0a,  126 /* Public */,
      70,    1,  615,    2, 0x0a,  128 /* Public */,
      71,    1,  618,    2, 0x0a,  130 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

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
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   24,

       0        // eod
};

void cagd::GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->set_cc_maxLimit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_cc_cp_maxLimit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_cc_cp_values((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->set_e((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_speed2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->set_points((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->set_zeroth_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->set_first_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->set_second_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->surface_set_texture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->surface_set_material((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->_animate0(); break;
        case 13: _t->_animate1(); break;
        case 14: _t->_animate2(); break;
        case 15: _t->_animate3(); break;
        case 16: _t->_animatePassanger0(); break;
        case 17: _t->_animatePassanger1(); break;
        case 18: _t->_animatePassanger2(); break;
        case 19: _t->_animatePassanger3(); break;
        case 20: _t->_animateSurface(); break;
        case 21: _t->set_angle_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->set_angle_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->set_angle_z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->set_zoom_factor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->set_trans_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->set_trans_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->set_trans_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->set_selected_page((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->pc_set_selected_parametric_curve_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->pc_set_div_point_count((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->pc_set_derivative_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->pc_set_zeroth_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->pc_set_first_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->pc_set_second_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->race_set_selected_cyclic_curve_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->race_set_selected_control_point((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->race_move_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: _t->race_move_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: _t->race_move_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 40: _t->edit_e((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->edit_speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->edit_speed2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->cc_set_points((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->cc_set_zeroth_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->cc_set_first_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->cc_set_second_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->ps_set_selected_parametric_surface_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->ps_set_texture_state((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->ps_set_texture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->ps_set_material((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->patch_set_before((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: _t->patch_set_after((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->patch_set_uip_0((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->patch_set_uip_1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->patch_set_uip_2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->patch_set_vip_0((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->patch_set_vip_1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->patch_set_vip_2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->arc_set_arc((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 60: _t->arc_set_arc_0((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 61: _t->arc_set_arc_1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 62: _t->arc_set_arc_2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 63: _t->shader_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: _t->shader_do((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 65: _t->shader_intensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 66: _t->shader_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 67: _t->shader_shading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 68: _t->shader_smoothing((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_cc_maxLimit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_cc_cp_maxLimit)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_cc_cp_values)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_e)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_speed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_speed2)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_points)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_zeroth_derivative)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_first_derivative)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::set_second_derivative)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::surface_set_texture)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::surface_set_material)) {
                *result = 11;
                return;
            }
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
, QtPrivate::TypeAndForceComplete<GLWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


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
        if (_id < 69)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 69;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 69)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 69;
    }
    return _id;
}

// SIGNAL 0
void cagd::GLWidget::set_cc_maxLimit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cagd::GLWidget::set_cc_cp_maxLimit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cagd::GLWidget::set_cc_cp_values(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cagd::GLWidget::set_e(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void cagd::GLWidget::set_speed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void cagd::GLWidget::set_speed2(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void cagd::GLWidget::set_points(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void cagd::GLWidget::set_zeroth_derivative(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void cagd::GLWidget::set_first_derivative(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void cagd::GLWidget::set_second_derivative(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void cagd::GLWidget::surface_set_texture(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void cagd::GLWidget::surface_set_material(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
