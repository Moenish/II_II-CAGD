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
        _timer4 = new QTimer(this);
        _timer4->setInterval(0);
        _timer5 = new QTimer(this);
        _timer5->setInterval(0);
        _timer6 = new QTimer(this);
        _timer6->setInterval(0);
        _timer7 = new QTimer(this);
        _timer7->setInterval(0);
        _surfaceTimer = new QTimer(this);
        _surfaceTimer->setInterval(0);

        connect(_timer0, SIGNAL(timeout()), this, SLOT(_animate0()));
        connect(_timer1, SIGNAL(timeout()), this, SLOT(_animate1()));
        connect(_timer2, SIGNAL(timeout()), this, SLOT(_animate2()));
        connect(_timer3, SIGNAL(timeout()), this, SLOT(_animate3()));
        connect(_timer4, SIGNAL(timeout()), this, SLOT(_animatePassanger0()));
        connect(_timer5, SIGNAL(timeout()), this, SLOT(_animatePassanger1()));
        connect(_timer6, SIGNAL(timeout()), this, SLOT(_animatePassanger2()));
        connect(_timer7, SIGNAL(timeout()), this, SLOT(_animatePassanger3()));
        connect(_surfaceTimer, SIGNAL(timeout()), this, SLOT(_animateSurface()));
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
                HCoordinate3    directionRace(0.0f, 1.0f, 0.0f, 0.0f);
                Color4          ambientRace(0.4f, 0.4f, 0.4f, 1.0f);
                Color4          diffuseRace(0.8f, 0.8f, 0.8f, 1.0f);
                Color4          specularRace(1.0f, 1.0f, 1.0f, 1.0f);

                _dirLightRace = new (nothrow) DirectionalLight(GL_LIGHT0, directionRace, ambientRace, diffuseRace, specularRace);
                if (!_dirLightRace)
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
                emit set_e(_e[_selected_cyclic_curve_index]);
                emit set_speed(_cc_speed[_selected_cyclic_curve_index]);
                emit set_speed2(_cc_speed2[_selected_cyclic_curve_index]);
                emit set_points(_cc_points[_selected_cyclic_curve_index]);
                emit set_zeroth_derivative(_cc_zeroth_derivative[_selected_cyclic_curve_index]);
                emit set_first_derivative(_cc_first_derivative[_selected_cyclic_curve_index]);
                emit set_second_derivative(_cc_second_derivative[_selected_cyclic_curve_index]);

                _timer0->start();
                _timer1->start();
                _timer2->start();
                _timer3->start();
                _timer4->start();
                _timer5->start();
                _timer6->start();
                _timer7->start();

            // Surfaces
                HCoordinate3    directionSurface(1.0f, 0.0f, 0.0f, 0.0f);
                Color4          ambientSurface(0.4f, 0.4f, 0.4f, 1.0f);
                Color4          diffuseSurface(0.8f, 0.8f, 0.8f, 1.0f);
                Color4          specularSurface(1.0f, 1.0f, 1.0f, 1.0f);

                _dirLightSurface = new (nothrow) DirectionalLight(GL_LIGHT0, directionSurface, ambientSurface, diffuseSurface, specularSurface);
                if (!_dirLightSurface)
                {
                    throw("Exception: Could Not Create The Directional Light!");
                }


                _surface_textures.ResizeColumns(_ps_count);
                _surface_textures.ResizeColumns(_ps_count);

                _createParametricSurfaces();
                for (GLuint i = 0; i < _ps_count; i++)
                {
                    _generateParametricSurfaceImage(i);
                    _updateParametricSurfaceVBO(i);
                }

                _createParametricSurfaceCurves();
                for (GLuint i = 0; i < _psc_count; i++)
                {
                    _generateParametricSurfaceCurveImage(i);
                    _updateParametricSurfaceCurveVBO(i);
                }

                _getSurfaceTextures();

                emit surface_set_texture(_surface_selected_texture[_ps_selected_surface_index]);
                emit surface_set_material(_surface_selected_material[_ps_selected_surface_index]);

                _surfaceTimer->start();

            // Patch Magic
                HCoordinate3    directionPatch(0.0f, 1.0f, 0.0f, 0.0f);
                Color4          ambientPatch(0.4f, 0.4f, 0.4f, 1.0f);
                Color4          diffusePatch(0.8f, 0.8f, 0.8f, 1.0f);
                Color4          specularPatch(1.0f, 1.0f, 1.0f, 1.0f);

                _dirLightPatch = new (nothrow) DirectionalLight(GL_LIGHT0, directionPatch, ambientPatch, diffusePatch, specularPatch);
                if (!_dirLightPatch)
                {
                    throw("Exception: Could Not Create The Directional Light!");
                }
                _createPatch();

            // Arc
                _createArc();

            // Shaders
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
        if (_shader_do_shader) _shaders[_shader_index].Enable(GL_TRUE);
        switch (_selected_page)
        {
        case 0:
            // Parametric curves
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
            // Race
            glPushMatrix();
                glEnable(GL_NORMALIZE);
                for (GLuint i = 0; i < _static_object_count; i++)
                {
                    if (_dirLightRace)
                    {
                        const ModelProperties &static_object = _race_static_scene[i];
                        glPushMatrix();
                            if (static_object.material_id >= 0)
                            {
                                glEnable(GL_LIGHTING);
                            }
                            _dirLightRace->Enable();

                            glRotated(static_object.angle1[0], 1.0, 0.0, 0.0);
                            glRotated(static_object.angle1[1], 0.0, 1.0, 0.0);
                            glRotated(static_object.angle1[2], 0.0, 0.0, 1.0);

                            glTranslated(static_object.position[0], static_object.position[1], static_object.position[2]);

                            glRotated(static_object.angle2[0], 1.0, 0.0, 0.0);
                            glRotated(static_object.angle2[1], 0.0, 1.0, 0.0);
                            glRotated(static_object.angle2[2], 0.0, 0.0, 1.0);

                            glScaled(static_object.scale[0], static_object.scale[1], static_object.scale[2]);

                            glColor3f(static_object.color[0], static_object.color[1], static_object.color[2]);

                            if (static_object.material_id >= 0)
                            {
                                _race_object_materials[static_object.material_id].Apply();
                            }

                            _race_static_models[static_object.id].Render();

                            _dirLightRace->Disable();
                            if (static_object.material_id >= 0)
                            {
                                glDisable(GL_LIGHTING);
                            }
                        glPopMatrix();
                    }
                }

                for (GLuint i = 0; i < 2 * _moving_object_count; i = i + 2)
                {
                    if (_dirLightRace)
                    {
                        const ModelProperties &moving_object_vehicle = _race_moving_scene[i];
                        const ModelProperties &moving_object_passanger = _race_moving_scene[i + 1];

                        // Vehicle
                        glPushMatrix();
                            if (moving_object_vehicle.material_id >= 0)
                            {
                                glEnable(GL_LIGHTING);
                            }
                            _dirLightRace->Enable();

                            glMultMatrixd(_transformation[i / 2]);

                            glRotated(moving_object_vehicle.angle1[0], 1.0, 0.0, 0.0);
                            glRotated(moving_object_vehicle.angle1[1], 0.0, 1.0, 0.0);
                            glRotated(moving_object_vehicle.angle1[2], 0.0, 0.0, 1.0);

                            glTranslated(moving_object_vehicle.position[0], moving_object_vehicle.position[1], moving_object_vehicle.position[2]);

                            glRotated(moving_object_vehicle.angle2[0], 1.0, 0.0, 0.0);
                            glRotated(moving_object_vehicle.angle2[1], 0.0, 1.0, 0.0);
                            glRotated(moving_object_vehicle.angle2[2], 0.0, 0.0, 1.0);

                            glScaled(moving_object_vehicle.scale[0], moving_object_vehicle.scale[1], moving_object_vehicle.scale[2]);

                            glColor3f(moving_object_vehicle.color[0], moving_object_vehicle.color[1], moving_object_vehicle.color[2]);

                            if (moving_object_vehicle.material_id >= 0)
                            {
                                _race_object_materials[moving_object_vehicle.material_id].Apply();
                            }

                            _race_moving_models[moving_object_vehicle.id].Render();

                            _dirLightRace->Disable();
                            if (moving_object_vehicle.material_id >= 0)
                            {
                                glDisable(GL_LIGHTING);
                            }
                        glPopMatrix();


                        // Passanger
                        glPushMatrix();
                            if (moving_object_passanger.material_id >= 0)
                            {
                                glEnable(GL_LIGHTING);
                            }
                            _dirLightRace->Enable();

                            glMultMatrixd(_transformation[i / 2]);

                            glRotated(moving_object_passanger.angle1[0], 1.0, 0.0, 0.0);
                            glRotated(moving_object_passanger.angle1[1], 0.0, 1.0, 0.0);
                            glRotated(moving_object_passanger.angle1[2], 0.0, 0.0, 1.0);

                            glTranslated(moving_object_passanger.position[0], moving_object_passanger.position[1], moving_object_passanger.position[2]);

                            glRotated(moving_object_passanger.angle2[0], 1.0, 0.0, 0.0);
                            glRotated(moving_object_passanger.angle2[1], 0.0, 1.0, 0.0);
                            glRotated(moving_object_passanger.angle2[2], 0.0, 0.0, 1.0);

                            glScaled(moving_object_passanger.scale[0], moving_object_passanger.scale[1], moving_object_passanger.scale[2]);

                            glColor3f(moving_object_passanger.color[0], moving_object_passanger.color[1], moving_object_passanger.color[2]);

                            if (moving_object_passanger.material_id >= 0)
                            {
                                _race_object_materials[moving_object_passanger.material_id].Apply();
                            }

                            _race_moving_models[moving_object_passanger.id].Render();

                            _dirLightRace->Disable();
                            if (moving_object_passanger.material_id >= 0)
                            {
                                glDisable(GL_LIGHTING);
                            }
                        glPopMatrix();
                    }
                }
                _renderCyclicCurves();
                _renderAllExistingInterpolatingCyclicCurves();
                glDisable(GL_NORMALIZE);
            glPopMatrix();

            break;
        case 2:
            // Surfaces
            if (_ps_image_of_pss[_ps_selected_surface_index])
            {
                glPushMatrix();
                if (_dirLightSurface)
                {
                    glEnable(GL_NORMALIZE);
                    glEnable(GL_LIGHTING);
                    glEnable(GL_TEXTURE_2D);
                    _dirLightSurface->Enable();

                    // Surface
                    glPushMatrix();
                        _surface_materials[_surface_selected_material[_ps_selected_surface_index]].Apply();

                        if (_ps_do_texture)
                        {
                            _surface_textures[_surface_selected_texture[_ps_selected_surface_index]]->bind();
                        }
                        else
                        {
                            _surface_textures[_surface_selected_texture[_ps_selected_surface_index]]->release();
                        }

                        _ps_image_of_pss[_ps_selected_surface_index]->Render(GL_TRIANGLES);
                    glPopMatrix();

                    _dirLightSurface->Disable();

                    glDisable(GL_TEXTURE_2D);
                    glDisable(GL_LIGHTING);
                }
                glPopMatrix();
            }
            if (_ps_selected_surface_index < _psc_count && _ps_image_of_pscs[_ps_selected_surface_index])
            {
                // Parametric surface curves
                glPushMatrix();
                    glColor3f(1.0f, 0.0f, 0.0f);
                    _ps_image_of_pscs[_ps_selected_surface_index]->RenderDerivatives(0, GL_LINE_STRIP);
                glPopMatrix();

                // Object
                glPushMatrix();
                    glEnable(GL_LIGHTING);
                    _dirLightSurface->Enable();
                    MatFBRuby.Apply();
                    glMultMatrixd(_ps_transformation);
                    glTranslated(0.0f, 0.45f, 0.0f);
                    glScaled(1.0f, 1.0f, 1.0f);
                    _surface_rat_model.Render();
                    _dirLightSurface->Disable();
                    glDisable(GL_LIGHTING);
                glPopMatrix();
            }
            break;
        case 3:
            // Patch Magic
            glPushMatrix();
                glEnable(GL_NORMALIZE);
                glEnable(GL_LIGHTING);
                _dirLightPatch->Enable();
                glPushMatrix();
                    if (_patch_before_interpolation && _patch_do_before)
                    {
                        MatFBRuby.Apply();
                        _patch_before_interpolation->Render();
                    }

                    if (_patch_after_interpolation && _patch_do_after)
                    {
                        glEnable(GL_BLEND);
                        glDepthMask(GL_FALSE);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                            MatFBTurquoise.Apply();
                            _patch_after_interpolation->Render();
                        glDepthMask(GL_TRUE);
                        glDisable(GL_BLEND);
                    }
                glPopMatrix();
                _dirLightPatch->Disable();
                glDisable(GL_LIGHTING);
                glDisable(GL_NORMALIZE);

                // Isoparametric lines
                glPushMatrix();
                    // Before interpolation
                    if (_patch_buip)
                    {
                        for (GLuint i = 0; i < _patch_buip->GetColumnCount(); i++)
                        {
                            GenericCurve3 *curve = (*_patch_buip)[i];
                            if (curve)
                            {
                                if (_patch_do_uip_0)
                                {
                                    glColor3f(1.0f, 0.0f, 1.0f);
                                    curve->RenderDerivatives(0, GL_LINE_STRIP);
                                }

                                if (_patch_do_uip_1)
                                {
                                    glColor3f(1.0f, 1.0f, 0.0f);
                                    curve->RenderDerivatives(1, GL_LINE_STRIP);
                                    glColor3f(1.0f, 0.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(1, GL_POINTS);
                                    glPointSize(1.0f);
                                }

                                if (_patch_do_uip_2)
                                {
                                    glColor3f(1.0f, 1.0f, 1.0f);
                                    curve->RenderDerivatives(2, GL_LINES);
                                    glColor3f(0.0f, 1.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(2, GL_POINTS);
                                    glPointSize(1.0f);
                                }
                            }
                        }
                    }
                    if (_patch_bvip)
                    {
                        for (GLuint i = 0; i < _patch_bvip->GetColumnCount(); i++)
                        {
                            GenericCurve3 *curve = (*_patch_bvip)[i];
                            if (curve)
                            {
                                if (_patch_do_vip_0)
                                {
                                    glColor3f(1.0f, 0.0f, 1.0f);
                                    curve->RenderDerivatives(0, GL_LINE_STRIP);
                                }

                                if (_patch_do_vip_1)
                                {
                                    glColor3f(1.0f, 1.0f, 0.0f);
                                    curve->RenderDerivatives(1, GL_LINE_STRIP);
                                    glColor3f(1.0f, 0.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(1, GL_POINTS);
                                    glPointSize(1.0f);
                                }

                                if (_patch_do_vip_2)
                                {
                                    glColor3f(1.0f, 1.0f, 1.0f);
                                    curve->RenderDerivatives(2, GL_LINES);
                                    glColor3f(0.0f, 1.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(2, GL_POINTS);
                                    glPointSize(1.0f);
                                }
                            }
                        }
                    }

                    // After interpolation
                    if (_patch_auip)
                    {
                        for (GLuint i = 0; i < _patch_auip->GetColumnCount(); i++)
                        {
                            GenericCurve3 *curve = (*_patch_auip)[i];
                            if (curve)
                            {
                                if (_patch_do_uip_0)
                                {
                                    glColor3f(1.0f, 0.0f, 1.0f);
                                    curve->RenderDerivatives(0, GL_LINE_STRIP);
                                }

                                if (_patch_do_uip_1)
                                {
                                    glColor3f(1.0f, 1.0f, 0.0f);
                                    curve->RenderDerivatives(1, GL_LINE_STRIP);
                                    glColor3f(1.0f, 0.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(1, GL_POINTS);
                                    glPointSize(1.0f);
                                }

                                if (_patch_do_uip_2)
                                {
                                    glColor3f(1.0f, 1.0f, 1.0f);
                                    curve->RenderDerivatives(2, GL_LINES);
                                    glColor3f(0.0f, 1.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(2, GL_POINTS);
                                    glPointSize(1.0f);
                                }
                            }
                        }
                    }
                    if (_patch_avip)
                    {
                        for (GLuint i = 0; i < _patch_avip->GetColumnCount(); i++)
                        {
                            GenericCurve3 *curve = (*_patch_avip)[i];
                            if (curve)
                            {
                                if (_patch_do_vip_0)
                                {
                                    glColor3f(1.0f, 0.0f, 1.0f);
                                    curve->RenderDerivatives(0, GL_LINE_STRIP);
                                }

                                if (_patch_do_vip_1)
                                {
                                    glColor3f(1.0f, 1.0f, 0.0f);
                                    curve->RenderDerivatives(1, GL_LINE_STRIP);
                                    glColor3f(1.0f, 0.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(1, GL_POINTS);
                                    glPointSize(1.0f);
                                }

                                if (_patch_do_vip_2)
                                {
                                    glColor3f(1.0f, 1.0f, 1.0f);
                                    curve->RenderDerivatives(2, GL_LINES);
                                    glColor3f(0.0f, 1.0f, 0.0f);
                                    glPointSize(2.0f);
                                    curve->RenderDerivatives(2, GL_POINTS);
                                    glPointSize(1.0f);
                                }
                            }
                        }
                    }

                glPopMatrix();
            glPopMatrix();
            break;
        case 4:
            glPushMatrix();
            // Arc
                if(_arc && _arc_do_arc)
                {
                    glColor3f(1.0f, 0.0f, 0.0f);
                    _arc->RenderData(GL_LINE_STRIP);
                    glPointSize(10.0f);
                    _arc->RenderData(GL_POINTS);
                    glPointSize(1.0f);
                }

                if (_arc_image_of_arc)
                {
                    if (_arc_do_arc_0)
                    {
                        glColor3f(0.0f, 1.0f, 1.0f);
                        _arc_image_of_arc->RenderDerivatives(0, GL_LINE_STRIP);
                    }

                    if (_arc_do_arc_1)
                    {
                        glColor3f(1.0f, 0.0f, 1.0f);
                        _arc_image_of_arc->RenderDerivatives(1, GL_LINES);
                        _arc_image_of_arc->RenderDerivatives(1, GL_POINTS);
                    }

                    if (_arc_do_arc_2)
                    {
                        glColor3f(1.0f, 1.0f, 1.0f);
                        _arc_image_of_arc->RenderDerivatives(2, GL_LINES);
                        _arc_image_of_arc->RenderDerivatives(2, GL_POINTS);
                    }
                }
            glPopMatrix();
            break;
        }
        if (_shader_do_shader) _shaders[_shader_index].Disable();

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
    // Race
    void GLWidget::_animate0()
    {
        GLuint selected_object_index = 0;
        DCoordinate3 _t;
        DCoordinate3 der1;
        DCoordinate3 der2;

        if (_time_index[selected_object_index] >= _div[selected_object_index])
        {
            _time_index[selected_object_index] = 0;
        }

        if (selected_object_index >= _icc_count)
        {
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
        }
        else
        {
            if (!_img_iccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
            {
                throw Exception("Exception: Could not get derivative");
            }
        }

        _time_index[selected_object_index] += _cc_speed2[selected_object_index];

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

        if (_time_index[selected_object_index] >= _div[selected_object_index])
        {
            _time_index[selected_object_index] = 0;
        }

        if (selected_object_index >= _icc_count)
        {
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
        }
        else
        {
            if (!_img_iccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
            {
                throw Exception("Exception: Could not get derivative");
            }
        }

        _time_index[selected_object_index] += _cc_speed2[selected_object_index];

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

        if (_time_index[selected_object_index] >= _div[selected_object_index])
        {
            _time_index[selected_object_index] = 0;
        }

        if (selected_object_index >= _icc_count)
        {
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
        }
        else
        {
            if (!_img_iccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
            {
                throw Exception("Exception: Could not get derivative");
            }
        }

        _time_index[selected_object_index] += _cc_speed2[selected_object_index];

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

        if (_time_index[selected_object_index] >= _div[selected_object_index])
        {
            _time_index[selected_object_index] = 0;
        }

        if (selected_object_index >= _icc_count)
        {
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
        }
        else
        {
            if (!_img_iccs[selected_object_index]->GetDerivative(0, _time_index[selected_object_index], _t))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(1, _time_index[selected_object_index], der1))
            {
                throw Exception("Exception: Could not get derivative");
            }

            if (!_img_iccs[selected_object_index]->GetDerivative(2, _time_index[selected_object_index], der2))
            {
                throw Exception("Exception: Could not get derivative");
            }
        }

        _time_index[selected_object_index] += _cc_speed2[selected_object_index];

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

    void GLWidget::_animatePassanger0()
    {
        GLuint selected_object_index = 0;
        GLuint model_index = _race_moving_scene[selected_object_index].id + 1;

        GLfloat *vertex = _race_moving_models[model_index].MapVertexBuffer(GL_READ_WRITE);
        GLfloat *normal = _race_moving_models[model_index].MapNormalBuffer(GL_READ_ONLY);

        _angles[selected_object_index] += DEG_TO_RADIAN;
        if (_angles[selected_object_index] >= TWO_PI)
                _angles[selected_object_index] -= TWO_PI;

        GLfloat scale = sin(_angles[selected_object_index]) / 3000.0;
        for (GLuint i = 0; i < _race_moving_models[model_index].VertexCount(); ++i)
        {
            for (GLuint coordinate = 0; coordinate < 3; ++coordinate, ++vertex, ++normal)
                *vertex += scale * (*normal);
        }
        _race_moving_models[model_index].UnmapVertexBuffer();
        _race_moving_models[model_index].UnmapNormalBuffer();

        update();
    }

    void GLWidget::_animatePassanger1()
    {
        GLuint selected_object_index = 1;
        GLuint model_index = _race_moving_scene[selected_object_index].id + 1;

        GLfloat *vertex = _race_moving_models[model_index].MapVertexBuffer(GL_READ_WRITE);
        GLfloat *normal = _race_moving_models[model_index].MapNormalBuffer(GL_READ_ONLY);

        _angles[selected_object_index] += DEG_TO_RADIAN;
        if (_angles[selected_object_index] >= TWO_PI)
                _angles[selected_object_index] -= TWO_PI;

        GLfloat scale = sin(_angles[selected_object_index]) / 3000.0;
        for (GLuint i = 0; i < _race_moving_models[model_index].VertexCount(); ++i)
        {
            for (GLuint coordinate = 0; coordinate < 3; ++coordinate, ++vertex, ++normal)
                *vertex += scale * (*normal);
        }
        _race_moving_models[model_index].UnmapVertexBuffer();
        _race_moving_models[model_index].UnmapNormalBuffer();

        update();
    }

    void GLWidget::_animatePassanger2()
    {
        GLuint selected_object_index = 2;
        GLuint model_index = _race_moving_scene[selected_object_index].id + 1;

        GLfloat *vertex = _race_moving_models[model_index].MapVertexBuffer(GL_READ_WRITE);
        GLfloat *normal = _race_moving_models[model_index].MapNormalBuffer(GL_READ_ONLY);

        _angles[selected_object_index] += DEG_TO_RADIAN;
        if (_angles[selected_object_index] >= TWO_PI)
                _angles[selected_object_index] -= TWO_PI;

        GLfloat scale = sin(_angles[selected_object_index]) / 3000.0;
        for (GLuint i = 0; i < _race_moving_models[model_index].VertexCount(); ++i)
        {
            for (GLuint coordinate = 0; coordinate < 3; ++coordinate, ++vertex, ++normal)
                *vertex += scale * (*normal);
        }
        _race_moving_models[model_index].UnmapVertexBuffer();
        _race_moving_models[model_index].UnmapNormalBuffer();

        update();
    }

    void GLWidget::_animatePassanger3()
    {
        GLuint selected_object_index = 3;
        GLuint model_index = _race_moving_scene[selected_object_index].id + 1;

        GLfloat *vertex = _race_moving_models[model_index].MapVertexBuffer(GL_READ_WRITE);
        GLfloat *normal = _race_moving_models[model_index].MapNormalBuffer(GL_READ_ONLY);

        _angles[selected_object_index] += DEG_TO_RADIAN;
        if (_angles[selected_object_index] >= TWO_PI)
                _angles[selected_object_index] -= TWO_PI;

        GLfloat scale = sin(_angles[selected_object_index]) / 3000.0;
        for (GLuint i = 0; i < _race_moving_models[model_index].VertexCount(); ++i)
        {
            for (GLuint coordinate = 0; coordinate < 3; ++coordinate, ++vertex, ++normal)
                *vertex += scale * (*normal);
        }
        _race_moving_models[model_index].UnmapVertexBuffer();
        _race_moving_models[model_index].UnmapNormalBuffer();

        update();
    }

    // Surface
    void GLWidget::_animateSurface()
    {
        if (_ps_selected_surface_index < _psc_count)
        {
            DCoordinate3 point;
            DCoordinate3 diff_u;
            DCoordinate3 diff_v;

            switch (_ps_selected_surface_index)
            {
            case 0:
                point  = torusSurface::d00(_ps_u, _ps_v);
                diff_u = torusSurface::d10(_ps_u, _ps_v);
                diff_v = torusSurface::d01(_ps_u, _ps_v);
                break;
            case 1:
                point  = sphere::d00(_ps_u, _ps_v);
                diff_u = sphere::d10(_ps_u, _ps_v);
                diff_v = sphere::d01(_ps_u, _ps_v);
                break;
            case 2:
                point  = hyperboloid::d00(_ps_u, _ps_v);
                diff_u = hyperboloid::d10(_ps_u, _ps_v);
                diff_v = hyperboloid::d01(_ps_u, _ps_v);
                break;
            }

            DCoordinate3 normal = diff_u ^ diff_v;
            DCoordinate3 normal__diff_u = normal ^ diff_u;

            normal.normalize();
            diff_u.normalize();
            normal__diff_u.normalize();

            _ps_transformation[0] = diff_u[0];
            _ps_transformation[1] = diff_u[1];
            _ps_transformation[2] = diff_u[2];
            _ps_transformation[3] = 0;

            _ps_transformation[4] = normal[0];
            _ps_transformation[5] = normal[1];
            _ps_transformation[6] = normal[2];
            _ps_transformation[7] = 0;

            _ps_transformation[8]  = normal__diff_u[0];
            _ps_transformation[9]  = normal__diff_u[1];
            _ps_transformation[10] = normal__diff_u[2];
            _ps_transformation[11] = 0;

            _ps_transformation[12] = point[0];
            _ps_transformation[13] = point[1];
            _ps_transformation[14] = point[2];
            _ps_transformation[15] = 1;

            if (_ps_u >= _ps_umaxs[_ps_selected_surface_index])
            {
                _ps_u = _ps_umins[_ps_selected_surface_index];
            }

            _ps_u += 0.1 * DEG_TO_RADIAN;
            _ps_v = 3.0 * _ps_u;

            update();
        }
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
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);
        }
        else
        {
            emit set_cc_cp_values(_iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][0],
                                  _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][1],
                                  _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][2]);
            emit set_e(_e[_selected_cyclic_curve_index]);
        }

        emit set_speed(_cc_speed[_selected_cyclic_curve_index]);
        emit set_speed2(_cc_speed2[_selected_cyclic_curve_index]);
        emit set_points(_cc_points[_selected_cyclic_curve_index]);
        emit set_zeroth_derivative(_cc_zeroth_derivative[_selected_cyclic_curve_index]);
        emit set_first_derivative(_cc_first_derivative[_selected_cyclic_curve_index]);
        emit set_second_derivative(_cc_second_derivative[_selected_cyclic_curve_index]);
        emit surface_set_texture(_surface_selected_texture[_ps_selected_surface_index]);
        emit surface_set_material(_surface_selected_material[_ps_selected_surface_index]);

        update();
    }

    // Parametric curves
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

    // Race
    void GLWidget::race_set_selected_cyclic_curve_index(int value)
    {
        _selected_cyclic_curve_index = (GLuint)value;
        emit set_cc_cp_maxLimit(2 * _n[_selected_cyclic_curve_index]);
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);
        }
        else
        {
            emit set_cc_cp_values(_iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][0],
                                  _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][1],
                                  _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][2]);
            emit set_e(_e[_selected_cyclic_curve_index]);
        }
        emit set_speed(_cc_speed[_selected_cyclic_curve_index]);
        emit set_speed2(_cc_speed2[_selected_cyclic_curve_index]);
        emit set_points(_cc_points[_selected_cyclic_curve_index]);
        emit set_zeroth_derivative(_cc_zeroth_derivative[_selected_cyclic_curve_index]);
        emit set_first_derivative(_cc_first_derivative[_selected_cyclic_curve_index]);
        emit set_second_derivative(_cc_second_derivative[_selected_cyclic_curve_index]);

        update();
    }

    void GLWidget::race_set_selected_control_point(int value)
    {
        _selected_cylcic_curve_control_point_index = (GLuint)value;
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            emit set_cc_cp_values((*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1],
                                  (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2]);
        }
        else
        {
            emit set_cc_cp_values(_iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][0],
                                  _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][1],
                                  _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][2]);
            emit set_e(_e[_selected_cyclic_curve_index]);
        }
        update();
    }

    void GLWidget::race_move_X(double value)
    {
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][0] = value;
            _generateCyclicCurveImage(_selected_cyclic_curve_index);
            _updateCyclicCurveVBO(_selected_cyclic_curve_index);
            _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        else
        {
            _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][0] = value;
            _modifyInterpolatingCyclicCurve(_selected_cyclic_curve_index);
        }

        update();
    }

    void GLWidget::race_move_Y(double value)
    {
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][1] = value;
            _generateCyclicCurveImage(_selected_cyclic_curve_index);
            _updateCyclicCurveVBO(_selected_cyclic_curve_index);
            _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        else
        {
            _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][1] = value;
            _modifyInterpolatingCyclicCurve(_selected_cyclic_curve_index);
        }

        update();
    }

    void GLWidget::race_move_Z(double value)
    {
        if (_selected_cyclic_curve_index >= _icc_count)
        {
            (*_ccs[_selected_cyclic_curve_index])[_selected_cylcic_curve_control_point_index][2] = value;
            _generateCyclicCurveImage(_selected_cyclic_curve_index);
            _updateCyclicCurveVBO(_selected_cyclic_curve_index);
            _updateCyclicCurveImageVBO(_selected_cyclic_curve_index);
        }
        else
        {
            _iccs[_selected_cyclic_curve_index][_selected_cylcic_curve_control_point_index][2] = value;
            _modifyInterpolatingCyclicCurve(_selected_cyclic_curve_index);
        }

        update();
    }

    void GLWidget::edit_e(double value)
    {
        _e[_selected_cyclic_curve_index] = value;
        _modifyInterpolatingCyclicCurve(_selected_cyclic_curve_index);

        update();
    }

    void GLWidget::edit_speed2(double value)
    {
        _cc_speed2[_selected_cyclic_curve_index] = value;
        update();
    }

    void GLWidget::edit_speed(int value)
    {
        _cc_speed[_selected_cyclic_curve_index] = value;

        switch (_selected_cyclic_curve_index)
        {
        case 0:
            (*_timer0).setInterval(_cc_speed[0]);
            break;
        case 1:
            (*_timer1).setInterval(_cc_speed[1]);
            break;
        case 2:
            (*_timer2).setInterval(_cc_speed[2]);
            break;
        case 3:
            (*_timer3).setInterval(_cc_speed[3]);
            break;
        }


        update();
    }

    void GLWidget::cc_set_points(bool value)
    {
        _cc_points[_selected_cyclic_curve_index] = value;
        update();
    }

    void GLWidget::cc_set_zeroth_derivative(bool value)
    {
        _cc_zeroth_derivative[_selected_cyclic_curve_index] = value;
        update();
    }

    void GLWidget::cc_set_first_derivative(bool value)
    {
        _cc_first_derivative[_selected_cyclic_curve_index] = value;
        update();
    }

    void GLWidget::cc_set_second_derivative(bool value)
    {
        _cc_second_derivative[_selected_cyclic_curve_index] = value;
        update();
    }

    // Surfaces
    void GLWidget::ps_set_selected_parametric_surface_index(int value)
    {
        _ps_selected_surface_index = (GLuint)value;
        emit surface_set_texture(_surface_selected_texture[_ps_selected_surface_index]);
        emit surface_set_material(_surface_selected_material[_ps_selected_surface_index]);
        update();
    }

    void GLWidget::ps_set_texture(int value)
    {
       _surface_selected_texture[_ps_selected_surface_index] = value;
       update();
    }

    void GLWidget::ps_set_material(int value)
    {
       _surface_selected_material[_ps_selected_surface_index] = value;
       update();
    }

    void GLWidget::ps_set_texture_state(bool value)
    {
        _ps_do_texture = value;
        update();
    }

    // Patch
    void GLWidget::patch_set_before(bool value)
    {
        _patch_do_before = value;
        update();
    }

    void GLWidget::patch_set_after(bool value)
    {
        _patch_do_after = value;
        update();
    }

    void GLWidget::patch_set_uip_0(bool value)
    {
        _patch_do_uip_0 = value;
        update();
    }

    void GLWidget::patch_set_uip_1(bool value)
    {
        _patch_do_uip_1 = value;
        update();
    }

    void GLWidget::patch_set_uip_2(bool value)
    {
        _patch_do_uip_2 = value;
        update();
    }

    void GLWidget::patch_set_vip_0(bool value)
    {
        _patch_do_vip_0 = value;
        update();
    }

    void GLWidget::patch_set_vip_1(bool value)
    {
        _patch_do_vip_1 = value;
        update();
    }

    void GLWidget::patch_set_vip_2(bool value)
    {
        _patch_do_vip_2 = value;
        update();
    }

    // Arc
    void GLWidget::arc_set_arc(bool value)
    {
        _arc_do_arc = value;
        update();
    }

    void GLWidget::arc_set_arc_0(bool value)
    {
        _arc_do_arc_0 = value;
        update();
    }

    void GLWidget::arc_set_arc_1(bool value)
    {
        _arc_do_arc_1 = value;
        update();
    }

    void GLWidget::arc_set_arc_2(bool value)
    {
        _arc_do_arc_2 = value;
        update();
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
    // Parametric curves
    GLuint GLWidget::get_pc_count()
    {
        return (_pc_count > curve_tests::count ? curve_tests::count : _pc_count);
    }

    std::vector<std::string> GLWidget::get_test_names()
    {
        return curve_tests::names();
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
            _img_ccs[i] = _ccs[i]->GenerateImage(_mod, _div[i]);
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
                    if (_cc_points[i])
                    {
                        glColor3d(1.0f, 1.0f, 1.0f);
                        cc->RenderData(GL_LINE_LOOP);

                        glPointSize(10.0f);
                        cc->RenderData(GL_POINTS);
                        glPointSize(1.0f);
                    }
                }

                if (img_cc)
                {
                    if (_cc_zeroth_derivative[i])
                    {
                        glColor3d(1.0f, 0.0f, 0.0f);
                        img_cc->RenderDerivatives(0, GL_LINE_LOOP);
                    }

                    if (_cc_first_derivative[i])
                    {
                        glColor3d(0.0f, 1.0f, 0.0f);
                        img_cc->RenderDerivatives(1, GL_LINES);
                    }

                    if (_cc_second_derivative[i])
                    {
                        glColor3d(0.0f, 0.0f, 1.0f);
                        img_cc->RenderDerivatives(2, GL_LINES);
                    }
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
        void GLWidget::_modifyInterpolatingCyclicCurve(GLuint icc_iter)
        {
            if (icc_iter < _icc_count)
            {
                GLuint dimension = 2 * _n[icc_iter] + 1;
                GLdouble u_min, u_max;
                _ccs[icc_iter]->GetDefinitionDomain(u_min, u_max);

                ColumnMatrix<GLdouble> U(dimension);

                GLdouble total_length = 0.0, sumi = 0.0;
                for (GLuint j = 0; j < dimension; j++)
                {
                    DCoordinate3 temp = _iccs[icc_iter][(j + 1) % (dimension)] - _iccs[icc_iter][j];
                    total_length += pow(temp.length(), _e[icc_iter]);
                }

                U[0] = u_min;

                for (GLuint i = 1; i < dimension; i++)
                {
                    DCoordinate3 temp;

                    temp = _iccs[icc_iter][(i) % dimension] - _iccs[icc_iter][i-1];
                    sumi += pow(temp.length(), _e[icc_iter]);

                    U[i] = u_min + (sumi/total_length) * (u_max - u_min);
                }

                if (!_ccs[icc_iter]->UpdateDataForInterpolation(U, _iccs[icc_iter]))
                {
                    throw Exception("Could not update knot values");
                    return;
                }

                if (!_ccs[icc_iter]->UpdateVertexBufferObjectsOfData())
                {
                    throw Exception("Could not update vbos");
                    return;
                }

                if (_img_ccs[icc_iter])
                {
                    delete _img_ccs[icc_iter];
                    _img_ccs[icc_iter] = nullptr;
                }

                _img_ccs[icc_iter] = _ccs[icc_iter]->GenerateImage(_mod, _div[icc_iter]);

                if (!_img_ccs[icc_iter])
                {
                    throw Exception("Could not create img of selected curve");
                    return;
                }

                if (!_img_ccs[icc_iter]->UpdateVertexBufferObjects())
                {
                    throw Exception("Could not update img vbo of selected curve");
                    return;
                }

                _generateInterpolatingCyclicCurveImage(icc_iter);

                _updateInterpolatingCyclicCurveImageVBO(icc_iter);

                _renderAllExistingInterpolatingCyclicCurves();
            }
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
                if (!_ccs[icc_iter]->UpdateDataForInterpolation(U, _iccs[icc_iter]))
                {
                    throw Exception("Exception: Could not update data for interpolation");
                    break;
                }

                _generateInterpolatingCyclicCurveImage(icc_iter);

                _updateInterpolatingCyclicCurveImageVBO(icc_iter);

                icc_iter++;
            }
        }

        void GLWidget::_generateInterpolatingCyclicCurveImage(GLuint i)
        {
            _img_iccs[i] = _ccs[i]->GenerateImage(_mod, _div[i]);
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
            if (_cc_points[_selected_cyclic_curve_index])
            {
                glColor3d(1.0, 1.0, 0.0);
                glPointSize(10.0);
                glBegin(GL_POINTS);
                for (GLuint j = 0; j < _iccs[i].GetRowCount(); j++)
                {
                    glVertex3dv(&_iccs[i][j][0]);
                }
                glEnd();
                glPointSize(1.0);
            }

            if (_img_iccs[i])
            {
                if (_cc_zeroth_derivative[_selected_cyclic_curve_index])
                {
                    glColor3d(1.0, 0.0, 0.0);
                    _img_iccs[i]->RenderDerivatives(0, GL_LINE_LOOP);
                }

                if (_cc_first_derivative[_selected_cyclic_curve_index])
                {
                    glColor3d(0.0, 1.0, 0.0);
                    _img_iccs[i]->RenderDerivatives(1, GL_LINES);
                }

                if (_cc_second_derivative[_selected_cyclic_curve_index])
                {
                    glColor3d(0.0, 0.0, 1.0);
                    _img_iccs[i]->RenderDerivatives(2, GL_LINES);
                }
            }
        }

        void GLWidget::_renderAllExistingInterpolatingCyclicCurves()
        {
            for (GLuint i = 0; i < _icc_count; i++)
            {
                if (_cc_points[i])
                {
                    glColor3d(1.0, 1.0, 0.0);
                    glPointSize(10.0);
                    glBegin(GL_POINTS);
                    for (GLuint j = 0; j < _iccs[i].GetRowCount(); j++)
                    {
                        glVertex3dv(&_iccs[i][j][0]);
                    }
                    glEnd();
                    glPointSize(1.0);
                }

                if (_img_iccs[i])
                {
                    if (_cc_zeroth_derivative[i])
                    {
                        glColor3d(1.0, 0.0, 0.0);
                        _img_iccs[i]->RenderDerivatives(0, GL_LINE_LOOP);
                    }

                    if (_cc_first_derivative[i])
                    {
                        glColor3d(0.0, 1.0, 0.0);
                        _img_iccs[i]->RenderDerivatives(1, GL_LINES);
                    }

                    if (_cc_second_derivative[i])
                    {
                        glColor3d(0.0, 0.0, 1.0);
                        _img_iccs[i]->RenderDerivatives(2, GL_LINES);
                    }
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

        _moving_object_count = _cc_count;

        _e.resize(_cc_count, 1.0);
        _cc_speed.resize(_cc_count, 1.0);
        _cc_speed2.resize(_cc_count, 1.0);
        _div.resize(_cc_count, 100);
        _cc_points.resize(_cc_count, true);
        _cc_zeroth_derivative.resize(_cc_count, true);
        _cc_first_derivative.resize(_cc_count, false);
        _cc_second_derivative.resize(_cc_count, false);

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
    // Surfaces
    GLuint GLWidget::get_ps_count()
    {
        return (_ps_count > surface_tests::count ? surface_tests::count : _ps_count);
    }

    std::vector<std::string> GLWidget::get_surface_test_names()
    {
        return surface_tests::names();
    }

    void GLWidget::_createParametricSurfaces()
    {
        _ps_derivatives = RowMatrix<TriangularMatrix<ParametricSurface3::PartialDerivative>>(_ps_count);
        _pss = RowMatrix<ParametricSurface3 *>(_ps_count);
        _ps_image_of_pss = RowMatrix<TriangulatedMesh3 *>(_ps_count);
        _ps_umins.ResizeColumns(_ps_count);
        _ps_umaxs.ResizeColumns(_ps_count);
        _ps_vmins.ResizeColumns(_ps_count);
        _ps_vmaxs.ResizeColumns(_ps_count);

        _surface_selected_material.ResizeColumns(_ps_count);
        _surface_selected_texture.ResizeColumns(_ps_count);

        for (GLuint i = 0; i < _ps_count; i++)
            _ps_derivatives[i] = TriangularMatrix<ParametricSurface3::PartialDerivative>(3);

        GLdouble tmp_umin = 0, tmp_umax = 0, tmp_vmin = 0, tmp_vmax = 0;

        GLuint ps_iter = 0;
        while (ps_iter < _ps_count)
        {
            switch (ps_iter)
            {
            case 0:
                tmp_umin = torusSurface::u_min;
                tmp_umax = torusSurface::u_max;
                tmp_vmin = torusSurface::v_min;
                tmp_vmax = torusSurface::v_max;
                _ps_derivatives[ps_iter](0, 0) = torusSurface::d00;
                _ps_derivatives[ps_iter](1, 0) = torusSurface::d10;
                _ps_derivatives[ps_iter](1, 1) = torusSurface::d01;
                break;
            case 1:
                tmp_umin = sphere::u_min;
                tmp_umax = sphere::u_max;
                tmp_vmin = sphere::v_min;
                tmp_vmax = sphere::v_max;
                _ps_derivatives[ps_iter](0, 0) = sphere::d00;
                _ps_derivatives[ps_iter](1, 0) = sphere::d10;
                _ps_derivatives[ps_iter](1, 1) = sphere::d01;
                break;
            case 2:
                tmp_umin = hyperboloid::u_min;
                tmp_umax = hyperboloid::u_max;
                tmp_vmin = hyperboloid::v_min;
                tmp_vmax = hyperboloid::v_max;
                _ps_derivatives[ps_iter](0, 0) = hyperboloid::d00;
                _ps_derivatives[ps_iter](1, 0) = hyperboloid::d10;
                _ps_derivatives[ps_iter](1, 1) = hyperboloid::d01;
                break;
            case 3:
                tmp_umin = plane::u_min;
                tmp_umax = plane::u_max;
                tmp_vmin = plane::v_min;
                tmp_vmax = plane::v_max;
                _ps_derivatives[ps_iter](0, 0) = plane::d00;
                _ps_derivatives[ps_iter](1, 0) = plane::d10;
                _ps_derivatives[ps_iter](1, 1) = plane::d01;
                break;
            case 4:
                tmp_umin = cone::u_min;
                tmp_umax = cone::u_max;
                tmp_vmin = cone::v_min;
                tmp_vmax = cone::v_max;
                _ps_derivatives[ps_iter](0, 0) = cone::d00;
                _ps_derivatives[ps_iter](1, 0) = cone::d10;
                _ps_derivatives[ps_iter](1, 1) = cone::d01;
                break;
            case 5:
                tmp_umin = cylinder::u_min;
                tmp_umax = cylinder::u_max;
                tmp_vmin = cylinder::v_min;
                tmp_vmax = cylinder::v_max;
                _ps_derivatives[ps_iter](0, 0) = cylinder::d00;
                _ps_derivatives[ps_iter](1, 0) = cylinder::d10;
                _ps_derivatives[ps_iter](1, 1) = cylinder::d01;
                break;
            }

            _ps_umins[ps_iter] = tmp_umin;
            _ps_umaxs[ps_iter] = tmp_umax;
            _ps_vmins[ps_iter] = tmp_vmin;
            _ps_vmaxs[ps_iter] = tmp_vmax;
            _pss[ps_iter] = new (nothrow) ParametricSurface3(_ps_derivatives[ps_iter], tmp_umin, tmp_umax, tmp_vmin, tmp_vmax);

            if (!_pss[ps_iter])
            {
                throw Exception("Exception: Could not create parametric surface");
                _destroyAllExistingParametricSurfaces();
                ps_iter = 0;
            }
            else
            {
                ps_iter++;
            }
        }

        // Loading da rat
        if (_surface_rat_model.LoadFromOFF("Models/Characters/mouse.off", GL_TRUE))
        {
            if(!_surface_rat_model.UpdateVertexBufferObjects())
            {
                throw Exception("Exception: Could not load da rat model");
                return;
            }
        }
    }

    void GLWidget::_createParametricSurfaceCurves()
    {
        _psc_derivatives = RowMatrix<RowMatrix<ParametricCurve3::Derivative>>(_psc_count);
        _pscs = RowMatrix<ParametricCurve3 *>(_psc_count);
        _ps_image_of_pscs = RowMatrix<GenericCurve3 *>(_psc_count);

        for (GLuint i = 0; i < _psc_count; i++)
            _psc_derivatives[i] = RowMatrix<ParametricCurve3::Derivative>(3);

        GLdouble tmp_min = 0, tmp_max = 0;

        GLuint psc_iter = 0;
        while (psc_iter < _psc_count)
        {
            switch (psc_iter)
            {
            case 0:
                tmp_min = torusSurface::u_min;
                tmp_max = torusSurface::u_max;
                _psc_derivatives[psc_iter][0] = torusSurface::d0;
                _psc_derivatives[psc_iter][1] = torusSurface::d1;
                _psc_derivatives[psc_iter][2] = torusSurface::d2;
                break;
            case 1:
                tmp_min = sphere::u_min;
                tmp_max = sphere::u_max;
                _psc_derivatives[psc_iter][0] = sphere::d0;
                _psc_derivatives[psc_iter][1] = sphere::d1;
                _psc_derivatives[psc_iter][2] = sphere::d2;
                break;
            case 2:
                tmp_min = hyperboloid::u_min;
                tmp_max = hyperboloid::u_max;
                _psc_derivatives[psc_iter][0] = hyperboloid::d0;
                _psc_derivatives[psc_iter][1] = hyperboloid::d1;
                _psc_derivatives[psc_iter][2] = hyperboloid::d2;
                break;
            }
            _pscs[psc_iter] = new (nothrow) ParametricCurve3(_psc_derivatives[psc_iter], tmp_min, tmp_max);

            if (!_pscs[psc_iter])
            {
                throw Exception("Exception: Could not create parametric surface curve");
                _destroyAllExistingParametricSurfaceCurves();
                psc_iter = 0;
            }
            else
            {
                psc_iter++;
            }
        }
    }

    void GLWidget::_generateParametricSurfaceImage(GLuint i)
    {
        _ps_image_of_pss[i] = _pss[i]->GenerateImage(_ps_udiv_point_count, _ps_vdiv_point_count, _ps_usage_flag);

        if (!_ps_image_of_pss[i])
        {
            throw Exception("Exception: Could not generate image of the parametric surface");
            _destroyAllExistingParametricSurfacesImages();
        }
    }

    void GLWidget::_generateParametricSurfaceCurveImage(GLuint i)
    {
        _ps_image_of_pscs[i] = _pscs[i]->GenerateImage(_ps_udiv_point_count, _ps_usage_flag);

        if (!_ps_image_of_pscs[i])
        {
            throw Exception("Exception: Could not generate image of the parametric surface curve");
            _destroyAllExistingParametricSurfaceCurvesImages();
        }
    }

    void GLWidget::_updateParametricSurfaceVBO(GLuint i)
    {
        if (!_ps_image_of_pss[i]->UpdateVertexBufferObjects(_ps_usage_flag))
        {
            throw Exception("Exception: Could not generate VBOs of the parametric surface");
            _destroyAllExistingParametricSurfacesImages();
        }
    }

    void GLWidget::_updateParametricSurfaceCurveVBO(GLuint i)
    {
        if (!_ps_image_of_pscs[i]->UpdateVertexBufferObjects(_ps_usage_flag))
        {
            throw Exception("Exception: Could not generate VBOs of the parametric surface curve");
            _destroyAllExistingParametricSurfaceCurvesImages();
        }
    }

    void GLWidget::_destroyAllExistingParametricSurfaces()
    {
        for (GLuint i = 0; i < _ps_count; i++)
        {
             if (_pss[i])
             {
                 delete _pss[i]; _pss[i] = nullptr;
             }
        }
    }

    void GLWidget::_destroyAllExistingParametricSurfacesImages()
    {
        for (GLuint i = 0; i < _ps_count; i++)
        {
            if (_ps_image_of_pss[i])
            {
                delete _ps_image_of_pss[i]; _ps_image_of_pss[i] = nullptr;
            }
        }
    }

    void GLWidget::_destroyAllExistingParametricSurfaceCurves()
    {
        for (GLuint i = 0; i < _psc_count; i++)
        {
             if (_pscs[i])
             {
                 delete _pscs[i]; _pscs[i] = nullptr;
             }
        }
    }

    void GLWidget::_destroyAllExistingParametricSurfaceCurvesImages()
    {
        for (GLuint i = 0; i < _psc_count; i++)
        {
            if (_ps_image_of_pscs[i])
            {
                delete _ps_image_of_pscs[i]; _ps_image_of_pscs[i] = nullptr;
            }
        }
    }

    void GLWidget::_getSurfaceTextures() {
        _surface_texture_paths.ResizeColumns(14);
        _surface_texture_paths[0] = "Textures/texture_01.jpg";
        _surface_texture_paths[1] = "Textures/texture_02.jpg";
        _surface_texture_paths[2] = "Textures/texture_03.jpg";
        _surface_texture_paths[3] = "Textures/texture_04.jpg";
        _surface_texture_paths[4] = "Textures/texture_05.jpg";
        _surface_texture_paths[5] = "Textures/texture_06.jpg";
        _surface_texture_paths[6] = "Textures/texture_07.jpg";
        _surface_texture_paths[7] = "Textures/texture_08.jpg";
        _surface_texture_paths[8] = "Textures/texture_09.jpg";
        _surface_texture_paths[9] = "Textures/texture_10.jpg";
        _surface_texture_paths[10] = "Textures/texture_11.jpg";
        _surface_texture_paths[11] = "Textures/texture_12.jpg";
        _surface_texture_paths[12] = "Textures/texture_13.jpg";
        _surface_texture_paths[13] = "Textures/texture_14.jpg";

        _surface_textures.ResizeColumns(_surface_texture_paths.GetColumnCount());

        for(GLuint i = 0; i < _surface_texture_paths.GetColumnCount(); i++)
        {
            _surface_textures[i] = new QOpenGLTexture(QImage(_surface_texture_paths[i]).mirrored());
            _surface_textures[i]->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
            _surface_textures[i]->setMagnificationFilter(QOpenGLTexture::Linear);
        }
    }


    //-----------
    // Patch Magic
    void GLWidget::_createPatch()
    {
        _patch = SecondOrderTrigonometricPatch3(1.0, 1.0);
//        _patch = SecondOrderTrigonometricPatch3(0.5, 0.5);

        for (GLuint i = 0; i < 4; i++)
            for (GLuint j = 0; j < 4; j++)
                _patch.SetData(i, j, _patch_data[i][j][0], _patch_data[i][j][1], _patch_data[i][j][2]);

        _patch_before_interpolation = _patch.GenerateImage(_patch_udiv_point_count, _patch_vdiv_point_count, _patch_usage_flag);

        if (_patch_before_interpolation)
            _patch_before_interpolation->UpdateVertexBufferObjects();

        // Define interpolation problem
        // 1: create knot-vector in dir. u
        RowMatrix<GLdouble> u_knot_vector(4);
        u_knot_vector(0) = 0.0;
        u_knot_vector(1) = 1.0 / 3.0;
        u_knot_vector(2) = 2.0 / 3.0;
        u_knot_vector(3) = 1.0;

        // 2: create knot-vector in dir. v
        ColumnMatrix<GLdouble> v_knot_vector(4);
        v_knot_vector(0) = 0.0;
        v_knot_vector(1) = 1.0 / 3.0;
        v_knot_vector(2) = 2.0 / 3.0;
        v_knot_vector(3) = 1.0;

        // Before interpolation
        _patch_buip = _patch.GenerateUIsoparametricLines(_patch_uip_point_count, 1, _patch_udiv_point_count, _patch_usage_flag);
        _patch_bvip = _patch.GenerateVIsoparametricLines(_patch_vip_point_count, 1, _patch_vdiv_point_count, _patch_usage_flag);

        if (_patch_buip)
        {
            for (GLuint i = 0; i < _patch_buip->GetColumnCount(); ++i)
            {
                if ((*_patch_buip)[i])
                {
                    (*_patch_buip)[i]->UpdateVertexBufferObjects();
                }
            }
        }

        if (_patch_bvip)
        {
            for (GLuint i = 0; i < _patch_bvip->GetColumnCount(); ++i)
            {
                if ((*_patch_bvip)[i])
                {
                    (*_patch_bvip)[i]->UpdateVertexBufferObjects();
                }
            }
        }

        // 3: define data-point matrix (e.g. set them to the original control points)
        Matrix<DCoordinate3> data_points_to_interpolate(4, 4);
        for (GLuint row = 0; row < 4; ++row)
            for (GLuint column = 0; column < 4; ++column)
                _patch.GetData(row, column, data_points_to_interpolate(row, column));

        // 4: solve the problem, generate mesh of interpolating patch
        if (_patch.UpdateDataForInterpolation(u_knot_vector, v_knot_vector, data_points_to_interpolate))
        {
            _patch_after_interpolation = _patch.GenerateImage(_patch_udiv_point_count, _patch_vdiv_point_count, _patch_usage_flag);

            if (_patch_after_interpolation)
                _patch_after_interpolation->UpdateVertexBufferObjects();
        }

        // After interpolation
        _patch_auip = _patch.GenerateUIsoparametricLines(_patch_uip_point_count, 1, _patch_udiv_point_count, _patch_usage_flag);
        _patch_avip = _patch.GenerateVIsoparametricLines(_patch_vip_point_count, 1, _patch_vdiv_point_count, _patch_usage_flag);

        if (_patch_auip)
        {
            for (GLuint i = 0; i < _patch_auip->GetColumnCount(); ++i)
            {
                if ((*_patch_auip)[i])
                {
                    (*_patch_auip)[i]->UpdateVertexBufferObjects();
                }
            }
        }

        if (_patch_avip)
        {
            for (GLuint i = 0; i < _patch_avip->GetColumnCount(); ++i)
            {
                if ((*_patch_avip)[i])
                {
                    (*_patch_avip)[i]->UpdateVertexBufferObjects();
                }
            }
        }
    }


    //-----------
    // Arc
    void GLWidget::_createArc()
    {
        _arc = new (nothrow) SecondOrderTrigonometricArc3(PI);
        if (!_arc)
        {
            delete _arc, _arc = nullptr;
            throw Exception("Exception: Could not create arc");
        }

        (*_arc)[0] = DCoordinate3(-1.0f, 0.0f, -1.0f);
        (*_arc)[1] = DCoordinate3(0.0f, 2.0f, 0.0f);
        (*_arc)[2] = DCoordinate3(1.0f, 2.0f, 0.0f);
        (*_arc)[3] = DCoordinate3(2.0f, 0.0f, -1.0f);

        _arc->UpdateVertexBufferObjectsOfData();

        _arc_image_of_arc = _arc->GenerateImage(2, _arc_div_point_count, _arc_usage_flag);

        if (!_arc_image_of_arc)
        {
            delete _arc_image_of_arc, _arc_image_of_arc = nullptr;
            throw Exception("Exception: Could not generate image of arc");
        }

        if (!_arc_image_of_arc->UpdateVertexBufferObjects(1.0, _arc_usage_flag))
        {
            delete _arc_image_of_arc, _arc_image_of_arc = nullptr;
            throw Exception("Exception: Could not generate VBOs of arc");
        }
    }


    //-----------
    // Shaders
    void GLWidget::_getShaders()
    {
        _shaders.ResizeColumns(4);

        try
        {
            if (!_shaders[0].InstallShaders("Shaders/directional_light.vert", "Shaders/directional_light.frag", GL_TRUE))
            {
                throw Exception("Could not install shaders");
            }
            if (!_shaders[1].InstallShaders("Shaders/two_sided_lighting.vert", "Shaders/two_sided_lighting.frag", GL_TRUE))
            {
                throw Exception("Could not install shaders");
            }
            if (!_shaders[2].InstallShaders("Shaders/toon.vert", "Shaders/toon.frag", GL_TRUE))
            {
                throw Exception("Could not install shaders");
            } else {
                _shaders[2].Enable();
                _shaders[2].SetUniformVariable4f("default_outline_color", _shader_scale, _shader_smoothing, _shader_shading, _shader_intensity);
                _shaders[2].Disable();
            }
            if (!_shaders[3].InstallShaders("Shaders/reflection_lines.vert", "Shaders/reflection_lines.frag", GL_TRUE))
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
        _destroyAllExistingParametricCurves();
        _destroyAllExistingParametricCurvesImages();
        _destroyAllExistingObjects();
        _destroyAllExistingCyclicCurves();
        _destroyAllExistingCyclicCurvesImages();
        _destroyAllExistingInterpolatingCyclicCurves();
        _destroyAllExistingInterpolatingCyclicCurvesImages();
        _destroyAllExistingParametricSurfaces();
        _destroyAllExistingParametricSurfacesImages();
        _destroyAllExistingParametricSurfaceCurves();
        _destroyAllExistingParametricSurfaceCurvesImages();
        if (_dirLightRace)
        {
            delete _dirLightRace; _dirLightRace = nullptr;
        }
        if (_dirLightSurface)
        {
            delete _dirLightSurface; _dirLightSurface = nullptr;
        }
        if (_dirLightPatch)
        {
            delete _dirLightPatch; _dirLightPatch = nullptr;
        }
        if (_arc)
        {
            delete _arc; _arc = nullptr;
        }
        if (_arc_image_of_arc)
        {
            delete _arc_image_of_arc; _arc_image_of_arc = nullptr;
        }
        if (_patch_before_interpolation)
        {
            delete _patch_before_interpolation, _patch_before_interpolation = nullptr;
        }
        if (_patch_after_interpolation)
        {
            delete _patch_after_interpolation, _patch_after_interpolation = nullptr;
        }
    }
}
