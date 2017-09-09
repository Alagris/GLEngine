#ifndef VERTEX_BUFFER_OBJECT_HELPERS_H
#define VERTEX_BUFFER_OBJECT_HELPERS_H
#include <GLFW/glfw3.h>
//#include "vertex_buffer_object.h"
namespace gle {
    struct VertexBufferObject;
    /**retruns total size in bytes*/
    const  GLsizeiptr countVBOTotalSize(const VertexBufferObject &vbo);
    const  GLsizei countVBOTotalSizeInElements(const VertexBufferObject &vbo);
    void correctVBOOffsets(VertexBufferObject &vbo);
    /**Returns the size of largest subarray. One of: vertices array, colors array, textures array and normals array*/
    const  GLsizei getVBOLargestSubArraySizeInElements(const VertexBufferObject &vbo);
    bool hasColorsArray(const VertexBufferObject &vbo);
    bool hasTexturesArray(const VertexBufferObject &vbo);
    bool hasVerticesArray(const VertexBufferObject &vbo);
    void printDebug(const VertexBufferObject &vbo);
}
#endif // VERTEX_BUFFER_OBJECT_HELPERS_H
