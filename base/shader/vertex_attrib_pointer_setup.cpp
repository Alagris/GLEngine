#include <GL/glew.h>
#include "vertex_attrib_pointer_setup.h"
#include "vertex_buffer_object.h"
#include "vertex_attrib_helpers.h"
#include "assimp_constants.h"
#include "vertex_buffer_object_helpers.h"
namespace gle {


    const bool findInputLocations(
        const GLuint program,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        GLint & vertexInputLoc,
        GLint & colorInputLoc,
        GLint & textureInputLoc)
    {
        vertexInputLoc = vertexInputLocation==nullptr?-1:glGetAttribLocation(program,vertexInputLocation);
        if(vertexInputLoc<0)return false;
        colorInputLoc= colorInputLocation==nullptr?-1:glGetAttribLocation(program,colorInputLocation);
        textureInputLoc= textureInputLocation==nullptr?-1:glGetAttribLocation(program,textureInputLocation);
        return true;
    }

    const bool bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const GLuint program,
        const int colorSetIndex,
        const int textureSetIndex,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA)
    {
        GLint vertexInputLoc=-1;
        GLint colorInputLoc=-1;
        GLint textureInputLoc=-1;
        if(findInputLocations(program,vertexInputLocation,colorInputLocation,textureInputLocation,vertexInputLoc,colorInputLoc,textureInputLoc)) {
            bindVertexAttribPointers(vbo,colorSetIndex,textureSetIndex,(GLuint)vertexInputLoc,colorInputLoc,textureInputLoc,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
            return true;
        }
        return false;
    }


    void bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const int colorSetIndex,
        const int textureSetIndex,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation,
        const GLint textureInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA) {

        glVertexAttribPointer(vertexInputLocation, SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.getVertexArrayOffsetInBytes());
        glEnableVertexAttribArray(vertexInputLocation);

        if(colorInputLocation>-1) {
            const GLuint index=(GLuint)colorInputLocation;
            if(colorSetIndex>-1 && vbo.getColorArraySizeInElements()>0) {
                glVertexAttribPointer(index, SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)getColorArrayOffsetInBytes(vbo,colorSetIndex));
                glEnableVertexAttribArray(index);
            } else {
                glVertexAttrib<SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS,float>(index,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
                glDisableVertexAttribArray(index);
            }
        }

        if(textureInputLocation>-1) {
            const GLuint index=(GLuint)textureInputLocation;
            if(textureSetIndex>-1 && vbo.getTextureArraySizeInElements(textureSetIndex)>0) {
                glVertexAttribPointer(index, getTextureDimentionality(vbo,textureSetIndex), GL_FLOAT,GL_FALSE, 0, (void*)getTextureArrayOffsetInBytes(vbo,textureSetIndex));
                glEnableVertexAttribArray(index);
            } else {
                glVertexAttrib<SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_ELEMENTS,float>(index,0,0,0,0);
                glDisableVertexAttribArray(index);
            }
        }
    }
}
