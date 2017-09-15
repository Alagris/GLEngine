#include <GL/glew.h>
#include "vertex_array_object.h"
#include "vertex_buffer_object.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
#include <iostream>
#include <vector>
#include "vertex_buffer_object_helpers.h"
namespace gle {

    ////////////////////////
    //Pimpl
    ////////////////////////

    class VertexArrayObject::Pimpl {
      public:
        ///////
        //constructors
        ///////
        Pimpl(const bool destroyAutomatically=true):
            m_vao(0),
            m_vbo(0),
            m_ebo(0),
//            m_eboType(GL_UNSIGNED_INT),
            m_destroyAutomatically(destroyAutomatically) {}

        ~Pimpl(){
            destroy();
        }
        ///////
        //variables
        ///////
        GLuint m_vao;
        GLuint m_vbo;
        GLuint m_ebo;
//        GLenum m_eboType;
        const bool m_destroyAutomatically;
        ///////
        //functions
        ///////
        void destroy();
    };
    void VertexArrayObject::Pimpl::destroy() {
        if(m_destroyAutomatically) {
            if(m_vbo!=0) {
                glDeleteBuffers(1,&(m_vbo));
                m_vbo=0;
            }
            if(m_ebo!=0) {
                glDeleteBuffers(1,&(m_ebo));
                m_ebo=0;
            }
            if(m_vao!=0) {
                glDeleteVertexArrays(1,&(m_vao));
                m_vao=0;
            }
        }

    }

    ////////////////////////
    //VertexArrayObject
    ////////////////////////

    ////constructors/destructors
    VertexArrayObject::VertexArrayObject(const bool destroyAutomatically):
        pimpl(new Pimpl(destroyAutomatically)){}

    ////bind
    void VertexArrayObject::bind() {
        if(getVAO()!=0)glBindVertexArray(getVAO());
    }
    void VertexArrayObject::unbind() {
        if(getVAO()==0)return;
        GLint currentVAO;
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &currentVAO);
        if(currentVAO>=0&&getVAO()==(GLuint)currentVAO)glBindVertexArray(0);
    }

    ////get
    const GLuint VertexArrayObject::getVAO()const {
        return pimpl->m_vao;
    }
    const GLuint VertexArrayObject::getVBO()const {
        return pimpl->m_vbo;
    }
    const GLuint VertexArrayObject::getEBO()const {
        return pimpl->m_ebo;
    }

    void VertexArrayObject::generate() {
        if(pimpl->m_vao==0)glGenVertexArrays(1,&(pimpl->m_vao));
        if(pimpl->m_vbo==0)glGenBuffers(1,&(pimpl->m_vbo));
        if(pimpl->m_ebo==0)glGenBuffers(1,&(pimpl->m_ebo));
    }

    void VertexArrayObject::destroy() {
       if(pimpl)pimpl->destroy();
    }
}
