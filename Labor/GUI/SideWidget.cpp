#include "SideWidget.h"

namespace cagd
{
    SideWidget::SideWidget(QWidget *parent): QWidget(parent)
    {
        setupUi(this);

        QPalette p = rotate_x_slider->palette();

        p.setColor(QPalette::Highlight, QColor(255,50,10).lighter());

        rotate_x_slider->setPalette(p);

        p = rotate_y_slider->palette();

        p.setColor(QPalette::Highlight, QColor(50,255,10).lighter());

        rotate_y_slider->setPalette(p);
    }

    void SideWidget::set_cc_limit(int limit)
    {
        race_pathSelector->setMaximum(limit);
    }

    void SideWidget::set_cc_controlPoint_limit(int limit)
    {
        race_controlPoint->setMaximum(limit);
    }

    void SideWidget::set_cc_controlPoint_values(double x, double y, double z)
    {
        race_moveX->setValue(x);
        race_moveY->setValue(y);
        race_moveZ->setValue(z);
    }

    void SideWidget::set_e_value(double e)
    {
        race_edit_e->setValue(e);
    }

    void SideWidget::set_speed_value(int speed)
    {
        race_speedSpinbox->setValue(speed);
    }

    void SideWidget::set_div_value(int div)
    {
        race_divSpinbox->setValue(div);
    }

    void SideWidget::set_point(bool value)
    {
        race_doPoints->setChecked(value);
    }

    void SideWidget::set_zeroth_derivative(bool value)
    {
        race_doZerothDerivative->setChecked(value);
    }

    void SideWidget::set_first_derivative(bool value)
    {
        race_doFirstDerivative->setChecked(value);
    }

    void SideWidget::set_second_derivative(bool value)
    {
        race_doSecondDerivative->setChecked(value);
    }
}
