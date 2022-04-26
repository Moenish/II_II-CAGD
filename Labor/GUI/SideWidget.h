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
        void set_speed_value(int speed);
        void set_div_value(int div);
        void set_point(bool value);
        void set_zeroth_derivative(bool value);
        void set_first_derivative(bool value);
        void set_second_derivative(bool value);
    };
}
