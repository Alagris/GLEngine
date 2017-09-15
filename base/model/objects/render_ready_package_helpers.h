#ifndef RENDER_READY_PACKAGE_HELPERS_H
#define RENDER_READY_PACKAGE_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle {
    class RenderReadyPackage;

    void bindVertexAttribPointers(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);


    void setShaderVertexInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void setShaderColorInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void setShaderTextureInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void preparePackage(
        RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const int colorSetIndex,
        const int textureSetIndex);


    void renderEBO(const RenderReadyPackage &pack,const GLenum mode,unsigned int index);
    void renderAllEBO(const RenderReadyPackage &pack,const GLenum mode);
}

#endif // RENDER_READY_PACKAGE_HELPERS_H
