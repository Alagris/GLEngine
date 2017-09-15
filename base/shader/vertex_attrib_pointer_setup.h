#ifndef VERTEX_ATTRIB_POINTER_SETUP_H
#define VERTEX_ATTRIB_POINTER_SETUP_H
#include <GLFW/glfw3.h>
namespace gle {
    struct VertexBufferObject;


    const bool findInputLocations(
        const GLuint program,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        GLint & vertexInputLoc,
        GLint & colorInputLoc,
        GLint & textureInputLoc);

    void bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const  int colorSetIndex,
        const  int textureSetIndex,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation=-1,
        const GLint textureInputLocation=-1,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);

    const bool bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const GLuint program,
        const  int colorSetIndex,
        const  int textureSetIndex,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation=nullptr,
        const GLchar *const textureInputLocation=nullptr,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);
}
#endif // VERTEX_ATTRIB_POINTER_SETUP_H
