#include "CompositeTrigonometricPatch.h"
#include "Core/DCoordinates3.h"
#include "Core/Materials.h"
#include "Trigonometric/SecondOrderTrigonometricPatch3.h"
#include "qnamespace.h"
#include <atomic>
#include <new>

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

    GLboolean CompositeTrigonometricPatch::renderEveryPatch(Material material, GLuint selected_patch, GLboolean do_patch, GLboolean do_u_isoparametric, GLboolean do_v_isoparametric, GLboolean do_normal, GLboolean do_first_derivatives, GLboolean do_second_derivatives) const
    {
       for (GLuint i = 0; i < _nr_of_patches; i++)
       {
           renderSelectedPatch(i, material, selected_patch, do_patch, do_u_isoparametric, do_v_isoparametric, do_normal, do_first_derivatives, do_second_derivatives);
       }
       return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::patchExists(GLuint index)
    {
        if (_patches[index])
            return GL_TRUE;
        return GL_FALSE;
    }

    GLboolean CompositeTrigonometricPatch::renderSelectedPatch(GLuint index, Material material, GLuint selected_patch, GLboolean do_patch, GLboolean do_u_isoparametric, GLboolean do_v_isoparametric, GLboolean do_normal, GLboolean do_first_derivatives, GLboolean do_second_derivatives) const
    {
       if (_images[index])
       {
           glDisable(GL_LIGHTING);
           glColor3f(0.0f, 1.0f, 0.0f);
           if (_patches[index]->RenderData(GL_LINE_STRIP))
               cout<<"sajt1"<<endl;
           else
               cout<<"nem sajt1"<<endl;
           glPointSize(30.0f);
           if (_patches[index]->RenderData(GL_POINTS))
               cout<<"sajt2"<<endl;
           else
               cout<<"nem sajt2"<<endl;
           glPointSize(1.0f);
           glEnable(GL_LIGHTING);

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

        if (do_normal)
        {
            _images[index]->RenderNormals(_isoparametric_scale);
        }

        if (_patches[index])
            cout<<"valami"<<endl;
        else
            cout<<"nem valami"<<endl;
        if (do_patch)
        {

            if (index == selected_patch)
            {
                MatFBRuby.Apply();
            }
            else
                material.Apply();
             _images[index]->Render();
        }
        return GL_TRUE;
       }

       return GL_FALSE;
    }

    GLboolean CompositeTrigonometricPatch::renderDirections()
    {
        for (GLuint i = 0; i < _nr_of_patches; i ++)
           {
               if (patchExists(i))
               {
                   glDisable(GL_LIGHTING);
                   glDisable(GL_LIGHT0);
                   glDisable(GL_LIGHT1);
                   glDisable(GL_LIGHT2);
                   glDisable(GL_NORMALIZE);
                   glPointSize(40.0f);
                   glBegin(GL_POINTS);
                       double x, y, z;
                       _patches[i]->GetData(0, 0, x, y, z);       //NW - pink
                       glColor3f(1.00f, 0.43f, 0.78f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(0, 1, x, y, z);       //N - red
                       glColor3f(1.0f, 0.0f, 0.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(0, 2, x, y, z);       //N - red
                       glColor3f(1.0f, 0.0f, 0.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(0, 3, x, y, z);       //NE - brown
                       glColor3f(0.36f, 0.25f, 0.20f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(1, 0, x, y, z);       //W - orange
                       glColor3f(1.0f, 0.5f, 0.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(2, 0, x, y, z);       //W - orange
                       glColor3f(1.0f, 0.5f, 0.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(1, 3, x, y, z);       //E - green
                       glColor3f(0.0f, 1.0f, 0.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(2, 3, x, y, z);       //E - green
                       glColor3f(0.0f, 1.0f, 0.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(3, 3, x, y, z);       //SE - blue
                       glColor3f(0.0f, 0.0f, 1.0f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(3, 2, x, y, z);       //S - purple
                       glColor3f(0.53f, 0.12f, 0.47f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(3, 1, x, y, z);       //S - purple
                       glColor3f(0.53f, 0.12f, 0.47f);
                       glVertex3f(x, y, z);

                       _patches[i]->GetData(3, 0, x, y, z);       //SW - yellow
                       glColor3f(1.0f, 1.0f, 0.0f);
                       glVertex3f(x, y, z);
                   glEnd();
                   glEnable(GL_LIGHTING);
                   glEnable(GL_LIGHT2);
                   glEnable(GL_LIGHT1);
                   glEnable(GL_LIGHT0);
                   glEnable(GL_NORMALIZE);
               }
           }

        return GL_TRUE;
    }

    void CompositeTrigonometricPatch::_initializeDefaultControlPoints()
    {
        _default_control_points.resize(16);
        _default_control_points[0]  = DCoordinate3(-2.0, -2.0,  0.0);
        _default_control_points[1]  = DCoordinate3(-2.0, -1.0,  0.0);
        _default_control_points[2]  = DCoordinate3(-2.0,  1.0,  0.0);
        _default_control_points[3]  = DCoordinate3(-2.0,  2.0,  0.0);

        _default_control_points[4]  = DCoordinate3(-1.0, -2.0,  0.0);
        _default_control_points[5]  = DCoordinate3(-1.0, -1.0,  2.0);
        _default_control_points[6]  = DCoordinate3(-1.0,  1.0,  2.0);
        _default_control_points[7]  = DCoordinate3(-1.0,  2.0,  0.0);

        _default_control_points[8]  = DCoordinate3( 1.0, -2.0,  0.0);
        _default_control_points[9]  = DCoordinate3( 1.0, -1.0,  2.0);
        _default_control_points[10] = DCoordinate3( 1.0,  1.0,  2.0);
        _default_control_points[11] = DCoordinate3( 1.0,  2.0,  0.0);

        _default_control_points[12] = DCoordinate3( 2.0, -2.0,  0.0);
        _default_control_points[13] = DCoordinate3( 2.0, -1.0,  0.0);
        _default_control_points[14] = DCoordinate3( 2.0,  1.0,  0.0);
        _default_control_points[15] = DCoordinate3( 2.0,  2.0,  0.0);
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

        _neighbours.resize(initial_patch_count, std::vector<SecondOrderTrigonometricPatch3*>(8, nullptr));
        _connection_types.resize(initial_patch_count, std::vector<Direction>(8, Direction::N));

        _nr_of_patches = 0;
        _initializeDefaultControlPoints();
    }

    GLboolean CompositeTrigonometricPatch::insertNewPatch(Material* material, const vector<DCoordinate3>& controlPoints)
    {
        GLuint index = _nr_of_patches;
        _patches[index] = new (nothrow) SecondOrderTrigonometricPatch3(_u_alpha, _v_alpha);

        setControlPointsForPatch(_patches[index], controlPoints);

        bool value = _patches[index]->UpdateVertexBufferObjectsOfData(GL_STATIC_DRAW);
        if (!value)
            return GL_FALSE;


        _images[index] = _patches[index]->GenerateImage(_u_isoparametric_div_count, _v_isoparametric_div_count);

        if (_images[index])
            _images[index]->UpdateVertexBufferObjects();

        _u_isoparametric_lines[index] = _patches[index]->GenerateUIsoparametricLines(_u_isoparametric_line_count, 2, _u_isoparametric_div_count);
        _v_isoparametric_lines[index] = _patches[index]->GenerateVIsoparametricLines(_v_isoparametric_line_count, 2, _v_isoparametric_div_count);

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
        if (_neighbours[patch_index][direction] != nullptr)
        {
            cout << "Continuation of merged patches is not possible." << endl;
            return GL_FALSE;
        }
        vector<DCoordinate3> new_control_points(16);

        switch (direction) {
            case N:
            {
                for (GLuint i = 0; i < 4; i++)
                {
                    new_control_points[i + 4 * 0] = (*_patches[patch_index])(0, 3) + i * ((*_patches[patch_index])(0, 3) - (*_patches[patch_index])(0, 2));
                    new_control_points[i + 4 * 1] = (*_patches[patch_index])(1, 3) + i * ((*_patches[patch_index])(1, 3) - (*_patches[patch_index])(1, 2));
                    new_control_points[i + 4 * 2] = (*_patches[patch_index])(2, 3) + i * ((*_patches[patch_index])(2, 3) - (*_patches[patch_index])(2, 2));
                    new_control_points[i + 4 * 3] = (*_patches[patch_index])(3, 3) + i * ((*_patches[patch_index])(3, 3) - (*_patches[patch_index])(3, 2));
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

        _neighbours[patch_index][direction] = _patches[_nr_of_patches - 1];
        // itt még kimaradt a connection type
        // _neighbours[patch_index]
        _connection_types[patch_index][direction] = direction;

        _neighbours[patch_index][(Direction)((direction + 4) % 8)] = _patches[patch_index];
        _connection_types[patch_index][direction] = (Direction)((direction + 4) % 8);

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

    void CompositeTrigonometricPatch::_updateMergeData(GLuint index1, GLuint index2)
    {
//            _patches[index]->SetUAlpha(_u_alpha);
//            _patches[index]->SetVAlpha(_v_alpha);

            delete _images[index1]; _images[index1] = nullptr;
            delete _images[index2]; _images[index2] = nullptr;

            SecondOrderTrigonometricPatch3*& cur_patch = _patches[index1];

//            setControlPointsForPatch(cur_patch, getPoints(index1));

            cur_patch->UpdateVertexBufferObjectsOfData();

            _images[index1] = cur_patch->GenerateImage(_u_isoparametric_div_count, _v_isoparametric_div_count);

            if (_images[index1])
                _images[index1]->UpdateVertexBufferObjects();

            _u_isoparametric_lines[index1] = cur_patch->GenerateUIsoparametricLines(_u_isoparametric_line_count, 2, _u_isoparametric_div_count);
            _v_isoparametric_lines[index1] = cur_patch->GenerateVIsoparametricLines(_v_isoparametric_line_count, 2, _v_isoparametric_div_count);

            for (GLuint i = 0; i < _u_isoparametric_lines[index1]->GetColumnCount(); i++)
            {
                (*_u_isoparametric_lines[index1])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            for (GLuint i = 0; i < _v_isoparametric_lines[index1]->GetColumnCount(); i++)
            {
                (*_v_isoparametric_lines[index1])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            cur_patch = _patches[index2];
            cur_patch->UpdateVertexBufferObjectsOfData();

            _images[index2] = cur_patch->GenerateImage(_u_isoparametric_div_count, _v_isoparametric_div_count);

            if (_images[index2])
                _images[index2]->UpdateVertexBufferObjects();

            _u_isoparametric_lines[index2] = cur_patch->GenerateUIsoparametricLines(_u_isoparametric_line_count, 2, _u_isoparametric_div_count);
            _v_isoparametric_lines[index2] = cur_patch->GenerateVIsoparametricLines(_v_isoparametric_line_count, 2, _v_isoparametric_div_count);

            for (GLuint i = 0; i < _u_isoparametric_lines[index2]->GetColumnCount(); i++)
            {
                (*_u_isoparametric_lines[index2])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            for (GLuint i = 0; i < _v_isoparametric_lines[index2]->GetColumnCount(); i++)
            {
                (*_v_isoparametric_lines[index2])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
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

    GLboolean CompositeTrigonometricPatch::joinPatches(GLuint patch_index_1, GLuint patch_index_2, Direction dir_1, Direction dir_2)
    {
        if (_neighbours[patch_index_1][dir_1] != nullptr || _neighbours[patch_index_2][dir_2] != nullptr)
        {
            cout << "Invalid szomszédok ezekből az irányokból!" << endl;
            return GL_FALSE;
        }

        // TODO itt az alfákkal lesz valami fikusz
        _patches[_nr_of_patches] = new (nothrow) SecondOrderTrigonometricPatch3();
        _materials[_nr_of_patches] = &MatFBRuby;

        switch(dir_1)
        {
            case N:
            {
                for (int i = 0; i < 4; i++)
                {
                    DCoordinate3 cp;
                    _patches[patch_index_1]->GetData(0, i, cp);
                    _patches[_nr_of_patches]->SetData(3, i, cp);
                }

                for (int i = 0; i < 4; i++)
                {
                    DCoordinate3 cp0, cp1;
                    _patches[patch_index_1]->GetData(0, i, cp0);
                    _patches[patch_index_1]->GetData(1, i, cp1);
                    _patches[_nr_of_patches]->SetData(2, i, 2 * cp0 - cp1);
                }

                switch (dir_2)
                {
                    case N:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(0, i, cp);
                            _patches[_nr_of_patches]->SetData(0, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(0, i, cp0);
                            _patches[patch_index_2]->GetData(1, i, cp1);
                            _patches[_nr_of_patches]->SetData(1, i, 2 * cp0 - cp1);
                        }

                        break;
                    }

                    case E:
                    {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(3 - i, 3, cp);
                            _patches[_nr_of_patches]->SetData(0, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(3 - i, 2, cp2);
                            _patches[patch_index_2]->GetData(3 - i, 3, cp3);
                            _patches[_nr_of_patches]->SetData(1, i, 2 * cp3 - cp2);
                        }

                        break;
                    }

                    case S:
                    {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(3, i, cp);
                            _patches[_nr_of_patches]->SetData(0, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(2, i, cp2);
                            _patches[patch_index_2]->GetData(3, i, cp3);
                            _patches[_nr_of_patches]->SetData(1, i, 2 * cp3 - cp2);
                        }

                        break;
                    }

                    case W:
                    {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(i, 0, cp);
                            _patches[_nr_of_patches]->SetData(0, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(i, 0, cp0);
                            _patches[patch_index_2]->GetData(i, 1, cp1);
                            _patches[_nr_of_patches]->SetData(1, i, 2 * cp0 - cp1);
                        }
                        break;
                    }
                }
                break;
            }

            case E:
            {

                for (int i = 0; i < 4; i++)
                {
                    DCoordinate3 cp;
                    _patches[patch_index_1]->GetData(i, 3, cp);
                    _patches[_nr_of_patches]->SetData(i, 0, cp);
                }

                for (int i = 0; i < 4; i++)
                {
                    DCoordinate3 cp2, cp3;
                    _patches[patch_index_1]->GetData(i, 2, cp2);
                    _patches[patch_index_1]->GetData(i, 3, cp3);
                    _patches[_nr_of_patches]->SetData(i, 1, 2 * cp3 - cp2);
                }

                switch (dir_2)
                {
                   case N:
                   {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(0, i, cp);
                            _patches[_nr_of_patches]->SetData(i, 3, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(0, i, cp0);
                            _patches[patch_index_2]->GetData(1, i, cp1);
                            _patches[_nr_of_patches]->SetData(i, 2, 2 * cp0 - cp1);
                        }
                        break;
                   }

                   case E:
                   {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(i, 3, cp);
                            _patches[_nr_of_patches]->SetData(i, 3, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(i, 2, cp2);
                            _patches[patch_index_2]->GetData(i, 3, cp3);
                            _patches[_nr_of_patches]->SetData(i, 2, 2 * cp3 - cp2);
                        }
                        break;
                   }

                   case S:
                   {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(3, i, cp);
                            _patches[_nr_of_patches]->SetData(i, 3, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(2, i, cp2);
                            _patches[patch_index_2]->GetData(3, i, cp3);
                            _patches[_nr_of_patches]->SetData(i, 2, 2 * cp3 - cp2);
                        }
                        break;
                   }

                   case W:
                   {

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(i, 0, cp);
                            _patches[_nr_of_patches]->SetData(i, 3, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(i, 0, cp0);
                            _patches[patch_index_2]->GetData(i, 1, cp1);
                            _patches[_nr_of_patches]->SetData(i, 2, 2 * cp0 - cp1);
                        }
                        break;
                   }
                }

                break;
            }

            case S:
            {
            for (int i = 0; i < 4; i++)
            {
                DCoordinate3 cp;
                _patches[patch_index_1]->GetData(3, i, cp);
                _patches[_nr_of_patches]->SetData(0, i, cp);
            }

            for (int i = 0; i < 4; i++)
            {
                DCoordinate3 cp2, cp3;
                _patches[patch_index_1]->GetData(2, i, cp2);
                _patches[patch_index_1]->GetData(3, i, cp3);
                _patches[_nr_of_patches]->SetData(1, i, 2 * cp3 - cp2);
            }

                switch (dir_2)
                {

                    case N:
                    {
                    for (int i = 0; i < 4; i++)
                    {
                        DCoordinate3 cp;
                        _patches[patch_index_2]->GetData(0, i, cp);
                        _patches[_nr_of_patches]->SetData(3, i, cp);
                    }

                    for (int i = 0; i < 4; i++)
                    {
                        DCoordinate3 cp0, cp1;
                        _patches[patch_index_2]->GetData(0, i, cp0);
                        _patches[patch_index_2]->GetData(1, i, cp1);
                        _patches[_nr_of_patches]->SetData(2, i, 2 * cp0 - cp1);
                    }
                        break;
                    }

                    case E:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(i, 3, cp);
                            _patches[_nr_of_patches]->SetData(3, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(i, 2, cp2);
                            _patches[patch_index_2]->GetData(i, 3, cp3);
                            _patches[_nr_of_patches]->SetData(2, i, 2 * cp3 - cp2);
                        }
                        break;
                    }

                    case S:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(3, i, cp);
                            _patches[_nr_of_patches]->SetData(3, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(2, i, cp2);
                            _patches[patch_index_2]->GetData(3, i, cp3);
                            _patches[_nr_of_patches]->SetData(2, i, 2 * cp3 - cp2);
                        }
                        break;
                    }

                    case W:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(3 - i, 0, cp);
                            _patches[_nr_of_patches]->SetData(3, i, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(3 - i, 0, cp0);
                            _patches[patch_index_2]->GetData(3 - i, 1, cp1);
                            _patches[_nr_of_patches]->SetData(2, i, 2 * cp0 - cp1);
                        }
                        break;
                    }
                }

                break;
            }

            case W:
            {

                for (int i = 0; i < 4; i++)
                {
                    DCoordinate3 cp;
                    _patches[patch_index_1]->GetData(i, 0, cp);
                    _patches[_nr_of_patches]->SetData(i, 3, cp);
                }

                for (int i = 0; i < 4; i++)
                {
                    DCoordinate3 cp0, cp1;
                    _patches[patch_index_1]->GetData(i, 0, cp0);
                    _patches[patch_index_1]->GetData(i, 1, cp1);
                    _patches[_nr_of_patches]->SetData(i, 2, 2 * cp0 - cp1);
                }

                switch (dir_2)
                {

                    case N:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(0, i, cp);
                            _patches[_nr_of_patches]->SetData(i, 0, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(0, i, cp0);
                            _patches[patch_index_2]->GetData(1, i, cp1);
                            _patches[_nr_of_patches]->SetData(i, 1, 2 * cp0 - cp1);
                        }
                        break;
                    }

                    case E:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(i, 3, cp);
                            _patches[_nr_of_patches]->SetData(i, 0, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(i, 2, cp2);
                            _patches[patch_index_2]->GetData(i, 3, cp3);
                            _patches[_nr_of_patches]->SetData(i, 1, 2 * cp3 - cp2);
                        }
                        break;
                    }


                    case S:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(3, i, cp);
                            _patches[_nr_of_patches]->SetData(i, 0, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp2, cp3;
                            _patches[patch_index_2]->GetData(2, i, cp2);
                            _patches[patch_index_2]->GetData(3, i, cp3);
                            _patches[_nr_of_patches]->SetData(i, 1, 2 * cp3 - cp2);
                        }
                        break;
                    }


                    case W:
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp;
                            _patches[patch_index_2]->GetData(i, 0, cp);
                            _patches[_nr_of_patches]->SetData(i, 0, cp);
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            DCoordinate3 cp0, cp1;
                            _patches[patch_index_2]->GetData(i, 0, cp0);
                            _patches[patch_index_2]->GetData(i, 1, cp1);
                            _patches[_nr_of_patches]->SetData(i, 1, 2 * cp0 - cp1);
                        }
                        break;
                    }
                    break;
                }

                break;
            }

            case NE:
            {

                DCoordinate3 cp03, cp02, cp13;
                _patches[patch_index_1]->GetData(0, 3, cp03);
                _patches[patch_index_1]->GetData(0, 2, cp02);
                _patches[patch_index_1]->GetData(1, 3, cp13);
                for(int i = 0; i < 3; i++)
                {
                    _patches[_nr_of_patches]->SetData(3, i, cp03 + i * (cp03 - cp02));
                    _patches[_nr_of_patches]->SetData(3 - i, 0, cp03 + i * (cp03 - cp13));
                }

                DCoordinate3 black00, red33, black33, red00;
                black00 = cp03 + 3 * (cp03 - cp13);
                red33 = cp03 + 3 * (cp03 - cp02);

                switch (dir_2)
                {

                    case SW:
                    {
                        DCoordinate3 cp30, cp20, cp31;
                        _patches[patch_index_2]->GetData(3, 0, cp30);
                        _patches[patch_index_2]->GetData(2, 0, cp20);
                        _patches[patch_index_2]->GetData(3, 1, cp31);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(0, 3 - i, cp30 + i * (cp30 - cp31));
                            _patches[_nr_of_patches]->SetData(i, 3, cp30 + i * (cp30 - cp20));
                        }

                        black33 = cp30 + 3 * (cp30 - cp20);
                        red00 = cp30 + 3 * (cp30 - cp31);
                        break;
                    }

                    case NW:
                    {
                        DCoordinate3 cp00, cp10, cp01;
                        _patches[patch_index_2]->GetData(0, 0, cp00);
                        _patches[patch_index_2]->GetData(1, 0, cp10);
                        _patches[patch_index_2]->GetData(0, 1, cp01);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(0, 3 - i, cp00 + i * (cp00 - cp01));
                            _patches[_nr_of_patches]->SetData(i, 3, cp00 + i * (cp10 - cp00));
                        }

                        black33 = cp00 + 3 * (cp10 - cp00);
                        red00 = cp00 + 3 * (cp00 - cp10);
                        break;
                    }

                    case SE:
                    {
                        DCoordinate3 cp33, cp23, cp32;
                        _patches[patch_index_2]->GetData(3, 3, cp33);
                        _patches[patch_index_2]->GetData(2, 3, cp23);
                        _patches[patch_index_2]->GetData(3, 2, cp32);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(0, 3 - i, cp33 + i * (cp32 - cp33));
                            _patches[_nr_of_patches]->SetData(i, 3, cp33 + i * (cp33 - cp23));
                        }

                        black33 = cp33 + 3 * (cp33 - cp32);
                        red00 = cp33 + 3 * (cp32 - cp33);
                    }

                    case NE:
                    {
                        DCoordinate3 cp03, cp02, cp13;
                        _patches[patch_index_2]->GetData(0, 3, cp03);
                        _patches[patch_index_2]->GetData(0, 2, cp02);
                        _patches[patch_index_2]->GetData(1, 3, cp13);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(0, 3 - i, cp03 + i * (cp02 - cp03));
                            _patches[_nr_of_patches]->SetData(i, 3, cp03 + i * (cp13 - cp03));
                        }

                        black00 = cp03 + 3 * (cp02 - cp03);
                        red33 = cp03 + 3 * (cp13 - cp03);
                    }

                }
                _patches[_nr_of_patches]->SetData(0, 0, 0.5 * (black00 + red00));
                _patches[_nr_of_patches]->SetData(3, 3, 0.5 * (black33 + red33));
                (*_patches[_nr_of_patches])(1, 1) = 0.5 * (*_patches[_nr_of_patches])(1, 0) + 1 / 3 * (*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * (*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1);
               (*_patches[_nr_of_patches])(1, 2) = 0.5 * (*_patches[_nr_of_patches])(1, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 2) + 1 / 3 * (*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2);
                (*_patches[_nr_of_patches])(2, 1) = 0.5 * (*_patches[_nr_of_patches])(2, 0) + 1 / 3 * (*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * (*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1);
                (*_patches[_nr_of_patches])(2, 2) = 0.5 * (*_patches[_nr_of_patches])(2, 0) + 2 / 3 * (*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0) + (*_patches[_nr_of_patches])(0, 1) + 2 / 3 * (*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2);
                 break;
            }

            case SW:
            {

                DCoordinate3 cp30, cp20, cp31;
                _patches[patch_index_1]->GetData(3, 0, cp30);
                _patches[patch_index_1]->GetData(2, 0, cp20);
                _patches[patch_index_1]->GetData(3, 1, cp31);
                for(int i = 0; i < 3; i++)
                {
                    _patches[_nr_of_patches]->SetData(0, 3 - i, cp30 + i * (cp30 - cp31));
                    _patches[_nr_of_patches]->SetData(i, 3, cp30 + i * (cp30 - cp20));
                }

                DCoordinate3 fekete00, piros00, fekete33, piros33;
                fekete33 = cp30 + 3 * (cp30 - cp20);
                piros00 = cp30 + 3 * (cp30 - cp31);

                switch (dir_2)
                {

                    case NE:
                    {
                        DCoordinate3 cp03, cp02, cp13;
                        _patches[patch_index_2]->GetData(0, 3, cp03);
                        _patches[patch_index_2]->GetData(0, 2, cp02);
                        _patches[patch_index_2]->GetData(1, 3, cp13);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(3, i, cp03 + i * (cp03 - cp02));
                            _patches[_nr_of_patches]->SetData(3 - i, 0, cp03 + i * (cp03 - cp13));
                        }

                        fekete00 = cp03 + 3 * (cp03 - cp13);
                        piros33 = cp03 + 3 * (cp03 - cp02);
                        break;
                    }

                    case SW:
                    {
                        DCoordinate3 cp30, cp20, cp31;
                        _patches[patch_index_2]->GetData(3, 0, cp30);
                        _patches[patch_index_2]->GetData(2, 0, cp20);
                        _patches[patch_index_2]->GetData(3, 1, cp31);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(3 - i, 0, cp30 + i * (cp20 - cp30));
                            _patches[_nr_of_patches]->SetData(3, i, cp30 + i * (cp31 - cp30));
                        }

                        fekete33 = cp30 + 3 * (cp31 - cp30);
                        piros00 = cp30 + 3 * (cp20 - cp30);
                        break;
                    }

                    case NW:
                    {
                        DCoordinate3 cp00, cp10, cp01;
                        _patches[patch_index_2]->GetData(0, 0, cp00);
                        _patches[patch_index_2]->GetData(1, 0, cp10);
                        _patches[patch_index_2]->GetData(0, 1, cp01);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(3 - i, 0, cp00 + i * (cp00 - cp10));
                            _patches[_nr_of_patches]->SetData(3, i, cp00 + i * (cp01 - cp00));
                        }

                        fekete33 = cp00 + 3 * (cp01 - cp00);
                        piros00 = cp00 + 3 * (cp00 - cp10);
                        break;
                    }

                    case SE:
                    {
                        DCoordinate3 cp33, cp23, cp32;
                        _patches[patch_index_2]->GetData(3, 3, cp33);
                        _patches[patch_index_2]->GetData(2, 3, cp23);
                        _patches[patch_index_2]->GetData(3, 2, cp32);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(3 - i, 0, cp33 + i * (cp23 - cp33));
                            _patches[_nr_of_patches]->SetData(3, i, cp33 + i * (cp33 - cp32));
                        }

                        fekete33 = cp33 + 3 * (cp33 - cp32);
                        piros00 = cp33 + 3 * (cp23 - cp33);
                        break;
                    }
                }

                _patches[_nr_of_patches]->SetData(0, 0, 0.5 * (fekete00 + piros00));
                _patches[_nr_of_patches]->SetData(3, 3, 0.5 * (fekete33 + piros33));

                (*_patches[_nr_of_patches])(1, 1) = 0.5 * ((*_patches[_nr_of_patches])(1, 0) + 1 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1)));
                (*_patches[_nr_of_patches])(1, 2) = 0.5 * ((*_patches[_nr_of_patches])(1, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 2) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2)));
                (*_patches[_nr_of_patches])(2, 1) = 0.5 * ((*_patches[_nr_of_patches])(2, 0) + 1 / 3 * ((*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0)) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1)));
                (*_patches[_nr_of_patches])(2, 2) = 0.5 * ((*_patches[_nr_of_patches])(2, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0)) + (*_patches[_nr_of_patches])(0, 1) + 2 / 3 * ((*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2)));
                break;
            }

            case NW:
            {

                DCoordinate3 cp00, cp01, cp10;
                _patches[patch_index_1]->GetData(0, 0, cp00);
                _patches[patch_index_1]->GetData(0, 1, cp01);
                _patches[patch_index_1]->GetData(1, 0, cp10);
                for(int i = 0; i < 3; i++)
                {
                    _patches[patch_index_1]->SetData(3, 3 - i, cp00 + i * (cp00 - cp01));
                    _patches[patch_index_1]->SetData(3 - i, 3, cp00 + i * (cp00 - cp10));
                }

                DCoordinate3 fekete30, piros30, fekete03, piros03;
                fekete30 = cp00 + 3 * (cp00 - cp01);
                piros03 = cp00 + 3 * (cp00 - cp10);

                switch (dir_2)
                {
                    case SE:
                    {
                        DCoordinate3 cp33, cp23, cp32;
                        _patches[patch_index_2]->GetData(3, 3, cp33);
                        _patches[patch_index_2]->GetData(2, 3, cp23);
                        _patches[patch_index_2]->GetData(3, 2, cp32);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[patch_index_2]->SetData(0, i, cp33 + i * (cp33 - cp32));
                            _patches[patch_index_2]->SetData(i, 0, cp33 + i * (cp33 - cp23));
                        }

                        fekete03 = cp33 + 3 * (cp33 - cp32);
                        piros30 = cp33 + 3 * (cp33 - cp23);
                        break;
                    }

                    case NW:
                    {
                        DCoordinate3 cp00, cp01, cp10;
                        _patches[patch_index_2]->GetData(0, 0, cp00);
                        _patches[patch_index_2]->GetData(0, 1, cp01);
                        _patches[patch_index_2]->GetData(1, 0, cp10);
                        for(int i = 0; i < 3; i++)
                        {
                            _patches[_nr_of_patches]->SetData(0, i, cp00 + i * (cp01 - cp00));
                            _patches[_nr_of_patches]->SetData(i, 0, cp00 + i * (cp10 - cp00));
                        }

                        fekete30 = cp00 + 3 * (cp10 - cp00);
                        piros03 = cp00 + 3 * (cp01 - cp00);
                        break;
                    }

                    case NE:
                    {
                        DCoordinate3 cp03, cp02, cp13;
                        _patches[patch_index_2]->GetData(0, 3, cp03);
                        _patches[patch_index_2]->GetData(0, 2, cp02);
                        _patches[patch_index_2]->GetData(1, 3, cp13);
                        for(int i = 0; i < 3; i++)
                        {
                          _patches[_nr_of_patches]->SetData(0, i, cp03 + i * (cp03 - cp02));
                          _patches[_nr_of_patches]->SetData(i, 3, cp03 + i * (cp13 - cp03));
                        }

                        fekete30 = cp03 + 3 * (cp13 - cp03);
                        piros03 = cp03 + 3 * (cp03 - cp02);
                        break;
                    }

                    case SW:
                    {
                        DCoordinate3 cp30, cp20, cp31;
                        _patches[patch_index_2]->GetData(3, 0, cp30);
                        _patches[patch_index_2]->GetData(2, 0, cp20);
                        _patches[patch_index_2]->GetData(3, 1, cp31);
                        for(int i = 0; i < 3; i++)
                        {
                          _patches[_nr_of_patches]->SetData(0, i, cp30 + i * (cp31 - cp30));
                          _patches[_nr_of_patches]->SetData(i, 3, cp30 + i * (cp30 - cp20));
                        }

                        fekete30 = cp30 + 3 * (cp30 - cp20);
                        piros03 = cp30 + 3 * (cp31 - cp30);
                        break;
                    }
                }

                (*_patches[_nr_of_patches]).SetData(3, 0, 0.5 * (fekete30 + piros30));
                (*_patches[_nr_of_patches]).SetData(0, 3, 0.5 * (fekete03 + piros03));

                (*_patches[_nr_of_patches])(1, 1) = 0.5 * ((*_patches[_nr_of_patches])(1, 0) + 1 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1)));
                (*_patches[_nr_of_patches])(1, 2) = 0.5 * ((*_patches[_nr_of_patches])(1, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 2) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2)));
                (*_patches[_nr_of_patches])(2, 1) = 0.5 * ((*_patches[_nr_of_patches])(2, 0) + 1 / 3 * ((*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0)) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1)));
                (*_patches[_nr_of_patches])(2, 2) = 0.5 * ((*_patches[_nr_of_patches])(2, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0)) + (*_patches[_nr_of_patches])(0, 1) + 2 / 3 * ((*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2)));
                break;
            }

            case SE:
            {

                DCoordinate3 cp33, cp23, cp32;
                _patches[patch_index_1]->GetData(3, 3, cp33);
                _patches[patch_index_1]->GetData(2, 3, cp23);
                _patches[patch_index_1]->GetData(3, 2, cp32);
                for(int i = 0; i < 3; i++)
                {
                    _patches[_nr_of_patches]->SetData(0, i, cp33 + i * (cp33 - cp32));
                    _patches[_nr_of_patches]->SetData(i, 0, cp33 + i * (cp33 - cp23));
                }

                DCoordinate3 fekete30, piros30, fekete03, piros03;
                fekete03 = cp33 + 3 * (cp33 - cp32);
                piros30 = cp33 + 3 * (cp33 - cp23);

                switch (dir_2)
                {

                    case NW:
                    {
                        DCoordinate3 cp00, cp01, cp10;
                        _patches[patch_index_2]->GetData(0, 0, cp00);
                        _patches[patch_index_2]->GetData(0, 1, cp01);
                        _patches[patch_index_2]->GetData(1, 0, cp10);
                        for(int i = 0; i < 3; i++)
                        {
                          _patches[_nr_of_patches]->SetData(3, 3 - i, cp00 + i * (cp00 - cp01));
                          _patches[_nr_of_patches]->SetData(3 - i, 3, cp00 + i * (cp00 - cp10));
                        }

                        DCoordinate3 fekete30, piros30, fekete03, piros03;
                        fekete30 = cp00 + 3 * (cp00 - cp01);
                        piros03 = cp00 + 3 * (cp00 - cp10);
                        break;
                    }

                    case NE:
                    {
                        DCoordinate3 cp03, cp02, cp13;
                        _patches[patch_index_2]->GetData(0, 3, cp03);
                        _patches[patch_index_2]->GetData(0, 2, cp02);
                        _patches[patch_index_2]->GetData(1, 3, cp13);
                        for(int i = 0; i < 3; i++)
                        {
                          _patches[_nr_of_patches]->SetData(3, 3 - i, cp03 + i * (cp02 - cp03));
                          _patches[patch_index_2]->SetData(3 - i, 3, cp03 + i * (cp03 - cp13));
                        }

                        fekete30 = cp03 + 3 * (cp02 - cp03);
                        piros03 = cp03 + 3 * (cp03 - cp13);
                        break;
                    }

                    case SE:
                    {
                        DCoordinate3 cp33, cp23, cp32;
                        _patches[patch_index_2]->GetData(3, 3, cp33);
                        _patches[patch_index_2]->GetData(2, 3, cp23);
                        _patches[patch_index_2]->GetData(3, 2, cp32);
                        for(int i = 0; i < 3; i++)
                        {
                          _patches[_nr_of_patches]->SetData(3, 3 - i, cp33 + i * (cp32 - cp33));
                          _patches[_nr_of_patches]->SetData(3 - i, 3, cp33 + i * (cp23 - cp33));
                        }

                        fekete03 = cp33 + 3 * (cp23 - cp33);
                        piros30 = cp33 + 3 * (cp32 - cp33);
                        break;
                    }

                    case SW:
                    {
                        DCoordinate3 cp30, cp20, cp31;
                        _patches[patch_index_2]->GetData(3, 0, cp30);
                        _patches[patch_index_2]->GetData(2, 0, cp20);
                        _patches[patch_index_2]->GetData(3, 1, cp31);
                        for(int i = 0; i < 3; i++)
                        {
                          _patches[_nr_of_patches]->SetData(3, 3 - i, cp30 + i * (cp30 - cp31));
                          _patches[_nr_of_patches]->SetData(3 - i, 3, cp30 + i * (cp20 - cp30));
                        }

                        fekete30 = cp30 + 3 * (cp30 - cp31);
                        piros03 = cp30 + 3 * (cp20 - cp30);
                        break;
                    }
                }

                _patches[_nr_of_patches]->SetData(3, 0, 0.5 * (fekete30 + piros30));
                _patches[_nr_of_patches]->SetData(0, 3, 0.5 * (fekete03 + piros03));

                (*_patches[_nr_of_patches])(1, 1) = 0.5 * ((*_patches[_nr_of_patches])(1, 0) + 1 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1)));
                (*_patches[_nr_of_patches])(1, 2) = 0.5 * ((*_patches[_nr_of_patches])(1, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(1, 3) - (*_patches[_nr_of_patches])(1, 0)) + (*_patches[_nr_of_patches])(0, 2) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2)));
                (*_patches[_nr_of_patches])(2, 1) = 0.5 * ((*_patches[_nr_of_patches])(2, 0) + 1 / 3 * ((*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0)) + (*_patches[_nr_of_patches])(0, 1) + 1 / 3 * ((*_patches[_nr_of_patches])(3, 1) - (*_patches[_nr_of_patches])(0, 1)));
                (*_patches[_nr_of_patches])(2, 2) = 0.5 * ((*_patches[_nr_of_patches])(2, 0) + 2 / 3 * ((*_patches[_nr_of_patches])(2, 3) - (*_patches[_nr_of_patches])(2, 0)) + (*_patches[_nr_of_patches])(0, 1) + 2 / 3 * ((*_patches[_nr_of_patches])(3, 2) - (*_patches[_nr_of_patches])(0, 2)));

                break;
            }

        }

        _neighbours[_nr_of_patches][dir_1] = _patches[patch_index_1];
        _neighbours[_nr_of_patches][dir_2] = _patches[patch_index_2];
        _connection_types[_nr_of_patches][dir_1] = dir_1;
        _connection_types[_nr_of_patches][dir_2] = dir_2;

        _neighbours[patch_index_1][dir_1] = _patches[_nr_of_patches];
        _connection_types[_nr_of_patches][dir_1] = dir_2;

        _neighbours[patch_index_2][dir_2] = _patches[_nr_of_patches];
        _connection_types[_nr_of_patches][dir_2] = dir_1;

        _patches[_nr_of_patches]->UpdateVertexBufferObjectsOfData();

        _images[_nr_of_patches] = _patches[_nr_of_patches]->GenerateImage(_uDivPointCount, _vDivPointCount, GL_STATIC_DRAW);

        if (_images[_nr_of_patches])
            _images[_nr_of_patches]->UpdateVertexBufferObjects();

        _patches[_nr_of_patches]->UpdateVertexBufferObjectsOfData();

        _u_isoparametric_lines[_nr_of_patches] = _patches[_nr_of_patches]->GenerateUIsoparametricLines(_uIsoLineCount, 2, _uDivPointCount);
        _v_isoparametric_lines[_nr_of_patches] = _patches[_nr_of_patches]->GenerateVIsoparametricLines(_vIsoLineCount, 2, _vDivPointCount);

        for (GLuint i = 0; i < _u_isoparametric_lines[_nr_of_patches]->GetColumnCount(); i++)
        {
            (*_u_isoparametric_lines[_nr_of_patches])[i]->UpdateVertexBufferObjects();
        }

        for (GLuint i = 0; i < _v_isoparametric_lines[_nr_of_patches]->GetColumnCount(); i++)
        {
            (*_v_isoparametric_lines[_nr_of_patches])[i]->UpdateVertexBufferObjects();
        }

        _nr_of_patches++;

        return GL_TRUE;
    }


    void CompositeTrigonometricPatch::translateSelectedPatch(GLuint index, GLuint coord, double value)
    {
        for (GLuint i = 0; i < 4; i ++)
        {
            for (GLuint j = 0; j < 4; j ++)
            {
                (*_patches[index])(i, j)[coord] += value;
            }
        }
        _updateData();
    }

    void CompositeTrigonometricPatch::moveCp(int index, int row, int column, bool& new_img, Direction &dir)
    {
        new_img = false;
        DCoordinate3 cp;
        _patches[index]->GetData(row, column, cp);
        if (row == 0 && column == 1)
        {
            if(_neighbours[index][N] != nullptr)
            {
                new_img = true;
                dir = N;
                if(_connection_types[index][N] == N)
                {
                    _neighbours[index][N]->SetData(0, 1, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][N]->SetData(1, 1, 2 * cp - cp11);
                }

                if(_connection_types[index][N] == E)
                {
                    _neighbours[index][N]->SetData(2, 3, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][N]->SetData(2, 2, 2 * cp - cp11);
                }

                if(_connection_types[index][N] == S)
                {
                    _neighbours[index][N]->SetData(3, 1, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][N]->SetData(2, 1, 2 * cp - cp11);
                }

                if(_connection_types[index][N] == W)
                {
                    _neighbours[index][N]->SetData(2, 0, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][N]->SetData(2, 1, 2 * cp - cp11);
                }
            }
        }

        if (row == 0 && column == 2)
        {

            if (_neighbours[index][N] != nullptr)
            {
                new_img = true;
                dir = N;

                if(_connection_types[index][N] == N)
                {
                    _neighbours[index][N]->SetData(0, 2, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][N]->SetData(1, 2, 2 * cp - cp12);
                }

                if(_connection_types[index][N] == E)
                {
                    _neighbours[index][N]->SetData(1, 3, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][N]->SetData(1, 2, 2 * cp - cp12);
                }

                if(_connection_types[index][N] == S)
                {
                    _neighbours[index][N]->SetData(3, 2, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][N]->SetData(2, 2, 2 * cp - cp12);
                }

                if(_connection_types[index][N] == W)
                {
                    _neighbours[index][N]->SetData(2, 0, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][N]->SetData(2, 1, 2 * cp - cp12);
                }
            }

        }

        if (row == 1 && column == 0)
        {

            if (_neighbours[index][W] != nullptr)
            {
                new_img = true;
                dir = W;

                if(_connection_types[index][W] == N)
                {
                    _neighbours[index][W]->SetData(0, 1, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][W]->SetData(1, 1, 2 * cp - cp11);
                }

                if(_connection_types[index][W] == E)
                {
                    _neighbours[index][W]->SetData(1, 3, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][W]->SetData(1, 2, 2 * cp - cp11);
                }

                if(_connection_types[index][W] == S)
                {
                    _neighbours[index][W]->SetData(3, 2, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][W]->SetData(2, 2, 2 * cp - cp11);
                }

                if(_connection_types[index][W] == W)
                {
                    _neighbours[index][W]->SetData(1, 0, cp);

                    DCoordinate3 cp11 = (*_patches[index])(1, 1);

                    _neighbours[index][W]->SetData(1, 1, 2 * cp - cp11);
                }
            }
        }

        if (row == 1 && column == 3)
        {

            if (_neighbours[index][E] != nullptr)
            {
                new_img = true;
                dir = E;

                if (_connection_types[index][E] == N)
                {
                    _neighbours[index][E]->SetData(0, 2, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][E]->SetData(1, 2, 2 * cp - cp12);
                }

                if (_connection_types[index][E] == E)
                {
                    _neighbours[index][E]->SetData(1, 3, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][E]->SetData(1, 2, 2 * cp - cp12);
                }

                if (_connection_types[index][E] == W)
                {
                    _neighbours[index][E]->SetData(1, 0, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][E]->SetData(1, 1, 2 * cp - cp12);
                }

                if (_connection_types[index][E] == S)
                {
                    _neighbours[index][E]->SetData(3, 1, cp);

                    DCoordinate3 cp12 = (*_patches[index])(1, 2);

                    _neighbours[index][E]->SetData(2, 1, 2 * cp - cp12);
                }
            }
        }

        if (row == 2 && column == 0)
        {
            if (_neighbours[index][W] != nullptr)
            {
                new_img = true;
                dir = W;

                if(_connection_types[index][W] == N)
                {
                    _neighbours[index][W]->SetData(0, 2, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][W]->SetData(1, 2, 2 * cp - cp21);
                }

                if(_connection_types[index][W] == E)
                {
                    _neighbours[index][W]->SetData(2, 3, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][W]->SetData(2, 2, 2 * cp - cp21);
                }

                if(_connection_types[index][W] == S)
                {
                    _neighbours[index][W]->SetData(3, 1, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][W]->SetData(2, 1, 2 * cp - cp21);
                }

                if(_connection_types[index][W] == W)
                {
                    _neighbours[index][W]->SetData(2, 0, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][W]->SetData(2, 1, 2 * cp - cp21);
                }
            }
        }

        if (row == 2 && column == 3)
        {

            if (_neighbours[index][E] != nullptr)
            {
                new_img = true;
                dir = E;

                if (_connection_types[index][E] == N)
                {
                    _neighbours[index][E]->SetData(0, 1, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][E]->SetData(1, 1, 2 * cp - cp22);
                }

                if (_connection_types[index][E] == E)
                {
                    _neighbours[index][E]->SetData(2, 3, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][E]->SetData(2, 2, 2 * cp - cp22);
                }

                if (_connection_types[index][E] == W)
                {
                    _neighbours[index][E]->SetData(2, 0, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][E]->SetData(2, 1, 2 * cp - cp22);
                }

                if (_connection_types[index][E] == S)
                {
                    _neighbours[index][E]->SetData(3, 2, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][E]->SetData(2, 2, 2 * cp - cp22);
                }
            }
        }

        if (row == 3 && column == 1)
        {
            if (_neighbours[index][S] != nullptr)
            {
                new_img = true;
                dir = S;

                if (_connection_types[index][S] == N)
                {
                    _neighbours[index][S]->SetData(0, 1, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][S]->SetData(1, 1, 2 * cp - cp21);
                }

                if (_connection_types[index][S] == E)
                {
                    _neighbours[index][S]->SetData(1, 3, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][S]->SetData(1, 2, 2 * cp - cp21);
                }

                if (_connection_types[index][S] == W)
                {
                    _neighbours[index][S]->SetData(2, 0, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][S]->SetData(2, 1, 2 * cp - cp21);
                }

                if (_connection_types[index][S] == S)
                {
                    _neighbours[index][S]->SetData(3, 1, cp);

                    DCoordinate3 cp21 = (*_patches[index])(2, 1);

                    _neighbours[index][S]->SetData(2, 1, 2 * cp - cp21);
                }
            }
        }

        if (row == 3 && column == 2)
        {
            if (_neighbours[index][S] != nullptr)
            {
                new_img = true;
                dir = S;

                if (_connection_types[index][S] == N)
                {
                    _neighbours[index][S]->SetData(0, 2, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][S]->SetData(1, 2, 2 * cp - cp22);
                }

                if (_connection_types[index][S] == E)
                {
                    _neighbours[index][S]->SetData(2, 3, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][S]->SetData(2, 2, 2 * cp - cp22);
                }

                if (_connection_types[index][S] == W)
                {
                    _neighbours[index][S]->SetData(1, 0, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][S]->SetData(1, 1, 2 * cp - cp22);
                }

                if (_connection_types[index][S] == S)
                {
                    _neighbours[index][S]->SetData(3, 2, cp);

                    DCoordinate3 cp22 = (*_patches[index])(2, 2);

                    _neighbours[index][S]->SetData(2, 2, 2 * cp - cp22);
                }
            }
        }

    }

    void CompositeTrigonometricPatch::Modify(int coord, int index, double value, int selected_row, int selected_column)
    {
        if (_patches[index] == nullptr)
        {
            return;
        }
        DCoordinate3 cp;

        _patches[index]->GetData(selected_row, selected_column, cp);
        switch (coord)
        {
            case 0:
                cp[0] = value;
                break;
            case 1:
                cp[1] = value;
                break;
            case 2:
                cp[2] = value;
                break;
            default:
                break;
        }

        int r = selected_row;
        int c = selected_column;


        if ((r == 0 && c == 0 && _neighbours[index][NW] == nullptr && _neighbours[index][N] == nullptr && _neighbours[index][W] == nullptr) ||
                (r == 0 && c == 3 && _neighbours[index][NE] == nullptr && _neighbours[index][N] == nullptr && _neighbours[index][E] == nullptr) ||
                (r == 3 && c == 0 && _neighbours[index][SW] == nullptr && _neighbours[index][S] == nullptr && _neighbours[index][W] == nullptr) ||
                (r == 3 && c == 3 && _neighbours[index][SE] == nullptr && _neighbours[index][S] == nullptr && _neighbours[index][E] == nullptr) ||
                (r == 0 && c == 1 && _neighbours[index][N] == nullptr && _neighbours[index][NW] == nullptr) ||
                (r == 0 && c == 2 && _neighbours[index][N] == nullptr && _neighbours[index][NE] == nullptr) ||
                (r == 1 && c == 0 && _neighbours[index][W] == nullptr && _neighbours[index][NW] == nullptr) ||
                (r == 2 && c == 0 && _neighbours[index][W] == nullptr && _neighbours[index][SW] == nullptr) ||
                (r == 3 && c == 1 && _neighbours[index][S] == nullptr && _neighbours[index][SW] == nullptr) ||
                (r == 3 && c == 2 && _neighbours[index][S] == nullptr && _neighbours[index][SE] == nullptr) ||
                (r == 2 && c == 3 && _neighbours[index][E] == nullptr && _neighbours[index][SE] == nullptr) ||
                (r == 1 && c == 3 && _neighbours[index][E] == nullptr && _neighbours[index][NE] == nullptr) ||
                (r == 1 && c == 1 && _neighbours[index][N] == nullptr && _neighbours[index][W] == nullptr) ||
                (r == 2 && c == 1 && _neighbours[index][W] == nullptr && _neighbours[index][S] == nullptr) ||
                (r == 1 && c == 2 && _neighbours[index][N] == nullptr && _neighbours[index][E] == nullptr) ||
                (r == 2 && c == 2 && _neighbours[index][E] == nullptr && _neighbours[index][S] == nullptr))
        {

            if (_images[index])
            {
                delete _images[index]; _images[index] = nullptr;
            }

            _patches[index]->SetData(selected_row, selected_column, cp);

            _images[index] = _patches[index]->GenerateImage(_uDivPointCount, _vDivPointCount, GL_STATIC_DRAW);

            if (_images[index])
                _images[index]->UpdateVertexBufferObjects();

            _u_isoparametric_lines[index] = _patches[index]->GenerateUIsoparametricLines(_uIsoLineCount, 2, _uDivPointCount);
            _v_isoparametric_lines[index] = _patches[index]->GenerateUIsoparametricLines(_vIsoLineCount, 2, _vDivPointCount);

            for (GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            for (GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                (*_v_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }


            //_patch.GetData(_selected_row_index, _selected_column_index, data_points_to_interpolate(_selected_row_index, _selected_column_index));
            _patches[index]->UpdateVertexBufferObjectsOfData();
            }

            bool new_image_1 = false;
            bool new_image_2 = false;
            bool new_image_3 = false;

            Direction direction_1, direction_2, direction_3;

            _patches[index]->SetData(r, c, cp);

            moveCp(index, r, c, new_image_1, direction_1);

            if (r == 0 && c == 0)
            {

                if (_neighbours[index][NW] != nullptr)
                {
                    new_image_1 = true;
                    direction_1 = NW;

                    if (_connection_types[index][NW] == NW)
                    {
                        _neighbours[index][NW]->SetData(0, 0, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);
                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][NW]->SetData(0, 1, 2 * cp - cp01);
                        _neighbours[index][NW]->SetData(1, 0, 2 * cp - cp10);
                    }

                    if (_connection_types[index][NW] == NE)
                    {
                        _neighbours[index][NW]->SetData(0, 3, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);
                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][NW]->SetData(0, 2, 2 * cp - cp01);
                        _neighbours[index][NW]->SetData(1, 3, 2 * cp - cp10);
                    }

                    if (_connection_types[index][NW] == SW)
                    {
                        _neighbours[index][NW]->SetData(3, 0, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);
                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][NW]->SetData(3, 1, 2 * cp - cp01);
                        _neighbours[index][NW]->SetData(2, 0, 2 * cp - cp10);
                    }

                    if (_connection_types[index][NW] == SE)
                    {
                        _neighbours[index][NW]->SetData(3, 3, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);
                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][NW]->SetData(3, 2, 2 * cp - cp01);
                        _neighbours[index][NW]->SetData(2, 3, 2 * cp - cp10);
                    }
                }

                if (_neighbours[index][N] != nullptr)
                {
                    new_image_2 = true;
                    direction_2 = N;

                    if(_connection_types[index][N] == N)
                    {
                        _neighbours[index][N]->SetData(0, 0, cp);

                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][N]->SetData(1, 0, 2 * cp - cp10);
                    }

                    if(_connection_types[index][N] == E)
                    {
                        _neighbours[index][N]->SetData(3, 3, cp);

                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][N]->SetData(3, 2, 2 * cp - cp10);
                    }

                    if(_connection_types[index][N] == S)
                    {
                        _neighbours[index][N]->SetData(3, 0, cp);

                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][N]->SetData(2, 0, 2 * cp - cp10);
                    }

                    if(_connection_types[index][N] == W)
                    {
                        _neighbours[index][N]->SetData(3, 0, cp);

                        DCoordinate3 cp10 = (*_patches[index])(1, 0);

                        _neighbours[index][N]->SetData(3, 1, 2 * cp - cp10);
                    }
                }


                if (_neighbours[index][W] != nullptr)
                {
                    new_image_3 = true;
                    direction_3 = W;

                    if(_connection_types[index][W] == N)
                    {
                        _neighbours[index][W]->SetData(0, 0, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);

                        _neighbours[index][W]->SetData(1, 0, 2 * cp - cp01);
                    }

                    if(_connection_types[index][W] == E)
                    {
                        _neighbours[index][W]->SetData(0, 3, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);

                        _neighbours[index][W]->SetData(0, 2, 2 * cp - cp01);
                    }

                    if(_connection_types[index][W] == S)
                    {
                        _neighbours[index][W]->SetData(3, 3, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);

                        _neighbours[index][W]->SetData(2, 3, 2 * cp - cp01);
                    }

                    if(_connection_types[index][W] == W)
                    {
                        _neighbours[index][W]->SetData(0, 0, cp);

                        DCoordinate3 cp01 = (*_patches[index])(0, 1);

                        _neighbours[index][W]->SetData(0, 1, 2 * cp - cp01);
                    }
                }
            }

            if (r == 0 && c == 3)
            {

                if (_neighbours[index][NE] != nullptr)
                {
                    new_image_1 = true;
                    direction_1 = NE;

                    if (_connection_types[index][NE] == NW)
                    {
                        _neighbours[index][NE]->SetData(0, 0, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);
                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][NE]->SetData(0, 1, 2 * cp - cp02);
                        _neighbours[index][NE]->SetData(1, 0, 2 * cp - cp13);
                    }

                    if (_connection_types[index][NE] == NE)
                    {
                        _neighbours[index][NE]->SetData(0, 3, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);
                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][NE]->SetData(0, 2, 2 * cp - cp02);
                        _neighbours[index][NE]->SetData(1, 3, 2 * cp - cp13);
                    }

                    if (_connection_types[index][NE] == SW)
                    {
                        _neighbours[index][NE]->SetData(3, 0, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);
                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][NE]->SetData(3, 1, 2 * cp - cp02);
                        _neighbours[index][NE]->SetData(2, 0, 2 * cp - cp13);
                    }

                    if (_connection_types[index][NE] == SE)
                    {
                        _neighbours[index][NE]->SetData(3, 3, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);
                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][NE]->SetData(3, 2, 2 * cp - cp02);
                        _neighbours[index][NE]->SetData(2, 3, 2 * cp - cp13);
                    }
                }


                if (_neighbours[index][N] != nullptr)
                {
                    new_image_2 = true;
                    direction_2 = N;

                    if(_connection_types[index][N] == N)
                    {
                        _neighbours[index][N]->SetData(0, 3, cp);

                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][N]->SetData(1, 3, 2 * cp - cp13);
                    }

                    if(_connection_types[index][N] == E)
                    {
                        _neighbours[index][N]->SetData(0, 3, cp);

                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][N]->SetData(0, 2, 2 * cp - cp13);
                    }

                    if(_connection_types[index][N] == S)
                    {
                        _neighbours[index][N]->SetData(3, 3, cp);

                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][N]->SetData(2, 3, 2 * cp - cp13);
                    }

                    if(_connection_types[index][N] == W)
                    {
                        _neighbours[index][N]->SetData(3, 0, cp);

                        DCoordinate3 cp13 = (*_patches[index])(1, 3);

                        _neighbours[index][N]->SetData(3, 1, 2 * cp - cp13);
                    }
                }


                if (_neighbours[index][E] != nullptr)
                {
                    new_image_3 = true;
                    direction_3 = E;

                    if (_connection_types[index][E] == N)
                    {
                        _neighbours[index][E]->SetData(0, 3, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);

                        _neighbours[index][E]->SetData(1, 3, 2 * cp - cp02);
                    }

                    if (_connection_types[index][E] == E)
                    {
                        _neighbours[index][E]->SetData(0, 3, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);

                        _neighbours[index][E]->SetData(0, 2, 2 * cp - cp02);
                    }

                    if (_connection_types[index][E] == W)
                    {
                        _neighbours[index][E]->SetData(0, 0, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);

                        _neighbours[index][E]->SetData(0, 1, 2 * cp - cp02);
                    }

                    if (_connection_types[index][S] == S)
                    {
                        _neighbours[index][E]->SetData(3, 0, cp);

                        DCoordinate3 cp02 = (*_patches[index])(0, 2);

                        _neighbours[index][E]->SetData(2, 0, 2 * cp - cp02);
                    }
                }
            }

            if (r == 1 && c == 1)
            {

                moveCp(index, 0, 1, new_image_1, direction_1);

                moveCp(index, 1, 0, new_image_2, direction_2);
            }

            if (r == 2 && c == 1)
            {

                moveCp(index, 2, 0, new_image_1, direction_1);

                moveCp(index, 3, 1, new_image_2, direction_2);
            }

            if (r == 2 && c == 2)
            {
                moveCp(index, 2, 3, new_image_1, direction_1);

                moveCp(index, 3, 2, new_image_2, direction_2);
            }

            if (r == 3 && c == 0)
            {

                if (_neighbours[index][SW] != nullptr)
                {
                    new_image_1 = true;
                    direction_1 = SW;

                    if (_connection_types[index][SW] == NW)
                    {
                        _neighbours[index][SW]->SetData(0, 0, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);
                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][SW]->SetData(0, 1, 2 * cp - cp20);
                        _neighbours[index][SW]->SetData(1, 0, 2 * cp - cp31);
                    }

                    if (_connection_types[index][SW] == NE)
                    {
                        _neighbours[index][SW]->SetData(0, 3, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);
                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][SW]->SetData(0, 2, 2 * cp - cp20);
                        _neighbours[index][SW]->SetData(1, 3, 2 * cp - cp31);
                    }

                    if (_connection_types[index][SW] == SW)
                    {
                        _neighbours[index][SW]->SetData(3, 0, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);
                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][SW]->SetData(3, 1, 2 * cp - cp20);
                        _neighbours[index][SW]->SetData(2, 0, 2 * cp - cp31);
                    }

                    if (_connection_types[index][SW] == SE)
                    {
                        _neighbours[index][SW]->SetData(3, 3, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);
                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][SW]->SetData(3, 2, 2 * cp - cp20);
                        _neighbours[index][SW]->SetData(2, 3, 2 * cp - cp31);
                    }
                }


                if (_neighbours[index][W] != nullptr)
                {
                    new_image_2 = true;
                    direction_2 = W;

                    if(_connection_types[index][W] == N)
                    {
                        _neighbours[index][W]->SetData(0, 3, cp);

                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][W]->SetData(1, 3, 2 * cp - cp31);
                    }

                    if(_connection_types[index][W] == E)
                    {
                        _neighbours[index][W]->SetData(3, 3, cp);

                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][W]->SetData(3, 2, 2 * cp - cp31);
                    }

                    if(_connection_types[index][W] == S)
                    {
                        _neighbours[index][W]->SetData(3, 0, cp);

                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][W]->SetData(2, 0, 2 * cp - cp31);
                    }

                    if(_connection_types[index][W] == W)
                    {
                        _neighbours[index][W]->SetData(3, 0, cp);

                        DCoordinate3 cp31 = (*_patches[index])(3, 1);

                        _neighbours[index][W]->SetData(3, 1, 2 * cp - cp31);
                    }
                }


                if (_neighbours[index][S] != nullptr)
                {
                    new_image_3 = true;
                    direction_3 = S;

                    if (_connection_types[index][S] == N)
                    {
                        _neighbours[index][S]->SetData(0, 0, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);

                        _neighbours[index][S]->SetData(1, 0, 2 * cp - cp20);
                    }

                    if (_connection_types[index][S] == E)
                    {
                        _neighbours[index][S]->SetData(0, 3, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);

                        _neighbours[index][S]->SetData(0, 2, 2 * cp - cp20);
                    }

                    if (_connection_types[index][S] == W)
                    {
                        _neighbours[index][S]->SetData(3, 0, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);

                        _neighbours[index][S]->SetData(3, 1, 2 * cp - cp20);
                    }

                    if (_connection_types[index][S] == S)
                    {
                        _neighbours[index][S]->SetData(3, 0, cp);

                        DCoordinate3 cp20 = (*_patches[index])(2, 0);

                        _neighbours[index][S]->SetData(2, 0, 2 * cp - cp20);
                    }
                }

            }

            if (r == 3 && c == 3)
            {

                if (_neighbours[index][SE] != nullptr)
                {
                    new_image_1 = true;
                    direction_1 = SE;

                    if (_connection_types[index][SE] == NW)
                    {
                        _neighbours[index][SE]->SetData(0, 0, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);
                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][SE]->SetData(0, 1, 2 * cp - cp23);
                        _neighbours[index][SE]->SetData(1, 0, 2 * cp - cp32);
                    }

                    if (_connection_types[index][SE] == NE)
                    {
                        _neighbours[index][SE]->SetData(0, 3, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);
                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][SE]->SetData(0, 2, 2 * cp - cp23);
                        _neighbours[index][SE]->SetData(1, 3, 2 * cp - cp32);
                    }

                    if (_connection_types[index][SE] == SW)
                    {
                        _neighbours[index][SE]->SetData(3, 0, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);
                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][SE]->SetData(3, 1, 2 * cp23 - cp);
                        _neighbours[index][SE]->SetData(2, 0, 2 * cp32 - cp);
                    }

                    if (_connection_types[index][SE] == SE)
                    {
                        _neighbours[index][SE]->SetData(3, 3, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);
                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][SE]->SetData(3, 2, 2 * cp - cp23);
                        _neighbours[index][SE]->SetData(2, 3, 2 * cp - cp32);
                    }
                }


                if (_neighbours[index][E] != nullptr)
                {
                    new_image_2 = true;
                    direction_2 = E;

                    if (_connection_types[index][E] == N)
                    {
                        _neighbours[index][E]->SetData(0, 0, cp);

                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][E]->SetData(1, 0, 2 * cp - cp32);
                    }

                    if (_connection_types[index][E] == E)
                    {
                        _neighbours[index][E]->SetData(3, 3, cp);

                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][E]->SetData(3, 2, 2 * cp - cp32);
                    }

                    if (_connection_types[index][E] == W)
                    {
                        _neighbours[index][E]->SetData(3, 0, cp);

                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][E]->SetData(3, 1, 2 * cp - cp32);
                    }

                    if (_connection_types[index][E] == S)
                    {
                        _neighbours[index][E]->SetData(3, 3, cp);

                        DCoordinate3 cp32 = (*_patches[index])(3, 2);

                        _neighbours[index][E]->SetData(2, 3, 2 * cp - cp32);
                    }
                }


                if (_neighbours[index][S] != nullptr)
                {
                    new_image_3 = true;
                    direction_3 = S;

                    if (_connection_types[index][S] == N)
                    {
                        _neighbours[index][S]->SetData(0, 3, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);

                        _neighbours[index][S]->SetData(1, 3, 2 * cp - cp23);
                    }

                    if (_connection_types[index][S] == E)
                    {
                        _neighbours[index][S]->SetData(3, 3, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);

                        _neighbours[index][S]->SetData(3, 2, 2 * cp - cp23);
                    }

                    if (_connection_types[index][S] == W)
                    {
                        _neighbours[index][S]->SetData(0, 0, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);

                        _neighbours[index][S]->SetData(0, 1, 2 * cp - cp23);
                    }

                    if (_connection_types[index][S] == S)
                    {
                        _neighbours[index][S]->SetData(3, 3, cp);

                        DCoordinate3 cp23 = (*_patches[index])(2, 3);

                        _neighbours[index][S]->SetData(2, 3, 2 * cp - cp23);
                    }
                }
            }

            _images[index] = _patches[index]->GenerateImage(_uDivPointCount, _vDivPointCount, GL_STATIC_DRAW);

            if (_images[index])
                _images[index]->UpdateVertexBufferObjects();

            _u_isoparametric_lines[index] = _patches[index]->GenerateUIsoparametricLines(_uIsoLineCount, 2, _uDivPointCount);
            _v_isoparametric_lines[index] = _patches[index]->GenerateVIsoparametricLines(_vIsoLineCount, 2, _vDivPointCount);

            for (GLuint i = 0; i < _u_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            for (GLuint i = 0; i < _v_isoparametric_lines[index]->GetColumnCount(); i++)
            {
                (*_v_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
            }

            //_patch.GetData(_selected_row_index, _selected_column_index, data_points_to_interpolate(_selected_row_index, _selected_column_index));
            _patches[index]->UpdateVertexBufferObjectsOfData();


            if (new_image_1)
            {
                auto neighbour = _neighbours[index][direction_1];
                auto it = std::find(_patches.begin(), _patches.end(), neighbour);
                int index2 = it - _patches.begin();
                _images[index2] = _patches[index2]->GenerateImage(_uDivPointCount, _vDivPointCount, GL_STATIC_DRAW);

                if (_images[index2])
                    _images[index2]->UpdateVertexBufferObjects();

                _u_isoparametric_lines[index2] = _patches[index2]->GenerateUIsoparametricLines(_uIsoLineCount, 2, _uDivPointCount);
                _v_isoparametric_lines[index2] = _patches[index2]->GenerateVIsoparametricLines(_vIsoLineCount, 2, _vDivPointCount);

                for (GLuint i = 0; i < _u_isoparametric_lines[index2]->GetColumnCount(); i++)
                {
                    (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
                }

                for (GLuint i = 0; i < _v_isoparametric_lines[index2]->GetColumnCount(); i++)
                {
                    (*_v_isoparametric_lines[index2])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
                }

                //_patch.GetData(_selected_row_index, _selected_column_index, data_points_to_interpolate(_selected_row_index, _selected_column_index));
                _patches[index2]->UpdateVertexBufferObjectsOfData();

            }

            if (new_image_2)
            {

                auto neighbour = _neighbours[index][direction_2];
                auto it = std::find(_patches.begin(), _patches.end(), neighbour);
                int index2 = it - _patches.begin();
                _images[index2] = _patches[index2]->GenerateImage(_uDivPointCount, _vDivPointCount, GL_STATIC_DRAW);

                if (_images[index2])
                    _images[index2]->UpdateVertexBufferObjects();

                _u_isoparametric_lines[index2] = _patches[index2]->GenerateUIsoparametricLines(_uIsoLineCount, 2, _uDivPointCount);
                _v_isoparametric_lines[index2] = _patches[index2]->GenerateVIsoparametricLines(_vIsoLineCount, 2, _vDivPointCount);

                for (GLuint i = 0; i < _u_isoparametric_lines[index2]->GetColumnCount(); i++)
                {
                    (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
                }

                for (GLuint i = 0; i < _v_isoparametric_lines[index2]->GetColumnCount(); i++)
                {
                    (*_v_isoparametric_lines[index2])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
                }

                //_patch.GetData(_selected_row_index, _selected_column_index, data_points_to_interpolate(_selected_row_index, _selected_column_index));
                _patches[index2]->UpdateVertexBufferObjectsOfData();
            }

            if (new_image_3)
            {
                auto neighbour = _neighbours[index][direction_3];
                auto it = std::find(_patches.begin(), _patches.end(), neighbour);
                int index2 = it - _patches.begin();
                _images[index2] = _patches[index2]->GenerateImage(_uDivPointCount, _vDivPointCount, GL_STATIC_DRAW);

                if (_images[index2])
                    _images[index2]->UpdateVertexBufferObjects();

                _u_isoparametric_lines[index2] = _patches[index2]->GenerateUIsoparametricLines(_uIsoLineCount, 2, _uDivPointCount);
                _v_isoparametric_lines[index2] = _patches[index2]->GenerateVIsoparametricLines(_vIsoLineCount, 2, _vDivPointCount);

                for (GLuint i = 0; i < _u_isoparametric_lines[index2]->GetColumnCount(); i++)
                {
                    (*_u_isoparametric_lines[index])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
                }

                for (GLuint i = 0; i < _v_isoparametric_lines[index2]->GetColumnCount(); i++)
                {
                    (*_v_isoparametric_lines[index2])[i]->UpdateVertexBufferObjects(_isoparametric_scale);
                }

                //_patch.GetData(_selected_row_index, _selected_column_index, data_points_to_interpolate(_selected_row_index, _selected_column_index));
                _patches[index2]->UpdateVertexBufferObjectsOfData();

            }
    }


    GLboolean CompositeTrigonometricPatch::mergePatches(GLuint patch_index_1, GLuint patch_index_2, Direction dir_1, Direction dir_2)
    {
        GLboolean bad = true;
        for (GLuint i = N; i != NE; i++)
        {
            if (static_cast<Direction>(i) == i)
            {
                bad = false;
            }
        }
        assert(!bad);

        if (_neighbours[patch_index_1][dir_1] != nullptr
                || _neighbours[patch_index_2][dir_2] != nullptr)
        {
            return GL_FALSE;
        }

        DCoordinate3 c1, c2, c3, c4;

        // Merging based on the given directions

        switch (dir_1)
        {
        case N:
        {
            switch (dir_2)
            {
            case N:
            {
                    c1 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(1,0)) / 2;
                    c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(1,1)) / 2;
                    c3 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(1,2)) / 2;
                    c4 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(1,3)) / 2;

                    (*_patches[patch_index_1])(0,0) = c1;
                    (*_patches[patch_index_1])(0,1) = c2;
                    (*_patches[patch_index_1])(0,2) = c3;
                    (*_patches[patch_index_1])(0,3) = c4;

                    (*_patches[patch_index_2])(0,0) = c1;
                    (*_patches[patch_index_2])(0,1) = c2;
                    (*_patches[patch_index_2])(0,2) = c3;
                    (*_patches[patch_index_2])(0,3) = c4;

                    _neighbours[patch_index_1][N] = _patches[patch_index_2];
                    _neighbours[patch_index_2][N] = _patches[patch_index_1];

                    _connection_types[patch_index_1][N] = N;
                    _connection_types[patch_index_2][N] = N;


//
                break;
            }
            case E:
            {
                c1 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(3,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(2,2)) / 2;
                c3 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(1,2)) / 2;
                c4 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(0,2)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(0,1) = c2;
                (*_patches[patch_index_1])(0,2) = c3;
                (*_patches[patch_index_1])(0,3) = c4;

                (*_patches[patch_index_2])(0,3) = c4;
                (*_patches[patch_index_2])(1,3) = c3;
                (*_patches[patch_index_2])(2,3) = c2;
                (*_patches[patch_index_2])(3,3) = c1;

                _neighbours[patch_index_1][N] = _patches[patch_index_2];
                _neighbours[patch_index_2][E] = _patches[patch_index_1];
                _connection_types[patch_index_1][N] = E;
                _connection_types[patch_index_2][E] = N;

//
                break;
            }
            case S:
            {
                c1 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(2,0)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(2,1)) / 2;
                c3 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(2,2)) / 2;
                c4 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(2,3)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(0,1) = c2;
                (*_patches[patch_index_1])(0,2) = c3;
                (*_patches[patch_index_1])(0,3) = c4;

                (*_patches[patch_index_2])(3,0) = c1;
                (*_patches[patch_index_2])(3,1) = c2;
                (*_patches[patch_index_2])(3,2) = c3;
                (*_patches[patch_index_2])(3,3) = c4;

                _neighbours[patch_index_1][N] = _patches[patch_index_2];
                _neighbours[patch_index_2][S] = _patches[patch_index_1];

                _connection_types[patch_index_1][N] = S;
                _connection_types[patch_index_2][S] = N;


//
                break;
            }
            case W:
            {
                c1 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(2,1)) / 2;
                c4 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(3,1)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(0,1) = c2;
                (*_patches[patch_index_1])(0,2) = c3;
                (*_patches[patch_index_1])(0,3) = c4;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(1,0) = c2;
                (*_patches[patch_index_2])(2,0) = c3;
                (*_patches[patch_index_2])(3,0) = c4;

                _neighbours[patch_index_1][N] = _patches[patch_index_2];
                _neighbours[patch_index_2][W] = _patches[patch_index_1];

                _connection_types[patch_index_1][N] = W;
                _connection_types[patch_index_2][W] = N;

