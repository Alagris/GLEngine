#include <GL/glew.h>
#include "gl_error_handler.h"
#include <iostream>
#include <string>
#include "gl_enum_to_string.h"

#include <GLFW/glfw3.h>
namespace gle {
    void receiveFromGLFW(int error, const char* description) {
        std::cerr<<"GLFW ERROR ("<< error<<"): "<<description<<std::endl;
    }
    void receiveFromGL(GLenum source,
                       GLenum type,
                       GLuint id,
                       GLenum severity,
                       GLsizei length,
                       const GLchar* message,
                       const void* userParam) {
        std::cout << "---------------------GL ERROR begin------------" << std::endl;
        std::cout << "message: "<< message << std::endl;
        std::string val;
        getNameOfGL_DEBUG_TYPE(type,val);
        std::cout << "type: "<<val<<std::endl;
        std::cout << "id: " << id << std::endl;
        getNameOfGL_DEBUG_SEVERITY(severity,val);
        std::cout << "severity: "<<val<<std::endl;
        std::cout << "---------------------GL ERROR end--------------" << std::endl;
    }

    void glSetErrorCallback() {
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(receiveFromGL, nullptr);
        GLuint unusedIds = 0;
        glDebugMessageControl(GL_DONT_CARE,
                              GL_DONT_CARE,
                              GL_DONT_CARE,
                              0,
                              &unusedIds,
                              true);
    }
    void bindErrorCallbacks() {
        glfwSetErrorCallback(receiveFromGLFW);


        gle::glSetErrorCallback();
    }
}

