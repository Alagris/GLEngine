#ifndef MATRIX_MATH_TYPES_H_INCLUDED
#define MATRIX_MATH_TYPES_H_INCLUDED
#include <GL/glew.h>
namespace gle {
    /**it is supposted to be row major order*/
    typedef GLfloat Mat4[4*4];

    struct Vec3 {
        Vec3(const GLfloat p_x=0,const GLfloat p_y=0,const GLfloat p_z=0,const GLfloat p_w=1):x(p_x),y(p_y),z(p_z),w(p_w) {}
        Vec3(const Vec3 &  v):x(v.x),y(v.y),z(v.z),w(v.w) {}
        GLfloat x,y,z,w;
    };
}

#endif // MATRIX_MATH_TYPES_H_INCLUDED
