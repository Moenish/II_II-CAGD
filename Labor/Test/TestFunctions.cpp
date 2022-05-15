#include <cmath>
#include "TestFunctions.h"
#include "../Core/Constants.h"

using namespace cagd;
using namespace std;

// Information about curve tests
GLuint curve_tests::count = 8;

std::vector<std::string> curve_tests::names()
{
    return std::vector<std::string>{"Spiral on cone", "Torus knot", "Rose", "Spherical spiral", "Helix", "Butterfly", "Teszt", "Torus"};
}

// Spiral on cone
GLdouble spiral_on_cone::u_min = -TWO_PI;
GLdouble spiral_on_cone::u_max = +TWO_PI;

DCoordinate3 spiral_on_cone::d0(GLdouble u)
{
    return DCoordinate3(u * cos(u), u * sin(u), u);
}

DCoordinate3 spiral_on_cone::d1(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3(c - u * s, s + u * c, 1.0);
}

DCoordinate3 spiral_on_cone::d2(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3(-2.0 * s - u * c, 2.0 * c - u * s, 0);
}

// Torus knot
GLdouble torus_knot::u_min = 0;
GLdouble torus_knot::u_max = 6 * PI;

DCoordinate3 torus_knot::d0(GLdouble u)
{
    GLdouble c = cos(2.0 * u / 3.0), s = sin(2.0 * u / 3.0);
    return DCoordinate3((2.0 + c) * cos(u), (2.0 + c) * sin(u), s);
}

DCoordinate3 torus_knot::d1(GLdouble u)
{
    GLdouble c = cos(2.0 * u / 3.0), s = sin(2.0 * u / 3.0);
    return DCoordinate3(-(c + 2.0) * sin(u) - (2.0 * s * cos(u) / 3.0),
                         (c + 2.0) * cos(u) - (2.0 * s * sin(u) / 3.0),
                         2.0 * c / 3.0);
}

DCoordinate3 torus_knot::d2(GLdouble u)
{
    GLdouble c = cos(2.0 * u / 3.0), s = sin(2.0 * u / 3.0);
    return DCoordinate3( (12.0 * s * sin(u) + (-13.0 * c - 18.0) * cos(u)) / 9.0,
                        -((13.0 * c + 18.0) * sin(u) + 12.0 * s * cos(u)) / 9.0,
                        -4.0 * s / 9.0);
}

// Rose
GLdouble rose::u_min = 0;
GLdouble rose::u_max = 10 * PI;

DCoordinate3 rose::d0(GLdouble u)
{
    GLdouble r = cos(4.0 / 5.0 * u);
    return DCoordinate3(r * cos(u), r * sin(u), r);
}

DCoordinate3 rose::d1(GLdouble u)
{
    GLdouble r = cos(4.0 / 5.0 * u);
    return DCoordinate3(-r * sin(u), r * cos(u), 0);
}

DCoordinate3 rose::d2(GLdouble u)
{
    GLdouble r = cos(4.0 / 5.0 * u);
    return DCoordinate3(-r * cos(u), -r * sin(u), 0);
}

// Spherical spiral
GLdouble spherical_spiral::u_min = -300;
GLdouble spherical_spiral::u_max = 300;
GLdouble spherical_spiral::a = 0.1;

DCoordinate3 spherical_spiral::d0(GLdouble u)
{
    return DCoordinate3(cos(u) / sqrt(1.0 + (a * a * u * u)), sin(u) / sqrt(1.0 + (a * a * u * u)), -(a * u) / sqrt(1.0 + (a * a * u * u)));
}

DCoordinate3 spherical_spiral::d1(GLdouble u)
{
    GLdouble x = -((a*a*u*u + 1.0)*sin(u) + a*a*u*cos(u)) / (pow((a*a*u*u + 1.0), (3.0/2.0)));
    GLdouble y = -(a*a*u*sin(u) + (-a*a*u*u - 1.0)*cos(u)) / (pow((a*a*u*u + 1.0), (3.0/2.0)));
    GLdouble z = -a / (pow((a*a*u*u + 1.0), (3.0/2.0)));
    return DCoordinate3(x, y, z);
}

