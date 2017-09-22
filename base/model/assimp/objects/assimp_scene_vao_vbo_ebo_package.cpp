#include "assimp_scene_vao_vbo_ebo_package.h"
#include "vertex_array_object.h"
#include "assimp_scene_element_buffer_object.h"
#include "assimp_vertex_buffer_object.h"
#include "vertex_buffer_object_helpers.h"
#include "vertex_array_object_helpers.h"
#include "model_buffer_generators.h"
#include "assimp_converters.h"
#include "vao_vbo_ebo_package_helpers.h"
namespace gle {
    AssimpSceneVaoVboEboPackage::AssimpSceneVaoVboEboPackage(const aiScene * const scene,const GLenum eboType,const bool deleteAutomatically):
        VaoVboEboPackage(eboType,deleteAutomatically),
        m_scene(scene) {}



    const vbo_offset AssimpSceneVaoVboEboPackage::addVBO( const aiMesh * const mesh,const vbo_offset offset) {
        std::shared_ptr<VertexBufferObject> vbo(new AssimpVertexBufferObject(mesh,offset));
        VaoVboEboPackage::addVBO(vbo);
        return getVBOEndingOffset(*vbo.get());
    }

    void AssimpSceneVaoVboEboPackage::collectVboSizes() {
        reserveVBOsCapacity(m_scene->mNumMeshes);

        vbo_offset offset=0;
        for(unsigned int i=0; i<m_scene->mNumMeshes; i++) {
            offset=addVBO(m_scene->mMeshes[i],offset);
        }
    }

    void AssimpSceneVaoVboEboPackage::copyData(const GLenum usage,const GLuint targetVBO_ID) {
        std::unique_ptr<GLfloat[]> buffer(new GLfloat[getLargestSubArraySizeOfAllVBOsInElements(*this)]);
        for(unsigned int i=0; i<m_scene->mNumMeshes; i++) {
            const aiMesh * const mesh= m_scene->mMeshes[i];
            AssimpVertexBufferObject * vbo=static_cast<AssimpVertexBufferObject*>(VaoVboEboPackage::getVBORef(i).get());
            (*vbo).generate(targetVBO_ID,usage,buffer.get(),false);
        }
    }


    void AssimpSceneVaoVboEboPackage::generate(const GLenum usage) {
        if(m_scene && !m_hasBeenGenerated) {
            //generating vao
            VertexArrayObject & vao=getVAORef();
            vao.generate();
            //generating VBO
            collectVboSizes();
            generateEmptyVBO_glb(getEndingOffsetOfAllVBOs(*this),usage,vao.getVBO());
            copyData(usage,vao.getVBO());
//            vbo_offset offset=0;
//            unsigned int buffLength=0;
//            unsigned int totalLength=0;
//            countSumAndMaxTexColVerNorInMeshesOfSceneInElements(m_scene,buffLength,totalLength);
//            std::unique_ptr<GLfloat[]> buffer(new GLfloat[buffLength]);
//            generateEmptyVBO_glb(convertVboElementsNumberToBytesNumber(totalLength),usage,vao.getVBO());
//            for(unsigned int i=0; i<m_scene->mNumMeshes; i++) {
//                AssimpVertexBufferObject vbo(m_scene->mMeshes[i],offset);//576 0
//                vbo.generate(vao.getVBO(),usage,buffer.get(),false);
//                addVBO(vbo);
//                offset=getVBOEndingOffset(vbo);
//            }
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
