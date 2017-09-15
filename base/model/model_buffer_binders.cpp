#include <GL/glew.h>
#include "model_buffer_binders.h"
namespace gle {

    void bindVAO(const GLuint vao) {
        glBindVertexArray(vao);
    }
    void bindBuffer(const GLenum target,const GLuint bufferID) {
        glBindBuffer(target,bufferID);
    }
}
