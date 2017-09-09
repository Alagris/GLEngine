#include "vertex_buffer_object_helpers.h"
#include "vertex_buffer_object.h"
#include "assimp_converters.h"
#include <iostream>
namespace gle {
    const GLsizeiptr countVBOTotalSize(const  VertexBufferObject & vbo) {
        return convertColorElementsNumberToBytesNumber(vbo.colorArraySize)
               +convertTextureElementsNumberToBytesNumber(vbo.textureArraySize)
               +convertVertexElementsNumberToBytesNumber(vbo.vertexArraySize);

    }
    const  GLsizei countVBOTotalSizeInElements(const VertexBufferObject &vbo) {
        return vbo.colorArraySize+vbo.textureArraySize+vbo.vertexArraySize;
    }
    void correctVBOOffsets( VertexBufferObject & vbo) {
        vbo.colorArrayOffset=vbo.vertexArrayOffset+convertVertexElementsNumberToBytesNumber(vbo.vertexArraySize);
        vbo.textureArrayOffset=vbo.colorArrayOffset+convertColorElementsNumberToBytesNumber(vbo.colorArraySize);
    }

    constexpr const GLsizei max(const GLsizei a,const GLsizei b,const GLsizei c) {
        return a>b?(a>c?a:c):(b>c?b:c);
    }

    const  GLsizei getVBOLargestSubArraySizeInElements(const VertexBufferObject &vbo) {
        return max(vbo.colorArraySize,vbo.textureArraySize,vbo.vertexArraySize);
    }

    bool hasColorsArray(const VertexBufferObject &vbo) {
        return vbo.colorArraySize!=0;
    }
    bool hasTexturesArray(const VertexBufferObject &vbo) {
        return vbo.textureArraySize!=0;
    }
    bool hasVerticesArray(const VertexBufferObject &vbo) {
        return vbo.vertexArraySize!=0;
    }

    void printDebug(const VertexBufferObject &vbo){
        std::cout<<"Vertices: "<< vbo.vertexArraySize<<"("<<vbo.vertexArrayOffset<<")\n";
        std::cout<<"Colors: "<< vbo.colorArraySize<<"("<<vbo.colorArrayOffset<<")\n";
        std::cout<<"Textures: "<< vbo.textureArraySize<<"("<<vbo.textureArrayOffset<<")\n";
    }
}
