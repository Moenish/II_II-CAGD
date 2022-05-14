#pragma once

#include <cmath>
#include <GL/glew.h>

namespace cagd
{
    namespace SOTF
    {
        GLdouble f0(GLdouble alpha, GLdouble t);
        GLdouble f1(GLdouble alpha, GLdouble t);
        GLdouble f2(GLdouble alpha, GLdouble t);
        GLdouble f3(GLdouble alpha, GLdouble t);

        GLdouble f0_1(GLdouble alpha, GLdouble t);
        GLdouble f1_1(GLdouble alpha, GLdouble t);
        GLdouble f2_1(GLdouble alpha, GLdouble t);
        GLdouble f3_1(GLdouble alpha, GLdouble t);

        GLdouble f0_2(GLdouble alpha, GLdouble t);
        GLdouble f1_2(GLdouble alpha, GLdouble t);
        GLdouble f2_2(GLdouble alpha, GLdouble t);
        GLdouble f3_2(GLdouble alpha, GLdouble t);
    }
}
