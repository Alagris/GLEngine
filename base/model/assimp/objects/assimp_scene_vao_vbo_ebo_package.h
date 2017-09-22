#ifndef ASSIMP_SCENE_VAO_VBO_EBO_PACKAGE_H
#define ASSIMP_SCENE_VAO_VBO_EBO_PACKAGE_H
#include "vao_vbo_ebo_package.h"
#include <assimp/scene.h>
#include <GLFW/glfw3.h>
#include "offset_types.h"
namespace gle {

    class AssimpSceneVaoVboEboPackage:public VaoVboEboPackage
    {
      public:
        AssimpSceneVaoVboEboPackage(const aiScene * const scene,const GLenum eboType=GL_UNSIGNED_INT,const bool deleteAutomatically=true);
        virtual ~AssimpSceneVaoVboEboPackage() {}
        virtual void generate(const GLenum usage);
      protected:

      private:
        const aiScene * m_scene;
        bool m_hasBeenGenerated=false;

        const vbo_offset addVBO( const aiMesh * const mesh,const vbo_offset offset);
        void collectVboSizes();
        void copyData(const GLenum usage,const GLuint targetVBO_ID);
    };
}
#endif // ASSIMP_SCENE_VAO_VBO_EBO_PACKAGE_H
