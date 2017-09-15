#include "assimp_scene_buffer_generators.h"
#include "model_buffer_generators.h"
#include "assimp_subbuffer_generators.h"
#include "assimp_converters.h"
#include "assimp_max_counters.h"
#include <memory>
namespace gle {

//    const GLuint generateTexturesVBO(const aiScene*const scene,const unsigned int textureSetIndex,const GLenum usage){
//        if(mesh->mNumUVComponents[textureSetIndex]==1)return generateTextures1DVBO(mesh,textureSetIndex,usage);
//        if(mesh->mNumUVComponents[textureSetIndex]==2)return generateTextures2DVBO(mesh,textureSetIndex,usage);
//        if(mesh->mNumUVComponents[textureSetIndex]==3)return generateTextures3DVBO(mesh,textureSetIndex,usage);
//        return 0;
//    }
//
//    const GLuint generateTextures1DVBO(const aiScene*const scene,const unsigned int textureSetIndex,const GLenum usage) {
//        const unsigned int size=countTextureVerticesInMesh(mesh);
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[convertTexture1DVerticesNumberToElementsNumber(size)]);
//        copyTexture1DVertices(mesh,textureSetIndex,bufPtr.get());
//        return generateVBO(convertTexture1DVerticesNumberToBytesNumber(size),bufPtr.get(),usage);
//    }
//
//    const GLuint generateTextures2DVBO(const aiScene*const scene,const unsigned int textureSetIndex,const GLenum usage) {
//        const unsigned int size=countTextureVerticesInMesh(mesh);
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[convertTexture2DVerticesNumberToElementsNumber(size)]);
//        copyTexture2DVertices(mesh,textureSetIndex,bufPtr.get());
//        return generateVBO(convertTexture2DVerticesNumberToBytesNumber(size),bufPtr.get(),usage);
//    }
//
//    const GLuint generateTextures3DVBO(const aiScene*const scene,const unsigned int textureSetIndex,const GLenum usage) {
//        const unsigned int size=countTextureVerticesInMesh(mesh);
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[convertTexture3DVerticesNumberToElementsNumber(size)]);
//        copyTexture3DVertices(mesh,textureSetIndex,bufPtr.get());
//        return generateVBO(convertTexture3DVerticesNumberToBytesNumber(size),bufPtr.get(),usage);
//    }
//
//
//    const GLuint generateColorsVBO(const aiScene*const scene,const unsigned int colorSetIndex,const GLenum usage) {
//        const unsigned int size=countColorVerticesInMesh(mesh);
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[convertColorVerticesNumberToElementsNumber(size)]);
//        copyColorVertices(mesh,colorSetIndex,bufPtr.get());
//        return generateVBO(convertColorVerticesNumberToBytesNumber(size),bufPtr.get(),usage);
//    }
//
//    const GLuint generateVerticesVBO(const aiScene*const scene,const GLenum usage) {
//        const unsigned int size=countVerticesInMesh(mesh);
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[convertVerticesNumberToElementsNumber(size)]);
//        copyVertices(mesh,bufPtr.get());
//        return generateVBO(convertVerticesNumberToBytesNumber(size),bufPtr.get(),usage);
//    }


//    const GLuint generateEBO(const GLuint eboBufferID,const aiScene*const scene,const GLenum usage,const unsigned int numIndicesPerFace) {
//        const unsigned int size=countMaxIndicesInMeshesOfScene(scene);
//        std::unique_ptr<GLuint[]> bufPtr(new GLuint[convertIndicesNumberToElementsNumber(size)]);
//        intptr_t offsetInBytes=0;
//        for(unsigned int i=0;i<scene->mNumMeshes;i++){
//            offsetInBytes+=generateIndicesSubEBO(scene->mMeshes[i],bufPtr.get(),numIndicesPerFace,offsetInBytes);
//        }
//        return eboBufferID ;
//        //generateEBO(convertIndicesNumberToBytesNumber(size),bufPtr.get(),usage,eboBufferID);
//    }
//
//    const GLuint generateEBO(const aiScene*const scene,const GLenum usage,const unsigned int numIndicesPerFace) {
//        return generateEBO(glGenBuffer(),scene,usage,numIndicesPerFace);
//    }

}
