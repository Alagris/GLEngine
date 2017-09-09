#include <GL/glew.h>
#include "vertex_attrib_pointer_setup.h"
#include "vertex_buffer_object.h"
#include "vertex_attrib_helpers.h"
#include "assimp_constants.h"
namespace gle {


    bool bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const GLuint program,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA)
    {
        const GLint vertexInputLoc = vertexInputLocation==nullptr?-1:glGetAttribLocation(program,vertexInputLocation);
        if(vertexInputLoc<0)return false;
        const GLint colorInputLoc= colorInputLocation==nullptr?-1:glGetAttribLocation(program,colorInputLocation);
        const GLint textureInputLoc= textureInputLocation==nullptr?-1:glGetAttribLocation(program,textureInputLocation);
        bindVertexAttribPointers(vbo,(GLuint)vertexInputLoc,colorInputLoc,textureInputLoc,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
        return true;

    }


    void bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation,
        const GLint textureInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA) {

        glVertexAttribPointer(vertexInputLocation, SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.vertexArrayOffset);
        glEnableVertexAttribArray(vertexInputLocation);

        if(colorInputLocation>-1) {
            const GLuint index=(GLuint)colorInputLocation;
            if(vbo.colorArraySize>0) {

                glVertexAttribPointer(index, SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.colorArrayOffset);
                glEnableVertexAttribArray(index);
            } else {
                glVertexAttrib<SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS,float>(index,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
            }

        }
        if(textureInputLocation>-1) {
            GLuint index=(GLuint)textureInputLocation;
            if(vbo.textureArraySize>0) {
                glVertexAttribPointer(index, SIZE_OF_ASSIMP_TEXTURE_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.textureArrayOffset);
                glEnableVertexAttribArray(index);
            }
        }
    }
}
