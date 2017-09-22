#ifndef VERTEX_ATTRIB_POINTER_SETUP_H
#define VERTEX_ATTRIB_POINTER_SETUP_H
#include <GLFW/glfw3.h>
#include "shader_types.h"
namespace gle {
    struct VertexBufferObject;


//    const bool findInputLocations(
//        const GLuint program,
//        const GLchar *const vertexInputLocation,
//        const GLchar *const colorInputLocation,
//        const GLchar *const textureInputLocation,
//        GLint & vertexInputLoc,
//        GLint & colorInputLoc,
//        GLint & textureInputLoc);

    void bindVertexAttribPointerVertex(
        const VertexBufferObject &vbo,
        const mandatory_shader_location vertexInputLocation) ;

    void bindVertexAttribPointerColor(
        const VertexBufferObject &vbo,
        const int colorSetIndex,
        const shader_location colorInputLocation,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);

    void bindVertexAttribPointerTexture(
        const VertexBufferObject &vbo,
        const int textureSetIndex,
        const shader_location textureInputLocation);

     void bindVertexAttribPointerNormal(
        const VertexBufferObject &vbo,
        const shader_location normalInputLocation,
        const GLfloat defaultNormalX=0,
        const GLfloat defaultNormalY=1,
        const GLfloat defaultNormalZ=0);

    void bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const int colorSetIndex,
        const int textureSetIndex,
        const mandatory_shader_location vertexInputLocation,
        const shader_location colorInputLocation=-1,
        const shader_location textureInputLocation=-1,
        const shader_location normalInputLocation=-1,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1,
        const GLfloat defaultNormalX=0,
        const GLfloat defaultNormalY=1,
        const GLfloat defaultNormalZ=0);

//    const bool bindVertexAttribPointers(
//        const VertexBufferObject &vbo,
//        const GLuint program,
//        const  int colorSetIndex,
//        const  int textureSetIndex,
//        const GLchar *const vertexInputLocation,
//        const GLchar *const colorInputLocation=nullptr,
//        const GLchar *const textureInputLocation=nullptr,
//        const GLfloat defaultColorR=0,
//        const GLfloat defaultColorG=0,
//        const GLfloat defaultColorB=0,
//        const GLfloat defaultColorA=1);
}
#endif // VERTEX_ATTRIB_POINTER_SETUP_H
