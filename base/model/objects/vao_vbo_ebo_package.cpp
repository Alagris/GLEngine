#include <GL/glew.h>
#include "vao_vbo_ebo_package.h"
#include "vertex_array_object.h"
#include "vertex_buffer_object.h"
#include "element_buffer_object.h"
#include <vector>
namespace gle {

    struct VaoVboEboPackage::Pimpl {
        Pimpl(const GLenum eboType,const bool deleteAutomatically):m_vao(deleteAutomatically),m_ebo(eboType) {}
        Pimpl(const VertexArrayObject  & vao,const std::shared_ptr<VertexBufferObject>  &vbo,const ElementBufferObject & ebo):
            m_vao(vao),m_ebo(ebo),m_vbos( {
            vbo
        }) {}
        Pimpl(const VertexArrayObject  & vao,const ElementBufferObject & ebo,const unsigned int vboCount=0):m_vao(vao),m_ebo(ebo) {
            if(vboCount!=0)m_vbos.reserve(vboCount);
        }
        VertexArrayObject m_vao;
        ElementBufferObject m_ebo;
        std::vector<std::shared_ptr<VertexBufferObject> > m_vbos;
    };

    VaoVboEboPackage::VaoVboEboPackage(const GLenum eboType,const bool deleteAutomatically):pimpl(new Pimpl(eboType,deleteAutomatically)) {}

    VaoVboEboPackage::VaoVboEboPackage(const VertexArrayObject  & vao,const std::shared_ptr<VertexBufferObject>  &vbo,const ElementBufferObject & ebo):pimpl(new Pimpl(vao,vbo,ebo)) {}

    VaoVboEboPackage::VaoVboEboPackage(const VertexArrayObject  & vao,const ElementBufferObject & ebo,const unsigned int vboCount):pimpl(new Pimpl(vao,ebo,vboCount)) {}

    const VertexArrayObject & VaoVboEboPackage::getVAO()const {
        return pimpl.get()->m_vao;
    }
    const std::shared_ptr<VertexBufferObject> & VaoVboEboPackage::getVBO(const unsigned int index)const {
        return pimpl.get()->m_vbos[index];
    }
    const ElementBufferObject & VaoVboEboPackage::getEBO()const {
        return pimpl.get()->m_ebo;
    }
    const unsigned int VaoVboEboPackage::getVBOsNumber()const {
        return pimpl.get()->m_vbos.size();
    }
    void VaoVboEboPackage::setVAO(const VertexArrayObject &vao) {
        pimpl.get()->m_vao=vao;
    }
    void VaoVboEboPackage::setVBO(const std::shared_ptr<VertexBufferObject> & vbo,const unsigned int index) {
        pimpl.get()->m_vbos[index]=vbo;
    }
    void VaoVboEboPackage::setEBO(const ElementBufferObject &ebo) {
        pimpl.get()->m_ebo=ebo;
    }
    void VaoVboEboPackage::addVBO(const std::shared_ptr<VertexBufferObject> & vbo) {
        pimpl.get()->m_vbos.push_back(vbo);
    }
    void VaoVboEboPackage::reserveVBOsCapacity(const unsigned int capacity){
        pimpl.get()->m_vbos.reserve(capacity);
    }
    std::shared_ptr<VertexBufferObject> &  VaoVboEboPackage::getVBORef (const unsigned int index) {
        return pimpl.get()->m_vbos[index];
    }
    ElementBufferObject & VaoVboEboPackage::getEBORef() {
        return pimpl.get()->m_ebo;
    }
    VertexArrayObject  &  VaoVboEboPackage::getVAORef() {
        return pimpl.get()->m_vao;
    }
    std::shared_ptr<VertexBufferObject>  * const VaoVboEboPackage::getVBOPtr(){
        return &(pimpl.get()->m_vbos[0]);
    }
    const std::shared_ptr<VertexBufferObject>  * const VaoVboEboPackage::getVBOPtr()const{
        return &(pimpl.get()->m_vbos[0]);
    }

}
