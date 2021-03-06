#include "assimp_buffer_generators.h"
#include "model_buffer_generators.h"
#include "assimp_copy_data.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
#include "assimp_helpers.h"
#include <memory>
#include "vertex_buffer_object.h"
#include "element_buffer_object.h"




namespace gle {



//    const GLuint generateTextures1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//        copyTexture1DVertices(mesh,textureSetIndex,bufPtr.get());
//        return generateVBO_glb(convertTexture1DElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
//    }
//
//    const GLuint generateTextures2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//        copyTexture2DVertices(mesh,textureSetIndex,bufPtr.get());
//        return generateVBO_glb(convertTexture2DElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
//    }
//
//    const GLuint generateTextures3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//        copyTexture3DVertices(mesh,textureSetIndex,bufPtr.get());
//        return generateVBO_glb(convertTexture3DElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
//    }
//
//    const GLuint generateTexturesVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//        if(mesh->mNumUVComponents[textureSetIndex]==1)return generateTextures1DVBO_glb(mesh,textureSetIndex,usage,bufferID,size);
//        if(mesh->mNumUVComponents[textureSetIndex]==2)return generateTextures2DVBO_glb(mesh,textureSetIndex,usage,bufferID,size);
//        if(mesh->mNumUVComponents[textureSetIndex]==3)return generateTextures3DVBO_glb(mesh,textureSetIndex,usage,bufferID,size);
//        return bufferID;
//    }











    namespace index {
        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const unsigned int size) {
            std::unique_ptr<GLuint[]> bufPtr(new GLuint[size]);
            copy(mesh,3,bufPtr.get());
            return ::gle::generateEBO_glb(convertIndexElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
        }
        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const ElementBufferObject&targetEBO,const unsigned int meshIndex) {
            return generateEBO_glb(mesh,usage,bufferID,targetEBO.getElementArraySizeInElements(meshIndex));
        }
        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
            return generateEBO_glb(mesh,usage,bufferID,convertIndicesNumberToElementsNumber(countInMesh(mesh)));
        }
    }


    namespace vertex {

        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const unsigned int size) {
            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
            copy(mesh,bufPtr.get());
            return ::gle::generateVBO_glb(convertVboElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
        }
        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO) {
            return generateVBO_glb(mesh, usage, bufferID,targetVBO.getVertexArraySizeInElements());
        }
        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
            return generateVBO_glb(mesh,usage,bufferID,convertVerticesNumberToElementsNumber(countInMesh(mesh)));
        }
    }


    namespace color {
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
            copy(mesh,colorSetIndex,bufPtr.get());
            return ::gle::generateVBO_glb(convertVboElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
        }
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO) {
            return generateVBO_glb( mesh, colorSetIndex, usage, bufferID,targetVBO.getColorArraySizeInElements()) ;
        }
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID) {
            return generateVBO_glb(mesh,colorSetIndex,usage,bufferID,convertColorVerticesNumberToElementsNumber(countInMesh(mesh)));
        }
    }

    namespace normal {
    }


    namespace texture {
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
            copy(mesh,textureSetIndex,bufPtr.get());
            return ::gle::generateVBO_glb(convertVboElementsNumberToBytesNumber(size),bufPtr.get(),usage,bufferID);
        }

        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO) {
            return generateVBO_glb(mesh,textureSetIndex,usage,bufferID,targetVBO.getTextureArraySizeInElements(textureSetIndex));
        }
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
            return generateVBO_glb(mesh,textureSetIndex,usage,bufferID,convertTextureVerticesNumberToElementsNumber(countInMesh(mesh),getDimentionality(mesh,textureSetIndex)));
        }
    }




















//    const GLuint generateTexturesVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        if(mesh->mNumUVComponents[textureSetIndex]==1)return generateTextures1DVBO_glb(mesh,textureSetIndex,usage,bufferID);
//        if(mesh->mNumUVComponents[textureSetIndex]==2)return generateTextures2DVBO_glb(mesh,textureSetIndex,usage,bufferID);
//        if(mesh->mNumUVComponents[textureSetIndex]==3)return generateTextures3DVBO_glb(mesh,textureSetIndex,usage,bufferID);
//        return bufferID;
//    }

//    const GLuint generateTextures1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        return generateTextures1DVBO_glb(mesh, textureSetIndex, usage, bufferID,convertTexture1DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh))) ;
//    }
//
//    const GLuint generateTextures2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        return generateTextures2DVBO_glb(mesh, textureSetIndex, usage, bufferID,convertTexture2DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh)));
//    }
//
//    const GLuint generateTextures3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        return generateTextures3DVBO_glb( mesh, textureSetIndex, usage, bufferID,convertTexture3DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh)));
//    }













//    const GLuint generateTexturesVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//        return generateTexturesVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateTextures1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//        return generateTextures1DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateTextures2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//        return generateTextures2DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateTextures3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//        return generateTextures3DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//
//    const GLuint generateColorsVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage) {
//        return generateColorsVBO_glb(mesh,colorSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateVerticesVBO_glb(const aiMesh*const mesh,const GLenum usage) {
//        return generateVerticesVBO_glb(mesh,usage,glGenBuffer());
//    }
//
//    const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage) {
//        return generateEBO_glb(mesh,usage,glGenBuffer());
//    }
//
//
//
//
//
//
//
//
//
//
//    const GLuint generateTexturesVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const VertexBufferObject&targetVBO) {
//        return generateTexturesVBO_glb(mesh,textureSetIndex,usage,glGenBuffer(),targetVBO);
//    }
//
//    const GLuint generateTextures1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const VertexBufferObject&targetVBO) {
//        return generateTextures1DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer(),targetVBO);
//    }
//
//    const GLuint generateTextures2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const VertexBufferObject&targetVBO) {
//        return generateTextures2DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer(),targetVBO);
//    }
//
//    const GLuint generateTextures3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const VertexBufferObject&targetVBO) {
//        return generateTextures3DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer(),targetVBO);
//    }


//    const GLuint generateColorsVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const VertexBufferObject&targetVBO) {
//        return generateColorsVBO_glb(mesh,colorSetIndex,usage,glGenBuffer(),targetVBO);
//    }
//
//    const GLuint generateVerticesVBO_glb(const aiMesh*const mesh,const GLenum usage,const VertexBufferObject&targetVBO) {
//        return generateVerticesVBO_glb(mesh,usage,glGenBuffer(),targetVBO);
//    }
//
//    const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const ElementBufferObject&targetEBO,const unsigned int meshIndex) {
//        return generateEBO_glb(mesh,usage,glGenBuffer(),targetEBO,meshIndex);
//    }

}
