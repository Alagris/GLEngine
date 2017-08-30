#include <GL/glew.h>
#include "display.h"
#include <stdlib.h>
#include "input_key_registry.h"
#include <iostream>
gle::InputKeyRegistry inputKeyRegistry;

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout<<"Key: "<<key<<", mods: "+mods<<", scancode: "+scancode<<std::endl;
    std::cout.flush();
//    inputKeyRegistry.executeKey( window,  key,  scancode,  action,  mods);
}

namespace gle {

    struct Display::Pimpl {

        //here will be added more stuff in the future
    };



    void Display::registerKey(const int key, const GLFWkeyfun callbackFunc) {
        inputKeyRegistry.addKey(key,callbackFunc);
    }

    Display::Display(const int width,const int height,const char *const title,const bool useDebugContext) {
        if (!glfwInit())
            exit(EXIT_FAILURE);

        if(useDebugContext)glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetKeyCallback(window,keyboardCallback);
        glfwMakeContextCurrent(window);//this must go before glew

        if (glewInit() != GLEW_OK) {   // init glew, and bind gl* Extension functions
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwSwapInterval(1);//vsync
    }

    Display::~Display() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
