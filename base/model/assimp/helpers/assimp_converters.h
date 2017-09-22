#ifndef ASSIMP_CONVERTERS_H_INCLUDED
#define ASSIMP_CONVERTERS_H_INCLUDED
#include "assimp_constants.h"


namespace gle {

    /////////////////////
    //mixed
    /////////////////////


    inline constexpr const unsigned int convertVboElementsNumberToBytesNumber(const unsigned int elementsNumber) {
        return elementsNumber*SIZE_OF_ASSIMP_VERTEX_ELEMENT;
    }


    /////////////////////
    //vertices
    /////////////////////

//    inline const unsigned int convertVertexElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_VERTEX_ELEMENT;
//    }
    /**Use this to compute size of array needed to store all of the mesh vertices*/
    inline constexpr const unsigned int convertVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS;
    }
    inline constexpr const unsigned int convertVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
        return convertVboElementsNumberToBytesNumber(convertVerticesNumberToElementsNumber(verticesNumber));
    }
    /////////////////////
    //indices
    /////////////////////
    /**Use this to compute size of buffer needed to store all of the mesh indices*/
    inline const unsigned int convertIndicesNumberToElementsNumber(const unsigned int indicesNumber) {
        return indicesNumber*SIZE_OF_ASSIMP_INDEX_TYPE_IN_ELEMENTS;
    }
    inline const unsigned int convertIndexElementsNumberToBytesNumber(const unsigned int elementsNumber) {
        return elementsNumber*SIZE_OF_ASSIMP_INDEX_ELEMENT;
    }
    inline const unsigned int convertIndicesNumberToBytesNumber(const unsigned int indicesNumber) {
        return convertIndexElementsNumberToBytesNumber(convertIndicesNumberToElementsNumber(indicesNumber));
    }

    /////////////////////
    //colors
    /////////////////////
    inline const unsigned int convertColorVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS;
    }
//    inline const unsigned int convertColorElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_COLOR_ELEMENT;
//    }
    /**Use this to compute size of buffer needed to store all of the mesh color vertices*/
    inline const unsigned int convertColorVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
        return convertVboElementsNumberToBytesNumber(convertColorVerticesNumberToElementsNumber(verticesNumber));
    }
    /////////////////////
    //vertex normals
    /////////////////////

//    inline const unsigned int convertVertexNormalElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_VERTEX_NORMAL_ELEMENT;
//    }
    /**Use this to compute size of array needed to store all of the mesh vertices*/
    inline const unsigned int convertVertexNormalsNumberToElementsNumber(const unsigned int verticesNumber) {
        return verticesNumber*SIZE_OF_ASSIMP_VERTEX_NORMAL_TYPE_IN_ELEMENTS;
    }
    inline const unsigned int convertVertexNormalsNumberToBytesNumber(const unsigned int verticesNumber) {
        return convertVboElementsNumberToBytesNumber(convertVertexNormalsNumberToElementsNumber(verticesNumber));
    }
    /////////////////////
    //textures
    /////////////////////

//    inline const unsigned int convertTexture3DVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
//        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_ELEMENTS;
//    }
//    /**Use this to compute size of buffer needed to store all of the mesh color vertices*/
//    inline const unsigned int convertTexture3DVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
//        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_BYTES;
//    }
//    inline const unsigned int convertTexture3DElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_TEXTURE_ELEMENT;
//    }
//
//    inline const unsigned int convertTexture2DVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
//        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_2D_TYPE_IN_ELEMENTS;
//    }
//    /**Use this to compute size of buffer needed to store all of the mesh color vertices*/
//    inline const unsigned int convertTexture2DVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
//        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_2D_TYPE_IN_BYTES;
//    }
//    inline const unsigned int convertTexture2DElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_TEXTURE_ELEMENT;
//    }
//
//    inline const unsigned int convertTexture1DVerticesNumberToElementsNumber(const unsigned int verticesNumber) {
//        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_1D_TYPE_IN_ELEMENTS;
//    }
//    /**Use this to compute size of buffer needed to store all of the mesh color vertices*/
//    inline const unsigned int convertTexture1DVerticesNumberToBytesNumber(const unsigned int verticesNumber) {
//        return verticesNumber*SIZE_OF_ASSIMP_TEXTURE_1D_TYPE_IN_BYTES;
//    }
//    inline const unsigned int convertTexture1DElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_TEXTURE_ELEMENT;
//    }
//
//    inline const unsigned int convertTextureElementsNumberToBytesNumber(const unsigned int elementsNumber) {
//        return elementsNumber*SIZE_OF_ASSIMP_TEXTURE_ELEMENT;
//    }

    inline constexpr const unsigned int convertTextureVerticesNumberToElementsNumber(const unsigned int verticesNumber,const unsigned int dimentionality) {
        return verticesNumber*dimentionality;
    }
    inline constexpr const unsigned int convertTextureVerticesNumberToBytesNumber(const unsigned int verticesNumber,const unsigned int dimentionality) {
        return convertVboElementsNumberToBytesNumber(convertTextureVerticesNumberToElementsNumber(verticesNumber,dimentionality));
    }





}
#endif // ASSIMP_CONVERTERS_H_INCLUDED
