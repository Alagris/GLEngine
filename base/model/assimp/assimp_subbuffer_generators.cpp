#include <GL/glew.h>
#include "assimp_subbuffer_generators.h"
#include "vertex_buffer_object.h"
#include "assimp_converters.h"
#include "assimp_counters.h"
#include "assimp_copy_data.h"
#include <iostream>
#include "vertex_buffer_object_helpers.h"
namespace gle {
    namespace {
        void generateColorsSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo) {
            copyColorVertices(mesh,colorSetIndex,buffer);
            glBufferSubData(GL_ARRAY_BUFFER, targetVbo.colorArrayOffset, convertColorElementsNumberToBytesNumber(targetVbo.colorArraySize), (void*)buffer);
        }
        void  generateVerticesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const VertexBufferObject & targetVbo) {
            copyVertices(mesh,buffer);
            glBufferSubData(GL_ARRAY_BUFFER, targetVbo.vertexArrayOffset, convertVertexElementsNumberToBytesNumber(targetVbo.vertexArraySize), (void*)buffer);
        }
        void  generateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
            copyTextureVertices(mesh,textureSetIndex,buffer);
            glBufferSubData(GL_ARRAY_BUFFER, targetVbo.textureArrayOffset, convertTextureElementsNumberToBytesNumber(targetVbo.textureArraySize), (void*)buffer);
        }


        void copyBuffers(const aiMesh*const mesh,
                         const unsigned int colorSetIndex,
                         const unsigned int textureSetIndex,
                         bool copyColors,
                         bool copyTextures,
                         GLfloat *const buffer,
                         const VertexBufferObject & targetVbo) {
            generateVerticesSubVBO(mesh,buffer,targetVbo);
            if(copyColors) {
                generateColorsSubVBO(mesh,buffer,colorSetIndex,targetVbo);
            }
            if(copyTextures) {
                generateTexturesSubVBO(mesh,buffer,textureSetIndex,targetVbo);
            }
        }
    }
    void generateColorsSubVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo) {
        const unsigned int size=convertColorVerticesNumberToElementsNumber(mesh->mNumVertices);
        if(size==0)return;
        GLfloat * buffer =new GLfloat[size];
        generateColorsSubVBO(mesh,buffer,colorSetIndex,targetVbo);
        delete[] buffer;
    }
    void  generateVerticesSubVBO(const aiMesh*const mesh,const VertexBufferObject & targetVbo) {
        const unsigned int size=convertVerticesNumberToElementsNumber(mesh->mNumVertices);
        if(size==0)return;
        GLfloat * buffer =new GLfloat[size];
        generateVerticesSubVBO(mesh,buffer,targetVbo);
        delete[] buffer;
    }
    void  generateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        const unsigned int size=convertTextureVerticesNumberToElementsNumber(mesh->mNumVertices);
        if(size==0)return;
        GLfloat * buffer =new GLfloat[size];
        generateTexturesSubVBO(mesh,buffer,textureSetIndex,targetVbo);
        delete[] buffer;
    }

    void  generateVerticesColorsAndTexturesSubVBO(
        const aiMesh*const mesh,
        const unsigned int colorSetIndex,
        const unsigned int textureSetIndex,
        const VertexBufferObject & targetVbo,
        const GLuint vboID,
        const GLenum usage)
    {
        GLfloat *const buffer =new GLfloat[getVBOLargestSubArraySizeInElements(targetVbo)];
        if(vboID!=0) {
            glBufferData(GL_ARRAY_BUFFER,countVBOTotalSize(targetVbo),nullptr,usage);
        }
        copyBuffers(mesh,colorSetIndex,textureSetIndex,hasColorsArray(targetVbo),hasTexturesArray(targetVbo),buffer,targetVbo);
        delete[] buffer;
    }




}
