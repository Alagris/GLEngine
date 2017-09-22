#ifndef MODEL_BUFFER_GENERATORS_H
#define MODEL_BUFFER_GENERATORS_H
#include <GLFW/glfw3.h>
namespace gle {

    /////////////////////////////////////////
    //         IMPORTANT IMPORTANT         //
    /////////////////////////////////////////
    /////////////////////////////////////////
    /////////////////////////////////////////
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Every function that ends with _glb
    //chnages OpenGL state by binding something
    //and not unbinding it
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /////////////////////////////////////////
    /////////////////////////////////////////
    /////////////////////////////////////////


    /**target is one of:
    GL_ARRAY_BUFFER,GL_ELEMENT_ARRAY_BUFFER,
    GL_PIXEL_PACK_BUFFER,GL_PIXEL_UNPACK_BUFFER.

    usage must be: GL_STREAM_DRAW, GL_STREAM_READ,
    GL_STREAM_COPY, GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY,
    GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.

    returns VBO ID*/


    /**size measured in bytes*/
    const GLuint generateBuffer_glb(const GLenum target,const GLsizeiptr size,const GLvoid * data,const GLenum usage,const GLuint bufferID);
    /**size measured in bytes*/
    inline const GLuint generateEBO_glb(const GLsizeiptr size,const GLuint * const indices,const GLenum usage,const GLuint bufferID) {
         return generateBuffer_glb(GL_ELEMENT_ARRAY_BUFFER,size,indices,usage,bufferID);
    }
    /**size measured in bytes*/
    inline const GLuint generateVBO_glb(const GLsizeiptr size,const GLfloat * const vertices,const GLenum usage,const GLuint bufferID) {
         return generateBuffer_glb(GL_ARRAY_BUFFER,size,vertices,usage,bufferID);
    }
    /**size measured in bytes*/
    inline const GLuint generateEmptyEBO_glb(const GLsizeiptr size,const GLenum usage,const GLuint bufferID) {
         return generateBuffer_glb(GL_ELEMENT_ARRAY_BUFFER,size,nullptr,usage,bufferID);
    }
    /**size measured in bytes*/
    inline const GLuint generateEmptyVBO_glb(const GLsizeiptr size,const GLenum usage,const GLuint bufferID) {
         return generateBuffer_glb(GL_ARRAY_BUFFER,size,nullptr,usage,bufferID);
    }

    const GLuint glGenBuffer();
    /**size measured in bytes*/
    inline GLuint generateBuffer_glb(const GLenum target,const GLsizeiptr size,const GLvoid * data,const GLenum usage){
        return generateBuffer_glb(target,size,data,usage,glGenBuffer());
    }
    /**size measured in bytes*/
    inline const GLuint generateEBO_glb(const GLsizeiptr size,const GLuint * const indices,const GLenum usage) {
        return generateBuffer_glb(GL_ELEMENT_ARRAY_BUFFER,size,indices,usage);
    }
    /**size measured in bytes*/
    inline const GLuint generateVBO_glb(const GLsizeiptr size,const GLfloat * const vertices,const GLenum usage) {
        return generateBuffer_glb(GL_ARRAY_BUFFER,size,vertices,usage);
    }
    /**size measured in bytes*/
    inline const GLuint generateEmptyEBO_glb(const GLsizeiptr size,const GLenum usage) {
        return generateBuffer_glb(GL_ELEMENT_ARRAY_BUFFER,size,nullptr,usage);
    }
    /**size measured in bytes*/
    inline const GLuint generateEmptyVBO_glb(const GLsizeiptr size,const GLenum usage) {
        return generateBuffer_glb(GL_ARRAY_BUFFER,size,nullptr,usage);
    }


}

#endif // MODEL_BUFFER_GENERATORS_H
