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
    GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
    {
        _timer0 = new QTimer(this);
        _timer0->setInterval(0);
        _timer1 = new QTimer(this);
        _timer1->setInterval(0);
        _timer2 = new QTimer(this);
        _timer2->setInterval(0);
        _timer3 = new QTimer(this);
        _timer3->setInterval(0);

        connect(_timer0, SIGNAL(timeout()), this, SLOT(_animate0()));
        connect(_timer1, SIGNAL(timeout()), this, SLOT(_animate1()));
        connect(_timer2, SIGNAL(timeout()), this, SLOT(_animate2()));
        connect(_timer3, SIGNAL(timeout()), this, SLOT(_animate3()));
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
            // Parametric curves
                _createParametricCurves();
                for (GLuint i = 0; i < _pc_count; i++)
                {
                    _generateParametricImage(i);
                    _updateParametricVBO(i);
                }
            // Race
                HCoordinate3    direction(1.0f, 0.0f, 0.0f, 0.0f);
                Color4          ambient(0.4f, 0.4f, 0.4f, 1.0f);
                Color4          diffuse(0.8f, 0.8f, 0.8f, 1.0f);
                Color4          specular(1.0f, 1.0f, 1.0f, 1.0f);

                _dirLight = new (nothrow) DirectionalLight(GL_LIGHT0, direction, ambient, diffuse, specular);
                if (!_dirLight)
                {
                    throw("Exception: Could Not Create The Directional Light!");
                }

                _createRaceObjects();
                // Cyclic curve
                    _createAllCyclicCurves();
                    _createAllInterpolatingCyclicCurves();
            emit set_cc_maxLimit(_cc_count - 1);
            emit set_cc_cp_maxLimit(2 * _n[_selected_cyclic_curve_index]);
            emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);

            _timer0->start();
            _timer1->start();
            _timer2->start();
            _timer3->start();

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
        switch (_selected_page)
        {
        case 0:
            if (_pc_image_of_pcs[_pc_selected_curve_index])
            {
                glPushMatrix();
                glColor3f(1.0f, 1.0f, 1.0f);
                if (_pc_zeroth_derivative)
                {
                    glColor3f(1.0f, 0.0f, 0.0f);
                    _pc_image_of_pcs[_pc_selected_curve_index]->RenderDerivatives(0, GL_LINE_STRIP);
                }

                glPointSize(5.0f);

                if (_pc_first_derivative)
                {
                    glColor3f(0.0f, 1.0f, 0.0f);
                    _pc_image_of_pcs[_pc_selected_curve_index]->RenderDerivatives(1, GL_LINES);
                    _pc_image_of_pcs[_pc_selected_curve_index]->RenderDerivatives(1, GL_POINTS);
                }

                if (_pc_second_derivative)
                {
                    glColor3f(0.0f, 0.0f, 1.0f);
                    _pc_image_of_pcs[_pc_selected_curve_index]->RenderDerivatives(2, GL_LINES);
                    _pc_image_of_pcs[_pc_selected_curve_index]->RenderDerivatives(2, GL_POINTS);
                }

                glPointSize(1.0f);
                glColor3f(1.0f, 1.0f, 1.0f);
                glPopMatrix();
            }
            break;
        case 1:
            glEnable(GL_NORMALIZE);
            for (GLuint i = 0; i < _static_object_count; i++)
            {
                if (_dirLight)
                {
                    glPushMatrix();
                    const ModelProperties &static_object = _race_static_scene[i];
                    if (static_object.material_id >= 0)
                    {
                        glEnable(GL_LIGHTING);
                    }
                    _dirLight->Enable();

                    glRotated(static_object.angle[0], 1.0, 0.0, 0.0);
                    glRotated(static_object.angle[1], 0.0, 1.0, 0.0);
                    glRotated(static_object.angle[2], 0.0, 0.0, 1.0);

                    glTranslated(static_object.position[0], static_object.position[1], static_object.position[2]);
                    glScaled(static_object.scale[0], static_object.scale[1], static_object.scale[2]);

                    glColor3f(static_object.color[0], static_object.color[1], static_object.color[2]);

                    if (static_object.material_id >= 0)
                    {
                        _race_object_materials[static_object.material_id].Apply();
                    }

                    _race_static_models[static_object.id].Render();

                    _dirLight->Disable();
                    if (static_object.material_id >= 0)
                    {
                        glDisable(GL_LIGHTING);
                    }
                    glPopMatrix();
                }
            }

            for (GLuint i = 0; i < 2 * _moving_object_count; i = i + 2)
            {
                if (_dirLight)
                {
                    glPushMatrix();
                    const ModelProperties &moving_object_vehicle = _race_moving_scene[i];
                    const ModelProperties &moving_object_passanger = _race_moving_scene[i + 1];
                    // Vehicle
                    if (moving_object_vehicle.material_id >= 0)
                    {
                        glEnable(GL_LIGHTING);
                    }
                    _dirLight->Enable();

                    glRotated(moving_object_vehicle.angle[0], 1.0, 0.0, 0.0);
                    glRotated(moving_object_vehicle.angle[1], 0.0, 1.0, 0.0);
                    glRotated(moving_object_vehicle.angle[2], 0.0, 0.0, 1.0);

                    glTranslated(moving_object_vehicle.position[0], moving_object_vehicle.position[1], moving_object_vehicle.position[2]);
                    glScaled(moving_object_vehicle.scale[0], moving_object_vehicle.scale[1], moving_object_vehicle.scale[2]);

                    glColor3f(moving_object_vehicle.color[0], moving_object_vehicle.color[1], moving_object_vehicle.color[2]);

                    if (moving_object_vehicle.material_id >= 0)
                    {
                        _race_object_materials[moving_object_vehicle.material_id].Apply();
                    }

                    glMultMatrixd(_transformation[i / 2]);

                    _race_moving_models[moving_object_vehicle.id].Render();

                    _dirLight->Disable();
                    if (moving_object_vehicle.material_id >= 0)
                    {
                        glDisable(GL_LIGHTING);
                    }

                    // Passanger
                    if (moving_object_passanger.material_id >= 0)
                    {
                        glEnable(GL_LIGHTING);
                    }
                    _dirLight->Enable();

                    glRotated(moving_object_passanger.angle[0], 1.0, 0.0, 0.0);
                    glRotated(moving_object_passanger.angle[1], 0.0, 1.0, 0.0);
                    glRotated(moving_object_passanger.angle[2], 0.0, 0.0, 1.0);

                    glTranslated(moving_object_passanger.position[0], moving_object_passanger.position[1], moving_object_passanger.position[2]);
                    glScaled(moving_object_passanger.scale[0], moving_object_passanger.scale[1], moving_object_passanger.scale[2]);

                    glColor3f(moving_object_passanger.color[0], moving_object_passanger.color[1], moving_object_passanger.color[2]);

                    if (moving_object_passanger.material_id >= 0)
                    {
                        _race_object_materials[moving_object_passanger.material_id].Apply();
                    }

                    glMultMatrixd(_transformation[i / 2]);

                    glTranslated(0.0, 1.0, 0.0);
                    _race_moving_models[moving_object_passanger.id].Render();

                    _dirLight->Disable();
                    if (moving_object_passanger.material_id >= 0)
                    {
                        glDisable(GL_LIGHTING);
                    }
                    glPopMatrix();
                }
            }
            _renderCyclicCurves();
            _renderAllExistingInterpolatingCyclicCurves();

            break;
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
    void GLWidget::_animate0()
    {
        GLuint selected_object_index = 0;
        DCoordinate3 _t;
        DCoordinate3 der1;
        DCoordinate3 der2;

        if (_time_index[selected_object_index] >= _div)
        {
            _time_index[selected_object_index] = 0;
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
        {
            throw Exception("Exception: Could not get derivative");
        }

        _time_index[selected_object_index]++;

        _j_prime[selected_object_index] = der1;
        DCoordinate3 orange = der1 ^ der2;
        DCoordinate3 purple = der1 ^ orange;
        _i_prime[selected_object_index] = orange;
        _k_prime[selected_object_index] = purple;

        _i_prime[selected_object_index].normalize();
        _j_prime[selected_object_index].normalize();
        _k_prime[selected_object_index].normalize();

        _transformation[selected_object_index][0] = _i_prime[selected_object_index][0];
        _transformation[selected_object_index][1] = _i_prime[selected_object_index][1];
        _transformation[selected_object_index][2] = _i_prime[selected_object_index][2];
        _transformation[selected_object_index][3] = 0;

        _transformation[selected_object_index][4] = _j_prime[selected_object_index][0];
        _transformation[selected_object_index][5] = _j_prime[selected_object_index][1];
        _transformation[selected_object_index][6] = _j_prime[selected_object_index][2];
        _transformation[selected_object_index][7] = 0;

        _transformation[selected_object_index][8] =  _k_prime[selected_object_index][0];
        _transformation[selected_object_index][9] =  _k_prime[selected_object_index][1];
        _transformation[selected_object_index][10] = _k_prime[selected_object_index][2];
        _transformation[selected_object_index][11] = 0;

        _transformation[selected_object_index][12] = _t[0];
        _transformation[selected_object_index][13] = _t[1];
        _transformation[selected_object_index][14] = _t[2];
        _transformation[selected_object_index][15] = 1;

        update();
    }

    void GLWidget::_animate1()
    {
        GLuint selected_object_index = 1;
        DCoordinate3 _t;
        DCoordinate3 der1;
        DCoordinate3 der2;

        if (_time_index[selected_object_index] >= _div)
        {
            _time_index[selected_object_index] = 0;
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
        {
            throw Exception("Exception: Could not get derivative");
        }

        _time_index[selected_object_index]++;

        _j_prime[selected_object_index] = der1;
        DCoordinate3 orange = der1 ^ der2;
        DCoordinate3 purple = der1 ^ orange;
        _i_prime[selected_object_index] = orange;
        _k_prime[selected_object_index] = purple;

        _i_prime[selected_object_index].normalize();
        _j_prime[selected_object_index].normalize();
        _k_prime[selected_object_index].normalize();

        _transformation[selected_object_index][0] = _i_prime[selected_object_index][0];
        _transformation[selected_object_index][1] = _i_prime[selected_object_index][1];
        _transformation[selected_object_index][2] = _i_prime[selected_object_index][2];
        _transformation[selected_object_index][3] = 0;

        _transformation[selected_object_index][4] = _j_prime[selected_object_index][0];
        _transformation[selected_object_index][5] = _j_prime[selected_object_index][1];
        _transformation[selected_object_index][6] = _j_prime[selected_object_index][2];
        _transformation[selected_object_index][7] = 0;

        _transformation[selected_object_index][8] =  _k_prime[selected_object_index][0];
        _transformation[selected_object_index][9] =  _k_prime[selected_object_index][1];
        _transformation[selected_object_index][10] = _k_prime[selected_object_index][2];
        _transformation[selected_object_index][11] = 0;

        _transformation[selected_object_index][12] = _t[0];
        _transformation[selected_object_index][13] = _t[1];
        _transformation[selected_object_index][14] = _t[2];
        _transformation[selected_object_index][15] = 1;

        update();
    }

    void GLWidget::_animate2()
    {
        GLuint selected_object_index = 2;
        DCoordinate3 _t;
        DCoordinate3 der1;
        DCoordinate3 der2;

        if (_time_index[selected_object_index] >= _div)
        {
            _time_index[selected_object_index] = 0;
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
        {
            throw Exception("Exception: Could not get derivative");
        }

        _time_index[selected_object_index]++;

        _j_prime[selected_object_index] = der1;
        DCoordinate3 orange = der1 ^ der2;
        DCoordinate3 purple = der1 ^ orange;
        _i_prime[selected_object_index] = orange;
        _k_prime[selected_object_index] = purple;

        _i_prime[selected_object_index].normalize();
        _j_prime[selected_object_index].normalize();
        _k_prime[selected_object_index].normalize();

        _transformation[selected_object_index][0] = _i_prime[selected_object_index][0];
        _transformation[selected_object_index][1] = _i_prime[selected_object_index][1];
        _transformation[selected_object_index][2] = _i_prime[selected_object_index][2];
        _transformation[selected_object_index][3] = 0;

        _transformation[selected_object_index][4] = _j_prime[selected_object_index][0];
        _transformation[selected_object_index][5] = _j_prime[selected_object_index][1];
        _transformation[selected_object_index][6] = _j_prime[selected_object_index][2];
        _transformation[selected_object_index][7] = 0;

        _transformation[selected_object_index][8] =  _k_prime[selected_object_index][0];
        _transformation[selected_object_index][9] =  _k_prime[selected_object_index][1];
        _transformation[selected_object_index][10] = _k_prime[selected_object_index][2];
        _transformation[selected_object_index][11] = 0;

        _transformation[selected_object_index][12] = _t[0];
        _transformation[selected_object_index][13] = _t[1];
        _transformation[selected_object_index][14] = _t[2];
        _transformation[selected_object_index][15] = 1;

        update();
    }

    void GLWidget::_animate3()
    {
        GLuint selected_object_index = 3;
        DCoordinate3 _t;
        DCoordinate3 der1;
        DCoordinate3 der2;

        if (_time_index[selected_object_index] >= _div)
        {
            _time_index[selected_object_index] = 0;
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
        {
            throw Exception("Exception: Could not get derivative");
        }

        if (!_img_ccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
        {
            throw Exception("Exception: Could not get derivative");
        }

        _time_index[selected_object_index]++;

        _j_prime[selected_object_index] = der1;
        DCoordinate3 orange = der1 ^ der2;
        DCoordinate3 purple = der1 ^ orange;
        _i_prime[selected_object_index] = orange;
        _k_prime[selected_object_index] = purple;

        _i_prime[selected_object_index].normalize();
        _j_prime[selected_object_index].normalize();
        _k_prime[selected_object_index].normalize();

        _transformation[selected_object_index][0] = _i_prime[selected_object_index][0];
        _transformation[selected_object_index][1] = _i_prime[selected_object_index][1];
        _transformation[selected_object_index][2] = _i_prime[selected_object_index][2];
        _transformation[selected_object_index][3] = 0;

        _transformation[selected_object_index][4] = _j_prime[selected_object_index][0];
        _transformation[selected_object_index][5] = _j_prime[selected_object_index][1];
        _transformation[selected_object_index][6] = _j_prime[selected_object_index][2];
        _transformation[selected_object_index][7] = 0;

        _transformation[selected_object_index][8] =  _k_prime[selected_object_index][0];
        _transformation[selected_object_index][9] =  _k_prime[selected_object_index][1];
        _transformation[selected_object_index][10] = _k_prime[selected_object_index][2];
        _transformation[selected_object_index][11] = 0;

        _transformation[selected_object_index][12] = _t[0];
        _transformation[selected_object_index][13] = _t[1];
        _transformation[selected_object_index][14] = _t[2];
        _transformation[selected_object_index][15] = 1;

        update();
    }

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
        emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                              (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                              (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);
        update();
    }

    void GLWidget::pc_set_selected_parametric_curve_index(int value)
    {
        _pc_selected_curve_index = (GLuint)value;
        update();
    }

    void GLWidget::pc_set_div_point_count(int value)
    {
        if (_pc_div_point_count != (GLuint)value)
        {
            _pc_div_point_count = (GLuint)value;
            _generateParametricImage(_pc_selected_curve_index);
            _updateParametricVBO(_pc_selected_curve_index);
            update();
        }
    }

    void GLWidget::pc_set_derivative_scale(double value)
    {
        if (_pc_derivative_scale != (GLdouble)value)
        {
            _pc_derivative_scale = (GLdouble)value;
            _generateParametricImage(_pc_selected_curve_index);
            _updateParametricVBO(_pc_selected_curve_index);
            update();
        }
    }

    void GLWidget::pc_set_zeroth_derivative(bool value)
    {
        _pc_zeroth_derivative = value;
        update();
    }

    void GLWidget::pc_set_first_derivative(bool value)
    {
        _pc_first_derivative = value;
        update();
    }

    void GLWidget::pc_set_second_derivative(bool value)
    {
        _pc_second_derivative = value;
        update();
    }

    void GLWidget::race_set_selected_cyclic_curve_index(int value)
    {
        _selected_cyclic_curve_index = (GLuint)value;
        emit set_cc_cp_maxLimit(2 * _n[_selected_cyclic_curve_index]);
        emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                              (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                              (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);
        update();
    }

    void GLWidget::race_set_selected_control_point(int value)
    {
        _selected_cylcic_curve_control_point_index = (GLuint)value;
        emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                              (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                              (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);
        update();
    }

    void GLWidget::race_move_X(double value)
    {
        (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0] = value;

        if (_selected_cyclic_curve_index >= _icc_count)
        {
            _generateCyclicCurveImage(_selected_cyclic_curve_index);
            _updateCyclicCurveVBO(_selected_cyclic_curve_index);
            _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        else
        {
            _generateInterpolatingCyclicCurveImage(_selected_cyclic_curve_index);
            _updateInterpolatingCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        /*_generateCyclicCurveImage(_selected_cyclic_curve_index);
        _updateCyclicCurveVBO(_selected_cyclic_curve_index);
        _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        if (_selected_cyclic_curve_index < _icc_count && false)
        {
            _createInterpolatingCyclicCurve(_selected_cyclic_curve_index);
        }*/
        update();
    }

    void GLWidget::race_move_Y(double value)
    {
        (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1] = value;
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            _generateCyclicCurveImage(_selected_cyclic_curve_index);
            _updateCyclicCurveVBO(_selected_cyclic_curve_index);
            _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        else
        {
            _generateInterpolatingCyclicCurveImage(_selected_cyclic_curve_index);
            _updateInterpolatingCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        /*_generateCyclicCurveImage(_selected_cyclic_curve_index);
        _updateCyclicCurveVBO(_selected_cyclic_curve_index);
        _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        if (_selected_cyclic_curve_index < _icc_count && false)
        {
            _createInterpolatingCyclicCurve(_selected_cyclic_curve_index);
        }*/
        update();
    }

    void GLWidget::race_move_Z(double value)
    {
        (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2] = value;
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            _generateCyclicCurveImage(_selected_cyclic_curve_index);
            _updateCyclicCurveVBO(_selected_cyclic_curve_index);
            _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        else
        {
            _generateInterpolatingCyclicCurveImage(_selected_cyclic_curve_index);
            _updateInterpolatingCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        /*_generateCyclicCurveImage(_selected_cyclic_curve_index);
        _updateCyclicCurveVBO(_selected_cyclic_curve_index);
        _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        if (_selected_cyclic_curve_index < _icc_count && false)
        {
            _createInterpolatingCyclicCurve(_selected_cyclic_curve_index);
        }*/
        update();
    }


    //-----------
    // Parametric curves
    GLuint GLWidget::get_pc_count()
    {
        return (_pc_count > tests::count ? tests::count : _pc_count);
    }

    std::vector<std::string> GLWidget::get_test_names()
    {
        return tests::names();
    }

    void GLWidget::_createParametricCurves()
    {
        _pc_derivatives = RowMatrix<RowMatrix<ParametricCurve3::Derivative>>(_pc_count);
        _pcs = RowMatrix<ParametricCurve3 *>(_pc_count);
        _pc_image_of_pcs = RowMatrix<GenericCurve3 *>(_pc_count);

        for (GLuint i = 0; i < _pc_count; i++)
            _pc_derivatives[i] = RowMatrix<ParametricCurve3::Derivative>(3);

        GLdouble tmp_min = 0, tmp_max = 0;

        GLuint pc_iter = 0;
        while (pc_iter < _pc_count)
        {
            switch (pc_iter)
            {
            case 0:
                tmp_min = spiral_on_cone::u_min;
                tmp_max = spiral_on_cone::u_max;
                _pc_derivatives[pc_iter][0] = spiral_on_cone::d0;
                _pc_derivatives[pc_iter][1] = spiral_on_cone::d1;
                _pc_derivatives[pc_iter][2] = spiral_on_cone::d2;
                break;
            case 1:
                tmp_min = torus_knot::u_min;
                tmp_max = torus_knot::u_max;
                _pc_derivatives[pc_iter][0] = torus_knot::d0;
                _pc_derivatives[pc_iter][1] = torus_knot::d1;
                _pc_derivatives[pc_iter][2] = torus_knot::d2;
                break;
            case 2:
                tmp_min = rose::u_min;
                tmp_max = rose::u_max;
                _pc_derivatives[pc_iter][0] = rose::d0;
                _pc_derivatives[pc_iter][1] = rose::d1;
                _pc_derivatives[pc_iter][2] = rose::d2;
                break;
            case 3:
                tmp_min = spherical_spiral::u_min;
                tmp_max = spherical_spiral::u_max;
                _pc_derivatives[pc_iter][0] = spherical_spiral::d0;
                _pc_derivatives[pc_iter][1] = spherical_spiral::d1;
                _pc_derivatives[pc_iter][2] = spherical_spiral::d2;
                break;
            case 4:
                tmp_min = helix::u_min;
                tmp_max = helix::u_max;
                _pc_derivatives[pc_iter][0] = helix::d0;
                _pc_derivatives[pc_iter][1] = helix::d1;
                _pc_derivatives[pc_iter][2] = helix::d2;
                break;
            case 5:
                tmp_min = butterfly::u_min;
                tmp_max = butterfly::u_max;
                _pc_derivatives[pc_iter][0] = butterfly::d0;
                _pc_derivatives[pc_iter][1] = butterfly::d1;
                _pc_derivatives[pc_iter][2] = butterfly::d2;
                break;
            case 6:
                tmp_min = test::u_min;
                tmp_max = test::u_max;
                _pc_derivatives[pc_iter][0] = test::d0;
                _pc_derivatives[pc_iter][1] = test::d1;
                _pc_derivatives[pc_iter][2] = test::d2;
                break;
            case 7:
                tmp_min = torus::u_min;
                tmp_max = torus::u_max;
                _pc_derivatives[pc_iter][0] = torus::d0;
                _pc_derivatives[pc_iter][1] = torus::d1;
                _pc_derivatives[pc_iter][2] = torus::d2;
                break;
            }
            _pcs[pc_iter] = new (nothrow) ParametricCurve3(_pc_derivatives[pc_iter], tmp_min, tmp_max);

            if (!_pcs[pc_iter])
            {
                throw Exception("Exception: Could not create parametric curve");
                _destroyAllExistingParametricCurves();
                pc_iter = 0;
            }
            else
            {
                pc_iter++;
            }
        }
    }

    void GLWidget::_generateParametricImage(GLuint i)
    {
        _pc_image_of_pcs[i] = _pcs[i]->GenerateImage(_pc_div_point_count, _pc_usage_flag);

        if (!_pc_image_of_pcs[i])
        {
            throw Exception("Exception: Could not generate image of the parametric curve");
            _destroyAllExistingParametricCurvesImages();
        }
    }

    void GLWidget::_updateParametricVBO(GLuint i)
    {
        if (!_pc_image_of_pcs[i]->UpdateVertexBufferObjects(_pc_derivative_scale, _pc_usage_flag))
        {
            throw Exception("Exception: Could not generate VBOs of the parametric curve");
            _destroyAllExistingParametricCurvesImages();
        }
    }

    void GLWidget::_destroyAllExistingParametricCurves()
    {
        for (GLuint i = 0; i < _pc_count; i++)
        {
             if (_pcs[i])
             {
                 delete _pcs[i]; _pcs[i] = nullptr;
             }
        }
    }

    void GLWidget::_destroyAllExistingParametricCurvesImages()
    {
        for (GLuint i = 0; i < _pc_count; i++)
        {
            if (_pc_image_of_pcs[i])
            {
                delete _pc_image_of_pcs[i]; _pc_image_of_pcs[i] = nullptr;
            }
        }
    }


    //-----------
    // Race
        // Approximating cyclic curves
        GLuint GLWidget::get_cc_count()
        {
            return _cc_count;
        }

        void GLWidget::_createCyclicCurve(GLuint i)
        {
                _updateCyclicCurveVBO(i);

                _generateCyclicCurveImage(i);

                _updateCyclicCurveImageVBO(i);
        }

        void GLWidget::_createAllCyclicCurves()
        {
            for (GLuint i = 0; i < _cc_count; i++)
            {
                _updateCyclicCurveVBO(i);
            }

            for (GLuint i = 0; i < _cc_count; i++)
            {
                _generateCyclicCurveImage(i);
            }

            for (GLuint i = 0; i < _cc_count; i++)
            {
                _updateCyclicCurveImageVBO(i);
            }
        }

        void GLWidget::_generateCyclicCurveImage(GLuint i)
        {
            _img_ccs[i] = _ccs[i]->GenerateImage(_mod, _div);
            if (!_img_ccs[i])
            {
                throw Exception("Exception: Could not genereate the image of cyclic curve");
                _destroyAllExistingCyclicCurvesImages();
            }
        }

        void GLWidget::_updateCyclicCurveVBO(GLuint i)
        {
            if (!_ccs[i]->UpdateVertexBufferObjectsOfData())
            {
                throw Exception("Exception: Could not update VBOs of cyclic curve's control polygon");
                _destroyAllExistingCyclicCurvesImages();
            }
        }

        void GLWidget::_updateCyclicCurveImageVBO(GLuint i)
        {
            if (!_img_ccs[i]->UpdateVertexBufferObjects())
            {
                throw Exception("Exception: Could not update VBOs of cyclic curve's image");
                _destroyAllExistingCyclicCurvesImages();
            }
        }

        void GLWidget::_renderCyclicCurves()
        {
            for (GLuint i = _icc_count; i < _cc_count; i++)
            {
                CyclicCurve3 *cc = _ccs[i];
                GenericCurve3 *img_cc = _img_ccs[i];
                if (cc)
                {
                    glColor3d(1.0f, 0.0f, 0.0f);
                    cc->RenderData(GL_LINE_LOOP);

                    glPointSize(10.0f);
                    cc->RenderData(GL_POINTS);
                    glPointSize(1.0f);
                }

                if (img_cc)
                {
                    glColor3d(1.0f, 0.0f, 0.0f);
                    img_cc->RenderDerivatives(0, GL_LINE_LOOP);

    //                glColor3d(0.0f, 1.0f, 0.0f);
    //                img_cc->RenderDerivatives(1, GL_LINES);

    //                glColor3d(0.0f, 0.0f, 1.0f);
    //                img_cc->RenderDerivatives(2, GL_LINES);
                }
            }
        }

        void GLWidget::_destroyCyclicCurve(GLuint i)
        {
            if (_ccs[i])
            {
                delete _ccs[i]; _ccs[i] = nullptr;
            }
        }

        void GLWidget::_destroyCyclicCurveImage(GLuint i)
        {
            if (_img_ccs[i])
            {
                delete _img_ccs[i]; _img_ccs[i] = nullptr;
            }
        }

        void GLWidget::_destroyAllExistingCyclicCurves()
        {
            for (GLuint i = 0; i < _cc_count; i++)
            {
                if (_ccs[i])
                {
                    delete _ccs[i]; _ccs[i] = nullptr;
                }
            }
        }

        void GLWidget::_destroyAllExistingCyclicCurvesImages()
        {
            for (GLuint i = 0; i < _cc_count; i++)
            {
                if (_img_ccs[i])
                {
                    delete _img_ccs[i]; _img_ccs[i] = nullptr;
                }
            }
        }

        // Interpolating cyclic curves
        void GLWidget::_createInterpolatingCyclicCurve(GLuint icc_iter)
        {
                GLuint dimension = 2 * _n[icc_iter] + 1;
                GLdouble step = TWO_PI / (dimension);

                ColumnMatrix<GLdouble> U(dimension);
                for (GLuint i = 0; i < dimension; i++)
                {
                    U[i] = i * step;
                }

                _iccs[icc_iter].ResizeRows(dimension);

                for (GLuint i = 0; i < dimension; i++)
                {
                    DCoordinate3 &dp = _iccs[icc_iter][i];

                    dp[0] = (*_ccs[icc_iter])[i][0] * step;
                    dp[1] = (*_ccs[icc_iter])[i][1] * step;
                    dp[2] = (*_ccs[icc_iter])[i][2] * step;
                }

                _img_iccs.ResizeColumns(_icc_count);
                    if (!_ccs[icc_iter]->UpdateDataForInterpolation(U, _iccs[icc_iter]))
                    {
                        throw Exception("Exception: Could not update data for interpolation");
                    }

                    _generateInterpolatingCyclicCurveImage(icc_iter);

                    _updateInterpolatingCyclicCurveImageVBO(icc_iter);
        }

        void GLWidget::_createAllInterpolatingCyclicCurves()
        {
            GLuint icc_iter = 0;
            while (icc_iter < _icc_count)
            {
                GLuint dimension = 2 * _n[icc_iter] + 1;
                GLdouble step = TWO_PI / (dimension);

                ColumnMatrix<GLdouble> U(dimension);
                for (GLuint i = 0; i < dimension; i++)
                {
                    U[i] = i * step;
                }

                _iccs[icc_iter].ResizeRows(dimension);

                for (GLuint i = 0; i < dimension; i++)
                {
                    DCoordinate3 &dp = _iccs[icc_iter][i];

                    dp[0] = (*_ccs[icc_iter])[i][0] * step;
                    dp[1] = (*_ccs[icc_iter])[i][1] * step;
                    dp[2] = (*_ccs[icc_iter])[i][2] * step;
                }

                _img_iccs.ResizeColumns(_icc_count);
                for (GLuint i = 0; i < _icc_count; i++)
                {
                    if (!_ccs[i]->UpdateDataForInterpolation(U, _iccs[icc_iter]))
                    {
                        throw Exception("Exception: Could not update data for interpolation");
                    }

                    _generateInterpolatingCyclicCurveImage(i);

                    _updateInterpolatingCyclicCurveImageVBO(i);
                }

                icc_iter++;
            }
        }

        void GLWidget::_generateInterpolatingCyclicCurveImage(GLuint i)
        {
            _img_iccs[i] = _ccs[i]->GenerateImage(_mod, _div);
            if (!_img_iccs[i])
            {
                throw Exception("Exception: Could not generate the image of interpolating cyclic curve");
                _destroyAllExistingCyclicCurvesImages();
            }
        }

        void GLWidget::_updateInterpolatingCyclicCurveImageVBO(GLuint i)
        {
            if (!_img_iccs[i]->UpdateVertexBufferObjects())
            {
                throw Exception("Exception: Could not update VBOs of interpolating cyclic curve's image");
                _destroyAllExistingCyclicCurvesImages();
            }
        }

        void GLWidget::_renderInterpolatingCyclicCurve(GLuint i)
        {
                glColor3d(1.0, 0.0, 1.0);
                glPointSize(10.0);
                glBegin(GL_POINTS);
                for (GLuint j = 0; j < _iccs[i].GetRowCount(); j++)
                {
                    glVertex3dv(&_iccs[i][j][0]);
                }
                glEnd();
                glPointSize(1.0);

                if (_img_iccs[i])
                {
                    glColor3d(1.0, 0.9, 0.0);
                    _img_iccs[i]->RenderDerivatives(0, GL_LINE_LOOP);
                }
        }

        void GLWidget::_renderAllExistingInterpolatingCyclicCurves()
        {
            for (GLuint i = 0; i < _icc_count; i++)
            {
                glColor3d(1.0, 0.0, 1.0);
                glPointSize(10.0);
                glBegin(GL_POINTS);
                for (GLuint j = 0; j < _iccs[i].GetRowCount(); j++)
                {
                    glVertex3dv(&_iccs[i][j][0]);
                }
                glEnd();
                glPointSize(1.0);

                if (_img_iccs[i])
                {
                    glColor3d(1.0, 0.9, 0.0);
                    _img_iccs[i]->RenderDerivatives(0, GL_LINE_LOOP);
                }
            }
        }

        void GLWidget::_destroyInterpolatingCyclicCurveImage(GLuint i)
        {
            if (_img_iccs[i])
            {
                delete _img_iccs[i]; _img_iccs[i] = nullptr;
            }
        }

        void GLWidget::_destroyInterpolatingCyclicCurve(GLuint i)
        {

        }

        void GLWidget::_destroyAllExistingInterpolatingCyclicCurves()
        {
            _iccs.ResizeColumns(0);
        }

        void GLWidget::_destroyAllExistingInterpolatingCyclicCurvesImages()
        {
            for (GLuint i = 0; i < _icc_count; i++)
            {
                if (_img_iccs[i])
                {
                    delete _img_iccs[i]; _img_iccs[i] = nullptr;
                }
            }
        }

    // Race
    void GLWidget::_createRaceObjects()
    {
        if (!_getModels())
        {
            throw Exception("Exception: Could not get models");
            _destroyAllExistingObjects();
        }

        if (!_getScene())
        {
            throw Exception("Exception: Could not get scene");
            _destroyAllExistingObjects();
        }
    }

    void GLWidget::_destroyAllExistingObjects()
    {
        _static_object_count = 0;
        _moving_object_count = 0;
        _race_static_scene.ResizeColumns(_static_object_count);
        _race_moving_scene.ResizeColumns(_moving_object_count);
    }

    bool GLWidget::_getModels()
    {
        _moving_model_count = (GLuint)_moving_model_paths.size();
        _static_model_count = (GLuint)_static_model_paths.size();
        _race_moving_models.ResizeColumns(_moving_model_count);
        _race_static_models.ResizeColumns(_static_model_count);

        for (GLuint i = 0; i < _moving_model_count; i++)
        {
            if (_race_moving_models[i].LoadFromOFF(_moving_model_paths[i], GL_TRUE))
            {
                if(!_race_moving_models[i].UpdateVertexBufferObjects())
                {
                    throw Exception("Exception: Could not load moving model");
                    return GL_FALSE;
                }
            }
        }

        for (GLuint i = 0; i < _static_model_count; i++)
        {
            if (_race_static_models[i].LoadFromOFF(_static_model_paths[i], GL_TRUE))
            {
                if(!_race_static_models[i].UpdateVertexBufferObjects())
                {
                    throw Exception("Exception: Could not load static model");
                    return GL_FALSE;
                }
            }
        }

        return GL_TRUE;
    }

    bool GLWidget::_getScene()
    {
        ifstream sceneStream;
        sceneStream.open("Models/Scene.txt");

        if (!sceneStream.is_open())
        {
            throw Exception("Exception: Could not open scene file");
            return GL_FALSE;
        }

        sceneStream >> _cc_count;
        sceneStream >> _icc_count;

        _ccs.ResizeColumns(_cc_count);
        _img_ccs.ResizeColumns(_cc_count);
        _iccs.ResizeColumns(_icc_count);

        sceneStream >> _n;

        for (GLuint i = 0; i < _cc_count; i++)
        {
            ColumnMatrix<DCoordinate3> tempData;
            sceneStream >> tempData;
            _ccs[i] = new (nothrow) CyclicCurve3(_n[i]);
            if (!_ccs[i])
            {
                throw Exception("Exception: Could not create cyclic curve");
                _destroyAllExistingCyclicCurves();
                _destroyAllExistingCyclicCurvesImages();
                return GL_FALSE;
            }
            _ccs[i]->SetData(tempData);
        }

        sceneStream >> _moving_object_count;
        _race_moving_scene.ResizeColumns(2 * _moving_object_count);
        for (GLuint i = 0; i < 2 * _moving_object_count; i = i + 2)
        {
            sceneStream >> _race_moving_scene[i];
            if (sceneStream.fail())
            {
                throw Exception("Exception: Could not read scene file completely");
                return GL_FALSE;
            }

            if (_race_moving_scene[i].id > _moving_model_count)
            {
                throw Exception("Exception: Invalid moving passanger model id");
                return GL_FALSE;
            }

            sceneStream >> _race_moving_scene[i + 1];
            if (sceneStream.fail())
            {
                throw Exception("Exception: Could not read scene file completely");
                return GL_FALSE;
            }

            if (_race_moving_scene[i + 1].id > _moving_model_count)
            {
                throw Exception("Exception: Invalid moving vehicle model id");
                return GL_FALSE;
            }
        }


        sceneStream >> _static_object_count;
        _race_static_scene.ResizeColumns(_static_object_count);
        for (GLuint i = 0; i < _static_object_count; i++)
        {
            sceneStream >> _race_static_scene[i];
            if (sceneStream.fail())
            {
                throw Exception("Exception: Could not read scene file completely");
                return GL_FALSE;
            }

            if (_race_static_scene[i].id > _static_model_count)
            {
                throw Exception("Exception: Invalid static model id");
                return GL_FALSE;
            }
        }

        sceneStream.close();
        return GL_TRUE;
    }


    //-----------
    // destructor
    //-----------
    GLWidget::~GLWidget()
    {
        _destroyAllExistingParametricCurves();
        _destroyAllExistingParametricCurvesImages();
        _destroyAllExistingObjects();
        _destroyAllExistingCyclicCurves();
        _destroyAllExistingCyclicCurvesImages();
        _destroyAllExistingInterpolatingCyclicCurves();
        _destroyAllExistingInterpolatingCyclicCurvesImages();
        if (_dirLight)
        {
            delete _dirLight; _dirLight = nullptr;
        }
    }
}
