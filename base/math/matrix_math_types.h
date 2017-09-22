#ifndef MATRIX_MATH_TYPES_H_INCLUDED
#define MATRIX_MATH_TYPES_H_INCLUDED
#include <GLFW/glfw3.h>
namespace gle {
    /**it is supposted to be row major order*/
    typedef GLfloat Mat4[4*4];

//    class Mat4{
//        public:
//        GLfloat & operator[](unsigned int i) {
//            return data[i] ;
//        }
//        const GLfloat & operator[](unsigned int i) const {
//            return data[i] ;
//        }
//        operator GLfloat*const() {
//            return data ;
//        }
//        operator const GLfloat*const() const {
//            return data ;
//        }
//        GLfloat & x0y0=data[0],  & x1y0=data[1],  & x2y0=data[2],  & x3y0=data[3];
//        GLfloat & x0y1=data[4],  & x1y1=data[5],  & x2y1=data[6],  & x3y1=data[7];
//        GLfloat & x0y2=data[8],  & x1y2=data[9],  & x2y2=data[10], & x3y2=data[11];
//        GLfloat & x0y3=data[12], & x1y3=data[13], & x2y3=data[14], & x3y3=data[15];
//      private:
//        GLfloat data[4*4];
//
//    };

    class Vec3 {
      public:
        Vec3(const GLfloat p_x=0,const GLfloat p_y=0,const GLfloat p_z=0,const GLfloat p_w=1):m_data{p_x,p_y,p_z,p_w} {}
        Vec3(const Vec3 &  v):m_data{v.x,v.y,v.z,v.w}{}
        GLfloat & operator[](unsigned int i) {
            return m_data[i] ;
        }
        const GLfloat & operator[](unsigned int i) const {
            return m_data[i] ;
        }
        operator GLfloat*() {
            return m_data ;
        }
        operator const GLfloat*() const {
            return m_data ;
        }
        operator GLfloat*const() {
            return m_data ;
        }
        operator const GLfloat*const() const {
            return m_data ;
        }

        GLfloat*const getArray() {
            return m_data ;
        }
        const GLfloat*const getArray() const {
            return m_data ;
        }
        GLfloat &x=m_data[0];
        GLfloat &y=m_data[1];
        GLfloat &z=m_data[2];
        GLfloat &w=m_data[3];
      private:
        GLfloat m_data[4];
    };
}

#endif // MATRIX_MATH_TYPES_H_INCLUDED
