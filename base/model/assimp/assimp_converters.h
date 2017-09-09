#ifndef ASSIMP_CONVERTERS_H_INCLUDED
#define ASSIMP_CONVERTERS_H_INCLUDED
#include "assimp_constants.h"

namespace gle {
    inline const unsigned int convertVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_VERTEX_TYPE_IN_BYTES;
    }
    inline const unsigned int convertVertexElementsNumberToBytesNumber(const unsigned int elementsNumber) {
        return elementsNumber*SIZE_OF_ASSIMP_VERTEX_ELEMENT;
    }
    /**Use this to compute size of array needed to store all of the mesh vertices*/
    inline const unsigned int convertVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS;
    }
    inline const unsigned int convertIndicesNumberToBytesNumber(const unsigned int indicesNumber) {
        return indicesNumber*SIZE_OF_ASSIMP_INDEX_TYPE_IN_BYTES;
    }
    inline const unsigned int convertIndexElementsNumberToBytesNumber(const unsigned int elementsNumber) {
        return elementsNumber*SIZE_OF_ASSIMP_INDEX_ELEMENT;
    }
    /**Use this to compute size of array needed to store all of the mesh indices*/
    inline const unsigned int convertIndicesNumberToElementsNumber(const unsigned int indicesNumber) {
        return indicesNumber*SIZE_OF_ASSIMP_INDEX_TYPE_IN_ELEMENTS;
    }
    inline const unsigned int convertColorVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS;
    }
    /**Use this to compute size of array needed to store all of the mesh color vertices*/
    inline const unsigned int convertColorVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_COLOR_TYPE_IN_BYTES;
    }
    inline const unsigned int convertColorElementsNumberToBytesNumber(const unsigned int elementsNumber) {
        return elementsNumber*SIZE_OF_ASSIMP_COLOR_ELEMENT;
    }

    inline const unsigned int convertTextureVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_TYPE_IN_ELEMENTS;
    }
    /**Use this to compute size of array needed to store all of the mesh color vertices*/
    inline const unsigned int convertTextureVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_TYPE_IN_BYTES;
    }
    inline const unsigned int convertTextureElementsNumberToBytesNumber(const unsigned int elementsNumber) {
        return elementsNumber*SIZE_OF_ASSIMP_TEXTURE_ELEMENT;
    }

}
#endif // ASSIMP_CONVERTERS_H_INCLUDED
