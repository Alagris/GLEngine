#include "assimp_scene_vao_vbo_ebo_package.h"
#include "vertex_array_object.h"
#include "assimp_scene_element_buffer_object.h"
#include "assimp_vertex_buffer_object.h"
#include "vertex_buffer_object_helpers.h"
#include "vertex_array_object_helpers.h"
#include "assimp_max_elements_counters.h"
#include "assimp_scene_empty_buffer_generators.h"


namespace gle {
    AssimpSceneVaoVboEboPackage::AssimpSceneVaoVboEboPackage(const aiScene * const scene,const GLenum eboType,const bool deleteAutomatically):
        VaoVboEboPackage(eboType,deleteAutomatically),
        m_scene(scene){}

    void AssimpSceneVaoVboEboPackage::generate(const GLenum usage) {
        if(m_scene && !m_hasBeenGenerated) {
            //generating vao
            VertexArrayObject & vao=getVAORef();
            vao.generate();
            //generating VBO
            vbo_offset offset=0;
            std::unique_ptr<GLfloat[]> buffer(new GLfloat[countMaxTexColVerInMeshesOfSceneInElements(m_scene)]);
            generateTexColVerAllSetsEmptyVBO_glb(m_scene,usage,vao.getVBO());
            for(unsigned int i=0; i<m_scene->mNumMeshes; i++) {
                AssimpVertexBufferObject vbo(m_scene->mMeshes[i],offset);//576 0
                vbo.generate(vao.getVBO(),usage,buffer.get(),false);
                addVBO(vbo);
                offset=getVBOEndingOffset(vbo);
            }
            //generating ebo
            AssimpSceneElementBufferObject ebo=AssimpSceneElementBufferObject(m_scene);
            ebo.generate(vao.getEBO(),usage);
            setEBO(ebo);
            //bindigng everything together
            bindVAOTogether(vao);
            m_hasBeenGenerated=true;
        }
    }

}
