#include <GL/glew.h>
#include "display.h"
#include <stdlib.h>
#include "input_key_registry.h"
#include <iostream>
#include "window_input_handler.h"
namespace {
    gle::InputKeyRegistry inputKeyRegistry;

    void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        std::cout<<"Key: "<<key<<", mods: "+mods<<", scancode: "+scancode<<std::endl;
        std::cout.flush();
//    inputKeyRegistry.executeKey( window,  key,  scancode,  action,  mods);
    }

    gle::Display * focusedDisplay=nullptr;


    void showCursor(GLFWwindow * window) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    void disableCursor(GLFWwindow * window) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        //        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    }
}

namespace gle {

    void Display::windowResizeCallback (GLFWwindow * window, int w, int h) {
        if(focusedDisplay==nullptr)return;
        if(focusedDisplay->m_isAutoResizeEnabled)glViewport(0,0,w,h);
        focusedDisplay->m_windowWidth=w;
        focusedDisplay->m_windowHeight=h;
    }

    void Display::registerKey(const int key, const GLFWkeyfun callbackFunc) {
        inputKeyRegistry.addKey(key,callbackFunc);
    }

    Display::Display(const int width,const int height,const char *const title,const bool useDebugContext,const bool enableAutoResize):
        m_isAutoResizeEnabled(enableAutoResize),
        m_isMouseGrabbed(false),
        m_windowWidth(0),
        m_windowHeight(0)
    {
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
        glfwSetWindowSizeCallback(getWindow(),windowResizeCallback);
        bind();
    }


    void Display::bind() {
        focusedDisplay=this;
    }
    void Display::unbind() {
        if(focusedDisplay==this)focusedDisplay=nullptr;
    }
    void Display::toggleGrabMouse() {
        if(isMouseGrabbed()) {
            m_isMouseGrabbed=false;
            showCursor(getWindow());
        } else {
            m_isMouseGrabbed=true;
            setMouseInCenter();
            disableCursor(getWindow());
        }
    }
    void Display::updateInput()const {
        glfwPollEvents();
        keyboardUpdateKeys(getWindow());
        mouseUpdatePosition();
        if(m_isMouseGrabbed) {
            setMouseInCenter();
        }
    }
    void Display::setMouseInCenter()const {
        const double x=getWindowWidth()/2;
        const double y=getWindowHeight()/2;
        glfwSetCursorPos(getWindow(),x,y);
        mouseResetPosition(x,y);
    }


    Display::~Display() {
        unbind();
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
