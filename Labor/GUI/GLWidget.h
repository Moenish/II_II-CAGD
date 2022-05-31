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
#include <GUI/ArcContinueWindow.h>
#include <GUI/ArcJoinWindow.h>
#include <GUI/ArcMergeWindow.h>
#include <GUI/PatchContinueWindow.h>
#include <GUI/PatchJoinWindow.h>
#include <GUI/PatchMergeWindow.h>

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

            ArcContinueWindow           *_arcContinueWindow;
            ArcJoinWindow               *_arcJoinWindow;
            ArcMergeWindow              *_arcMergeWindow;
            PatchContinueWindow         *_patchContinueWindow;
            PatchJoinWindow             *_patchJoinWindow;
            PatchMergeWindow            *_patchMergeWindow;

            void                        _getTextures();

            // Arcs
                std::vector<SecondOrderTrigonometricCompositeCurve3::Direction> _sotc_arc_directions{
                            SecondOrderTrigonometricCompositeCurve3::Direction::LEFT,
                            SecondOrderTrigonometricCompositeCurve3::Direction::RIGHT};

                SecondOrderTrigonometricCompositeCurve3     _sotc_arc;

                GLdouble            _sotc_arc_alpha         = 1.0;
                GLdouble            _sotc_arc_scale         = 1.0;
                GLuint              _sotc_arc_DivCount      = 10;

                GLuint              _sotc_arc_selected_arc  = 0;
                GLuint              _sotc_arc_selected_cp   = 0;

                GLdouble            _sotc_arc_translate_previous_x = 0;
                GLdouble            _sotc_arc_translate_previous_y = 0;
                GLdouble            _sotc_arc_translate_previous_z = 0;

                GLuint              _sotc_arc_continue_arc          = 0;
                GLuint              _sotc_arc_continue_direction    = 0;

                GLuint              _sotc_arc_join_arc1             = 0;
                GLuint              _sotc_arc_join_arc2             = 0;
                GLuint              _sotc_arc_join_direction1       = 0;
                GLuint              _sotc_arc_join_direction2       = 0;

                GLuint              _sotc_arc_merge_arc1            = 0;
                GLuint              _sotc_arc_merge_arc2            = 0;
                GLuint              _sotc_arc_merge_direction1      = 0;
                GLuint              _sotc_arc_merge_direction2      = 0;

                bool                _sotc_arc_do_first_derivatives  = false;
                bool                _sotc_arc_do_second_derivatives = false;

            // Patches
                std::vector<CompositeTrigonometricPatch::Direction> _sotc_patch_directions{
                            CompositeTrigonometricPatch::Direction::N,
                            CompositeTrigonometricPatch::Direction::NE,
                            CompositeTrigonometricPatch::Direction::E,
                            CompositeTrigonometricPatch::Direction::SE,
                            CompositeTrigonometricPatch::Direction::S,
                            CompositeTrigonometricPatch::Direction::SW,
                            CompositeTrigonometricPatch::Direction::W,
                            CompositeTrigonometricPatch::Direction::NW};

                std::vector<DCoordinate3>                   _sotc_patch_general_shape;
                CompositeTrigonometricPatch                 _sotc_patch;

                GLdouble            _sotc_patch_alpha_U     = 1.0;
                GLdouble            _sotc_patch_alpha_V     = 1.0;
                GLdouble            _sotc_patch_scale       = 1.0;

                GLuint              _sotc_patch_isoparametric_DivCount_U    = 10;
                GLuint              _sotc_patch_isoparametric_DivCount_V    = 10;
                GLuint              _sotc_patch_isoparametric_LineCount_U   = 4;
                GLuint              _sotc_patch_isoparametric_LineCount_V   = 4;

                GLuint              _sotc_patch_selected_patch      = 0;
                GLuint              _sotc_patch_selected_row        = 0;
                GLuint              _sotc_patch_selected_col        = 0;
                GLuint              _sotc_patch_selected_material   = 0;
                GLuint              _sotc_patch_selected_texture    = 0;

                GLdouble            _sotc_patch_translate_previous_x = 0;
                GLdouble            _sotc_patch_translate_previous_y = 0;
                GLdouble            _sotc_patch_translate_previous_z = 0;

                GLuint              _sotc_patch_continue_patch      = 0;
                GLuint              _sotc_patch_continue_direction  = 0;

                GLuint              _sotc_patch_join_patch1         = 0;
                GLuint              _sotc_patch_join_patch2         = 0;
                GLuint              _sotc_patch_join_direction1     = 0;
                GLuint              _sotc_patch_join_direction2     = 0;

                GLuint              _sotc_patch_merge_patch1        = 0;
                GLuint              _sotc_patch_merge_patch2        = 0;
                GLuint              _sotc_patch_merge_direction1    = 0;
                GLuint              _sotc_patch_merge_direction2    = 0;

                bool                _sotc_patch_do_normal               = false;
                bool                _sotc_patch_do_first_derivatives    = false;
                bool                _sotc_patch_do_second_derivatives   = false;
                bool                _sotc_patch_do_texture              = false;


      // Shaders
            RowMatrix<ShaderProgram>    _shaders;
            GLuint                      _shader_index       = 0;
            GLfloat                     _shader_intensity   = 1.0f;
            GLfloat                     _shader_scale       = 1.0f;
            GLfloat                     _shader_smoothing   = 1.0f;
            GLfloat                     _shader_shading     = 1.0f;

            bool                        _shader_do_shader = false;

            void                        _getShaders();

    public:
        // special and default constructor
        // the format specifies the properties of the rendering window
        GLWidget(QWidget*               parent = 0,
                 ArcContinueWindow*     arcContinueWindow = nullptr,
                 ArcJoinWindow*         arcJoinWindow = nullptr,
                 ArcMergeWindow*        arcMergeWindow = nullptr,
                 PatchContinueWindow*   patchContinueWindow = nullptr,
                 PatchJoinWindow*       patchJoinWindow = nullptr,
                 PatchMergeWindow*      patchMergeWindow = nullptr);

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
            void showArcContinueWindow();
            void showArcJoinWindow();
            void showArcMergeWindow();
            void showPatchContinueWindow();
            void showPatchJoinWindow();
            void showPatchMergeWindow();

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

                void arcInteractionButtonContinue();
                void arcInteractionButtonJoin();
                void arcInteractionButtonMerge();

                void arcInteractionContinueSetArc(int value);
                void arcInteractionContinueSetDirection(int value);

                void arcInteractionJoinSetArc1(int value);
                void arcInteractionJoinSetArc2(int value);
                void arcInteractionJoinSetDirection1(int value);
                void arcInteractionJoinSetDirection2(int value);

                void arcInteractionMergeSetArc1(int value);
                void arcInteractionMergeSetArc2(int value);
                void arcInteractionMergeSetDirection1(int value);
                void arcInteractionMergeSetDirection2(int value);

            // Patches
                void patchInsertSetAlpha_U(double value);
                void patchInsertSetAlpha_V(double value);
                void patchInsertSetScale(double value);
                void patchInsertButtonCreate();
                void patchInsertButtonSave();
                void patchInsertButtonLoad();

                void patchIsoparametricSetDivCount_U(int value);
                void patchIsoparametricSetDivCount_V(int value);
                void patchIsoparametricSetLineCount_U(int value);
                void patchIsoparametricSetLineCount_V(int value);

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

                void patchInteractionButtonContinue();
                void patchInteractionButtonJoin();
                void patchInteractionButtonMerge();

                void patchInteractionContinueSetPatch(int value);
                void patchInteractionContinueSetDirection(int value);

                void patchInteractionJoinSetPatch1(int value);
                void patchInteractionJoinSetPatch2(int value);
                void patchInteractionJoinSetDirection1(int value);
                void patchInteractionJoinSetDirection2(int value);

                void patchInteractionMergeSetPatch1(int value);
                void patchInteractionMergeSetPatch2(int value);
                void patchInteractionMergeSetDirection1(int value);
                void patchInteractionMergeSetDirection2(int value);

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
