#ifndef ASSIMP_SUBBUFFER_GENERATORS_H
#define ASSIMP_SUBBUFFER_GENERATORS_H
#include <assimp/mesh.h>
namespace gle {
    class VertexBufferObject;
    class ElementBufferObject;

    void generateColorsSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo);
    void generateVerticesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const VertexBufferObject & targetVbo);
    void generateTextures3DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
    void generateTextures2DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
    void generateTextures1DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
    void generateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
//    /**Returns size (in bytes) of generated sub EBO*/
//    const GLsizeiptr generateIndicesSubEBO(const aiMesh*const mesh,GLuint *const buffer,const unsigned int numIndicesPerFace=3,const intptr_t offsetInBytes=0);
    const void generateIndicesSubEBO(const aiMesh*const mesh,GLuint *const buffer,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace=3);




    void generateColorsSubVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo);
    void generateVerticesSubVBO(const aiMesh*const mesh,const VertexBufferObject & targetVbo);
    void generateTextures3DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
    void generateTextures2DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
    void generateTextures1DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
    void generateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
//    /**Returns size (in bytes) of generated sub EBO*/
//    const GLsizeiptr generateIndicesSubEBO(const aiMesh*const mesh,const unsigned int numIndicesPerFace=3,const intptr_t offsetInBytes=0);
    const void generateIndicesSubEBO(const aiMesh*const mesh,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace=3) ;
}

#endif // ASSIMP_SUBBUFFER_GENERATORS_H
