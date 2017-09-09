#ifndef ASSIMP_LOADER_H
#define ASSIMP_LOADER_H
#include <GLFW/glfw3.h>
namespace gle {
    struct VertexArrayObject;
    bool importModel( const char * pFile,VertexArrayObject & vaoOutput);
}
#endif // ASSIMP_LOADER_H
