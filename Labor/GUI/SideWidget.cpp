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

    void SideWidget::setArcAlpha(double value)
    {
        arcInsertDSpinBox_Alpha->setValue(value);
    }

    void SideWidget::setArcScale(double value)
    {
        arcInsertDSpinBox_Scale->setValue(value);
    }

    void SideWidget::setArcDivCount(int value)
    {
        arcInsertISpinBox_DivCount->setValue(value);
    }

    void SideWidget::setArcX(double value)
    {
        arcManipulateDSpinBox_X->setValue(value);
    }

    void SideWidget::setArcY(double value)
    {
        arcManipulateDSpinBox_Y->setValue(value);
    }

    void SideWidget::setArcZ(double value)
    {
        arcManipulateDSpinBox_Z->setValue(value);
    }

    void SideWidget::setPatchAlphaU(double value)
    {
        patchInsertDSpinBox_UAlpha->setValue(value);
    }

    void SideWidget::setPatchAlphaV(double value)
    {
        patchInsertDSpinBox_VAlpha->setValue(value);
    }

    void SideWidget::setPatchScale(double value)
    {
        patchInsertDSpinBox_Scale->setValue(value);
    }

    void SideWidget::setPatchDivCountU(int value)
    {
        patchIsoparametricISpinBox_UDivCount->setValue(value);
    }

    void SideWidget::setPatchDivCountV(int value)
    {
        patchIsoparametricISpinBox_VDivCount->setValue(value);
    }

    void SideWidget::setPatchLineCountU(int value)
    {
        patchIsoparametricISpinBox_ULineCount->setValue(value);
    }

    void SideWidget::setPatchLineCountV(int value)
    {
        patchIsoparametricISpinBox_VLineCount->setValue(value);
    }

    void SideWidget::setPatchX(double value)
    {
        patchManipulateDSpinBox_X->setValue(value);
    }

    void SideWidget::setPatchY(double value)
    {
        patchManipulateDSpinBox_Y->setValue(value);
    }

    void SideWidget::setPatchZ(double value)
    {
        patchManipulateDSpinBox_Z->setValue(value);
    }

}
