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

    GLboolean CompositeTrigonometricPatch::renderEveryPatch(Material material, GLboolean do_patch, GLboolean do_u_isoparametric, GLboolean do_v_isoparametric, GLboolean do_normal, GLboolean do_first_derivatives, GLboolean do_second_derivatives) const
    {
       for (GLuint i = 0; i < _nr_of_patches; i++)
       {
           renderSelectedPatch(i, material, do_patch, do_u_isoparametric, do_v_isoparametric, do_normal, do_first_derivatives, do_second_derivatives);
       }
       return GL_TRUE;
    }


    GLboolean CompositeTrigonometricPatch::renderSelectedPatch(GLuint index, Material material, GLboolean do_patch, GLboolean do_u_isoparametric, GLboolean do_v_isoparametric, GLboolean do_normal, GLboolean do_first_derivatives, GLboolean do_second_derivatives) const
    {
       if (do_u_isoparametric)
       {
            glColor3f(1.0f, 0.0f, 0.0f);
            for(GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                 (*_u_isoparametric_lines[index])[i]->RenderDerivatives(0, GL_LINE_STRIP);
            }

            if (do_first_derivatives)
            {
                for(GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
                {
                    glColor3f(1.0f, 1.0f, 0.0f);
                    (*_u_isoparametric_lines[index])[i]->RenderDerivatives(1, GL_LINES);
                    glColor3f(1.0f, 0.0f, 1.0f);
                    glPointSize(3.0f);
                    (*_u_isoparametric_lines[index])[i]->RenderDerivatives(1, GL_POINTS);
                    glPointSize(1.0f);
                }
            }

            if (do_second_derivatives)
            {
                for(GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
                {
                    glColor3f(1.0f, 1.0f, 0.0f);
                    (*_u_isoparametric_lines[index])[i]->RenderDerivatives(2, GL_LINES);
                    glColor3f(0.0f, 1.0f, 1.0f);
                    glPointSize(3.0f);
                    (*_u_isoparametric_lines[index])[i]->RenderDerivatives(2, GL_POINTS);
                    glPointSize(1.0f);
                }
            }
       }

       if (do_v_isoparametric)
       {
            glColor3f(1.0f, 0.0f, 0.0f);
            for(GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                 (*_v_isoparametric_lines[index])[i]->RenderDerivatives(0, GL_LINE_STRIP);
            }

            if (do_first_derivatives)
            {
                for(GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
                {
                    glColor3f(1.0f, 1.0f, 0.0f);
                    (*_v_isoparametric_lines[index])[i]->RenderDerivatives(1, GL_LINES);
                    glColor3f(1.0f, 0.0f, 1.0f);
                    glPointSize(3.0f);
                    (*_v_isoparametric_lines[index])[i]->RenderDerivatives(1, GL_POINTS);
                    glPointSize(1.0f);
                }
            }

            if (do_second_derivatives)
            {
                for(GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
                {
                    glColor3f(1.0f, 1.0f, 0.0f);
                    (*_v_isoparametric_lines[index])[i]->RenderDerivatives(2, GL_LINES);
                    glColor3f(0.0f, 1.0f, 1.0f);
                    glPointSize(3.0f);
                    (*_v_isoparametric_lines[index])[i]->RenderDerivatives(2, GL_POINTS);
                    glPointSize(1.0f);
                }
            }
       }

       if (do_patch)
       {
           material.Apply();
            _images[index]->Render();
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
        _patches[index] = new (nothrow) SecondOrderTrigonometricPatch3(_u_alpha, _v_alpha);

        SecondOrderTrigonometricPatch3*& cur_patch = _patches[index];

        setControlPointsForPatch(cur_patch, controlPoints);

        cur_patch->UpdateVertexBufferObjectsOfData();

        _images[index] = cur_patch->GenerateImage(_u_isoparametric_div_count, _v_isoparametric_div_count);

        if (_images[index])
            _images[index]->UpdateVertexBufferObjects();

        _u_isoparametric_lines[index] = cur_patch->GenerateUIsoparametricLines(_u_isoparametric_line_count, 2, _u_isoparametric_div_count);
        _v_isoparametric_lines[index] = cur_patch->GenerateVIsoparametricLines(_v_isoparametric_line_count, 2, _v_isoparametric_div_count);

        for (GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
        {
            (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
        }

        for (GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
        {
            (*_v_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
        }

        _materials[index] = material;

        _nr_of_patches++;

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

    std::vector<DCoordinate3> CompositeTrigonometricPatch::getPoints(GLuint index)
    {
        std::vector<DCoordinate3> points(16);

        GLdouble x = 0, y = 0, z = 0;

        for (GLuint i = 0; i < 4; i++)
        {
            for (GLuint j = 0; j < 4; j++)
            {
                _patches[index]->GetData(i, j, x, y, z);

                points[i * 4 + j] = DCoordinate3(x, y, z);
            }
        }

        return points;
    }

    void CompositeTrigonometricPatch::_updateData()
    {
        for (GLuint index = 0; index < _nr_of_patches; index++)
        {
            _patches[index]->SetUAlpha(_u_alpha);
            _patches[index]->SetVAlpha(_v_alpha);

            delete _images[index]; _images[index] = nullptr;

            SecondOrderTrigonometricPatch3*& cur_patch = _patches[index];

            setControlPointsForPatch(cur_patch, getPoints(index));

            cur_patch->UpdateVertexBufferObjectsOfData();

            _images[index] = cur_patch->GenerateImage(_u_isoparametric_div_count, _v_isoparametric_div_count);

            if (_images[index])
                _images[index]->UpdateVertexBufferObjects();

            _u_isoparametric_lines[index] = cur_patch->GenerateUIsoparametricLines(_u_isoparametric_line_count, 2, _u_isoparametric_div_count);
            _v_isoparametric_lines[index] = cur_patch->GenerateVIsoparametricLines(_v_isoparametric_line_count, 2, _v_isoparametric_div_count);

            for (GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            for (GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                (*_v_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }
        }
    }

    GLboolean CompositeTrigonometricPatch::setAlpha_U(GLdouble value)
    {
        _u_alpha = value;

        _updateData();

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::setAlpha_V(GLdouble value)
    {
        _v_alpha = value;

        _updateData();

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::setIsoparametricScale(GLdouble value)
    {
        _isoparametric_scale = value;

        _updateData();

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::setIsoparametricDivCount_U(GLuint value)
    {
        _u_isoparametric_div_count = value;

        _updateData();

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::setIsoparametricDivCount_V(GLuint value)
    {
        _v_isoparametric_div_count = value;

        _updateData();

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::setIsoparametricLineCount_U(GLuint value)
    {
        _u_isoparametric_line_count = value;

        _updateData();

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::setIsoparametricLineCount_V(GLuint value)
    {
        _v_isoparametric_line_count = value;

        _updateData();

        return GL_TRUE;
    }

    DCoordinate3 CompositeTrigonometricPatch::getSelectedPoint(GLuint patch_index, GLuint row, GLuint col)
    {
        return (*_patches[patch_index])(row, col);
    }
}
