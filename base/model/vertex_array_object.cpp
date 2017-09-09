#include <GL/glew.h>
#include "vertex_array_object.h"
#include "vertex_buffer_object.h"
#include "element_buffer_object.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
#include <iostream>
#include "vertex_buffer_object_helpers.h"
namespace gle {

    ////////////////////////
    //Pimpl
    ////////////////////////

    class VertexArrayObject::Pimpl {
      public:

        Pimpl():
            m_vao(0),
            m_vbo(0),
            m_ebo(0),
            m_vboList(),
            m_eboType(GL_UNSIGNED_INT) {}
        GLuint m_vao;
        GLuint m_vbo;
        GLuint m_ebo;
        std::vector<VertexBufferObject> m_vboList;
        GLenum m_eboType;
        /**size in number of array elements*/
        std::vector<GLsizei> m_eboArraySizes;
        /**offset in bytes*/
        std::vector< ebo_offset> m_eboArrayOffsets;
        void push_back(const aiMesh * const mesh);
        void reserve(const size_t size);
        inline  ebo_offset * getEBOArrayOffsetsPtr() {
            return &(m_eboArrayOffsets[0]);
        }
        inline GLsizei* getEBOArraySizesPtr() {
            return &(m_eboArraySizes[0]);
        }
        inline const unsigned int size() const {
            return m_vboList.size();
        }
      private:
        void addEBO(const aiMesh * const mesh);
        const ebo_offset calculateNextEBOOffset()const;
        const vbo_offset calculateNextVBOOffset()const;
    };
    const ebo_offset VertexArrayObject::Pimpl::calculateNextEBOOffset()const {
        if(m_eboArrayOffsets.empty())return 0;
        return m_eboArrayOffsets.back()+ convertIndexElementsNumberToBytesNumber(m_eboArraySizes.back());
    }
    const vbo_offset VertexArrayObject::Pimpl::calculateNextVBOOffset()const {
        if(m_vboList.empty())return 0;
        return m_vboList.back().vertexArrayOffset+ countVBOTotalSize(m_vboList.back());
    }
    void VertexArrayObject::Pimpl::addEBO(const aiMesh * const mesh) {
        m_eboArraySizes.push_back(convertIndicesNumberToElementsNumber(countIndicesInMesh(mesh)));
        m_eboArrayOffsets.push_back(calculateNextEBOOffset());
    }
    void VertexArrayObject::Pimpl::reserve(const size_t size) {
        m_vboList.reserve(size);
        m_eboArraySizes.reserve(size);
        m_eboArrayOffsets.reserve(size);
    }
    void VertexArrayObject::Pimpl::push_back(const aiMesh * const mesh) {
        m_vboList.push_back(VertexBufferObject(mesh,calculateNextVBOOffset()));
        addEBO(mesh);
    }

    ////////////////////////
    //VertexArrayObject
    ////////////////////////

    VertexArrayObject::VertexArrayObject():pimpl(new Pimpl()) {}

    VertexArrayObject::VertexArrayObject(const aiMesh * const mesh):pimpl(new Pimpl()) {
        if(mesh->mNumVertices!=0) {
            generateID();
            push_back(mesh);
        }
    }
    VertexArrayObject::VertexArrayObject(const aiMesh * const * const meshes,const unsigned int meshesNum):pimpl(new Pimpl()) {
        pimpl->reserve(meshesNum);
        for(unsigned int i=0; i<meshesNum; i++) {
            if(meshes[i]->mNumVertices==0) {
                std::cerr<<"Empty mesh found! Name: "<<(meshes[i]->mName.C_Str())<<"\n";
            } else {
                push_back(meshes[i]);
            }
        }
        if(!empty())generateID();
    }
    VertexArrayObject::VertexArrayObject(const aiScene* const scene):VertexArrayObject(scene->mMeshes,scene->mNumMeshes) {}
    VertexArrayObject:: ~VertexArrayObject() {
    }

    const GLuint VertexArrayObject::getVAO()const {
        return pimpl->m_vao;
    }
    const GLuint VertexArrayObject::getVBO()const {
        return pimpl->m_vbo;
    }
    const GLuint VertexArrayObject::getEBO()const {
        return pimpl->m_ebo;
    }
    const unsigned int VertexArrayObject::size() const {
        return pimpl->size();
    }
    const VertexBufferObject & VertexArrayObject::getVBO(unsigned int index)const {
        return pimpl->m_vboList.at(index);
    }
    const GLsizei VertexArrayObject::getEBOArraySize(unsigned int index)const {
        return pimpl->m_eboArraySizes.at(index);
    }
    const ebo_offset VertexArrayObject::getEBOArrayOffset(unsigned int index)const {
        return pimpl->m_eboArrayOffsets.at(index);
    }
    const GLenum VertexArrayObject::getEBOArrayType()const {
        return pimpl->m_eboType;
    }
    void VertexArrayObject::push_back(const aiMesh * const mesh) {
        pimpl->push_back(mesh);
    }
    void VertexArrayObject::bind() {
        if(getVAO()!=0)glBindVertexArray(getVAO());
    }
    void VertexArrayObject::bindVBO() {
        if(getVBO()!=0)glBindBuffer(GL_ARRAY_BUFFER,getVBO());
    }
    void VertexArrayObject::bindEBO() {
        if(getEBO()!=0)glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,getEBO());
    }
    void VertexArrayObject::unbind() {
        if(getVAO()==0)return;
        GLint currentVAO;
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &currentVAO);
        if(currentVAO>=0&&getVAO()==(GLuint)currentVAO)glBindVertexArray(0);
    }
    void VertexArrayObject::unbindVBO() {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
    void VertexArrayObject::unbindEBO() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    }
    void VertexArrayObject::generateID() {
        glGenVertexArrays(1,&(pimpl->m_vao));
        glGenBuffers(1,&(pimpl->m_vbo));
        glGenBuffers(1,&(pimpl->m_ebo));
    }

    void VertexArrayObject::renderAllEBO(const GLenum mode)const {
        if(getVAO()!=0) {
            glBindVertexArray(getVAO());
            glMultiDrawElements(mode,pimpl->getEBOArraySizesPtr(),getEBOArrayType(),(void**)pimpl->getEBOArrayOffsetsPtr(),size());
            glBindVertexArray(0);
        }
    }

    void VertexArrayObject::renderEBO(const GLenum mode,unsigned int index)const {
        glDrawElements(mode,getEBOArraySize(index),getEBOArrayType(),(void*)getEBOArrayOffset(index));
    }

    void VertexArrayObject::destroy() {
        std::cout<<"(VAO destroy) These were: "<<pimpl->m_vao<<" and "<< pimpl->m_vbo<<"\n";
        glDeleteBuffers(1,&(pimpl->m_vbo));
        glDeleteVertexArrays(1,&(pimpl->m_vao));
        std::cout<<"(VAO destroy) These should be both 0: "<<pimpl->m_vao<<" and "<< pimpl->m_vbo<<"\n";
    }
}
