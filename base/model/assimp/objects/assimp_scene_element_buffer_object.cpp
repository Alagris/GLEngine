#include "assimp_scene_element_buffer_object.h"
#include "assimp_elements_counters.h"
#include "assimp_subbuffer_generators.h"
#include "model_buffer_generators.h"
#include "element_buffer_object_helpers.h"
#include "model_buffer_binders.h"
#include "vertex_buffer_object.h"


namespace gle {

     const aiMesh * const getmesh(const aiScene*const scene,unsigned int i){
         unsigned int x=0;
         if(i==0)i=x;
         else if(i==x)i=0;
        return scene->mMeshes[i];
    }

    AssimpSceneElementBufferObject::AssimpSceneElementBufferObject(const aiScene*const scene,const ebo_offset elementArrayOffset,const GLenum type,const unsigned int numIndicesPerFace):
        ElementBufferObject(type),
        m_scene(scene),
        m_numIndicesPerFace(numIndicesPerFace)
    {
        reserve(scene->mNumMeshes);
        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
            const unsigned int n=countIndicesElementsInMesh(getmesh(m_scene,i),numIndicesPerFace);
            push_back(n);
        }
    }




    const GLuint AssimpSceneElementBufferObject::generate(const GLuint reservedEBO_ID,const GLenum usage)  {
        if(m_scene&& !m_hasBeenGenerated) {
            const ElementBufferObject &ebo = *this;
            std::unique_ptr<GLuint[]> bufPtr(new GLuint[getEBOLargestSubArraySizeInElements(ebo)]);
            generateEmptyEBO_glb(getTotalSizeOfEBOInBytes(ebo),usage,reservedEBO_ID);
            for(unsigned int i=0; i<m_scene->mNumMeshes; i++) {
                generateIndicesSubEBO(getmesh(m_scene,i),bufPtr.get(),i,ebo,m_numIndicesPerFace);
            }
            unbindEBO();
            m_hasBeenGenerated=true;
        }
        return reservedEBO_ID;
    }
}
