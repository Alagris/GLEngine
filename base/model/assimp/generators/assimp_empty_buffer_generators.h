#ifndef ASSIMP_EMPTY_BUFFER_GENERATORS_H
#define ASSIMP_EMPTY_BUFFER_GENERATORS_H
#include <GLFW/glfw3.h>
#include <assimp/mesh.h>
namespace gle {

    /////////////////////////////////////////
    //         IMPORTANT IMPORTANT         //
    /////////////////////////////////////////
    /////////////////////////////////////////
    /////////////////////////////////////////
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Every function that ends with _glb
    //chnages OpenGL state by binding something
    //and not unbinding it
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /////////////////////////////////////////
    /////////////////////////////////////////
    /////////////////////////////////////////

//     class ElementBufferObject;
//    class VertexBufferObject;

    namespace index {
//        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const ElementBufferObject&targetEBO,const unsigned int meshIndex);
        const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID);
//        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage);
    }
    namespace vertex {
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage);
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID);
    }
    namespace color {
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID);
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage);
    }
    namespace normal {

    }
    namespace texture {
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
        const GLuint generateEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
    }


//    const GLuint generateColorsEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateVerticesEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID);
//    const GLuint generateTexturesEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateTexturesEmpty1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateTexturesEmpty2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateTexturesEmpty3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID);
//
//
//    const GLuint generateColorsEmptyVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage);
//    const GLuint generateVerticesEmptyVBO_glb(const aiMesh*const mesh,const GLenum usage);
//    const GLuint generateTexturesEmptyVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//    const GLuint generateTexturesEmpty1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//    const GLuint generateTexturesEmpty2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//    const GLuint generateTexturesEmpty3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//    const GLuint generateEmptyEBO_glb(const aiMesh*const mesh,const GLenum usage);




}
#endif // ASSIMP_EMPTY_BUFFER_GENERATORS_H
