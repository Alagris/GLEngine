#ifndef ASSIMP_SCENE_VAO_VBO_EBO_PACKAGE_H
#define ASSIMP_SCENE_VAO_VBO_EBO_PACKAGE_H
#include "vao_vbo_ebo_package.h"
#include <assimp/scene.h>
#include <GLFW/glfw3.h>
namespace gle {

    class AssimpSceneVaoVboEboPackage:public VaoVboEboPackage
    {
      public:
        AssimpSceneVaoVboEboPackage(const aiScene * const scene,const GLenum eboType=GL_UNSIGNED_INT,const bool deleteAutomatically=true);
        virtual ~AssimpSceneVaoVboEboPackage(){}
        virtual void generate(const GLenum usage);
      protected:

      private:
        const aiScene * m_scene;
        bool m_hasBeenGenerated=false;
    };
}
#endif // ASSIMP_SCENE_VAO_VBO_EBO_PACKAGE_H
