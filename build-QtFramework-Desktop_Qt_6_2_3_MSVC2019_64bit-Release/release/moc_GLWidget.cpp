/****************************************************************************
** Meta object code from reading C++ file 'GLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Labor/GUI/GLWidget.h"
#include <QtGui/qtextcursor.h>
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
    const uint offsetsAndSize[180];
    char stringdata0[2219];
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
QT_MOC_LITERAL(128, 21), // "showArcContinueWindow"
QT_MOC_LITERAL(150, 17), // "showArcJoinWindow"
QT_MOC_LITERAL(168, 18), // "showArcMergeWindow"
QT_MOC_LITERAL(187, 23), // "showPatchContinueWindow"
QT_MOC_LITERAL(211, 19), // "showPatchJoinWindow"
QT_MOC_LITERAL(231, 20), // "showPatchMergeWindow"
QT_MOC_LITERAL(252, 17), // "arcInsertSetAlpha"
QT_MOC_LITERAL(270, 17), // "arcInsertSetScale"
QT_MOC_LITERAL(288, 20), // "arcInsertSetDivCount"
QT_MOC_LITERAL(309, 21), // "arcInsertButtonCreate"
QT_MOC_LITERAL(331, 31), // "arcManipulateDoFirstDerivatives"
QT_MOC_LITERAL(363, 32), // "arcManipulateDoSecondDerivatives"
QT_MOC_LITERAL(396, 27), // "arcManipulateSetSelectedArc"
QT_MOC_LITERAL(424, 26), // "arcManipulateSetSelectedCP"
QT_MOC_LITERAL(451, 18), // "arcManipulateSet_X"
QT_MOC_LITERAL(470, 18), // "arcManipulateSet_Y"
QT_MOC_LITERAL(489, 18), // "arcManipulateSet_Z"
QT_MOC_LITERAL(508, 27), // "arcManipulateSetTranslate_X"
QT_MOC_LITERAL(536, 27), // "arcManipulateSetTranslate_Y"
QT_MOC_LITERAL(564, 27), // "arcManipulateSetTranslate_Z"
QT_MOC_LITERAL(592, 25), // "arcManipulateButtonDelete"
QT_MOC_LITERAL(618, 28), // "arcInteractionButtonContinue"
QT_MOC_LITERAL(647, 24), // "arcInteractionButtonJoin"
QT_MOC_LITERAL(672, 25), // "arcInteractionButtonMerge"
QT_MOC_LITERAL(698, 28), // "arcInteractionContinueSetArc"
QT_MOC_LITERAL(727, 34), // "arcInteractionContinueSetDire..."
QT_MOC_LITERAL(762, 25), // "arcInteractionJoinSetArc1"
QT_MOC_LITERAL(788, 25), // "arcInteractionJoinSetArc2"
QT_MOC_LITERAL(814, 31), // "arcInteractionJoinSetDirection1"
QT_MOC_LITERAL(846, 31), // "arcInteractionJoinSetDirection2"
QT_MOC_LITERAL(878, 26), // "arcInteractionMergeSetArc1"
QT_MOC_LITERAL(905, 26), // "arcInteractionMergeSetArc2"
QT_MOC_LITERAL(932, 32), // "arcInteractionMergeSetDirection1"
QT_MOC_LITERAL(965, 32), // "arcInteractionMergeSetDirection2"
QT_MOC_LITERAL(998, 21), // "patchInsertSetAlpha_U"
QT_MOC_LITERAL(1020, 21), // "patchInsertSetAlpha_V"
QT_MOC_LITERAL(1042, 19), // "patchInsertSetScale"
QT_MOC_LITERAL(1062, 23), // "patchInsertButtonCreate"
QT_MOC_LITERAL(1086, 21), // "patchInsertButtonSave"
QT_MOC_LITERAL(1108, 21), // "patchInsertButtonLoad"
QT_MOC_LITERAL(1130, 31), // "patchIsoparametricSetDivCount_U"
QT_MOC_LITERAL(1162, 31), // "patchIsoparametricSetDivCount_V"
QT_MOC_LITERAL(1194, 32), // "patchIsoparametricSetLineCount_U"
QT_MOC_LITERAL(1227, 32), // "patchIsoparametricSetLineCount_V"
QT_MOC_LITERAL(1260, 23), // "patchManipulateDoNormal"
QT_MOC_LITERAL(1284, 33), // "patchManipulateDoFirstDerivat..."
QT_MOC_LITERAL(1318, 34), // "patchManipulateDoSecondDeriva..."
QT_MOC_LITERAL(1353, 31), // "patchManipulateSetSelectedPatch"
QT_MOC_LITERAL(1385, 29), // "patchManipulateSetSelectedRow"
QT_MOC_LITERAL(1415, 29), // "patchManipulateSetSelectedCol"
QT_MOC_LITERAL(1445, 20), // "patchManipulateSet_X"
QT_MOC_LITERAL(1466, 20), // "patchManipulateSet_Y"
QT_MOC_LITERAL(1487, 20), // "patchManipulateSet_Z"
QT_MOC_LITERAL(1508, 29), // "patchManipulateSetTranslate_X"
QT_MOC_LITERAL(1538, 29), // "patchManipulateSetTranslate_Y"
QT_MOC_LITERAL(1568, 29), // "patchManipulateSetTranslate_Z"
QT_MOC_LITERAL(1598, 34), // "patchManipulateSetSelectedMat..."
QT_MOC_LITERAL(1633, 33), // "patchManipulateSetSelectedTex..."
QT_MOC_LITERAL(1667, 24), // "patchManipulateDoTexture"
QT_MOC_LITERAL(1692, 27), // "patchManipulateButtonDelete"
QT_MOC_LITERAL(1720, 30), // "patchInteractionButtonContinue"
QT_MOC_LITERAL(1751, 26), // "patchInteractionButtonJoin"
QT_MOC_LITERAL(1778, 27), // "patchInteractionButtonMerge"
QT_MOC_LITERAL(1806, 32), // "patchInteractionContinueSetPatch"
QT_MOC_LITERAL(1839, 36), // "patchInteractionContinueSetDi..."
QT_MOC_LITERAL(1876, 29), // "patchInteractionJoinSetPatch1"
QT_MOC_LITERAL(1906, 29), // "patchInteractionJoinSetPatch2"
QT_MOC_LITERAL(1936, 33), // "patchInteractionJoinSetDirect..."
QT_MOC_LITERAL(1970, 33), // "patchInteractionJoinSetDirect..."
QT_MOC_LITERAL(2004, 30), // "patchInteractionMergeSetPatch1"
QT_MOC_LITERAL(2035, 30), // "patchInteractionMergeSetPatch2"
QT_MOC_LITERAL(2066, 34), // "patchInteractionMergeSetDirec..."
QT_MOC_LITERAL(2101, 34), // "patchInteractionMergeSetDirec..."
QT_MOC_LITERAL(2136, 10), // "shader_set"
QT_MOC_LITERAL(2147, 9), // "shader_do"
QT_MOC_LITERAL(2157, 16), // "shader_intensity"
QT_MOC_LITERAL(2174, 12), // "shader_scale"
QT_MOC_LITERAL(2187, 14), // "shader_shading"
QT_MOC_LITERAL(2202, 16) // "shader_smoothing"

    },
    "cagd::GLWidget\0set_angle_x\0\0value\0"
    "set_angle_y\0set_angle_z\0set_zoom_factor\0"
    "set_trans_x\0set_trans_y\0set_trans_z\0"
    "set_selected_page\0showArcContinueWindow\0"
    "showArcJoinWindow\0showArcMergeWindow\0"
    "showPatchContinueWindow\0showPatchJoinWindow\0"
    "showPatchMergeWindow\0arcInsertSetAlpha\0"
    "arcInsertSetScale\0arcInsertSetDivCount\0"
    "arcInsertButtonCreate\0"
    "arcManipulateDoFirstDerivatives\0"
    "arcManipulateDoSecondDerivatives\0"
    "arcManipulateSetSelectedArc\0"
    "arcManipulateSetSelectedCP\0"
    "arcManipulateSet_X\0arcManipulateSet_Y\0"
    "arcManipulateSet_Z\0arcManipulateSetTranslate_X\0"
    "arcManipulateSetTranslate_Y\0"
    "arcManipulateSetTranslate_Z\0"
    "arcManipulateButtonDelete\0"
    "arcInteractionButtonContinue\0"
    "arcInteractionButtonJoin\0"
    "arcInteractionButtonMerge\0"
    "arcInteractionContinueSetArc\0"
    "arcInteractionContinueSetDirection\0"
    "arcInteractionJoinSetArc1\0"
    "arcInteractionJoinSetArc2\0"
    "arcInteractionJoinSetDirection1\0"
    "arcInteractionJoinSetDirection2\0"
    "arcInteractionMergeSetArc1\0"
    "arcInteractionMergeSetArc2\0"
    "arcInteractionMergeSetDirection1\0"
    "arcInteractionMergeSetDirection2\0"
    "patchInsertSetAlpha_U\0patchInsertSetAlpha_V\0"
    "patchInsertSetScale\0patchInsertButtonCreate\0"
    "patchInsertButtonSave\0patchInsertButtonLoad\0"
    "patchIsoparametricSetDivCount_U\0"
    "patchIsoparametricSetDivCount_V\0"
    "patchIsoparametricSetLineCount_U\0"
    "patchIsoparametricSetLineCount_V\0"
    "patchManipulateDoNormal\0"
    "patchManipulateDoFirstDerivatives\0"
    "patchManipulateDoSecondDerivatives\0"
    "patchManipulateSetSelectedPatch\0"
    "patchManipulateSetSelectedRow\0"
    "patchManipulateSetSelectedCol\0"
    "patchManipulateSet_X\0patchManipulateSet_Y\0"
    "patchManipulateSet_Z\0patchManipulateSetTranslate_X\0"
    "patchManipulateSetTranslate_Y\0"
    "patchManipulateSetTranslate_Z\0"
    "patchManipulateSetSelectedMaterial\0"
    "patchManipulateSetSelectedTexture\0"
    "patchManipulateDoTexture\0"
    "patchManipulateButtonDelete\0"
    "patchInteractionButtonContinue\0"
    "patchInteractionButtonJoin\0"
    "patchInteractionButtonMerge\0"
    "patchInteractionContinueSetPatch\0"
    "patchInteractionContinueSetDirection\0"
    "patchInteractionJoinSetPatch1\0"
    "patchInteractionJoinSetPatch2\0"
    "patchInteractionJoinSetDirection1\0"
    "patchInteractionJoinSetDirection2\0"
    "patchInteractionMergeSetPatch1\0"
    "patchInteractionMergeSetPatch2\0"
    "patchInteractionMergeSetDirection1\0"
    "patchInteractionMergeSetDirection2\0"
    "shader_set\0shader_do\0shader_intensity\0"
    "shader_scale\0shader_shading\0"
    "shader_smoothing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__GLWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      87,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  536,    2, 0x0a,    1 /* Public */,
       4,    1,  539,    2, 0x0a,    3 /* Public */,
       5,    1,  542,    2, 0x0a,    5 /* Public */,
       6,    1,  545,    2, 0x0a,    7 /* Public */,
       7,    1,  548,    2, 0x0a,    9 /* Public */,
       8,    1,  551,    2, 0x0a,   11 /* Public */,
       9,    1,  554,    2, 0x0a,   13 /* Public */,
      10,    1,  557,    2, 0x0a,   15 /* Public */,
      11,    0,  560,    2, 0x0a,   17 /* Public */,
      12,    0,  561,    2, 0x0a,   18 /* Public */,
      13,    0,  562,    2, 0x0a,   19 /* Public */,
      14,    0,  563,    2, 0x0a,   20 /* Public */,
      15,    0,  564,    2, 0x0a,   21 /* Public */,
      16,    0,  565,    2, 0x0a,   22 /* Public */,
      17,    1,  566,    2, 0x0a,   23 /* Public */,
      18,    1,  569,    2, 0x0a,   25 /* Public */,
      19,    1,  572,    2, 0x0a,   27 /* Public */,
      20,    0,  575,    2, 0x0a,   29 /* Public */,
      21,    1,  576,    2, 0x0a,   30 /* Public */,
      22,    1,  579,    2, 0x0a,   32 /* Public */,
      23,    1,  582,    2, 0x0a,   34 /* Public */,
      24,    1,  585,    2, 0x0a,   36 /* Public */,
      25,    1,  588,    2, 0x0a,   38 /* Public */,
      26,    1,  591,    2, 0x0a,   40 /* Public */,
      27,    1,  594,    2, 0x0a,   42 /* Public */,
      28,    1,  597,    2, 0x0a,   44 /* Public */,
      29,    1,  600,    2, 0x0a,   46 /* Public */,
      30,    1,  603,    2, 0x0a,   48 /* Public */,
      31,    0,  606,    2, 0x0a,   50 /* Public */,
      32,    0,  607,    2, 0x0a,   51 /* Public */,
      33,    0,  608,    2, 0x0a,   52 /* Public */,
      34,    0,  609,    2, 0x0a,   53 /* Public */,
      35,    1,  610,    2, 0x0a,   54 /* Public */,
      36,    1,  613,    2, 0x0a,   56 /* Public */,
      37,    1,  616,    2, 0x0a,   58 /* Public */,
      38,    1,  619,    2, 0x0a,   60 /* Public */,
      39,    1,  622,    2, 0x0a,   62 /* Public */,
      40,    1,  625,    2, 0x0a,   64 /* Public */,
      41,    1,  628,    2, 0x0a,   66 /* Public */,
      42,    1,  631,    2, 0x0a,   68 /* Public */,
      43,    1,  634,    2, 0x0a,   70 /* Public */,
      44,    1,  637,    2, 0x0a,   72 /* Public */,
      45,    1,  640,    2, 0x0a,   74 /* Public */,
      46,    1,  643,    2, 0x0a,   76 /* Public */,
      47,    1,  646,    2, 0x0a,   78 /* Public */,
      48,    0,  649,    2, 0x0a,   80 /* Public */,
      49,    0,  650,    2, 0x0a,   81 /* Public */,
      50,    0,  651,    2, 0x0a,   82 /* Public */,
      51,    1,  652,    2, 0x0a,   83 /* Public */,
      52,    1,  655,    2, 0x0a,   85 /* Public */,
      53,    1,  658,    2, 0x0a,   87 /* Public */,
      54,    1,  661,    2, 0x0a,   89 /* Public */,
      55,    1,  664,    2, 0x0a,   91 /* Public */,
      56,    1,  667,    2, 0x0a,   93 /* Public */,
      57,    1,  670,    2, 0x0a,   95 /* Public */,
      58,    1,  673,    2, 0x0a,   97 /* Public */,
      59,    1,  676,    2, 0x0a,   99 /* Public */,
      60,    1,  679,    2, 0x0a,  101 /* Public */,
      61,    1,  682,    2, 0x0a,  103 /* Public */,
      62,    1,  685,    2, 0x0a,  105 /* Public */,
      63,    1,  688,    2, 0x0a,  107 /* Public */,
      64,    1,  691,    2, 0x0a,  109 /* Public */,
      65,    1,  694,    2, 0x0a,  111 /* Public */,
      66,    1,  697,    2, 0x0a,  113 /* Public */,
      67,    1,  700,    2, 0x0a,  115 /* Public */,
      68,    1,  703,    2, 0x0a,  117 /* Public */,
      69,    1,  706,    2, 0x0a,  119 /* Public */,
      70,    0,  709,    2, 0x0a,  121 /* Public */,
      71,    0,  710,    2, 0x0a,  122 /* Public */,
      72,    0,  711,    2, 0x0a,  123 /* Public */,
      73,    0,  712,    2, 0x0a,  124 /* Public */,
      74,    1,  713,    2, 0x0a,  125 /* Public */,
      75,    1,  716,    2, 0x0a,  127 /* Public */,
      76,    1,  719,    2, 0x0a,  129 /* Public */,
      77,    1,  722,    2, 0x0a,  131 /* Public */,
      78,    1,  725,    2, 0x0a,  133 /* Public */,
      79,    1,  728,    2, 0x0a,  135 /* Public */,
      80,    1,  731,    2, 0x0a,  137 /* Public */,
      81,    1,  734,    2, 0x0a,  139 /* Public */,
      82,    1,  737,    2, 0x0a,  141 /* Public */,
      83,    1,  740,    2, 0x0a,  143 /* Public */,
      84,    1,  743,    2, 0x0a,  145 /* Public */,
      85,    1,  746,    2, 0x0a,  147 /* Public */,
      86,    1,  749,    2, 0x0a,  149 /* Public */,
      87,    1,  752,    2, 0x0a,  151 /* Public */,
      88,    1,  755,    2, 0x0a,  153 /* Public */,
      89,    1,  758,    2, 0x0a,  155 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
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
        case 8: _t->showArcContinueWindow(); break;
        case 9: _t->showArcJoinWindow(); break;
        case 10: _t->showArcMergeWindow(); break;
        case 11: _t->showPatchContinueWindow(); break;
        case 12: _t->showPatchJoinWindow(); break;
        case 13: _t->showPatchMergeWindow(); break;
        case 14: _t->arcInsertSetAlpha((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->arcInsertSetScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->arcInsertSetDivCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->arcInsertButtonCreate(); break;
        case 18: _t->arcManipulateDoFirstDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->arcManipulateDoSecondDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->arcManipulateSetSelectedArc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->arcManipulateSetSelectedCP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->arcManipulateSet_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->arcManipulateSet_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->arcManipulateSet_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->arcManipulateSetTranslate_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->arcManipulateSetTranslate_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->arcManipulateSetTranslate_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->arcManipulateButtonDelete(); break;
        case 29: _t->arcInteractionButtonContinue(); break;
        case 30: _t->arcInteractionButtonJoin(); break;
        case 31: _t->arcInteractionButtonMerge(); break;
        case 32: _t->arcInteractionContinueSetArc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->arcInteractionContinueSetDirection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->arcInteractionJoinSetArc1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->arcInteractionJoinSetArc2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->arcInteractionJoinSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->arcInteractionJoinSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->arcInteractionMergeSetArc1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->arcInteractionMergeSetArc2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->arcInteractionMergeSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->arcInteractionMergeSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->patchInsertSetAlpha_U((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->patchInsertSetAlpha_V((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 44: _t->patchInsertSetScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 45: _t->patchInsertButtonCreate(); break;
        case 46: _t->patchInsertButtonSave(); break;
        case 47: _t->patchInsertButtonLoad(); break;
        case 48: _t->patchIsoparametricSetDivCount_U((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->patchIsoparametricSetDivCount_V((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->patchIsoparametricSetLineCount_U((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->patchIsoparametricSetLineCount_V((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->patchManipulateDoNormal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->patchManipulateDoFirstDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->patchManipulateDoSecondDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->patchManipulateSetSelectedPatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->patchManipulateSetSelectedRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->patchManipulateSetSelectedCol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->patchManipulateSet_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 59: _t->patchManipulateSet_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 60: _t->patchManipulateSet_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 61: _t->patchManipulateSetTranslate_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 62: _t->patchManipulateSetTranslate_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 63: _t->patchManipulateSetTranslate_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 64: _t->patchManipulateSetSelectedMaterial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->patchManipulateSetSelectedTexture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->patchManipulateDoTexture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->patchManipulateButtonDelete(); break;
        case 68: _t->patchInteractionButtonContinue(); break;
        case 69: _t->patchInteractionButtonJoin(); break;
        case 70: _t->patchInteractionButtonMerge(); break;
        case 71: _t->patchInteractionContinueSetPatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->patchInteractionContinueSetDirection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: _t->patchInteractionJoinSetPatch1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 74: _t->patchInteractionJoinSetPatch2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 75: _t->patchInteractionJoinSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 76: _t->patchInteractionJoinSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->patchInteractionMergeSetPatch1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 78: _t->patchInteractionMergeSetPatch2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 79: _t->patchInteractionMergeSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: _t->patchInteractionMergeSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->shader_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: _t->shader_do((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 83: _t->shader_intensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 84: _t->shader_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 85: _t->shader_shading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 86: _t->shader_smoothing((*reinterpret_cast< double(*)>(_a[1]))); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


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
        if (_id < 87)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 87;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 87)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 87;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
