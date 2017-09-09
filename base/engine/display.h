#ifndef DISPLAY_H
#define DISPLAY_H
#include <GLFW/glfw3.h>
#include "bindable.h"
namespace gle {
    class Display:public Bindable
    {

      public:
        /**enableAutoResize will automatically resize OpenGL viewport when window is resizedd*/
        Display(const int width,const int height,const char * const title,const bool useDebugContext=false,const bool enableAutoResize=true);
        ~Display();
        GLFWwindow * getWindow() const {
            return window;
        };
        void registerKey(const int key, const GLFWkeyfun callbackFunc);
        inline void setAutoWindowResize(const bool enableAutoResize) {
            m_isAutoResizeEnabled=enableAutoResize;
        }
        inline bool isAutoWindowResizeEnabled()const {
            return m_isAutoResizeEnabled;
        }
        void updateInput()const;
        void toggleGrabMouse();
        inline int getWindowWidth() const {
            return m_windowWidth;
        }
        inline int getWindowHeight() const {
            return m_windowHeight;
        }
        void bind();
        void unbind();
        inline bool isMouseGrabbed(){
            return m_isMouseGrabbed;
        }
      protected:

      private:
        GLFWwindow * window;
        bool m_isAutoResizeEnabled;
        bool m_isMouseGrabbed;
        int m_windowWidth;
        int m_windowHeight;
        Display(const Display & );
        Display& operator=(const  Display& );
        static void windowResizeCallback (GLFWwindow * window, int w, int h);
        void setMouseInCenter()const;
    };
}
#endif // DISPLAY_H
