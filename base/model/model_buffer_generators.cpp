#include <GL/glew.h>
#include "model_buffer_generators.h"

namespace gle {

    const GLuint generateBuffer(const GLenum target,const GLsizeiptr size,const GLvoid * data,const GLenum usage,const GLuint bufferID){
         // The following commands will talk about our buffer
        glBindBuffer(target, bufferID);
        // Give our data to OpenGL.
        glBufferData(target, size, data, usage);
        return bufferID;
    }

    const GLuint glGenBuffer(){
        // This will identify our buffer
        GLuint bufferID=0;
        // Generate 1 buffer, put the resulting identifier in buffer
        glGenBuffers(1, &bufferID);
        return bufferID;
    }


}
