#include "model_buffer_generators.h"
namespace gle {
    GLuint generateBuffer(const GLenum target,const GLsizeiptr size,const GLvoid * data,const GLenum usage) {
        // This will identify our buffer
        GLuint buffer=0;
        // Generate 1 buffer, put the resulting identifier in buffer
        glGenBuffers(1, &buffer);
        // The following commands will talk about our buffer
        glBindBuffer(target, buffer);
        // Give our data to OpenGL.
        glBufferData(target, size, data, usage);
        //unbind buffer
        glBindBuffer(target, 0);
        return buffer;
    }
}