DCoordinate3 spherical_spiral::d2(GLdouble u)
{
    GLdouble x = ((2.0*a*a*a*a*u*u*u + 2.0*a*a*u)*sin(u) + (-a*a*a*a*u*u*u*u + (2.0*a*a*a*a - 2.0*a*a)*u*u - a*a - 1.0)*cos(u)) / (pow((a*a*u*u + 1.0), (5.0/2.0)));
    GLdouble y = -((a*a*a*a*u*u*u*u + (2.0*a*a - 2.0*a*a*a*a)*u*u + a*a + 1.0)*sin(u) + (2.0*a*a*a*a*u*u*u + 2.0*a*a*u)*cos(u)) / (pow((a*a*u*u + 1.0), (5.0/2.0)));
    GLdouble z = (3.0*a*a*a * u) / (pow((a*a*u*u + 1.0), (5.0/2.0)));
    return DCoordinate3(x, y, z);
}


// Helix
GLdouble helix::u_min = 0;
GLdouble helix::u_max = 8.0 * PI;
GLdouble helix::c = 0.1;
GLdouble helix::r = 1.5;

DCoordinate3 helix::d0(GLdouble u)
{
    return DCoordinate3(r * cos(u), r * sin(u), c * u);
}

DCoordinate3 helix::d1(GLdouble u)
{
    return DCoordinate3(-r * sin(u), r * cos(u), c);
}

DCoordinate3 helix::d2(GLdouble u)
{
    return DCoordinate3(-r * cos(u), -r * sin(u), 0);
}



// Butterfly
GLdouble butterfly::u_min = 0;
GLdouble butterfly::u_max = 12.0 * PI;

DCoordinate3 butterfly::d0(GLdouble u)
{
    return DCoordinate3(sin(u) * (exp(cos(u)) - 2.0 * cos(4.0 * u) - pow(sin(u / 12.0), 5.0)), cos(u) * (exp(cos(u)) - 2.0 * cos(4.0 * u) - pow(sin(u / 12.0), 5.0)), cos(u) * sin(u));
}

DCoordinate3 butterfly::d1(GLdouble u)
{
    GLdouble x = sin(u) * (8.0 * sin(4.0 * u) - exp(cos(u))*sin(u) - ((5.0 * cos(u / 12.0) * pow(sin(u / 12.0), 4.0)) / 12.0)) + cos(u) * (-2.0 * cos(4.0 * u) + exp(cos(u)) - pow(sin(u / 12.0), 5.0));
    GLdouble y = cos(u) * (8.0 * sin(4.0 * u) - exp(cos(u))*sin(u) - ((5.0 * cos(u / 12.0) * pow(sin(u / 12.0), 4.0)) / 12.0)) - sin(u) * (-2.0 * cos(4.0 * u) + exp(cos(u)) - pow(sin(u / 12.0), 5.0));
    return DCoordinate3(x, y, pow(cos(u), 2.0) - pow(sin(u), 2.0));
}

DCoordinate3 butterfly::d2(GLdouble u)
{
    GLdouble x =  (2304.0*cos(u)*sin(4.0*u)+4896.0*sin(u)*cos(4.0*u)+144.0*exp(cos(u))*pow(sin(u),3.0)+(-432.0*exp(cos(u))*cos(u)-144.0*exp(cos(u))+149.0*pow(sin(u/12.0),5.0)-20.0*pow(cos(u/12.0),2.0)*pow(sin(u/12.0), 3.0))*sin(u)-120.0*cos(u/12.0)*pow(sin(u/12.0),4.0)*cos(u))/144.0;
    GLdouble y = -(2304.0*sin(u)*sin(4.0*u)-4896.0*cos(u)*cos(4.0*u)+(-144.0*exp(cos(u))*cos(u)-288.0*exp(cos(u)))*pow(sin(u),2.0)-120.0*cos(u/12.0)*pow(sin(u/12.0),4.0)*sin(u)+144.0*exp(cos(u))*pow(cos(u),2.0)+(144.0*exp(cos(u))-149.0*pow(sin(u/12.0),5.0)+20.0*pow(cos(u/12.0),2.0)*pow(sin(u/12.0),3.0))*cos(u))/144.0;
    return 0.025*DCoordinate3(x, y, -4.0 * cos(u) * sin(u));
}


// Teszt
GLdouble test::u_min = -2 * PI;
GLdouble test::u_max = 2 * PI;
GLdouble test::a = 2.0;
GLdouble test::r = 1.1;

