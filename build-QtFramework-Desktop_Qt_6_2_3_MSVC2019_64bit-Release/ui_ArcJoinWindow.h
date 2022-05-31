/********************************************************************************
** Form generated from reading UI file 'ArcJoinWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCJOINWINDOW_H
#define UI_ARCJOINWINDOW_H

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

class Ui_ArcJoinWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *arcJoinFirstArcLayout;
    QLabel *arcJoinFirstArcLabel;
    QSpinBox *arcJoinFirstArcSpinBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *arcJoinSecondArcLayout;
    QLabel *arcJoinSecondArcLabel;
    QSpinBox *arcJoinSecondArcSpinBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *arcJoinFirstDirectionLayout;
    QLabel *arcJoinFirstDirectionLabel;
    QComboBox *arcJoinFirstDirectionComboBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *arcJoinSecondDirectionLayout;
    QLabel *arcJoinSecondDirectionLabel;
    QComboBox *arcJoinSecondDirectionComboBox;
    QLabel *arcJoinWindowLabel;

    void setupUi(QDialog *ArcJoinWindow)
    {
        if (ArcJoinWindow->objectName().isEmpty())
            ArcJoinWindow->setObjectName(QString::fromUtf8("ArcJoinWindow"));
        ArcJoinWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(ArcJoinWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(ArcJoinWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 50, 361, 51));
        arcJoinFirstArcLayout = new QHBoxLayout(horizontalLayoutWidget);
        arcJoinFirstArcLayout->setObjectName(QString::fromUtf8("arcJoinFirstArcLayout"));
        arcJoinFirstArcLayout->setContentsMargins(0, 0, 0, 0);
        arcJoinFirstArcLabel = new QLabel(horizontalLayoutWidget);
        arcJoinFirstArcLabel->setObjectName(QString::fromUtf8("arcJoinFirstArcLabel"));

        arcJoinFirstArcLayout->addWidget(arcJoinFirstArcLabel);

        arcJoinFirstArcSpinBox = new QSpinBox(horizontalLayoutWidget);
        arcJoinFirstArcSpinBox->setObjectName(QString::fromUtf8("arcJoinFirstArcSpinBox"));
        arcJoinFirstArcSpinBox->setMaximum(3);

        arcJoinFirstArcLayout->addWidget(arcJoinFirstArcSpinBox);

        horizontalLayoutWidget_2 = new QWidget(ArcJoinWindow);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 100, 361, 51));
        arcJoinSecondArcLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        arcJoinSecondArcLayout->setObjectName(QString::fromUtf8("arcJoinSecondArcLayout"));
        arcJoinSecondArcLayout->setContentsMargins(0, 0, 0, 0);
        arcJoinSecondArcLabel = new QLabel(horizontalLayoutWidget_2);
        arcJoinSecondArcLabel->setObjectName(QString::fromUtf8("arcJoinSecondArcLabel"));

        arcJoinSecondArcLayout->addWidget(arcJoinSecondArcLabel);

        arcJoinSecondArcSpinBox = new QSpinBox(horizontalLayoutWidget_2);
        arcJoinSecondArcSpinBox->setObjectName(QString::fromUtf8("arcJoinSecondArcSpinBox"));
        arcJoinSecondArcSpinBox->setMaximum(3);

        arcJoinSecondArcLayout->addWidget(arcJoinSecondArcSpinBox);

        verticalLayoutWidget = new QWidget(ArcJoinWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 150, 171, 80));
        arcJoinFirstDirectionLayout = new QVBoxLayout(verticalLayoutWidget);
        arcJoinFirstDirectionLayout->setObjectName(QString::fromUtf8("arcJoinFirstDirectionLayout"));
        arcJoinFirstDirectionLayout->setContentsMargins(0, 0, 0, 0);
        arcJoinFirstDirectionLabel = new QLabel(verticalLayoutWidget);
        arcJoinFirstDirectionLabel->setObjectName(QString::fromUtf8("arcJoinFirstDirectionLabel"));
        arcJoinFirstDirectionLabel->setAlignment(Qt::AlignCenter);

        arcJoinFirstDirectionLayout->addWidget(arcJoinFirstDirectionLabel);

        arcJoinFirstDirectionComboBox = new QComboBox(verticalLayoutWidget);
        arcJoinFirstDirectionComboBox->addItem(QString());
        arcJoinFirstDirectionComboBox->addItem(QString());
        arcJoinFirstDirectionComboBox->setObjectName(QString::fromUtf8("arcJoinFirstDirectionComboBox"));

        arcJoinFirstDirectionLayout->addWidget(arcJoinFirstDirectionComboBox);

        verticalLayoutWidget_2 = new QWidget(ArcJoinWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(209, 150, 171, 80));
        arcJoinSecondDirectionLayout = new QVBoxLayout(verticalLayoutWidget_2);
        arcJoinSecondDirectionLayout->setObjectName(QString::fromUtf8("arcJoinSecondDirectionLayout"));
        arcJoinSecondDirectionLayout->setContentsMargins(0, 0, 0, 0);
        arcJoinSecondDirectionLabel = new QLabel(verticalLayoutWidget_2);
        arcJoinSecondDirectionLabel->setObjectName(QString::fromUtf8("arcJoinSecondDirectionLabel"));
        arcJoinSecondDirectionLabel->setAlignment(Qt::AlignCenter);

        arcJoinSecondDirectionLayout->addWidget(arcJoinSecondDirectionLabel);

        arcJoinSecondDirectionComboBox = new QComboBox(verticalLayoutWidget_2);
        arcJoinSecondDirectionComboBox->addItem(QString());
        arcJoinSecondDirectionComboBox->addItem(QString());
        arcJoinSecondDirectionComboBox->setObjectName(QString::fromUtf8("arcJoinSecondDirectionComboBox"));

        arcJoinSecondDirectionLayout->addWidget(arcJoinSecondDirectionComboBox);

        arcJoinWindowLabel = new QLabel(ArcJoinWindow);
        arcJoinWindowLabel->setObjectName(QString::fromUtf8("arcJoinWindowLabel"));
        arcJoinWindowLabel->setGeometry(QRect(22, 0, 361, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        arcJoinWindowLabel->setFont(font);
        arcJoinWindowLabel->setAcceptDrops(false);
        arcJoinWindowLabel->setTextFormat(Qt::AutoText);
        arcJoinWindowLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(ArcJoinWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ArcJoinWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ArcJoinWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ArcJoinWindow);
    } // setupUi

    void retranslateUi(QDialog *ArcJoinWindow)
    {
        ArcJoinWindow->setWindowTitle(QCoreApplication::translate("ArcJoinWindow", "Dialog", nullptr));
        arcJoinFirstArcLabel->setText(QCoreApplication::translate("ArcJoinWindow", "First arc index", nullptr));
        arcJoinSecondArcLabel->setText(QCoreApplication::translate("ArcJoinWindow", "Second arc index", nullptr));
        arcJoinFirstDirectionLabel->setText(QCoreApplication::translate("ArcJoinWindow", "First direction", nullptr));
        arcJoinFirstDirectionComboBox->setItemText(0, QCoreApplication::translate("ArcJoinWindow", "LEFT", nullptr));
        arcJoinFirstDirectionComboBox->setItemText(1, QCoreApplication::translate("ArcJoinWindow", "RIGHT", nullptr));

        arcJoinFirstDirectionComboBox->setCurrentText(QCoreApplication::translate("ArcJoinWindow", "LEFT", nullptr));
        arcJoinSecondDirectionLabel->setText(QCoreApplication::translate("ArcJoinWindow", "Second direction", nullptr));
        arcJoinSecondDirectionComboBox->setItemText(0, QCoreApplication::translate("ArcJoinWindow", "LEFT", nullptr));
        arcJoinSecondDirectionComboBox->setItemText(1, QCoreApplication::translate("ArcJoinWindow", "RIGHT", nullptr));

        arcJoinSecondDirectionComboBox->setCurrentText(QCoreApplication::translate("ArcJoinWindow", "LEFT", nullptr));
        arcJoinWindowLabel->setText(QCoreApplication::translate("ArcJoinWindow", "Join two arcs together", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArcJoinWindow: public Ui_ArcJoinWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCJOINWINDOW_H
