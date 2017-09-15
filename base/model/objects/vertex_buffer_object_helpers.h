#ifndef VERTEX_BUFFER_OBJECT_HELPERS_H
#define VERTEX_BUFFER_OBJECT_HELPERS_H
#include <GLFW/glfw3.h>
//#include "vertex_buffer_object.h"
namespace gle {
    typedef intptr_t vbo_offset;
    class VertexBufferObject;
    /**Returns the size of largest subarray. One of: vertices array, colors array, textures array and normals array*/
    const  GLsizei getVBOLargestSubArraySizeInElements(const VertexBufferObject &vbo);
    const GLsizeiptr getTotalSizeOfVBOInBytes(const VertexBufferObject &vbo);
    const bool hasColorsArray(const VertexBufferObject &vbo);
    const bool hasTexturesArray(const VertexBufferObject &vbo);
    const bool hasVerticesArray(const VertexBufferObject &vbo);
    void printDebug(const VertexBufferObject &vbo);
    const unsigned int getTextureDimentionality(const VertexBufferObject &vbo,const unsigned int textureSetIndex);
    const GLsizei sumFirstNTextureSizes(const VertexBufferObject &vbo,const unsigned int n);
    const GLsizei getTotalSizeOfAllColorArraysInElements(const VertexBufferObject &vbo);
    const GLsizei getTotalSizeOfAllTextureArraysInElements(const VertexBufferObject &vbo) ;
    /**Returns offset pointing right at the first byte after VBO*/
    const vbo_offset getVBOEndingOffset(const VertexBufferObject &vbo);
    const vbo_offset getTextureArrayOffsetInBytes(const VertexBufferObject &vbo,const unsigned int textureCoordSetIndex);
    const vbo_offset getColorArrayOffsetInBytes(const VertexBufferObject &vbo,const unsigned int colorSetIndex);

}
#endif // VERTEX_BUFFER_OBJECT_HELPERS_H
