#include "base_runner.h"
#include "display.h"
#include <GLFW/glfw3.h>
#include <iostream>
namespace gle {
    callbackFunc initF=nullptr,updateF=nullptr,renderF=nullptr,destroyF=nullptr;
    void setInitializationCallback(const callbackFunc f) {
        initF=f;
    }
    void setUpdateCallback(const callbackFunc f) {
        updateF=f;
    }
    void setRenderCallback(const callbackFunc f) {
        renderF=f;
    }
    void setDestroyCallback(const callbackFunc f) {
        destroyF=f;
    }
    typedef  Display * DisplayPtr;
    class DisplayPtrWrapper {
      private:
        DisplayPtr & m_ptrDisplay;
        DisplayPtrWrapper(const DisplayPtrWrapper & d);
        DisplayPtrWrapper& operator=(const  DisplayPtrWrapper& d);
      public:
        DisplayPtrWrapper(DisplayPtr & ptrDisplay):m_ptrDisplay(ptrDisplay) {}
        DisplayPtrWrapper(DisplayPtr & ptrDisplay,DisplayPtr val):m_ptrDisplay(ptrDisplay) {
            m_ptrDisplay=val;
        }
        ~DisplayPtrWrapper();
    };

    DisplayPtrWrapper::~DisplayPtrWrapper() {
        m_ptrDisplay=nullptr;
    }

    DisplayPtr ptrDisplay=nullptr;
    void run(
        const int width,
        const int height,
        const char * const title,
        const bool useDebugContext,
        const callbackFunc initF,
        const callbackFunc updateF,
        const callbackFunc renderF,
        const callbackFunc destroyF) {
        Display display(width,height,title,useDebugContext);
        DisplayPtrWrapper wrapper(ptrDisplay,&display);
        if(initF)initF(display);
        while(!glfwWindowShouldClose(display.getWindow())) {
            if(updateF)updateF(display);
            if(renderF)renderF(display);
        }
        if(destroyF)destroyF(display);

    }

    void run(const int width,const int height,const char * const title,const bool useDebugContext) {
        run(width,height,title,useDebugContext,initF,updateF,renderF,destroyF);
    }

}
