#include "vertex_buffer_object.h"
#include "assimp_counters.h"
#include "assimp_converters.h"
namespace gle {
    VertexBufferObject::VertexBufferObject():
        vertexArraySize(0),
        vertexArrayOffset(0),
        colorArraySize(0),
        colorArrayOffset(0),
        textureArraySize(0),
        textureArrayOffset(0) {}

    VertexBufferObject::VertexBufferObject(const aiMesh*const mesh):VertexBufferObject(mesh,0){}

    VertexBufferObject::VertexBufferObject(const aiMesh*const mesh,const vbo_offset initialOffset):
        vertexArraySize(convertVerticesNumberToElementsNumber(countVerticesInMesh(mesh))),
        vertexArrayOffset(initialOffset),
        colorArraySize(0),
        colorArrayOffset(0),
        textureArraySize(0),
        textureArrayOffset(0)
    {

        if(mesh->HasVertexColors(0)) {
            colorArrayOffset=vertexArrayOffset+convertVertexElementsNumberToBytesNumber(vertexArraySize);
            colorArraySize=convertColorVerticesNumberToElementsNumber(countColorVerticesInMesh(mesh));
        }
        if(mesh->HasTextureCoords(0)) {
            textureArrayOffset=vertexArrayOffset+convertVertexElementsNumberToBytesNumber(vertexArraySize)+convertColorElementsNumberToBytesNumber(colorArraySize);
            textureArraySize=convertTextureVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
        }

    }
}
