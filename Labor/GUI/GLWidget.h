#pragma once

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <Parametric/ParametricCurves3.h>
#include <Core/GenericCurves3.h>
#include <Cyclic/CyclicCurves3.h>
#include <Core/TriangulatedMeshes3.h>
#include <Core/Materials.h>
#include <Core/Lights.h>

namespace cagd
{
    struct ModelProperties
    {
        GLuint          id;
        GLuint          moving;
        GLint           material_id;
        DCoordinate3    position;
        GLdouble        angle[3];
        GLdouble        scale[3];
        GLdouble        color[3];

        inline friend std::istream& operator>>(std::istream& inStream, ModelProperties& modelP)
        {
            inStream >> modelP.id;
            inStream >> modelP.moving;
            inStream >> modelP.material_id;
            inStream >> modelP.position.x() >> modelP.position.y() >> modelP.position.z();
            inStream >> modelP.angle[0] >> modelP.angle[1] >> modelP.angle[2];
            inStream >> modelP.scale[0] >> modelP.scale[1] >> modelP.scale[2];
            inStream >> modelP.color[0] >> modelP.color[1] >> modelP.color[2];
            return inStream;
        }

        inline friend std::ostream& operator<<(std::ostream& outStream, ModelProperties& modelP)
        {
            outStream << modelP.id << std::endl;
            outStream << modelP.moving << std::endl;
            outStream << modelP.material_id << std::endl;
            outStream << modelP.position.x() << modelP.position.y() << modelP.position.z() << std::endl;
            outStream << modelP.angle[0] << modelP.angle[1] << modelP.angle[2] << std::endl;
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

        QTimer          *_timer1;
        DCoordinate3    _i_prime, _j_prime, _k_prime;
        GLdouble        _transformation[16];
        GLuint          _time_index = 0;

        // Parametric curves
            RowMatrix<RowMatrix<ParametricCurve3::Derivative>>  _pc_derivatives;
            GLdouble                                            _pc_derivative_scale = 1.0;
            bool                                                _pc_zeroth_derivative = true;
            bool                                                _pc_first_derivative = false;
            bool                                                _pc_second_derivative = false;

            GLuint                                    _pc_count = 8;
            RowMatrix<ParametricCurve3*>              _pcs;
            RowMatrix<GenericCurve3*>                 _pc_image_of_pcs;
            GLuint                                    _pc_selected_curve_index = 0;
            GLuint                                    _pc_div_point_count = 200;
            GLenum                                    _pc_usage_flag = GL_STATIC_DRAW;

            void _createParametricCurves();
            void _generateParametricImage(GLuint);
            void _updateParametricVBO(GLuint);
            void _destroyAllExistingParametricCurves();
            void _destroyAllExistingParametricCurvesImages();

        // 3D race
            // Generic curves
                GLuint                                  _mod = 2, _div = 100;
                RowMatrix<GenericCurve3*>               _image_of_ccs;
                GLuint                                  _selected_cyclic_curve_index = 0;
                GLuint                                  _selected_cylcic_curve_control_point_index = 0;
            // Approximating cyclic curves
                GLuint                                  _cc_count = 3;
                RowMatrix<GLuint>                       _n;
                RowMatrix<CyclicCurve3*>                _ccs;
                RowMatrix<RowMatrix<DCoordinate3>>      _cc_control_points;
                std::vector<std::string>                _cc_path_names{"Path1", "Path2", "Path3", "Path4"};
            // Interpolating cyclic curves
                GLuint                                  _icc_count = 2;
                RowMatrix<ColumnMatrix<DCoordinate3>>   _iccs;
            DirectionalLight                        *_dirLight = nullptr;
            Material                                _race_object_materials[6]{MatFBBrass, MatFBSilver, MatFBGold,
                                                                              MatFBEmerald, MatFBPearl, MatFBTurquoise};
            RowMatrix<TriangulatedMesh3>            _race_models;
            RowMatrix<ModelProperties>              _race_scene;
            GLuint                                  _model_count = 0;
            GLuint                                  _object_count = 0;
            std::vector<std::string>                _model_paths{"Models/Boats/boat_01.off",
                                                                 "Models/Boats/boat_02.off",
                                                                 "Models/Building blocks/Buildings/building_01.off",
                                                                 "Models/Building blocks/Buildings/building_02.off",
                                                                 "Models/Building blocks/Buildings/building_03.off",
                                                                 "Models/Building blocks/Benches/bench_01.off",
                                                                 "Models/Building blocks/Benches/bench_02.off",
                                                                 "Models/Building blocks/Ornaments/ornament_01.off",
                                                                 "Models/Building blocks/Ornaments/ornament_02.off",
                                                                 "Models/Building blocks/Ornaments/ornament_03.off",
                                                                 "Models/Building blocks/Primitives/arc.off",
                                                                 "Models/Building blocks/Primitives/cone.off",
                                                                 "Models/Building blocks/Primitives/cube.off",
                                                                 "Models/Building blocks/Primitives/prism.off",
                                                                 "Models/Building blocks/Stands/stand_01.off",
                                                                 "Models/Building blocks/Stands/stand_02.off",
                                                                 "Models/Building blocks/Stands/stand_03.off",
                                                                 "Models/Building blocks/Statues/angel.off",
                                                                 "Models/Building blocks/Statues/dragon.off",
                                                                 "Models/Building blocks/Statues/Lucy.off"/*,
                                                                 "Models/Building blocks/Street lamps/street_lamp_01.off",
                                                                 "Models/Building blocks/Street lamps/street_lamp_02.off",
                                                                 "Models/Building blocks/Street lamps/street_lamp_03.off",
                                                                 "Models/Building blocks/Trees/tree_01.off",
                                                                 "Models/Building blocks/Trees/tree_02.off",
                                                                 "Models/Characters/elephant.off",
                                                                 "Models/Characters/gangster.off",
                                                                 "Models/Characters/mouse.off",
                                                                 "Models/Characters/Spot.off",
                                                                 "Models/Flying objects/Airplanes/airplane_01.off",
                                                                 "Models/Flying objects/Airplanes/airplane_02.off"*/};

            void _createCyclicCurves();
            void _generateCyclicCurveImage(GLuint);
            void _updateCyclicCurveVBO(GLuint);
            void _updateCyclicCurveImageVBO(GLuint);
            void _renderCyclicCurves();
            void _destroyAllExistingCyclicCurves();
            void _destroyAllExistingCyclicCurvesImages();

            void _createInterpolatingCyclicCurves();
            void _renderInterpolatingCyclicCurves();
            void _destroyInterpolatingCyclicCurves();

            void _createRaceObjects();
            void _destroyAllExistingObjects();
            bool _getModels();
            bool _getScene();

    public:
        // special and default constructor
        // the format specifies the properties of the rendering window
        GLWidget(QWidget* parent = 0);

        // redeclared virtual functions
        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);

        std::vector<std::string> get_test_names();
        std::vector<std::string> get_cc_path_names();
        GLuint get_pc_count();
        GLuint get_cc_count();

        // destructor
        ~GLWidget();

    private slots:
        void _animate1();

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

        // Parametric curves
        void pc_set_selected_parametric_curve_index(int value);
        void pc_set_div_point_count(int value);
        void pc_set_derivative_scale(double value);

        void pc_set_zeroth_derivative(bool value);
        void pc_set_first_derivative(bool value);
        void pc_set_second_derivative(bool value);

        // 3D race
        void race_set_selected_cyclic_curve_index(int value);
        void race_set_selected_control_point(int value);
        void race_move_X(double value);
        void race_move_Y(double value);
        void race_move_Z(double value);


    signals:
        void set_cc_cp_maxLimit(int);
        void set_cc_cp_values(double, double, double);
    };
}
