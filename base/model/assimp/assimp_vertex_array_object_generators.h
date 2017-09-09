#ifndef ASSIMP_VERTEX_ARRAY_OBJECT_GENERATORS_H
#define ASSIMP_VERTEX_ARRAY_OBJECT_GENERATORS_H
#include <assimp/mesh.h>
#include <GLFW/glfw3.h>
namespace gle{
    struct VertexArrayObject;
    VertexArrayObject generateVAO(const aiMesh*const mesh,const GLenum usage);

}
#endif // ASSIMP_VERTEX_ARRAY_OBJECT_GENERATORS_H
