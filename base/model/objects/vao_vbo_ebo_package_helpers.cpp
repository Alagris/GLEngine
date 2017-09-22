#include <GL/glew.h>
#include "vao_vbo_ebo_package_helpers.h"
#include "vao_vbo_ebo_package.h"
#include "element_buffer_object.h"
#include "vertex_array_object.h"
#include "vertex_array_object_helpers.h"
#include "vertex_buffer_object_helpers.h"
#include "vertex_attrib_pointer_setup.h"
#include "model_buffer_binders.h"
#include <iostream>
#include "max.h"
namespace gle {
    const unsigned int getSize(const VaoVboEboPackage & pack) {
        return pack.getEBO().getSize();
    }
    const bool isEmpty(const VaoVboEboPackage & pack) {
        return getSize(pack)>0;
    }
    const GLuint getVAO_ID(const VaoVboEboPackage & pack) {
        return pack.getVAO().getVAO();
    }
    const bool hasVAO_ID(const VaoVboEboPackage & pack) {
        return getVAO_ID(pack)!=0;
    }
    const GLuint getVBO_ID(const VaoVboEboPackage & pack) {
        return pack.getVAO().getVBO();
    }
    const bool hasVBO_ID(const VaoVboEboPackage & pack) {
        return getVBO_ID(pack)!=0;
    }
    const GLuint getEBO_ID(const VaoVboEboPackage & pack) {
        return pack.getVAO().getEBO();
    }
    const bool hasEBO_ID(const VaoVboEboPackage & pack) {
        return getEBO_ID(pack)!=0;
    }
    const bool isValid(const VaoVboEboPackage & pack) {
        if(pack.getEBO().getSize()!=pack.getVBOsNumber())return false;
        return true;
    }
    const GLsizei * const getEBOArraySizesPtr(const VaoVboEboPackage & pack) {
        return pack.getEBO().getEBOArraySizesPtr();
    }
    const GLenum getEBOType(const VaoVboEboPackage & pack) {
        return pack.getEBO().getType();
    }
    const ebo_offset * const getEBOArrayOffsetsPtr(const VaoVboEboPackage & pack) {
        return pack.getEBO().getEBOArrayOffsetsPtr();
    }
    void bindVAO(const VaoVboEboPackage & pack) {
        bindVAO(pack.getVAO());
    }
    void bindVBO(const VaoVboEboPackage & pack) {
        bindVBO(pack.getVAO());
    }
    void bindEBO(const VaoVboEboPackage & pack) {
        bindEBO(pack.getVAO());
    }
    const GLsizei getElementArraySizeInElements(const VaoVboEboPackage & pack,unsigned int index) {
        return pack.getEBO().getElementArraySizeInElements(index);
    }
    const ebo_offset getElementArrayOffsetInBytes(const VaoVboEboPackage & pack,unsigned int index) {
        return pack.getEBO().getElementArrayOffsetInBytes(index);
    }
    void renderAllEBO(const VaoVboEboPackage & pack,const GLenum mode) {
        if(hasVAO_ID(pack)&&!isEmpty(pack)) {
            bindVAO(pack);
            glMultiDrawElements(mode,getEBOArraySizesPtr(pack),getEBOType(pack),(void**)getEBOArrayOffsetsPtr(pack),getSize(pack));
            unbindVAO();
        }
    }
    void renderEBO(const VaoVboEboPackage & pack,const GLenum mode,unsigned int index) {
        if(index<getSize(pack)) {
            bindVAO(pack);
            glDrawElements(mode,getElementArraySizeInElements(pack,index),getEBOType(pack),(void*)getElementArrayOffsetInBytes(pack,index));
            unbindVAO();
        }
    }

    bool debugVboTextureDimentionality(const VaoVboEboPackage &pack){
        for(unsigned int i=0;i<pack.getVBOsNumber();i++){
            int invalidIndex=validateDimentionality(getVBO(pack,i));
            if(invalidIndex>-1){
                std::cout<<"Invalid VBO (index="<< i<<") texture (index="<< invalidIndex<<") dimentionality!";
            }
        }
    }
    const VertexBufferObject & getVBO(const VaoVboEboPackage & pack,unsigned int index){
        return *pack.getVBO(index).get();
    }

    const vbo_offset getEndingOffsetOfAllVBOs(const VaoVboEboPackage &pack) {
        return getVBOEndingOffset(*pack.getVBO(pack.getVBOsNumber()-1).get());
    }

    const GLsizei getLargestSubArraySizeOfAllVBOsInElements(const VaoVboEboPackage &pack) {
        GLsizei max=0;
        for(unsigned int i=0; i<pack.getVBOsNumber(); i++) {
            compareMax<GLsizei>(getVBOLargestSubArraySizeInElements(*pack.getVBO(i).get()),max);
        }
        return max;
    }
}
