#ifndef VERTEX_BUFFER_OBJECT_H
#define VERTEX_BUFFER_OBJECT_H
//#include <assimp/mesh.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "generatable.h"
namespace gle {
    typedef intptr_t vbo_offset;
    class VertexBufferObject :public Generatable {
      public:
        ///////////////////
        //public constructors
        ///////////////////
        VertexBufferObject();
        virtual ~VertexBufferObject() {}

        VertexBufferObject(const GLsizei vertexArraySizeInElements,
                           const GLsizei colorArraySizeInElements,
                           const GLsizei textureCoordArraySizeInElements,
                           const uint8_t textureDimentionality=2,
                           const vbo_offset initialOffset=0);
      protected:
        ///////////////////
        //protected constructors
        ///////////////////
        VertexBufferObject(const GLsizei vertexArraySizeInElements,
                           const unsigned int colorSetsNumber,
                           const GLsizei colorArraySizeInElements,
                           const vbo_offset initialOffset,
                           const GLsizei textureSetsNumber);
      public:
        ///////////////////
        //public functions
        ///////////////////
        const GLsizei getVertexArraySizeInElements() const ;
        const GLsizei getVertexArrayOffsetInBytes() const ;
        const GLsizei getColorArraySizeInElements()const ;
        const unsigned int getColorSetsNumber() const ;
        const vbo_offset getColorArrayOffsetInBytes()const;

        const GLsizei getTextureArraySizeInElements(const unsigned int textureCoordSetIndex)const ;
        const unsigned int getTextureSetsNumber() const ;
        inline const  bool has1DTexture()const {
            return getTextureDimentionalityInfo(HAS_1D_TEXTURE);
        }
        inline const  bool has2DTexture()const {
            return getTextureDimentionalityInfo(HAS_2D_TEXTURE);
        }
        inline const  bool has3DTexture()const {
            return getTextureDimentionalityInfo(HAS_3D_TEXTURE);
        }
        const vbo_offset getTextureArrayOffsetInBytes()const ;
        const  unsigned int getBiggestTextureDimentionality()const;
        virtual const GLuint generate(const GLuint reservedID,const GLenum usage)  {}
      protected:
        class Pimpl;
        std::shared_ptr<Pimpl> pimpl;
        ///////////////////
        //constants
        ///////////////////
        const static uint8_t HAS_1D_TEXTURE=1;
        const static uint8_t HAS_2D_TEXTURE=2;
        const static uint8_t HAS_3D_TEXTURE=2*2;
        ///////////////////
        //protected functions
        ///////////////////

        void setTextureArraySizeInElements(const unsigned int textureCoordSetIndex,const GLsizei size );

        inline void setHas1DTexture() {
            setTextureDimentionalityInfo(HAS_1D_TEXTURE);
        }
        inline void setHas2DTexture() {
            setTextureDimentionalityInfo(HAS_2D_TEXTURE);
        }
        inline void setHas3DTexture() {
            setTextureDimentionalityInfo(HAS_3D_TEXTURE);
        }


        const vbo_offset recalculateColorArrayOffset()const;
        const vbo_offset recalculateTextureArrayOffset()const;
      private:
        void setTextureDimentionalityInfo(const uint8_t mask);
        bool getTextureDimentionalityInfo(const uint8_t mask)const;

    };
}

#endif // VERTEX_BUFFER_OBJECT_H
