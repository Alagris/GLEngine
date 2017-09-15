#include "assimp_vertex_array_object_generators.h"
#include "assimp_vertex_buffer_object.h"
#include "assimp_element_buffer_object.h"
#include "vertex_array_object_helpers.h"
#include "vertex_array_object.h"
#include "vertex_attrib_pointer_setup.h"
#include "vertex_buffer_object_helpers.h"

namespace gle {



//    const VertexArrayObject generateVAO(
//        const aiMesh*const mesh,
//        const GLenum usage,
//        const unsigned int colorSetIndexToUse,
//        const unsigned int textureSetIndexToUse,
//        const GLuint vertexInputLocation,
//        const GLint colorInputLocation,
//        const GLint textureInputLocation,
//        const GLfloat defaultColorR,
//        const GLfloat defaultColorG,
//        const GLfloat defaultColorB,
//        const GLfloat defaultColorA)
//    {
//        VertexArrayObject vao;
//        vao.generate();
//        vao.bind();
//        //generating ebo
//        AssimpElementBufferObject ebo(mesh);
//        ebo.generate(vao.getEBO(),usage);
//        vao.push_back(ebo.getElementArraySizeInElements());
//        //generating VBO
//        AssimpVertexBufferObject vbo(mesh);
//        vbo.generate(vao.getVBO(),usage);
//        //setting up shader bindings
//        printDebug(vbo);
//        bindVertexAttribPointers(
//            vbo,
//            colorSetIndexToUse,
//            textureSetIndexToUse,
//            vertexInputLocation,
//            colorInputLocation,
//            textureInputLocation,
//            defaultColorR,
//            defaultColorG,
//            defaultColorB,
//            defaultColorA);
//        return vao;
//    }
//
//    const VertexArrayObject generateVAO(
//        const aiMesh*const mesh,
//        const GLenum usage,
//        const unsigned int colorSetIndexToUse,
//        const unsigned int textureSetIndexToUse,
//        const GLuint program,
//        const GLchar *const vertexInputLocation,
//        const GLchar *const colorInputLocation,
//        const GLchar *const textureInputLocation,
//        const GLfloat defaultColorR,
//        const GLfloat defaultColorG,
//        const GLfloat defaultColorB,
//        const GLfloat defaultColorA)
//    {
//        GLint vertexInputLoc=-1;
//        GLint colorInputLoc=-1;
//        GLint textureInputLoc=-1;
//        if(findInputLocations(program,vertexInputLocation,colorInputLocation,textureInputLocation,vertexInputLoc,colorInputLoc,textureInputLoc)) {
//            return generateVAO(
//                       mesh,
//                       usage,
//                       colorSetIndexToUse,
//                       textureSetIndexToUse,
//                       static_cast<GLuint>(vertexInputLoc),
//                       colorInputLoc,
//                       textureInputLoc,
//                       defaultColorR,
//                       defaultColorG,
//                       defaultColorB,
//                       defaultColorA);
//        }
//        return VertexArrayObject();
//    }
//
//
//    const VertexArrayObject generateVAO(
//        const aiScene*const scene,
//        const GLenum usage,
//        const unsigned int colorSetIndexToUse,
//        const unsigned int textureSetIndexToUse,
//        const GLuint vertexInputLocation,
//        const GLint colorInputLocation,
//        const GLint textureInputLocation,
//        const GLfloat defaultColorR,
//        const GLfloat defaultColorG,
//        const GLfloat defaultColorB,
//        const GLfloat defaultColorA)
//    {
//
//
//        VertexArrayObject vao;
//        vao.generate();
//        vao.bind();
//        //generating ebo
//        AssimpElementBufferObject ebo(mesh);
//        ebo.generate(vao.getEBO(),usage);
//        vao.push_back(ebo.getElementArraySizeInElements());
//        //generating VBO
//        AssimpVertexBufferObject vbo(mesh);
//        vbo.generate(vao.getVBO(),usage);
//        //setting up shader bindings
//        printDebug(vbo);
//        bindVertexAttribPointers(
//            vbo,
//            colorSetIndexToUse,
//            textureSetIndexToUse,
//            vertexInputLocation,
//            colorInputLocation,
//            textureInputLocation,
//            defaultColorR,
//            defaultColorG,
//            defaultColorB,
//            defaultColorA);
//        return vao;
//    }
//
//    const VertexArrayObject generateVAO(
//        const aiScene*const scene,
//        const GLenum usage,
//        const unsigned int colorSetIndexToUse,
//        const unsigned int textureSetIndexToUse,
//        const GLuint program,
//        const GLchar *const vertexInputLocation,
//        const GLchar *const colorInputLocation,
//        const GLchar *const textureInputLocation,
//        const GLfloat defaultColorR=0,
//        const GLfloat defaultColorG=0,
//        const GLfloat defaultColorB=0,
//        const GLfloat defaultColorA=1)
//    {
//
//        GLint vertexInputLoc=-1;
//        GLint colorInputLoc=-1;
//        GLint textureInputLoc=-1;
//        if(findInputLocations(program,vertexInputLocation,colorInputLocation,textureInputLocation,vertexInputLoc,colorInputLoc,textureInputLoc)) {
//            return generateVAO(
//                       scene,
//                       usage,
//                       colorSetIndexToUse,
//                       textureSetIndexToUse,
//                       static_cast<GLuint>(vertexInputLoc),
//                       colorInputLoc,
//                       textureInputLoc,
//                       defaultColorR,
//                       defaultColorG,
//                       defaultColorB,
//                       defaultColorA);
//        }
//        return VertexArrayObject();
//    }
}