DCoordinate3 test::d0(GLdouble u)
{
    return DCoordinate3(r * cos(u), r * sin(u), a*r*r*u*u);
}

DCoordinate3 test::d1(GLdouble u)
{
    return DCoordinate3(-r * sin(u), r * cos(u), 2.0*a*r*r*u);
}

DCoordinate3 test::d2(GLdouble u)
{
    return DCoordinate3(-r * cos(u), -r * sin(u), 2.0*a*r*r);
}


// Torus
GLdouble torus::u_min = -10 * PI;
GLdouble torus::u_max = 10 * PI;
GLdouble torus::p = 1.0;

DCoordinate3 torus::d0(GLdouble u)
{
    return DCoordinate3(p * sin(u) * cos(u), p * sin(u) * sin(u), p * cos(u));
}

DCoordinate3 torus::d1(GLdouble u)
{
    return DCoordinate3(-p * (sin(u) * sin(u) - cos(u) * cos(u)), 2.0 * p * cos(u) * sin(u), 0);
}

DCoordinate3 torus::d2(GLdouble u)
{
    return DCoordinate3(-4.0 * p * cos(u) * sin(u), -2.0 * (sin(u) * sin(u) - cos(u) * cos(u)), 0);
}




// Information about surface tests
GLuint surface_tests::count = 6;

std::vector<std::string> surface_tests::names()
{
    return std::vector<std::string>{"Torus", "Sphere", "Hyperboloid", "Plane", "Cone", "Cylinder"};
}

// Torus Surface
GLdouble torusSurface::u_min = -1 * PI;
GLdouble torusSurface::u_max = 1 * PI;
GLdouble torusSurface::v_min = -1 * PI;
GLdouble torusSurface::v_max = 1 * PI;
GLdouble torusSurface::r = 2.0;
GLdouble torusSurface::p = 1.0;

DCoordinate3 torusSurface::d0(GLdouble u)
{
    return DCoordinate3((r + p * cos(3 * u)) * cos(u), (r + p * cos(3 * u)) * sin(u), p * sin(3 * u));
}
DCoordinate3 torusSurface::d1(GLdouble u)
{
    return DCoordinate3(-3 * p * cos(u) * sin(3 * u) - sin(u) * (p * cos(3 * u) + r),
                        cos(u) * (p * cos(3 * u) + r) - 3 * p * sin(u) * sin(3 * u),
                        3 * p * cos(3 * u));
}
DCoordinate3 torusSurface::d2(GLdouble u)
{
    return DCoordinate3(6 * p * sin(u) * sin(3 * u) - 10 * p * cos(u) * cos(3 * u) - r * cos(u),
                        -6 * p * cos(u) * sin(3 * u) - 10 * p * sin(u) * cos(3 * u) - r * sin(u),
                        -9 * p * sin(3 * u));
}

DCoordinate3 torusSurface::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3((r + p * cos(v)) * cos(u), (r + p * cos(v)) * sin(u), p * sin(v));
}

DCoordinate3 torusSurface::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(-(p * cos(v) + r) * sin(u), (p * cos(v) + r) * cos(u), 0);
}

DCoordinate3 torusSurface::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(-p * cos(u) * sin(v), -p * sin(u) * sin(v), p * cos(v));
}


// Sphere
GLdouble sphere::u_min = 0;
GLdouble sphere::u_max = PI;
GLdouble sphere::v_min = 0;
GLdouble sphere::v_max = 2 * PI;
GLdouble sphere::r = 4.0;

DCoordinate3 sphere::d0(GLdouble u)
{
    return DCoordinate3(r * sin(u) * cos(3 * u), r * sin(u) * sin(3 * u), r * cos(u));
}
DCoordinate3 sphere::d1(GLdouble u)
{
    return DCoordinate3(-r * (3 * sin(u) * sin(3 * u) - cos(u) * cos(3 * u)),
                        r * (cos(u)  *sin(3 * u) + 3 * sin(u) * cos(3 * u)),
                        -r * sin(u));
}
DCoordinate3 sphere::d2(GLdouble u)
{
    return DCoordinate3(-r * (6 * cos(u) * sin(3 * u) + 10 * sin(u) * cos(3 * u)),
                        r * (6 * cos(u) * cos(3 * u) - 10 * sin(u) * sin(3 * u)),
                        -r * cos(u));
}

