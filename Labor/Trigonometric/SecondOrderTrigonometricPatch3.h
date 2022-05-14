#pragma once

#include "../Core/TensorProductSurfaces3.h"
#include "../Core/Constants.h"

namespace cagd
{
    class SecondOrderTrigonometricPatch3: public TensorProductSurface3
    {
    private:
        GLdouble _alpha[2]; // _alpha[0], _alpha[1], possible shape parameters in dir. u and v

        GLdouble f0(GLdouble alpha, GLdouble t) const;
        GLdouble f1(GLdouble alpha, GLdouble t) const;
        GLdouble f2(GLdouble alpha, GLdouble t) const;
        GLdouble f3(GLdouble alpha, GLdouble t) const;

        GLdouble f0_1(GLdouble alpha, GLdouble t) const;
        GLdouble f1_1(GLdouble alpha, GLdouble t) const;
        GLdouble f2_1(GLdouble alpha, GLdouble t) const;
        GLdouble f3_1(GLdouble alpha, GLdouble t) const;

        GLdouble f0_2(GLdouble alpha, GLdouble t) const;
        GLdouble f1_2(GLdouble alpha, GLdouble t) const;
        GLdouble f2_2(GLdouble alpha, GLdouble t) const;
        GLdouble f3_2(GLdouble alpha, GLdouble t) const;

    public:
        SecondOrderTrigonometricPatch3(GLdouble u_alpha = PI / 2.0, GLdouble v_alpha = 1.0);

        GLboolean UBlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean VBlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean U1BlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean V1BlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean U2BlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean V2BlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean CalculatePartialDerivatives(GLuint maximum_order_of_partial_derivatives, GLdouble u, GLdouble v, PartialDerivatives& pd) const;

        GLboolean SetUAlpha(GLdouble alpha);
        GLdouble GetUAlpha();

        GLboolean SetVAlpha(GLdouble alpha);
        GLdouble GetVAlpha();
    };
}
