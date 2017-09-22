#include <GL/glew.h>
#include "generatable.h"
namespace gle {
    Generatable::Generatable() {}

    Generatable::~Generatable() {}

    const GLuint Generatable::generate(const GLenum usage)  {
        GLuint bufferID=0;
        glGenBuffers(1, &bufferID);
        return generate(bufferID,usage);
    }
}
