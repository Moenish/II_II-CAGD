#include "SecondOrderTrigonometricPatch3.h"
#include "SecondOrderTrigonometricFunctions.h"

using namespace cagd;


GLdouble SecondOrderTrigonometricPatch3::f0(GLdouble alpha, GLdouble t) const
{
    return SOTF::f0(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f1(GLdouble alpha, GLdouble t) const
{
    return SOTF::f1(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f2(GLdouble alpha, GLdouble t) const
{
    return SOTF::f2(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f3(GLdouble alpha, GLdouble t) const
{
    return SOTF::f3(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f0_1(GLdouble alpha, GLdouble t) const
{
    return SOTF::f0_1(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f1_1(GLdouble alpha, GLdouble t) const
{
    return SOTF::f1_1(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f2_1(GLdouble alpha, GLdouble t) const
{
    return SOTF::f2_1(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f3_1(GLdouble alpha, GLdouble t) const
{
    return SOTF::f3_1(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f0_2(GLdouble alpha, GLdouble t) const
{
    return SOTF::f0_2(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f1_2(GLdouble alpha, GLdouble t) const
{
    return SOTF::f1_2(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f2_2(GLdouble alpha, GLdouble t) const
{
    return SOTF::f2_2(alpha, t);
}

GLdouble SecondOrderTrigonometricPatch3::f3_2(GLdouble alpha, GLdouble t) const
{
    return SOTF::f3_2(alpha, t);
}



SecondOrderTrigonometricPatch3::SecondOrderTrigonometricPatch3(GLdouble u, GLdouble v): TensorProductSurface3(0.0, u, 0.0, v) { _alpha[0] = u; _alpha[1] = v; }

GLboolean SecondOrderTrigonometricPatch3::UBlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble> &blending_values) const
{
    if (u_knot < 0.0 || u_knot > _alpha[0])
        return GL_FALSE;

    blending_values.ResizeColumns(4);

    blending_values[0] = f0(_alpha[0], u_knot);
    blending_values[1] = f1(_alpha[0], u_knot);
    blending_values[2] = f2(_alpha[0], u_knot);
    blending_values[3] = f3(_alpha[0], u_knot);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::VBlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble> &blending_values) const
{
    if (v_knot < 0.0 || v_knot > _alpha[1])
        return GL_FALSE;

    blending_values.ResizeColumns(4);

    blending_values[0] = f0(_alpha[1], v_knot);
    blending_values[1] = f1(_alpha[1], v_knot);
    blending_values[2] = f2(_alpha[1], v_knot);
    blending_values[3] = f3(_alpha[1], v_knot);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::U1BlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble> &blending_values) const
{
    if (u_knot < 0.0 || u_knot > _alpha[0])
        return GL_FALSE;

    blending_values.ResizeColumns(4);

    blending_values[0] = f0_1(_alpha[0], u_knot);
    blending_values[1] = f1_1(_alpha[0], u_knot);
    blending_values[2] = f2_1(_alpha[0], u_knot);
    blending_values[3] = f3_1(_alpha[0], u_knot);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::V2BlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble> &blending_values) const
{
    if (v_knot < 0.0 || v_knot > _alpha[1])
        return GL_FALSE;

    blending_values.ResizeColumns(4);

    blending_values[0] = f0_2(_alpha[1], v_knot);
    blending_values[1] = f1_2(_alpha[1], v_knot);
    blending_values[2] = f2_2(_alpha[1], v_knot);
    blending_values[3] = f3_2(_alpha[1], v_knot);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::U2BlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble> &blending_values) const
{
    if (u_knot < 0.0 || u_knot > _alpha[0])
        return GL_FALSE;

    blending_values.ResizeColumns(4);

    blending_values[0] = f0_2(_alpha[0], u_knot);
    blending_values[1] = f1_2(_alpha[0], u_knot);
    blending_values[2] = f2_2(_alpha[0], u_knot);
    blending_values[3] = f3_2(_alpha[0], u_knot);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::V1BlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble> &blending_values) const
{
    if (v_knot < 0.0 || v_knot > _alpha[1])
        return GL_FALSE;

    blending_values.ResizeColumns(4);

    blending_values[0] = f0_1(_alpha[1], v_knot);
    blending_values[1] = f1_1(_alpha[1], v_knot);
    blending_values[2] = f2_1(_alpha[1], v_knot);
    blending_values[3] = f3_1(_alpha[1], v_knot);

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::CalculatePartialDerivatives(GLuint maximum_order_of_partial_derivatives, GLdouble u, GLdouble v, PartialDerivatives &pd) const
{
    if (u < 0.0 || u > _alpha[0] || v < 0.0 || v > _alpha[1] || maximum_order_of_partial_derivatives > 2) // 2
        return GL_FALSE;

    // Blending values + derivatives in dir. u
    RowMatrix<GLdouble> u_blending_values(4), d1_u_blending_values(4), d2_u_blending_values(4);

    UBlendingFunctionValues(u, u_blending_values);
    U1BlendingFunctionValues(u, d1_u_blending_values);
    U2BlendingFunctionValues(u, d2_u_blending_values);

    // Same VooDoo magic, but with dir. v
    RowMatrix<GLdouble> v_blending_values(4), d1_v_blending_values(4), d2_v_blending_values(4);

    VBlendingFunctionValues(v, v_blending_values);
    V1BlendingFunctionValues(v, d1_v_blending_values);
    V2BlendingFunctionValues(v, d2_v_blending_values);

    pd.ResizeRows(3); // 3
    pd.LoadNullVectors();

    for (GLuint row = 0; row < 4; ++row)
    {
        DCoordinate3 aux_d0_v, aux_d1_v, aux_d2_v;
        for (GLuint column = 0; column < 4; ++column)
        {
            aux_d0_v += _data(row, column) * v_blending_values(column);
            aux_d1_v += _data(row, column) * d1_v_blending_values(column);
            aux_d2_v += _data(row, column) * d2_v_blending_values(column);
        }
        pd(0, 0) += aux_d0_v * u_blending_values(row);          // surface point
        pd(1, 0) += aux_d0_v * d1_u_blending_values(row);       // 1st order dir. u partial
        pd(1, 1) += aux_d1_v * u_blending_values(row);          // 1st order dir. v partial

        pd(2, 0) += aux_d0_v * d2_u_blending_values[row];
        pd(2, 1) += aux_d1_v * d1_u_blending_values[row];
        pd(2, 2) += aux_d2_v * u_blending_values[row];
    }

    return GL_TRUE;
}

GLboolean SecondOrderTrigonometricPatch3::SetUAlpha(GLdouble alpha) {
    _alpha[0] = alpha;
    _u_max = alpha;
    return GL_TRUE;
}
GLdouble SecondOrderTrigonometricPatch3::GetUAlpha() {
    return _alpha[0];
}

GLboolean SecondOrderTrigonometricPatch3::SetVAlpha(GLdouble alpha) {
    _alpha[1] = alpha;
    _v_max = alpha;
    return GL_TRUE;
}
GLdouble SecondOrderTrigonometricPatch3::GetVAlpha() {
    return _alpha[1];
}
