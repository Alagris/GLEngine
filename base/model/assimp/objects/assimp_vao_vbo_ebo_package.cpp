#include "assimp_vao_vbo_ebo_package.h"
#include "vertex_array_object.h"
#include "vertex_buffer_object.h"
#include "assimp_element_buffer_object.h"
#include "assimp_vertex_buffer_object.h"
#include "vertex_array_object_helpers.h"

namespace gle {
    AssimpVaoVboEboPackage::AssimpVaoVboEboPackage(const aiMesh * const mesh,const GLenum eboType,const bool deleteAutomatically):
        VaoVboEboPackage(eboType,deleteAutomatically),
        m_mesh(mesh)
    {
    }

    void AssimpVaoVboEboPackage::generate(const GLenum usage) {
        if(m_mesh && !m_hasBeenGenerated) {
            //generating vao
            VertexArrayObject & vao=getVAORef();
            vao.generate();
            //generating ebo
            AssimpElementBufferObject ebo=AssimpElementBufferObject(m_mesh);
            ebo.generate(vao.getEBO(),usage);
            setEBO(ebo);
            //generating VBO
            AssimpVertexBufferObject vbo(m_mesh);
            vbo.generate(vao.getVBO(),usage);
            addVBO(vbo);

            //binding everything together
            bindVAOTogether(vao);

            m_hasBeenGenerated=true;
        }
    }

}
