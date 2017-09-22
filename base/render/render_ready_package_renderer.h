#ifndef RENDER_READY_PACKAGE_RENDERER_H
#define RENDER_READY_PACKAGE_RENDERER_H
#include <GLFW/glfw3.h>
#include "matrix_math_types.h"
namespace gle{
    class RenderReadyPackage;
    void renderEBO(const RenderReadyPackage &pack,const GLenum mode,unsigned int index);
    void renderAllEBO(const RenderReadyPackage &pack,const GLenum mode);
    void renderAllNodes(const RenderReadyPackage &pack,const GLenum mode,const Mat4 viewProjectionMatrix,const unsigned int rootNodeIndex);
}
#endif // RENDER_READY_PACKAGE_RENDERER_H
