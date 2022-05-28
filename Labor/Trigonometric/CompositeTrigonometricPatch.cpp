#include "CompositeTrigonometricPatch.h"
#include "Core/DCoordinates3.h"
#include "Trigonometric/SecondOrderTrigonometricPatch3.h"
#include <atomic>

using namespace std;

namespace cagd
{
    // Privát rész.
    vector <DCoordinate3> CompositeTrigonometricPatch::_default_control_points;

    void CompositeTrigonometricPatch::setControlPointsForPatch(SecondOrderTrigonometricPatch3* patch, const std::vector<DCoordinate3>& controlPoints)
    {
       for(int i = 0; i < 4; i++)
       {
           for(int j = 0; j < 4; j++)
           {
               patch->SetData(i, j, controlPoints[i * 4 + j]);
           }
       }
    }

    void CompositeTrigonometricPatch::_initializeDefaultControlPoints()
    {
        _default_control_points.resize(16);
        _default_control_points[0] = DCoordinate3(-2.0, -2.0, 1.0);
        _default_control_points[1] = DCoordinate3(-2.0, -1.0, -2.0);
        _default_control_points[2] = DCoordinate3(-2.0,  1.0, -2.0);
        _default_control_points[3] = DCoordinate3(-2.0,  2.0,  1.0);
        _default_control_points[4] = DCoordinate3(-1.0, -2.0,  0.0);
        _default_control_points[5] = DCoordinate3(-1.0, -1.0,  1.0);
        _default_control_points[6] = DCoordinate3(-1.0,  1.0,  1.0);
        _default_control_points[7] = DCoordinate3(-1.0,  2.0,  0.0);
        _default_control_points[8] = DCoordinate3( 1.0, -2.0,  0.0);
        _default_control_points[9] = DCoordinate3( 1.0, -1.0,  1.0);
        _default_control_points[10] = DCoordinate3( 1.0,  1.0,  1.0);
        _default_control_points[11] = DCoordinate3( 1.0,  2.0,  0.0);
        _default_control_points[12] = DCoordinate3( 2.0, -2.0,  1.0);
        _default_control_points[13] = DCoordinate3( 2.0, -1.0, -2.0);
        _default_control_points[14] = DCoordinate3( 2.0,  1.0, -2.0);
        _default_control_points[15] = DCoordinate3( 2.0,  2.0,  1.0);

    }

    // Publikus rész
    CompositeTrigonometricPatch::CompositeTrigonometricPatch(GLuint initial_patch_count)
    {
        _patches.resize(initial_patch_count);
        _images.resize(initial_patch_count);
        _materials.resize(initial_patch_count);
        _textures.resize(initial_patch_count);
        _shaders.resize(initial_patch_count);
        _u_isoparametric_lines.resize(initial_patch_count);
        _v_isoparametric_lines.resize(initial_patch_count);

        _nr_of_patches = 0;
        _initializeDefaultControlPoints();
    }


    GLboolean CompositeTrigonometricPatch::insertNewPatch(const vector<DCoordinate3>& controlPoints, Material* material)
    {
        GLuint index = _nr_of_patches;
        _patches[index] = new (nothrow) SecondOrderTrigonometricPatch3();

        SecondOrderTrigonometricPatch3*& cur_patch = _patches[index];

        setControlPointsForPatch(cur_patch, controlPoints);

        cur_patch->UpdateVertexBufferObjectsOfData();

        _images[index] = cur_patch->GenerateImage(30, 30);
        _u_isoparametric_lines[index] = cur_patch->GenerateUIsoparametricLines(30, 2, 30);
        _v_isoparametric_lines[index] = cur_patch->GenerateVIsoparametricLines(30, 2, 30);

        for (GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
        {
            (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects();
        }

        for (GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
        {
            (*_v_isoparametric_lines[index])[i]->UpdateVertexBufferObjects();
        }

        _materials[index] = material;

        _nr_of_patches++;

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::continuePatch(GLuint patch_index, Direction direction)
    {
        vector<DCoordinate3> new_control_points(16);

        switch (direction) {
            case N:
            {
                for (GLuint i = 0; i < 4; i ++)
                {
                    new_control_points[i + 4 * 0] = (*_patches[patch_index])(0, 3) + i * (*_patches[patch_index])(0, 3) - (*_patches[patch_index])(0, 2);
                    new_control_points[i + 4 * 1] = (*_patches[patch_index])(1, 3) + i * (*_patches[patch_index])(1, 3) - (*_patches[patch_index])(1, 2);
                    new_control_points[i + 4 * 2] = (*_patches[patch_index])(2, 3) + i * (*_patches[patch_index])(2, 3) - (*_patches[patch_index])(2, 2);
                    new_control_points[i + 4 * 3] = (*_patches[patch_index])(3, 3) + i * (*_patches[patch_index])(3, 3) - (*_patches[patch_index])(3, 2);
                }
                break;
            }
            case NE:
            {
                break;
            }
            case E:
            {
                break;
            }
            case SE:
            {
                break;
            }
            case S:
            {
                break;
            }
            case SW:
            {
                break;
            }
            case W:
            {
                for (GLuint i = 0; i < 4; i ++)
                {
                    new_control_points[i + 4 * 0] = (*_patches[patch_index])(0, 3) + i * (*_patches[patch_index])(0, 3) - (*_patches[patch_index])(0, 2);
                    new_control_points[i + 4 * 1] = (*_patches[patch_index])(1, 3) + i * (*_patches[patch_index])(1, 3) - (*_patches[patch_index])(1, 2);
                    new_control_points[i + 4 * 2] = (*_patches[patch_index])(2, 3) + i * (*_patches[patch_index])(2, 3) - (*_patches[patch_index])(2, 2);
                    new_control_points[i + 4 * 3] = (*_patches[patch_index])(3, 3) + i * (*_patches[patch_index])(3, 3) - (*_patches[patch_index])(3, 2);
                }
                break;
            }
            case NW:
            {
                break;
            }
        }

        insertNewPatch(new_control_points, _materials[patch_index]);

        return GL_TRUE;
    }
}