DCoordinate3 sphere::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(r * sin(u) * cos(v), r * sin(u) * sin(v), r * cos(u));
}

DCoordinate3 sphere::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(r*cos(v)*cos(u), r*sin(v)*cos(u), -r*sin(u));
}

DCoordinate3 sphere::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(-r*sin(u)*sin(v), r*sin(u)*cos(v), 0);
}

// Hyperboloid
GLdouble hyperboloid::u_min = -3.0 * PI;
GLdouble hyperboloid::u_max = 3.0 * PI;
GLdouble hyperboloid::v_min = 0;
GLdouble hyperboloid::v_max = 2.0 * PI;
GLdouble hyperboloid::a = 1.0;
GLdouble hyperboloid::c = 1.0;

DCoordinate3 hyperboloid::d0(GLdouble u)
{
    return DCoordinate3(a * sqrt(1.0 + u * u) * cos(3.0 * u),
                        a * sqrt(1.0 + u * u) * sin(3.0 * u),
                        c * u);
}

DCoordinate3 hyperboloid::d1(GLdouble u)
{
    return DCoordinate3(-(a * ((3.0 * u * u + 3.0) * sin(3.0 * u) - u * cos(3.0 * u))) / sqrt(u * u + 1.0),
                        (a * (u * sin(3.0 * u) + (3.0 * u * u + 3.0) * cos(3.0 * u))) / sqrt(u * u + 1.0),
                        c);
}

DCoordinate3 hyperboloid::d2(GLdouble u)
{
    return DCoordinate3(-(a * ((6.0 * u * u * u + 6.0 * u) * sin(3.0 * u) + (9.0 * u * u * u * u + 18.0 * u * u + 8.0) * cos(3.0 * u))) / pow((u * u + 1.0), (3.0 / 2.0)),
                        -(a * ((9.0 * u * u * u * u + 18.0 * u * u + 8.0) * sin(3.0 * u) + (-6.0 * u * u * u - 6.0 * u) * cos(3.0 * u))) / pow((u * u + 1.0), (3.0 / 2.0)),
                        0.0);
}

DCoordinate3 hyperboloid::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(a * sqrt(1.0 + u * u) * cos(v), a * sqrt(1.0 + u * u) * sin(v), c * u);
}

DCoordinate3 hyperboloid::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3((a * cos(v) * u) / sqrt(u * u + 1.0), (a * sin(v) * u) / sqrt(u * u + 1.0), c);
}

DCoordinate3 hyperboloid::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(-a * sqrt(u * u + 1.0) * sin(v), a * sqrt(u * u + 1.0) * cos(v), 0.0);
}

// Plane
GLdouble plane::u_min = -3.0 * PI;;
GLdouble plane::u_max = 3.0 * PI;
GLdouble plane::v_min = -3.0 * PI;
GLdouble plane::v_max = 3.0 * PI;
GLdouble plane::a = 3.14;
GLdouble plane::b = 2.12;
GLdouble plane::c = 4.0;
GLdouble plane::d = 1.0;

DCoordinate3 plane::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(u, v, 1.0 / c * (d - a * u - b * v));
}

DCoordinate3 plane::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(1, 0 * u * v, -a / c);
}

DCoordinate3 plane::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(0 * u * v, 1 , -b / c);
}

// Cone
GLdouble cone::u_min = 0;
GLdouble cone::u_max = 2.0 * PI;
GLdouble cone::v_min = 0;
GLdouble cone::v_max = 2.0 * PI;
GLdouble cone::a = 3.0;


DCoordinate3 cone::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(u * cos(v), u * sin(v), a * u);
}

DCoordinate3 cone::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(cos(v), sin(v), a + 0 * u);
}

DCoordinate3 cone::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(-u * sin(v), u * cos(v), 0);
}

// Cylinder
GLdouble cylinder::u_min = 0;
GLdouble cylinder::u_max = 2.0 * PI;
GLdouble cylinder::v_min = 0;
GLdouble cylinder::v_max = 2.0 * PI;
GLdouble cylinder::a = 2.0;


DCoordinate3 cylinder::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(a * cos(u), a * sin(u), v);
}

DCoordinate3 cylinder::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(-a * sin(u), a * cos(u), 0 * u * v);
}

DCoordinate3 cylinder::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(0, 0 * u * v, 1);
}
