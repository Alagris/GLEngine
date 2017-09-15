#include "element_buffer_object_helpers.h"
#include "element_buffer_object.h"
#include "assimp_converters.h"
#include "max.h"
namespace gle {
    const  GLsizei getEBOLargestSubArraySizeInElements(const ElementBufferObject &ebo) {
        GLsizei max=0;
        for(unsigned int i=0; i<ebo.getSize(); i++) {
            compareMax<GLsizei>(ebo.getElementArraySizeInElements(i),max);
        }
        return max;
    }
    const GLsizeiptr getTotalSizeOfEBOInBytes(const ElementBufferObject &ebo) {
//        GLsizei out=0;
//        for(unsigned int i=0; i<ebo.getSize(); i++) {
//            out+=ebo.getElementArraySizeInElements(i);
//        }
//        return convertIndexElementsNumberToBytesNumber(out);
        return ebo.getElementArrayFinalOffsetInBytes();
    }
}
