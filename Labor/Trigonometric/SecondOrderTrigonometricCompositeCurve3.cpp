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

