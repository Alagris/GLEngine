#include <GL/glew.h>
#include "vertex_attrib_pointer_setup.h"
#include "vertex_buffer_object.h"
#include "vertex_attrib_helpers.h"
#include "assimp_constants.h"
#include "vertex_buffer_object_helpers.h"



namespace gle {




    void bindVertexAttribPointerVertex(const VertexBufferObject &vbo,const mandatory_shader_location vertexInputLocation) {
        glVertexAttribPointer(vertexInputLocation, SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.getVertexArrayOffsetInBytes());
        glEnableVertexAttribArray(vertexInputLocation);
    }

    void bindVertexAttribPointerColor(
        const VertexBufferObject &vbo,
        const int colorSetIndex,
        const shader_location colorInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA)
    {
        if(colorInputLocation>-1) {
            const mandatory_shader_location index=static_cast<mandatory_shader_location>(colorInputLocation);
            if(colorSetIndex>-1 && colorSetIndex<vbo.getColorSetsNumber() && vbo.getColorArraySizeInElements()>0) {
                glVertexAttribPointer(index, SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)getColorArrayOffsetInBytes(vbo,colorSetIndex));
                glEnableVertexAttribArray(index);
            } else {
                glVertexAttrib<SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS,float>(index,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
                glDisableVertexAttribArray(index);
            }
        }
    }

    void bindVertexAttribPointerTexture(
        const VertexBufferObject &vbo,
        const int textureSetIndex,
        const shader_location textureInputLocation)
    {
        if(textureInputLocation>-1) {
            const mandatory_shader_location index=static_cast<mandatory_shader_location>(textureInputLocation);
            if(textureSetIndex>-1 && textureSetIndex<vbo.getTextureSetsNumber() && vbo.getTextureArraySizeInElements(textureSetIndex)>0) {
                glVertexAttribPointer(index, getTextureDimentionality(vbo,textureSetIndex), GL_FLOAT,GL_FALSE, 0, (void*)getTextureArrayOffsetInBytes(vbo,textureSetIndex));
                glEnableVertexAttribArray(index);
            } else {
                glVertexAttrib<SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_ELEMENTS,float>(index,0,0,0,0);
                glDisableVertexAttribArray(index);
            }
        }
    }

    void bindVertexAttribPointerNormal(
        const VertexBufferObject &vbo,
        const shader_location normalInputLocation,
        const GLfloat defaultNormalX,
        const GLfloat defaultNormalY,
        const GLfloat defaultNormalZ)
    {
        if(normalInputLocation>-1) {
            const mandatory_shader_location index=static_cast<mandatory_shader_location>(normalInputLocation);
            if( vbo.getVertexNormalArraySizeInElements()>0) {
                glVertexAttribPointer(index, SIZE_OF_ASSIMP_VERTEX_NORMAL_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.getVertexNormalArrayOffsetInBytes());
                glEnableVertexAttribArray(index);
            } else {
                glVertexAttrib<SIZE_OF_ASSIMP_VERTEX_NORMAL_TYPE_IN_ELEMENTS,float>(index,defaultNormalX,defaultNormalY,defaultNormalZ,0);
                glDisableVertexAttribArray(index);
            }
        }
    }



    void bindVertexAttribPointers(
        const VertexBufferObject &vbo,
        const int colorSetIndex,
        const int textureSetIndex,
        const mandatory_shader_location vertexInputLocation,
        const shader_location colorInputLocation,
        const shader_location textureInputLocation,
        const shader_location normalInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA,
        const GLfloat defaultNormalX,
        const GLfloat defaultNormalY,
        const GLfloat defaultNormalZ) {
        bindVertexAttribPointerVertex(vbo,vertexInputLocation);
        bindVertexAttribPointerColor(vbo,colorSetIndex,colorInputLocation,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
        bindVertexAttribPointerTexture(vbo,textureSetIndex,textureInputLocation);
        bindVertexAttribPointerNormal(vbo,normalInputLocation,defaultNormalX,defaultNormalY,defaultNormalZ);


//
//        glVertexAttribPointer(vertexInputLocation, SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)vbo.getVertexArrayOffsetInBytes());
//        glEnableVertexAttribArray(vertexInputLocation);
//
//        if(colorInputLocation>-1) {
//            const GLuint index=static_cast<GLuint>(colorInputLocation);
//            if(colorSetIndex>-1 && colorSetIndex<vbo.getColorSetsNumber() && vbo.getColorArraySizeInElements()>0) {
//                glVertexAttribPointer(index, SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS, GL_FLOAT,GL_FALSE, 0, (void*)getColorArrayOffsetInBytes(vbo,colorSetIndex));
//                glEnableVertexAttribArray(index);
//            } else {
//                glVertexAttrib<SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS,float>(index,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
//                glDisableVertexAttribArray(index);
//            }
//        }
//
//        if(textureInputLocation>-1) {
//            const GLuint index=static_cast<GLuint>(textureInputLocation);
//            if(textureSetIndex>-1 && textureSetIndex<vbo.getTextureSetsNumber() && vbo.getTextureArraySizeInElements(textureSetIndex)>0) {
//                glVertexAttribPointer(index, getTextureDimentionality(vbo,textureSetIndex), GL_FLOAT,GL_FALSE, 0, (void*)getTextureArrayOffsetInBytes(vbo,textureSetIndex));
//                glEnableVertexAttribArray(index);
//            } else {
//                glVertexAttrib<SIZE_OF_ASSIMP_TEXTURE_3D_TYPE_IN_ELEMENTS,float>(index,0,0,0,0);
//                glDisableVertexAttribArray(index);
//            }
//        }

    }
}
