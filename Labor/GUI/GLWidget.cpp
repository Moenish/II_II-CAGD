#include "GLWidget.h"

#if !defined(__APPLE__)
#include <GL/glu.h>
#endif

#include <iostream>
#include <fstream>
using namespace std;

#include <Core/Exceptions.h>
#include <Core/DCoordinates3.h>
#include <Core/Matrices.h>
#include <Test/TestFunctions.h>
#include <Core/Constants.h>
#include <QTimer>

namespace cagd
{
    //--------------------------------
    // special and default constructor
    //--------------------------------
GLWidget::GLWidget(QWidget* parent, ArcContinueWindow* arcContinueWindow, ArcJoinWindow* arcJoinWindow, ArcMergeWindow* arcMergeWindow, PatchContinueWindow* patchContinueWindow, PatchJoinWindow* patchJoinWindow, PatchMergeWindow* patchMergeWindow) : QOpenGLWidget(parent)
    {
        _arcContinueWindow      = arcContinueWindow;
        _arcJoinWindow          = arcJoinWindow;
        _arcMergeWindow         = arcMergeWindow;
        _patchContinueWindow    = patchContinueWindow;
        _patchJoinWindow        = patchJoinWindow;
        _patchMergeWindow       = patchMergeWindow;
    }

    //--------------------------------------------------------------------------------------
    // this virtual function is called once before the first call to paintGL() or resizeGL()
    //--------------------------------------------------------------------------------------
    void GLWidget::initializeGL()
    {
        // creating a perspective projection matrix
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        _aspect = static_cast<double>(width()) / static_cast<double>(height());
        _z_near = 1.0;
        _z_far = 1000.0;
        _fovy = 45.0;

        gluPerspective(_fovy, _aspect, _z_near, _z_far);

        // setting the model view matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        _eye[0] = _eye[1] = 0.0;
        _eye[2] = 6.0;
        _center[0] = _center[1] = _center[2] = 0.0;
        _up[0] = _up[2] = 0.0;
        _up[1] = 1.0;

        gluLookAt(_eye[0], _eye[1], _eye[2], _center[0], _center[1], _center[2], _up[0], _up[1], _up[2]);

        // enabling the depth test
        glEnable(GL_DEPTH_TEST);

        // setting the background color
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // initial values of transformation parameters
        _angle_x = _angle_y = _angle_z = 0.0;
        _trans_x = _trans_y = _trans_z = 0.0;
        _zoom = 1.0;

        try
        {
            // initializing the OpenGL Extension Wrangler library
            GLenum error = glewInit();

            if (error != GLEW_OK)
            {
                throw Exception("Could not initialize the OpenGL Extension Wrangler Library!");
            }

            if (!glewIsSupported("GL_VERSION_2_0"))
            {
                throw Exception("Your graphics card is not compatible with OpenGL 2.0+! "
                                "Try to update your driver or buy a new graphics adapter!");
            }

            // create and store your geometry in display lists or vertex buffer objects

            // Project
                HCoordinate3    direction(0.0f, 1.0f, 0.0f, 0.0f);
                Color4          ambient(0.4f, 0.4f, 0.4f, 1.0f);
                Color4          diffuse(0.8f, 0.8f, 0.8f, 1.0f);
                Color4          specular(1.0f, 1.0f, 1.0f, 1.0f);

                _dirLight = new (nothrow) DirectionalLight(GL_LIGHT0, direction, ambient, diffuse, specular);
                if (!_dirLight)
                {
                    throw("Exception: Could Not Create The Directional Light!");
                }
                _sotc_arc_color = new Color4(1.0f, 0.0f, 0.0f, 1.0f);

                emitArcSignals();
                emitPatchSignals();


            // Shaders
                _getTextures();
                _getShaders();


            glEnable(GL_POINT_SMOOTH);
            glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
            glEnable(GL_LINE_SMOOTH);
            glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
            glEnable(GL_POLYGON_SMOOTH);
            glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
            glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
            glEnable(GL_DEPTH_TEST);
        }
        catch (Exception &e)
        {
            cout << e << endl;
        }
    }

