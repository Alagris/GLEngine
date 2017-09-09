#ifndef ASSIMP_SUBBUFFER_GENERATORS_H
#define ASSIMP_SUBBUFFER_GENERATORS_H
#include <assimp/mesh.h>
namespace gle{
    struct VertexBufferObject;
    void generateColorsSubVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo);
    void generateVerticesSubVBO(const aiMesh*const mesh,const VertexBufferObject & targetVbo);
    void generateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);

     void  generateVerticesColorsAndTexturesSubVBO(
        const aiMesh*const mesh,
        const unsigned int colorSetIndex,
        const unsigned int textureSetIndex,
        const VertexBufferObject & targetVbo,
        const GLuint vboID=0,
        const GLenum usage=GL_STATIC_DRAW);
}

#endif // ASSIMP_SUBBUFFER_GENERATORS_H
