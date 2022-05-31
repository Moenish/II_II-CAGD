#ifndef SECONDORDERTRIGONOMETRICCOMPOSITECURVE3_H
#define SECONDORDERTRIGONOMETRICCOMPOSITECURVE3_H

#include "SecondOrderTrigonometricArc3.h"
#include <Core/Colors4.h>
#include <Core/Exceptions.h>

using namespace std;

namespace cagd
{
    class SecondOrderTrigonometricCompositeCurve3
    {
    public:
        enum Direction{LEFT, RIGHT};
        
        class ArcAttributes
        {
        public:
            SecondOrderTrigonometricArc3    *arc;
            GenericCurve3                   *image;
            Color4                          *color;
            
            ArcAttributes       *prev, *next;
            Direction           previousConnection, nextConnection;

            ArcAttributes()
            {
                arc = nullptr;
                image = nullptr;
                prev = nullptr;
                next = nullptr;
                color = new Color4(0.0, 0.0, 1.0);
            }
            
            ArcAttributes(const ArcAttributes &rhs)
            {
                this->arc = new SecondOrderTrigonometricArc3(rhs.arc->GetAlpha());
                (*arc)[0] = (*rhs.arc)[0];
                (*arc)[1] = (*rhs.arc)[1];
                (*arc)[2] = (*rhs.arc)[2];
                (*arc)[3] = (*rhs.arc)[3];
                
                arc->UpdateVertexBufferObjectsOfData();
                this->color = rhs.color;
                this->prev = rhs.prev;
                this->next = rhs.next;
                this->image = arc->GenerateImage(2, 100);
                image->UpdateVertexBufferObjects();
            }
            
            ~ArcAttributes()
            {
                if (arc)
                {
                    delete arc;
                    arc = nullptr;
                }
                if (image)
                {
                    delete image;
                    image = nullptr;
                }
            }
        };
        
        
        SecondOrderTrigonometricCompositeCurve3(GLdouble alpha = 1.0, GLuint minimalReservedArcCount = 1000);
        
        GLboolean   insertLine(Color4 *color, GLuint maxDerivativeOrder, GLuint divPointCount, const std::vector<DCoordinate3>&points = _default_line_points, GLenum usageFlag = GL_STATIC_DRAW);
        GLboolean   insertArc(Color4 *color, GLuint maxDerivativeOrder, GLuint divPointCount, const std::vector<DCoordinate3>&points = _default_arc_points, GLenum usage_flag = GL_STATIC_DRAW);
        GLboolean   deleteExistingArc(GLuint index);
        void        deleteAllArcs();
        GLboolean   arcExists(GLuint i) const;
        
        GLboolean   continueExistingArc(GLuint index, Direction direction);
        GLboolean   joinExistingArcs(GLuint index1, Direction dir1, GLuint index2, Direction dir2);
        GLboolean   mergeExistingArcs(GLuint index1, Direction dir1, GLuint index2, Direction dir2);

        GLboolean   generateImageOfSelectedArcs(GLuint index1, GLuint index2);
        GLboolean   renderSelectedArc(GLuint index, GLuint order, GLenum renderMode = GL_POINTS);
        GLboolean   renderAllArcs(GLuint order, GLenum renderMode = GL_POINTS);
        void        renderAllArcsScale();

        DCoordinate3    getSelectedCP(GLuint arcIndex, GLuint cpIndex) const;
        void            setSelectedCP(GLuint index);
        GLdouble        getAlpha() const;
        void            setAlpha(GLdouble alpha);
        void            setAlphaOfArcs();
        GLdouble        getScale() const;
        void            setScale(GLdouble scale);
        GLuint          getDivPointCount() const;
        void            setDivPointCount(GLuint divPointCount);

        GLuint          getArcCount() const;

        void            setSelectedArc(GLuint index);
        void            setAlphaAndRenderArcs(double alpha, GLenum usageFlag = GL_STATIC_DRAW);
        void            renderArcsWithModifiedDivPointCount(GLenum usageFlag = GL_STATIC_DRAW);
        void            modifyArcPosition(GLuint index, GLuint cpIndex, double x, double y, double z, GLenum usageFlag = GL_STATIC_DRAW);
        void            initializeDefaultPoints();


    private:
        static std::vector<DCoordinate3>     _default_line_points;
        static std::vector<DCoordinate3>     _default_arc_points;

    protected:
        GLuint          _arc_count = 0;
        GLuint          _arc_div_point_count = 10;
        GLuint          _arc_max_derivative_order = 2;
        GLdouble        _arc_scale = 1.0;
        GLdouble        _alpha = 1.0;
        
        vector<ArcAttributes>   _attributes;
        GLuint                  _selected_arc_index = 0;
        GLuint                  _selected_cp = 0;
    };
}

#endif // SECONDORDERTRIGONOMETRICCOMPOSITECURVE3_H
