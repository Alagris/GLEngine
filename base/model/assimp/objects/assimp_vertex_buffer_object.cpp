#include "assimp_vertex_buffer_object.h"
#include "vertex_buffer_object_helpers.h"
#include "assimp_subbuffer_generators.h"
#include "model_buffer_generators.h"
#include "assimp_elements_counters.h"
#include "assimp_counters.h"
#include <memory>
#include "model_buffer_binders.h"


namespace gle {

    AssimpVertexBufferObject::AssimpVertexBufferObject(const aiMesh*const mesh,const vbo_offset initialOffset):
        VertexBufferObject(
            countVerticesElementsInMesh(mesh),
            countActiveColorSetsInMesh(mesh),
            countColorElementsInMesh(mesh),
            initialOffset,
            countActiveTextureSetsInMesh(mesh)),
        m_mesh(mesh)
    {
        for (unsigned int n=0; n < getTextureSetsNumber(); n++) {
            if(mesh->mNumUVComponents[n]==1)setHas1DTexture();
            if(mesh->mNumUVComponents[n]==2)setHas2DTexture();
            if(mesh->mNumUVComponents[n]==3)setHas3DTexture();
            setTextureArraySizeInElements(n,countTextureElementsInMesh(mesh,n));
        }
    }


    void copyData(const aiMesh*const mesh,GLfloat * const buffer,const VertexBufferObject & vbo) {
        //copy vertices data
        generateVerticesSubVBO(mesh,buffer,vbo);
        //copy color data
        for(unsigned int i=0; i<vbo.getColorSetsNumber(); i++) {
            generateColorsSubVBO(mesh,buffer,i,vbo);
        }
        //copy texture coordinates data
        for(unsigned int i=0; i<vbo.getTextureSetsNumber(); i++) {
            generateTexturesSubVBO(mesh,buffer,i,vbo);
        }
    }

    const GLuint AssimpVertexBufferObject::generate(const GLuint reservedVBO_ID,const GLenum usage,GLfloat * const buffer,const bool createNewVBO) {
        if(m_mesh && !m_hasBeenGenerated) {
            const VertexBufferObject & vbo = *this;
            //reserve memory for opengl buffer
            if(createNewVBO&&getVertexArrayOffsetInBytes()==0) {
                generateEmptyVBO_glb(getTotalSizeOfVBOInBytes(vbo),usage,reservedVBO_ID);
            }else{
                bindVBO(reservedVBO_ID);
            }
            //create temporary buffer. It's a bridge for copying data from assimp to opengl
            if(buffer) {
                copyData(m_mesh,buffer,vbo);
            } else {
                std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[getVBOLargestSubArraySizeInElements(vbo)]);
                copyData(m_mesh,bufPtr.get(),vbo);
            }
            //the end
            unbindVBO();
            m_hasBeenGenerated=true;
        }
        return reservedVBO_ID;
    }

}
