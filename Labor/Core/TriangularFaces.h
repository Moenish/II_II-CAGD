#pragma once

#include <GL/glew.h>
#include <iostream>
#include <vector>

namespace cagd
{
    class TriangularFace
    {
    protected:
        GLuint _node[3];

    public:
        // default constructor
        TriangularFace();

        // homework: copy constructor
        TriangularFace(const TriangularFace& face);

        // homework: assignment operator
        TriangularFace& operator =(const TriangularFace& rhs);

        // homework: get node identifiers by value
        GLuint operator [](GLuint i) const;

        // homework: get node identifiers by reference
        GLuint& operator [](GLuint i);
    };

    // default constructor
    inline TriangularFace::TriangularFace()
    {
        _node[0] = _node[1] = _node[2] = 0;
    }

    // homework: copy constructor
    inline TriangularFace::TriangularFace(const TriangularFace& face)
    {
        _node[0] = face._node[0];
        _node[1] = face._node[1];
        _node[2] = face._node[2];
    }

    // homework: assignment operator
    inline TriangularFace& TriangularFace::operator =(const TriangularFace& rhs)
    {
        _node[0] = rhs._node[0];
        _node[1] = rhs._node[1];
        _node[2] = rhs._node[2];
        return *this;
    }

    // homework: get node identifiers by value
    inline GLuint TriangularFace::operator [](GLuint i) const
    {
        return _node[i];
    }

    // homework: get node identifiers by reference
    inline GLuint& TriangularFace::operator [](GLuint i)
    {
        return _node[i];
    }

    // output to stream
    inline std::ostream& operator <<(std::ostream& lhs, const TriangularFace& rhs)
    {
        lhs << 3;
        for (GLuint i = 0; i < 3; ++i)
            lhs  << " " << rhs[i];
        return lhs;
    }

    // homework
    inline std::istream& operator >>(std::istream& lhs, TriangularFace& rhs)
    {
        GLuint n;
        lhs >> n;
        for(GLuint i = 0; i < n; i++)
            lhs >> rhs[i];
        return lhs;
    }
}