//
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case E:
        {
            switch (dir_2)
            {
            case N:
            {
                c1 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(1,0)) / 2;
                c2 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(1,2)) / 2;
                c4 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(1,3)) / 2;

                (*_patches[patch_index_1])(0,3) = c4;
                (*_patches[patch_index_1])(1,3) = c3;
                (*_patches[patch_index_1])(2,3) = c2;
                (*_patches[patch_index_1])(3,3) = c1;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(0,1) = c2;
                (*_patches[patch_index_2])(0,2) = c3;
                (*_patches[patch_index_2])(0,3) = c4;

                _neighbours[patch_index_1][E] = _patches[patch_index_2];
                _connection_types[patch_index_1][E] = N;
                _neighbours[patch_index_2][N] = _patches[patch_index_1];
                _connection_types[patch_index_2][N] = E;
            break;
            }
            case E:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(1,2)) / 2;
                c3 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(2,2)) / 2;
                c4 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(3,2)) / 2;

                (*_patches[patch_index_1])(0,3) = c1;
                (*_patches[patch_index_1])(1,3) = c2;
                (*_patches[patch_index_1])(2,3) = c3;
                (*_patches[patch_index_1])(3,3) = c4;

                (*_patches[patch_index_2])(0,3) = c1;
                (*_patches[patch_index_2])(1,3) = c2;
                (*_patches[patch_index_2])(2,3) = c3;
                (*_patches[patch_index_2])(3,3) = c4;

                _neighbours[patch_index_1][E] = _patches[patch_index_2];
                _connection_types[patch_index_1][E] = E;
                _neighbours[patch_index_2][E] = _patches[patch_index_1];
                _connection_types[patch_index_2][E] = E;


            break;
            }
            case S:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(2,0)) / 2;
                c2 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(2,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(2,2)) / 2;
                c4 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(2,3)) / 2;

                (*_patches[patch_index_1])(0,3) = c1;
                (*_patches[patch_index_1])(1,3) = c2;
                (*_patches[patch_index_1])(2,3) = c3;
                (*_patches[patch_index_1])(3,3) = c4;

                (*_patches[patch_index_2])(3,0) = c1;
                (*_patches[patch_index_2])(3,1) = c2;
                (*_patches[patch_index_2])(3,2) = c3;
                (*_patches[patch_index_2])(3,3) = c4;

                _neighbours[patch_index_1][E] = _patches[patch_index_2];
                _connection_types[patch_index_1][E] = S;
                _neighbours[patch_index_2][S] = _patches[patch_index_1];
                _connection_types[patch_index_2][S] = E;



                break;
            }
            case W:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,2) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(2,1)) / 2;
                c4 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(3,1)) / 2;

                (*_patches[patch_index_1])(0,3) = c1;
                (*_patches[patch_index_1])(1,3) = c2;
                (*_patches[patch_index_1])(2,3) = c3;
                (*_patches[patch_index_1])(3,3) = c4;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(1,0) = c2;
                (*_patches[patch_index_2])(2,0) = c3;
                (*_patches[patch_index_2])(3,0) = c4;

                _neighbours[patch_index_1][E] = _patches[patch_index_2];
                _connection_types[patch_index_1][E] = W;
                _neighbours[patch_index_2][W] = _patches[patch_index_1];
                _connection_types[patch_index_2][W] = E;


                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case S:
        {
            switch (dir_2)
            {
            case N:
            {
                c1 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(1,0)) / 2;
                c2 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(1,2)) / 2;
                c4 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(1,3)) / 2;

                (*_patches[patch_index_1])(3,0) = c1;
                (*_patches[patch_index_1])(3,1) = c2;
                (*_patches[patch_index_1])(3,2) = c3;
                (*_patches[patch_index_1])(3,3) = c4;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(0,1) = c2;
                (*_patches[patch_index_2])(0,2) = c3;
                (*_patches[patch_index_2])(0,3) = c4;

                _neighbours[patch_index_1][S] = _patches[patch_index_2];
                _connection_types[patch_index_1][S] = N;
                _neighbours[patch_index_2][N] = _patches[patch_index_1];
                _connection_types[patch_index_2][N] = S;


                break;
            }
            case E:
            {
                c1 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(1,2)) / 2;
                c3 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(2,2)) / 2;
                c4 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(3,2)) / 2;

                (*_patches[patch_index_1])(3,0) = c1;
                (*_patches[patch_index_1])(3,1) = c2;
                (*_patches[patch_index_1])(3,2) = c3;
                (*_patches[patch_index_1])(3,3) = c4;

                (*_patches[patch_index_2])(0,3) = c1;
                (*_patches[patch_index_2])(1,3) = c2;
                (*_patches[patch_index_2])(2,3) = c3;
                (*_patches[patch_index_2])(3,3) = c4;

                _neighbours[patch_index_1][S] = _patches[patch_index_2];
                _connection_types[patch_index_1][S] = E;
                _neighbours[patch_index_2][E] = _patches[patch_index_1];
                _connection_types[patch_index_2][E] = S;


                break;
            }
            case S:
            {
                c1 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(2,0)) / 2;
                c2 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(2,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(2,2)) / 2;
                c4 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(2,3)) / 2;

                (*_patches[patch_index_1])(3,0) = c1;
                (*_patches[patch_index_1])(3,1) = c2;
                (*_patches[patch_index_1])(3,2) = c3;
                (*_patches[patch_index_1])(3,3) = c4;

                (*_patches[patch_index_2])(3,0) = c1;
                (*_patches[patch_index_2])(3,1) = c2;
                (*_patches[patch_index_2])(3,2) = c3;
                (*_patches[patch_index_2])(3,3) = c4;

                _neighbours[patch_index_1][S] = _patches[patch_index_2];
                _connection_types[patch_index_1][S] = S;
                _neighbours[patch_index_2][S] = _patches[patch_index_1];
                _connection_types[patch_index_2][S] = S;



                break;
            }
            case W:
            {
                c1 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(2,2) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(2,1)) / 2;
                c4 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(3,1)) / 2;

                (*_patches[patch_index_1])(3,0) = c4;
                (*_patches[patch_index_1])(3,1) = c3;
                (*_patches[patch_index_1])(3,2) = c2;
                (*_patches[patch_index_1])(3,3) = c1;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(1,0) = c2;
                (*_patches[patch_index_2])(2,0) = c3;
                (*_patches[patch_index_2])(3,0) = c4;

                _neighbours[patch_index_1][S] = _patches[patch_index_2];
                _connection_types[patch_index_1][S] = W;
                _neighbours[patch_index_2][W] = _patches[patch_index_1];
                _connection_types[patch_index_2][W] = S;


                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case W:
        {
            switch (dir_2)
            {
            case N:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(1,0)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(1,2)) / 2;
                c4 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(1,3)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(1,0) = c2;
                (*_patches[patch_index_1])(2,0) = c3;
                (*_patches[patch_index_1])(3,0) = c4;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(0,1) = c2;
                (*_patches[patch_index_2])(0,2) = c3;
                (*_patches[patch_index_2])(0,3) = c4;

                _neighbours[patch_index_1][W] = _patches[patch_index_2];
                _connection_types[patch_index_1][W] = N;
                _neighbours[patch_index_2][N] = _patches[patch_index_1];
                _connection_types[patch_index_2][N] = W;



                break;
            }
            case E:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(1,2)) / 2;
                c3 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(2,2)) / 2;
                c4 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(3,2)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(1,0) = c2;
                (*_patches[patch_index_1])(2,0) = c3;
                (*_patches[patch_index_1])(3,0) = c4;

                (*_patches[patch_index_2])(0,3) = c1;
                (*_patches[patch_index_2])(1,3) = c2;
                (*_patches[patch_index_2])(2,3) = c3;
                (*_patches[patch_index_2])(3,3) = c4;

                _neighbours[patch_index_1][W] = _patches[patch_index_2];
                _connection_types[patch_index_1][W] = E;
                _neighbours[patch_index_2][E] = _patches[patch_index_1];
                _connection_types[patch_index_2][E] = W;


            }
            case S:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(2,3)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(2,2)) / 2;
                c3 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(2,1)) / 2;
                c4 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(2,0)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(1,0) = c2;
                (*_patches[patch_index_1])(2,0) = c3;
                (*_patches[patch_index_1])(3,0) = c4;

                (*_patches[patch_index_2])(3,0) = c4;
                (*_patches[patch_index_2])(3,1) = c3;
                (*_patches[patch_index_2])(3,2) = c2;
                (*_patches[patch_index_2])(3,3) = c1;

                _neighbours[patch_index_1][W] = _patches[patch_index_2];
                _connection_types[patch_index_1][W] = S;
                _neighbours[patch_index_2][S] = _patches[patch_index_1];
                _connection_types[patch_index_2][S] = W;



                break;
            }
            case W:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,1) + (*_patches[patch_index_2])(1,1)) / 2;
                c3 = ((*_patches[patch_index_1])(2,1) + (*_patches[patch_index_2])(2,1)) / 2;
                c4 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(3,1)) / 2;

                (*_patches[patch_index_1])(0,0) = c1;
                (*_patches[patch_index_1])(1,0) = c2;
                (*_patches[patch_index_1])(2,0) = c3;
                (*_patches[patch_index_1])(3,0) = c4;

                (*_patches[patch_index_2])(0,0) = c1;
                (*_patches[patch_index_2])(1,0) = c2;
                (*_patches[patch_index_2])(2,0) = c3;
                (*_patches[patch_index_2])(3,0) = c4;

                _neighbours[patch_index_1][W] = _patches[patch_index_2];
                _connection_types[patch_index_1][W] = W;
                _neighbours[patch_index_2][W] = _patches[patch_index_1];
                _connection_types[patch_index_2][W] = W;


                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case NE:
        {
            switch(dir_2)
            {
            case NE:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(1,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,2) = (*_patches[patch_index_1])(0,2) + c2 - c3;
                (*_patches[patch_index_1])(1,3) = (*_patches[patch_index_1])(1,3) + c1 - c3;
                (*_patches[patch_index_1])(0,3) = c3;

                (*_patches[patch_index_2])(0,3) = c3;
                (*_patches[patch_index_2])(1,3) = (*_patches[patch_index_2])(1,3) + c1 - c3;
                (*_patches[patch_index_2])(0,2) = (*_patches[patch_index_2])(0,2) + c2 - c3;

                _neighbours[patch_index_1][NE] = _patches[patch_index_2];
                _connection_types[patch_index_1][NE] = NE;
                _neighbours[patch_index_2][NE] = _patches[patch_index_1];
                _connection_types[patch_index_2][NE] = NE;


                break;
            }
            case SE:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(3,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(2,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,2) = (*_patches[patch_index_1])(0,2) + c2 - c3;
                (*_patches[patch_index_1])(1,3) = (*_patches[patch_index_1])(1,3) + c1 - c3;
                (*_patches[patch_index_1])(0,3) = c3;

                (*_patches[patch_index_2])(3,3) = c3;
                (*_patches[patch_index_2])(2,3) = (*_patches[patch_index_2])(2,3) + c1 - c3;
                (*_patches[patch_index_2])(3,2) = (*_patches[patch_index_2])(3,2) + c2 - c3;

                _neighbours[patch_index_1][NE] = _patches[patch_index_2];
                _connection_types[patch_index_1][NE] = SE;
                _neighbours[patch_index_2][SE] = _patches[patch_index_1];
                _connection_types[patch_index_2][SE] = NE;

                //
                break;
            }
            case SW:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(3,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(2,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,2) = (*_patches[patch_index_1])(0,2) + c2 - c3;
                (*_patches[patch_index_1])(1,3) = (*_patches[patch_index_1])(1,3) + c1 - c3;
                (*_patches[patch_index_1])(0,3) = c3;

                (*_patches[patch_index_2])(3,0) = c3;
                (*_patches[patch_index_2])(2,0) = (*_patches[patch_index_2])(2,0) + c1 - c3;
                (*_patches[patch_index_2])(3,1) = (*_patches[patch_index_2])(3,1) + c2 - c3;

                _neighbours[patch_index_1][NE] = _patches[patch_index_2];
                _connection_types[patch_index_1][NE] = SW;
                _neighbours[patch_index_2][SW] = _patches[patch_index_1];
                _connection_types[patch_index_2][SW] = NE;


                break;
            }
            case NW:
            {
                c1 = ((*_patches[patch_index_1])(0,2) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,3) + (*_patches[patch_index_2])(1,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,2) = (*_patches[patch_index_1])(0,2) + c2 - c3;
                (*_patches[patch_index_1])(1,3) = (*_patches[patch_index_1])(1,3) + c1 - c3;
                (*_patches[patch_index_1])(0,3) = c3;

                (*_patches[patch_index_2])(0,0) = c3;
                (*_patches[patch_index_2])(1,0) = (*_patches[patch_index_2])(1,0) + c1 - c3;
                (*_patches[patch_index_2])(0,1) = (*_patches[patch_index_2])(0,1) + c2 - c3;

                _neighbours[patch_index_1][NE] = _patches[patch_index_2];
                _connection_types[patch_index_1][NE] = NW;
                _neighbours[patch_index_2][NW] = _patches[patch_index_1];
                _connection_types[patch_index_2][NW] = NE;


                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case SE:
        {
            switch(dir_2)
            {
            case NE:
            {
                c1 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(1,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(2,3) = (*_patches[patch_index_1])(2,3) + c1 - c3;
                (*_patches[patch_index_1])(3,2) = (*_patches[patch_index_1])(3,2) + c2 - c3;
                (*_patches[patch_index_1])(3,3) = c3;

                (*_patches[patch_index_2])(0,3) = c3;
                (*_patches[patch_index_2])(0,2) = (*_patches[patch_index_2])(0,2) + c2 - c3;
                (*_patches[patch_index_2])(1,3) = (*_patches[patch_index_2])(1,3) + c1 - c3;

                _neighbours[patch_index_1][SE] = _patches[patch_index_2];
                _connection_types[patch_index_1][SE] = NE;
                _neighbours[patch_index_2][NE] = _patches[patch_index_1];
                _connection_types[patch_index_2][NE] = SE;


                break;
            }
            case SE:
            {
                c1 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(3,2)) / 2;
                c2 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(2,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(2,3) = (*_patches[patch_index_1])(2,3) + c1 - c3;
                (*_patches[patch_index_1])(3,2) = (*_patches[patch_index_1])(3,2) + c2 - c3;
                (*_patches[patch_index_1])(3,3) = c3;

                (*_patches[patch_index_2])(3,3) = c3;
                (*_patches[patch_index_2])(3,2) = (*_patches[patch_index_2])(3,2) + c2 - c3;
                (*_patches[patch_index_2])(2,3) = (*_patches[patch_index_2])(2,3) + c1 - c3;

                _neighbours[patch_index_1][SE] = _patches[patch_index_2];
                _connection_types[patch_index_1][SE] = SE;
                _neighbours[patch_index_2][SE] = _patches[patch_index_1];
                _connection_types[patch_index_2][SE] = SE;



                break;
            }
            case SW:
            {
                c1 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(3,1)) / 2;
                c2 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(2,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(2,3) = (*_patches[patch_index_1])(2,3) + c1 - c3;
                (*_patches[patch_index_1])(3,2) = (*_patches[patch_index_1])(3,2) + c2 - c3;
                (*_patches[patch_index_1])(3,3) = c3;

                (*_patches[patch_index_2])(3,0) = c3;
                (*_patches[patch_index_2])(3,1) = (*_patches[patch_index_2])(3,1) + c2 - c3;
                (*_patches[patch_index_2])(2,0) = (*_patches[patch_index_2])(2,0) + c1 - c3;

                _neighbours[patch_index_1][SE] = _patches[patch_index_2];
                _connection_types[patch_index_1][SE] = SW;
                _neighbours[patch_index_2][SW] = _patches[patch_index_1];
                _connection_types[patch_index_2][SW] = SE;


                break;
            }
            case NW:
            {
                c1 = ((*_patches[patch_index_1])(3,2) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(2,3) + (*_patches[patch_index_2])(1,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(2,3) = (*_patches[patch_index_1])(2,3) + c1 - c3;
                (*_patches[patch_index_1])(3,2) = (*_patches[patch_index_1])(3,2) + c2 - c3;
                (*_patches[patch_index_1])(3,3) = c3;

                (*_patches[patch_index_2])(0,0) = c3;
                (*_patches[patch_index_2])(0,1) = (*_patches[patch_index_2])(0,1) + c2 - c3;
                (*_patches[patch_index_2])(1,0) = (*_patches[patch_index_2])(1,0) + c1 - c3;

                _neighbours[patch_index_1][SE] = _patches[patch_index_2];
                _connection_types[patch_index_1][SE] = NW;
                _neighbours[patch_index_2][NW] = _patches[patch_index_1];
                _connection_types[patch_index_2][NW] = SE;



                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case SW:
        {
            switch(dir_2)
            {
            case NE:
            {
                c1 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(1,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(3,1) = (*_patches[patch_index_1])(3,1) + c2 - c3;
                (*_patches[patch_index_1])(2,0) = (*_patches[patch_index_1])(2,0) + c1 - c3;
                (*_patches[patch_index_1])(3,0) = c3;

                (*_patches[patch_index_2])(0,3) = c3;
                (*_patches[patch_index_2])(1,3) = (*_patches[patch_index_2])(1,3) + c1 - c3;
                (*_patches[patch_index_2])(0,2) = (*_patches[patch_index_2])(0,2) + c2 - c3;

                _neighbours[patch_index_1][SW] = _patches[patch_index_2];
                _connection_types[patch_index_1][SW] = NE;
                _neighbours[patch_index_2][NE] = _patches[patch_index_1];
                _connection_types[patch_index_2][NE] = SW;


                break;
            }
            case SE:
            {
                c1 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(3,2)) / 2;
                c2 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(2,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(3,1) = (*_patches[patch_index_1])(3,1) + c2 - c3;
                (*_patches[patch_index_1])(2,0) = (*_patches[patch_index_1])(2,0) + c1 - c3;
                (*_patches[patch_index_1])(3,0) = c3;

                (*_patches[patch_index_2])(3,3) = c3;
                (*_patches[patch_index_2])(2,3) = (*_patches[patch_index_2])(2,3) + c1 - c3;
                (*_patches[patch_index_2])(3,2) = (*_patches[patch_index_2])(3,2) + c2 - c3;

                _neighbours[patch_index_1][SW] = _patches[patch_index_2];
                _connection_types[patch_index_1][SW] = SE;
                _neighbours[patch_index_2][SE] = _patches[patch_index_1];
                _connection_types[patch_index_2][SE] = SW;


                break;
            }
            case SW:
            {
                c1 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(3,1)) / 2;
                c2 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(2,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(3,1) = (*_patches[patch_index_1])(3,1) + c2 - c3;
                (*_patches[patch_index_1])(2,0) = (*_patches[patch_index_1])(2,0) + c1 - c3;
                (*_patches[patch_index_1])(3,0) = c3;

                (*_patches[patch_index_2])(3,0) = c3;
                (*_patches[patch_index_2])(2,0) = (*_patches[patch_index_2])(2,0) + c1 - c3;
                (*_patches[patch_index_2])(3,1) = (*_patches[patch_index_2])(3,1) + c2 - c3;

                _neighbours[patch_index_1][SW] = _patches[patch_index_2];
                _connection_types[patch_index_1][SW] = SW;
                _neighbours[patch_index_2][SW] = _patches[patch_index_1];
                _connection_types[patch_index_2][SW] = SW;


                break;
            }
            case NW:
            {
                c1 = ((*_patches[patch_index_1])(3,1) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(2,0) + (*_patches[patch_index_2])(1,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(3,1) = (*_patches[patch_index_1])(3,1) + c2 - c3;
                (*_patches[patch_index_1])(2,0) = (*_patches[patch_index_1])(2,0) + c1 - c3;
                (*_patches[patch_index_1])(3,0) = c3;

                (*_patches[patch_index_2])(0,0) = c3;
                (*_patches[patch_index_2])(1,0) = (*_patches[patch_index_2])(1,0) + c1 - c3;
                (*_patches[patch_index_2])(0,1) = (*_patches[patch_index_2])(0,1) + c2 - c3;

                _neighbours[patch_index_1][SW] = _patches[patch_index_2];
                _connection_types[patch_index_1][SW] = NW;
                _neighbours[patch_index_2][NW] = _patches[patch_index_1];
                _connection_types[patch_index_2][NW] = SW;



                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
        case NW:
        {
            switch(dir_2)
            {
            case NE:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(0,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(1,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,1) = (*_patches[patch_index_1])(0,1) + c2 - c3;
                (*_patches[patch_index_1])(1,0) = (*_patches[patch_index_1])(1,0) + c1 - c3;
                (*_patches[patch_index_1])(0,0) = c3;

                (*_patches[patch_index_2])(0,3) = c3;
                (*_patches[patch_index_2])(1,3) = (*_patches[patch_index_2])(1,3) + c1 - c3;
                (*_patches[patch_index_2])(0,2) = (*_patches[patch_index_2])(0,2) + c2 - c3;

                _neighbours[patch_index_1][NW] = _patches[patch_index_2];
                _connection_types[patch_index_1][NW] = NE;
                _neighbours[patch_index_2][NE] = _patches[patch_index_1];
                _connection_types[patch_index_2][NE] = NW;


                break;
            }
            case SE:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(3,2)) / 2;
                c2 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(2,3)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,1) = (*_patches[patch_index_1])(0,1) + c2 - c3;
                (*_patches[patch_index_1])(1,0) = (*_patches[patch_index_1])(1,0) + c1 - c3;
                (*_patches[patch_index_1])(0,0) = c3;

                (*_patches[patch_index_2])(3,3) = c3;
                (*_patches[patch_index_2])(3,2) = (*_patches[patch_index_2])(3,2) + c2 - c3;
                (*_patches[patch_index_2])(2,3) = (*_patches[patch_index_2])(2,3) + c1 - c3;

                _neighbours[patch_index_1][NW] = _patches[patch_index_2];
                _connection_types[patch_index_1][NW] = SE;
                _neighbours[patch_index_2][SE] = _patches[patch_index_1];
                _connection_types[patch_index_2][SE] = NW;


                break;
            }
            case SW:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(3,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(2,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,1) = (*_patches[patch_index_1])(0,1) + c2 - c3;
                (*_patches[patch_index_1])(1,0) = (*_patches[patch_index_1])(1,0) + c1 - c3;
                (*_patches[patch_index_1])(0,0) = c3;

                (*_patches[patch_index_2])(3,0) = c3;
                (*_patches[patch_index_2])(2,0) = (*_patches[patch_index_2])(2,0) + c1 - c3;
                (*_patches[patch_index_2])(3,1) = (*_patches[patch_index_2])(3,1) + c2 - c3;

                _neighbours[patch_index_1][NW] = _patches[patch_index_2];
                _connection_types[patch_index_1][NW] = SW;
                _neighbours[patch_index_2][SW] = _patches[patch_index_1];
                _connection_types[patch_index_2][SW] = NW;


                break;
            }
            case NW:
            {
                c1 = ((*_patches[patch_index_1])(0,1) + (*_patches[patch_index_2])(0,1)) / 2;
                c2 = ((*_patches[patch_index_1])(1,0) + (*_patches[patch_index_2])(1,0)) / 2;

                c3 = (c1 + c2) / 2;

                (*_patches[patch_index_1])(0,1) = (*_patches[patch_index_1])(0,1) + c2 - c3;
                (*_patches[patch_index_1])(1,0) = (*_patches[patch_index_1])(1,0) + c1 - c3;
                (*_patches[patch_index_1])(0,0) = c3;

                (*_patches[patch_index_2])(0,0) = c3;
                (*_patches[patch_index_2])(1,0) = (*_patches[patch_index_2])(1,0) + c1 - c3;
                (*_patches[patch_index_2])(0,1) = (*_patches[patch_index_2])(0,1) + c2 - c3;

                _neighbours[patch_index_1][NW] = _patches[patch_index_2];
                _connection_types[patch_index_1][NW] = NW;
                _neighbours[patch_index_2][NW] = _patches[patch_index_1];
                _connection_types[patch_index_2][NW] = NW;


                break;
            }
            default:
            {
                return GL_FALSE;
            }
            }
            break;
        }
    }

    // impossible not possible possiblen't impossiblen'tn't nossible possibruh it was 3am when i wrote this maybe there are ghosts around me maybe i am a ghost so help me god i

        _updateMergeData(patch_index_1, patch_index_2);
    return GL_FALSE;
}

    GLboolean CompositeTrigonometricPatch::deletePatch(GLuint index)
    {
        if (patchExists(index))
        {
            for (GLuint i = 0; i < 8; ++i)
            {
               if (_neighbours[index][i] != nullptr)
               {
                   for (GLuint j = 0; j < 8; ++j)
                   {
                       if (_connection_types[index][j] >= 0 && _connection_types[index][j] <= 7)
                       {
                           // FIX THIS
                           _neighbours[_neighbour_indexes[index][i]][0] = nullptr;

                           _neighbour_indexes[index][i] = 0;
                           _neighbours[index][i] = nullptr;
                       }
                   }
               }
            }

            if (_patches[index])
            {
                delete _patches[index]; _patches[index] = nullptr;
            }

            if (_images[index])
            {
                delete _images[index]; _images[index] = nullptr;
            }

            if (_u_isoparametric_lines[index])
            {
                for (GLuint j = 0; j < _u_isoparametric_lines[index]->GetColumnCount(); ++j){
                    delete (* _u_isoparametric_lines[index])[j];
                    (* _u_isoparametric_lines[index])[j] = nullptr;
                }
                delete _u_isoparametric_lines[index];
                _u_isoparametric_lines[index] = nullptr;
            }

            if (_v_isoparametric_lines[index])
            {
                for (GLuint j = 0; j < _v_isoparametric_lines[index]->GetColumnCount(); ++j){
                    delete (* _v_isoparametric_lines[index])[j];
                    (* _v_isoparametric_lines[index])[j] = nullptr;
                }
                delete _v_isoparametric_lines[index];
                _v_isoparametric_lines[index] = nullptr;
            }
        }

        return GL_TRUE;
    }

    GLboolean CompositeTrigonometricPatch::deleteAllPatches()
    {
        for (GLuint i = 0; i < _nr_of_patches; i++)
        {
            deletePatch(i);
        }
        return GL_TRUE;
    }

}
