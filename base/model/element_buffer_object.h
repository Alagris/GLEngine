#ifndef ELEMENT_BUFFER_OBJECT_H
#define ELEMENT_BUFFER_OBJECT_H
#include <GLFW/glfw3.h>
#include <assimp/mesh.h>
namespace gle {

    struct ElementBufferObject {
        ElementBufferObject();
        ElementBufferObject(const aiMesh*const mesh);
        GLenum type;
        /**size in number of array elements*/
        GLsizei elementArraySize;
        /**offset in bytes*/
        void * elementArrayOffset;
    };
}

#endif // ELEMENT_BUFFER_OBJECT_H
