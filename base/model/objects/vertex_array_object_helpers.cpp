#include <GL/glew.h>
#include "vertex_array_object_helpers.h"
#include "vertex_array_object.h"
#include "model_buffer_binders.h"
namespace gle {


    const bool hasVAO(const VertexArrayObject & vao) {
        return vao.getVAO()!=0;
    }
    const bool hasVBO(const VertexArrayObject & vao) {
        return vao.getVBO()!=0;
    }
    const bool hasEBO(const VertexArrayObject & vao) {
        return vao.getEBO()!=0;
    }

    void bindEBO(const VertexArrayObject & vao) {
        if(hasEBO(vao))bindEBO(vao.getEBO());
    }
    void bindVBO(const VertexArrayObject & vao) {
        if(hasVBO(vao))bindVBO(vao.getVBO());
    }
    void bindVAO(const VertexArrayObject & vao) {
        if(hasVAO(vao))bindVAO(vao.getVAO());
    }
    void bindVAOTogether(const VertexArrayObject & vao){
        bindVAO(vao);
        bindVBO(vao);
        bindEBO(vao);
        unbindVAO();
    }

}


