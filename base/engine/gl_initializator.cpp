#include "gl_initializator.h"
#include <GL/glew.h>
#include <iostream>
#include "display.h"
#include "gl_error_handler.h"
#include "window_input_handler.h"
namespace gle {
    void init(const Display * const display) {
        using namespace gle::deep;
        checkGLSLVersion();
        checkOpenGLVersion();
        bindErrorCallbacks();

        if(display==NULL) {
            std::cerr<<"initialization with NULL display\n";
        } else {
            bindInputCallbacks(display->getWindow());
        }
    }

    namespace deep {
        void initGL() {
            // Enable depth test
            glEnable(GL_DEPTH_TEST);
            // Accept fragment if it closer to the camera than the former one
            glDepthFunc(GL_LESS);
            // glEnable(GL_BLEND);
            // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glClearColor(0.f,0.f,0.f,1.f);
        }

        void checkOpenGLVersion() {
            std::cout<<"OpenGL version: "<<glGetString(GL_VERSION)<<std::endl;
        }
        void checkGLSLVersion() {
            std::cout<<"GLSL version: "<<glGetString(GL_SHADING_LANGUAGE_VERSION)<<std::endl;
        }
    }
}
