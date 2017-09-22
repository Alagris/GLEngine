#ifndef ASSIMP_LOADER_H
#define ASSIMP_LOADER_H
#include <GLFW/glfw3.h>
namespace gle {
    class RenderReadyPackage;

    const RenderReadyPackage importModel(
        const char * sourceFile,
        const GLenum usage);

    const RenderReadyPackage importModels(
        const char ** sourceFiles,
        const unsigned int filesNumber,
        const GLenum usage);

//    const RenderReadyPackage importModel(
//        const char * pFile,
//        const GLenum usage,
//        const GLuint program,
//        const GLchar *const vertexInputLocation,
//        const GLchar *const colorInputLocation,
//        const GLchar *const textureInputLocation,
//        const GLfloat defaultColorR=0,
//        const GLfloat defaultColorG=0,
//        const GLfloat defaultColorB=0,
//        const GLfloat defaultColorA=1);
}
#endif // ASSIMP_LOADER_H
