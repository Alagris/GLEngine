#ifndef ELEMENT_BUFFER_OBJECT_H
#define ELEMENT_BUFFER_OBJECT_H
#include <GLFW/glfw3.h>
#include "generatable.h"
#include <memory>
namespace gle {
    typedef intptr_t ebo_offset;

    class ElementBufferObject:public Generatable {
      public:
//        ElementBufferObject();
        ElementBufferObject(const GLsizei elementArraySize,const GLenum type=GL_UNSIGNED_INT,const ebo_offset elementArrayOffset=0);
        ElementBufferObject(const GLenum type=GL_UNSIGNED_INT);
        virtual ~ElementBufferObject();
        const GLenum getType ()const;
        const GLsizei getElementArraySizeInElements(const unsigned int index)const;
        const ebo_offset getElementArrayOffsetInBytes(const unsigned int index)const;
        /**Returns offset pointing to the end of EBO.
        If EBO holds x bytes in total then the output is exactly x
        (first byte is at position 0, last byte is at position x-1)*/
        inline const ebo_offset getElementArrayFinalOffsetInBytes()const{
            return getElementArrayOffsetInBytes(getSize());
        }
        /**Returns offset pointing to the beginning of last EBO subarray.*/
        inline const ebo_offset getLastElementArrayOffsetInBytes()const{
            return getElementArrayOffsetInBytes(getSize()-1);
        }
        virtual const GLuint generate(const GLuint reservedEBO_ID,const GLenum usage) {}
        const ebo_offset * const getEBOArrayOffsetsPtr() const;
        const GLsizei* const getEBOArraySizesPtr() const;
        const unsigned int getSize() const;
      protected:
        void reserve(const size_t size);
        void push_back(const GLsizei eboArraySizeInElements);
        const ebo_offset calculateNextEBOOffset()const;
      private:
        class Pimpl;
        std::shared_ptr<Pimpl> pimpl;
//        /**size in number of array elements*/
//        const GLsizei m_elementArraySize;
//        /**offset in bytes*/
//        const ebo_offset m_elementArrayOffset;
    };
}

#endif // ELEMENT_BUFFER_OBJECT_H
