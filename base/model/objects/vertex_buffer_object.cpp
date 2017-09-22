#include "vertex_buffer_object.h"
#include "assimp_elements_counters.h"
#include "assimp_converters.h"
#include <vector>
namespace gle {
    ////////////////////////
    //Pimpl
    ////////////////////////
    class VertexBufferObject::Pimpl {
      public:
        Pimpl();
        Pimpl(const GLsizei vertexArraySizeInElements,
              const GLsizei colorArraySizeInElements,
              const GLsizei vertexNormalArraySizeInElements,
              const GLsizei textureCoordArraySizeInElements,
              const uint8_t textureDimentionality=2,
              const vbo_offset initialOffset=0);
        Pimpl(const GLsizei vertexArraySizeInElements,
              const unsigned int colorSetsNumber,
              const GLsizei colorArraySizeInElements,
              const GLsizei vertexNormalArraySizeInElements,
              const vbo_offset initialOffset,
              const GLsizei textureSetsNumber);
        ///////////////////
        //variables
        ///////////////////
        /**size in number of array elements*/
        const GLsizei m_vertexArraySize;
        /**offset in bytes*/
        const  vbo_offset m_vertexArrayOffset;

        const unsigned int m_colorSetsNumber;
        /**size in number of array elements*/
        const GLsizei m_colorArraySize;
        /**offset in bytes*/
        const vbo_offset m_colorArrayOffset;

        /**size in number of array elements*/
        const GLsizei m_vertexNormalsArraySize;
        /**offset in bytes*/
        const vbo_offset m_vertexNormalsArrayOffset;


//        const unsigned int m_textureSetsNumber;

        /**size in number of array elements. IMPORTANT:
        This vector is actually meant to be of fixed size.
        Thanks to encapsulation we can achieve this fairly simply.
        We just have to remember to always take into account
        vector capacity instead of it's size. We just allocate
         initial capacity in constructor and then, each time
         we push_back, we check if the capacity hasn't been reached yet.

         In short, stick to this simple rule: you can change size
         anywhere but capacity can only be changed in a constructor*/
        std::vector<GLsizei> m_textureArraySizes;
//        const std::unique_ptr<GLsizei> m_textureArraySizes;
        /**offset in bytes*/
        const vbo_offset m_textureArrayOffset;
        uint8_t m_textureDimentionalityBitfield;

        ///////////////////
        //functions
        ///////////////////
        const GLsizei getTotalSizeOfAllColorArraysInElements()const {
            return m_colorArraySize*m_colorSetsNumber;
        }
        const vbo_offset recalculateColorArrayOffset()const {
            return m_vertexArrayOffset+convertVboElementsNumberToBytesNumber(m_vertexArraySize);
        }
        const vbo_offset recalculateVertexNormalsArrayOffset()const {
            return m_colorArrayOffset+convertVboElementsNumberToBytesNumber(getTotalSizeOfAllColorArraysInElements());
        }
        const vbo_offset recalculateTextureArrayOffset()const {
            return m_vertexNormalsArrayOffset+convertVboElementsNumberToBytesNumber(m_vertexNormalsArraySize);
        }
    };

    VertexBufferObject::Pimpl::Pimpl():
        m_vertexArraySize(0),
        m_vertexArrayOffset(0),
        m_colorSetsNumber(0),
        m_colorArraySize(0),
        m_colorArrayOffset(0),
        m_vertexNormalsArraySize(0),
        m_vertexNormalsArrayOffset(0),
//        m_textureSetsNumber(0),
        m_textureArraySizes(),
        m_textureArrayOffset(0),
        m_textureDimentionalityBitfield(0) {}

    VertexBufferObject::Pimpl::Pimpl(
        const GLsizei vertexArraySizeInElements,
        const GLsizei colorArraySizeInElements,
        const GLsizei vertexNormalArraySizeInElements,
        const GLsizei textureCoordArraySizeInElements,
        const uint8_t textureDimentionality,
        const vbo_offset initialOffset)
        :
        m_vertexArraySize(vertexArraySizeInElements),
        m_vertexArrayOffset(initialOffset),
        m_colorSetsNumber(1),
        m_colorArraySize(colorArraySizeInElements),
        m_colorArrayOffset(recalculateColorArrayOffset()),
        m_vertexNormalsArraySize(vertexNormalArraySizeInElements),
        m_vertexNormalsArrayOffset(recalculateVertexNormalsArrayOffset()),
//        m_textureSetsNumber(1),
        m_textureArraySizes(),
        m_textureArrayOffset(recalculateTextureArrayOffset()),
        m_textureDimentionalityBitfield(0)
    {
        m_textureArraySizes.push_back(textureCoordArraySizeInElements);
    }


