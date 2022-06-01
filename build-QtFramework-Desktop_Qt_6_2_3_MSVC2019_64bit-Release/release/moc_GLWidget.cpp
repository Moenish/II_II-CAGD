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
    const uint offsetsAndSize[226];
    char stringdata0[2609];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__GLWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__GLWidget_t qt_meta_stringdata_cagd__GLWidget = {
    {
QT_MOC_LITERAL(0, 14), // "cagd::GLWidget"
QT_MOC_LITERAL(15, 11), // "setArcAlpha"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 11), // "setArcScale"
QT_MOC_LITERAL(40, 14), // "setArcDivCount"
QT_MOC_LITERAL(55, 7), // "setArcX"
QT_MOC_LITERAL(63, 7), // "setArcY"
QT_MOC_LITERAL(71, 7), // "setArcZ"
QT_MOC_LITERAL(79, 15), // "setPatchAlpha_U"
QT_MOC_LITERAL(95, 15), // "setPatchAlpha_V"
QT_MOC_LITERAL(111, 13), // "setPatchScale"
QT_MOC_LITERAL(125, 18), // "setPatchDivCount_U"
QT_MOC_LITERAL(144, 18), // "setPatchDivCount_V"
QT_MOC_LITERAL(163, 19), // "setPatchLineCount_U"
QT_MOC_LITERAL(183, 19), // "setPatchLineCount_V"
QT_MOC_LITERAL(203, 9), // "setPatchX"
QT_MOC_LITERAL(213, 9), // "setPatchY"
QT_MOC_LITERAL(223, 9), // "setPatchZ"
QT_MOC_LITERAL(233, 11), // "set_angle_x"
QT_MOC_LITERAL(245, 5), // "value"
QT_MOC_LITERAL(251, 11), // "set_angle_y"
QT_MOC_LITERAL(263, 11), // "set_angle_z"
QT_MOC_LITERAL(275, 15), // "set_zoom_factor"
QT_MOC_LITERAL(291, 11), // "set_trans_x"
QT_MOC_LITERAL(303, 11), // "set_trans_y"
QT_MOC_LITERAL(315, 11), // "set_trans_z"
QT_MOC_LITERAL(327, 17), // "set_selected_page"
QT_MOC_LITERAL(345, 21), // "showArcContinueWindow"
QT_MOC_LITERAL(367, 17), // "showArcJoinWindow"
QT_MOC_LITERAL(385, 18), // "showArcMergeWindow"
QT_MOC_LITERAL(404, 23), // "showPatchContinueWindow"
QT_MOC_LITERAL(428, 19), // "showPatchJoinWindow"
QT_MOC_LITERAL(448, 20), // "showPatchMergeWindow"
QT_MOC_LITERAL(469, 14), // "emitArcSignals"
QT_MOC_LITERAL(484, 16), // "emitPatchSignals"
QT_MOC_LITERAL(501, 17), // "arcInsertSetAlpha"
QT_MOC_LITERAL(519, 17), // "arcInsertSetScale"
QT_MOC_LITERAL(537, 20), // "arcInsertSetDivCount"
QT_MOC_LITERAL(558, 21), // "arcInsertButtonCreate"
QT_MOC_LITERAL(580, 29), // "arcManipulateDoNegDerivatives"
QT_MOC_LITERAL(610, 32), // "arcManipulateDoZerothDerivatives"
QT_MOC_LITERAL(643, 31), // "arcManipulateDoFirstDerivatives"
QT_MOC_LITERAL(675, 32), // "arcManipulateDoSecondDerivatives"
QT_MOC_LITERAL(708, 27), // "arcManipulateSetSelectedArc"
QT_MOC_LITERAL(736, 26), // "arcManipulateSetSelectedCP"
QT_MOC_LITERAL(763, 18), // "arcManipulateSet_X"
QT_MOC_LITERAL(782, 18), // "arcManipulateSet_Y"
QT_MOC_LITERAL(801, 18), // "arcManipulateSet_Z"
QT_MOC_LITERAL(820, 27), // "arcManipulateSetTranslate_X"
QT_MOC_LITERAL(848, 27), // "arcManipulateSetTranslate_Y"
QT_MOC_LITERAL(876, 27), // "arcManipulateSetTranslate_Z"
QT_MOC_LITERAL(904, 25), // "arcManipulateButtonDelete"
QT_MOC_LITERAL(930, 28), // "arcInteractionButtonContinue"
QT_MOC_LITERAL(959, 24), // "arcInteractionButtonJoin"
QT_MOC_LITERAL(984, 25), // "arcInteractionButtonMerge"
QT_MOC_LITERAL(1010, 28), // "arcInteractionContinueSetArc"
QT_MOC_LITERAL(1039, 34), // "arcInteractionContinueSetDire..."
QT_MOC_LITERAL(1074, 25), // "arcInteractionJoinSetArc1"
QT_MOC_LITERAL(1100, 25), // "arcInteractionJoinSetArc2"
QT_MOC_LITERAL(1126, 31), // "arcInteractionJoinSetDirection1"
QT_MOC_LITERAL(1158, 31), // "arcInteractionJoinSetDirection2"
QT_MOC_LITERAL(1190, 26), // "arcInteractionMergeSetArc1"
QT_MOC_LITERAL(1217, 26), // "arcInteractionMergeSetArc2"
QT_MOC_LITERAL(1244, 32), // "arcInteractionMergeSetDirection1"
QT_MOC_LITERAL(1277, 32), // "arcInteractionMergeSetDirection2"
QT_MOC_LITERAL(1310, 21), // "patchInsertSetAlpha_U"
QT_MOC_LITERAL(1332, 21), // "patchInsertSetAlpha_V"
QT_MOC_LITERAL(1354, 19), // "patchInsertSetScale"
QT_MOC_LITERAL(1374, 23), // "patchInsertButtonCreate"
QT_MOC_LITERAL(1398, 21), // "patchInsertButtonSave"
QT_MOC_LITERAL(1420, 21), // "patchInsertButtonLoad"
QT_MOC_LITERAL(1442, 31), // "patchIsoparametricSetDivCount_U"
QT_MOC_LITERAL(1474, 31), // "patchIsoparametricSetDivCount_V"
QT_MOC_LITERAL(1506, 32), // "patchIsoparametricSetLineCount_U"
QT_MOC_LITERAL(1539, 32), // "patchIsoparametricSetLineCount_V"
QT_MOC_LITERAL(1572, 22), // "patchIsoparametricDo_U"
QT_MOC_LITERAL(1595, 22), // "patchIsoparametricDo_V"
QT_MOC_LITERAL(1618, 26), // "patchIsoparametricDoNormal"
QT_MOC_LITERAL(1645, 36), // "patchIsoparametricDoFirstDeri..."
QT_MOC_LITERAL(1682, 37), // "patchIsoparametricDoSecondDer..."
QT_MOC_LITERAL(1720, 22), // "patchManipulateDoPatch"
QT_MOC_LITERAL(1743, 31), // "patchManipulateSetSelectedPatch"
QT_MOC_LITERAL(1775, 29), // "patchManipulateSetSelectedRow"
QT_MOC_LITERAL(1805, 29), // "patchManipulateSetSelectedCol"
QT_MOC_LITERAL(1835, 20), // "patchManipulateSet_X"
QT_MOC_LITERAL(1856, 20), // "patchManipulateSet_Y"
QT_MOC_LITERAL(1877, 20), // "patchManipulateSet_Z"
QT_MOC_LITERAL(1898, 29), // "patchManipulateSetTranslate_X"
QT_MOC_LITERAL(1928, 29), // "patchManipulateSetTranslate_Y"
QT_MOC_LITERAL(1958, 29), // "patchManipulateSetTranslate_Z"
QT_MOC_LITERAL(1988, 34), // "patchManipulateSetSelectedMat..."
QT_MOC_LITERAL(2023, 33), // "patchManipulateSetSelectedTex..."
QT_MOC_LITERAL(2057, 24), // "patchManipulateDoTexture"
QT_MOC_LITERAL(2082, 27), // "patchManipulateButtonDelete"
QT_MOC_LITERAL(2110, 30), // "patchInteractionButtonContinue"
QT_MOC_LITERAL(2141, 26), // "patchInteractionButtonJoin"
QT_MOC_LITERAL(2168, 27), // "patchInteractionButtonMerge"
QT_MOC_LITERAL(2196, 32), // "patchInteractionContinueSetPatch"
QT_MOC_LITERAL(2229, 36), // "patchInteractionContinueSetDi..."
QT_MOC_LITERAL(2266, 29), // "patchInteractionJoinSetPatch1"
QT_MOC_LITERAL(2296, 29), // "patchInteractionJoinSetPatch2"
QT_MOC_LITERAL(2326, 33), // "patchInteractionJoinSetDirect..."
QT_MOC_LITERAL(2360, 33), // "patchInteractionJoinSetDirect..."
QT_MOC_LITERAL(2394, 30), // "patchInteractionMergeSetPatch1"
QT_MOC_LITERAL(2425, 30), // "patchInteractionMergeSetPatch2"
QT_MOC_LITERAL(2456, 34), // "patchInteractionMergeSetDirec..."
QT_MOC_LITERAL(2491, 34), // "patchInteractionMergeSetDirec..."
QT_MOC_LITERAL(2526, 10), // "shader_set"
QT_MOC_LITERAL(2537, 9), // "shader_do"
QT_MOC_LITERAL(2547, 16), // "shader_intensity"
QT_MOC_LITERAL(2564, 12), // "shader_scale"
QT_MOC_LITERAL(2577, 14), // "shader_shading"
QT_MOC_LITERAL(2592, 16) // "shader_smoothing"

    },
    "cagd::GLWidget\0setArcAlpha\0\0setArcScale\0"
    "setArcDivCount\0setArcX\0setArcY\0setArcZ\0"
    "setPatchAlpha_U\0setPatchAlpha_V\0"
    "setPatchScale\0setPatchDivCount_U\0"
    "setPatchDivCount_V\0setPatchLineCount_U\0"
    "setPatchLineCount_V\0setPatchX\0setPatchY\0"
    "setPatchZ\0set_angle_x\0value\0set_angle_y\0"
    "set_angle_z\0set_zoom_factor\0set_trans_x\0"
    "set_trans_y\0set_trans_z\0set_selected_page\0"
    "showArcContinueWindow\0showArcJoinWindow\0"
    "showArcMergeWindow\0showPatchContinueWindow\0"
    "showPatchJoinWindow\0showPatchMergeWindow\0"
    "emitArcSignals\0emitPatchSignals\0"
    "arcInsertSetAlpha\0arcInsertSetScale\0"
    "arcInsertSetDivCount\0arcInsertButtonCreate\0"
    "arcManipulateDoNegDerivatives\0"
    "arcManipulateDoZerothDerivatives\0"
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
    "patchIsoparametricDo_U\0patchIsoparametricDo_V\0"
    "patchIsoparametricDoNormal\0"
    "patchIsoparametricDoFirstDerivatives\0"
    "patchIsoparametricDoSecondDerivatives\0"
    "patchManipulateDoPatch\0"
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
     110,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  674,    2, 0x06,    1 /* Public */,
       3,    1,  677,    2, 0x06,    3 /* Public */,
       4,    1,  680,    2, 0x06,    5 /* Public */,
       5,    1,  683,    2, 0x06,    7 /* Public */,
       6,    1,  686,    2, 0x06,    9 /* Public */,
       7,    1,  689,    2, 0x06,   11 /* Public */,
       8,    1,  692,    2, 0x06,   13 /* Public */,
       9,    1,  695,    2, 0x06,   15 /* Public */,
      10,    1,  698,    2, 0x06,   17 /* Public */,
      11,    1,  701,    2, 0x06,   19 /* Public */,
      12,    1,  704,    2, 0x06,   21 /* Public */,
      13,    1,  707,    2, 0x06,   23 /* Public */,
      14,    1,  710,    2, 0x06,   25 /* Public */,
      15,    1,  713,    2, 0x06,   27 /* Public */,
      16,    1,  716,    2, 0x06,   29 /* Public */,
      17,    1,  719,    2, 0x06,   31 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  722,    2, 0x0a,   33 /* Public */,
      20,    1,  725,    2, 0x0a,   35 /* Public */,
      21,    1,  728,    2, 0x0a,   37 /* Public */,
      22,    1,  731,    2, 0x0a,   39 /* Public */,
      23,    1,  734,    2, 0x0a,   41 /* Public */,
      24,    1,  737,    2, 0x0a,   43 /* Public */,
      25,    1,  740,    2, 0x0a,   45 /* Public */,
      26,    1,  743,    2, 0x0a,   47 /* Public */,
      27,    0,  746,    2, 0x0a,   49 /* Public */,
      28,    0,  747,    2, 0x0a,   50 /* Public */,
      29,    0,  748,    2, 0x0a,   51 /* Public */,
      30,    0,  749,    2, 0x0a,   52 /* Public */,
      31,    0,  750,    2, 0x0a,   53 /* Public */,
      32,    0,  751,    2, 0x0a,   54 /* Public */,
      33,    0,  752,    2, 0x0a,   55 /* Public */,
      34,    0,  753,    2, 0x0a,   56 /* Public */,
      35,    1,  754,    2, 0x0a,   57 /* Public */,
      36,    1,  757,    2, 0x0a,   59 /* Public */,
      37,    1,  760,    2, 0x0a,   61 /* Public */,
      38,    0,  763,    2, 0x0a,   63 /* Public */,
      39,    1,  764,    2, 0x0a,   64 /* Public */,
      40,    1,  767,    2, 0x0a,   66 /* Public */,
      41,    1,  770,    2, 0x0a,   68 /* Public */,
      42,    1,  773,    2, 0x0a,   70 /* Public */,
      43,    1,  776,    2, 0x0a,   72 /* Public */,
      44,    1,  779,    2, 0x0a,   74 /* Public */,
      45,    1,  782,    2, 0x0a,   76 /* Public */,
      46,    1,  785,    2, 0x0a,   78 /* Public */,
      47,    1,  788,    2, 0x0a,   80 /* Public */,
      48,    1,  791,    2, 0x0a,   82 /* Public */,
      49,    1,  794,    2, 0x0a,   84 /* Public */,
      50,    1,  797,    2, 0x0a,   86 /* Public */,
      51,    0,  800,    2, 0x0a,   88 /* Public */,
      52,    0,  801,    2, 0x0a,   89 /* Public */,
      53,    0,  802,    2, 0x0a,   90 /* Public */,
      54,    0,  803,    2, 0x0a,   91 /* Public */,
      55,    1,  804,    2, 0x0a,   92 /* Public */,
      56,    1,  807,    2, 0x0a,   94 /* Public */,
      57,    1,  810,    2, 0x0a,   96 /* Public */,
      58,    1,  813,    2, 0x0a,   98 /* Public */,
      59,    1,  816,    2, 0x0a,  100 /* Public */,
      60,    1,  819,    2, 0x0a,  102 /* Public */,
      61,    1,  822,    2, 0x0a,  104 /* Public */,
      62,    1,  825,    2, 0x0a,  106 /* Public */,
      63,    1,  828,    2, 0x0a,  108 /* Public */,
      64,    1,  831,    2, 0x0a,  110 /* Public */,
      65,    1,  834,    2, 0x0a,  112 /* Public */,
      66,    1,  837,    2, 0x0a,  114 /* Public */,
      67,    1,  840,    2, 0x0a,  116 /* Public */,
      68,    0,  843,    2, 0x0a,  118 /* Public */,
      69,    0,  844,    2, 0x0a,  119 /* Public */,
      70,    0,  845,    2, 0x0a,  120 /* Public */,
      71,    1,  846,    2, 0x0a,  121 /* Public */,
      72,    1,  849,    2, 0x0a,  123 /* Public */,
      73,    1,  852,    2, 0x0a,  125 /* Public */,
      74,    1,  855,    2, 0x0a,  127 /* Public */,
      75,    1,  858,    2, 0x0a,  129 /* Public */,
      76,    1,  861,    2, 0x0a,  131 /* Public */,
      77,    1,  864,    2, 0x0a,  133 /* Public */,
      78,    1,  867,    2, 0x0a,  135 /* Public */,
      79,    1,  870,    2, 0x0a,  137 /* Public */,
      80,    1,  873,    2, 0x0a,  139 /* Public */,
      81,    1,  876,    2, 0x0a,  141 /* Public */,
      82,    1,  879,    2, 0x0a,  143 /* Public */,
      83,    1,  882,    2, 0x0a,  145 /* Public */,
      84,    1,  885,    2, 0x0a,  147 /* Public */,
      85,    1,  888,    2, 0x0a,  149 /* Public */,
      86,    1,  891,    2, 0x0a,  151 /* Public */,
      87,    1,  894,    2, 0x0a,  153 /* Public */,
      88,    1,  897,    2, 0x0a,  155 /* Public */,
      89,    1,  900,    2, 0x0a,  157 /* Public */,
      90,    1,  903,    2, 0x0a,  159 /* Public */,
      91,    1,  906,    2, 0x0a,  161 /* Public */,
      92,    1,  909,    2, 0x0a,  163 /* Public */,
      93,    0,  912,    2, 0x0a,  165 /* Public */,
      94,    0,  913,    2, 0x0a,  166 /* Public */,
      95,    0,  914,    2, 0x0a,  167 /* Public */,
      96,    0,  915,    2, 0x0a,  168 /* Public */,
      97,    1,  916,    2, 0x0a,  169 /* Public */,
      98,    1,  919,    2, 0x0a,  171 /* Public */,
      99,    1,  922,    2, 0x0a,  173 /* Public */,
     100,    1,  925,    2, 0x0a,  175 /* Public */,
     101,    1,  928,    2, 0x0a,  177 /* Public */,
     102,    1,  931,    2, 0x0a,  179 /* Public */,
     103,    1,  934,    2, 0x0a,  181 /* Public */,
     104,    1,  937,    2, 0x0a,  183 /* Public */,
     105,    1,  940,    2, 0x0a,  185 /* Public */,
     106,    1,  943,    2, 0x0a,  187 /* Public */,
     107,    1,  946,    2, 0x0a,  189 /* Public */,
     108,    1,  949,    2, 0x0a,  191 /* Public */,
     109,    1,  952,    2, 0x0a,  193 /* Public */,
     110,    1,  955,    2, 0x0a,  195 /* Public */,
     111,    1,  958,    2, 0x0a,  197 /* Public */,
     112,    1,  961,    2, 0x0a,  199 /* Public */,

 // signals: parameters
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

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   19,

       0        // eod
};

