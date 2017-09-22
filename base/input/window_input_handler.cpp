#include "window_input_handler.h"
#include "input_key_registry.h"
#include <vector>
#include <algorithm>

#include <GLFW/glfw3.h>
namespace gle {

    ////////////////
    //local variables
    ////////////////
    InputKeyRegistry inputKeyRegistry;


    typedef std::vector<mouse_callback> mouse_callbacks;
    typedef std::vector<mouse_button_callback> mouse_button_callbacks;
    mouse_callbacks mouseMoveCallbacks;
    mouse_callbacks mousePerTickMoveCallbacks;
    mouse_button_callbacks mousePressCallbacks;
    double lastRegisteredMousePosX=-1;
    double lastRegisteredMousePosY=-1;
    /**sometimes there are more than just one input callbacks registered between game ticks.
    Callbacks are executed only when glfwPollEvents() is called. However mouse input is
    registered virtually continously be hardware and OS. That's why this variable containes
    sum of mouse inputs regsitered between current and previous tick. This is updated by mouseUpdatePosition()*/
    double lastRegisteredMousePosPerTickX=-1;
    double lastRegisteredMousePosPerTickY=-1;
    double lastRegisteredMouseMovementPerTickX=-1;
    double lastRegisteredMouseMovementPerTickY=-1;
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
        if(result == std::end(*callbacks))callbacks->push_back(mouseCallback);
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
    void keyboardUpdateKeys(GLFWwindow* window) {
        inputKeyRegistry.updateKeys(window);
    }
    void mouseAddMoveCallback(const mouse_callback mouseCallback) {
        mouseAddCallback<mouse_callback,&mouseMoveCallbacks>(mouseCallback);
    }
    void mouseEraseMoveCallback(const mouse_callback mouseCallback) {
        mouseEraseCallback<mouse_callback,&mouseMoveCallbacks>(mouseCallback);
    }
    void mouseAddPerTickMoveCallback(const mouse_callback mouseCallback) {
        mouseAddCallback<mouse_callback,&mousePerTickMoveCallbacks>(mouseCallback);
    }
    void mouseErasePerTickMoveCallback(const mouse_callback mouseCallback) {
        mouseEraseCallback<mouse_callback,&mousePerTickMoveCallbacks>(mouseCallback);
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

    void mouseUpdatePosition() {

        for(const mouse_callback mouseCallback: mousePerTickMoveCallbacks) {
            mouseCallback(lastRegisteredMousePosX,lastRegisteredMousePosY,lastRegisteredMousePosPerTickX,lastRegisteredMousePosPerTickY);
        }
        lastRegisteredMouseMovementPerTickX= lastRegisteredMousePosX-lastRegisteredMousePosPerTickX;
        lastRegisteredMouseMovementPerTickY= lastRegisteredMousePosY-lastRegisteredMousePosPerTickY;
        lastRegisteredMousePosPerTickX=lastRegisteredMousePosX;
        lastRegisteredMousePosPerTickY=lastRegisteredMousePosY;

    }

    void mouseResetPosition(const double mouseX,const double mouseY){
        lastRegisteredMousePosX=mouseX;
        lastRegisteredMousePosY=mouseY;
        lastRegisteredMousePosPerTickX=mouseX;
        lastRegisteredMousePosPerTickY=mouseY;
        lastRegisteredMouseMovementPerTickX=0;
        lastRegisteredMouseMovementPerTickY=0;
    }

    double getLastMouseMovementX() {
        return lastRegisteredMouseMovementPerTickX;
    }
    double getLastMouseMovementY() {
        return lastRegisteredMouseMovementPerTickY;
    }
}
