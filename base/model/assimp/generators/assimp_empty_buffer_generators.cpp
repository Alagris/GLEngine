#include "assimp_empty_buffer_generators.h"
#include "model_buffer_generators.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
namespace gle {




    namespace index {
        const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//            std::unique_ptr<GLuint[]> bufPtr(new GLuint[size]);
//            copy(mesh,3,bufPtr.get());
            return ::gle::generateEmptyEBO_glb(convertIndexElementsNumberToBytesNumber(size),usage,bufferID);
        }
//        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const ElementBufferObject&targetEBO,const unsigned int meshIndex) {
//            return generateEBO_glb(mesh,usage,bufferID,targetEBO.getElementArraySizeInElements(meshIndex));
//        }
        const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
            return generateEmptyEBO_glb(mesh,usage,bufferID,convertIndicesNumberToElementsNumber(countInMesh(mesh)));
        }
    }


    namespace vertex {

        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//            copy(mesh,bufPtr.get());
            return ::gle::generateEmptyVBO_glb(convertVboElementsNumberToBytesNumber(size),usage,bufferID);
        }
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO) {
//            return generateVBO_glb(mesh, usage, bufferID,targetVBO.getVertexArraySizeInElements());
//        }
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
            return generateEmptyVBO_glb(mesh,usage,bufferID,convertVerticesNumberToElementsNumber(countInMesh(mesh)));
        }
    }


    namespace color {
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//            copy(mesh,colorSetIndex,bufPtr.get());
            return ::gle::generateEmptyVBO_glb(convertVboElementsNumberToBytesNumber(size),usage,bufferID);
        }
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO) {
//            return generateVBO_glb( mesh, colorSetIndex, usage, bufferID,targetVBO.getColorArraySizeInElements()) ;
//        }
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID) {
            return generateEmptyVBO_glb(mesh,colorSetIndex,usage,bufferID,convertColorVerticesNumberToElementsNumber(countInMesh(mesh)));
        }
    }

    namespace normal {
    }


    namespace texture {
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const unsigned int size) {
//            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//            copy(mesh,textureSetIndex,bufPtr.get());
            return ::gle::generateEmptyVBO_glb(convertVboElementsNumberToBytesNumber(size),usage,bufferID);
        }

//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO) {
//            return generateVBO_glb(mesh,textureSetIndex,usage,bufferID,targetVBO.getTextureArraySizeInElements(textureSetIndex));
//        }
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
            return generateEmptyVBO_glb(mesh,textureSetIndex,usage,bufferID,convertTextureVerticesNumberToElementsNumber(countInMesh(mesh),getDimentionality(mesh,textureSetIndex)));
        }
    }




//
//    const GLuint generateTexturesEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID){
//        if(mesh->mNumUVComponents[textureSetIndex]==1)return generateTexturesEmpty1DVBO_glb(mesh,textureSetIndex,usage,bufferID);
//        if(mesh->mNumUVComponents[textureSetIndex]==2)return generateTexturesEmpty2DVBO_glb(mesh,textureSetIndex,usage,bufferID);
//        if(mesh->mNumUVComponents[textureSetIndex]==3)return generateTexturesEmpty3DVBO_glb(mesh,textureSetIndex,usage,bufferID);
//        return bufferID;
//    }
//
//    const GLuint generateTexturesEmpty1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        const unsigned int size=countTextureVerticesInMesh(mesh);
//        return generateEmptyVBO_glb(convertTexture1DVerticesNumberToBytesNumber(size),usage,bufferID);
//    }
//
//    const GLuint generateTexturesEmpty2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        const unsigned int size=countTextureVerticesInMesh(mesh);
//        return generateEmptyVBO_glb(convertTexture2DVerticesNumberToBytesNumber(size),usage,bufferID);
//    }
//
//    const GLuint generateTexturesEmpty3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
//        const unsigned int size=countTextureVerticesInMesh(mesh);
//        return generateEmptyVBO_glb(convertTexture3DVerticesNumberToBytesNumber(size),usage,bufferID);
//    }
//
//
//    const GLuint generateColorsEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID) {
//        const unsigned int size=countColorVerticesInMesh(mesh);
//        return generateEmptyVBO_glb(convertColorVerticesNumberToBytesNumber(size),usage,bufferID);
//    }
//
//    const GLuint generateVerticesEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
//        const unsigned int size=countVerticesInMesh(mesh);
//        return generateEmptyVBO_glb(convertVerticesNumberToBytesNumber(size),usage,bufferID);
//    }
//
//
//    const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
//        const unsigned int size=countIndicesInMesh(mesh);
//        return generateEmptyEBO_glb(convertIndicesNumberToBytesNumber(size),usage,bufferID);
//    }
//
//
//
//
//    const GLuint generateTexturesEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage){
//        return generateTexturesEmptyVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateTexturesEmpty1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//        return generateTexturesEmpty1DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateTexturesEmpty2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//         return generateTexturesEmpty2DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateTexturesEmpty3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
//        return generateTexturesEmpty3DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
//    }
//
//
//    const GLuint generateColorsEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage) {
//         return generateColorsEmptyVBO_glb(mesh,colorSetIndex,usage,glGenBuffer());
//    }
//
//    const GLuint generateVerticesEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage) {
//         return generateVerticesEmptyVBO_glb(mesh,usage,glGenBuffer());
//    }
//
//    const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage) {
//        return generateEmptyEBO_glb(mesh,usage,glGenBuffer());
//    }

}
