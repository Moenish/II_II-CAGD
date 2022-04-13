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
}
