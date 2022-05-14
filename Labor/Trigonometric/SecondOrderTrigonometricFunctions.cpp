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
    GLdouble sin4Alpha = sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0);
    GLdouble sin3T = sin(t / 2.0) * sin(t / 2.0) * sin(t / 2.0);

    return ((4 * cos(alpha / 2.0)) / sin4Alpha) * sin((alpha - t) / 2.0) * sin3T +
            ((1 + 2 * cos(alpha / 2.0) * cos(alpha / 2.0)) / sin4Alpha)
            * (sin((alpha - t) / 2.0) * sin((alpha - t) / 2.0))
            * (sin(t / 2.0) * sin(t / 2.0));
}
GLdouble SOTF::f3(GLdouble alpha, GLdouble t)
{
    GLdouble sin4Alpha = sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0);
    GLdouble sin4T = sin(t / 2.0) * sin(t / 2.0) * sin(t / 2.0) * sin(t / 2.0);

    return (1 / (sin4Alpha)) * (sin4T);
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
    GLdouble sin4Alpha = sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0);
    return -(sin(t/2.0)*(2.0*cos(alpha/2.0)*cos((alpha-t)/2.0)*sin(t/2.0)*sin(t/2.0)+((2.0*cos(alpha/2.0)*cos(alpha/2.0)+1.0)*cos((alpha-t)/2.0)*sin((alpha-t)/2.0)-6*cos(alpha/2.0)*sin((alpha-t)/2.0)*cos(t/2.0))*sin(t/2.0)+(-2.0*cos(alpha/2.0)*cos(alpha/2.0)-1.0)*sin((alpha-t)/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)))/sin4Alpha;
}
GLdouble SOTF::f3_1(GLdouble alpha, GLdouble t)
{
    GLdouble sin4Alpha = sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0);
    GLdouble sin3T = sin(t / 2.0) * sin(t / 2.0) * sin(t / 2.0);
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
    GLdouble sin4Alpha = sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0);
    GLdouble sin3T = sin(t/2.0) * sin(t/2.0) * sin(t/2.0);

    return -(8.0*cos(alpha/2.0)*sin((alpha-t)/2.0)*sin3T+(12.0*cos(alpha/2.0)*cos((alpha-t)/2.0)*cos(t/2.0)+(4.0*cos(alpha/2.0)*cos(alpha/2.0)+2.0)*sin((alpha-t)/2.0)*sin((alpha-t)/2.0)+(-2*cos(alpha/2.0)*cos(alpha/2.0)-1.0)*cos((alpha-t)/2.0)*cos((alpha-t)/2.0))*sin(t/2.0)*sin(t/2.0)+((8.0*cos(alpha/2.0)*cos(alpha/2.0)+4.0)*cos((alpha-t)/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)-12.0*cos(alpha/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)*cos(t/2.0))*sin(t/2.0)+(-2.0*cos(alpha/2.0)*cos(alpha/2.0)-1.0)*sin((alpha-t)/2.0)*sin((alpha-t)/2.0)*cos(t/2.0)*cos(t/2.0))/(2.0*sin4Alpha);
}
GLdouble SOTF::f3_2(GLdouble alpha, GLdouble t)
{
    GLdouble sin4Alpha = sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0) * sin(alpha / 2.0);
    GLdouble sin3T = sin(t / 2.0) * sin(t / 2.0) * sin(t / 2.0);
    return (1.0 / (sin4Alpha)) * 3.0 * (sin(t / 2.0) * sin(t / 2.0)) * cos(t / 2.0) * cos(t / 2.0) + (1.0 / (sin4Alpha)) * (sin3T) * -sin(t / 2.0);
}
