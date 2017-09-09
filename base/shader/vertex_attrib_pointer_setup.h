#ifndef VERTEX_ATTRIB_POINTER_SETUP_H
#define VERTEX_ATTRIB_POINTER_SETUP_H
#include <GLFW/glfw3.h>
namespace gle {
    struct VertexBufferObject;

    void bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation,
        const GLint textureInputLocation,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);

    bool bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const GLuint program,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);
}
#endif // VERTEX_ATTRIB_POINTER_SETUP_H
