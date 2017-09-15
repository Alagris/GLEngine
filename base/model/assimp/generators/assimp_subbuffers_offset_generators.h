#ifndef ASSIMP_SUBBUFFERS_OFFSET_GENERATORS_H
#define ASSIMP_SUBBUFFERS_OFFSET_GENERATORS_H
#include <GLFW/glfw3.h>
#include <assimp/mesh.h>
namespace gle {
    class VertexBufferObject;
    class ElementBufferObject;

//    void generateColorsSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateVerticesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTextures3DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTextures2DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTextures1DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
    const void generateIndicesSubEBO(const aiMesh*const mesh,GLuint *const buffer,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace,unsigned int offset);
    const void generateIndicesSubEBO(
        const aiMesh*const mesh,
        GLuint *const buffer,
        const unsigned int meshIndex,
        const ElementBufferObject&targetEBO,
        const unsigned int numIndicesPerFace,
        const VertexBufferObject & correspondingVBO);




//    void generateColorsSubVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateVerticesSubVBO(const aiMesh*const mesh,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTextures3DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTextures2DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTextures1DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//    void generateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
    const void generateIndicesSubEBO(const aiMesh*const mesh,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace,unsigned int offset) ;
    const void generateIndicesSubEBO(
        const aiMesh*const mesh,
        const unsigned int meshIndex,
        const ElementBufferObject&targetEBO,
        const unsigned int numIndicesPerFace,
        const VertexBufferObject & correspondingVBO);
}

#endif // ASSIMP_SUBBUFFERS_OFFSET_GENERATORS_H
