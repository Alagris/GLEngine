#ifndef RENDER_READY_PACKAGE_HELPERS_H
#define RENDER_READY_PACKAGE_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle {
    class RenderReadyPackage;
    class ModelBase;


    void bindVertexAttribPointers(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const unsigned int rootNodeIndex,
        const GLfloat defaultNormalX=0,
        const GLfloat defaultNormalY=1,
        const GLfloat defaultNormalZ=0);
    void bindVertexAttribPointersNoLighting(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const GLfloat defaultNormalX=0,
        const GLfloat defaultNormalY=1,
        const GLfloat defaultNormalZ=0);
    void bindVertexAttribPointerVertex(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex);
    void bindVertexAttribPointerColor(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const unsigned int rootNodeIndex);
    void bindVertexAttribPointerColorNoLighting(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex);
    void bindVertexAttribPointerTexture(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex);
    void bindVertexAttribPointerNormal(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const GLfloat defaultNormalX=0,
        const GLfloat defaultNormalY=1,
        const GLfloat defaultNormalZ=0);

    void setShaderVertexInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void setShaderColorInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void setShaderTextureInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void setShaderNormalInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void setShaderModelViewProjectionMatrixLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation);

    void preparePackage(
        RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const unsigned int rootNodeIndex,
        const int colorSetIndex,
        const int textureSetIndex);

    ModelBase & getModel(RenderReadyPackage &pack);
    const ModelBase & getModel(const RenderReadyPackage &pack);


}

#endif // RENDER_READY_PACKAGE_HELPERS_H
