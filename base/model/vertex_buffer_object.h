#ifndef VERTEX_BUFFER_OBJECT_H
#define VERTEX_BUFFER_OBJECT_H
#include <assimp/mesh.h>
#include <GLFW/glfw3.h>
namespace gle {
    typedef intptr_t vbo_offset;
    struct VertexBufferObject {
        VertexBufferObject();
        VertexBufferObject(const aiMesh*const mesh);
        VertexBufferObject(const aiMesh*const mesh,const vbo_offset initialOffset);
        /**size in number of array elements*/
        GLsizei vertexArraySize;
        /**offset in bytes*/
        vbo_offset vertexArrayOffset;
        /**size in number of array elements*/
        GLsizei colorArraySize;
        /**offset in bytes*/
        vbo_offset colorArrayOffset;
        /**size in number of array elements*/
        GLsizei textureArraySize;
        /**offset in bytes*/
        vbo_offset textureArrayOffset;
    };
}

#endif // VERTEX_BUFFER_OBJECT_H
