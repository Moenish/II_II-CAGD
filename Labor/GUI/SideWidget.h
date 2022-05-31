#pragma once

#include <QWidget>
#include "ui_SideWidget.h"

namespace cagd
{
    class SideWidget: public QWidget, public Ui::SideWidget
    {
        Q_OBJECT
    public:
        // special and default constructor
        SideWidget(QWidget *parent = 0);

    public slots:
        void setArcAlpha(double);
        void setArcScale(double);
        void setArcDivCount(int);
        void setArcX(double);
        void setArcY(double);
        void setArcZ(double);

        void setPatchAlphaU(double);
        void setPatchAlphaV(double);
        void setPatchScale(double);
        void setPatchDivCountU(int);
        void setPatchDivCountV(int);
        void setPatchLineCountU(int);
        void setPatchLineCountV(int);
        void setPatchX(double);
        void setPatchY(double);
        void setPatchZ(double);
    };
}
