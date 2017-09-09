#include "assimp_buffer_generators.h"
#include "model_buffer_generators.h"
#include "assimp_copy_data.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
namespace gle {



    const GLuint generateTexturesVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage) {
        GLfloat * buffer =new GLfloat[convertTextureVerticesNumberToElementsNumber(mesh->mNumVertices)];
        copyTextureVertices(mesh,textureSetIndex,buffer);
        GLuint out= generateVBO(convertTextureVerticesNumberToBytesNumber(mesh->mNumVertices),buffer,usage);
        delete[] buffer;
        return out;
    }

    const GLuint generateColorsVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage) {
        GLfloat * buffer =new GLfloat[convertColorVerticesNumberToElementsNumber(mesh->mNumVertices)];
        copyColorVertices(mesh,colorSetIndex,buffer);
        GLuint out= generateVBO(convertColorVerticesNumberToBytesNumber(mesh->mNumVertices),buffer,usage);
        delete[] buffer;
        return out;
    }

    const GLuint generateVerticesVBO(const aiMesh*const mesh,const GLenum usage) {
        GLfloat * buffer =new GLfloat[convertVerticesNumberToElementsNumber(mesh->mNumVertices)];
        copyVertices(mesh,buffer);
        GLuint out= generateVBO(convertVerticesNumberToBytesNumber(mesh->mNumVertices),buffer,usage);
        delete[] buffer;
        return out;
    }


    const GLuint generateEBO(const aiMesh*const mesh,const GLenum usage,const GLuint eboBufferID) {
        const unsigned int indicesNum=countIndicesInMesh(mesh);
        GLuint * buffer =new GLuint[convertIndicesNumberToElementsNumber(indicesNum)];
        copyIndices(mesh,3,buffer);
        const GLuint out =generateEBO(convertIndicesNumberToBytesNumber(indicesNum),buffer,usage,eboBufferID);
        delete[] buffer;
        return out;
    }

    const GLuint generateEBO(const aiMesh*const mesh,const GLenum usage) {
        return generateEBO(mesh,usage,glGenBuffer());
    }

}
