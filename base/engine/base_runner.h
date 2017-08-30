#ifndef BASE_RUNNER_H
#define BASE_RUNNER_H
namespace gle{
    class Display;
    typedef void(*callbackFunc)(Display & disp);
    void setInitializationCallback(const callbackFunc f);
    void setUpdateCallback(const callbackFunc f);
    void setRenderCallback(const callbackFunc f);
    void setDestroyCallback(const callbackFunc f);
    void run(const int width,const int height,const char * const title,const bool useDebugContext);

}
#endif // BASE_RUNNER_H
