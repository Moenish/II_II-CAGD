#include "MainWindow.h"

namespace cagd
{
    MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    {
        setupUi(this);

        /*

          the structure of the main window's central widget

         *---------------------------------------------------*
         |                 central widget                    |
         |                                                   |
         |  *---------------------------*-----------------*  |
         |  |     rendering context     |   scroll area   |  |
         |  |       OpenGL widget       | *-------------* |  |
         |  |                           | | side widget | |  |
         |  |                           | |             | |  |
         |  |                           | |             | |  |
         |  |                           | *-------------* |  |
         |  *---------------------------*-----------------*  |
         |                                                   |
         *---------------------------------------------------*

        */
        _side_widget = new SideWidget(this);

        _scroll_area = new QScrollArea(this);
        _scroll_area->setWidget(_side_widget);
        _scroll_area->setSizePolicy(_side_widget->sizePolicy());
        _scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        _gl_widget = new GLWidget(this);

        centralWidget()->setLayout(new QHBoxLayout());
        centralWidget()->layout()->addWidget(_gl_widget);
        centralWidget()->layout()->addWidget(_scroll_area);

        // creating a signal slot mechanism between the rendering context and the side widget
        connect(_side_widget->rotate_x_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_x(int)));
        connect(_side_widget->rotate_y_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_y(int)));
        connect(_side_widget->rotate_z_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_z(int)));

        connect(_side_widget->zoom_factor_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_zoom_factor(double)));

        connect(_side_widget->trans_x_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_x(double)));
        connect(_side_widget->trans_y_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_y(double)));
        connect(_side_widget->trans_z_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_z(double)));

        // Project

            // Arcs
                connect(_side_widget->arcInsertDSpinBox_Alpha, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcInsertSetAlpha(double)));
                connect(_side_widget->arcInsertDSpinBox_Scale, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcInsertSetScale(double)));
                connect(_side_widget->arcInsertISpinBox_DivCount, SIGNAL(valueChanged(int)), _gl_widget, SLOT(arcInsertSetDivCount(int)));
                connect(_side_widget->arcInsertButton, SIGNAL(clicked()), _gl_widget, SLOT(arcInsertButtonCreate()));

                connect(_side_widget->arcManipulationCheckBox_FirstOrder, SIGNAL(clicked(bool)), _gl_widget, SLOT(arcManipulateDoFirstDerivatives(bool)));
                connect(_side_widget->arcManipulationCheckBox_SecondOrder, SIGNAL(clicked(bool)), _gl_widget, SLOT(arcManipulateDoSecondDerivatives(bool)));
                connect(_side_widget->arcManipulateISpinBox_SelectArc, SIGNAL(valueChanged(int)), _gl_widget, SLOT(arcManipulateSetSelectedArc(int)));
                connect(_side_widget->arcManipulateISpinBox_ControlPoint, SIGNAL(valueChanged(int)), _gl_widget, SLOT(arcManipulateSetSelectedCP(int)));
                connect(_side_widget->arcManipulateDSpinBox_X, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcManipulateSet_X(double)));
                connect(_side_widget->arcManipulateDSpinBox_Y, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcManipulateSet_Y(double)));
                connect(_side_widget->arcManipulateDSpinBox_Z, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcManipulateSet_Z(double)));
                connect(_side_widget->arcManipulateDSpinBox_TranslateX, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcManipulateSetTranslate_X(double)));
                connect(_side_widget->arcManipulateDSpinBox_TranslateY, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcManipulateSetTranslate_Y(double)));
                connect(_side_widget->arcManipulateDSpinBox_TranslateZ, SIGNAL(valueChanged(double)), _gl_widget, SLOT(arcManipulateSetTranslate_Z(double)));
                connect(_side_widget->arcDeleteButton, SIGNAL(clicked()), _gl_widget, SLOT(arcManipulateButtonDelete()));

            // Patches
                connect(_side_widget->patchInsertDSpinBox_UAlpha, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchInsertSetAlpha_U(double)));
                connect(_side_widget->patchInsertDSpinBox_VAlpha, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchInsertSetAlpha_V(double)));
                connect(_side_widget->patchInsertDSpinBox_Scale, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchInsertSetScale(double)));
                connect(_side_widget->patchInsertButton, SIGNAL(clicked()), _gl_widget, SLOT(patchInsertButtonCreate()));
                connect(_side_widget->patchSaveButton, SIGNAL(clicked()), _gl_widget, SLOT(patchInsertButtonSave()));
                connect(_side_widget->patchLoadButton, SIGNAL(clicked()), _gl_widget, SLOT(patchInsertButtonLoad()));

                connect(_side_widget->patchIsoparametricISpinBox_UDivCount, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchIsoparametricSetDivCount_U(int)));
                connect(_side_widget->patchIsoparametricISpinBox_VDivCount, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchIsoparametricSetDivCount_V(int)));
                connect(_side_widget->patchIsoparametricISpinBox_ULineCount, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchIsoparametricSetLineCount_U(int)));
                connect(_side_widget->patchIsoparametricISpinBox_VLineCount, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchIsoparametricSetLineCount_V(int)));

                connect(_side_widget->patchManipulationCheckBox_NormalVector, SIGNAL(clicked(bool)), _gl_widget, SLOT(patchManipulateDoNormal(bool)));
                connect(_side_widget->patchManipulationCheckBox_FirstOrder, SIGNAL(clicked(bool)), _gl_widget, SLOT(patchManipulateDoFirstDerivatives(bool)));
                connect(_side_widget->patchManipulationCheckBox_SecondOrder, SIGNAL(clicked(bool)), _gl_widget, SLOT(patchManipulateDoSecondDerivatives(bool)));
                connect(_side_widget->patchManipulateISpinBox_SelectPatch, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchManipulateSetSelectedPatch(int)));
                connect(_side_widget->patchManipulateISpinBox_SelectRow, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchManipulateSetSelectedRow(int)));
                connect(_side_widget->patchManipulateISpinBox_SelectColumn, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchManipulateSetSelectedCol(int)));
                connect(_side_widget->patchManipulateDSpinBox_X, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchManipulateSet_X(double)));
                connect(_side_widget->patchManipulateDSpinBox_Y, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchManipulateSet_Y(double)));
                connect(_side_widget->patchManipulateDSpinBox_Z, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchManipulateSet_Z(double)));
                connect(_side_widget->patchManipulateDSpinBox_TranslateX, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchManipulateSetTranslate_X(double)));
                connect(_side_widget->patchManipulateDSpinBox_TranslateY, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchManipulateSetTranslate_Y(double)));
                connect(_side_widget->patchManipulateDSpinBox_TranslateZ, SIGNAL(valueChanged(double)), _gl_widget, SLOT(patchManipulateSetTranslate_Z(double)));
                connect(_side_widget->patchManipulateISpinBox_Material, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchManipulateSetSelectedMaterial(int)));
                connect(_side_widget->patchManipulateISpinBox_Texture, SIGNAL(valueChanged(int)), _gl_widget, SLOT(patchManipulateSetSelectedTexture(int)));
                connect(_side_widget->patchDeleteButton, SIGNAL(clicked()), _gl_widget, SLOT(patchManipulateButtonDelete()));

        // Shaders
            connect(_side_widget->doShader, SIGNAL(clicked(bool)), _gl_widget, SLOT(shader_do(bool)));
            connect(_side_widget->shaderSelector, SIGNAL(valueChanged(int)), _gl_widget, SLOT(shader_set(int)));
            connect(_side_widget->shader_intensity, SIGNAL(valueChanged(double)), _gl_widget, SLOT(shader_intensity(double)));
            connect(_side_widget->shader_scale, SIGNAL(valueChanged(double)), _gl_widget, SLOT(shader_scale(double)));
            connect(_side_widget->shader_smoothing, SIGNAL(valueChanged(double)), _gl_widget, SLOT(shader_smoothing(double)));
            connect(_side_widget->shader_shading, SIGNAL(valueChanged(double)), _gl_widget, SLOT(shader_shading(double)));
    }


    //--------------------------------
    // implementation of private slots
    //--------------------------------
    void MainWindow::on_action_Quit_triggered()
    {
        qApp->exit(0);
    }
}
