#ifndef MODEL_BUFFER_GENERATORS_H
#define MODEL_BUFFER_GENERATORS_H
#include <GL/glew.h>
namespace gle {
    /**target is one of:
    GL_ARRAY_BUFFER,GL_ELEMENT_ARRAY_BUFFER,
    GL_PIXEL_PACK_BUFFER,GL_PIXEL_UNPACK_BUFFER.

    usage must be: GL_STREAM_DRAW, GL_STREAM_READ,
    GL_STREAM_COPY, GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY,
    GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.

    returns VBO ID*/
    GLuint generateBuffer(const GLenum target,const GLsizeiptr size,const GLvoid * data,const GLenum usage);
    inline GLuint generateEBO(const GLsizeiptr size,const GLuint * const indices,const GLenum usage) {
        return generateBuffer(GL_ELEMENT_ARRAY_BUFFER,size,indices,usage);
    }
    inline GLuint generateVBO(const GLsizeiptr size,const GLfloat * const vertices,const GLenum usage) {
        return generateBuffer(GL_ARRAY_BUFFER,size,vertices,usage);
    }
}

#endif // MODEL_BUFFER_GENERATORS_H