void cagd::GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setArcAlpha((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setArcScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setArcDivCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setArcX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setArcY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setArcZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setPatchAlpha_U((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setPatchAlpha_V((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setPatchScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setPatchDivCount_U((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setPatchDivCount_V((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setPatchLineCount_U((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setPatchLineCount_V((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setPatchX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setPatchY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->setPatchZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->set_angle_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->set_angle_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->set_angle_z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->set_zoom_factor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->set_trans_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->set_trans_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->set_trans_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->set_selected_page((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->showArcContinueWindow(); break;
        case 25: _t->showArcJoinWindow(); break;
        case 26: _t->showArcMergeWindow(); break;
        case 27: _t->showPatchContinueWindow(); break;
        case 28: _t->showPatchJoinWindow(); break;
        case 29: _t->showPatchMergeWindow(); break;
        case 30: _t->emitArcSignals(); break;
        case 31: _t->emitPatchSignals(); break;
        case 32: _t->arcInsertSetAlpha((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: _t->arcInsertSetScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 34: _t->arcInsertSetDivCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->arcInsertButtonCreate(); break;
        case 36: _t->arcManipulateDoNegDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->arcManipulateDoZerothDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->arcManipulateDoFirstDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->arcManipulateDoSecondDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->arcManipulateSetSelectedArc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->arcManipulateSetSelectedCP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->arcManipulateSet_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->arcManipulateSet_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 44: _t->arcManipulateSet_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 45: _t->arcManipulateSetTranslate_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 46: _t->arcManipulateSetTranslate_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 47: _t->arcManipulateSetTranslate_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 48: _t->arcManipulateButtonDelete(); break;
        case 49: _t->arcInteractionButtonContinue(); break;
        case 50: _t->arcInteractionButtonJoin(); break;
        case 51: _t->arcInteractionButtonMerge(); break;
        case 52: _t->arcInteractionContinueSetArc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->arcInteractionContinueSetDirection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->arcInteractionJoinSetArc1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->arcInteractionJoinSetArc2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->arcInteractionJoinSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->arcInteractionJoinSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->arcInteractionMergeSetArc1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->arcInteractionMergeSetArc2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->arcInteractionMergeSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->arcInteractionMergeSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: _t->patchInsertSetAlpha_U((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 63: _t->patchInsertSetAlpha_V((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 64: _t->patchInsertSetScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 65: _t->patchInsertButtonCreate(); break;
        case 66: _t->patchInsertButtonSave(); break;
        case 67: _t->patchInsertButtonLoad(); break;
        case 68: _t->patchIsoparametricSetDivCount_U((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 69: _t->patchIsoparametricSetDivCount_V((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: _t->patchIsoparametricSetLineCount_U((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->patchIsoparametricSetLineCount_V((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->patchIsoparametricDo_U((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 73: _t->patchIsoparametricDo_V((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 74: _t->patchIsoparametricDoNormal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 75: _t->patchIsoparametricDoFirstDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 76: _t->patchIsoparametricDoSecondDerivatives((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 77: _t->patchManipulateDoPatch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 78: _t->patchManipulateSetSelectedPatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 79: _t->patchManipulateSetSelectedRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: _t->patchManipulateSetSelectedCol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->patchManipulateSet_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 82: _t->patchManipulateSet_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 83: _t->patchManipulateSet_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 84: _t->patchManipulateSetTranslate_X((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 85: _t->patchManipulateSetTranslate_Y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 86: _t->patchManipulateSetTranslate_Z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 87: _t->patchManipulateSetSelectedMaterial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 88: _t->patchManipulateSetSelectedTexture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 89: _t->patchManipulateDoTexture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 90: _t->patchManipulateButtonDelete(); break;
        case 91: _t->patchInteractionButtonContinue(); break;
        case 92: _t->patchInteractionButtonJoin(); break;
        case 93: _t->patchInteractionButtonMerge(); break;
        case 94: _t->patchInteractionContinueSetPatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 95: _t->patchInteractionContinueSetDirection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 96: _t->patchInteractionJoinSetPatch1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 97: _t->patchInteractionJoinSetPatch2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 98: _t->patchInteractionJoinSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: _t->patchInteractionJoinSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: _t->patchInteractionMergeSetPatch1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 101: _t->patchInteractionMergeSetPatch2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 102: _t->patchInteractionMergeSetDirection1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: _t->patchInteractionMergeSetDirection2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 104: _t->shader_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 105: _t->shader_do((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 106: _t->shader_intensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 107: _t->shader_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 108: _t->shader_shading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 109: _t->shader_smoothing((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setArcAlpha)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setArcScale)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setArcDivCount)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setArcX)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setArcY)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setArcZ)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchAlpha_U)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchAlpha_V)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchScale)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchDivCount_U)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchDivCount_V)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchLineCount_U)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchLineCount_V)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchX)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchY)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (GLWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GLWidget::setPatchZ)) {
                *result = 15;
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
, QtPrivate::TypeAndForceComplete<GLWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


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
        if (_id < 110)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 110;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 110)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 110;
    }
    return _id;
}

// SIGNAL 0
void cagd::GLWidget::setArcAlpha(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cagd::GLWidget::setArcScale(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void cagd::GLWidget::setArcDivCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cagd::GLWidget::setArcX(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void cagd::GLWidget::setArcY(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void cagd::GLWidget::setArcZ(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void cagd::GLWidget::setPatchAlpha_U(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void cagd::GLWidget::setPatchAlpha_V(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void cagd::GLWidget::setPatchScale(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void cagd::GLWidget::setPatchDivCount_U(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void cagd::GLWidget::setPatchDivCount_V(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void cagd::GLWidget::setPatchLineCount_U(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void cagd::GLWidget::setPatchLineCount_V(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void cagd::GLWidget::setPatchX(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void cagd::GLWidget::setPatchY(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void cagd::GLWidget::setPatchZ(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
