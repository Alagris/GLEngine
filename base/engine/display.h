#ifndef DISPLAY_H
#define DISPLAY_H
#include <GLFW/glfw3.h>
namespace gle {
    class Display
    {

      public:
        Display(const int width,const int height,const char * const title,const bool useDebugContext);
        ~Display();
        GLFWwindow * getWindow() const {
            return window;
        };
        void registerKey(const int key, const GLFWkeyfun callbackFunc);
      protected:

      private:

        GLFWwindow * window;
        class Pimpl;
        Pimpl * pimpl;
        Display(const Display & );
        Display& operator=(const  Display& );
    };
}
#endif // DISPLAY_H
