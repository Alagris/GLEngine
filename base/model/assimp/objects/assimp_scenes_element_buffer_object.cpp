#include "assimp_scenes_element_buffer_object.h"
#include "assimp_elements_counters.h"
#include "assimp_subbuffer_generators.h"
#include "model_buffer_generators.h"
#include "element_buffer_object_helpers.h"
#include "model_buffer_binders.h"
#include "vertex_buffer_object.h"
#include "assimp_counters.h"

namespace gle {


    AssimpScenesElementBufferObject::AssimpScenesElementBufferObject(
        const aiScene *const* const scenes,
        const unsigned int scenesCount,
        const ebo_offset elementArrayOffset,
        const GLenum type,
        const unsigned int numIndicesPerFace)
        :
        ElementBufferObject(type),
        m_scenes(scenes),
        m_scenesCount(scenesCount),
        m_numIndicesPerFace(numIndicesPerFace)
    {
        reserve(countMeshesInScenes(scenes,scenesCount));
        for(unsigned int k=0; k<scenesCount; k++) {
            for(unsigned int i=0; i<scenes[k]->mNumMeshes; i++) {
                const unsigned int n=index::countElementsInMesh(scenes[k]->mMeshes[i],numIndicesPerFace);
                push_back(n);
            }
        }
    }




    const GLuint AssimpScenesElementBufferObject::generate(const GLuint reservedEBO_ID,const GLenum usage)  {
        if(m_scenes&& !m_hasBeenGenerated) {
            const ElementBufferObject &ebo = *this;
            std::unique_ptr<GLuint[]> bufPtr(new GLuint[getEBOLargestSubArraySizeInElements(ebo)]);
            generateEmptyEBO_glb(getTotalSizeOfEBOInBytes(ebo),usage,reservedEBO_ID);
            for(unsigned int k=0,meshIndex=0; k<m_scenesCount; k++) {
                for(unsigned int i=0; i<m_scenes[k]->mNumMeshes; i++,meshIndex++) {
                    index::generateSubEBO(m_scenes[k]->mMeshes[i],bufPtr.get(),meshIndex,ebo,m_numIndicesPerFace);
                }
            }
            unbindEBO();
            m_hasBeenGenerated=true;
        }
        return reservedEBO_ID;
    }
}
