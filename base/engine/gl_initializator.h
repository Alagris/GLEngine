#ifndef GL_INITIALIZATOR_H
#define GL_INITIALIZATOR_H

namespace gle {

    class Display;
    /**Calls all the rest of functions*/
    void init(const Display * const display);

    namespace deep {
        void initGL();
        void checkOpenGLVersion();
        void checkGLSLVersion();
    }
}
#endif // GL_INITIALIZATOR_H
