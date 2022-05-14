#include "SecondOrderTrigonometricArc3.h"
#include "SecondOrderTrigonometricFunctions.h"
#include "../Core/Constants.h"

using namespace cagd;

GLdouble SecondOrderTrigonometricArc3::f0(GLdouble t) const
{
    return SOTF::f0(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f1(GLdouble t) const
{
    return SOTF::f1(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f2(GLdouble t) const
{
    return SOTF::f2(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f3(GLdouble t) const
{
    return SOTF::f3(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f0_1(GLdouble t) const
{
    return SOTF::f0_1(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f1_1(GLdouble t) const
{
    return SOTF::f1_1(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f2_1(GLdouble t) const
{
    return SOTF::f2_1(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f3_1(GLdouble t) const
{
    return SOTF::f3_1(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f0_2(GLdouble t) const
{
    return SOTF::f0_2(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f1_2(GLdouble t) const
{
    return SOTF::f1_2(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f2_2(GLdouble t) const
{
    return SOTF::f2_2(_alpha, t);
}

GLdouble SecondOrderTrigonometricArc3::f3_2(GLdouble t) const
{
    return SOTF::f3_2(_alpha, t);
}


SecondOrderTrigonometricArc3::SecondOrderTrigonometricArc3(GLdouble alpha, GLenum data_usage_flag): LinearCombination3(0.0, alpha, 4, data_usage_flag)
{
    _alpha = alpha;
}

GLboolean SecondOrderTrigonometricArc3::BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const
{
    values.ResizeColumns(4);

    values[0] = f0(u);
    values[1] = f1(u);
    values[2] = f2(u);
    values[3] = f3(u);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricArc3::CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives &d) const
{
    d.ResizeRows(max_order_of_derivatives + 1);
    d.LoadNullVectors();

    d[0] = f0(u) * _data[0] + f1(u) * _data[1] + f2(u) * _data[2] + f3(u) * _data[3];

    if(max_order_of_derivatives >= 1) {
        d[1] = f0_1(u) * _data[0] + f1_1(u) * _data[1] + f2_1(u) * _data[2] + f3_1(u) * _data[3];
    }

    if(max_order_of_derivatives == 2) {
        d[2] = f0_2(u) * _data[0] + f1_2(u) * _data[1] + f2_2(u) * _data[2] + f3_2(u) * _data[3];
    }
    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricArc3::SetAlpha(GLdouble alpha)
{
    _u_max = alpha;
    _alpha = alpha;
    return GL_TRUE;
}
GLdouble SecondOrderTrigonometricArc3::GetAlpha() const
{
    return _alpha;
}
