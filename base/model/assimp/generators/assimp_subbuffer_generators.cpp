#include <GL/glew.h>
#include "assimp_subbuffer_generators.h"
#include "vertex_buffer_object.h"
#include "assimp_converters.h"
#include "vertex_buffer_object.h"
#include "assimp_copy_data.h"
#include <memory>
#include "vertex_buffer_object_helpers.h"
#include "element_buffer_object.h"



namespace gle {

    void generateColorsSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo) {
        copyColorVertices(mesh,colorSetIndex,buffer);
        glBufferSubData(GL_ARRAY_BUFFER,
                        getColorArrayOffsetInBytes(targetVbo,colorSetIndex),
                        convertColorElementsNumberToBytesNumber(targetVbo.getColorArraySizeInElements()),
                        static_cast<void*>(buffer));
    }

    void  generateVerticesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const VertexBufferObject & targetVbo) {
        copyVertices(mesh,buffer);
        glBufferSubData(GL_ARRAY_BUFFER,
                        targetVbo.getVertexArrayOffsetInBytes(),
                        convertVertexElementsNumberToBytesNumber(targetVbo.getVertexArraySizeInElements()),
                        static_cast<void*>(buffer));
    }

    namespace {
        typedef const unsigned int (*copyTextureVerticesFunc)(const aiMesh*const mesh,const unsigned int textureSetIndex,GLfloat *const buffer);
        typedef const unsigned int (*convertTextureElementsNumberToBytesNumberFunc)(const unsigned int elemNum);

        template<copyTextureVerticesFunc f1,convertTextureElementsNumberToBytesNumberFunc f2>
        inline void genericGenerateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
            f1(mesh,textureSetIndex,buffer);
            glBufferSubData(GL_ARRAY_BUFFER,
                            getTextureArrayOffsetInBytes(targetVbo,textureSetIndex),
                            f2(targetVbo.getTextureArraySizeInElements(textureSetIndex)),
                            static_cast<void*>(buffer));
        }
    }

    void  generateTextures3DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        genericGenerateTexturesSubVBO<copyTexture3DVertices,convertTexture3DElementsNumberToBytesNumber>(mesh,buffer,textureSetIndex,targetVbo);
    }

    void  generateTextures2DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        genericGenerateTexturesSubVBO<copyTexture2DVertices,convertTexture2DElementsNumberToBytesNumber>(mesh,buffer,textureSetIndex,targetVbo);
    }

    void  generateTextures1DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        genericGenerateTexturesSubVBO<copyTexture1DVertices,convertTexture1DElementsNumberToBytesNumber>(mesh,buffer,textureSetIndex,targetVbo);
    }

    void  generateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        if(mesh->mNumUVComponents[textureSetIndex]==3)generateTextures3DSubVBO(mesh,buffer,textureSetIndex,targetVbo);
        if(mesh->mNumUVComponents[textureSetIndex]==2)generateTextures2DSubVBO(mesh,buffer,textureSetIndex,targetVbo);
        if(mesh->mNumUVComponents[textureSetIndex]==1)generateTextures1DSubVBO(mesh,buffer,textureSetIndex,targetVbo);
    }

//    const GLsizeiptr generateIndicesSubEBO(const aiMesh*const mesh,GLuint *const buffer,const unsigned int numIndicesPerFace,const intptr_t offsetInBytes) {
//        const unsigned int sizeInElements=copyIndices(mesh,numIndicesPerFace,buffer);
//        const GLsizeiptr sizeInBytes=convertIndexElementsNumberToBytesNumber(sizeInElements);
//        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,
//                        offsetInBytes,
//                        sizeInBytes,
//                        static_cast<void*>(buffer));
//        return sizeInBytes;
//    }

    const void generateIndicesSubEBO(const aiMesh*const mesh,GLuint *const buffer,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace) {
        copyIndices(mesh,numIndicesPerFace,buffer);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,
                        targetEBO.getElementArrayOffsetInBytes(meshIndex),
                        convertIndexElementsNumberToBytesNumber(targetEBO.getElementArraySizeInElements(meshIndex)),
                        static_cast<void*>(buffer));
    }










    void generateColorsSubVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo) {
        const unsigned int size=targetVbo.getColorArraySizeInElements();//countColorElementsInMesh(mesh);
        if(size==0)return;
        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
        generateColorsSubVBO(mesh,bufPtr.get(),colorSetIndex,targetVbo);
    }

    void  generateVerticesSubVBO(const aiMesh*const mesh,const VertexBufferObject & targetVbo) {
        const unsigned int size=targetVbo.getVertexArraySizeInElements();//countVerticesElementsInMesh(mesh);//
        if(size==0)return;
        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
        generateVerticesSubVBO(mesh,bufPtr.get(),targetVbo);
    }



    namespace {
        typedef void (*generateTexturesSubVBOFunc)(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo);
        typedef const unsigned int (*convertTextureVerticesNumberToElementsNumberFunc)(const unsigned int verticesNum);

        template<generateTexturesSubVBOFunc f1,convertTextureVerticesNumberToElementsNumberFunc f2>
        inline void genericGenerateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
            const unsigned int size=targetVbo.getTextureArraySizeInElements(textureSetIndex);//f2(countTextureVerticesInMesh(mesh));
            if(size==0)return;
            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
            f1(mesh,bufPtr.get(),textureSetIndex,targetVbo);
        }
    }

    void  generateTextures3DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        genericGenerateTexturesSubVBO<generateTextures3DSubVBO,convertTexture3DVerticesNumberToElementsNumber>(mesh,textureSetIndex,targetVbo);
    }

    void  generateTextures2DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        genericGenerateTexturesSubVBO<generateTextures2DSubVBO,convertTexture2DVerticesNumberToElementsNumber>(mesh,textureSetIndex,targetVbo);
    }

    void  generateTextures1DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        genericGenerateTexturesSubVBO<generateTextures1DSubVBO,convertTexture1DVerticesNumberToElementsNumber>(mesh,textureSetIndex,targetVbo);
    }

    void  generateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo) {
        if(mesh->mNumUVComponents[textureSetIndex]==3)generateTextures3DSubVBO(mesh,textureSetIndex,targetVbo);
        if(mesh->mNumUVComponents[textureSetIndex]==2)generateTextures2DSubVBO(mesh,textureSetIndex,targetVbo);
        if(mesh->mNumUVComponents[textureSetIndex]==1)generateTextures1DSubVBO(mesh,textureSetIndex,targetVbo);
    }


//    const GLsizeiptr generateIndicesSubEBO(const aiMesh*const mesh,const unsigned int numIndicesPerFace,const intptr_t offsetInBytes) {
//        const unsigned int size=countIndicesElementsInMesh(mesh);
//        if(size==0)return 0;
//        std::unique_ptr<GLuint[]> bufPtr(new GLuint[size]);
//        return generateIndicesSubEBO(mesh,bufPtr.get(),numIndicesPerFace,offsetInBytes);
//    }

    const void generateIndicesSubEBO(const aiMesh*const mesh,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace) {
        const unsigned int size=targetEBO.getElementArraySizeInElements(meshIndex);
        if(size==0)return;
        std::unique_ptr<GLuint[]> bufPtr(new GLuint[size]);
        generateIndicesSubEBO(mesh,bufPtr.get(),meshIndex,targetEBO,numIndicesPerFace);
    }

}
