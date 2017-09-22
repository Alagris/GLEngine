#ifndef INPUT_KEY_REGISTRY_H
#define INPUT_KEY_REGISTRY_H
//#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace gle {

    const bool CONTINOUS_KEY_INPUT_MODE=true;
    const bool CALLBACK_KEY_INPUT_MODE=false;
    class InputKeyRegistry
    {
      public:
        InputKeyRegistry();
        ~InputKeyRegistry();
        void addKey(const int key,const GLFWkeyfun callbackFunc,const bool mode=CALLBACK_KEY_INPUT_MODE);
        void swapKey(const int oldKey,const int newKey);
        void setKey(const int key,const GLFWkeyfun newCallbackFunc);
        void setKeyMode(const int key,const bool mode);
        bool executeKey(GLFWwindow* window, int key, int scancode, int action, int mods) const;
        void updateKeys(GLFWwindow* window=nullptr)const;
        bool containsKey(const int key) const;

        inline bool isKeyEnabled(const int key) const {
            return getKey(key)!=nullptr;
        }
        inline void disableKey(const int key) {
            setKey(key,nullptr);
        }
      protected:

      private:
        struct Pimpl;
        struct RegisteredKey;
        Pimpl * pimpl;
        GLFWkeyfun getKey(const int key) const;

        InputKeyRegistry(const InputKeyRegistry & );
        InputKeyRegistry& operator=(const  InputKeyRegistry& );
        size_t getPos(const int key)const;
        RegisteredKey * getRegister(const int key)const;

    };
}
#endif // INPUT_KEY_REGISTRY_H
