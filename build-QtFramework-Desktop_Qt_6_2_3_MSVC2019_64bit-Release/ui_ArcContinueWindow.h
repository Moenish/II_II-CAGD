/********************************************************************************
** Form generated from reading UI file 'ArcContinueWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCCONTINUEWINDOW_H
#define UI_ARCCONTINUEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArcContinueWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *arcContinueWindowLabel;
    QWidget *formLayoutWidget;
    QFormLayout *arcContinueLayout;
    QComboBox *arcContinueDirectionComboBox;
    QLabel *arcContinueDirectionLabel;
    QSpinBox *arcContinueIndexSpinBox;
    QLabel *arcContinueIndexLabel;

    void setupUi(QDialog *ArcContinueWindow)
    {
        if (ArcContinueWindow->objectName().isEmpty())
            ArcContinueWindow->setObjectName(QString::fromUtf8("ArcContinueWindow"));
        ArcContinueWindow->resize(400, 179);
        buttonBox = new QDialogButtonBox(ArcContinueWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        arcContinueWindowLabel = new QLabel(ArcContinueWindow);
        arcContinueWindowLabel->setObjectName(QString::fromUtf8("arcContinueWindowLabel"));
        arcContinueWindowLabel->setGeometry(QRect(22, 20, 361, 20));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        arcContinueWindowLabel->setFont(font);
        arcContinueWindowLabel->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(ArcContinueWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(19, 59, 361, 71));
        arcContinueLayout = new QFormLayout(formLayoutWidget);
        arcContinueLayout->setObjectName(QString::fromUtf8("arcContinueLayout"));
        arcContinueLayout->setContentsMargins(0, 0, 0, 0);
        arcContinueDirectionComboBox = new QComboBox(formLayoutWidget);
        arcContinueDirectionComboBox->addItem(QString());
        arcContinueDirectionComboBox->addItem(QString());
        arcContinueDirectionComboBox->setObjectName(QString::fromUtf8("arcContinueDirectionComboBox"));

        arcContinueLayout->setWidget(1, QFormLayout::FieldRole, arcContinueDirectionComboBox);

        arcContinueDirectionLabel = new QLabel(formLayoutWidget);
        arcContinueDirectionLabel->setObjectName(QString::fromUtf8("arcContinueDirectionLabel"));

        arcContinueLayout->setWidget(1, QFormLayout::LabelRole, arcContinueDirectionLabel);

        arcContinueIndexSpinBox = new QSpinBox(formLayoutWidget);
        arcContinueIndexSpinBox->setObjectName(QString::fromUtf8("arcContinueIndexSpinBox"));
        arcContinueIndexSpinBox->setMaximum(1000);

        arcContinueLayout->setWidget(0, QFormLayout::FieldRole, arcContinueIndexSpinBox);

        arcContinueIndexLabel = new QLabel(formLayoutWidget);
        arcContinueIndexLabel->setObjectName(QString::fromUtf8("arcContinueIndexLabel"));

        arcContinueLayout->setWidget(0, QFormLayout::LabelRole, arcContinueIndexLabel);


        retranslateUi(ArcContinueWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ArcContinueWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ArcContinueWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ArcContinueWindow);
    } // setupUi

    void retranslateUi(QDialog *ArcContinueWindow)
    {
        ArcContinueWindow->setWindowTitle(QCoreApplication::translate("ArcContinueWindow", "Dialog", nullptr));
        arcContinueWindowLabel->setText(QCoreApplication::translate("ArcContinueWindow", "Continue arc", nullptr));
        arcContinueDirectionComboBox->setItemText(0, QCoreApplication::translate("ArcContinueWindow", "LEFT (RED)", nullptr));
        arcContinueDirectionComboBox->setItemText(1, QCoreApplication::translate("ArcContinueWindow", "RIGHT (GREEN)", nullptr));

        arcContinueDirectionLabel->setText(QCoreApplication::translate("ArcContinueWindow", "Direction", nullptr));
        arcContinueIndexLabel->setText(QCoreApplication::translate("ArcContinueWindow", "Arc index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArcContinueWindow: public Ui_ArcContinueWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCCONTINUEWINDOW_H
