#ifndef ELEMENT_BUFFER_OBJECT_HELPERS_H
#define ELEMENT_BUFFER_OBJECT_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle{
    class ElementBufferObject;
    const  GLsizei getEBOLargestSubArraySizeInElements(const ElementBufferObject &ebo);
    const GLsizeiptr getTotalSizeOfEBOInBytes(const ElementBufferObject &ebo);
}

#endif // ELEMENT_BUFFER_OBJECT_HELPERS_H
