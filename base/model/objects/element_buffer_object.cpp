#include "element_buffer_object.h"
#include <vector>
#include "assimp_converters.h"
namespace gle {

    ////////////////////////
    //Pimpl
    ////////////////////////
    class ElementBufferObject::Pimpl {
      public:
        ///////
        //constructors
        ///////
        Pimpl(const GLsizei elementArraySize,const GLenum type,const ebo_offset elementArrayOffset):
            m_type(type),
            m_eboArraySizes({elementArraySize}),
            m_eboArrayOffsets({elementArrayOffset,elementArrayOffset+convertIndexElementsNumberToBytesNumber(elementArraySize)}) {}
        Pimpl(const GLenum type=GL_UNSIGNED_INT):
            m_type(type),
            m_eboArraySizes(),
            m_eboArrayOffsets({0}) {}
        ///////
        //variables
        ///////
        const GLenum m_type;
        /**size in number of array elements*/
        std::vector<GLsizei> m_eboArraySizes;
        /**offset in bytes*/
        std::vector<ebo_offset> m_eboArrayOffsets;
        ///////
        //functions
        ///////
    };

    ////////////////////////
    //ElementBufferObject
    ////////////////////////

    ////constructors/destructors
//    ElementBufferObject::ElementBufferObject():pimpl(new Pimpl()) {}
    ElementBufferObject::ElementBufferObject(const GLenum type):pimpl(new Pimpl(type)) {}

    ElementBufferObject::ElementBufferObject(const GLsizei elementArraySize,const GLenum type,const ebo_offset elementArrayOffset):
        pimpl(new Pimpl(elementArraySize,type,elementArrayOffset)) {}


    ElementBufferObject::~ElementBufferObject() {}


    ////EBO functions
    const GLenum ElementBufferObject::getType ()const {
        return pimpl.get()->m_type ;
    }
    const GLsizei ElementBufferObject::getElementArraySizeInElements(const unsigned int index)const {
        return pimpl.get()->m_eboArraySizes[index];
    }
    const ebo_offset ElementBufferObject::getElementArrayOffsetInBytes(const unsigned int index)const {
        return pimpl.get()->m_eboArrayOffsets[index];
    }
    const ebo_offset * const ElementBufferObject::getEBOArrayOffsetsPtr() const {
        return &(pimpl.get()->m_eboArrayOffsets[0]);
    }
    const GLsizei* const ElementBufferObject::getEBOArraySizesPtr() const {
        return &(pimpl.get()->m_eboArraySizes[0]);
    }
    const unsigned int ElementBufferObject::getSize() const {
        //This is very important to return size of m_eboArraySizes
        //because m_eboArrayOffsets always holds one extra element
        //and thus it's bigger by one
        return pimpl.get()->m_eboArraySizes.size();
    }

    const ebo_offset ElementBufferObject::calculateNextEBOOffset()const {
        return pimpl.get()->m_eboArrayOffsets.back()+ convertIndexElementsNumberToBytesNumber(pimpl.get()->m_eboArraySizes.back());
    }
    void ElementBufferObject::push_back(const GLsizei eboArraySizeInElements) {
        pimpl.get()->m_eboArraySizes.push_back(eboArraySizeInElements);
        pimpl.get()->m_eboArrayOffsets.push_back(calculateNextEBOOffset());
    }
    void ElementBufferObject::reserve(const size_t size) {
        pimpl.get()->m_eboArraySizes.reserve(size);
        pimpl.get()->m_eboArrayOffsets.reserve(size+1);
    }







}
