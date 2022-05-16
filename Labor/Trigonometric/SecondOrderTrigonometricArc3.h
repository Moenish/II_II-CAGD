#include <Core/LinearCombination3.h>
#include <Core/Constants.h>

namespace cagd
{
    class SecondOrderTrigonometricArc3: public LinearCombination3
    {
    private:
        SecondOrderTrigonometricArc3 *lArc;
        SecondOrderTrigonometricArc3 *rArc;

        GLdouble _alpha = PI / 2.0;

        GLdouble f0(GLdouble t) const;
        GLdouble f1(GLdouble t) const;
        GLdouble f2(GLdouble t) const;
        GLdouble f3(GLdouble t) const;

        GLdouble f0_1(GLdouble t) const;
        GLdouble f1_1(GLdouble t) const;
        GLdouble f2_1(GLdouble t) const;
        GLdouble f3_1(GLdouble t) const;

        GLdouble f0_2(GLdouble t) const;
        GLdouble f1_2(GLdouble t) const;
        GLdouble f2_2(GLdouble t) const;
        GLdouble f3_2(GLdouble t) const;
    public:
        SecondOrderTrigonometricArc3(GLdouble alpha = PI / 2.0, GLenum data_usage_flag = GL_STATIC_DRAW);

        GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
        GLboolean CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives& d) const;

        GLboolean SetAlpha(GLdouble alpha);
        GLdouble GetAlpha() const;

        GLboolean SetPoint(GLuint row, GLuint col, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetPoint(GLuint row, GLuint col, const DCoordinate3 &position);
    };
}