    VertexBufferObject::Pimpl::Pimpl(
        const GLsizei vertexArraySizeInElements,
        const unsigned int colorSetsNumber,
        const GLsizei colorArraySizeInElements,
        const GLsizei vertexNormalArraySizeInElements,
        const vbo_offset initialOffset,
        const GLsizei textureSetsNumber)
        :
        m_vertexArraySize(vertexArraySizeInElements),
        m_vertexArrayOffset(initialOffset),
        m_colorSetsNumber(colorSetsNumber),
        m_colorArraySize(colorArraySizeInElements),
        m_colorArrayOffset(recalculateColorArrayOffset()),
        m_vertexNormalsArraySize(vertexNormalArraySizeInElements),
        m_vertexNormalsArrayOffset(recalculateVertexNormalsArrayOffset()),
//        m_textureSetsNumber(textureSetsNumber),
        m_textureArraySizes(),
        m_textureArrayOffset(recalculateTextureArrayOffset()),
        m_textureDimentionalityBitfield(0)
    {
        m_textureArraySizes.reserve(textureSetsNumber);
    }


    ////////////////////////
    //VertexBufferObject
    ////////////////////////

    VertexBufferObject::VertexBufferObject():pimpl(new Pimpl()) {}


    VertexBufferObject::VertexBufferObject(
        const GLsizei vertexArraySizeInElements,
        const GLsizei colorArraySizeInElements,
        const GLsizei vertexNormalArraySizeInElements,
        const GLsizei textureCoordArraySizeInElements,
        const uint8_t textureDimentionality,
        const vbo_offset initialOffset):
        pimpl(new Pimpl(
                  vertexArraySizeInElements,
                  colorArraySizeInElements,
                  vertexNormalArraySizeInElements,
                  textureCoordArraySizeInElements,
                  textureDimentionality,
                  initialOffset))
    {
        if(textureDimentionality==1)setHas1DTexture();
        if(textureDimentionality==2)setHas2DTexture();
        if(textureDimentionality==3)setHas3DTexture();
    }


    VertexBufferObject::VertexBufferObject(
        const GLsizei vertexArraySizeInElements,
        const unsigned int colorSetsNumber,
        const GLsizei colorArraySizeInElements,
        const GLsizei vertexNormalArraySizeInElements,
        const vbo_offset initialOffset,
        const GLsizei textureSetsNumber):
        pimpl(new Pimpl(
                  vertexArraySizeInElements,
                  colorSetsNumber,
                  colorArraySizeInElements,
                  vertexNormalArraySizeInElements,
                  initialOffset,
                  textureSetsNumber)) {}


    const unsigned int VertexBufferObject::getBiggestTextureDimentionality()const {
        if(pimpl.get()->m_textureDimentionalityBitfield>2)return 3;
        if(pimpl.get()->m_textureDimentionalityBitfield>1)return 2;
        if(pimpl.get()->m_textureDimentionalityBitfield>0)return 1;
        return 0;

    }
    const GLsizei VertexBufferObject::getVertexArraySizeInElements() const {
        return pimpl.get()->m_vertexArraySize;
    }
    const GLsizei VertexBufferObject::getVertexArrayOffsetInBytes() const {
        return pimpl.get()->m_vertexArrayOffset;
    }
    const GLsizei VertexBufferObject::getColorArraySizeInElements()const {
        return pimpl.get()->m_colorArraySize;
    }
    const unsigned int VertexBufferObject::getColorSetsNumber() const {
        return pimpl.get()->m_colorSetsNumber;
    }
    const vbo_offset VertexBufferObject::getColorArrayOffsetInBytes()const {
        return pimpl.get()->m_colorArrayOffset;
    }
    const GLsizei VertexBufferObject::getVertexNormalArraySizeInElements()const {
        return pimpl.get()->m_vertexNormalsArraySize;
    }
    const vbo_offset VertexBufferObject::getVertexNormalArrayOffsetInBytes()const {
        return pimpl.get()->m_vertexNormalsArrayOffset;
    }
    const GLsizei VertexBufferObject::getTextureArraySizeInElements(const unsigned int textureCoordSetIndex)const {
        return pimpl.get()->m_textureArraySizes[textureCoordSetIndex];
    }
    const unsigned int VertexBufferObject::getTextureSetsNumber() const {
        return pimpl.get()->m_textureArraySizes.capacity();
    }
    const vbo_offset VertexBufferObject::getTextureArrayOffsetInBytes()const {
        return pimpl.get()->m_textureArrayOffset;
    }
    void VertexBufferObject::setTextureDimentionalityInfo(const uint8_t mask) {
        pimpl.get()->m_textureDimentionalityBitfield|=mask;
    }
    bool VertexBufferObject::getTextureDimentionalityInfo(const uint8_t mask)const {
        return static_cast<bool>((pimpl.get()->m_textureDimentionalityBitfield)&mask);
    }
    void VertexBufferObject::setTextureArraySizeInElements(const unsigned int textureCoordSetIndex,const GLsizei size) {
        std::vector<GLsizei> & arr =pimpl.get()->m_textureArraySizes;
        if(textureCoordSetIndex<arr.capacity()) {
            if(arr.size()<=textureCoordSetIndex) {
                while(arr.size()<textureCoordSetIndex)arr.push_back(0);
                arr.push_back(size);
            } else {
                arr[textureCoordSetIndex]=size;
            }
        }
    }
    const vbo_offset VertexBufferObject::recalculateColorArrayOffset()const {
        return pimpl.get()->recalculateColorArrayOffset();
    }
    const vbo_offset VertexBufferObject::recalculateTextureArrayOffset()const {
        return pimpl.get()->recalculateTextureArrayOffset();
    }
}
