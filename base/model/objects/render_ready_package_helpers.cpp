#include <GL/glew.h>
#include "render_ready_package_helpers.h"
#include "render_ready_package.h"
#include "vertex_attrib_pointer_setup.h"
#include "vao_vbo_ebo_package_helpers.h"
#include "model_buffer_binders.h"


#include <iostream>
namespace gle {

    void bindVertexAttribPointers(
        const RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA) {
        bindVertexAttribPointers(
            pack.getData().getVBO(vboIndex),
            pack.getColorSetIndexUsedByVBO(vboIndex),
            pack.getTextureSetIndexUsedByVBO(vboIndex),
            pack.getShaderVertexInputLocation(),
            pack.getShaderColorInputLocation(),
            pack.getShaderTextureInputLocation(),
            defaultColorR,defaultColorG,defaultColorB,defaultColorA);
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


    void preparePackage(
        RenderReadyPackage &pack,
        const unsigned int vboIndex,
        const int colorSetIndex,
        const int textureSetIndex
    )
    {
        pack.setColorSetIndexUsedByVBO(colorSetIndex,vboIndex);
        pack.setTextureSetIndexUsedByVBO(textureSetIndex,vboIndex);
        bindVAO(pack.getData());
        bindEBO(pack.getData());
        bindVBO(pack.getData());
        bindVertexAttribPointers(pack,vboIndex);
        unbindVAO();
    }


    void renderEBO(const RenderReadyPackage &pack,const GLenum mode,unsigned int index) {
        if(index<getSize(pack.getData())) {
            const GLsizei count=getElementArraySizeInElements(pack.getData(),index);
            if(count>0) {
                bindVAO(pack.getData());
                bindVertexAttribPointers(pack,index);
                glDrawElements(mode,count,getEBOType(pack.getData()),(void*)getElementArrayOffsetInBytes(pack.getData(),index));
                unbindVAO();
            }
        }
    }

    void renderAllEBO(const RenderReadyPackage &pack,const GLenum mode) {
        bindVAO(pack.getData());
        for(unsigned int i=0; i<getSize(pack.getData()); i++) {//2,4,6,35,36,37,66,70,89
            const GLsizei count=getElementArraySizeInElements(pack.getData(),i);
            if(count>0) {
                bindVertexAttribPointers(pack,i);
                glDrawElements(mode,count,getEBOType(pack.getData()),(void*)getElementArrayOffsetInBytes(pack.getData(),i));
            }
        }
        unbindVAO();
    }
}
