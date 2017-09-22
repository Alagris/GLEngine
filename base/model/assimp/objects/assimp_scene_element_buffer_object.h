#ifndef ASSIMP_SCENE_ELEMENT_BUFFER_OBJECT_H
#define ASSIMP_SCENE_ELEMENT_BUFFER_OBJECT_H
#include "element_buffer_object.h"
#include <assimp/scene.h>
#include <GLFW/glfw3.h>
namespace gle {
    class AssimpSceneElementBufferObject:public ElementBufferObject
    {
      public:
        AssimpSceneElementBufferObject():m_scene(nullptr) {}
        AssimpSceneElementBufferObject(const aiScene*const scene,const ebo_offset elementArrayOffset=0,const GLenum type=GL_UNSIGNED_INT,const unsigned int numIndicesPerFace=3);
        virtual ~AssimpSceneElementBufferObject(){}
        virtual const GLuint generate(const GLuint reservedEBO_ID,const GLenum usage);
      protected:
      private:
        const aiScene* m_scene;
        bool m_hasBeenGenerated=false;
        unsigned int m_numIndicesPerFace;
    };
}

#endif // ASSIMP_SCENE_ELEMENT_BUFFER_OBJECT_H
