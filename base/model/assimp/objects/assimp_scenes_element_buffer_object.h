#ifndef ASSIMP_SCENES_ELEMENT_BUFFER_OBJECT_H
#define ASSIMP_SCENES_ELEMENT_BUFFER_OBJECT_H
#include "element_buffer_object.h"
#include <assimp/scene.h>
#include <GLFW/glfw3.h>
namespace gle {
    class AssimpScenesElementBufferObject:public ElementBufferObject
    {
      public:
        AssimpScenesElementBufferObject():m_scenes(nullptr),m_scenesCount(0) {}
        AssimpScenesElementBufferObject(
            const aiScene *const* const scenes,
            const unsigned int scenesCount,
            const ebo_offset elementArrayOffset=0,
            const GLenum type=GL_UNSIGNED_INT,
            const unsigned int numIndicesPerFace=3);
        virtual ~AssimpScenesElementBufferObject() {}
        virtual const GLuint generate(const GLuint reservedEBO_ID,const GLenum usage);
      protected:
      private:
        const aiScene*const* m_scenes;
        unsigned int m_scenesCount;
        bool m_hasBeenGenerated=false;
        unsigned int m_numIndicesPerFace;
    };
}
#endif // ASSIMP_SCENES_ELEMENT_BUFFER_OBJECT_H
