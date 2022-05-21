/********************************************************************************
** Form generated from reading UI file 'SideWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEWIDGET_H
#define UI_SIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideWidget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *rotate_x_slider;
    QLabel *label_2;
    QSlider *rotate_y_slider;
    QLabel *label_3;
    QSlider *rotate_z_slider;
    QLabel *label_4;
    QDoubleSpinBox *zoom_factor_spin_box;
    QLabel *label_5;
    QDoubleSpinBox *trans_x_spin_box;
    QLabel *label_6;
    QDoubleSpinBox *trans_y_spin_box;
    QLabel *label_7;
    QDoubleSpinBox *trans_z_spin_box;
    QCheckBox *doShader;
    QSpinBox *shaderSelector;
    QDoubleSpinBox *shader_scale;
    QDoubleSpinBox *shader_smoothing;
    QDoubleSpinBox *shader_shading;
    QLabel *shader_label_8;
    QLabel *shader_label_9;
    QLabel *shader_label_10;
    QDoubleSpinBox *shader_intensity;
    QLabel *shader_label_11;
    QTabWidget *page_tabs;
    QWidget *tabArc;
    QToolBox *arcToolBox;
    QWidget *arcCreation;
    QToolButton *arcInsertButton;
    QWidget *formLayoutWidget;
    QFormLayout *arcInsertFormLayout;
    QLabel *arcInsertLabel_Alpha;
    QDoubleSpinBox *arcInsertDSpinBox_Alpha;
    QDoubleSpinBox *arcInsertDSpinBox_Scale;
    QLabel *arcInsertLabel_Scale;
    QDoubleSpinBox *arcInsertDSpinBox_DivCount;
    QLabel *arcInsertLabel_DivCount;
    QWidget *arcManipulation;
    QToolButton *arcDeleteButton;
    QWidget *formLayoutWidget_4;
    QFormLayout *arcManipulationFormLayout;
    QLabel *arcManipulateLabel_ControlPoint;
    QSpinBox *arcManipulateISpinBox_ControlPoint;
    QLabel *arcManipulateLabel_X;
    QDoubleSpinBox *arcManipulateDSpinBox_X;
    QLabel *arcManipulateLabel_Y;
    QLabel *arcManipulateLabel_Z;
    QDoubleSpinBox *arcManipulateDSpinBox_Y;
    QDoubleSpinBox *arcManipulateDSpinBox_Z;
    QLabel *arcManipulateLabel_SelectArc;
    QSpinBox *arcManipulateISpinBox_SelectArc;
    QDoubleSpinBox *arcManipulateDSpinBox_TranslateX;
    QDoubleSpinBox *arcManipulateDSpinBox_TranslateY;
    QDoubleSpinBox *arcManipulateDSpinBox_TranslateZ;
    QLabel *arcManipulateLabel_TranslateX;
    QLabel *arcManipulateLabel_TranslateY;
    QLabel *arcManipulateLabel_TranslateZ;
    QWidget *formLayoutWidget_16;
    QFormLayout *formLayout_2;
    QCheckBox *arcManipulationCheckBox_FirstOrder;
    QCheckBox *arcManipulationCheckBox_SecondOrder;
    QWidget *arcInteraction;
    QToolButton *arcContinueButton;
    QToolButton *arcMergeButton;
    QToolButton *arcJoinButton;
    QWidget *tabPatch;
    QToolBox *patchToolBox;
    QWidget *patchCreation;
    QToolButton *patchInsertButton;
    QWidget *formLayoutWidget_13;
    QFormLayout *patchInsertFormLayout;
    QLabel *patchInsertLabel_UAlpha;
    QDoubleSpinBox *patchInsertDSpinBox_VAlpha;
    QLabel *patchInsertLabel_VAlpha;
    QDoubleSpinBox *patchInsertDSpinBox_UAlpha;
    QLabel *patchInsertLabel_Scale;
    QDoubleSpinBox *patchInsertDSpinBox_Scale;
    QToolButton *patchSaveButton;
    QToolButton *patchLoadButton;
    QWidget *patchIsoparametricLines;
    QWidget *formLayoutWidget_15;
    QFormLayout *patchIsoparametricFormLayout;
    QLabel *patchIsoparametricLabel_UDivCount;
    QLabel *patchIsoparametricLabel_VDivCount;
    QLabel *patchIsoparametricLabel_ULineCount;
    QLabel *patchIsoparametricLabel_VLineCount;
    QSpinBox *patchIsoparametricISpinBox_UDivCount;
    QSpinBox *patchIsoparametricISpinBox_VDivCount;
    QSpinBox *patchIsoparametricISpinBox_ULineCount;
    QSpinBox *patchIsoparametricISpinBox_VLineCount;
    QWidget *patchManipulation;
    QToolButton *patchDeleteButton;
    QWidget *formLayoutWidget_14;
    QFormLayout *patchManipulationFormLayout_Positions;
    QLabel *patchManipulateLabel_X;
    QDoubleSpinBox *patchManipulateDSpinBox_X;
    QLabel *patchManipulateLabel_Y;
    QDoubleSpinBox *patchManipulateDSpinBox_Y;
    QLabel *patchManipulateLabel_Z;
    QDoubleSpinBox *patchManipulateDSpinBox_Z;
    QLabel *patchManipulateLabel_TranlsateX;
    QDoubleSpinBox *patchManipulateDSpinBox_TranslateX;
    QLabel *patchManipulateLabel_TranslateY;
    QDoubleSpinBox *patchManipulateDSpinBox_TranslateY;
    QLabel *patchManipulateLabel_TranslateZ;
    QDoubleSpinBox *patchManipulateDSpinBox_TranslateZ;
    QSpinBox *patchManipulateISpinBox_Material;
    QLabel *patchManipulateLabel_Material;
    QSpinBox *patchManipulateISpinBox_Texture;
    QLabel *patchManipulateLabel_Texture;
    QCheckBox *patchManipulateCheckBox_DoTexture;
    QWidget *formLayoutWidget_17;
    QFormLayout *patchManipulationFormLayout_CheckBoxes;
    QCheckBox *patchManipulationCheckBox_FirstOrder;
    QCheckBox *patchManipulationCheckBox_SecondOrder;
    QCheckBox *patchManipulationCheckBox_NormalVector;
    QWidget *formLayoutWidget_18;
    QFormLayout *patchManipulationFormLayout_SelectPatch;
    QSpinBox *patchManipulateISpinBox_SelectPatch;
    QLabel *patchManipulateLabel_SelectPatch;
    QWidget *formLayoutWidget_19;
    QFormLayout *patchManipulationFormLayoutSelectRow;
    QLabel *patchManipulateLabel_SelectRow;
    QSpinBox *patchManipulateISpinBox_SelectRow;
    QWidget *formLayoutWidget_20;
    QFormLayout *patchManipulationFormLayout_SelectColumn;
    QLabel *patchManipulateLabel_SelectColumn;
    QSpinBox *patchManipulateISpinBox_SelectColumn;
    QWidget *patchInteraction;
    QToolButton *patchContinueButton;
    QToolButton *patchMergeButton;
    QToolButton *patchJoinButton;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QString::fromUtf8("SideWidget"));
        SideWidget->resize(334, 1086);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 331, 1081));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 21, 321, 401));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        rotate_x_slider = new QSlider(layoutWidget);
        rotate_x_slider->setObjectName(QString::fromUtf8("rotate_x_slider"));
        rotate_x_slider->setMinimum(-180);
        rotate_x_slider->setMaximum(180);
        rotate_x_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, rotate_x_slider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        rotate_y_slider = new QSlider(layoutWidget);
        rotate_y_slider->setObjectName(QString::fromUtf8("rotate_y_slider"));
        rotate_y_slider->setMinimum(-180);
        rotate_y_slider->setMaximum(180);
        rotate_y_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, rotate_y_slider);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        rotate_z_slider = new QSlider(layoutWidget);
        rotate_z_slider->setObjectName(QString::fromUtf8("rotate_z_slider"));
        rotate_z_slider->setMinimum(-180);
        rotate_z_slider->setMaximum(180);
        rotate_z_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, rotate_z_slider);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        zoom_factor_spin_box = new QDoubleSpinBox(layoutWidget);
        zoom_factor_spin_box->setObjectName(QString::fromUtf8("zoom_factor_spin_box"));
        zoom_factor_spin_box->setDecimals(5);
        zoom_factor_spin_box->setMinimum(0.000100000000000);
        zoom_factor_spin_box->setMaximum(10000.000000000000000);
        zoom_factor_spin_box->setSingleStep(0.010000000000000);
        zoom_factor_spin_box->setValue(1.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, zoom_factor_spin_box);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        trans_x_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_x_spin_box->setObjectName(QString::fromUtf8("trans_x_spin_box"));
        trans_x_spin_box->setMinimum(-100.000000000000000);
        trans_x_spin_box->setMaximum(100.000000000000000);
        trans_x_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, trans_x_spin_box);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        trans_y_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_y_spin_box->setObjectName(QString::fromUtf8("trans_y_spin_box"));
        trans_y_spin_box->setMinimum(-100.000000000000000);
        trans_y_spin_box->setMaximum(100.000000000000000);
        trans_y_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, trans_y_spin_box);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        trans_z_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_z_spin_box->setObjectName(QString::fromUtf8("trans_z_spin_box"));
        trans_z_spin_box->setMinimum(-100.000000000000000);
        trans_z_spin_box->setMaximum(100.000000000000000);
        trans_z_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, trans_z_spin_box);

        doShader = new QCheckBox(layoutWidget);
        doShader->setObjectName(QString::fromUtf8("doShader"));

        formLayout->setWidget(7, QFormLayout::LabelRole, doShader);

        shaderSelector = new QSpinBox(layoutWidget);
        shaderSelector->setObjectName(QString::fromUtf8("shaderSelector"));
        shaderSelector->setMaximum(3);

        formLayout->setWidget(7, QFormLayout::FieldRole, shaderSelector);

        shader_scale = new QDoubleSpinBox(layoutWidget);
        shader_scale->setObjectName(QString::fromUtf8("shader_scale"));
        shader_scale->setSingleStep(0.010000000000000);
        shader_scale->setValue(1.000000000000000);

        formLayout->setWidget(8, QFormLayout::FieldRole, shader_scale);

        shader_smoothing = new QDoubleSpinBox(layoutWidget);
        shader_smoothing->setObjectName(QString::fromUtf8("shader_smoothing"));
        shader_smoothing->setSingleStep(0.010000000000000);
        shader_smoothing->setValue(1.000000000000000);

        formLayout->setWidget(9, QFormLayout::FieldRole, shader_smoothing);

        shader_shading = new QDoubleSpinBox(layoutWidget);
        shader_shading->setObjectName(QString::fromUtf8("shader_shading"));
        shader_shading->setSingleStep(0.010000000000000);
        shader_shading->setValue(1.000000000000000);

        formLayout->setWidget(10, QFormLayout::FieldRole, shader_shading);

        shader_label_8 = new QLabel(layoutWidget);
        shader_label_8->setObjectName(QString::fromUtf8("shader_label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, shader_label_8);

        shader_label_9 = new QLabel(layoutWidget);
        shader_label_9->setObjectName(QString::fromUtf8("shader_label_9"));

        formLayout->setWidget(9, QFormLayout::LabelRole, shader_label_9);

        shader_label_10 = new QLabel(layoutWidget);
        shader_label_10->setObjectName(QString::fromUtf8("shader_label_10"));

        formLayout->setWidget(10, QFormLayout::LabelRole, shader_label_10);

        shader_intensity = new QDoubleSpinBox(layoutWidget);
        shader_intensity->setObjectName(QString::fromUtf8("shader_intensity"));
        shader_intensity->setMaximum(1.000000000000000);
        shader_intensity->setSingleStep(0.010000000000000);
        shader_intensity->setValue(1.000000000000000);

        formLayout->setWidget(11, QFormLayout::FieldRole, shader_intensity);

        shader_label_11 = new QLabel(layoutWidget);
        shader_label_11->setObjectName(QString::fromUtf8("shader_label_11"));

        formLayout->setWidget(11, QFormLayout::LabelRole, shader_label_11);

        page_tabs = new QTabWidget(groupBox);
        page_tabs->setObjectName(QString::fromUtf8("page_tabs"));
        page_tabs->setGeometry(QRect(10, 370, 311, 701));
        tabArc = new QWidget();
        tabArc->setObjectName(QString::fromUtf8("tabArc"));
        arcToolBox = new QToolBox(tabArc);
        arcToolBox->setObjectName(QString::fromUtf8("arcToolBox"));
        arcToolBox->setGeometry(QRect(10, 10, 291, 501));
        arcCreation = new QWidget();
        arcCreation->setObjectName(QString::fromUtf8("arcCreation"));
        arcCreation->setGeometry(QRect(0, 0, 291, 396));
        arcInsertButton = new QToolButton(arcCreation);
        arcInsertButton->setObjectName(QString::fromUtf8("arcInsertButton"));
        arcInsertButton->setGeometry(QRect(70, 150, 131, 51));
        formLayoutWidget = new QWidget(arcCreation);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 271, 137));
        arcInsertFormLayout = new QFormLayout(formLayoutWidget);
        arcInsertFormLayout->setObjectName(QString::fromUtf8("arcInsertFormLayout"));
        arcInsertFormLayout->setContentsMargins(0, 0, 0, 0);
        arcInsertLabel_Alpha = new QLabel(formLayoutWidget);
        arcInsertLabel_Alpha->setObjectName(QString::fromUtf8("arcInsertLabel_Alpha"));

        arcInsertFormLayout->setWidget(0, QFormLayout::LabelRole, arcInsertLabel_Alpha);

        arcInsertDSpinBox_Alpha = new QDoubleSpinBox(formLayoutWidget);
        arcInsertDSpinBox_Alpha->setObjectName(QString::fromUtf8("arcInsertDSpinBox_Alpha"));

        arcInsertFormLayout->setWidget(0, QFormLayout::FieldRole, arcInsertDSpinBox_Alpha);

        arcInsertDSpinBox_Scale = new QDoubleSpinBox(formLayoutWidget);
        arcInsertDSpinBox_Scale->setObjectName(QString::fromUtf8("arcInsertDSpinBox_Scale"));

        arcInsertFormLayout->setWidget(1, QFormLayout::FieldRole, arcInsertDSpinBox_Scale);

        arcInsertLabel_Scale = new QLabel(formLayoutWidget);
        arcInsertLabel_Scale->setObjectName(QString::fromUtf8("arcInsertLabel_Scale"));

        arcInsertFormLayout->setWidget(1, QFormLayout::LabelRole, arcInsertLabel_Scale);

        arcInsertDSpinBox_DivCount = new QDoubleSpinBox(formLayoutWidget);
        arcInsertDSpinBox_DivCount->setObjectName(QString::fromUtf8("arcInsertDSpinBox_DivCount"));

        arcInsertFormLayout->setWidget(2, QFormLayout::FieldRole, arcInsertDSpinBox_DivCount);

        arcInsertLabel_DivCount = new QLabel(formLayoutWidget);
        arcInsertLabel_DivCount->setObjectName(QString::fromUtf8("arcInsertLabel_DivCount"));

        arcInsertFormLayout->setWidget(2, QFormLayout::LabelRole, arcInsertLabel_DivCount);

        arcToolBox->addItem(arcCreation, QString::fromUtf8("Create SOT Arc"));
        arcManipulation = new QWidget();
        arcManipulation->setObjectName(QString::fromUtf8("arcManipulation"));
        arcDeleteButton = new QToolButton(arcManipulation);
        arcDeleteButton->setObjectName(QString::fromUtf8("arcDeleteButton"));
        arcDeleteButton->setGeometry(QRect(70, 320, 131, 51));
        formLayoutWidget_4 = new QWidget(arcManipulation);
        formLayoutWidget_4->setObjectName(QString::fromUtf8("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 80, 271, 231));
        arcManipulationFormLayout = new QFormLayout(formLayoutWidget_4);
        arcManipulationFormLayout->setObjectName(QString::fromUtf8("arcManipulationFormLayout"));
        arcManipulationFormLayout->setContentsMargins(0, 0, 0, 0);
        arcManipulateLabel_ControlPoint = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_ControlPoint->setObjectName(QString::fromUtf8("arcManipulateLabel_ControlPoint"));

        arcManipulationFormLayout->setWidget(1, QFormLayout::LabelRole, arcManipulateLabel_ControlPoint);

        arcManipulateISpinBox_ControlPoint = new QSpinBox(formLayoutWidget_4);
        arcManipulateISpinBox_ControlPoint->setObjectName(QString::fromUtf8("arcManipulateISpinBox_ControlPoint"));
        arcManipulateISpinBox_ControlPoint->setMinimum(0);
        arcManipulateISpinBox_ControlPoint->setMaximum(3);
        arcManipulateISpinBox_ControlPoint->setValue(0);

        arcManipulationFormLayout->setWidget(1, QFormLayout::FieldRole, arcManipulateISpinBox_ControlPoint);

        arcManipulateLabel_X = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_X->setObjectName(QString::fromUtf8("arcManipulateLabel_X"));

        arcManipulationFormLayout->setWidget(2, QFormLayout::LabelRole, arcManipulateLabel_X);

        arcManipulateDSpinBox_X = new QDoubleSpinBox(formLayoutWidget_4);
        arcManipulateDSpinBox_X->setObjectName(QString::fromUtf8("arcManipulateDSpinBox_X"));
        arcManipulateDSpinBox_X->setMinimum(-99.989999999999995);
        arcManipulateDSpinBox_X->setSingleStep(0.100000000000000);

        arcManipulationFormLayout->setWidget(2, QFormLayout::FieldRole, arcManipulateDSpinBox_X);

        arcManipulateLabel_Y = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_Y->setObjectName(QString::fromUtf8("arcManipulateLabel_Y"));

        arcManipulationFormLayout->setWidget(3, QFormLayout::LabelRole, arcManipulateLabel_Y);

        arcManipulateLabel_Z = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_Z->setObjectName(QString::fromUtf8("arcManipulateLabel_Z"));

        arcManipulationFormLayout->setWidget(4, QFormLayout::LabelRole, arcManipulateLabel_Z);

        arcManipulateDSpinBox_Y = new QDoubleSpinBox(formLayoutWidget_4);
        arcManipulateDSpinBox_Y->setObjectName(QString::fromUtf8("arcManipulateDSpinBox_Y"));
        arcManipulateDSpinBox_Y->setMinimum(-99.989999999999995);
        arcManipulateDSpinBox_Y->setSingleStep(0.100000000000000);

        arcManipulationFormLayout->setWidget(3, QFormLayout::FieldRole, arcManipulateDSpinBox_Y);

        arcManipulateDSpinBox_Z = new QDoubleSpinBox(formLayoutWidget_4);
        arcManipulateDSpinBox_Z->setObjectName(QString::fromUtf8("arcManipulateDSpinBox_Z"));
        arcManipulateDSpinBox_Z->setMinimum(-99.989999999999995);
        arcManipulateDSpinBox_Z->setSingleStep(0.100000000000000);

        arcManipulationFormLayout->setWidget(4, QFormLayout::FieldRole, arcManipulateDSpinBox_Z);

        arcManipulateLabel_SelectArc = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_SelectArc->setObjectName(QString::fromUtf8("arcManipulateLabel_SelectArc"));

        arcManipulationFormLayout->setWidget(0, QFormLayout::LabelRole, arcManipulateLabel_SelectArc);

        arcManipulateISpinBox_SelectArc = new QSpinBox(formLayoutWidget_4);
        arcManipulateISpinBox_SelectArc->setObjectName(QString::fromUtf8("arcManipulateISpinBox_SelectArc"));
        arcManipulateISpinBox_SelectArc->setMinimum(0);
        arcManipulateISpinBox_SelectArc->setMaximum(100);
        arcManipulateISpinBox_SelectArc->setValue(0);

        arcManipulationFormLayout->setWidget(0, QFormLayout::FieldRole, arcManipulateISpinBox_SelectArc);

        arcManipulateDSpinBox_TranslateX = new QDoubleSpinBox(formLayoutWidget_4);
        arcManipulateDSpinBox_TranslateX->setObjectName(QString::fromUtf8("arcManipulateDSpinBox_TranslateX"));
        arcManipulateDSpinBox_TranslateX->setMinimum(-100.000000000000000);
        arcManipulateDSpinBox_TranslateX->setMaximum(100.000000000000000);
        arcManipulateDSpinBox_TranslateX->setSingleStep(0.100000000000000);

        arcManipulationFormLayout->setWidget(5, QFormLayout::FieldRole, arcManipulateDSpinBox_TranslateX);

        arcManipulateDSpinBox_TranslateY = new QDoubleSpinBox(formLayoutWidget_4);
        arcManipulateDSpinBox_TranslateY->setObjectName(QString::fromUtf8("arcManipulateDSpinBox_TranslateY"));
        arcManipulateDSpinBox_TranslateY->setMinimum(-100.000000000000000);
        arcManipulateDSpinBox_TranslateY->setMaximum(100.000000000000000);
        arcManipulateDSpinBox_TranslateY->setSingleStep(0.100000000000000);
        arcManipulateDSpinBox_TranslateY->setStepType(QAbstractSpinBox::DefaultStepType);

        arcManipulationFormLayout->setWidget(6, QFormLayout::FieldRole, arcManipulateDSpinBox_TranslateY);

        arcManipulateDSpinBox_TranslateZ = new QDoubleSpinBox(formLayoutWidget_4);
        arcManipulateDSpinBox_TranslateZ->setObjectName(QString::fromUtf8("arcManipulateDSpinBox_TranslateZ"));
        arcManipulateDSpinBox_TranslateZ->setMinimum(-100.000000000000000);
        arcManipulateDSpinBox_TranslateZ->setMaximum(100.000000000000000);
        arcManipulateDSpinBox_TranslateZ->setSingleStep(0.100000000000000);
        arcManipulateDSpinBox_TranslateZ->setValue(0.000000000000000);

        arcManipulationFormLayout->setWidget(7, QFormLayout::FieldRole, arcManipulateDSpinBox_TranslateZ);

        arcManipulateLabel_TranslateX = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_TranslateX->setObjectName(QString::fromUtf8("arcManipulateLabel_TranslateX"));

        arcManipulationFormLayout->setWidget(5, QFormLayout::LabelRole, arcManipulateLabel_TranslateX);

        arcManipulateLabel_TranslateY = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_TranslateY->setObjectName(QString::fromUtf8("arcManipulateLabel_TranslateY"));

        arcManipulationFormLayout->setWidget(6, QFormLayout::LabelRole, arcManipulateLabel_TranslateY);

        arcManipulateLabel_TranslateZ = new QLabel(formLayoutWidget_4);
        arcManipulateLabel_TranslateZ->setObjectName(QString::fromUtf8("arcManipulateLabel_TranslateZ"));

        arcManipulationFormLayout->setWidget(7, QFormLayout::LabelRole, arcManipulateLabel_TranslateZ);

        formLayoutWidget_16 = new QWidget(arcManipulation);
        formLayoutWidget_16->setObjectName(QString::fromUtf8("formLayoutWidget_16"));
        formLayoutWidget_16->setGeometry(QRect(9, 9, 271, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_16);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        arcManipulationCheckBox_FirstOrder = new QCheckBox(formLayoutWidget_16);
        arcManipulationCheckBox_FirstOrder->setObjectName(QString::fromUtf8("arcManipulationCheckBox_FirstOrder"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, arcManipulationCheckBox_FirstOrder);

        arcManipulationCheckBox_SecondOrder = new QCheckBox(formLayoutWidget_16);
        arcManipulationCheckBox_SecondOrder->setObjectName(QString::fromUtf8("arcManipulationCheckBox_SecondOrder"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, arcManipulationCheckBox_SecondOrder);

        arcToolBox->addItem(arcManipulation, QString::fromUtf8("Manipulate Arc"));
        arcInteraction = new QWidget();
        arcInteraction->setObjectName(QString::fromUtf8("arcInteraction"));
        arcInteraction->setGeometry(QRect(0, 0, 291, 396));
        arcContinueButton = new QToolButton(arcInteraction);
        arcContinueButton->setObjectName(QString::fromUtf8("arcContinueButton"));
        arcContinueButton->setGeometry(QRect(70, 20, 131, 51));
        arcMergeButton = new QToolButton(arcInteraction);
        arcMergeButton->setObjectName(QString::fromUtf8("arcMergeButton"));
        arcMergeButton->setGeometry(QRect(70, 160, 131, 51));
        arcJoinButton = new QToolButton(arcInteraction);
        arcJoinButton->setObjectName(QString::fromUtf8("arcJoinButton"));
        arcJoinButton->setGeometry(QRect(70, 90, 131, 51));
        arcToolBox->addItem(arcInteraction, QString::fromUtf8("Interactions With SOT Arcs"));
        page_tabs->addTab(tabArc, QString());
        tabPatch = new QWidget();
        tabPatch->setObjectName(QString::fromUtf8("tabPatch"));
        patchToolBox = new QToolBox(tabPatch);
        patchToolBox->setObjectName(QString::fromUtf8("patchToolBox"));
        patchToolBox->setGeometry(QRect(10, 10, 291, 641));
        patchCreation = new QWidget();
        patchCreation->setObjectName(QString::fromUtf8("patchCreation"));
        patchCreation->setGeometry(QRect(0, 0, 291, 501));
        patchInsertButton = new QToolButton(patchCreation);
        patchInsertButton->setObjectName(QString::fromUtf8("patchInsertButton"));
        patchInsertButton->setGeometry(QRect(70, 180, 131, 51));
        formLayoutWidget_13 = new QWidget(patchCreation);
        formLayoutWidget_13->setObjectName(QString::fromUtf8("formLayoutWidget_13"));
        formLayoutWidget_13->setGeometry(QRect(9, 9, 271, 166));
        patchInsertFormLayout = new QFormLayout(formLayoutWidget_13);
        patchInsertFormLayout->setObjectName(QString::fromUtf8("patchInsertFormLayout"));
        patchInsertFormLayout->setContentsMargins(0, 0, 0, 0);
        patchInsertLabel_UAlpha = new QLabel(formLayoutWidget_13);
        patchInsertLabel_UAlpha->setObjectName(QString::fromUtf8("patchInsertLabel_UAlpha"));

        patchInsertFormLayout->setWidget(0, QFormLayout::LabelRole, patchInsertLabel_UAlpha);

        patchInsertDSpinBox_VAlpha = new QDoubleSpinBox(formLayoutWidget_13);
        patchInsertDSpinBox_VAlpha->setObjectName(QString::fromUtf8("patchInsertDSpinBox_VAlpha"));

        patchInsertFormLayout->setWidget(0, QFormLayout::FieldRole, patchInsertDSpinBox_VAlpha);

        patchInsertLabel_VAlpha = new QLabel(formLayoutWidget_13);
        patchInsertLabel_VAlpha->setObjectName(QString::fromUtf8("patchInsertLabel_VAlpha"));

        patchInsertFormLayout->setWidget(1, QFormLayout::LabelRole, patchInsertLabel_VAlpha);

        patchInsertDSpinBox_UAlpha = new QDoubleSpinBox(formLayoutWidget_13);
        patchInsertDSpinBox_UAlpha->setObjectName(QString::fromUtf8("patchInsertDSpinBox_UAlpha"));

        patchInsertFormLayout->setWidget(1, QFormLayout::FieldRole, patchInsertDSpinBox_UAlpha);

        patchInsertLabel_Scale = new QLabel(formLayoutWidget_13);
        patchInsertLabel_Scale->setObjectName(QString::fromUtf8("patchInsertLabel_Scale"));

        patchInsertFormLayout->setWidget(2, QFormLayout::LabelRole, patchInsertLabel_Scale);

        patchInsertDSpinBox_Scale = new QDoubleSpinBox(formLayoutWidget_13);
        patchInsertDSpinBox_Scale->setObjectName(QString::fromUtf8("patchInsertDSpinBox_Scale"));

        patchInsertFormLayout->setWidget(2, QFormLayout::FieldRole, patchInsertDSpinBox_Scale);

        patchSaveButton = new QToolButton(patchCreation);
        patchSaveButton->setObjectName(QString::fromUtf8("patchSaveButton"));
        patchSaveButton->setGeometry(QRect(70, 240, 131, 51));
        patchLoadButton = new QToolButton(patchCreation);
        patchLoadButton->setObjectName(QString::fromUtf8("patchLoadButton"));
        patchLoadButton->setGeometry(QRect(70, 300, 131, 51));
        patchToolBox->addItem(patchCreation, QString::fromUtf8("Create SOT Patch"));
        patchIsoparametricLines = new QWidget();
        patchIsoparametricLines->setObjectName(QString::fromUtf8("patchIsoparametricLines"));
        formLayoutWidget_15 = new QWidget(patchIsoparametricLines);
        formLayoutWidget_15->setObjectName(QString::fromUtf8("formLayoutWidget_15"));
        formLayoutWidget_15->setGeometry(QRect(10, 10, 271, 141));
        patchIsoparametricFormLayout = new QFormLayout(formLayoutWidget_15);
        patchIsoparametricFormLayout->setObjectName(QString::fromUtf8("patchIsoparametricFormLayout"));
        patchIsoparametricFormLayout->setContentsMargins(0, 0, 0, 0);
        patchIsoparametricLabel_UDivCount = new QLabel(formLayoutWidget_15);
        patchIsoparametricLabel_UDivCount->setObjectName(QString::fromUtf8("patchIsoparametricLabel_UDivCount"));

        patchIsoparametricFormLayout->setWidget(0, QFormLayout::LabelRole, patchIsoparametricLabel_UDivCount);

        patchIsoparametricLabel_VDivCount = new QLabel(formLayoutWidget_15);
        patchIsoparametricLabel_VDivCount->setObjectName(QString::fromUtf8("patchIsoparametricLabel_VDivCount"));

        patchIsoparametricFormLayout->setWidget(1, QFormLayout::LabelRole, patchIsoparametricLabel_VDivCount);

        patchIsoparametricLabel_ULineCount = new QLabel(formLayoutWidget_15);
        patchIsoparametricLabel_ULineCount->setObjectName(QString::fromUtf8("patchIsoparametricLabel_ULineCount"));

        patchIsoparametricFormLayout->setWidget(2, QFormLayout::LabelRole, patchIsoparametricLabel_ULineCount);

        patchIsoparametricLabel_VLineCount = new QLabel(formLayoutWidget_15);
        patchIsoparametricLabel_VLineCount->setObjectName(QString::fromUtf8("patchIsoparametricLabel_VLineCount"));

        patchIsoparametricFormLayout->setWidget(3, QFormLayout::LabelRole, patchIsoparametricLabel_VLineCount);

        patchIsoparametricISpinBox_UDivCount = new QSpinBox(formLayoutWidget_15);
        patchIsoparametricISpinBox_UDivCount->setObjectName(QString::fromUtf8("patchIsoparametricISpinBox_UDivCount"));
        patchIsoparametricISpinBox_UDivCount->setMinimum(10);
        patchIsoparametricISpinBox_UDivCount->setMaximum(200);
        patchIsoparametricISpinBox_UDivCount->setValue(100);

        patchIsoparametricFormLayout->setWidget(0, QFormLayout::FieldRole, patchIsoparametricISpinBox_UDivCount);

        patchIsoparametricISpinBox_VDivCount = new QSpinBox(formLayoutWidget_15);
        patchIsoparametricISpinBox_VDivCount->setObjectName(QString::fromUtf8("patchIsoparametricISpinBox_VDivCount"));
        patchIsoparametricISpinBox_VDivCount->setMinimum(10);
        patchIsoparametricISpinBox_VDivCount->setMaximum(200);
        patchIsoparametricISpinBox_VDivCount->setValue(100);

        patchIsoparametricFormLayout->setWidget(1, QFormLayout::FieldRole, patchIsoparametricISpinBox_VDivCount);

        patchIsoparametricISpinBox_ULineCount = new QSpinBox(formLayoutWidget_15);
        patchIsoparametricISpinBox_ULineCount->setObjectName(QString::fromUtf8("patchIsoparametricISpinBox_ULineCount"));
        patchIsoparametricISpinBox_ULineCount->setMinimum(2);
        patchIsoparametricISpinBox_ULineCount->setMaximum(10);
        patchIsoparametricISpinBox_ULineCount->setValue(5);

        patchIsoparametricFormLayout->setWidget(2, QFormLayout::FieldRole, patchIsoparametricISpinBox_ULineCount);

        patchIsoparametricISpinBox_VLineCount = new QSpinBox(formLayoutWidget_15);
        patchIsoparametricISpinBox_VLineCount->setObjectName(QString::fromUtf8("patchIsoparametricISpinBox_VLineCount"));
        patchIsoparametricISpinBox_VLineCount->setMinimum(2);
        patchIsoparametricISpinBox_VLineCount->setMaximum(10);
        patchIsoparametricISpinBox_VLineCount->setValue(5);

        patchIsoparametricFormLayout->setWidget(3, QFormLayout::FieldRole, patchIsoparametricISpinBox_VLineCount);

        patchToolBox->addItem(patchIsoparametricLines, QString::fromUtf8("Isoparametric Lines"));
        patchManipulation = new QWidget();
        patchManipulation->setObjectName(QString::fromUtf8("patchManipulation"));
        patchManipulation->setGeometry(QRect(0, 0, 291, 511));
        patchDeleteButton = new QToolButton(patchManipulation);
        patchDeleteButton->setObjectName(QString::fromUtf8("patchDeleteButton"));
        patchDeleteButton->setGeometry(QRect(70, 460, 131, 51));
        formLayoutWidget_14 = new QWidget(patchManipulation);
        formLayoutWidget_14->setObjectName(QString::fromUtf8("formLayoutWidget_14"));
        formLayoutWidget_14->setGeometry(QRect(10, 180, 271, 351));
        patchManipulationFormLayout_Positions = new QFormLayout(formLayoutWidget_14);
        patchManipulationFormLayout_Positions->setObjectName(QString::fromUtf8("patchManipulationFormLayout_Positions"));
        patchManipulationFormLayout_Positions->setContentsMargins(0, 0, 0, 0);
        patchManipulateLabel_X = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_X->setObjectName(QString::fromUtf8("patchManipulateLabel_X"));

        patchManipulationFormLayout_Positions->setWidget(1, QFormLayout::LabelRole, patchManipulateLabel_X);

        patchManipulateDSpinBox_X = new QDoubleSpinBox(formLayoutWidget_14);
        patchManipulateDSpinBox_X->setObjectName(QString::fromUtf8("patchManipulateDSpinBox_X"));
        patchManipulateDSpinBox_X->setMinimum(-99.989999999999995);
        patchManipulateDSpinBox_X->setSingleStep(0.100000000000000);

        patchManipulationFormLayout_Positions->setWidget(1, QFormLayout::FieldRole, patchManipulateDSpinBox_X);

        patchManipulateLabel_Y = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_Y->setObjectName(QString::fromUtf8("patchManipulateLabel_Y"));

        patchManipulationFormLayout_Positions->setWidget(2, QFormLayout::LabelRole, patchManipulateLabel_Y);

        patchManipulateDSpinBox_Y = new QDoubleSpinBox(formLayoutWidget_14);
        patchManipulateDSpinBox_Y->setObjectName(QString::fromUtf8("patchManipulateDSpinBox_Y"));
        patchManipulateDSpinBox_Y->setMinimum(-99.989999999999995);
        patchManipulateDSpinBox_Y->setSingleStep(0.100000000000000);

        patchManipulationFormLayout_Positions->setWidget(2, QFormLayout::FieldRole, patchManipulateDSpinBox_Y);

        patchManipulateLabel_Z = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_Z->setObjectName(QString::fromUtf8("patchManipulateLabel_Z"));

        patchManipulationFormLayout_Positions->setWidget(3, QFormLayout::LabelRole, patchManipulateLabel_Z);

        patchManipulateDSpinBox_Z = new QDoubleSpinBox(formLayoutWidget_14);
        patchManipulateDSpinBox_Z->setObjectName(QString::fromUtf8("patchManipulateDSpinBox_Z"));
        patchManipulateDSpinBox_Z->setMinimum(-99.989999999999995);
        patchManipulateDSpinBox_Z->setSingleStep(0.100000000000000);

        patchManipulationFormLayout_Positions->setWidget(3, QFormLayout::FieldRole, patchManipulateDSpinBox_Z);

        patchManipulateLabel_TranlsateX = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_TranlsateX->setObjectName(QString::fromUtf8("patchManipulateLabel_TranlsateX"));

        patchManipulationFormLayout_Positions->setWidget(4, QFormLayout::LabelRole, patchManipulateLabel_TranlsateX);

        patchManipulateDSpinBox_TranslateX = new QDoubleSpinBox(formLayoutWidget_14);
        patchManipulateDSpinBox_TranslateX->setObjectName(QString::fromUtf8("patchManipulateDSpinBox_TranslateX"));
        patchManipulateDSpinBox_TranslateX->setMinimum(-100.000000000000000);
        patchManipulateDSpinBox_TranslateX->setMaximum(100.000000000000000);
        patchManipulateDSpinBox_TranslateX->setSingleStep(0.100000000000000);

        patchManipulationFormLayout_Positions->setWidget(4, QFormLayout::FieldRole, patchManipulateDSpinBox_TranslateX);

        patchManipulateLabel_TranslateY = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_TranslateY->setObjectName(QString::fromUtf8("patchManipulateLabel_TranslateY"));

        patchManipulationFormLayout_Positions->setWidget(5, QFormLayout::LabelRole, patchManipulateLabel_TranslateY);

        patchManipulateDSpinBox_TranslateY = new QDoubleSpinBox(formLayoutWidget_14);
        patchManipulateDSpinBox_TranslateY->setObjectName(QString::fromUtf8("patchManipulateDSpinBox_TranslateY"));
        patchManipulateDSpinBox_TranslateY->setMinimum(-100.000000000000000);
        patchManipulateDSpinBox_TranslateY->setMaximum(100.000000000000000);
        patchManipulateDSpinBox_TranslateY->setSingleStep(0.100000000000000);
        patchManipulateDSpinBox_TranslateY->setStepType(QAbstractSpinBox::DefaultStepType);

        patchManipulationFormLayout_Positions->setWidget(5, QFormLayout::FieldRole, patchManipulateDSpinBox_TranslateY);

        patchManipulateLabel_TranslateZ = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_TranslateZ->setObjectName(QString::fromUtf8("patchManipulateLabel_TranslateZ"));

        patchManipulationFormLayout_Positions->setWidget(6, QFormLayout::LabelRole, patchManipulateLabel_TranslateZ);

        patchManipulateDSpinBox_TranslateZ = new QDoubleSpinBox(formLayoutWidget_14);
        patchManipulateDSpinBox_TranslateZ->setObjectName(QString::fromUtf8("patchManipulateDSpinBox_TranslateZ"));
        patchManipulateDSpinBox_TranslateZ->setMinimum(-100.000000000000000);
        patchManipulateDSpinBox_TranslateZ->setMaximum(100.000000000000000);
        patchManipulateDSpinBox_TranslateZ->setSingleStep(0.100000000000000);
        patchManipulateDSpinBox_TranslateZ->setValue(0.000000000000000);

        patchManipulationFormLayout_Positions->setWidget(6, QFormLayout::FieldRole, patchManipulateDSpinBox_TranslateZ);

        patchManipulateISpinBox_Material = new QSpinBox(formLayoutWidget_14);
        patchManipulateISpinBox_Material->setObjectName(QString::fromUtf8("patchManipulateISpinBox_Material"));

        patchManipulationFormLayout_Positions->setWidget(7, QFormLayout::FieldRole, patchManipulateISpinBox_Material);

        patchManipulateLabel_Material = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_Material->setObjectName(QString::fromUtf8("patchManipulateLabel_Material"));

        patchManipulationFormLayout_Positions->setWidget(7, QFormLayout::LabelRole, patchManipulateLabel_Material);

        patchManipulateISpinBox_Texture = new QSpinBox(formLayoutWidget_14);
        patchManipulateISpinBox_Texture->setObjectName(QString::fromUtf8("patchManipulateISpinBox_Texture"));

        patchManipulationFormLayout_Positions->setWidget(8, QFormLayout::FieldRole, patchManipulateISpinBox_Texture);

        patchManipulateLabel_Texture = new QLabel(formLayoutWidget_14);
        patchManipulateLabel_Texture->setObjectName(QString::fromUtf8("patchManipulateLabel_Texture"));

        patchManipulationFormLayout_Positions->setWidget(8, QFormLayout::LabelRole, patchManipulateLabel_Texture);

        patchManipulateCheckBox_DoTexture = new QCheckBox(formLayoutWidget_14);
        patchManipulateCheckBox_DoTexture->setObjectName(QString::fromUtf8("patchManipulateCheckBox_DoTexture"));

        patchManipulationFormLayout_Positions->setWidget(9, QFormLayout::LabelRole, patchManipulateCheckBox_DoTexture);

        formLayoutWidget_17 = new QWidget(patchManipulation);
        formLayoutWidget_17->setObjectName(QString::fromUtf8("formLayoutWidget_17"));
        formLayoutWidget_17->setGeometry(QRect(10, 0, 271, 94));
        patchManipulationFormLayout_CheckBoxes = new QFormLayout(formLayoutWidget_17);
        patchManipulationFormLayout_CheckBoxes->setObjectName(QString::fromUtf8("patchManipulationFormLayout_CheckBoxes"));
        patchManipulationFormLayout_CheckBoxes->setContentsMargins(0, 0, 0, 0);
        patchManipulationCheckBox_FirstOrder = new QCheckBox(formLayoutWidget_17);
        patchManipulationCheckBox_FirstOrder->setObjectName(QString::fromUtf8("patchManipulationCheckBox_FirstOrder"));

        patchManipulationFormLayout_CheckBoxes->setWidget(1, QFormLayout::LabelRole, patchManipulationCheckBox_FirstOrder);

        patchManipulationCheckBox_SecondOrder = new QCheckBox(formLayoutWidget_17);
        patchManipulationCheckBox_SecondOrder->setObjectName(QString::fromUtf8("patchManipulationCheckBox_SecondOrder"));

        patchManipulationFormLayout_CheckBoxes->setWidget(2, QFormLayout::LabelRole, patchManipulationCheckBox_SecondOrder);

        patchManipulationCheckBox_NormalVector = new QCheckBox(formLayoutWidget_17);
        patchManipulationCheckBox_NormalVector->setObjectName(QString::fromUtf8("patchManipulationCheckBox_NormalVector"));

        patchManipulationFormLayout_CheckBoxes->setWidget(0, QFormLayout::LabelRole, patchManipulationCheckBox_NormalVector);

        formLayoutWidget_18 = new QWidget(patchManipulation);
        formLayoutWidget_18->setObjectName(QString::fromUtf8("formLayoutWidget_18"));
        formLayoutWidget_18->setGeometry(QRect(9, 90, 271, 41));
        patchManipulationFormLayout_SelectPatch = new QFormLayout(formLayoutWidget_18);
        patchManipulationFormLayout_SelectPatch->setObjectName(QString::fromUtf8("patchManipulationFormLayout_SelectPatch"));
        patchManipulationFormLayout_SelectPatch->setContentsMargins(0, 0, 0, 0);
        patchManipulateISpinBox_SelectPatch = new QSpinBox(formLayoutWidget_18);
        patchManipulateISpinBox_SelectPatch->setObjectName(QString::fromUtf8("patchManipulateISpinBox_SelectPatch"));
        patchManipulateISpinBox_SelectPatch->setMinimum(0);
        patchManipulateISpinBox_SelectPatch->setMaximum(100);
        patchManipulateISpinBox_SelectPatch->setValue(0);

        patchManipulationFormLayout_SelectPatch->setWidget(0, QFormLayout::FieldRole, patchManipulateISpinBox_SelectPatch);

        patchManipulateLabel_SelectPatch = new QLabel(formLayoutWidget_18);
        patchManipulateLabel_SelectPatch->setObjectName(QString::fromUtf8("patchManipulateLabel_SelectPatch"));

        patchManipulationFormLayout_SelectPatch->setWidget(0, QFormLayout::LabelRole, patchManipulateLabel_SelectPatch);

        formLayoutWidget_19 = new QWidget(patchManipulation);
        formLayoutWidget_19->setObjectName(QString::fromUtf8("formLayoutWidget_19"));
        formLayoutWidget_19->setGeometry(QRect(9, 130, 121, 51));
        patchManipulationFormLayoutSelectRow = new QFormLayout(formLayoutWidget_19);
        patchManipulationFormLayoutSelectRow->setObjectName(QString::fromUtf8("patchManipulationFormLayoutSelectRow"));
        patchManipulationFormLayoutSelectRow->setContentsMargins(0, 0, 0, 0);
        patchManipulateLabel_SelectRow = new QLabel(formLayoutWidget_19);
        patchManipulateLabel_SelectRow->setObjectName(QString::fromUtf8("patchManipulateLabel_SelectRow"));

        patchManipulationFormLayoutSelectRow->setWidget(0, QFormLayout::LabelRole, patchManipulateLabel_SelectRow);

        patchManipulateISpinBox_SelectRow = new QSpinBox(formLayoutWidget_19);
        patchManipulateISpinBox_SelectRow->setObjectName(QString::fromUtf8("patchManipulateISpinBox_SelectRow"));
        patchManipulateISpinBox_SelectRow->setMinimum(0);
        patchManipulateISpinBox_SelectRow->setMaximum(100);
        patchManipulateISpinBox_SelectRow->setValue(0);

        patchManipulationFormLayoutSelectRow->setWidget(0, QFormLayout::FieldRole, patchManipulateISpinBox_SelectRow);

        formLayoutWidget_20 = new QWidget(patchManipulation);
        formLayoutWidget_20->setObjectName(QString::fromUtf8("formLayoutWidget_20"));
        formLayoutWidget_20->setGeometry(QRect(140, 130, 141, 51));
        patchManipulationFormLayout_SelectColumn = new QFormLayout(formLayoutWidget_20);
        patchManipulationFormLayout_SelectColumn->setObjectName(QString::fromUtf8("patchManipulationFormLayout_SelectColumn"));
        patchManipulationFormLayout_SelectColumn->setContentsMargins(0, 0, 0, 0);
        patchManipulateLabel_SelectColumn = new QLabel(formLayoutWidget_20);
        patchManipulateLabel_SelectColumn->setObjectName(QString::fromUtf8("patchManipulateLabel_SelectColumn"));

        patchManipulationFormLayout_SelectColumn->setWidget(0, QFormLayout::LabelRole, patchManipulateLabel_SelectColumn);

        patchManipulateISpinBox_SelectColumn = new QSpinBox(formLayoutWidget_20);
        patchManipulateISpinBox_SelectColumn->setObjectName(QString::fromUtf8("patchManipulateISpinBox_SelectColumn"));
        patchManipulateISpinBox_SelectColumn->setEnabled(true);
        patchManipulateISpinBox_SelectColumn->setMinimum(0);
        patchManipulateISpinBox_SelectColumn->setMaximum(100);
        patchManipulateISpinBox_SelectColumn->setValue(0);

        patchManipulationFormLayout_SelectColumn->setWidget(0, QFormLayout::FieldRole, patchManipulateISpinBox_SelectColumn);

        patchToolBox->addItem(patchManipulation, QString::fromUtf8("Manipulate SOT Patch"));
        formLayoutWidget_14->raise();
        formLayoutWidget_17->raise();
        patchDeleteButton->raise();
        formLayoutWidget_18->raise();
        formLayoutWidget_19->raise();
        formLayoutWidget_20->raise();
        patchInteraction = new QWidget();
        patchInteraction->setObjectName(QString::fromUtf8("patchInteraction"));
        patchInteraction->setGeometry(QRect(0, 0, 291, 501));
        patchContinueButton = new QToolButton(patchInteraction);
        patchContinueButton->setObjectName(QString::fromUtf8("patchContinueButton"));
        patchContinueButton->setGeometry(QRect(70, 20, 131, 51));
        patchMergeButton = new QToolButton(patchInteraction);
        patchMergeButton->setObjectName(QString::fromUtf8("patchMergeButton"));
        patchMergeButton->setGeometry(QRect(70, 160, 131, 51));
        patchJoinButton = new QToolButton(patchInteraction);
        patchJoinButton->setObjectName(QString::fromUtf8("patchJoinButton"));
        patchJoinButton->setGeometry(QRect(70, 90, 131, 51));
        patchToolBox->addItem(patchInteraction, QString::fromUtf8("Interactions With SOT Patches"));
        page_tabs->addTab(tabPatch, QString());
#if QT_CONFIG(shortcut)
        label->setBuddy(rotate_x_slider);
        label_2->setBuddy(rotate_y_slider);
        label_3->setBuddy(rotate_z_slider);
        label_4->setBuddy(zoom_factor_spin_box);
        label_5->setBuddy(trans_x_spin_box);
        label_6->setBuddy(trans_y_spin_box);
        label_7->setBuddy(trans_z_spin_box);
#endif // QT_CONFIG(shortcut)

        retranslateUi(SideWidget);

        page_tabs->setCurrentIndex(0);
        arcToolBox->setCurrentIndex(0);
        patchToolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SideWidget);
    } // setupUi

    void retranslateUi(QWidget *SideWidget)
    {
        SideWidget->setWindowTitle(QCoreApplication::translate("SideWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SideWidget", "Transformations", nullptr));
        label->setText(QCoreApplication::translate("SideWidget", "Rotate around x", nullptr));
        label_2->setText(QCoreApplication::translate("SideWidget", "Rotate around y", nullptr));
        label_3->setText(QCoreApplication::translate("SideWidget", "Rotate around z", nullptr));
        label_4->setText(QCoreApplication::translate("SideWidget", "Zoom factor", nullptr));
#if QT_CONFIG(tooltip)
        zoom_factor_spin_box->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("SideWidget", "Translate along x", nullptr));
        label_6->setText(QCoreApplication::translate("SideWidget", "Translate along y", nullptr));
        label_7->setText(QCoreApplication::translate("SideWidget", "Translate along z", nullptr));
        doShader->setText(QCoreApplication::translate("SideWidget", "Shader", nullptr));
        shader_label_8->setText(QCoreApplication::translate("SideWidget", "Scale", nullptr));
        shader_label_9->setText(QCoreApplication::translate("SideWidget", "Smoothing", nullptr));
        shader_label_10->setText(QCoreApplication::translate("SideWidget", "Shading", nullptr));
        shader_label_11->setText(QCoreApplication::translate("SideWidget", "Intensity", nullptr));
        arcInsertButton->setText(QCoreApplication::translate("SideWidget", "Insert Arc", nullptr));
        arcInsertLabel_Alpha->setText(QCoreApplication::translate("SideWidget", "Alpha", nullptr));
        arcInsertLabel_Scale->setText(QCoreApplication::translate("SideWidget", "Scale", nullptr));
        arcInsertLabel_DivCount->setText(QCoreApplication::translate("SideWidget", "Div Count", nullptr));
        arcToolBox->setItemText(arcToolBox->indexOf(arcCreation), QCoreApplication::translate("SideWidget", "Create SOT Arc", nullptr));
        arcDeleteButton->setText(QCoreApplication::translate("SideWidget", "Delete Arc", nullptr));
        arcManipulateLabel_ControlPoint->setText(QCoreApplication::translate("SideWidget", "Control point", nullptr));
        arcManipulateLabel_X->setText(QCoreApplication::translate("SideWidget", "X", nullptr));
        arcManipulateLabel_Y->setText(QCoreApplication::translate("SideWidget", "Y", nullptr));
        arcManipulateLabel_Z->setText(QCoreApplication::translate("SideWidget", "Z", nullptr));
        arcManipulateLabel_SelectArc->setText(QCoreApplication::translate("SideWidget", "Selected Arc", nullptr));
        arcManipulateLabel_TranslateX->setText(QCoreApplication::translate("SideWidget", "Translate along x", nullptr));
        arcManipulateLabel_TranslateY->setText(QCoreApplication::translate("SideWidget", "Translate along y", nullptr));
        arcManipulateLabel_TranslateZ->setText(QCoreApplication::translate("SideWidget", "Translate along z", nullptr));
        arcManipulationCheckBox_FirstOrder->setText(QCoreApplication::translate("SideWidget", "Show First Order Derivatives", nullptr));
        arcManipulationCheckBox_SecondOrder->setText(QCoreApplication::translate("SideWidget", "Show Second Order Derivatives", nullptr));
        arcToolBox->setItemText(arcToolBox->indexOf(arcManipulation), QCoreApplication::translate("SideWidget", "Manipulate Arc", nullptr));
        arcContinueButton->setText(QCoreApplication::translate("SideWidget", "Continue Arc", nullptr));
        arcMergeButton->setText(QCoreApplication::translate("SideWidget", "Merge Arcs", nullptr));
        arcJoinButton->setText(QCoreApplication::translate("SideWidget", "Join Arcs", nullptr));
        arcToolBox->setItemText(arcToolBox->indexOf(arcInteraction), QCoreApplication::translate("SideWidget", "Interactions With SOT Arcs", nullptr));
        page_tabs->setTabText(page_tabs->indexOf(tabArc), QCoreApplication::translate("SideWidget", "Arc", nullptr));
        patchInsertButton->setText(QCoreApplication::translate("SideWidget", "Insert Patch", nullptr));
        patchInsertLabel_UAlpha->setText(QCoreApplication::translate("SideWidget", "U Alpha", nullptr));
        patchInsertLabel_VAlpha->setText(QCoreApplication::translate("SideWidget", "U Alpha", nullptr));
        patchInsertLabel_Scale->setText(QCoreApplication::translate("SideWidget", "Scale", nullptr));
        patchSaveButton->setText(QCoreApplication::translate("SideWidget", "Save Patch", nullptr));
        patchLoadButton->setText(QCoreApplication::translate("SideWidget", "Load Patch", nullptr));
        patchToolBox->setItemText(patchToolBox->indexOf(patchCreation), QCoreApplication::translate("SideWidget", "Create SOT Patch", nullptr));
        patchIsoparametricLabel_UDivCount->setText(QCoreApplication::translate("SideWidget", "U Div Count", nullptr));
        patchIsoparametricLabel_VDivCount->setText(QCoreApplication::translate("SideWidget", "V Div Count", nullptr));
        patchIsoparametricLabel_ULineCount->setText(QCoreApplication::translate("SideWidget", "U Line Count ", nullptr));
        patchIsoparametricLabel_VLineCount->setText(QCoreApplication::translate("SideWidget", "V Line Count", nullptr));
        patchToolBox->setItemText(patchToolBox->indexOf(patchIsoparametricLines), QCoreApplication::translate("SideWidget", "Isoparametric Lines", nullptr));
        patchDeleteButton->setText(QCoreApplication::translate("SideWidget", "Delete Patch", nullptr));
        patchManipulateLabel_X->setText(QCoreApplication::translate("SideWidget", "X", nullptr));
        patchManipulateLabel_Y->setText(QCoreApplication::translate("SideWidget", "Y", nullptr));
        patchManipulateLabel_Z->setText(QCoreApplication::translate("SideWidget", "Z", nullptr));
        patchManipulateLabel_TranlsateX->setText(QCoreApplication::translate("SideWidget", "Translate along x", nullptr));
        patchManipulateLabel_TranslateY->setText(QCoreApplication::translate("SideWidget", "Translate along y", nullptr));
        patchManipulateLabel_TranslateZ->setText(QCoreApplication::translate("SideWidget", "Translate along z", nullptr));
        patchManipulateLabel_Material->setText(QCoreApplication::translate("SideWidget", "Material", nullptr));
        patchManipulateLabel_Texture->setText(QCoreApplication::translate("SideWidget", "Texture", nullptr));
        patchManipulateCheckBox_DoTexture->setText(QCoreApplication::translate("SideWidget", "Use Texture", nullptr));
        patchManipulationCheckBox_FirstOrder->setText(QCoreApplication::translate("SideWidget", "Show First Order Derivatives", nullptr));
        patchManipulationCheckBox_SecondOrder->setText(QCoreApplication::translate("SideWidget", "Show Second Order Derivatives", nullptr));
        patchManipulationCheckBox_NormalVector->setText(QCoreApplication::translate("SideWidget", "Show Normal Vectors", nullptr));
        patchManipulateLabel_SelectPatch->setText(QCoreApplication::translate("SideWidget", "Select Patch", nullptr));
        patchManipulateLabel_SelectRow->setText(QCoreApplication::translate("SideWidget", "Row", nullptr));
        patchManipulateLabel_SelectColumn->setText(QCoreApplication::translate("SideWidget", "Column", nullptr));
        patchToolBox->setItemText(patchToolBox->indexOf(patchManipulation), QCoreApplication::translate("SideWidget", "Manipulate SOT Patch", nullptr));
        patchContinueButton->setText(QCoreApplication::translate("SideWidget", "Continue Patch", nullptr));
        patchMergeButton->setText(QCoreApplication::translate("SideWidget", "Merge Patches", nullptr));
        patchJoinButton->setText(QCoreApplication::translate("SideWidget", "JoinPatches", nullptr));
        patchToolBox->setItemText(patchToolBox->indexOf(patchInteraction), QCoreApplication::translate("SideWidget", "Interactions With SOT Patches", nullptr));
        page_tabs->setTabText(page_tabs->indexOf(tabPatch), QCoreApplication::translate("SideWidget", "Patch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
