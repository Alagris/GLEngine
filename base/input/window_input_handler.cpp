#include "window_input_handler.h"
#include <GLFW/glfw3.h>
#include "input_key_registry.h"
#include <vector>
#include <algorithm>
namespace gle {

    ////////////////
    //local variables
    ////////////////
    InputKeyRegistry inputKeyRegistry;

    typedef std::vector<mouse_callback> mouse_callbacks;
    typedef std::vector<mouse_button_callback> mouse_button_callbacks;
    mouse_callbacks mouseMoveCallbacks;
    mouse_button_callbacks mousePressCallbacks;
    double lastRegisteredMousePosX=-1;
    double lastRegisteredMousePosY=-1;


    ////////////////
    //local functions
    ////////////////


    void receiveFromKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods) {
        inputKeyRegistry.executeKey(window,key,scancode,action,mods);
    }

    void receiveFromMouse(GLFWwindow* window, double xpos, double ypos) {
        for(const mouse_callback mouseCallback: mouseMoveCallbacks) {
            mouseCallback(xpos,ypos,lastRegisteredMousePosX,lastRegisteredMousePosY);
        }
        lastRegisteredMousePosX=xpos;
        lastRegisteredMousePosY=ypos;
    }

    void receiveFromMouseButton(GLFWwindow *window, int button, int action, int mods) {
        for(const mouse_button_callback mouseCallback: mousePressCallbacks) {
            mouseCallback(button,action,mods,lastRegisteredMousePosX,lastRegisteredMousePosY);
        }
    }
    template<class T,std::vector<T>* callbacks>
    void mouseAddCallback(const T mouseCallback) {
        auto result = std::find(callbacks->begin(),callbacks->end(),mouseCallback);
        if(result != std::end(*callbacks))callbacks->push_back(mouseCallback);
    }
    template<class T,std::vector<T>* callbacks>
    void mouseEraseCallback(const T mouseCallback) {
        auto result = std::find(callbacks->begin(),callbacks->end(),mouseCallback);
        if(result != std::end(*callbacks))callbacks->erase(result);
    }
    void bindInputCallbacks(GLFWwindow* window,GLFWcursorposfun cursorposfun,GLFWkeyfun keyfun,GLFWmousebuttonfun mousebuttonfun) {
        glfwSetCursorPosCallback(window, cursorposfun);
        glfwSetKeyCallback(window, keyfun);
        glfwSetMouseButtonCallback(window,mousebuttonfun);
    }
    ////////////////
    //public functions
    ////////////////
    void bindInputCallbacks(GLFWwindow* window) {
        bindInputCallbacks(window,receiveFromMouse,receiveFromKeyboard,receiveFromMouseButton);
    }
    void unbindInputCallbacks(GLFWwindow* window) {
        bindInputCallbacks(window,nullptr,nullptr,nullptr);
    }
    void keyboardAddKey(const int key,const GLFWkeyfun callbackFunc,const bool inputMode) {
        inputKeyRegistry.addKey(key,callbackFunc,inputMode);
    }
    void keyboardSwapKey(const int oldKey,const int newKey) {
        inputKeyRegistry.swapKey(oldKey,newKey);
    }
    void keyboardSetKey(const int key,const GLFWkeyfun newCallbackFunc) {
        inputKeyRegistry.setKey(key,newCallbackFunc);
    }
    bool keyboardContainsKey(const int key) {
        return inputKeyRegistry.containsKey(key);
    }
    bool keyboardIsKeyEnabled(const int key) {
        return inputKeyRegistry.isKeyEnabled(key);
    }
    void keyboardDisableKey(const int key) {
        inputKeyRegistry.disableKey(key);
    }
    void keyboardUpdateKeys() {
        inputKeyRegistry.updateKeys();
    }
    void mouseAddMoveCallback(const mouse_callback mouseCallback) {
        mouseAddCallback<mouse_callback,&mouseMoveCallbacks>(mouseCallback);
    }
    void mouseEraseMoveCallback(const mouse_callback mouseCallback) {
        mouseEraseCallback<mouse_callback,&mouseMoveCallbacks>(mouseCallback);
    }
    void mouseAddPressCallback(const mouse_button_callback mouseCallback) {
        mouseAddCallback<mouse_button_callback,&mousePressCallbacks>(mouseCallback);
    }
    void mouseErasePressCallback(const mouse_button_callback mouseCallback) {
        mouseEraseCallback<mouse_button_callback,&mousePressCallbacks>(mouseCallback);
    }
    double getLastMousePosX() {
        return lastRegisteredMousePosX;
    }
    double getLastMousePosY() {
        return lastRegisteredMousePosY;
    }
}
