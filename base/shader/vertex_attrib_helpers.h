#ifndef VERTEX_ATTRIB_HELPERS_H
#define VERTEX_ATTRIB_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle{
    template<GLint size,typename T>
    void glVertexAttrib(const GLuint index,const T x,const T y, const T z, const T w);

    template<>
    void glVertexAttrib<1,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w);

    template<>
    void glVertexAttrib<2,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w);

    template<>
    void glVertexAttrib<3,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w);

    template<>
    void glVertexAttrib<4,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w);

    template<>
    void glVertexAttrib<1,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w);

    template<>
    void glVertexAttrib<2,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w);

    template<>
    void glVertexAttrib<3,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w);

    template<>
    void glVertexAttrib<4,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w);

    template<>
    void glVertexAttrib<1,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w);

    template<>
    void glVertexAttrib<2,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w);

    template<>
    void glVertexAttrib<3,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w);

    template<>
    void glVertexAttrib<4,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w);
}
#endif // VERTEX_ATTRIB_HELPERS_H
