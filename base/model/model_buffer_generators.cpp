#include <GL/glew.h>
#include "model_buffer_generators.h"
#include "model_buffer_binders.h"
namespace gle {

    const GLuint generateBuffer_glb(const GLenum target,const GLsizeiptr size,const GLvoid * data,const GLenum usage,const GLuint bufferID){
        bindBuffer(target,bufferID);
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
