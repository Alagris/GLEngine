#ifndef ASSIMP_LOADER_H
#define ASSIMP_LOADER_H
#include <GLFW/glfw3.h>
namespace gle {
    class RenderReadyPackage;

    bool importModel(
        const char * pFile,
        RenderReadyPackage & output,
        const GLenum usage,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation,
        const GLint textureInputLocation,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);

    bool importModel(
        const char * pFile,
        RenderReadyPackage & output,
        const GLenum usage,
        const GLuint program,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);
}
#endif // ASSIMP_LOADER_H
