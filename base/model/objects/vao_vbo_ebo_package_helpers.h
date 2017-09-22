#ifndef VAO_VBO_EBO_PACKAGE_HELPERS_H
#define VAO_VBO_EBO_PACKAGE_HELPERS_H
#include <GLFW/glfw3.h>
#include "offset_types.h"
namespace gle {
    class VaoVboEboPackage;
    class VertexBufferObject;
    const unsigned int getSize(const VaoVboEboPackage & pack) ;
    const bool isEmpty(const VaoVboEboPackage & pack) ;
    const GLuint getVAO_ID(const VaoVboEboPackage & pack) ;
    const bool hasVAO_ID(const VaoVboEboPackage & pack) ;
    const GLuint getVBO_ID(const VaoVboEboPackage & pack) ;
    const bool hasVBO_ID(const VaoVboEboPackage & pack) ;
    const GLuint getEBO_ID(const VaoVboEboPackage & pack) ;
    const bool hasEBO_ID(const VaoVboEboPackage & pack) ;
    const bool isValid(const VaoVboEboPackage & pack);
    const GLsizei * const getEBOArraySizesPtr(const VaoVboEboPackage & pack);
    const GLenum getEBOType(const VaoVboEboPackage & pack);
    const ebo_offset * const getEBOArrayOffsetsPtr(const VaoVboEboPackage & pack);
    void bindVAO(const VaoVboEboPackage & pack);
    void bindVBO(const VaoVboEboPackage & pack);
    void bindEBO(const VaoVboEboPackage & pack);
    const GLsizei getElementArraySizeInElements(const VaoVboEboPackage & pack,unsigned int index);
    const ebo_offset getElementArrayOffsetInBytes(const VaoVboEboPackage & pack,unsigned int index);
    void renderAllEBO(const VaoVboEboPackage & pack,const GLenum mode) ;
    void renderEBO(const VaoVboEboPackage & pack,const GLenum mode,unsigned int index);
    const VertexBufferObject & getVBO(const VaoVboEboPackage & pack,unsigned int index);
    bool debugVboTextureDimentionality(const VaoVboEboPackage &pack);
    const vbo_offset getEndingOffsetOfAllVBOs(const VaoVboEboPackage &pack) ;
    const GLsizei getLargestSubArraySizeOfAllVBOsInElements(const VaoVboEboPackage &pack);
}

#endif // VAO_VBO_EBO_PACKAGE_HELPERS_H
