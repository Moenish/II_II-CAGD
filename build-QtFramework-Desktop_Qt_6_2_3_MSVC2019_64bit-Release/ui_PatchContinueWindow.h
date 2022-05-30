/********************************************************************************
** Form generated from reading UI file 'PatchContinueWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATCHCONTINUEWINDOW_H
#define UI_PATCHCONTINUEWINDOW_H

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

class Ui_PatchContinueWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *patchContinueLayout;
    QComboBox *patchContinueDirectionComboBox;
    QLabel *patchContinueDirectionLabel;
    QSpinBox *patchContinueIndexSpinBox;
    QLabel *patchContinueIndexLabel;
    QLabel *patchContinueWindowLabel;

    void setupUi(QDialog *PatchContinueWindow)
    {
        if (PatchContinueWindow->objectName().isEmpty())
            PatchContinueWindow->setObjectName(QString::fromUtf8("PatchContinueWindow"));
        PatchContinueWindow->resize(400, 160);
        buttonBox = new QDialogButtonBox(PatchContinueWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(PatchContinueWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(17, 39, 361, 71));
        patchContinueLayout = new QFormLayout(formLayoutWidget);
        patchContinueLayout->setObjectName(QString::fromUtf8("patchContinueLayout"));
        patchContinueLayout->setContentsMargins(0, 0, 0, 0);
        patchContinueDirectionComboBox = new QComboBox(formLayoutWidget);
        patchContinueDirectionComboBox->setObjectName(QString::fromUtf8("patchContinueDirectionComboBox"));

        patchContinueLayout->setWidget(1, QFormLayout::FieldRole, patchContinueDirectionComboBox);

        patchContinueDirectionLabel = new QLabel(formLayoutWidget);
        patchContinueDirectionLabel->setObjectName(QString::fromUtf8("patchContinueDirectionLabel"));

        patchContinueLayout->setWidget(1, QFormLayout::LabelRole, patchContinueDirectionLabel);

        patchContinueIndexSpinBox = new QSpinBox(formLayoutWidget);
        patchContinueIndexSpinBox->setObjectName(QString::fromUtf8("patchContinueIndexSpinBox"));
        patchContinueIndexSpinBox->setMaximum(3);

        patchContinueLayout->setWidget(0, QFormLayout::FieldRole, patchContinueIndexSpinBox);

        patchContinueIndexLabel = new QLabel(formLayoutWidget);
        patchContinueIndexLabel->setObjectName(QString::fromUtf8("patchContinueIndexLabel"));

        patchContinueLayout->setWidget(0, QFormLayout::LabelRole, patchContinueIndexLabel);

        patchContinueWindowLabel = new QLabel(PatchContinueWindow);
        patchContinueWindowLabel->setObjectName(QString::fromUtf8("patchContinueWindowLabel"));
        patchContinueWindowLabel->setGeometry(QRect(20, 0, 361, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        patchContinueWindowLabel->setFont(font);
        patchContinueWindowLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(PatchContinueWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PatchContinueWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PatchContinueWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PatchContinueWindow);
    } // setupUi

    void retranslateUi(QDialog *PatchContinueWindow)
    {
        PatchContinueWindow->setWindowTitle(QCoreApplication::translate("PatchContinueWindow", "Dialog", nullptr));
        patchContinueDirectionLabel->setText(QCoreApplication::translate("PatchContinueWindow", "Direction", nullptr));
        patchContinueIndexLabel->setText(QCoreApplication::translate("PatchContinueWindow", "Patch index", nullptr));
        patchContinueWindowLabel->setText(QCoreApplication::translate("PatchContinueWindow", "Continue patch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatchContinueWindow: public Ui_PatchContinueWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATCHCONTINUEWINDOW_H
