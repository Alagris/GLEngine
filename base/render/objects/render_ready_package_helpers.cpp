#include <GL/glew.h>
#include "render_ready_package_helpers.h"
#include "render_ready_package.h"
#include "vertex_attrib_pointer_setup.h"
#include "vao_vbo_ebo_package.h"
#include "vao_vbo_ebo_package_helpers.h"
#include "model_buffer_binders.h"
#include "model_base.h"
#include "model_node.h"
#include "render_ready_root_node.h"



namespace gle {

    void bindVertexAttribPointers(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const unsigned int rootNodeIndex,
        const GLfloat defaultNormalX,
        const GLfloat defaultNormalY,
        const GLfloat defaultNormalZ) {
        bindVertexAttribPointerVertex(pack,vboIndex);
        bindVertexAttribPointerColor(pack,vboIndex,rootNodeIndex);
        bindVertexAttribPointerTexture(pack,vboIndex);
        bindVertexAttribPointerNormal(pack,vboIndex,defaultNormalX,defaultNormalY,defaultNormalZ);
    }
    void bindVertexAttribPointersNoLighting(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const GLfloat defaultNormalX,
        const GLfloat defaultNormalY,
        const GLfloat defaultNormalZ) {
        bindVertexAttribPointerVertex(pack,vboIndex);
        bindVertexAttribPointerColorNoLighting(pack,vboIndex);
        bindVertexAttribPointerTexture(pack,vboIndex);
        bindVertexAttribPointerNormal(pack,vboIndex,defaultNormalX,defaultNormalY,defaultNormalZ);
    }


    void bindVertexAttribPointerVertex(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex) {
        bindVertexAttribPointerVertex(
            *pack.getData().getVBO(vboIndex).get(),
            pack.getShaderVertexInputLocation());
    }

    void bindVertexAttribPointerColor(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const unsigned int rootNodeIndex) {
        bindVertexAttribPointerColor(
            *pack.getData().getVBO(vboIndex).get(),
            pack.getColorSetIndexUsedByVBO(vboIndex),
            pack.getShaderColorInputLocation(),
            pack.getRootNode(rootNodeIndex).getDefaultColorR(),
            pack.getRootNode(rootNodeIndex).getDefaultColorG(),
            pack.getRootNode(rootNodeIndex).getDefaultColorB(),
            pack.getRootNode(rootNodeIndex).getDefaultColorA());
    }
    void bindVertexAttribPointerColorNoLighting(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex) {
        bindVertexAttribPointerColor(
            *pack.getData().getVBO(vboIndex).get(),
            pack.getColorSetIndexUsedByVBO(vboIndex),
            pack.getShaderColorInputLocation());
    }
    void bindVertexAttribPointerTexture(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex) {
        bindVertexAttribPointerTexture(
            *pack.getData().getVBO(vboIndex).get(),
            pack.getTextureSetIndexUsedByVBO(vboIndex),
            pack.getShaderTextureInputLocation());
    }
    void bindVertexAttribPointerNormal(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const GLfloat defaultNormalX,
        const GLfloat defaultNormalY,
        const GLfloat defaultNormalZ) {
        bindVertexAttribPointerNormal(
            *pack.getData().getVBO(vboIndex).get(),
            pack.getShaderNormalInputLocation(),
            defaultNormalX,defaultNormalY,defaultNormalZ);
    }

    void setShaderVertexInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation) {
        pack.setShaderVertexInputLocation(glGetAttribLocation(program,inputLocation));
    }

    void setShaderColorInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation) {
        pack.setShaderColorInputLocation(glGetAttribLocation(program,inputLocation));
    }

    void setShaderTextureInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation) {
        pack.setShaderTextureInputLocation(glGetAttribLocation(program,inputLocation));
    }

    void setShaderNormalInputLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation) {
        pack.setShaderNormalInputLocation(glGetAttribLocation(program,inputLocation));
    }

    void setShaderModelViewProjectionMatrixLocation( RenderReadyPackage &pack,const GLuint program,const  GLchar *const inputLocation) {
        pack.setShaderModelViewProjectionMatrixLocation(glGetUniformLocation(program,inputLocation));
    }

    void preparePackage(
        RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const unsigned int rootNodeIndex,
        const int colorSetIndex,
        const int textureSetIndex
    )
    {
        pack.setColorSetIndexUsedByVBO(colorSetIndex,vboIndex);
        pack.setTextureSetIndexUsedByVBO(textureSetIndex,vboIndex);
        bindVAO(pack.getData());
        bindEBO(pack.getData());
        bindVBO(pack.getData());
        bindVertexAttribPointers(pack,vboIndex,rootNodeIndex);
        unbindVAO();
    }


    ModelBase & getModel(RenderReadyPackage &pack,const unsigned int rootNodeIndex) {
        return pack.getRootNode(rootNodeIndex).get()->getModelMatrix();
    }
    const ModelBase & getModel(const RenderReadyPackage &pack,const unsigned int rootNodeIndex) {
        return pack.getRootNode(rootNodeIndex).get()->getModelMatrix();
    }



}
