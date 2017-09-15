#include "assimp_empty_buffer_generators.h"
#include "model_buffer_generators.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
namespace gle {



    const GLuint generateTexturesEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID){
        if(mesh->mNumUVComponents[textureSetIndex]==1)return generateTexturesEmpty1DVBO_glb(mesh,textureSetIndex,usage,bufferID);
        if(mesh->mNumUVComponents[textureSetIndex]==2)return generateTexturesEmpty2DVBO_glb(mesh,textureSetIndex,usage,bufferID);
        if(mesh->mNumUVComponents[textureSetIndex]==3)return generateTexturesEmpty3DVBO_glb(mesh,textureSetIndex,usage,bufferID);
        return bufferID;
    }

    const GLuint generateTexturesEmpty1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
        const unsigned int size=countTextureVerticesInMesh(mesh);
        return generateEmptyVBO_glb(convertTexture1DVerticesNumberToBytesNumber(size),usage,bufferID);
    }

    const GLuint generateTexturesEmpty2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
        const unsigned int size=countTextureVerticesInMesh(mesh);
        return generateEmptyVBO_glb(convertTexture2DVerticesNumberToBytesNumber(size),usage,bufferID);
    }

    const GLuint generateTexturesEmpty3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID) {
        const unsigned int size=countTextureVerticesInMesh(mesh);
        return generateEmptyVBO_glb(convertTexture3DVerticesNumberToBytesNumber(size),usage,bufferID);
    }


    const GLuint generateColorsEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID) {
        const unsigned int size=countColorVerticesInMesh(mesh);
        return generateEmptyVBO_glb(convertColorVerticesNumberToBytesNumber(size),usage,bufferID);
    }

    const GLuint generateVerticesEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
        const unsigned int size=countVerticesInMesh(mesh);
        return generateEmptyVBO_glb(convertVerticesNumberToBytesNumber(size),usage,bufferID);
    }


    const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID) {
        const unsigned int size=countIndicesInMesh(mesh);
        return generateEmptyEBO_glb(convertIndicesNumberToBytesNumber(size),usage,bufferID);
    }




    const GLuint generateTexturesEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage){
        return generateTexturesEmptyVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
    }

    const GLuint generateTexturesEmpty1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
        return generateTexturesEmpty1DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
    }

    const GLuint generateTexturesEmpty2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
         return generateTexturesEmpty2DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
    }

    const GLuint generateTexturesEmpty3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
        return generateTexturesEmpty3DVBO_glb(mesh,textureSetIndex,usage,glGenBuffer());
    }


    const GLuint generateColorsEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage) {
         return generateColorsEmptyVBO_glb(mesh,colorSetIndex,usage,glGenBuffer());
    }

    const GLuint generateVerticesEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage) {
         return generateVerticesEmptyVBO_glb(mesh,usage,glGenBuffer());
    }

    const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage) {
        return generateEmptyEBO_glb(mesh,usage,glGenBuffer());
    }

}
