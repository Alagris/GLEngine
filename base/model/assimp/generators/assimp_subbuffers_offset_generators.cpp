//#include "GL/glew.h"
#include "assimp_subbuffers_offset_generators.h"
//#include "vertex_buffer_object.h"
//#include "assimp_converters.h"
//#include "vertex_buffer_object.h"
//#include "assimp_copy_offset_data.h"
//#include <memory>
//#include "vertex_buffer_object_helpers.h"
//#include "element_buffer_object.h"



namespace gle {

//    void generateColorsSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        copyColorVertices(mesh,colorSetIndex,buffer,offset);
//        glBufferSubData(GL_ARRAY_BUFFER,
//                        getColorArrayOffsetInBytes(targetVbo,colorSetIndex),
//                        convertColorElementsNumberToBytesNumber(targetVbo.getColorArraySizeInElements()),
//                        static_cast<void*>(buffer));
//    }
//
//    void  generateVerticesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const VertexBufferObject & targetVbo,unsigned int offset) {
//        copyVertices(mesh,buffer,offset);
//        glBufferSubData(GL_ARRAY_BUFFER,
//                        targetVbo.getVertexArrayOffsetInBytes(),
//                        convertVertexElementsNumberToBytesNumber(targetVbo.getVertexArraySizeInElements()),
//                        static_cast<void*>(buffer));
//    }
//
//    namespace {
//        typedef const unsigned int (*copyTextureVerticesFunc)(const aiMesh*const mesh,const unsigned int textureSetIndex,GLfloat *const buffer,unsigned int offset);
//        typedef const unsigned int (*convertTextureElementsNumberToBytesNumberFunc)(const unsigned int elemNum);
//
//        template<copyTextureVerticesFunc f1,convertTextureElementsNumberToBytesNumberFunc f2>
//        inline void genericGenerateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//            f1(mesh,textureSetIndex,buffer,offset);
//            glBufferSubData(GL_ARRAY_BUFFER,
//                            getTextureArrayOffsetInBytes(targetVbo,textureSetIndex),
//                            f2(targetVbo.getTextureArraySizeInElements(textureSetIndex)),
//                            static_cast<void*>(buffer));
//        }
//    }
//
//    void  generateTextures3DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        genericGenerateTexturesSubVBO<copyTexture3DVertices,convertTexture3DElementsNumberToBytesNumber>(mesh,buffer,textureSetIndex,targetVbo,offset);
//    }
//
//    void  generateTextures2DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        genericGenerateTexturesSubVBO<copyTexture2DVertices,convertTexture2DElementsNumberToBytesNumber>(mesh,buffer,textureSetIndex,targetVbo,offset);
//    }
//
//    void  generateTextures1DSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        genericGenerateTexturesSubVBO<copyTexture1DVertices,convertTexture1DElementsNumberToBytesNumber>(mesh,buffer,textureSetIndex,targetVbo,offset);
//    }
//
//    void  generateTexturesSubVBO(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        if(mesh->mNumUVComponents[textureSetIndex]==3)generateTextures3DSubVBO(mesh,buffer,textureSetIndex,targetVbo,offset);
//        if(mesh->mNumUVComponents[textureSetIndex]==2)generateTextures2DSubVBO(mesh,buffer,textureSetIndex,targetVbo,offset);
//        if(mesh->mNumUVComponents[textureSetIndex]==1)generateTextures1DSubVBO(mesh,buffer,textureSetIndex,targetVbo,offset);
//    }

//    const void generateIndicesSubEBO(const aiMesh*const mesh,GLuint *const buffer,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace,unsigned int offset) {
//        copyIndices(mesh,numIndicesPerFace,buffer,offset);
//        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,
//                        targetEBO.getElementArrayOffsetInBytes(meshIndex),
//                        convertIndexElementsNumberToBytesNumber(targetEBO.getElementArraySizeInElements(meshIndex)),
//                        static_cast<void*>(buffer));
//    }
//    const void generateIndicesSubEBO(
//        const aiMesh*const mesh,
//        GLuint *const buffer,
//        const unsigned int meshIndex,
//        const ElementBufferObject&targetEBO,
//        const unsigned int numIndicesPerFace,
//        const VertexBufferObject & correspondingVBO)
//    {
//        generateIndicesSubEBO( mesh, buffer, meshIndex,targetEBO, numIndicesPerFace, correspondingVBO.getVertexArrayOffsetInBytes());
//    }










//    void generateColorsSubVBO(const aiMesh*const mesh,const unsigned int colorSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        const unsigned int size=targetVbo.getColorArraySizeInElements();//countColorElementsInMesh(mesh);
//        if(size==0)return;
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//        generateColorsSubVBO(mesh,bufPtr.get(),colorSetIndex,targetVbo,offset);
//    }
//
//    void  generateVerticesSubVBO(const aiMesh*const mesh,const VertexBufferObject & targetVbo,unsigned int offset) {
//        const unsigned int size=targetVbo.getVertexArraySizeInElements();//countVerticesElementsInMesh(mesh);//
//        if(size==0)return;
//        std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//        generateVerticesSubVBO(mesh,bufPtr.get(),targetVbo,offset);
//    }
//
//
//
//    namespace {
//        typedef void (*generateTexturesSubVBOFunc)(const aiMesh*const mesh,GLfloat *const buffer,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset);
//        typedef const unsigned int (*convertTextureVerticesNumberToElementsNumberFunc)(const unsigned int verticesNum);
//
//        template<generateTexturesSubVBOFunc f1,convertTextureVerticesNumberToElementsNumberFunc f2>
//        inline void genericGenerateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//            const unsigned int size=targetVbo.getTextureArraySizeInElements(textureSetIndex);//f2(countTextureVerticesInMesh(mesh));
//            if(size==0)return;
//            std::unique_ptr<GLfloat[]> bufPtr(new GLfloat[size]);
//            f1(mesh,bufPtr.get(),textureSetIndex,targetVbo,offset);
//        }
//    }
//
//    void  generateTextures3DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        genericGenerateTexturesSubVBO<generateTextures3DSubVBO,convertTexture3DVerticesNumberToElementsNumber>(mesh,textureSetIndex,targetVbo,offset);
//    }
//
//    void  generateTextures2DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        genericGenerateTexturesSubVBO<generateTextures2DSubVBO,convertTexture2DVerticesNumberToElementsNumber>(mesh,textureSetIndex,targetVbo,offset);
//    }
//
//    void  generateTextures1DSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        genericGenerateTexturesSubVBO<generateTextures1DSubVBO,convertTexture1DVerticesNumberToElementsNumber>(mesh,textureSetIndex,targetVbo,offset);
//    }
//
//    void  generateTexturesSubVBO(const aiMesh*const mesh,const unsigned int textureSetIndex,const VertexBufferObject & targetVbo,unsigned int offset) {
//        if(mesh->mNumUVComponents[textureSetIndex]==3)generateTextures3DSubVBO(mesh,textureSetIndex,targetVbo,offset);
//        if(mesh->mNumUVComponents[textureSetIndex]==2)generateTextures2DSubVBO(mesh,textureSetIndex,targetVbo,offset);
//        if(mesh->mNumUVComponents[textureSetIndex]==1)generateTextures1DSubVBO(mesh,textureSetIndex,targetVbo,offset);
//    }


//    const void generateIndicesSubEBO(const aiMesh*const mesh,const unsigned int meshIndex,const ElementBufferObject&targetEBO,const unsigned int numIndicesPerFace,unsigned int offset) {
//        const unsigned int size=targetEBO.getElementArraySizeInElements(meshIndex);
//        if(size==0)return;
//        std::unique_ptr<GLuint[]> bufPtr(new GLuint[size]);
//        generateIndicesSubEBO(mesh,bufPtr.get(),meshIndex,targetEBO,numIndicesPerFace,offset);
//    }
//    const void generateIndicesSubEBO(
//        const aiMesh*const mesh,
//        const unsigned int meshIndex,
//        const ElementBufferObject&targetEBO,
//        const unsigned int numIndicesPerFace,
//        const VertexBufferObject & correspondingVBO)
//    {
//        generateIndicesSubEBO( mesh, meshIndex,targetEBO,numIndicesPerFace,correspondingVBO.getVertexArrayOffsetInBytes()) ;
//    }
}
