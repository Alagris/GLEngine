#ifndef WINDOW_INPUT_HANDLER_H
#define WINDOW_INPUT_HANDLER_H
#include <GLFW/glfw3.h>
namespace gle {

    typedef void (*mouse_callback)(const double x,const double y,const double previousX,const double previousY);
    typedef void (*mouse_button_callback)(const int button,const int action,const int mods,const double x,const double y);
    void bindInputCallbacks(GLFWwindow* window);
    void unbindInputCallbacks(GLFWwindow* window);
    /**If continousInputMode is true, then key handler
    function is triggered always (provided that key is pressed).
     If it's false, then everything is determined by
     GLFW callback triggers*/
    void keyboardAddKey(const int key,const GLFWkeyfun callbackFunc,const bool inputMode=true);
    void keyboardSwapKey(const int oldKey,const int newKey);
    void keyboardEnableKey(const int key,const GLFWkeyfun newCallbackFunc);
    bool keyboardContainsKey(const int key);
    bool keyboardIsKeyEnabled(const int key);
    void keyboardDisableKey(const int key);
    void keyboardUpdateKeys(GLFWwindow* window=nullptr);
    void mouseAddMoveCallback(const mouse_callback mouseCallback);
    void mouseEraseMoveCallback(const mouse_callback mouseCallback);
    void mouseAddPerTickMoveCallback(const mouse_callback mouseCallback);
    void mouseErasePerTickMoveCallback(const mouse_callback mouseCallback);
    void mouseAddPressCallback(const mouse_button_callback mouseCallback);
    void mouseErasePressCallback(const mouse_button_callback mouseCallback);
    void mouseUpdatePosition();
    void mouseResetPosition(const double mouseX,const double mouseY);
    double getLastMousePosX();
    double getLastMousePosY();
    double getLastMouseMovementX();
    double getLastMouseMovementY();
}
#endif // WINDOW_INPUT_HANDLER_H