    //-----------------------
    // the rendering function
    //-----------------------
    void GLWidget::paintGL()
    {
        // clears the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // stores/duplicates the original model view matrix
        glPushMatrix();

        // applying transformations
        glRotatef(_angle_x, 1.0, 0.0, 0.0);
        glRotatef(_angle_y, 0.0, 1.0, 0.0);
        glRotatef(_angle_z, 0.0, 0.0, 1.0);
        glTranslated(_trans_x, _trans_y, _trans_z);
        glScaled(_zoom, _zoom, _zoom);

        // render your geometry (this is oldest OpenGL rendering technique, later we will use some advanced methods)
        if (_shader_do_shader)
        {
            if (_shader_index == 2 && _shader_intensity < 1.0f)
            {
                glEnable(GL_BLEND);
                glDepthMask(GL_FALSE);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
            }
            _shaders[_shader_index].Enable(GL_TRUE);
        }
        switch (_selected_page)
        {
        case 0:
            // Arcs
            glPushMatrix();
            if (_sotc_arc_do_neg_derivatives)
                _sotc_arc.renderAllArcs(-1, GL_POINTS);
            if (_sotc_arc_do_zeroth_derivatives)
                _sotc_arc.renderAllArcs(0, GL_LINE_STRIP);
            if (_sotc_arc_do_first_derivatives)
                _sotc_arc.renderAllArcs(1, GL_LINES);
            if (_sotc_arc_do_second_derivatives)
                _sotc_arc.renderAllArcs(2, GL_LINES);
            glPopMatrix();

            break;
        case 1:
            // Patches
            glPushMatrix();
                glEnable(GL_NORMALIZE);
                glEnable(GL_LIGHTING);
                glEnable(GL_TEXTURE_2D);
                    _dirLight->Enable();

                    if (_textures_loaded)
                    {
                        if (_sotc_patch_do_texture)
                        {
                            _textures[_sotc_patch_selected_texture]->bind();
                        }
                        else
                        {
                            _textures[_sotc_patch_selected_texture]->release();
                        }
                    }

                    _sotc_patch.renderEveryPatch(_materials[_sotc_patch_selected_material], _sotc_patch_do_patch, _sotc_patch_do_isoparametric_u, _sotc_patch_do_isoparametric_v, _sotc_patch_do_normal, _sotc_patch_do_first_derivatives, _sotc_patch_do_second_derivatives);
                    _dirLight->Disable();
                glDisable(GL_TEXTURE_2D);
                glDisable(GL_LIGHTING);
                glDisable(GL_NORMALIZE);
            glPopMatrix();

            break;
        }
        if (_shader_do_shader)
        {
            if (_shader_index == 2 && _shader_intensity < 1.0f)
            {
                glDepthMask(GL_TRUE);
                glDisable(GL_BLEND);
            }
            _shaders[_shader_index].Disable();
        }

        // pops the current matrix stack, replacing the current matrix with the one below it on the stack,
        // i.e., the original model view matrix is restored
        glPopMatrix();
    }

    //----------------------------------------------------------------------------
    // when the main window is resized one needs to redefine the projection matrix
    //----------------------------------------------------------------------------
    void GLWidget::resizeGL(int w, int h)
    {
        // setting the new size of the rendering context
        glViewport(0, 0, w, h);

        // redefining the projection matrix
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        _aspect = static_cast<double>(w) / static_cast<double>(h);

        gluPerspective(_fovy, _aspect, _z_near, _z_far);

        // switching back to the model view matrix
        glMatrixMode(GL_MODELVIEW);

        update();
    }

    //-----------------------------------
    // implementation of the private slots
    //-----------------------------------


    //-----------------------------------
    // implementation of the public slots
    //-----------------------------------
    void GLWidget::set_angle_x(int value)
    {
        if (_angle_x != value)
        {
            _angle_x = value;
            update();
        }
    }

    void GLWidget::set_angle_y(int value)
    {
        if (_angle_y != value)
        {
            _angle_y = value;
            update();
        }
    }

    void GLWidget::set_angle_z(int value)
    {
        if (_angle_z != value)
        {
            _angle_z = value;
            update();
        }
    }

    void GLWidget::set_zoom_factor(double value)
    {
        if (_zoom != value)
        {
            _zoom = value;
            update();
        }
    }

    void GLWidget::set_trans_x(double value)
    {
        if (_trans_x != value)
        {
            _trans_x = value;
            update();
        }
    }

