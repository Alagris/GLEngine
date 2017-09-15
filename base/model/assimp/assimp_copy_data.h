#ifndef ASSIMP_COPY_DATA_H
#define ASSIMP_COPY_DATA_H
#include <GLFW/glfw3.h>
#include "assimp/mesh.h"

namespace gle {

    const unsigned int copyVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination );
    inline const unsigned int copyVertices(const aiMesh *const mesh,GLfloat *const destination ) {
        return copyVertices(mesh->mVertices,mesh->mNumVertices,destination);
    }
    const unsigned int copyColorVertices(const aiColor4D *const  meshColors,const unsigned int numVertices,GLfloat *const destination );
    inline const unsigned int copyColorVertices(const aiMesh *const mesh,const unsigned int colorSetIndex,GLfloat *const destination ) {
        return copyColorVertices(mesh->mColors[colorSetIndex],mesh->mNumVertices,destination);
    }
    const unsigned int copyIndices(const aiFace *const meshFaces,const unsigned int numFaces,const unsigned int numIndicesPerFace,GLuint *const destination );
    inline const unsigned int copyIndices(const aiMesh *const mesh,const unsigned int numIndicesPerFace,GLuint *const destination ) {
        return copyIndices(mesh->mFaces,mesh->mNumFaces,numIndicesPerFace,destination);
    }
    inline const unsigned int copyTexture3DVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination ){
        return copyVertices( meshTextureVertices, numVertices, destination);
    }
    inline const unsigned int copyTexture3DVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination ) {
        return copyVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination);
    }
    const unsigned int copyTexture2DVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination );
    inline const unsigned int copyTexture2DVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination ) {
        return copyTexture2DVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination);
    }
    const unsigned int copyTexture1DVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination );
    inline const unsigned int copyTexture1DVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination ) {
        return copyTexture1DVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination);
    }




}

#endif // ASSIMP_COPY_DATA_H
