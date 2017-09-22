#include "assimp_element_buffer_object.h"
#include "assimp_elements_counters.h"
#include "assimp_buffer_generators.h"
#include "model_buffer_binders.h"



#include <iostream>
#include "element_buffer_object_helpers.h"
#include "model_buffer_generators.h"
#include "assimp_subbuffer_generators.h"
namespace gle {
    AssimpElementBufferObject::AssimpElementBufferObject():m_mesh(nullptr) {}

    AssimpElementBufferObject::AssimpElementBufferObject(const aiMesh*const mesh,const ebo_offset elementArrayOffset,const GLenum type):
        ElementBufferObject(index::countElementsInMesh(mesh),type,elementArrayOffset),
        m_mesh(mesh) {}

    AssimpElementBufferObject::~AssimpElementBufferObject() {}

    const GLuint AssimpElementBufferObject::generate(const GLuint reservedEBO_ID,const GLenum usage)  {
        if(m_mesh&& !m_hasBeenGenerated) {
            const ElementBufferObject & ebo = *this;
            index::generateEBO_glb(m_mesh,usage,reservedEBO_ID,ebo,0);
            unbindEBO();
            m_hasBeenGenerated=true;
        }
        return reservedEBO_ID;
    }
}
