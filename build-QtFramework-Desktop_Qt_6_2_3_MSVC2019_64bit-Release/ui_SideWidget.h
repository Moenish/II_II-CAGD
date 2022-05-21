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
    QWidget *tab_arc;
    QWidget *tab_patch;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QString::fromUtf8("SideWidget"));
        SideWidget->resize(334, 881);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 331, 871));
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
        page_tabs->setGeometry(QRect(0, 420, 321, 441));
        tab_arc = new QWidget();
        tab_arc->setObjectName(QString::fromUtf8("tab_arc"));
        page_tabs->addTab(tab_arc, QString());
        tab_patch = new QWidget();
        tab_patch->setObjectName(QString::fromUtf8("tab_patch"));
        page_tabs->addTab(tab_patch, QString());
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
        page_tabs->setTabText(page_tabs->indexOf(tab_arc), QCoreApplication::translate("SideWidget", "Arc", nullptr));
        page_tabs->setTabText(page_tabs->indexOf(tab_patch), QCoreApplication::translate("SideWidget", "Patch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
