#include "CompositeTrigonometricPatch.h"
#include "Core/DCoordinates3.h"
#include "Core/Materials.h"
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

    GLboolean CompositeTrigonometricPatch::renderEveryPatch(GLuint order, GLenum render_mode) const
    {
       for (GLuint i = 0; i < _nr_of_patches; i++)
       {
           renderSelectedPatch(i, order, render_mode);
       }
       return GL_TRUE;
    }


    GLboolean CompositeTrigonometricPatch::renderSelectedPatch(GLuint index, GLuint order, GLenum render_mode) const
    {
       _patches[index]->RenderData();

       MatFBTurquoise.Apply();
       _images[index]->Render();

       for(GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
       {
            glColor3f(1.0f, 0.0f, 0.0f);
            (*_u_isoparametric_lines[index])[i]->RenderDerivatives(order, render_mode);
       }

       for(GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
       {
            glColor3f(1.0f, 0.0f, 0.0f);
            (*_v_isoparametric_lines[index])[i]->RenderDerivatives(order, render_mode);
       }

       return GL_TRUE;
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


    GLboolean CompositeTrigonometricPatch::insertNewPatch(Material* material, const vector<DCoordinate3>& controlPoints)
    {
        GLuint index = _nr_of_patches;
        _patches[index] = new (nothrow) SecondOrderTrigonometricPatch3();

        SecondOrderTrigonometricPatch3*& cur_patch = _patches[index];

        setControlPointsForPatch(cur_patch, controlPoints);

        cur_patch->UpdateVertexBufferObjectsOfData();

        _images[index] = cur_patch->GenerateImage(30, 30);

        if (_images[index])
            _images[index]->UpdateVertexBufferObjects();

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

        cout<<"inserted patch"<<endl;
        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::continuePatch(GLuint patch_index, Direction direction)
    {
//        if (_neighbours[patch_index][direction] != nullptr)
//        {
//            cout << "Continuation of merged patches is not possible." << endl;
//            return GL_FALSE;
//        }
        vector<DCoordinate3> new_control_points(16);

        switch (direction) {
            case N:
            {
                for (GLuint i = 0; i < 4; i++)
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
                DCoordinate3 q = (*_patches[patch_index])(3, 3);
                DCoordinate3 u = (*_patches[patch_index])(3, 3) - (*_patches[patch_index])(3, 2);
                DCoordinate3 r = (*_patches[patch_index])(3, 3) - (*_patches[patch_index])(2, 3);

                for (GLuint i = 0; i < 4; i ++)
                {
                    new_control_points[i] = q + i * u;
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                    new_control_points[i * 4] = q + i * r;
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                    for (GLuint j = 1; j < 4; j ++)
                    {
                        new_control_points[j * 4 + i] += (q + j * r) + i * u;
                        new_control_points[i * 4 + j] += (q + i * r) + j * u;
                    }
               }

                for (GLuint i = 1; i < 4; i ++)
                {
                    for (GLuint j = 1; j < 4; j ++)
                    {
                        new_control_points[j * 4 + i] /= 2.0;
                    }
                }
                break;
            }
            case E:
            {
                for (GLuint i = 0; i < 4; i++)
                {
                    new_control_points[i * 4 + 0] = (*_patches[patch_index])(3, 0) + i * ((*_patches[patch_index])(3, 0) - (*_patches[patch_index])(2, 0));
                    new_control_points[i * 4 + 1] = (*_patches[patch_index])(3, 1) + i * ((*_patches[patch_index])(3, 1) - (*_patches[patch_index])(2, 1));
                    new_control_points[i * 4 + 2] = (*_patches[patch_index])(3, 2) + i * ((*_patches[patch_index])(3, 2) - (*_patches[patch_index])(2, 2));
                    new_control_points[i * 4 + 3] = (*_patches[patch_index])(3, 3) + i * ((*_patches[patch_index])(3, 3) - (*_patches[patch_index])(2, 3));
                }
                break;
            }
            case SE:
            {
                DCoordinate3 q = (*_patches[patch_index])(3, 0);
                DCoordinate3 d = (*_patches[patch_index])(3, 0) - (*_patches[patch_index])(3, 1);
                DCoordinate3 r = (*_patches[patch_index])(3, 0) - (*_patches[patch_index])(2, 0);

                for (GLuint i = 0; i < 4; i ++)
                {
                   new_control_points[3 - i] = q + i * d;
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                   new_control_points[3 + i * 4] = q + i * r;
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                   for (GLuint j = 1; j < 4; j ++)
                   {
                       new_control_points[j * 4 + (3 - i)] += (q + j * r) + i * d;
                       new_control_points[i * 4 + (3 - j)] += (q + i * r) + j * d;
                   }
                }

                for (GLuint i = 0; i < 3; i ++)
                {
                   for (GLuint j = 1; j < 4; j ++)
                   {
                       new_control_points[j * 4 + i] /= 2.0;
                   }
                }
                break;
            }
            case S:
            {
                for (GLuint i = 0; i < 4; i++)
                {
                    new_control_points[0 * 4 + 3 - i] = (*_patches[patch_index])(0, 0) + i * ((*_patches[patch_index])(0, 0) - (*_patches[patch_index])(0, 1));
                    new_control_points[1 * 4 + 3 - i] = (*_patches[patch_index])(1, 0) + i * ((*_patches[patch_index])(1, 0) - (*_patches[patch_index])(1, 1));
                    new_control_points[2 * 4 + 3 - i] = (*_patches[patch_index])(2, 0) + i * ((*_patches[patch_index])(2, 0) - (*_patches[patch_index])(2, 1));
                    new_control_points[3 * 4 + 3 - i] = (*_patches[patch_index])(3, 0) + i * ((*_patches[patch_index])(3, 0) - (*_patches[patch_index])(3, 1));
                }
                break;
            }
            case SW:
            {
                    DCoordinate3 q = (*_patches[patch_index])(0, 0);
                    DCoordinate3 d = (*_patches[patch_index])(0, 0) - (*_patches[patch_index])(0, 1);
                    DCoordinate3 l = (*_patches[patch_index])(0, 0) - (*_patches[patch_index])(1, 0);

                    for (GLuint i = 0; i < 4; i ++)
                    {
                        new_control_points[15 - i] = q + i * d;
                    }

                    for (GLuint i = 1; i < 4; i ++)
                    {
                        new_control_points[15 - i * 4] = q + i * l;
                    }

                    for (GLuint i = 1; i < 4; i ++)
                    {
                        for (GLuint j = 1; j < 4; j ++)
                        {
                            new_control_points[(3 - j) * 4 + (3 - i)] += (q + j * l) + i * d;
                            new_control_points[(3 - i) * 4 + (3 - j)] += (q + i * l) + j * d;
                        }
                    }

                    for (GLuint i = 0; i < 3; i ++)
                    {
                        for (GLuint j = 0; j < 3; j ++)
                        {
                            new_control_points[j * 4 + i] /= 2.0;
                        }
                    }
                break;
            }
            case W:
            {
                for (GLuint i = 0; i < 4; i ++)
                {
                    new_control_points[16 - i * 4 - 4] = (*_patches[patch_index])(0, 0) + i * ((*_patches[patch_index])(0, 0) - (*_patches[patch_index])(1, 0));
                    new_control_points[16 - i * 4 - 3] = (*_patches[patch_index])(0, 1) + i * ((*_patches[patch_index])(0, 1) - (*_patches[patch_index])(1, 1));
                    new_control_points[16 - i * 4 - 2] = (*_patches[patch_index])(0, 2) + i * ((*_patches[patch_index])(0, 2) - (*_patches[patch_index])(1, 2));
                    new_control_points[16 - i * 4 - 1] = (*_patches[patch_index])(0, 3) + i * ((*_patches[patch_index])(0, 3) - (*_patches[patch_index])(1, 3));
//                    new_control_points[i + 4 * 0] = (*_patches[patch_index])(0, 3) + i * (*_patches[patch_index])(0, 3) - (*_patches[patch_index])(0, 2);
//                    new_control_points[i + 4 * 1] = (*_patches[patch_index])(1, 3) + i * (*_patches[patch_index])(1, 3) - (*_patches[patch_index])(1, 2);
//                    new_control_points[i + 4 * 2] = (*_patches[patch_index])(2, 3) + i * (*_patches[patch_index])(2, 3) - (*_patches[patch_index])(2, 2);
//                    new_control_points[i + 4 * 3] = (*_patches[patch_index])(3, 3) + i * (*_patches[patch_index])(3, 3) - (*_patches[patch_index])(3, 2);
                }
                break;
            }
            case NW:
            {
                DCoordinate3 q = (*_patches[patch_index])(0, 3);
                DCoordinate3 u = (*_patches[patch_index])(0, 3) - (*_patches[patch_index])(0, 2);
                DCoordinate3 l = (*_patches[patch_index])(0, 3) - (*_patches[patch_index])(1, 3);

                for (GLuint i = 0; i < 4; i ++)
                {
                    new_control_points[12 + i] = q + i * u;
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                    new_control_points[12 - i * 4] = q + i * l;
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                    for (GLuint j = 1; j < 4; j ++)
                    {
                        new_control_points[(3 - j) * 4 + i] += (q + j * l) + i * u;
                        new_control_points[(3 - i) * 4 + j] += (q + i * l) + j * u;
                    }
                }

                for (GLuint i = 1; i < 4; i ++)
                {
                    for (GLuint j = 0; j < 3; j ++)
                    {
                        new_control_points[j * 4 + i] /= 2.0;
                    }
                }
                break;
            }
        }

        insertNewPatch(_materials[patch_index], new_control_points);

//        _neighbours[patch_index][direction] = _patches[_nr_of_patches - 1];
        // itt még kimaradt a connection type
        // _neighbours[patch_index]
//        _connection_types[patch_index][direction] = direction;

//        _neighbours[patch_index][(Direction)((direction + 4) % 8)] = _patches[patch_index];
//        _connection_types[patch_index][direction] = (Direction)((direction + 4) % 8);

        return GL_TRUE;
    }

    DCoordinate3 CompositeTrigonometricPatch::getSelectedPoint(GLuint patch_index, GLuint row, GLuint col)
    {
        return (*_patches[patch_index])(row, col);
    }
}
