#ifndef ASSIMP_CONSTANTS_H_INCLUDED
#define ASSIMP_CONSTANTS_H_INCLUDED
namespace gle {
    const unsigned int SIZE_OF_ASSIMP_INDEX_TYPE_IN_ELEMENTS=1;
    /**3 coordinates (x,y and z) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS=3;
    /**4 color values (r,g,b and a) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS=4;
    /**3 coordinates (x,y and z) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_ELEMENTS=3;
    /**3 coordinates (x,y and z) but we ignore z and so we end up with only 2 (x and y). Each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_2D_TYPE_IN_ELEMENTS=2;
    /**3 coordinates (x,y and z) but we ignore z and y and so we end up with only 1 ( x coordinate ). Each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_1D_TYPE_IN_ELEMENTS=1;

    const unsigned int SIZE_OF_ASSIMP_INDEX_ELEMENT=sizeof(unsigned int);
    /**3 coordinates (x,y and z) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_VERTEX_ELEMENT=sizeof(float);
    /**4 color values (r,g,b and a) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_COLOR_ELEMENT=sizeof(float);
    /**3 coordinates (x,y and z) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_ELEMENT=sizeof(float);

    const unsigned int SIZE_OF_ASSIMP_INDEX_TYPE_IN_BYTES=SIZE_OF_ASSIMP_INDEX_ELEMENT*SIZE_OF_ASSIMP_INDEX_TYPE_IN_ELEMENTS;
    /**3 coordinates (x,y and z) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_VERTEX_TYPE_IN_BYTES=SIZE_OF_ASSIMP_VERTEX_ELEMENT*SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS;
    /**4 color values (r,g,b and a) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_COLOR_TYPE_IN_BYTES=SIZE_OF_ASSIMP_COLOR_ELEMENT*SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS;
    /**3 coordinates (x,y and z) each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_BYTES=SIZE_OF_ASSIMP_TEXTURE_ELEMENT*SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_ELEMENTS;
    /**3 coordinates (x,y and z) but we ignore z and so we end up with only 2 (x and y). Each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_2D_TYPE_IN_BYTES=SIZE_OF_ASSIMP_TEXTURE_ELEMENT*SIZE_OF_ASSIMP_TEXTURE_2D_TYPE_IN_ELEMENTS;
    /**3 coordinates (x,y and z) but we ignore z and y and so we end up with only 1 ( x coordinate ). Each of type float*/
    const unsigned int SIZE_OF_ASSIMP_TEXTURE_1D_TYPE_IN_BYTES=SIZE_OF_ASSIMP_TEXTURE_ELEMENT*SIZE_OF_ASSIMP_TEXTURE_1D_TYPE_IN_ELEMENTS;
}
#endif // ASSIMP_CONSTANTS_H_INCLUDED
