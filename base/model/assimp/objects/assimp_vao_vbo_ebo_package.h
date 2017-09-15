#ifndef ASSIMP_VAO_VBO_EBO_PACKAGE_H
#define ASSIMP_VAO_VBO_EBO_PACKAGE_H
#include "vao_vbo_ebo_package.h"
#include <assimp/mesh.h>
#include <GLFW/glfw3.h>
namespace gle {

    class AssimpVaoVboEboPackage:public VaoVboEboPackage
    {
      public:
        AssimpVaoVboEboPackage(const aiMesh * const mesh,const GLenum eboType=GL_UNSIGNED_INT,const bool deleteAutomatically=true);
        virtual ~AssimpVaoVboEboPackage(){}
        virtual void generate(const GLenum usage);
      protected:

      private:
        const aiMesh * m_mesh;
        bool m_hasBeenGenerated=false;
    };
}
#endif // ASSIMP_VAO_VBO_EBO_PACKAGE_H