    void GLWidget::set_trans_y(double value)
    {
        if (_trans_y != value)
        {
            _trans_y = value;
            update();
        }
    }

    void GLWidget::set_trans_z(double value)
    {
        if (_trans_z != value)
        {
            _trans_z = value;
            update();
        }
    }

    void GLWidget::set_selected_page(int value)
    {
        _selected_page = (GLuint)value;

        if (_selected_page == 0)
            emitArcSignals();
        else
            emitPatchSignals();

        update();
    }

    // Project
        void GLWidget::showArcContinueWindow()
        {
            _arcContinueWindow->show();
        }

        void GLWidget::showArcJoinWindow()
        {
            _arcJoinWindow->show();
        }

        void GLWidget::showArcMergeWindow()
        {
            _arcMergeWindow->show();
        }

        void GLWidget::showPatchContinueWindow()
        {
            _patchContinueWindow->show();
        }

        void GLWidget::showPatchJoinWindow()
        {
            _patchJoinWindow->show();
        }

        void GLWidget::showPatchMergeWindow()
        {
            _patchMergeWindow->show();
        }

        void GLWidget::emitArcSignals()
        {
            emit setArcAlpha(_sotc_arc.getAlpha());
            emit setArcScale(_sotc_arc.getScale());
            emit setArcDivCount(_sotc_arc.getDivPointCount());
            if (_sotc_arc.arcExists(_sotc_arc_selected_arc))
            {
                emit setArcX(_sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).x());
                emit setArcY(_sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).y());
                emit setArcZ(_sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).z());
            }
        }

        void GLWidget::emitPatchSignals()
        {
            emit setPatchAlpha_U(_sotc_patch_alpha_U);
            emit setPatchAlpha_V(_sotc_patch_alpha_V);
            emit setPatchScale(_sotc_patch_scale);
            emit setPatchDivCount_U(_sotc_patch_isoparametric_DivCount_U);
            emit setPatchDivCount_V(_sotc_patch_isoparametric_DivCount_V);
            emit setPatchLineCount_U(_sotc_patch_isoparametric_LineCount_U);
            emit setPatchLineCount_V(_sotc_patch_isoparametric_LineCount_V);
            if (_sotc_patch.patchExists(_sotc_patch_selected_patch))
            {
                emit setPatchX(_sotc_patch.getSelectedPoint(_sotc_patch_selected_patch, _sotc_patch_selected_row, _sotc_patch_selected_col).x());
                emit setPatchY(_sotc_patch.getSelectedPoint(_sotc_patch_selected_patch, _sotc_patch_selected_row, _sotc_patch_selected_col).y());
                emit setPatchZ(_sotc_patch.getSelectedPoint(_sotc_patch_selected_patch, _sotc_patch_selected_row, _sotc_patch_selected_col).z());
            }
        }

        // Arcs
            void GLWidget::arcInsertSetAlpha(double value)
            {
                if (_sotc_arc_alpha != value)
                {
                    _sotc_arc_alpha = value;
                    _sotc_arc.setAlphaAndRenderArcs(value);
                }

                emitArcSignals();

                update();
            }

            void GLWidget::arcInsertSetScale(double value)
            {
                if (_sotc_arc_scale != value)
                {
                    _sotc_arc_scale = value;
                    _sotc_arc.setScale(value);
                    _sotc_arc.renderAllArcsScale();
                }

                emitArcSignals();

                update();
            }

            void GLWidget::arcInsertSetDivCount(int value)
            {
                if (_sotc_arc_DivCount != value)
                {
                    _sotc_arc_DivCount = value;
                    _sotc_arc.setDivPointCount(value);
                    _sotc_arc.renderArcsWithModifiedDivPointCount();
                }

                emitArcSignals();

                update();
            }

            void GLWidget::arcInsertButtonCreate()
            {
                _sotc_arc.insertArc(_sotc_arc_color, 2, _sotc_arc_DivCount);

                emitArcSignals();

                update();
            }

            void GLWidget::arcManipulateDoNegDerivatives(bool value)
            {
                _sotc_arc_do_neg_derivatives = value;

                update();
            }

            void GLWidget::arcManipulateDoZerothDerivatives(bool value)
            {
                _sotc_arc_do_first_derivatives = value;

                update();
            }

            void GLWidget::arcManipulateDoFirstDerivatives(bool value)
            {
                _sotc_arc_do_first_derivatives = value;

                update();
            }

            void GLWidget::arcManipulateDoSecondDerivatives(bool value)
            {
                _sotc_arc_do_second_derivatives = value;

                update();
            }

            void GLWidget::arcManipulateSetSelectedArc(int value)
            {
                if (_sotc_arc_selected_arc != value)
                {
                    _sotc_arc_selected_arc = value;
                    _sotc_arc.setSelectedArc(value);
                }

                emitArcSignals();

                update();
            }

            void GLWidget::arcManipulateSetSelectedCP(int value)
            {
                if (_sotc_arc_selected_cp != value)
                {
                    _sotc_arc_selected_cp = value;
                    _sotc_arc.setSelectedCP(value);
                }

                emitArcSignals();

                update();
            }

            void GLWidget::arcManipulateSet_X(double x)
            {
                // TODO
                _sotc_arc.modifyArcPosition(_sotc_arc_selected_arc, _sotc_arc_selected_cp,
                                            x,
                                            _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).y(),
                                            _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).z());

                update();
            }

            void GLWidget::arcManipulateSet_Y(double y)
            {
                _sotc_arc.modifyArcPosition(_sotc_arc_selected_arc, _sotc_arc_selected_cp,
                                            _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).x(),
                                            y,
                                            _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).z());

                update();
            }

            void GLWidget::arcManipulateSet_Z(double z)
            {
                _sotc_arc.modifyArcPosition(_sotc_arc_selected_arc, _sotc_arc_selected_cp,
                                            _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).x(),
                                            _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, _sotc_arc_selected_cp).y(),
                                            z);

                update();
            }

            void GLWidget::arcManipulateSetTranslate_X(double value)
            {
                value = value - _sotc_arc_translate_previous_x;
                _sotc_arc_translate_previous_x = value + _sotc_arc_translate_previous_x;
                for (GLuint i = 0; i < 4; ++i)
                {
                    double x = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[0] + value;
                    double y = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[1];
                    double z = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[2];
                    _sotc_arc.modifyArcPosition(_sotc_arc_selected_arc, i, x, y, z);
                }

                update();
            }

            void GLWidget::arcManipulateSetTranslate_Y(double value)
            {
                value = value - _sotc_arc_translate_previous_y;
                _sotc_arc_translate_previous_y = value + _sotc_arc_translate_previous_y;
                for (GLuint i = 0; i < 4; ++i)
                {
                    double x = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[0];
                    double y = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[1] + value;
                    double z = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[2];
                    _sotc_arc.modifyArcPosition(_sotc_arc_selected_arc, i, x, y, z);
                }

                update();
            }

            void GLWidget::arcManipulateSetTranslate_Z(double value)
            {
                value = value - _sotc_arc_translate_previous_z;
                _sotc_arc_translate_previous_z = value + _sotc_arc_translate_previous_z;
                for (GLuint i = 0; i < 4; ++i)
                {
                    double x = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[0];
                    double y = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[1];
                    double z = _sotc_arc.getSelectedCP(_sotc_arc_selected_arc, i)[2] + value;
                    _sotc_arc.modifyArcPosition(_sotc_arc_selected_arc, i, x, y, z);
                }

                update();
            }

            void GLWidget::arcManipulateButtonDelete()
            {
                _sotc_arc.deleteExistingArc(_sotc_arc_selected_arc);

                update();
            }

            void GLWidget::arcInteractionButtonContinue()
            {
                _sotc_arc.continueExistingArc(_sotc_arc_continue_arc, _sotc_arc_directions[_sotc_arc_continue_direction]);

                update();
            }

            void GLWidget::arcInteractionButtonJoin()
            {
                _sotc_arc.joinExistingArcs(_sotc_arc_join_arc1, _sotc_arc_directions[_sotc_arc_join_direction1],
                                           _sotc_arc_join_arc2, _sotc_arc_directions[_sotc_arc_join_direction2]);

                update();
            }

            void GLWidget::arcInteractionButtonMerge()
            {
                _sotc_arc.mergeExistingArcs(_sotc_arc_merge_arc1, _sotc_arc_directions[_sotc_arc_merge_direction1],
                                            _sotc_arc_merge_arc2, _sotc_arc_directions[_sotc_arc_merge_direction2]);

                update();
            }

            void GLWidget::arcInteractionContinueSetArc(int value)
            {
                if (_sotc_arc_continue_arc != value)
                    _sotc_arc_continue_arc = value;
            }

            void GLWidget::arcInteractionContinueSetDirection(int value)
            {
                if (_sotc_arc_continue_direction != value)
                    _sotc_arc_continue_direction = value;
            }

            void GLWidget::arcInteractionJoinSetArc1(int value)
            {
                if (_sotc_arc_join_arc1 != value)
                    _sotc_arc_join_arc1 = value;
            }

            void GLWidget::arcInteractionJoinSetArc2(int value)
            {
                if (_sotc_arc_join_arc2 != value)
                    _sotc_arc_join_arc2 = value;
            }

            void GLWidget::arcInteractionJoinSetDirection1(int value)
            {
                if (_sotc_arc_join_direction1 != value)
                    _sotc_arc_join_direction1 = value;
            }

            void GLWidget::arcInteractionJoinSetDirection2(int value)
            {
                if (_sotc_arc_join_direction2 != value)
                    _sotc_arc_join_direction2 = value;
            }

            void GLWidget::arcInteractionMergeSetArc1(int value)
            {
                if (_sotc_arc_merge_arc1 != value)
                    _sotc_arc_merge_arc1 = value;
            }

            void GLWidget::arcInteractionMergeSetArc2(int value)
            {
                if (_sotc_arc_merge_arc2 != value)
                    _sotc_arc_merge_arc2 = value;
            }

            void GLWidget::arcInteractionMergeSetDirection1(int value)
            {
                if (_sotc_arc_merge_direction1 != value)
                    _sotc_arc_merge_direction1 = value;
            }

            void GLWidget::arcInteractionMergeSetDirection2(int value)
            {
                if (_sotc_arc_merge_direction2 != value)
                    _sotc_arc_merge_direction2 = value;
            }


        // Patches
            void GLWidget::patchInsertSetAlpha_U(double value)
            {
                if (_sotc_patch_alpha_U != value)
                {
                    _sotc_patch_alpha_U = value;
                    _sotc_patch.setAlpha_U(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchInsertSetAlpha_V(double value)
            {
                if (_sotc_patch_alpha_V != value)
                {
                    _sotc_patch_alpha_V = value;
                    _sotc_patch.setAlpha_V(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchInsertSetScale(double value)
            {
                if (_sotc_patch_scale != value)
                {
                    _sotc_patch_scale = value;
                    _sotc_patch.setIsoparametricScale(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchInsertButtonCreate()
            {
                _sotc_patch.insertNewPatch(&_materials[0]);

                emitPatchSignals();

                update();
            }

            void GLWidget::patchInsertButtonSave()
            {
                // TODO
                update();
            }

            void GLWidget::patchInsertButtonLoad()
            {
                // TODO
                update();
            }


            void GLWidget::patchIsoparametricSetDivCount_U(int value)
            {
                if (_sotc_patch_isoparametric_DivCount_U != value)
                {
                    _sotc_patch_isoparametric_DivCount_U = value;
                    _sotc_patch.setIsoparametricDivCount_U(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchIsoparametricSetDivCount_V(int value)
            {
                if (_sotc_patch_isoparametric_DivCount_V != value)
                {
                    _sotc_patch_isoparametric_DivCount_V = value;
                    _sotc_patch.setIsoparametricDivCount_V(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchIsoparametricSetLineCount_U(int value)
            {
                if (_sotc_patch_isoparametric_LineCount_U != value)
                {
                    _sotc_patch_isoparametric_LineCount_U = value;
                    _sotc_patch.setIsoparametricLineCount_U(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchIsoparametricSetLineCount_V(int value)
            {
                if (_sotc_patch_isoparametric_LineCount_V != value)
                {
                    _sotc_patch_isoparametric_LineCount_V = value;
                    _sotc_patch.setIsoparametricLineCount_V(value);
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchIsoparametricDo_U(bool value)
            {
                _sotc_patch_do_isoparametric_u = value;

                update();
            }

            void GLWidget::patchIsoparametricDo_V(bool value)
            {
                _sotc_patch_do_isoparametric_v = value;

                update();
            }

            void GLWidget::patchIsoparametricDoNormal(bool value)
            {
                _sotc_patch_do_normal = value;

                update();
            }

            void GLWidget::patchIsoparametricDoFirstDerivatives(bool value)
            {
                _sotc_patch_do_first_derivatives = value;

                update();
            }

            void GLWidget::patchIsoparametricDoSecondDerivatives(bool value)
            {
                _sotc_patch_do_second_derivatives = value;

                update();
            }

            void GLWidget::patchManipulateDoPatch(bool value)
            {
                _sotc_patch_do_patch = value;

                update();
            }


            void GLWidget::patchManipulateSetSelectedPatch(int value)
            {
                if (_sotc_patch_selected_patch != value)
                {
                    _sotc_patch_selected_patch = value;
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchManipulateSetSelectedRow(int value)
            {
                if (_sotc_patch_selected_row != value)
                {
                    _sotc_patch_selected_row = value;
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchManipulateSetSelectedCol(int value)
            {
                if (_sotc_patch_selected_col != value)
                {
                    _sotc_patch_selected_col = value;
                }

                emitPatchSignals();

                update();
            }

            void GLWidget::patchManipulateSet_X(double value)
            {
                // TODO
                update();
            }

            void GLWidget::patchManipulateSet_Y(double value)
            {
                // TODO
                update();
            }

            void GLWidget::patchManipulateSet_Z(double value)
            {
                // TODO
                update();
            }

            void GLWidget::patchManipulateSetTranslate_X(double value)
            {
                // TODO
                value = value - _sotc_patch_translate_previous_x;
                _sotc_patch_translate_previous_x = value + _sotc_patch_translate_previous_x;
                _sotc_patch.translateSelectedPatch(_sotc_patch_selected_patch, 0, value);

                update();
            }

            void GLWidget::patchManipulateSetTranslate_Y(double value)
            {
                // TODO
                value = value - _sotc_patch_translate_previous_y;
                _sotc_patch_translate_previous_y = value + _sotc_patch_translate_previous_y;
                _sotc_patch.translateSelectedPatch(_sotc_patch_selected_patch, 1, value);

                update();
            }

            void GLWidget::patchManipulateSetTranslate_Z(double value)
            {
                // TODO
                value = value - _sotc_patch_translate_previous_z;
                _sotc_patch_translate_previous_z = value + _sotc_patch_translate_previous_z;
                _sotc_patch.translateSelectedPatch(_sotc_patch_selected_patch, 2, value);

                update();
            }

            void GLWidget::patchManipulateSetSelectedMaterial(int value)
            {
                if (_sotc_patch_selected_material != value)
                {
                    _sotc_patch_selected_material = value;
                }

                update();
            }

            void GLWidget::patchManipulateSetSelectedTexture(int value)
            {
                if (_sotc_patch_selected_texture != value)
                {
                    _sotc_patch_selected_texture = value;
                }

                update();
            }

            void GLWidget::patchManipulateDoTexture(bool value)
            {
                _sotc_patch_do_texture = value;

                update();
            }

            void GLWidget::patchManipulateButtonDelete()
            {
                // TODO
//                _sotc_patch.deletePatch(_sotc_patch_selected_patch);

                update();
            }

            void GLWidget::patchInteractionButtonContinue()
            {
                _sotc_patch.continuePatch(_sotc_patch_continue_patch, _sotc_patch_directions[_sotc_patch_continue_direction]);

                update();
            }

            void GLWidget::patchInteractionButtonJoin()
            {
                // TODO
                _sotc_patch.joinPatches(_sotc_patch_join_patch1, _sotc_patch_join_patch2, _sotc_patch_directions[_sotc_patch_join_direction1], _sotc_patch_directions[_sotc_patch_join_direction2]);

                update();
            }

            void GLWidget::patchInteractionButtonMerge()
            {
                // TODO
                _sotc_patch.mergePatches(_sotc_patch_merge_patch1, _sotc_patch_merge_patch2, _sotc_patch_directions[_sotc_patch_merge_direction1], _sotc_patch_directions[_sotc_patch_merge_direction2]);

                update();
            }

            void GLWidget::patchInteractionContinueSetPatch(int value)
            {
                if (_sotc_patch_continue_patch != value)
                    _sotc_patch_continue_patch = value;
            }

            void GLWidget::patchInteractionContinueSetDirection(int value)
            {
                if (_sotc_patch_continue_direction != value)
                    _sotc_patch_continue_direction = value;
            }

            void GLWidget::patchInteractionJoinSetPatch1(int value)
            {
                if (_sotc_patch_join_patch1 != value)
                    _sotc_patch_join_patch1 = value;
            }

            void GLWidget::patchInteractionJoinSetPatch2(int value)
            {
                if (_sotc_patch_join_patch2 != value)
                    _sotc_patch_join_patch2 = value;
            }

            void GLWidget::patchInteractionJoinSetDirection1(int value)
            {
                if (_sotc_patch_join_direction1 != value)
                    _sotc_patch_join_direction1 = value;
            }

            void GLWidget::patchInteractionJoinSetDirection2(int value)
            {
                if (_sotc_patch_join_direction2 != value)
                    _sotc_patch_join_direction2 = value;
            }

            void GLWidget::patchInteractionMergeSetPatch1(int value)
            {
                if (_sotc_patch_merge_patch1 != value)
                    _sotc_patch_merge_patch1 = value;
            }

            void GLWidget::patchInteractionMergeSetPatch2(int value)
            {
                if (_sotc_patch_merge_patch2 != value)
                    _sotc_patch_merge_patch2 = value;
            }

            void GLWidget::patchInteractionMergeSetDirection1(int value)
            {
                if (_sotc_patch_merge_direction1 != value)
                    _sotc_patch_merge_direction1 = value;
            }

            void GLWidget::patchInteractionMergeSetDirection2(int value)
            {
                if (_sotc_patch_merge_direction2 != value)
                    _sotc_patch_merge_direction2 = value;
            }



    // Shaders
    void GLWidget::shader_set(int value)
    {
        _shader_index = value;
        update();
    }

    void GLWidget::shader_do(bool value)
    {
        _shader_do_shader = value;
        update();
    }

    void GLWidget::shader_intensity(double value)
    {
        if (_shader_intensity != value)
        {
            _shaders[_shader_index].Enable();
            _shader_intensity = value;
            if (_shader_index == 2)
            {
                _shaders[_shader_index].SetUniformVariable4f("default_outline_color", _shader_scale, _shader_shading, _shader_smoothing, _shader_intensity);
            }
            if (_shader_index == 3)
            {
                _shaders[_shader_index].SetUniformVariable1f("scale_factor", _shader_scale);
                _shaders[_shader_index].SetUniformVariable1f("smoothing", _shader_smoothing);
                _shaders[_shader_index].SetUniformVariable1f("shading", _shader_shading);
            }
            _shaders[_shader_index].Disable();
            update();
        }
    }

    void GLWidget::shader_scale(double value)
    {
        if (_shader_scale != value)
        {
            _shaders[_shader_index].Enable();
            _shader_scale = value;
            if (_shader_index == 2)
            {
                _shaders[_shader_index].SetUniformVariable4f("default_outline_color", _shader_scale, _shader_shading, _shader_smoothing, _shader_intensity);
            }
            if (_shader_index == 3)
            {
                _shaders[_shader_index].SetUniformVariable1f("scale_factor", _shader_scale);
                _shaders[_shader_index].SetUniformVariable1f("smoothing", _shader_smoothing);
                _shaders[_shader_index].SetUniformVariable1f("shading", _shader_shading);
            }
            _shaders[_shader_index].Disable();
            update();
        }
    }

    void GLWidget::shader_shading(double value)
    {
        if (_shader_shading != value)
        {
            _shaders[_shader_index].Enable();
            _shader_shading = value;
            if (_shader_index == 2)
            {
                _shaders[_shader_index].SetUniformVariable4f("default_outline_color", _shader_scale, _shader_shading, _shader_smoothing, _shader_intensity);
            }
            if (_shader_index == 3)
            {
                _shaders[_shader_index].SetUniformVariable1f("scale_factor", _shader_scale);
                _shaders[_shader_index].SetUniformVariable1f("smoothing", _shader_smoothing);
                _shaders[_shader_index].SetUniformVariable1f("shading", _shader_shading);
            }
            _shaders[_shader_index].Disable();
            update();
        }
    }

    void GLWidget::shader_smoothing(double value)
    {
        if (_shader_smoothing != value)
        {
            _shaders[_shader_index].Enable();
            _shader_smoothing = value;
            if (_shader_index == 2)
            {
                _shaders[_shader_index].SetUniformVariable4f("default_outline_color", _shader_scale, _shader_shading, _shader_smoothing, _shader_intensity);
            }
            if (_shader_index == 3)
            {
                _shaders[_shader_index].SetUniformVariable1f("scale_factor", _shader_scale);
                _shaders[_shader_index].SetUniformVariable1f("smoothing", _shader_smoothing);
                _shaders[_shader_index].SetUniformVariable1f("shading", _shader_shading);
            }
            _shaders[_shader_index].Disable();
            update();
        }
    }

    //-----------

    // Patches
    void GLWidget::_getTextures() {
        _texture_paths.ResizeColumns(14);
        _texture_paths[0] = "Textures/texture_01.jpg";
        _texture_paths[1] = "Textures/texture_02.jpg";
        _texture_paths[2] = "Textures/texture_03.jpg";
        _texture_paths[3] = "Textures/texture_04.jpg";
        _texture_paths[4] = "Textures/texture_05.jpg";
        _texture_paths[5] = "Textures/texture_06.jpg";
        _texture_paths[6] = "Textures/texture_07.jpg";
        _texture_paths[7] = "Textures/texture_08.jpg";
        _texture_paths[8] = "Textures/texture_09.jpg";
        _texture_paths[9] = "Textures/texture_10.jpg";
        _texture_paths[10] = "Textures/texture_11.jpg";
        _texture_paths[11] = "Textures/texture_12.jpg";
        _texture_paths[12] = "Textures/texture_13.jpg";
        _texture_paths[13] = "Textures/texture_14.jpg";

        _textures.ResizeColumns(_texture_paths.GetColumnCount());

        for(GLuint i = 0; i < _texture_paths.GetColumnCount(); i++)
        {
            _textures[i] = new QOpenGLTexture(QImage(_texture_paths[i]).mirrored());
            _textures[i]->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
            _textures[i]->setMagnificationFilter(QOpenGLTexture::Linear);
        }

        _textures_loaded = true;
    }

    // Shaders
    void GLWidget::_getShaders()
    {
        _shaders.ResizeColumns(4);

        try
        {
            if (!_shaders[0].InstallShaders("Shaders/directional_light.vert", "Shaders/directional_light.frag", GL_FALSE))
            {
                throw Exception("Could not install shaders");
            }
            if (!_shaders[1].InstallShaders("Shaders/two_sided_lighting.vert", "Shaders/two_sided_lighting.frag", GL_FALSE))
            {
                throw Exception("Could not install shaders");
            }
            if (!_shaders[2].InstallShaders("Shaders/toon.vert", "Shaders/toon.frag", GL_FALSE))
            {
                throw Exception("Could not install shaders");
            } else {
                _shaders[2].Enable();
                _shaders[2].SetUniformVariable4f("default_outline_color", _shader_scale, _shader_smoothing, _shader_shading, _shader_intensity);
                _shaders[2].Disable();
            }
            if (!_shaders[3].InstallShaders("Shaders/reflection_lines.vert", "Shaders/reflection_lines.frag", GL_FALSE))
            {
                throw Exception("Could not install shaders");
            } else {
                _shaders[3].Enable();
                _shaders[3].SetUniformVariable1f("scale_factor", _shader_scale);
                _shaders[3].SetUniformVariable1f("smoothing", _shader_smoothing);
                _shaders[3].SetUniformVariable1f("shading", _shader_shading);
                _shaders[3].Disable();
            }
        }
        catch (Exception &e)
        {
            cerr << e << endl;
        }
    }

    //-----------
    // destructor
    //-----------
    GLWidget::~GLWidget()
    {
        if (_dirLight)
        {
            delete _dirLight; _dirLight = nullptr;
        }

        _sotc_arc.deleteAllArcs();

//        _sotc_patch.deleteAllPatches();
    }
}
