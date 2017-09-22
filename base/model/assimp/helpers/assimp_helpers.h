#ifndef ASSIMP_HELPERS_H_INCLUDED
#define ASSIMP_HELPERS_H_INCLUDED
#include "assimp_constants.h"
#include <assimp/scene.h>

namespace gle {


    namespace color {
        inline const bool hasAtLeastOneActiveSetInMesh(const aiMesh*const mesh) {
            return mesh->HasVertexColors(0);
        }

        inline const unsigned int countActiveSetsInMesh(const aiMesh*const mesh) {
            return mesh->GetNumColorChannels();
        }

    }

    namespace texture {
        inline const bool hasAtLeastOneActiveSetInMesh(const aiMesh*const mesh) {
            return mesh->HasTextureCoords(0);
        }
        inline const unsigned int countActiveSetsInMesh(const aiMesh*const mesh) {
            return mesh->GetNumUVChannels();
        }
        inline constexpr const unsigned int getDimentionality(const aiMesh*const mesh,const unsigned int textureSetIndex) {
            return mesh->mNumUVComponents[textureSetIndex];
        }
        inline const unsigned int getDimentionality(const unsigned int textureElementsNumber,const unsigned int vertexElementsNumber) {
            //vertexElementsNumber/SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS = verticesNumber
            //textureVerticesNumber*dimentionality=textureElementsNumber
            //textureVerticesNumber=verticesNumber
            //textureElementsNumber/verticesNumber = dimentionality
            //textureElementsNumber/(vertexElementsNumber/SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS) = dimentionality
            //textureElementsNumber/vertexElementsNumber*SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS = dimentionality
            if(vertexElementsNumber==0)return 2;//let's assume 2 is default
            return textureElementsNumber*SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS/vertexElementsNumber;
        }
    }

}


#endif // ASSIMP_HELPERS_H_INCLUDED
