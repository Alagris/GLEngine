#ifndef ASSIMP_COPY_DATA_H
#define ASSIMP_COPY_DATA_H
#include <GLFW/glfw3.h>
#include <assimp/mesh.h>

namespace gle {

    namespace primitive {
        const unsigned int copy3DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination );
        const unsigned int copy2DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination );
        const unsigned int copy1DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination );
        const unsigned int copyColorVertices(const aiColor4D *const  meshColors,const unsigned int numVertices,GLfloat *const destination );
        const unsigned int copyIndices(const aiFace *const meshFaces,const unsigned int numFaces,const unsigned int numIndicesPerFace,GLuint *const destination );
    }

    namespace index {
        using namespace ::gle::primitive;
        inline const unsigned int copy(const aiMesh *const mesh,const unsigned int numIndicesPerFace,GLuint *const destination ) {
            return copyIndices(mesh->mFaces,mesh->mNumFaces,numIndicesPerFace,destination);
        }
    }

    namespace vertex {
        using namespace ::gle::primitive;
        inline unsigned int copy(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination ) {
            return copy3DVertices(meshVertices,numVertices,destination);
        }
        inline const unsigned int copy(const aiMesh *const mesh,GLfloat *const destination ) {
            return copy3DVertices(mesh->mVertices,mesh->mNumVertices,destination);
        }
    }

    namespace color {
        using namespace ::gle::primitive;
        inline const unsigned int copy(const aiColor4D *const  meshColors,const unsigned int numVertices,GLfloat *const destination ) {
            return copyColorVertices( meshColors, numVertices, destination );
        }
        inline const unsigned int copy(const aiMesh *const mesh,const unsigned int colorSetIndex,GLfloat *const destination ) {
            return copyColorVertices(mesh->mColors[colorSetIndex],mesh->mNumVertices,destination);
        }
    }

    namespace normal {
        using namespace ::gle::primitive;

        inline const unsigned int copy(const aiMesh *const mesh,GLfloat *const destination ) {
            if(mesh->HasNormals() )return copy3DVertices(mesh->mNormals,mesh->mNumVertices,destination);
            return 0;
        }
        inline const unsigned int copy(const aiVector3D *const  meshVertexNormals,const unsigned int numVertices,GLfloat *const destination ) {
            return copy3DVertices( meshVertexNormals, numVertices, destination);
        }
    }

    namespace texture {
        using namespace ::gle::primitive;

        inline const unsigned int copy(const aiVector3D *const  meshTextureVertices,const unsigned int numVertices,GLfloat *const destination,const unsigned int dimentionality ) {
            if(dimentionality==1)return copy1DVertices( meshTextureVertices, numVertices, destination);
            if(dimentionality==2)return copy2DVertices( meshTextureVertices, numVertices, destination);
            if(dimentionality==3)return copy3DVertices( meshTextureVertices, numVertices, destination);
        }
        inline const unsigned int copy(const aiMesh *const mesh,const unsigned int textureSetIndex,GLfloat *const destination) {
            return copy(mesh->mTextureCoords[textureSetIndex],mesh->mNumVertices,destination,mesh->mNumUVComponents[textureSetIndex]);
        }
    }
}

#endif // ASSIMP_COPY_DATA_H
