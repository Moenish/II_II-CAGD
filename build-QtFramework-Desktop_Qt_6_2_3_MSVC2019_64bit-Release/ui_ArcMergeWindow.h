/********************************************************************************
** Form generated from reading UI file 'ArcMergeWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCMERGEWINDOW_H
#define UI_ARCMERGEWINDOW_H

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

class Ui_ArcMergeWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *arcMergeFirstDirectionLayout;
    QLabel *arcMergeFirstDirectionLabel;
    QComboBox *arcMergeFirstDirectionComboBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *arcMergeSecondDirectionLayout;
    QLabel *arcMergeSecondDirectionLabel;
    QComboBox *arcMergeSecondDirectionComboBox;
    QLabel *arcMergeWindowLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *arcMergeFirstArcLayout;
    QLabel *arcMergeFirstArcLabel;
    QSpinBox *arcMergeFirstArcSpinBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *arcMergeSecondArcLayout;
    QLabel *arcMergeSecondArcLabel;
    QSpinBox *arcMergeSecondArcSpinBox;

    void setupUi(QDialog *ArcMergeWindow)
    {
        if (ArcMergeWindow->objectName().isEmpty())
            ArcMergeWindow->setObjectName(QString::fromUtf8("ArcMergeWindow"));
        ArcMergeWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(ArcMergeWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(ArcMergeWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 150, 171, 80));
        arcMergeFirstDirectionLayout = new QVBoxLayout(verticalLayoutWidget);
        arcMergeFirstDirectionLayout->setObjectName(QString::fromUtf8("arcMergeFirstDirectionLayout"));
        arcMergeFirstDirectionLayout->setContentsMargins(0, 0, 0, 0);
        arcMergeFirstDirectionLabel = new QLabel(verticalLayoutWidget);
        arcMergeFirstDirectionLabel->setObjectName(QString::fromUtf8("arcMergeFirstDirectionLabel"));
        arcMergeFirstDirectionLabel->setAlignment(Qt::AlignCenter);

        arcMergeFirstDirectionLayout->addWidget(arcMergeFirstDirectionLabel);

        arcMergeFirstDirectionComboBox = new QComboBox(verticalLayoutWidget);
        arcMergeFirstDirectionComboBox->setObjectName(QString::fromUtf8("arcMergeFirstDirectionComboBox"));

        arcMergeFirstDirectionLayout->addWidget(arcMergeFirstDirectionComboBox);

        verticalLayoutWidget_2 = new QWidget(ArcMergeWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(209, 150, 171, 80));
        arcMergeSecondDirectionLayout = new QVBoxLayout(verticalLayoutWidget_2);
        arcMergeSecondDirectionLayout->setObjectName(QString::fromUtf8("arcMergeSecondDirectionLayout"));
        arcMergeSecondDirectionLayout->setContentsMargins(0, 0, 0, 0);
        arcMergeSecondDirectionLabel = new QLabel(verticalLayoutWidget_2);
        arcMergeSecondDirectionLabel->setObjectName(QString::fromUtf8("arcMergeSecondDirectionLabel"));
        arcMergeSecondDirectionLabel->setAlignment(Qt::AlignCenter);

        arcMergeSecondDirectionLayout->addWidget(arcMergeSecondDirectionLabel);

        arcMergeSecondDirectionComboBox = new QComboBox(verticalLayoutWidget_2);
        arcMergeSecondDirectionComboBox->setObjectName(QString::fromUtf8("arcMergeSecondDirectionComboBox"));

        arcMergeSecondDirectionLayout->addWidget(arcMergeSecondDirectionComboBox);

        arcMergeWindowLabel = new QLabel(ArcMergeWindow);
        arcMergeWindowLabel->setObjectName(QString::fromUtf8("arcMergeWindowLabel"));
        arcMergeWindowLabel->setGeometry(QRect(22, 0, 361, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        arcMergeWindowLabel->setFont(font);
        arcMergeWindowLabel->setAcceptDrops(false);
        arcMergeWindowLabel->setTextFormat(Qt::AutoText);
        arcMergeWindowLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(ArcMergeWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 50, 361, 51));
        arcMergeFirstArcLayout = new QHBoxLayout(horizontalLayoutWidget);
        arcMergeFirstArcLayout->setObjectName(QString::fromUtf8("arcMergeFirstArcLayout"));
        arcMergeFirstArcLayout->setContentsMargins(0, 0, 0, 0);
        arcMergeFirstArcLabel = new QLabel(horizontalLayoutWidget);
        arcMergeFirstArcLabel->setObjectName(QString::fromUtf8("arcMergeFirstArcLabel"));

        arcMergeFirstArcLayout->addWidget(arcMergeFirstArcLabel);

        arcMergeFirstArcSpinBox = new QSpinBox(horizontalLayoutWidget);
        arcMergeFirstArcSpinBox->setObjectName(QString::fromUtf8("arcMergeFirstArcSpinBox"));
        arcMergeFirstArcSpinBox->setMaximum(3);

        arcMergeFirstArcLayout->addWidget(arcMergeFirstArcSpinBox);

        horizontalLayoutWidget_2 = new QWidget(ArcMergeWindow);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 100, 361, 51));
        arcMergeSecondArcLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        arcMergeSecondArcLayout->setObjectName(QString::fromUtf8("arcMergeSecondArcLayout"));
        arcMergeSecondArcLayout->setContentsMargins(0, 0, 0, 0);
        arcMergeSecondArcLabel = new QLabel(horizontalLayoutWidget_2);
        arcMergeSecondArcLabel->setObjectName(QString::fromUtf8("arcMergeSecondArcLabel"));

        arcMergeSecondArcLayout->addWidget(arcMergeSecondArcLabel);

        arcMergeSecondArcSpinBox = new QSpinBox(horizontalLayoutWidget_2);
        arcMergeSecondArcSpinBox->setObjectName(QString::fromUtf8("arcMergeSecondArcSpinBox"));
        arcMergeSecondArcSpinBox->setMaximum(3);

        arcMergeSecondArcLayout->addWidget(arcMergeSecondArcSpinBox);


        retranslateUi(ArcMergeWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ArcMergeWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ArcMergeWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ArcMergeWindow);
    } // setupUi

    void retranslateUi(QDialog *ArcMergeWindow)
    {
        ArcMergeWindow->setWindowTitle(QCoreApplication::translate("ArcMergeWindow", "Dialog", nullptr));
        arcMergeFirstDirectionLabel->setText(QCoreApplication::translate("ArcMergeWindow", "First direction", nullptr));
        arcMergeFirstDirectionComboBox->setCurrentText(QString());
        arcMergeSecondDirectionLabel->setText(QCoreApplication::translate("ArcMergeWindow", "Second direction", nullptr));
        arcMergeSecondDirectionComboBox->setCurrentText(QString());
        arcMergeWindowLabel->setText(QCoreApplication::translate("ArcMergeWindow", "Merge two arcs together", nullptr));
        arcMergeFirstArcLabel->setText(QCoreApplication::translate("ArcMergeWindow", "First arc index", nullptr));
        arcMergeSecondArcLabel->setText(QCoreApplication::translate("ArcMergeWindow", "Second arc index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArcMergeWindow: public Ui_ArcMergeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCMERGEWINDOW_H
