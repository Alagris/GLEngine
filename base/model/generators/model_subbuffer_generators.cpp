#include <GL/glew.h>
#include "model_subbuffer_generators.h"
namespace gle{

    const GLsizeiptr countTotalSize(const size_t partsCount,const GLsizeiptr * const partSizes) {
        GLsizeiptr out=0;
        for(size_t i=0; i<partsCount; i++) {
            out+=partSizes[i];
        }
        return out;
    }
    void fillBuffer(const GLenum target,const size_t partsCount,const GLsizeiptr * const partSizes,const GLvoid *const *const partData) {
        GLintptr offsetInclusive=0;
        for(size_t i=0; i<partsCount; i++) {
            GLsizeiptr partSize=partSizes[0];
            const GLvoid * data=partData[0];
            glBufferSubData(target,offsetInclusive,partSize,data);
            offsetInclusive+=partSize;
        }
    }
    const GLuint generateBuffer(const GLenum target,const size_t partsCount,const GLsizeiptr * const partSizes,const GLvoid *const *const partData,const GLenum usage) {
        if(partsCount==0)return 0;
        // This will identify our buffer
        GLuint buffer=0;
        // Generate 1 buffer, put the resulting identifier in buffer
        glGenBuffers(1, &buffer);
        // The following commands will talk about our buffer
        glBindBuffer(target, buffer);
        // Give our data to OpenGL.
        glBufferData(target, countTotalSize(partsCount,partSizes), nullptr, usage);

        fillBuffer( target, partsCount, partSizes, partData);

        //unbind buffer
        glBindBuffer(target, 0);
        return buffer;
    }
}
