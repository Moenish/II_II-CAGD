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
#include <QtWidgets/QComboBox>
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
    QTabWidget *page_tabs;
    QWidget *parametric_curve_page;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QComboBox *pc_curveSelector;
    QLabel *pc_label_10;
    QDoubleSpinBox *pc_derivativeScale;
    QLabel *pc_label_9;
    QSpinBox *pc_divPointsCount;
    QCheckBox *pc_doZerothDerivative;
    QCheckBox *pc_doFirstDerivative;
    QCheckBox *pc_doSecondDerivative;
    QLabel *pc_label_8;
    QWidget *race_page;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *race_label_11;
    QLabel *race_label_12;
    QSpinBox *race_controlPoint;
    QLabel *race_label_moveX;
    QLabel *race_label_moveY;
    QLabel *race_label_moveZ;
    QDoubleSpinBox *race_moveX;
    QDoubleSpinBox *race_moveY;
    QDoubleSpinBox *race_moveZ;
    QSpinBox *race_pathSelector;
    QDoubleSpinBox *race_edit_e;
    QLabel *race_edit_e_label;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QString::fromUtf8("SideWidget"));
        SideWidget->resize(334, 566);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 331, 561));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 21, 321, 231));
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

        page_tabs = new QTabWidget(groupBox);
        page_tabs->setObjectName(QString::fromUtf8("page_tabs"));
        page_tabs->setGeometry(QRect(10, 250, 311, 301));
        parametric_curve_page = new QWidget();
        parametric_curve_page->setObjectName(QString::fromUtf8("parametric_curve_page"));
        formLayoutWidget = new QWidget(parametric_curve_page);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 291, 241));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setVerticalSpacing(7);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        pc_curveSelector = new QComboBox(formLayoutWidget);
        pc_curveSelector->setObjectName(QString::fromUtf8("pc_curveSelector"));
        pc_curveSelector->setMaxCount(10);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pc_curveSelector);

        pc_label_10 = new QLabel(formLayoutWidget);
        pc_label_10->setObjectName(QString::fromUtf8("pc_label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pc_label_10);

        pc_derivativeScale = new QDoubleSpinBox(formLayoutWidget);
        pc_derivativeScale->setObjectName(QString::fromUtf8("pc_derivativeScale"));
        pc_derivativeScale->setDecimals(2);
        pc_derivativeScale->setMinimum(0.000000000000000);
        pc_derivativeScale->setMaximum(100.000000000000000);
        pc_derivativeScale->setSingleStep(0.010000000000000);
        pc_derivativeScale->setValue(1.000000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pc_derivativeScale);

        pc_label_9 = new QLabel(formLayoutWidget);
        pc_label_9->setObjectName(QString::fromUtf8("pc_label_9"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pc_label_9);

        pc_divPointsCount = new QSpinBox(formLayoutWidget);
        pc_divPointsCount->setObjectName(QString::fromUtf8("pc_divPointsCount"));
        pc_divPointsCount->setMinimum(1);
        pc_divPointsCount->setMaximum(100000);
        pc_divPointsCount->setValue(200);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pc_divPointsCount);

        pc_doZerothDerivative = new QCheckBox(formLayoutWidget);
        pc_doZerothDerivative->setObjectName(QString::fromUtf8("pc_doZerothDerivative"));
        pc_doZerothDerivative->setChecked(true);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, pc_doZerothDerivative);

        pc_doFirstDerivative = new QCheckBox(formLayoutWidget);
        pc_doFirstDerivative->setObjectName(QString::fromUtf8("pc_doFirstDerivative"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, pc_doFirstDerivative);

        pc_doSecondDerivative = new QCheckBox(formLayoutWidget);
        pc_doSecondDerivative->setObjectName(QString::fromUtf8("pc_doSecondDerivative"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, pc_doSecondDerivative);

        pc_label_8 = new QLabel(formLayoutWidget);
        pc_label_8->setObjectName(QString::fromUtf8("pc_label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pc_label_8);

        page_tabs->addTab(parametric_curve_page, QString());
        race_page = new QWidget();
        race_page->setObjectName(QString::fromUtf8("race_page"));
        formLayoutWidget_2 = new QWidget(race_page);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(9, 9, 291, 211));
        formLayout_3 = new QFormLayout(formLayoutWidget_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        race_label_11 = new QLabel(formLayoutWidget_2);
        race_label_11->setObjectName(QString::fromUtf8("race_label_11"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, race_label_11);

        race_label_12 = new QLabel(formLayoutWidget_2);
        race_label_12->setObjectName(QString::fromUtf8("race_label_12"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, race_label_12);

        race_controlPoint = new QSpinBox(formLayoutWidget_2);
        race_controlPoint->setObjectName(QString::fromUtf8("race_controlPoint"));
        race_controlPoint->setMaximum(4);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, race_controlPoint);

        race_label_moveX = new QLabel(formLayoutWidget_2);
        race_label_moveX->setObjectName(QString::fromUtf8("race_label_moveX"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, race_label_moveX);

        race_label_moveY = new QLabel(formLayoutWidget_2);
        race_label_moveY->setObjectName(QString::fromUtf8("race_label_moveY"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, race_label_moveY);

        race_label_moveZ = new QLabel(formLayoutWidget_2);
        race_label_moveZ->setObjectName(QString::fromUtf8("race_label_moveZ"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, race_label_moveZ);

        race_moveX = new QDoubleSpinBox(formLayoutWidget_2);
        race_moveX->setObjectName(QString::fromUtf8("race_moveX"));
        race_moveX->setMinimum(-100.000000000000000);
        race_moveX->setMaximum(100.000000000000000);
        race_moveX->setSingleStep(0.010000000000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, race_moveX);

        race_moveY = new QDoubleSpinBox(formLayoutWidget_2);
        race_moveY->setObjectName(QString::fromUtf8("race_moveY"));
        race_moveY->setMinimum(-100.000000000000000);
        race_moveY->setMaximum(100.000000000000000);
        race_moveY->setSingleStep(0.010000000000000);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, race_moveY);

        race_moveZ = new QDoubleSpinBox(formLayoutWidget_2);
        race_moveZ->setObjectName(QString::fromUtf8("race_moveZ"));
        race_moveZ->setMinimum(-100.000000000000000);
        race_moveZ->setMaximum(100.000000000000000);
        race_moveZ->setSingleStep(0.010000000000000);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, race_moveZ);

        race_pathSelector = new QSpinBox(formLayoutWidget_2);
        race_pathSelector->setObjectName(QString::fromUtf8("race_pathSelector"));
        race_pathSelector->setMaximum(3);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, race_pathSelector);

        race_edit_e = new QDoubleSpinBox(formLayoutWidget_2);
        race_edit_e->setObjectName(QString::fromUtf8("race_edit_e"));
        race_edit_e->setMinimum(0.000000000000000);
        race_edit_e->setMaximum(10.000000000000000);
        race_edit_e->setSingleStep(0.010000000000000);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, race_edit_e);

        race_edit_e_label = new QLabel(formLayoutWidget_2);
        race_edit_e_label->setObjectName(QString::fromUtf8("race_edit_e_label"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, race_edit_e_label);

        page_tabs->addTab(race_page, QString());
#if QT_CONFIG(shortcut)
        label->setBuddy(rotate_x_slider);
        label_2->setBuddy(rotate_y_slider);
        label_3->setBuddy(rotate_z_slider);
        label_4->setBuddy(zoom_factor_spin_box);
        label_5->setBuddy(trans_x_spin_box);
        label_6->setBuddy(trans_y_spin_box);
        label_7->setBuddy(trans_z_spin_box);
        pc_label_10->setBuddy(trans_z_spin_box);
        pc_label_9->setBuddy(trans_z_spin_box);
        pc_label_8->setBuddy(trans_z_spin_box);
        race_label_11->setBuddy(trans_z_spin_box);
        race_label_12->setBuddy(trans_z_spin_box);
        race_label_moveX->setBuddy(trans_z_spin_box);
        race_label_moveY->setBuddy(trans_z_spin_box);
        race_label_moveZ->setBuddy(trans_z_spin_box);
        race_edit_e_label->setBuddy(trans_z_spin_box);
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
        pc_label_10->setText(QCoreApplication::translate("SideWidget", "Derivative scale", nullptr));
#if QT_CONFIG(tooltip)
        pc_derivativeScale->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pc_label_9->setText(QCoreApplication::translate("SideWidget", "Division points", nullptr));
        pc_doZerothDerivative->setText(QCoreApplication::translate("SideWidget", "Zeroth Derivative", nullptr));
        pc_doFirstDerivative->setText(QCoreApplication::translate("SideWidget", "First Derivative", nullptr));
        pc_doSecondDerivative->setText(QCoreApplication::translate("SideWidget", "Second Derivative", nullptr));
        pc_label_8->setText(QCoreApplication::translate("SideWidget", "Selected curve", nullptr));
        page_tabs->setTabText(page_tabs->indexOf(parametric_curve_page), QCoreApplication::translate("SideWidget", "Parametric Curves", nullptr));
        race_label_11->setText(QCoreApplication::translate("SideWidget", "Selected path", nullptr));
        race_label_12->setText(QCoreApplication::translate("SideWidget", "Selected control point", nullptr));
        race_label_moveX->setText(QCoreApplication::translate("SideWidget", "Move X", nullptr));
        race_label_moveY->setText(QCoreApplication::translate("SideWidget", "Move Y", nullptr));
        race_label_moveZ->setText(QCoreApplication::translate("SideWidget", "Move Z", nullptr));
        race_edit_e_label->setText(QCoreApplication::translate("SideWidget", "E", nullptr));
        page_tabs->setTabText(page_tabs->indexOf(race_page), QCoreApplication::translate("SideWidget", "3D Race", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
