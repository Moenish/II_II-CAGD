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
        void set_cc_limit(int limit);
        void set_cc_controlPoint_limit(int limit);
        void set_cc_controlPoint_values(double x, double y, double z);
        void set_e_value(double e);
    };
}
