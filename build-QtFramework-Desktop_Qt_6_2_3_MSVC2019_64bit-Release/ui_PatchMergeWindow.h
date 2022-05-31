/********************************************************************************
** Form generated from reading UI file 'PatchMergeWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATCHMERGEWINDOW_H
#define UI_PATCHMERGEWINDOW_H

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

class Ui_PatchMergeWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *patchMergeSecondPatchLayout;
    QLabel *patchMergeSecondPatchLabel;
    QSpinBox *patchMergeSecondPatchSpinBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *patchMergeSecondDirectionLayout;
    QLabel *patchMergeSecondDirectionLabel;
    QComboBox *patchMergeSecondDirectionComboBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *patchMergeFirstDirectionLayout;
    QLabel *patchMergeFirstDirectionLabel;
    QComboBox *patchMergeFirstDirectionComboBox;
    QLabel *patchMergeWindowLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *patchMergeFirstPatchLayout;
    QLabel *patchMergeFirstPatchLabel;
    QSpinBox *patchMergeFirstPatchSpinBox;

    void setupUi(QDialog *PatchMergeWindow)
    {
        if (PatchMergeWindow->objectName().isEmpty())
            PatchMergeWindow->setObjectName(QString::fromUtf8("PatchMergeWindow"));
        PatchMergeWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(PatchMergeWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget_2 = new QWidget(PatchMergeWindow);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 100, 361, 51));
        patchMergeSecondPatchLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        patchMergeSecondPatchLayout->setObjectName(QString::fromUtf8("patchMergeSecondPatchLayout"));
        patchMergeSecondPatchLayout->setContentsMargins(0, 0, 0, 0);
        patchMergeSecondPatchLabel = new QLabel(horizontalLayoutWidget_2);
        patchMergeSecondPatchLabel->setObjectName(QString::fromUtf8("patchMergeSecondPatchLabel"));

        patchMergeSecondPatchLayout->addWidget(patchMergeSecondPatchLabel);

        patchMergeSecondPatchSpinBox = new QSpinBox(horizontalLayoutWidget_2);
        patchMergeSecondPatchSpinBox->setObjectName(QString::fromUtf8("patchMergeSecondPatchSpinBox"));
        patchMergeSecondPatchSpinBox->setMaximum(3);

        patchMergeSecondPatchLayout->addWidget(patchMergeSecondPatchSpinBox);

        verticalLayoutWidget_2 = new QWidget(PatchMergeWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(209, 150, 171, 80));
        patchMergeSecondDirectionLayout = new QVBoxLayout(verticalLayoutWidget_2);
        patchMergeSecondDirectionLayout->setObjectName(QString::fromUtf8("patchMergeSecondDirectionLayout"));
        patchMergeSecondDirectionLayout->setContentsMargins(0, 0, 0, 0);
        patchMergeSecondDirectionLabel = new QLabel(verticalLayoutWidget_2);
        patchMergeSecondDirectionLabel->setObjectName(QString::fromUtf8("patchMergeSecondDirectionLabel"));
        patchMergeSecondDirectionLabel->setAlignment(Qt::AlignCenter);

        patchMergeSecondDirectionLayout->addWidget(patchMergeSecondDirectionLabel);

        patchMergeSecondDirectionComboBox = new QComboBox(verticalLayoutWidget_2);
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->addItem(QString());
        patchMergeSecondDirectionComboBox->setObjectName(QString::fromUtf8("patchMergeSecondDirectionComboBox"));

        patchMergeSecondDirectionLayout->addWidget(patchMergeSecondDirectionComboBox);

        verticalLayoutWidget = new QWidget(PatchMergeWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 150, 171, 80));
        patchMergeFirstDirectionLayout = new QVBoxLayout(verticalLayoutWidget);
        patchMergeFirstDirectionLayout->setObjectName(QString::fromUtf8("patchMergeFirstDirectionLayout"));
        patchMergeFirstDirectionLayout->setContentsMargins(0, 0, 0, 0);
        patchMergeFirstDirectionLabel = new QLabel(verticalLayoutWidget);
        patchMergeFirstDirectionLabel->setObjectName(QString::fromUtf8("patchMergeFirstDirectionLabel"));
        patchMergeFirstDirectionLabel->setAlignment(Qt::AlignCenter);

        patchMergeFirstDirectionLayout->addWidget(patchMergeFirstDirectionLabel);

        patchMergeFirstDirectionComboBox = new QComboBox(verticalLayoutWidget);
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->addItem(QString());
        patchMergeFirstDirectionComboBox->setObjectName(QString::fromUtf8("patchMergeFirstDirectionComboBox"));

        patchMergeFirstDirectionLayout->addWidget(patchMergeFirstDirectionComboBox);

        patchMergeWindowLabel = new QLabel(PatchMergeWindow);
        patchMergeWindowLabel->setObjectName(QString::fromUtf8("patchMergeWindowLabel"));
        patchMergeWindowLabel->setGeometry(QRect(22, 0, 361, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        patchMergeWindowLabel->setFont(font);
        patchMergeWindowLabel->setAcceptDrops(false);
        patchMergeWindowLabel->setTextFormat(Qt::AutoText);
        patchMergeWindowLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(PatchMergeWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 50, 361, 51));
        patchMergeFirstPatchLayout = new QHBoxLayout(horizontalLayoutWidget);
        patchMergeFirstPatchLayout->setObjectName(QString::fromUtf8("patchMergeFirstPatchLayout"));
        patchMergeFirstPatchLayout->setContentsMargins(0, 0, 0, 0);
        patchMergeFirstPatchLabel = new QLabel(horizontalLayoutWidget);
        patchMergeFirstPatchLabel->setObjectName(QString::fromUtf8("patchMergeFirstPatchLabel"));

        patchMergeFirstPatchLayout->addWidget(patchMergeFirstPatchLabel);

        patchMergeFirstPatchSpinBox = new QSpinBox(horizontalLayoutWidget);
        patchMergeFirstPatchSpinBox->setObjectName(QString::fromUtf8("patchMergeFirstPatchSpinBox"));
        patchMergeFirstPatchSpinBox->setMaximum(3);

        patchMergeFirstPatchLayout->addWidget(patchMergeFirstPatchSpinBox);


        retranslateUi(PatchMergeWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PatchMergeWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PatchMergeWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PatchMergeWindow);
    } // setupUi

    void retranslateUi(QDialog *PatchMergeWindow)
    {
        PatchMergeWindow->setWindowTitle(QCoreApplication::translate("PatchMergeWindow", "Dialog", nullptr));
        patchMergeSecondPatchLabel->setText(QCoreApplication::translate("PatchMergeWindow", "Second patch index", nullptr));
        patchMergeSecondDirectionLabel->setText(QCoreApplication::translate("PatchMergeWindow", "Second direction", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(0, QCoreApplication::translate("PatchMergeWindow", "N", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(1, QCoreApplication::translate("PatchMergeWindow", "NE", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(2, QCoreApplication::translate("PatchMergeWindow", "E", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(3, QCoreApplication::translate("PatchMergeWindow", "SE", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(4, QCoreApplication::translate("PatchMergeWindow", "S", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(5, QCoreApplication::translate("PatchMergeWindow", "SW", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(6, QCoreApplication::translate("PatchMergeWindow", "W", nullptr));
        patchMergeSecondDirectionComboBox->setItemText(7, QCoreApplication::translate("PatchMergeWindow", "NW", nullptr));

        patchMergeSecondDirectionComboBox->setCurrentText(QCoreApplication::translate("PatchMergeWindow", "N", nullptr));
        patchMergeFirstDirectionLabel->setText(QCoreApplication::translate("PatchMergeWindow", "First direction", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(0, QCoreApplication::translate("PatchMergeWindow", "N", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(1, QCoreApplication::translate("PatchMergeWindow", "NE", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(2, QCoreApplication::translate("PatchMergeWindow", "E", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(3, QCoreApplication::translate("PatchMergeWindow", "SE", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(4, QCoreApplication::translate("PatchMergeWindow", "S", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(5, QCoreApplication::translate("PatchMergeWindow", "SW", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(6, QCoreApplication::translate("PatchMergeWindow", "W", nullptr));
        patchMergeFirstDirectionComboBox->setItemText(7, QCoreApplication::translate("PatchMergeWindow", "NW", nullptr));

        patchMergeFirstDirectionComboBox->setCurrentText(QCoreApplication::translate("PatchMergeWindow", "N", nullptr));
        patchMergeWindowLabel->setText(QCoreApplication::translate("PatchMergeWindow", "Merge two patches together", nullptr));
        patchMergeFirstPatchLabel->setText(QCoreApplication::translate("PatchMergeWindow", "First patch index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatchMergeWindow: public Ui_PatchMergeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATCHMERGEWINDOW_H
