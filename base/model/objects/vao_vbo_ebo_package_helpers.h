#ifndef VAO_VBO_EBO_PACKAGE_HELPERS_H
#define VAO_VBO_EBO_PACKAGE_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle {
    typedef intptr_t ebo_offset;
    class VaoVboEboPackage;
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

    void bindVertexAttribPointers(
        const VaoVboEboPackage &pack,
        const unsigned int vboIndex,
        const unsigned int colorSetIndex,
        const unsigned int textureSetIndex,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation=-1,
        const GLint textureInputLocation=-1,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);

    const bool bindVertexAttribPointers(
        const VaoVboEboPackage &pack,
        const unsigned int vboIndex,
        const GLuint program,
        const unsigned int colorSetIndex,
        const unsigned int textureSetIndex,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation=nullptr,
        const GLchar *const textureInputLocation=nullptr,
        const GLfloat defaultColorR=0,
        const GLfloat defaultColorG=0,
        const GLfloat defaultColorB=0,
        const GLfloat defaultColorA=1);
}

#endif // VAO_VBO_EBO_PACKAGE_HELPERS_H
