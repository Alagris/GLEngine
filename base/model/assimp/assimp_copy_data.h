#ifndef ASSIMP_COPY_DATA_H
#define ASSIMP_COPY_DATA_H
#include <GLFW/glfw3.h>
#include "assimp/mesh.h"
namespace gle {

    void copyVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination );
    inline void copyVertices(const aiMesh *const mesh,GLfloat *const destination ) {
        copyVertices(mesh->mVertices,mesh->mNumVertices,destination);
    }
    void copyColorVertices(const aiColor4D *const  meshColors,const unsigned int numVertices,GLfloat *const destination );
    inline void copyColorVertices(const aiMesh *const mesh,const unsigned int colorSetIndex,GLfloat *const destination ) {
        copyColorVertices(mesh->mColors[colorSetIndex],mesh->mNumVertices,destination);
    }
    void copyIndices(const aiFace *const meshFaces,const unsigned int numFaces,const unsigned int numIndicesPerFace,GLuint *const destination );
    inline void copyIndices(const aiMesh *const mesh,const unsigned int numIndicesPerFace,GLuint *const destination ) {
        copyIndices(mesh->mFaces,mesh->mNumFaces,numIndicesPerFace,destination);
    }
    inline void copyTextureVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination ){
        copyVertices( meshTextureVertices, numVertices, destination);
    }
    inline void copyTextureVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination ) {
        copyVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination);
    }

}

#endif // ASSIMP_COPY_DATA_H
