#pragma once

#include <GL/glew.h>
#include <limits>
#include <cmath>
#include "Matrices.h"

namespace cagd
{
    class RealSquareMatrix: public Matrix<GLdouble>
    {
    private:
        GLboolean           _lu_decomposition_is_done;
        std::vector<GLuint> _row_permutation;

    public:
        // special/default constructor
        RealSquareMatrix(GLuint size = 1);

        // homework: copy constructor
        RealSquareMatrix(const RealSquareMatrix& m);

        // homework: assignment operator
        RealSquareMatrix& operator =(const RealSquareMatrix& rhs);

        // homework: square matrices have the same number of rows and columns!
        GLboolean ResizeRows(GLuint row_count);
        GLboolean ResizeColumns(GLuint column_count);

        // tries to determine the LU decomposition of this square matrix
        GLboolean PerformLUDecomposition();

        // Solves linear systems of type A * x = b, where A is a regular square matrix,
        // while b and x are row or column matrices with elements of type T.
        // Here matrix A corresponds to *this.
        // Advantage: T can be either GLdouble or DCoordinate, 
        // or any other type which has similar mathematical operators.
        template <class T>
        GLboolean SolveLinearSystem(const Matrix<T>& b, Matrix<T>& x, GLboolean represent_solutions_as_columns = GL_TRUE);
    };

    inline RealSquareMatrix::RealSquareMatrix(const RealSquareMatrix& m):
        Matrix<GLdouble>(m),
        _lu_decomposition_is_done(m._lu_decomposition_is_done),
        _row_permutation(m._row_permutation)
    {
    }

    inline RealSquareMatrix& RealSquareMatrix::operator =(const RealSquareMatrix& rhs)
    {
        if (this != &rhs)
        {
            Matrix<GLdouble>::operator=(rhs);
            this->_lu_decomposition_is_done = rhs._lu_decomposition_is_done;
            this->_row_permutation = rhs._row_permutation;
        }

        return *this;
    }

    inline GLboolean RealSquareMatrix::ResizeRows(GLuint row_count)
    {
        return Matrix<GLdouble>::ResizeRows(row_count) && Matrix<GLdouble>::ResizeColumns(row_count);
    }

    inline GLboolean RealSquareMatrix::ResizeColumns(GLuint column_count)
    {
        return Matrix<GLdouble>::ResizeRows(column_count) && Matrix<GLdouble>::ResizeColumns(column_count);;
    }

    template <class T>
    inline GLboolean RealSquareMatrix::SolveLinearSystem(const Matrix<T>& b, Matrix<T>& x, GLboolean represent_solutions_as_columns)
    {
        if (!_lu_decomposition_is_done)
            if (!PerformLUDecomposition())
                return GL_FALSE;

        if (represent_solutions_as_columns)
        {
            GLint size = static_cast<GLint>(GetColumnCount());
            if (static_cast<GLint>(b.GetRowCount()) != size)
                    return GL_FALSE;

            x = b;

            for (GLuint k = 0; k < b.GetColumnCount(); ++k)
            {
                GLint ii = 0;
                for (GLint i = 0; i < size; ++i)
                {
                    GLuint ip = _row_permutation[i];
                    T sum = x(ip, k);
                    x(ip, k) = x(i, k);
                    if (ii != 0)
                        for (GLint j = ii - 1; j < i; ++j)
                            sum -= _data[i][j] * x(j, k);
                    else
                        if (sum != 0.0)
                            ii = i + 1;
                    x(i, k) = sum;
                }

                for (GLint i = size - 1; i >= 0; --i)
                {
                    T sum = x(i, k);
                    for (GLint j = i + 1; j < size; ++j)
                        sum -= _data[i][j] * x(j, k);
                    x(i, k) = sum /= _data[i][i];
                }
            }
        }
        else
        {
            GLint size = static_cast<GLint>(GetRowCount());
            if (static_cast<GLint>(b.GetColumnCount()) != size)
                return GL_FALSE;

            x = b;

            for (GLuint k = 0; k < b.GetRowCount(); ++k)
            {
                GLint ii = 0;
                for (GLint i = 0; i < size; ++i)
                {
                    GLuint ip = _row_permutation[i];
                    T sum = x(k, ip);
                    x(k, ip) = x(k, i);
                    if (ii != 0)
                        for (GLint j = ii - 1; j < i; ++j)
                            sum -= _data[i][j] * x(k, j);
                    else
                        if (sum != 0.0)
                            ii = i + 1;
                    x(k, i) = sum;
                }

                for (GLint i = size - 1; i >= 0; --i)
                {
                    T sum = x(k, i);
                    for (GLint j = i + 1; j < size; ++j)
                        sum -= _data[i][j] * x(k, j);
                    x(k, i) = sum /= _data[i][i];
                }
            }
        }

        return GL_TRUE;
    }


// Immigrant functions

inline RealSquareMatrix::RealSquareMatrix(GLuint size):
        Matrix<GLdouble>(size, size),
        _lu_decomposition_is_done(GL_FALSE)
{
}

inline GLboolean RealSquareMatrix::PerformLUDecomposition()
{
    if (_lu_decomposition_is_done)
        return GL_TRUE;

    if (_row_count <= 1)
        return GL_FALSE;

    const GLdouble tiny = std::numeric_limits<GLdouble>::min();

    GLuint size = static_cast<GLuint>(_data.size());
    std::vector<GLdouble> implicit_scaling_of_each_row(size);

    _row_permutation.resize(size);

    GLdouble row_interchanges = 1.0;

    //-------------------------------------------------------
    // loop over rows to get the implicit scaling information
    //-------------------------------------------------------
    std::vector<GLdouble>::iterator its = implicit_scaling_of_each_row.begin();
    for (std::vector<std::vector<GLdouble> >::const_iterator itr = _data.begin(); itr < _data.end(); ++itr)
    {
        GLdouble big = 0.0;
        for (std::vector<GLdouble>::const_iterator itc = itr->begin(); itc < itr->end(); ++itc)
        {
            GLdouble temp = abs(*itc);
            if (temp > big)
                    big = temp;
        }

        if (big == 0.0)
        {
            // the matrix is singular
            return GL_FALSE;
        }
        *its = 1.0 / big;
        ++its;
    }

    //-----------------------------------
    // search for the largest pivot element
    //-----------------------------------
    for (GLuint k = 0; k < size; ++k)
    {
        GLuint imax = k;
        GLdouble big = 0.0;
        for (GLuint i = k; i < size; ++i)
        {
            GLdouble temp = implicit_scaling_of_each_row[i] * abs(_data[i][k]);
            if (temp > big)
            {
                big = temp;
                imax = i;
            }
        }

        // do we need to interchange rows?
        if (k != imax)
        {
            for (GLuint j = 0; j < size; ++j)
            {
                GLdouble temp = _data[imax][j];
                _data[imax][j] = _data[k][j];
                _data[k][j] = temp;
            }
            // change the parity of row_interchanges
            row_interchanges = -row_interchanges;
            // also interchange the scale factor
            implicit_scaling_of_each_row[imax] = implicit_scaling_of_each_row[k];
        }

        _row_permutation[k] = imax;
        if (_data[k][k] == 0.0)
            _data[k][k] = tiny;

        for (GLuint i = k + 1; i < size; ++i)
        {
            // divide by pivot element
            GLdouble temp = _data[i][k] /= _data[k][k];

            // reduce remaining submatrix
            for (GLuint j = k + 1; j < size; ++j)
                _data[i][j] -= temp * _data[k][j];
        }
    }

    _lu_decomposition_is_done = GL_TRUE;

    return GL_TRUE;
}

}
