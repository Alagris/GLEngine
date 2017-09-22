#ifndef ASSIMP_BUFFER_GENERATORS_H
#define ASSIMP_BUFFER_GENERATORS_H
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
    class ElementBufferObject;
    class VertexBufferObject;

    namespace index {
        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const ElementBufferObject&targetEBO,const unsigned int meshIndex);
        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID);
//        const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage);
    }
    namespace vertex {
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage);
        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
        const GLuint generateVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID);
    }
    namespace color {
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID);
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage);
    }
    namespace normal {

    }
    namespace texture {
//        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
        const GLuint generateVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
    }









//    const GLuint generateTextures1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateTextures2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);
//    const GLuint generateTextures3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID);






//    const GLuint generateTextures1DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//    const GLuint generateTextures2DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);
//    const GLuint generateTextures3DVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage);





//    const GLuint generateColorsVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
//    const GLuint generateVerticesVBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
//    const GLuint generateTexturesVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const GLuint bufferID,const VertexBufferObject&targetVBO);
//    const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const GLuint bufferID,const ElementBufferObject&targetEBO,const unsigned int meshIndex);


//    const GLuint generateColorsVBO_glb(const aiMesh*const mesh,const unsigned int colorSetIndex,const GLenum usage,const VertexBufferObject&targetVBO);
//    const GLuint generateVerticesVBO_glb(const aiMesh*const mesh,const GLenum usage,const VertexBufferObject&targetVBO);
//    const GLuint generateTexturesVBO_glb(const aiMesh*const mesh,const unsigned int textureSetIndex,const GLenum usage,const VertexBufferObject&targetVBO);
//    const GLuint generateEBO_glb(const aiMesh*const mesh,const GLenum usage,const ElementBufferObject&targetEBO,const unsigned int meshIndex);

}

#endif // ASSIMP_BUFFER_GENERATORS_H
