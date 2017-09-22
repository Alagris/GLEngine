#ifndef ASSIMP_ELEMENT_BUFFER_OBJECT_H
#define ASSIMP_ELEMENT_BUFFER_OBJECT_H
#include <GLFW/glfw3.h>
#include "element_buffer_object.h"
#include <assimp/mesh.h>

namespace gle {
    class AssimpElementBufferObject:public ElementBufferObject
    {
      public:
        AssimpElementBufferObject();
        AssimpElementBufferObject(const aiMesh*const mesh,const ebo_offset elementArrayOffset=0,const GLenum type=GL_UNSIGNED_INT);
        virtual ~AssimpElementBufferObject();
        virtual const GLuint generate(const GLuint reservedEBO_ID,const GLenum usage) ;
      protected:
      private:
        const aiMesh*const m_mesh;
        bool m_hasBeenGenerated=false;
    };
}
#endif // ASSIMP_ELEMENT_BUFFER_OBJECT_H
