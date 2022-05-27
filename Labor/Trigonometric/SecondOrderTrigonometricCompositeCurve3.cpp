#include <iostream>
#include <random>
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
    return GL_TRUE;
}
