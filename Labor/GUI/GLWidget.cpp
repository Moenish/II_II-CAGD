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

            break;
        case 1:
            // Patches

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

        update();
    }

    // Project

    // Arcs

    // Patches


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
    }

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
        if (_dirLight)
        {
            delete _dirLight; _dirLight = nullptr;
        }
    }
}
