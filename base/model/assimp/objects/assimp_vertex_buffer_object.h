#ifndef ASSIMP_VERTEX_BUFFER_OBJECT_H
#define ASSIMP_VERTEX_BUFFER_OBJECT_H
#include "vertex_buffer_object.h"
#include <GLFW/glfw3.h>
#include <assimp/mesh.h>
namespace gle {
    class AssimpVertexBufferObject:public VertexBufferObject
    {
      public:
        AssimpVertexBufferObject():m_mesh(nullptr){}
        AssimpVertexBufferObject(const aiMesh*const mesh,const vbo_offset initialOffset=0);
        virtual ~AssimpVertexBufferObject(){}
        virtual const GLuint generate(const GLuint reservedVBO_ID,const GLenum usage,GLfloat * const buffer,const bool createNewVBO=true) ;
        /**Generates new VBO and fills it with data pulled from assimp mesh*/
        virtual const GLuint generate(const GLuint reservedVBO_ID,const GLenum usage){
            generate(reservedVBO_ID,usage,nullptr);
        }

      protected:

      private:
        const aiMesh * const m_mesh;
        bool m_hasBeenGenerated=false;
    };
}

#endif // ASSIMP_VERTEX_BUFFER_OBJECT_H
