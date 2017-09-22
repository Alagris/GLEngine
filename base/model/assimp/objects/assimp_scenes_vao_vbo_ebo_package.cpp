#include "assimp_scenes_vao_vbo_ebo_package.h"
#include "vertex_array_object.h"
#include "assimp_scenes_element_buffer_object.h"
#include "assimp_vertex_buffer_object.h"
#include "vertex_buffer_object_helpers.h"
#include "vertex_array_object_helpers.h"
#include "model_buffer_generators.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
#include "vao_vbo_ebo_package_helpers.h"


namespace gle {
    AssimpScenesVaoVboEboPackage::AssimpScenesVaoVboEboPackage(
        const aiScene *const* const scenes,
        const unsigned int scenesCount,
        const GLenum eboType,
        const bool deleteAutomatically)
        :
        VaoVboEboPackage(eboType,deleteAutomatically),
        m_scenes(scenes),
        m_scenesCount(scenesCount) {}



    const vbo_offset AssimpScenesVaoVboEboPackage::addVBO( const aiMesh * const mesh,const vbo_offset offset) {
        std::shared_ptr<VertexBufferObject> vbo(new AssimpVertexBufferObject(mesh,offset));
        VaoVboEboPackage::addVBO(vbo);
        return getVBOEndingOffset(*vbo.get());
    }
    void AssimpScenesVaoVboEboPackage::collectVboSizes() {
        reserveVBOsCapacity(countMeshesInScenes(m_scenes,m_scenesCount));

        vbo_offset offset=0;
        for(unsigned int i=0; i<m_scenesCount; i++) {
            const aiScene * scene = m_scenes[i];
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                offset=addVBO(scene->mMeshes[i],offset);
            }
        }
    }


    void AssimpScenesVaoVboEboPackage::copyData(const GLenum usage,const GLuint targetVBO_ID) {
        std::unique_ptr<GLfloat[]> buffer(new GLfloat[getLargestSubArraySizeOfAllVBOsInElements(*this)]);
        for(unsigned int i=0,meshIndex=0; i<m_scenesCount; i++) {
            const aiScene * scene = m_scenes[i];
            for(unsigned int i=0; i<scene->mNumMeshes; i++,meshIndex++) {
                const aiMesh * const mesh= scene->mMeshes[i];
                AssimpVertexBufferObject * vbo=static_cast<AssimpVertexBufferObject*>(VaoVboEboPackage::getVBORef(meshIndex).get());
                (*vbo).generate(targetVBO_ID,usage,buffer.get(),false);
            }
        }
    }

    void AssimpScenesVaoVboEboPackage::generate(const GLenum usage) {
        if(m_scenes  && !m_hasBeenGenerated) {

            //generating vao
            VertexArrayObject & vao=getVAORef();
            vao.generate();
            //generating VBO
            collectVboSizes();
            generateEmptyVBO_glb(getEndingOffsetOfAllVBOs(*this),usage,vao.getVBO());
            copyData(usage,vao.getVBO());
            //generating ebo
            AssimpScenesElementBufferObject ebo=AssimpScenesElementBufferObject(m_scenes,m_scenesCount);
            ebo.generate(vao.getEBO(),usage);
            setEBO(ebo);
            //bindigng everything together
            bindVAOTogether(vao);
            m_hasBeenGenerated=true;
        }
    }

}
