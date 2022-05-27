#pragma once

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <Parametric/ParametricCurves3.h>
#include <Parametric/ParametricSurfaces3.h>
#include <Cyclic/CyclicCurves3.h>
#include <Core/GenericCurves3.h>
#include <Core/TriangulatedMeshes3.h>
#include <Core/Materials.h>
#include <Core/Lights.h>
#include <Core/ShaderPrograms.h>
#include <Trigonometric/SecondOrderTrigonometricPatch3.h>
#include <Trigonometric/SecondOrderTrigonometricArc3.h>

namespace cagd
{
    struct ModelProperties
    {
        GLuint          id;
        GLint           material_id;
        DCoordinate3    position;
        GLdouble        angle1[3];
        GLdouble        angle2[3];
        GLdouble        scale[3];
        GLdouble        color[3];

        inline friend std::istream& operator>>(std::istream& inStream, ModelProperties& modelP)
        {
            inStream >> modelP.id;
            inStream >> modelP.material_id;
            inStream >> modelP.position.x() >> modelP.position.y() >> modelP.position.z();
            inStream >> modelP.angle1[0] >> modelP.angle1[1] >> modelP.angle1[2];
            inStream >> modelP.angle2[0] >> modelP.angle2[1] >> modelP.angle2[2];
            inStream >> modelP.scale[0] >> modelP.scale[1] >> modelP.scale[2];
            inStream >> modelP.color[0] >> modelP.color[1] >> modelP.color[2];
            return inStream;
        }

        inline friend std::ostream& operator<<(std::ostream& outStream, ModelProperties& modelP)
        {
            outStream << modelP.id << std::endl;
            outStream << modelP.material_id << std::endl;
            outStream << modelP.position.x() << modelP.position.y() << modelP.position.z() << std::endl;
            outStream << modelP.angle1[0] << modelP.angle1[1] << modelP.angle1[2] << std::endl;
            outStream << modelP.angle2[0] << modelP.angle2[1] << modelP.angle2[2] << std::endl;
            outStream << modelP.scale[0] << modelP.scale[1] << modelP.scale[2] << std::endl;
            outStream << modelP.color[0] << modelP.color[1] << modelP.color[2] << std::endl;
            return outStream;
        }
    };

    class GLWidget: public QOpenGLWidget
    {
        Q_OBJECT
    private:
        // variables defining the projection matrix
        double       _aspect;            // aspect ratio of the rendering window
        double       _fovy;              // field of view in direction y
        double       _z_near, _z_far;    // distance of near and far clipping planes

        // variables defining the model-view matrix
        double       _eye[3], _center[3], _up[3];

        // variables needed by transformations
        int         _angle_x, _angle_y, _angle_z;
        double      _zoom;
        double      _trans_x, _trans_y, _trans_z;

        // your other declarations
        GLuint      _selected_page = 0;

        // Project
            DirectionalLight            *_dirLight = nullptr;

            Material                    _materials[6]{MatFBBrass, MatFBSilver, MatFBGold, MatFBEmerald, MatFBPearl, MatFBTurquoise};
            RowMatrix<GLuint>           _selected_material;
            RowMatrix<GLuint>           _selected_texture;
            RowMatrix<QString>          _texture_paths;
            RowMatrix<QOpenGLTexture*>  _textures;

            void                        _getTextures();


      // Shaders
            RowMatrix<ShaderProgram>    _shaders;
            GLuint                      _shader_index = 0;
            bool                        _shader_do_shader = false;
            GLfloat                     _shader_intensity = 1.0f;
            GLfloat                     _shader_scale       = 1.0f;
            GLfloat                     _shader_smoothing   = 1.0f;
            GLfloat                     _shader_shading     = 1.0f;

            void                    _getShaders();

    public:
        // special and default constructor
        // the format specifies the properties of the rendering window
        GLWidget(QWidget* parent = 0);

        // redeclared virtual functions
        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);

        // destructor
        ~GLWidget();

    private slots:

    public slots:
        // public event handling methods/slots
        void set_angle_x(int value);
        void set_angle_y(int value);
        void set_angle_z(int value);

        void set_zoom_factor(double value);

        void set_trans_x(double value);
        void set_trans_y(double value);
        void set_trans_z(double value);

        void set_selected_page(int value);

        // Project

        // Arcs

        // Patches

        // Shader
        void shader_set(int value);
        void shader_do(bool value);
        void shader_intensity(double value);
        void shader_scale(double value);
        void shader_shading(double value);
        void shader_smoothing(double value);

    signals:
        // Project

        // Arcs

        // Patches
    };
}
