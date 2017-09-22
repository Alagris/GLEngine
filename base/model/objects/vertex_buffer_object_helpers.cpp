#include "vertex_buffer_object_helpers.h"
#include "vertex_buffer_object.h"
#include <iostream>
#include "assimp_converters.h"
#include "assimp_helpers.h"
#include "max.h"
namespace gle {

    namespace {
        const GLsizei sumFirstNTextureSizesUnsafe(const VertexBufferObject &vbo,const unsigned int n) {
            GLsizei out=0;
            for(unsigned int i=0; i<n; i++) {
                out+=vbo.getTextureArraySizeInElements(i);
            }
            return out;
        }


    }


    const  GLsizei getVBOLargestSubArraySizeInElements(const VertexBufferObject &vbo) {
//      Instead of counting everything:
//        GLsizei max = 0;
//        compareMax<GLsizei>(vbo.getColorArraySizeInElements(),max);
//        compareMax<GLsizei>(vbo.getVertexArraySizeInElements(),max);
//
////      How to count texture elements?
////      instead of:
////        for(unsigned int i=0;i<vbo.getTextureSetsNumber();i++){
////            compareMax(vbo.getBiggestTextureDimentionality(i),max);
////        }
////      we can just do:
//        compareMax<GLsizei>(vbo.getBiggestTextureDimentionality()*vbo.getVertexArraySizeInElements(),max);
//        return max;
//      We can just return size of colors (colors have 4 elements per vertex which is max)
        const GLsizei colNum = vbo.getColorArraySizeInElements();
        return colNum==0?vbo.getVertexArraySizeInElements():colNum;
    }

    const GLsizeiptr getTotalSizeOfVBOInBytes(const VertexBufferObject &vbo) {
        return convertVboElementsNumberToBytesNumber(
                   vbo.getVertexArraySizeInElements()+
                   getTotalSizeOfAllColorArraysInElements(vbo)+
                   vbo.getVertexNormalArraySizeInElements()+
                   getTotalSizeOfAllTextureArraysInElements(vbo));
    }

    const bool hasColorsArray(const VertexBufferObject &vbo) {
        return vbo.getColorSetsNumber()!=0;
    }
    const bool hasTexturesArray(const VertexBufferObject &vbo) {
        return vbo.getTextureSetsNumber()!=0;
    }
    const bool hasVerticesArray(const VertexBufferObject &vbo) {
        return vbo.getVertexArraySizeInElements()!=0;
    }
    const bool hasVertexNormalsArray(const VertexBufferObject &vbo) {
        return vbo.getVertexNormalArraySizeInElements()!=0;
    }

    void printDebug(const VertexBufferObject &vbo) {
        std::cout<<"Vertices: "<< vbo.getVertexArraySizeInElements()<<"("<<vbo.getVertexArrayOffsetInBytes()<<")\n";
        std::cout<<"Colors: "<< vbo.getColorArraySizeInElements()<<" * "<<vbo.getColorSetsNumber()<<"("<<vbo.getColorArrayOffsetInBytes()<<")\n";
        std::cout<<"Normals: "<< vbo.getVertexNormalArraySizeInElements()<<"("<<vbo.getVertexNormalArrayOffsetInBytes()<<")\n";
        std::cout<<"Textures: "<< vbo.getTextureSetsNumber()<<"("<<vbo.getTextureArrayOffsetInBytes()<<")\n";
        for(unsigned int i=0; i<vbo.getTextureSetsNumber(); i++) {
            std::cout<<"Texture "<<i<<" size: "<<vbo.getTextureArraySizeInElements(i)<<"\n";
        }
    }

    const unsigned int getTextureDimentionality(const VertexBufferObject &vbo,const unsigned int textureSetIndex) {
        return texture::getDimentionality(vbo.getTextureArraySizeInElements(textureSetIndex),vbo.getVertexArraySizeInElements());
    }
    const GLsizei sumFirstNTextureSizes(const VertexBufferObject &vbo,const unsigned int n) {
        return sumFirstNTextureSizesUnsafe(vbo,n<=vbo.getTextureSetsNumber()?n:vbo.getTextureSetsNumber());
    }
    const GLsizei getTotalSizeOfAllColorArraysInElements(const VertexBufferObject &vbo) {
        return vbo.getColorArraySizeInElements()*vbo.getColorSetsNumber();
    }
    const GLsizei getTotalSizeOfAllTextureArraysInElements(const VertexBufferObject &vbo) {
        return sumFirstNTextureSizes(vbo,vbo.getTextureSetsNumber());
    }

    /**Returns offset pointing right at the first byte after VBO*/
    const vbo_offset getVBOEndingOffset(const VertexBufferObject &vbo) {
        return vbo.getTextureArrayOffsetInBytes()+convertVboElementsNumberToBytesNumber(getTotalSizeOfAllTextureArraysInElements(vbo));
    }

    const vbo_offset getTextureArrayOffsetInBytes(const VertexBufferObject &vbo,const unsigned int textureCoordSetIndex) {
        return vbo.getTextureArrayOffsetInBytes()+sumFirstNTextureSizes(vbo,textureCoordSetIndex);
    }

    const vbo_offset getColorArrayOffsetInBytes(const VertexBufferObject& vbo,const unsigned int colorSetIndex) {
        return vbo.getColorArrayOffsetInBytes()+convertVboElementsNumberToBytesNumber(colorSetIndex*vbo.getColorArraySizeInElements());
    }


    const bool validateDimentionality(const VertexBufferObject &vbo,const unsigned int textureCoordSetIndex) {
        const unsigned int d=getTextureDimentionality(vbo,textureCoordSetIndex);
        return d>0&&d<4;
    }
    /**returns index of invalid texture set or -1 if all sets are valid*/
    const int validateDimentionality(const VertexBufferObject &vbo) {
        for(unsigned int i=0; i<vbo.getTextureSetsNumber(); i++) {
            if(!validateDimentionality(vbo,i)) {
                return i;
            }
        }
        return -1;
    }
}
