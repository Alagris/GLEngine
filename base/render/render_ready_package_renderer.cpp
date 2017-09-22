#include <GL/glew.h>
#include "render_ready_package_helpers.h"
#include "render_ready_package_renderer.h"
#include "render_ready_package.h"
#include "vao_vbo_ebo_package_helpers.h"
#include "model_buffer_binders.h"
#include "model_node.h"
#include "matrix_computations.h"
#include "render_ready_root_node.h"
#include "shader_lighting_uniforms.h"
#include "shader_lighting_data.h"
#include "shader_lighting_helpers.h"



namespace gle {
    void renderEBO(const RenderReadyPackage &pack,const GLenum mode,unsigned int index) {
        if(index<getSize(pack.getData())) {
            const GLsizei count=getElementArraySizeInElements(pack.getData(),index);
            if(count>0) {
                bindVAO(pack.getData());
                bindVertexAttribPointersNoLighting(pack,index);
                glDrawElements(mode,count,getEBOType(pack.getData()),(void*)getElementArrayOffsetInBytes(pack.getData(),index));
                unbindVAO();
            }
        }
    }

    namespace {
        void renderEBO_internal(const RenderReadyPackage &pack,const GLenum mode,unsigned int eboIndex) {
            const GLsizei count=getElementArraySizeInElements(pack.getData(),eboIndex);
            if(count>0) {
                bindVertexAttribPointersNoLighting(pack,eboIndex);
                glDrawElements(mode,count,getEBOType(pack.getData()),(void*)getElementArrayOffsetInBytes(pack.getData(),eboIndex));
            }
        }
    }

    void renderAllEBO(const RenderReadyPackage &pack,const GLenum mode) {
        bindVAO(pack.getData());
        for(unsigned int i=0; i<getSize(pack.getData()); i++) {
            renderEBO_internal(pack,mode,i);
        }
        unbindVAO();
    }

    namespace {
        void renderEBO_internal(const RenderReadyPackage &pack,const GLenum mode,unsigned int eboIndex,const Mat4 mvpMatrix) {
            const GLsizei count=getElementArraySizeInElements(pack.getData(),eboIndex);
            if(count>0) {
                bindVertexAttribPointers(pack,eboIndex,0);
                glUniformMatrix4fv(pack.getShaderModelViewProjectionMatrixLocation(), 1, GL_TRUE, mvpMatrix);
                glDrawElements(mode,count,getEBOType(pack.getData()),(void*)getElementArrayOffsetInBytes(pack.getData(),eboIndex));
            }
        }

        void renderNode(const RenderReadyPackage &pack,const GLenum mode,const ModelNode &node,const Mat4 mvpMatrix) {
            for(unsigned int i=0; i<node.getVboIndexArraySize(); i++) {
                renderEBO_internal(pack,mode,node.getVboIndex(i),mvpMatrix);
            }
        }

        void renderNodeRecursive(const RenderReadyPackage &pack,const GLenum mode,const ModelNode &node,const Mat4 parentModelViewProjectionMatrix) {
            Mat4 mvpMatrix;
            multiplyMat4ByMat4(parentModelViewProjectionMatrix,node.getModelMatrix().getModelMatrix(),mvpMatrix);
            renderNode(pack,mode,node,mvpMatrix);
            for(unsigned int i=0; i<node.getChildrenCount(); i++) {
                renderNodeRecursive(pack,mode,*node.getChild(i).get(),mvpMatrix);
            }
        }
    }

    void renderAllNodes(const RenderReadyPackage &pack,const GLenum mode,const Mat4 viewProjectionMatrix,const unsigned int rootNodeIndex) {

        bindVAO(pack.getData());
        const RenderReadyRootNode rrrn=pack.getRootNode(rootNodeIndex);
        bind(rrrn.getLightingData(),pack.getLighting());
        const ModelNode &root= *rrrn.get().get();
        //the first parentModelViewProjectionMatrix is in fact just viewProjectionMatrix
        renderNodeRecursive(pack,mode,root,viewProjectionMatrix);
        unbindVAO();
    }
}
