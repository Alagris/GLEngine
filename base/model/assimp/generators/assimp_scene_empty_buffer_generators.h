#ifndef ASSIMP_SCENE_EMPTY_BUFFER_GENERATORS_H
#define ASSIMP_SCENE_EMPTY_BUFFER_GENERATORS_H

#include <GLFW/glfw3.h>
#include <assimp/scene.h>
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
    const GLuint generateTexColVerAllSetsEmptyVBO_glb(const aiScene*const scene,const GLenum usage,const GLuint bufferID) ;
    const GLuint generateColorsAllSetsEmptyVBO_glb(const aiScene*const scene,const GLenum usage,const GLuint bufferID) ;
    const GLuint generateTextureAllSetsEmptyVBO_glb(const aiScene*const scene,const GLenum usage,const GLuint bufferID) ;
    const GLuint generateColorsEmptyVBO_glb(const aiScene*const scene,const unsigned int colorSetIndex,const GLenum usage,const GLuint bufferID);
    const GLuint generateVerticesEmptyVBO_glb(const aiScene*const scene,const GLenum usage,const GLuint bufferID);
    const GLuint generateEmptyEBO_glb(const aiScene*const scene,const GLenum usage,const GLuint bufferID);


    const GLuint generateTexColVerAllSetsEmptyVBO_glb(const aiScene*const scene,const GLenum usage) ;
    const GLuint generateColorsAllSetsEmptyVBO_glb(const aiScene*const scene,const GLenum usage) ;
    const GLuint generateTextureAllSetsEmptyVBO_glb(const aiScene*const scene,const GLenum usage) ;
    const GLuint generateColorsEmptyVBO_glb(const aiScene*const scene,const unsigned int colorSetIndex,const GLenum usage);
    const GLuint generateVerticesEmptyVBO_glb(const aiScene*const scene,const GLenum usage);
    const GLuint generateEmptyEBO_glb(const aiScene*const scene,const GLenum usage);




}

#endif // ASSIMP_SCENE_EMPTY_BUFFER_GENERATORS_H
