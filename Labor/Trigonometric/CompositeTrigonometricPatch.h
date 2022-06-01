#pragma once
#include "Core/GenericCurves3.h"
#include "Core/Materials.h"
#include "Core/Matrices.h"
#include "Core/ShaderPrograms.h"
#include "Core/TriangulatedMeshes3.h"
#include "SecondOrderTrigonometricPatch3.h"
#include <vector>
#include <GL/glu.h>
#include "Core/DCoordinates3.h"
#include <QOpenGLTexture>

namespace cagd
{
    class CompositeTrigonometricPatch
    {
    private:
        GLuint                                           _nr_of_patches;
        std::vector<SecondOrderTrigonometricPatch3*>     _patches;
        std::vector<TriangulatedMesh3*>                  _images;
        std::vector<Material*>                           _materials;
        std::vector<QOpenGLTexture*>                     _textures;
        std::vector<ShaderProgram*>                      _shaders;
        std::vector<RowMatrix<GenericCurve3*>*>          _u_isoparametric_lines;
        std::vector<RowMatrix<GenericCurve3*>*>          _v_isoparametric_lines;
        std::vector<std::vector<GLuint>>                 _neighbour_indexes; // A deletePatch esetén végigjárjuk az oszlopokat
        std::vector<std::vector<SecondOrderTrigonometricPatch3*>>    _neighbours;
        GLuint                                          _uDivPointCount = 30;
        GLuint                                          _vDivPointCount = 30;
        GLuint                                          _uIsoLineCount = 5;
        GLuint                                          _vIsoLineCount = 5;

        GLdouble                _u_alpha = 1.0;
        GLdouble                _v_alpha = 1.0;
        GLdouble                _isoparametric_scale = 1.0;
        GLuint                  _u_isoparametric_div_count = 10;
        GLuint                  _v_isoparametric_div_count = 10;
        GLuint                  _u_isoparametric_line_count = 4;
        GLuint                  _v_isoparametric_line_count = 4;

        static std::vector<DCoordinate3>                 _default_control_points;

        void                                             _initializeDefaultControlPoints();
        void                                             _updateData();
        void                                             _updateMergeData(GLuint index1, GLuint index2);

        /**
         * Beállítja a felület kontrollpontjait.
         */
        void setControlPointsForPatch(SecondOrderTrigonometricPatch3* patch, const std::vector<DCoordinate3>& controlPoints = _default_control_points);
    public:
        enum Direction{N, NW, W, SW, S, SE, E, NE};
        std::vector<std::vector<Direction>>              _connection_types;
        /**
         * Inicializálja a patch kezelő objektumot egy adott számú hellyel patcheknek.
         *
         * @param initial_patch_count A kezdeti helyek száma.
         */
        CompositeTrigonometricPatch(GLuint initial_patch_count = 1000);

        /**
         * Létrehoz egy új SecondOrderTrigonometricPatch-et, és hozzáadja az
         * eltárolt patchek vektorába.
         */
        GLboolean                                       patchExists(GLuint index);
        GLboolean                                       insertNewPatch(Material* material, const std::vector<DCoordinate3>& controlPoints = _default_control_points);
        GLboolean                                       continuePatch(GLuint patch_index, Direction direction);
        GLboolean                                       joinPatches(GLuint patch_index_1, GLuint patch_index_2, Direction dir_1, Direction dir_2);
        GLboolean                                       mergePatches(GLuint patch_index_1, GLuint patch_index_2, Direction dir_1, Direction dir_2);
        GLboolean                                       deletePatch(GLuint patch_index);
        GLboolean                                       deleteAllPatches();
        GLboolean                                       renderSelectedPatch(GLuint index, Material material, GLboolean do_patch = true, GLboolean do_u_isoparametric = false, GLboolean do_v_isoparametric = false, GLboolean do_normal = false, GLboolean do_first_derivatives = false, GLboolean do_second_derivatives = false) const;
        GLboolean                                       renderEveryPatch(Material material, GLboolean do_patch = true, GLboolean do_u_isoparametric = false, GLboolean do_v_isoparametric = false, GLboolean do_normal = false, GLboolean do_first_derivatives = false, GLboolean do_second_derivatives = false) const;
        void                                            translateSelectedPatch(GLuint index, GLuint coord, double value);

        GLboolean                                       setAlpha_U(GLdouble value);
        GLboolean                                       setAlpha_V(GLdouble value);
        GLboolean                                       setIsoparametricScale(GLdouble value);
        GLboolean                                       setIsoparametricDivCount_U(GLuint value);
        GLboolean                                       setIsoparametricDivCount_V(GLuint value);
        GLboolean                                       setIsoparametricLineCount_U(GLuint value);
        GLboolean                                       setIsoparametricLineCount_V(GLuint value);

        DCoordinate3                                    getSelectedPoint(GLuint patch_index, GLuint row, GLuint col);
        std::vector<DCoordinate3>                       getPoints(GLuint index);


        // TODO
        // render with new values (alphaU, alphaV, linecountU, linecountV, etc.)

        // TODO
//        ~CompositeTrigonometricPatch();
    };
}
