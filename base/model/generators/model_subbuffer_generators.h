#ifndef MODEL_SUBBUFFER_GENERATORS_H
#define MODEL_SUBBUFFER_GENERATORS_H
#include <GLFW/glfw3.h>
namespace gle{
    const GLuint generateBuffer(const GLenum target,const size_t partsCount,const GLsizeiptr * const partSizes,const GLvoid *const *const partData,const GLenum usage);
}
#endif // MODEL_SUBBUFFER_GENERATORS_H
