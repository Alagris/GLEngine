#ifndef ASSIMP_BUFFER_GENERATORS_H
#define ASSIMP_BUFFER_GENERATORS_H
#include <GLFW/glfw3.h>
#include <assimp/mesh.h>
namespace gle {

    const GLuint generateColorsVBO(const aiMesh*const mesh,const GLenum usage);
    const GLuint generateVerticesVBO(const aiMesh*const mesh,const GLenum usage);
    const GLuint generateTexturesVBO(const aiMesh*const mesh,const GLenum usage);
    const GLuint generateEBO(const aiMesh*const mesh,const GLenum usage);

    const GLuint generateEBO(const aiMesh*const mesh,const GLenum usage,const GLuint eboBufferID);


}

#endif // ASSIMP_BUFFER_GENERATORS_H
