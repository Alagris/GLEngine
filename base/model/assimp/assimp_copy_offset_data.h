#ifndef ASSIMP_COPY_OFFSET_DATA_H
#define ASSIMP_COPY_OFFSET_DATA_H
#include <GLFW/glfw3.h>
#include "assimp/mesh.h"

namespace gle {

//    const unsigned int copyVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination,const unsigned int offset);
//    inline const unsigned int copyVertices(const aiMesh *const mesh,GLfloat *const destination,const unsigned int offset ) {
//        return copyVertices(mesh->mVertices,mesh->mNumVertices,destination,offset);
//    }
//    const unsigned int copyColorVertices(const aiColor4D *const  meshColors,const unsigned int numVertices,GLfloat *const destination ,const unsigned int offset);
//    inline const unsigned int copyColorVertices(const aiMesh *const mesh,const unsigned int colorSetIndex,GLfloat *const destination,const unsigned int offset ) {
//        return copyColorVertices(mesh->mColors[colorSetIndex],mesh->mNumVertices,destination,offset);
//    }
//    const unsigned int copyIndices(const aiFace *const meshFaces,const unsigned int numFaces,const unsigned int numIndicesPerFace,GLuint *const destination,const unsigned int offset );
//    inline const unsigned int copyIndices(const aiMesh *const mesh,const unsigned int numIndicesPerFace,GLuint *const destination,const unsigned int offset ) {
//        return copyIndices(mesh->mFaces,mesh->mNumFaces,numIndicesPerFace,destination,offset);
//    }
//    inline const unsigned int copyTexture3DVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination ,const unsigned int offset){
//        return copyVertices( meshTextureVertices, numVertices, destination,offset);
//    }
//    inline const unsigned int copyTexture3DVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination,const unsigned int offset ) {
//        return copyVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination,offset);
//    }
//    const unsigned int copyTexture2DVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination,const unsigned int offset );
//    inline const unsigned int copyTexture2DVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination ,const unsigned int offset) {
//        return copyTexture2DVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination,offset);
//    }
//    const unsigned int copyTexture1DVertices(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination ,const unsigned int offset);
//    inline const unsigned int copyTexture1DVertices(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination,const unsigned int offset ) {
//        return copyTexture1DVertices(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination,offset);
//    }




}

#endif // ASSIMP_COPY_OFFSET_DATA_H
