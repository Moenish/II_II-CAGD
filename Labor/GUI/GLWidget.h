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
#include <Core/Colors4.h>
#include <Core/ShaderPrograms.h>
#include <Trigonometric/SecondOrderTrigonometricCompositeCurve3.h>
#include <Trigonometric/CompositeTrigonometricPatch.h>

namespace cagd
{
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


            // Arcs
                SecondOrderTrigonometricCompositeCurve3     _sotc_arc;
                GLdouble            _sotc_arc_alpha;
                GLdouble            _sotc_arc_scale;
                GLuint              _sotc_arc_DivCount;

                bool                _sotc_arc_do_first_derivatives = false;
                bool                _sotc_arc_do_second_derivatives = false;
                GLuint              _sotc_arc_selected_arc = 0;
                GLuint              _sotc_arc_selected_cp = 0;

            // Patches
                std::vector<DCoordinate3>                   _sotc_patch_general_shape;
                CompositeTrigonometricPatch                 _sotc_patch;
                GLdouble            _sotc_patch_alpha_U;
                GLdouble            _sotc_patch_alpha_V;
                GLdouble            _sotc_patch_scale;

                GLuint              _sotc_patch_isoparametric_DivCount_U;
                GLuint              _sotc_patch_isoparametric_DivCount_V;
                GLuint              _sotc_patch_isoparametric_LineCount_U;
                GLuint              _sotc_patch_isoparametric_LineCount_V;

                bool                _sotc_patch_do_normal = false;
                bool                _sotc_patch_do_first_derivatives = false;
                bool                _sotc_patch_do_second_derivatives = false;
                GLuint              _sotc_patch_selected_patch = 0;
                GLuint              _sotc_patch_selected_row = 0;
                GLuint              _sotc_patch_selected_col = 0;
                GLuint              _sotc_patch_selected_material = 0;
                GLuint              _sotc_patch_selected_texture = 0;
                bool                _sotc_patch_do_texture = false;



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
                void arcInsertSetAlpha(double value);
                void arcInsertSetScale(double value);
                void arcInsertSetDivCount(int value);
                void arcInsertButtonCreate();

                void arcManipulateDoFirstDerivatives(bool value);
                void arcManipulateDoSecondDerivatives(bool value);
                void arcManipulateSetSelectedArc(int value);
                void arcManipulateSetSelectedCP(int value);
                void arcManipulateSet_X(double value);
                void arcManipulateSet_Y(double value);
                void arcManipulateSet_Z(double value);
                void arcManipulateSetTranslate_X(double value);
                void arcManipulateSetTranslate_Y(double value);
                void arcManipulateSetTranslate_Z(double value);
                void arcManipulateButtonDelete();

            // Patches
                void patchInsertSetAlpha_U(double value);
                void patchInsertSetAlpha_V(double value);
                void patchInsertSetScale(double value);
                void patchInsertButtonCreate();
                void patchInsertButtonSave();
                void patchInsertButtonLoad();

                void patchIsoparametricSetDivCount_U(double value);
                void patchIsoparametricSetDivCount_V(double value);
                void patchIsoparametricSetLineCount_U(double value);
                void patchIsoparametricSetLineCount_V(double value);

                void patchManipulateDoNormal(bool value);
                void patchManipulateDoFirstDerivatives(bool value);
                void patchManipulateDoSecondDerivatives(bool value);
                void patchManipulateSetSelectedPatch(int value);
                void patchManipulateSetSelectedRow(int value);
                void patchManipulateSetSelectedCol(int value);
                void patchManipulateSet_X(double value);
                void patchManipulateSet_Y(double value);
                void patchManipulateSet_Z(double value);
                void patchManipulateSetTranslate_X(double value);
                void patchManipulateSetTranslate_Y(double value);
                void patchManipulateSetTranslate_Z(double value);
                void patchManipulateSetSelectedMaterial(int value);
                void patchManipulateSetSelectedTexture(int value);
                void patchManipulateDoTexture(bool value);
                void patchManipulateButtonDelete();

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
