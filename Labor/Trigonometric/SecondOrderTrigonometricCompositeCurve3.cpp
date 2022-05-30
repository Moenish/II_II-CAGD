#include <iostream>
#include <random>
#include <cassert>
#include "SecondOrderTrigonometricCompositeCurve3.h"

using namespace cagd;

SecondOrderTrigonometricCompositeCurve3::SecondOrderTrigonometricCompositeCurve3(GLdouble alpha, GLuint minimalReservedArcCount)
{
    _alpha = alpha;
    _attributes.resize(minimalReservedArcCount);
}

GLboolean SecondOrderTrigonometricCompositeCurve3::insertLine(Color4 *color, GLuint maxDerivativeOrder, GLuint divPointCount, GLenum usageFlag)
{
    DCoordinate3 *points = new DCoordinate3[4];
    points[0].x() = -2.0;
    points[1].x() = -0.66;
    points[2].x() = 0.66;
    points[3].x() = 2.0;
    insertArc(points, color, maxDerivativeOrder, divPointCount, usageFlag);
    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricCompositeCurve3::insertArc(DCoordinate3 *points, Color4 *color, GLuint maxDerivativeOrder, GLuint divPointCount, GLenum usageFlag)
{
    GLuint index = _arc_count;
    _attributes[index].arc = new (nothrow) SecondOrderTrigonometricArc3();
    _attributes[index].color = color;

    if (!_attributes[index].arc)
    {
        deleteExistingArc(index);
        return GL_FALSE;
    }

    for (GLuint i = 0; i < 4; ++i)
    {
        (*_attributes[index].arc)[i] = points[i];
    }

    _attributes[index].arc->UpdateVertexBufferObjectsOfData();
    _attributes[index].image = _attributes[index].arc->GenerateImage(maxDerivativeOrder, divPointCount, usageFlag);

    if(!_attributes[index].image)
    {
        deleteExistingArc(index);
        return GL_FALSE;
    }

    _attributes[index].image->UpdateVertexBufferObjects();
    ++_arc_count;

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricCompositeCurve3::deleteExistingArc(GLuint index)
{
    if (_attributes[index].arc)
    {
        if (_attributes[index].prev)
        {
            if(_attributes[index].nextConnection == LEFT)
            {
                _attributes[index].prev->prev = nullptr;
            }
            else
            {
                _attributes[index].prev->next = nullptr;
            }
        }
        if (_attributes[index].next)
        {
            if(_attributes[index].nextConnection == LEFT)
            {
                _attributes[index].next->prev = nullptr;
            }
            else
            {
                _attributes[index].next->next = nullptr;
            }
        }

        delete _attributes[index].arc;
        _attributes[index].arc = nullptr;
    }

    if (_attributes[index].image)
    {
        delete _attributes[index].image;
        _attributes[index].image = nullptr;
    }

    return GL_TRUE;
}

void SecondOrderTrigonometricCompositeCurve3::deleteAllArcs()
{
    for (GLuint i = 0; i < _arc_count; ++i)
    {
        if (arcExists(i))
        {
            deleteExistingArc(i);
        }
    }
}

GLboolean SecondOrderTrigonometricCompositeCurve3::arcExists(GLuint index) const
{
    if(_attributes[index].arc == nullptr)
    {
        return GL_FALSE;
    }
    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricCompositeCurve3::continueExistingArc(GLuint index, Direction direction)
{
    DCoordinate3 *coord = new DCoordinate3[4];

    if (direction == LEFT)
    {
        for (GLuint i = 0; i < 4; i ++)
        {
            coord[i] = (*_attributes[index].arc)[3] + i * ((*_attributes[index].arc)[3] - (*_attributes[index].arc)[2]);
        }
    }
    else
    {
        for (GLuint i = 0; i < 4; i ++)
        {
            coord[i] = (*_attributes[index].arc)[0] + i * ((*_attributes[index].arc)[0] - (*_attributes[index].arc)[1]);
        }
    }

    constexpr int FLOAT_MIN = 0;
    constexpr int FLOAT_MAX = 1;

    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);

    Color4 *color = new Color4(distr(eng), distr(eng), distr(eng));
    insertArc(coord, color, 2, 100);

    if (direction == LEFT)
    {
        _attributes[index].prev =  &_attributes[_arc_count - 1];
        _attributes[index].previousConnection = RIGHT;
        _attributes[_arc_count - 1].next = &_attributes[index];
        _attributes[_arc_count - 1].nextConnection = LEFT;

    }
    else
    {
        _attributes[index].next =  &_attributes[_arc_count - 1];
        _attributes[index].nextConnection = RIGHT;
        _attributes[_arc_count - 1].next = &_attributes[index];
        _attributes[_arc_count - 1].nextConnection = RIGHT;
    }

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricCompositeCurve3::joinExistingArcs(GLuint index1, Direction dir1, GLuint index2, Direction dir2)
{
    assert((dir1 == RIGHT || dir1 == LEFT) && (dir2 == RIGHT || dir2 == LEFT) && index1 >= 0 && index1 <= _arc_count && index2 >= 0 && index2 <= _arc_count);

    if (dir1 == LEFT && _attributes[index1].prev != nullptr)
        return GL_FALSE;

    if (dir1 == RIGHT && _attributes[index1].next != nullptr)
        return GL_FALSE;

    if (dir2 == LEFT && _attributes[index2].prev != nullptr)
        return GL_FALSE;

    if (dir2 == RIGHT && _attributes[index2].next != nullptr)
        return GL_FALSE;

    _attributes[_arc_count].arc = new (nothrow) SecondOrderTrigonometricArc3();
    _attributes[_arc_count].color = new Color4(0.0, 1.0, 0.0);

    if(!_attributes[_arc_count].arc)
    {
        deleteExistingArc(_arc_count);
        return GL_FALSE;
    }

    if (dir1 == RIGHT)
    {
        (*_attributes[_arc_count].arc)[3] = (*_attributes[index1].arc)[0];
        (*_attributes[_arc_count].arc)[2] = 2 * (*_attributes[index1].arc)[0] - (*_attributes[index1].arc)[1];

        if (dir2 == RIGHT)
        {
            (*_attributes[_arc_count].arc)[0] = (*_attributes[index2].arc)[0];
            (*_attributes[_arc_count].arc)[1] = 2 * (*_attributes[index2].arc)[0] - (*_attributes[index2].arc)[1];

            _attributes[_arc_count].prev = &_attributes[index1];
            _attributes[_arc_count].next = &_attributes[index2];
            _attributes[_arc_count].previousConnection = RIGHT;
            _attributes[_arc_count].nextConnection = RIGHT;

            _attributes[index1].next = &_attributes[_arc_count];
            _attributes[index1].nextConnection = LEFT;

            _attributes[index2].next = &_attributes[_arc_count];
            _attributes[index2].nextConnection = RIGHT;
        }
        else
        {
            (*_attributes[_arc_count].arc)[0] = (*_attributes[index2].arc)[3];
            (*_attributes[_arc_count].arc)[1] = 2 * (*_attributes[index2].arc)[3] - (*_attributes[index2].arc)[2];

            _attributes[_arc_count].prev = &_attributes[index1];
            _attributes[_arc_count].next = &_attributes[index2];
            _attributes[_arc_count].previousConnection = RIGHT;
            _attributes[_arc_count].nextConnection = LEFT;

            _attributes[index1].next = &_attributes[_arc_count];
            _attributes[index1].nextConnection = LEFT;

            _attributes[index2].prev = &_attributes[_arc_count];
            _attributes[index2].previousConnection = RIGHT;
        }
    }

    else
    {
        (*_attributes[_arc_count].arc)[0] = (*_attributes[index1].arc)[3];
        (*_attributes[_arc_count].arc)[1] = 2 * (*_attributes[index1].arc)[3] - (*_attributes[index1].arc)[2];

        if (dir2 == RIGHT)
        {
            (*_attributes[_arc_count].arc)[3] = (*_attributes[index2].arc)[0];
            (*_attributes[_arc_count].arc)[2] = 2 * (*_attributes[index2].arc)[0] - (*_attributes[index2].arc)[1];

            _attributes[_arc_count].prev = &_attributes[index2];
            _attributes[_arc_count].next = &_attributes[index1];
            _attributes[_arc_count].previousConnection = RIGHT;
            _attributes[_arc_count].nextConnection = LEFT;

            _attributes[index1].prev = &_attributes[_arc_count];
            _attributes[index1].previousConnection = RIGHT;

            _attributes[index2].next = &_attributes[_arc_count];
            _attributes[index2].nextConnection = LEFT;
        }
        else
        {
            (*_attributes[_arc_count].arc)[3] = (*_attributes[index2].arc)[3];
            (*_attributes[_arc_count].arc)[2] = 2 * (*_attributes[index2].arc)[3] - (*_attributes[index2].arc)[2];

            _attributes[_arc_count].prev = &_attributes[index2];
            _attributes[_arc_count].next = &_attributes[index1];
            _attributes[_arc_count].previousConnection = LEFT;
            _attributes[_arc_count].nextConnection = LEFT;

            _attributes[index1].prev = &_attributes[_arc_count];
            _attributes[index1].previousConnection = RIGHT;

            _attributes[index2].prev = &_attributes[_arc_count];
            _attributes[index2].previousConnection = LEFT;
        }
    }


    _attributes[_arc_count].arc->UpdateVertexBufferObjectsOfData();

    _attributes[_arc_count].image = _attributes[_arc_count].arc->GenerateImage(2, _arc_div_point_count);

    if (!_attributes[_arc_count].image)
    {
         deleteExistingArc(_arc_count);
         return GL_FALSE;
    }

    _attributes[_arc_count].image->UpdateVertexBufferObjects();

    ++_arc_count;
    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricCompositeCurve3::mergeExistingArcs(GLuint index1, Direction dir1, GLuint index2, Direction dir2)
{
    assert((dir1 == RIGHT || dir1 == LEFT) && (dir2 == RIGHT || dir2 == LEFT));

    DCoordinate3 centre;
    if (dir1 == RIGHT && dir2 == LEFT && !_attributes[index1].next && !_attributes[index2].prev)
    {
        centre = ((*_attributes[index1].arc)[1] + (*_attributes[index2].arc)[2]) / 2;
        (*_attributes[index1].arc)[0] = centre;
        (*_attributes[index2].arc)[3] = centre;
        _attributes[index1].next = &_attributes[index2];
        _attributes[index1].nextConnection = LEFT;
        _attributes[index2].prev = &_attributes[index1];
        _attributes[index2].previousConnection = RIGHT;
        return generateImageOfSelectedArcs(index1, index2);
    }

    if (dir1 == RIGHT && dir2 == RIGHT && !_attributes[index1].next && !_attributes[index2].next)
    {
        centre = ((*_attributes[index1].arc)[1] + (*_attributes[index2].arc)[1]) / 2;
        (*_attributes[index1].arc)[0] = centre;
        (*_attributes[index2].arc)[0] = centre;
        _attributes[index1].next = &_attributes[index2];
        _attributes[index1].nextConnection = RIGHT;
        _attributes[index2].next = &_attributes[index1];
        _attributes[index2].nextConnection = RIGHT;
        return generateImageOfSelectedArcs(index1, index2);
    }

    if (dir1 == LEFT && dir2 == LEFT && !_attributes[index1].prev && !_attributes[index2].prev)
    {
        centre = ((*_attributes[index1].arc)[2] + (*_attributes[index2].arc)[2]) / 2;
        (*_attributes[index1].arc)[3] = centre;
        (*_attributes[index2].arc)[3] = centre;
        _attributes[index1].prev = &_attributes[index2];
        _attributes[index1].previousConnection = LEFT;
        _attributes[index2].prev = &_attributes[index1];
        _attributes[index2].previousConnection = LEFT;
        return generateImageOfSelectedArcs(index1, index2);
    }

    if (dir1 == LEFT && dir2 == RIGHT && !_attributes[index1].prev && !_attributes[index2].next)
    {
        centre = ((*_attributes[index1].arc)[2] + (*_attributes[index2].arc)[1]) / 2;
        (*_attributes[index1].arc)[3] = centre;
        (*_attributes[index2].arc)[0] = centre;
        _attributes[index1].prev = &_attributes[index2];
        _attributes[index1].previousConnection = LEFT;
        _attributes[index2].next = &_attributes[index1];
        _attributes[index2].nextConnection = RIGHT;
        return generateImageOfSelectedArcs(index1, index2);
    }

    return GL_FALSE;
}


GLboolean SecondOrderTrigonometricCompositeCurve3::generateImageOfSelectedArcs(GLuint index1, GLuint index2)
{
    if (_attributes[index1].arc == nullptr || _attributes[index2].arc == nullptr)
    {
        return GL_FALSE;
    }

    delete _attributes[index1].image; _attributes[index1].image = nullptr;

    _attributes[index1].image = _attributes[index1].arc->GenerateImage(_arc_max_derivative_order, _arc_div_point_count);

    if (!_attributes[index1].image)
    {
        return GL_FALSE;
    }

    if (!_attributes[index1].image->UpdateVertexBufferObjects())
    {
        return GL_FALSE;
    }

    if (!_attributes[index1].arc->UpdateVertexBufferObjectsOfData())
    {
        return GL_FALSE;
    }

    delete _attributes[index2].image; _attributes[index2].image = nullptr;

    _attributes[index2].image = _attributes[index2].arc->GenerateImage(_arc_max_derivative_order, _arc_div_point_count);

    if (!_attributes[index2].image)
    {
        return GL_FALSE;
    }

    if (!_attributes[index2].image->UpdateVertexBufferObjects())
    {
        return GL_FALSE;
    }

    if (!_attributes[index2].arc->UpdateVertexBufferObjectsOfData())
    {
        return GL_FALSE;
    }

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricCompositeCurve3::renderSelectedArc(GLuint index, GLuint order, GLenum renderMode)
{
    assert(index >= 0 && index <= _attributes.size());

    if (!_attributes[index].arc)
    {
        return GL_FALSE;
    }

    if (_attributes[index].arc && renderMode == GL_POINTS)
    {
        glPointSize(15.0f);
        glBegin(GL_POINTS);
            DCoordinate3 cp;
            glColor3f(0.0f, 1.0f, 0.0f);
            cp = (*_attributes[index].arc)[0];
            glVertex3f(cp[0], cp[1], cp[2]);

            glColor3f(1.0f, 1.0f, 1.0f);
            cp = (*_attributes[index].arc)[1];
            glVertex3f(cp[0], cp[1], cp[2]);

            glColor3f(1.0f, 1.0f, 1.0f);
            cp = (*_attributes[index].arc)[2];
            glVertex3f(cp[0], cp[1], cp[2]);

            glColor3f(1.0f, 0.0f, 0.0f);
            cp = (*_attributes[index].arc)[3];
            glVertex3f(cp[0], cp[1], cp[2]);
        glEnd();
        glPointSize(1.0f);

        if (index != _selected_arc_index)
        {
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        else
        {
            glColor3f(1.0f, 1.0f, 0.0f);
        }
        _attributes[index].arc->RenderData(GL_LINE_STRIP);
    }

    if (_attributes[index].image && renderMode != GL_POINTS)
    {
        glColor3f(_attributes[index].color->r(), _attributes[index].color->g(), _attributes[index].color->b());
        _attributes[index].image->RenderDerivatives(order, renderMode);
        return GL_TRUE;
    }

    return GL_FALSE;
}

void SecondOrderTrigonometricCompositeCurve3::setAlphaAndRenderArcs(double alpha, GLenum usageFlag)
{
    try
    {
        _alpha = alpha;
        setAlphaOfArcs();

        for (GLuint i = 0; i < _arc_count; ++i)
        {
             delete _attributes[i].image; _attributes[i].image = nullptr;
            _attributes[i].image = _attributes[i].arc->GenerateImage(_arc_max_derivative_order, _arc_div_point_count, usageFlag);
            if(!_attributes[i].image)
            {
                deleteAllArcs();
                throw Exception("Error occured during the image creation of the arc!");
            }

            if (!_attributes[i].image->UpdateVertexBufferObjects(_arc_scale))
            {
                deleteAllArcs();
                throw Exception("Error occured during the update of the VBOs of the arc!");
            }
        }
    } catch (Exception &e) {
        cout << e << endl;
    }
}

void SecondOrderTrigonometricCompositeCurve3::renderArcsWithModifiedDivPointCount(GLenum usageFlag)
{
    try
    {
        for (GLuint i = 0; i < _arc_count; ++i)
        {
             delete _attributes[i].image; _attributes[i].image = nullptr;
            _attributes[i].image = _attributes[i].arc->GenerateImage(_arc_max_derivative_order, _arc_div_point_count, usageFlag);
            if(!_attributes[i].image)
            {
                deleteAllArcs();
                throw Exception("Error occured during the image creation of the arc!");
            }

            if (!_attributes[i].image->UpdateVertexBufferObjects(_arc_scale))
            {
                deleteAllArcs();
                throw Exception("Error occured during the update of the VBOs of the arc!");
            }
        }
    } catch (Exception &e) {
        cout << e << endl;
    }
}

void SecondOrderTrigonometricCompositeCurve3::modifyArcPosition(GLuint index, GLuint cpIndex, double x, double y, double z, GLenum usageFlag)
{

}

GLboolean SecondOrderTrigonometricCompositeCurve3::renderAllArcs(GLuint order, GLenum renderMode)
{
    for (GLuint i = 0; i < _arc_count; ++i)
    {
        if (arcExists(i))
        {
            renderSelectedArc(i, order, renderMode);
        }
    }
    return GL_TRUE;
}

void SecondOrderTrigonometricCompositeCurve3::renderAllArcsScale()
{
    for (GLuint i = 0; i < _arc_count; ++i)
    {
        _attributes[i].image->UpdateVertexBufferObjects(_arc_scale);
    }
}

DCoordinate3 SecondOrderTrigonometricCompositeCurve3::getSelectedCP(GLuint arcIndex, GLuint cpIndex) const
{
    return (*_attributes[arcIndex].arc)[cpIndex];
}

void SecondOrderTrigonometricCompositeCurve3::setSelectedCP(GLuint index)
{
    _selected_cp = index;
}

void SecondOrderTrigonometricCompositeCurve3::setSelectedArc(GLuint index)
{
    _selected_arc_index = index;
}

GLdouble SecondOrderTrigonometricCompositeCurve3::getAlpha() const
{
    return _alpha;
}

void SecondOrderTrigonometricCompositeCurve3::setAlpha(GLdouble alpha)
{
    _alpha = alpha;
}

void SecondOrderTrigonometricCompositeCurve3::setAlphaOfArcs()
{
    for (GLuint i = 0; i < _arc_count; ++i)
    {
       _attributes[i].arc->SetAlpha(_alpha);
    }
}

GLdouble SecondOrderTrigonometricCompositeCurve3::getScale() const
{
    return _arc_scale;
}

void SecondOrderTrigonometricCompositeCurve3::setScale(GLdouble value)
{
    _arc_scale = value;
}

GLuint SecondOrderTrigonometricCompositeCurve3::getDivPointCount() const
{
    return _arc_div_point_count;
}

void SecondOrderTrigonometricCompositeCurve3::setDivPointCount(GLuint div_point_count)
{
    _arc_div_point_count = div_point_count;
}

GLuint SecondOrderTrigonometricCompositeCurve3::getArcCount() const
{
    return _arc_count;
}

