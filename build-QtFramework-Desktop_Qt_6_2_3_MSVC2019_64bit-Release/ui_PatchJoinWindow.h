/********************************************************************************
** Form generated from reading UI file 'PatchJoinWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATCHJOINWINDOW_H
#define UI_PATCHJOINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatchJoinWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *patchJoinSecondPatchLayout;
    QLabel *patchJoinSecondPatchLabel;
    QSpinBox *patchJoinSecondPatchSpinBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *patchJoinSecondDirectionLayout;
    QLabel *patchJoinSecondDirectionLabel;
    QComboBox *patchJoinSecondDirectionComboBox;
    QLabel *patchJoinWindowLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *patchJoinFirstDirectionLayout;
    QLabel *patchJoinFirstDirectionLabel;
    QComboBox *patchJoinFirstDirectionComboBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *patchJoinFirstPatchLayout;
    QLabel *patchJoinFirstPatchLabel;
    QSpinBox *patchJoinFirstPatchSpinBox;

    void setupUi(QDialog *PatchJoinWindow)
    {
        if (PatchJoinWindow->objectName().isEmpty())
            PatchJoinWindow->setObjectName(QString::fromUtf8("PatchJoinWindow"));
        PatchJoinWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(PatchJoinWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget_2 = new QWidget(PatchJoinWindow);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 100, 361, 51));
        patchJoinSecondPatchLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        patchJoinSecondPatchLayout->setObjectName(QString::fromUtf8("patchJoinSecondPatchLayout"));
        patchJoinSecondPatchLayout->setContentsMargins(0, 0, 0, 0);
        patchJoinSecondPatchLabel = new QLabel(horizontalLayoutWidget_2);
        patchJoinSecondPatchLabel->setObjectName(QString::fromUtf8("patchJoinSecondPatchLabel"));

        patchJoinSecondPatchLayout->addWidget(patchJoinSecondPatchLabel);

        patchJoinSecondPatchSpinBox = new QSpinBox(horizontalLayoutWidget_2);
        patchJoinSecondPatchSpinBox->setObjectName(QString::fromUtf8("patchJoinSecondPatchSpinBox"));
        patchJoinSecondPatchSpinBox->setMaximum(3);

        patchJoinSecondPatchLayout->addWidget(patchJoinSecondPatchSpinBox);

        verticalLayoutWidget_2 = new QWidget(PatchJoinWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(209, 150, 171, 80));
        patchJoinSecondDirectionLayout = new QVBoxLayout(verticalLayoutWidget_2);
        patchJoinSecondDirectionLayout->setObjectName(QString::fromUtf8("patchJoinSecondDirectionLayout"));
        patchJoinSecondDirectionLayout->setContentsMargins(0, 0, 0, 0);
        patchJoinSecondDirectionLabel = new QLabel(verticalLayoutWidget_2);
        patchJoinSecondDirectionLabel->setObjectName(QString::fromUtf8("patchJoinSecondDirectionLabel"));
        patchJoinSecondDirectionLabel->setAlignment(Qt::AlignCenter);

        patchJoinSecondDirectionLayout->addWidget(patchJoinSecondDirectionLabel);

        patchJoinSecondDirectionComboBox = new QComboBox(verticalLayoutWidget_2);
        patchJoinSecondDirectionComboBox->setObjectName(QString::fromUtf8("patchJoinSecondDirectionComboBox"));

        patchJoinSecondDirectionLayout->addWidget(patchJoinSecondDirectionComboBox);

        patchJoinWindowLabel = new QLabel(PatchJoinWindow);
        patchJoinWindowLabel->setObjectName(QString::fromUtf8("patchJoinWindowLabel"));
        patchJoinWindowLabel->setGeometry(QRect(22, 0, 361, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        patchJoinWindowLabel->setFont(font);
        patchJoinWindowLabel->setAcceptDrops(false);
        patchJoinWindowLabel->setTextFormat(Qt::AutoText);
        patchJoinWindowLabel->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(PatchJoinWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 150, 171, 80));
        patchJoinFirstDirectionLayout = new QVBoxLayout(verticalLayoutWidget);
        patchJoinFirstDirectionLayout->setObjectName(QString::fromUtf8("patchJoinFirstDirectionLayout"));
        patchJoinFirstDirectionLayout->setContentsMargins(0, 0, 0, 0);
        patchJoinFirstDirectionLabel = new QLabel(verticalLayoutWidget);
        patchJoinFirstDirectionLabel->setObjectName(QString::fromUtf8("patchJoinFirstDirectionLabel"));
        patchJoinFirstDirectionLabel->setAlignment(Qt::AlignCenter);

        patchJoinFirstDirectionLayout->addWidget(patchJoinFirstDirectionLabel);

        patchJoinFirstDirectionComboBox = new QComboBox(verticalLayoutWidget);
        patchJoinFirstDirectionComboBox->setObjectName(QString::fromUtf8("patchJoinFirstDirectionComboBox"));

        patchJoinFirstDirectionLayout->addWidget(patchJoinFirstDirectionComboBox);

        horizontalLayoutWidget = new QWidget(PatchJoinWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 50, 361, 51));
        patchJoinFirstPatchLayout = new QHBoxLayout(horizontalLayoutWidget);
        patchJoinFirstPatchLayout->setObjectName(QString::fromUtf8("patchJoinFirstPatchLayout"));
        patchJoinFirstPatchLayout->setContentsMargins(0, 0, 0, 0);
        patchJoinFirstPatchLabel = new QLabel(horizontalLayoutWidget);
        patchJoinFirstPatchLabel->setObjectName(QString::fromUtf8("patchJoinFirstPatchLabel"));

        patchJoinFirstPatchLayout->addWidget(patchJoinFirstPatchLabel);

        patchJoinFirstPatchSpinBox = new QSpinBox(horizontalLayoutWidget);
        patchJoinFirstPatchSpinBox->setObjectName(QString::fromUtf8("patchJoinFirstPatchSpinBox"));
        patchJoinFirstPatchSpinBox->setMaximum(3);

        patchJoinFirstPatchLayout->addWidget(patchJoinFirstPatchSpinBox);


        retranslateUi(PatchJoinWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PatchJoinWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PatchJoinWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PatchJoinWindow);
    } // setupUi

    void retranslateUi(QDialog *PatchJoinWindow)
    {
        PatchJoinWindow->setWindowTitle(QCoreApplication::translate("PatchJoinWindow", "Dialog", nullptr));
        patchJoinSecondPatchLabel->setText(QCoreApplication::translate("PatchJoinWindow", "Second patch index", nullptr));
        patchJoinSecondDirectionLabel->setText(QCoreApplication::translate("PatchJoinWindow", "Second direction", nullptr));
        patchJoinSecondDirectionComboBox->setCurrentText(QString());
        patchJoinWindowLabel->setText(QCoreApplication::translate("PatchJoinWindow", "Join two patches together", nullptr));
        patchJoinFirstDirectionLabel->setText(QCoreApplication::translate("PatchJoinWindow", "First direction", nullptr));
        patchJoinFirstDirectionComboBox->setCurrentText(QString());
        patchJoinFirstPatchLabel->setText(QCoreApplication::translate("PatchJoinWindow", "First patch index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatchJoinWindow: public Ui_PatchJoinWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATCHJOINWINDOW_H
