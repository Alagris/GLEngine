#ifndef MODEL_BUFFER_BINDERS_H
#define MODEL_BUFFER_BINDERS_H
#include <GLFW/glfw3.h>
namespace gle {
    void bindVAO(const GLuint vao);
    void bindBuffer(const GLenum target,const GLuint bufferID);
    inline void bindEBO(const GLuint ebo) {
        bindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    }
    inline void bindVBO(const GLuint vbo) {
        bindBuffer(GL_ARRAY_BUFFER,vbo);
    }
    inline void unbindEBO() {
        bindEBO(0);
    }
    inline void unbindVBO() {
        bindVBO(0);
    }
    inline void unbindVAO() {
        bindVAO(0);
    }
    inline void unbindBuffer(const GLenum target) {
        bindBuffer(target,0);
    }
}

#endif // MODEL_BUFFER_BINDERS_H
