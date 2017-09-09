#include <GL/glew.h>
#include "vertex_attrib_helpers.h"
namespace gle{


    template<>
    void glVertexAttrib<1,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w){
        glVertexAttrib1f(index,x);
    }

    template<>
    void glVertexAttrib<2,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w){
        glVertexAttrib2f(index,x,y);
    }


    template<>
    void glVertexAttrib<3,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w){
        glVertexAttrib3f(index,x,y,z);
    }


    template<>
    void glVertexAttrib<4,GLfloat>(const GLuint index,const GLfloat x,const GLfloat y, const GLfloat z, const GLfloat w){
        glVertexAttrib4f(index,x,y,z,w);
    }


    template<>
    void glVertexAttrib<1,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w){
        glVertexAttrib1d(index,x);
    }


    template<>
    void glVertexAttrib<2,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w){
        glVertexAttrib2d(index,x,y);
    }


    template<>
    void glVertexAttrib<3,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w){
        glVertexAttrib3d(index,x,y,z);
    }


    template<>
    void glVertexAttrib<4,GLdouble>(const GLuint index,const GLdouble x,const GLdouble y, const GLdouble z, const GLdouble w){
        glVertexAttrib4d(index,x,y,z,w);
    }


    template<>
    void glVertexAttrib<1,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w){
        glVertexAttrib1s(index,x);
    }


    template<>
    void glVertexAttrib<2,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w){
        glVertexAttrib2s(index,x,y);
    }


    template<>
    void glVertexAttrib<3,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w){
        glVertexAttrib3s(index,x,y,z);
    }


    template<>
    void glVertexAttrib<4,GLshort>(const GLuint index,const GLshort x,const GLshort y, const GLshort z, const GLshort w){
        glVertexAttrib4s(index,x,y,z,w);
    }

}
