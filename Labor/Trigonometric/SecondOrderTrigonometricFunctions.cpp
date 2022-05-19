#include "SecondOrderTrigonometricFunctions.h"

using namespace cagd;

GLdouble SOTF::f0(GLdouble alpha, GLdouble t)
{
    return SOTF::f3(alpha, alpha - t);
}
GLdouble SOTF::f1(GLdouble alpha, GLdouble t)
{
    return SOTF::f2(alpha, alpha - t);
}
GLdouble SOTF::f2(GLdouble alpha, GLdouble t)
{
    GLdouble c1 = alpha / 2.0;
    GLdouble c2 = t / 2.0;
    GLdouble c3 = c1 - c2;

    GLdouble sin4Alpha = sin(c1) * sin(c1) * sin(c1) * sin(c1);
    GLdouble sin3T = sin(c2) * sin(c2) * sin(c2);

    return (4.0 * cos(c1) / sin4Alpha * sin(c3) * sin3T) +
            (((1.0 + 2.0 * cos(c1) * cos(c1)) / sin4Alpha) * (sin(c3) * sin(c3)) * (sin(c2) * sin(c2)));
}
GLdouble SOTF::f3(GLdouble alpha, GLdouble t)
{
    GLdouble c1 = alpha / 2.0;
    GLdouble c2 = t / 2.0;

    GLdouble sin4Alpha = sin(c1) * sin(c1) * sin(c1) * sin(c1);
    GLdouble sin4T = sin(c2) * sin(c2) * sin(c2) * sin(c2);

    return (1.0 / (sin4Alpha)) * (sin4T);
}

GLdouble SOTF::f0_1(GLdouble alpha, GLdouble t)
{
    return -SOTF::f3_1(alpha, alpha - t);
}
GLdouble SOTF::f1_1(GLdouble alpha, GLdouble t)
{
    return -SOTF::f2_1(alpha, alpha - t);
}
GLdouble SOTF::f2_1(GLdouble alpha, GLdouble t)
{
    GLdouble c1 = alpha / 2.0;
    GLdouble c2 = t / 2.0;
    GLdouble c3 = c1 - c2;

    GLdouble sin4Alpha = sin(c1) * sin(c1) * sin(c1) * sin(c1);
//    GLdouble cos2Alpha = cos(c1) * cos(c1);

//    return (sin(c3) * cos(c2) * sin(c2) * (6.0 * cos(c1) * sin(c2) + (2.0 * cos2Alpha + 1.0) * sin(c3))) / sin4Alpha;
    return -(sin(c2)*(2.0*cos(c1)*cos(c3)*sin(c2)*sin(c2)+((2.0*cos(c1)*cos(c1)+1.0)*cos(c3)*sin(c3)-6*cos(c1)*sin(c3)*cos(c2))*sin(c2)+(-2.0*cos(c1)*cos(c1)-1.0)*sin(c3)*sin(c3)*cos(c2)))/sin4Alpha;

}
GLdouble SOTF::f3_1(GLdouble alpha, GLdouble t)
{
    GLdouble c1 = alpha / 2.0;
    GLdouble c2 = t / 2.0;

    GLdouble sin4Alpha = sin(c1) * sin(c1) * sin(c1) * sin(c1);
    GLdouble sin3T = sin(c2) * sin(c2) * sin(c2);

//    return (2.0 * cos(c2) * sin3T) / sin4Alpha;
    return (1.0 / (sin4Alpha)) * 2.0 * (sin3T) * cos(t / 2.0);
}

GLdouble SOTF::f0_2(GLdouble alpha, GLdouble t)
{
    return f3_2(alpha, alpha - t);
}
GLdouble SOTF::f1_2(GLdouble alpha, GLdouble t)
{
    return f2_2(alpha, alpha - t);
}
GLdouble SOTF::f2_2(GLdouble alpha, GLdouble t)
{
    GLdouble c1 = alpha / 2.0;
    GLdouble c2 = t / 2.0;
    GLdouble c3 = c1 - c2;

    GLdouble sin4Alpha = sin(c1) * sin(c1) * sin(c1) * sin(c1);
    GLdouble cos2Alpha = cos(c1) * cos(c1);
    GLdouble sin2T = sin(c2) * sin(c2);
    GLdouble sin3T = sin2T * sin(c2);

//    return -(sin(c3) * (6.0 * cos(c1) * sin3T + (2.0 * cos2Alpha + 1.0) * sin(c3) * sin2T -12.0 * cos(c1) * cos(c2) * cos(c2) * sin(c2) + (-2.0 * cos2Alpha - 1.0) * sin(c3) * cos(c2) * cos(c2))) / (2*sin4Alpha);
    return -(8.0*cos(alpha/2.0)*sin((alpha-t)/2.0)*sin3T+(12.0*cos(alpha/2.0)*cos((alpha-t)/2.0)*cos(t/2.0)+(4.0*cos(alpha/2.0)*cos(alpha/2.0)+2.0)*sin((alpha-t)/2.0)*sin((alpha-t)/2.0)+(-2.0*cos(alpha/2.0)*cos(alpha/2.0)-1.0)*cos((alpha-t)/2.0)*cos((alpha-t)/2.0))*sin(t/2.0)*sin(t/2.0)+((8.0*cos(alpha/2.0)*cos(alpha/2.0)+4.0)*cos((alpha-t)/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)-12.0*cos(alpha/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)*cos(t/2.0))*sin(t/2.0)+(-2.0*cos(alpha/2.0)*cos(alpha/2.0)-1.0)*sin((alpha-t)/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)*cos(t/2.0))/(2.0*sin4Alpha);
}
GLdouble SOTF::f3_2(GLdouble alpha, GLdouble t)
{
    GLdouble c1 = alpha / 2.0;
    GLdouble c2 = t / 2.0;

    GLdouble sin4Alpha = sin(c1) * sin(c1) * sin(c1) * sin(c1);
    GLdouble sin2T = sin(c2) * sin(c2) * sin(c2);
    GLdouble sin3T = sin2T * sin(c2);
    GLdouble sin4T = sin3T * sin(c2);

//    return -(sin4T - 3.0 * cos(c2) * cos(c2) * sin2T) / sin4Alpha;
    return (1.0 / (sin4Alpha)) * 3.0 * (sin(t / 2.0) * sin(t / 2.0)) * cos(t / 2.0) * cos(t / 2.0) + (1.0 / (sin4Alpha)) * (sin3T) * -sin(t / 2.0);
}
