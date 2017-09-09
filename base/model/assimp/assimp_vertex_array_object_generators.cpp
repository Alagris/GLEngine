#include "assimp_vertex_array_object_generators.h"
#include "vertex_array_object.h"
#include "assimp_buffer_generators.h"
#include "assimp_subbuffer_generators.h"
#include "vertex_attrib_pointer_setup.h"
namespace gle {

    VertexArrayObject generateVAO(const aiMesh*const mesh,const GLenum usage) {
        VertexArrayObject vao(mesh);
        if(!vao.empty()) {
            vao.bind();
            vao.bindEBO();
            generateEBO(mesh,usage,vao.getEBO());
            vao.bindVBO();
            const struct VertexBufferObject & vbo=vao.getVBO(0);
            generateVerticesColorsAndTexturesSubVBO(mesh,0,0,vbo,vao.getVBO());
            bindVertexAttribPointers(vbo,0,1,-1);
        }
        return vao;
    }
}
