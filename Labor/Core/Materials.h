#pragma once

#include "Colors4.h"
#include <GL/glew.h>

namespace cagd
{
    class Material
    {
    protected:
        Color4	_front_ambient, _front_diffuse, _front_specular, _front_emissive;
        GLfloat	_front_shininess;

        Color4	_back_ambient, _back_diffuse, _back_specular, _back_emissive;
        GLfloat	_back_shininess;

    public:
        Material(
            const Color4& front_ambient   = Color4(),
            const Color4& front_diffuse   = Color4(),
            const Color4& front_specular  = Color4(),
            const Color4& front_emissive  = Color4(),
            GLfloat front_shininess       = 128.0f,
            const Color4& backAmbient     = Color4(),
            const Color4& back_diffuse    = Color4(),
            const Color4& back_specular   = Color4(),
            const Color4& back_emissive   = Color4(),
            GLfloat back_shininess        = 128.0f);

        GLvoid SetAmbientColor(GLenum face, const Color4& c);
        GLvoid SetAmbientColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

        // homework
        GLvoid SetDiffuseColor(GLenum face, const Color4& c);
        GLvoid SetDiffuseColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

        // homework
        GLvoid SetSpecularColor(GLenum face, const Color4& c);
        GLvoid SetSpecularColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

        // homework
        GLvoid SetEmissiveColor(GLenum face, const Color4& c);
        GLvoid SetEmissiveColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f);

        // homework
        GLvoid SetShininess(GLenum face, GLfloat shininess);

        // homework
        GLvoid SetTransparency(GLfloat alpha);

        GLvoid Apply();

        // homework
        GLboolean IsTransparent() const;
    };

    inline GLvoid Material::SetDiffuseColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
    {
        switch (face)
        {
        case GL_FRONT:
            _front_diffuse.r() = r;
            _front_diffuse.g() = g;
            _front_diffuse.b() = b;
            _front_diffuse.a() = a;
        break;

        case GL_BACK:
            _back_diffuse.r() = r;
            _back_diffuse.g() = g;
            _back_diffuse.b() = b;
            _back_diffuse.a() = a;
        break;

        case GL_FRONT_AND_BACK:
            _front_diffuse.r() = r;
            _front_diffuse.g() = g;
            _front_diffuse.b() = b;
            _front_diffuse.a() = a;

            _back_diffuse.r()  = r;
            _back_diffuse.g()  = g;
            _back_diffuse.b()  = b;
            _back_diffuse.a()  = a;
        break;
        }
    }


    inline GLvoid Material::SetSpecularColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
    {
        switch (face)
        {
        case GL_FRONT:
            _front_specular.r() = r;
            _front_specular.g() = g;
            _front_specular.b() = b;
            _front_specular.a() = a;
        break;

        case GL_BACK:
            _back_specular.r() = r;
            _back_specular.g() = g;
            _back_specular.b() = b;
            _back_specular.a() = a;
        break;

        case GL_FRONT_AND_BACK:
            _front_specular.r() = r;
            _front_specular.g() = g;
            _front_specular.b() = b;
            _front_specular.a() = a;

            _back_specular.r()  = r;
            _back_specular.g()  = g;
            _back_specular.b()  = b;
            _back_specular.a()  = a;
        break;
        }
    }

    inline GLvoid Material::SetEmissiveColor(GLenum face, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
    {
        switch (face)
        {
        case GL_FRONT:
            _front_emissive.r() = r;
            _front_emissive.g() = g;
            _front_emissive.b() = b;
            _front_emissive.a() = a;
        break;

        case GL_BACK:
            _back_emissive.r() = r;
            _back_emissive.g() = g;
            _back_emissive.b() = b;
            _back_emissive.a() = a;
        break;

        case GL_FRONT_AND_BACK:
            _front_emissive.r() = r;
            _front_emissive.g() = g;
            _front_emissive.b() = b;
            _front_emissive.a() = a;

            _back_emissive.r()  = r;
            _back_emissive.g()  = g;
            _back_emissive.b()  = b;
            _back_emissive.a()  = a;
        break;
        }
    }

    inline GLvoid Material::SetShininess(GLenum face, GLfloat shininess)
    {
        switch (face)
        {
        case GL_FRONT:
            _front_shininess = shininess;
        break;

        case GL_BACK:
            _back_shininess = shininess;
        break;

        case GL_FRONT_AND_BACK:
            _front_shininess = shininess;

            _back_shininess = shininess;
        break;
        }
    }

    inline GLvoid Material::SetTransparency(GLfloat alpha)
    {
        _front_ambient.a() = alpha;
        _front_diffuse.a() = alpha;
        _front_specular.a() = alpha;

        _back_ambient.a() = alpha;
        _back_diffuse.a() = alpha;
        _back_specular.a() = alpha;
    }

    inline GLboolean Material::IsTransparent() const
    {
        return (_front_ambient.a()  < 1 &&
                _front_diffuse.a()  < 1 &&
                _front_specular.a() < 1 &&
                _back_ambient.a()   < 1 &&
                _back_diffuse.a()   < 1 &&
                _back_specular.a()  < 1 &&
                _back_emissive.a()  < 1 &&
                _front_emissive.a()
                );
    }

    extern
    Material    MatFBBrass,
                MatFBGold,
                MatFBSilver,
                MatFBEmerald,
                MatFBPearl,
                MatFBRuby,
                MatFBTurquoise;
}
