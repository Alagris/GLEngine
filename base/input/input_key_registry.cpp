#include "input_key_registry.h"
#include <iostream>
#include <vector>
#include <algorithm>
namespace gle {
    ///////////////
    //private:
    ///////////////

    struct InputKeyRegistry::RegisteredKey {
        RegisteredKey(const int pKey,const GLFWkeyfun pCallbackFunc,const bool mode=CALLBACK_KEY_INPUT_MODE):
            key(pKey),
            callbackFunc(pCallbackFunc),
            keyInputMode(mode),
            lastAction(GLFW_RELEASE) {}
        int key;
        GLFWkeyfun callbackFunc;
        bool keyInputMode;

        int lastScancode;
        int lastAction;
        int lastMods;


    };



    struct InputKeyRegistry::Pimpl {
        typedef std::vector<RegisteredKey*> registry;
        registry reg;
    };

    size_t InputKeyRegistry::getPos(const int key)const {
        return std::distance(pimpl->reg.begin(),std::find_if(pimpl->reg.begin(),pimpl->reg.end(),[key](InputKeyRegistry::RegisteredKey* regkey)->bool { return regkey->key==key; } ));
    }
    bool isPosValid(const size_t pos,const size_t vectorLength) {
        return pos<vectorLength;
    }
    InputKeyRegistry::RegisteredKey * InputKeyRegistry::getRegister(const int key) const {
        size_t i=getPos(key);
        if(!isPosValid(i,pimpl->reg.size()))return nullptr;
        return pimpl->reg.at(i);
    }


    ////////////////////
    //public:
    ////////////////////
    GLFWkeyfun InputKeyRegistry::getKey(const int key) const {
        InputKeyRegistry::RegisteredKey * regkey=getRegister(key);
        return regkey==nullptr?nullptr:regkey->callbackFunc;
    }

    bool InputKeyRegistry::containsKey(const int key) const {
        size_t i=getPos(key);
        return isPosValid(i,pimpl->reg.size());
    }


    void InputKeyRegistry::swapKey(const int oldKey,const int newKey) {
        RegisteredKey * regkey = getRegister(oldKey);
        if(regkey!=nullptr)regkey->key=newKey;
    }

    void InputKeyRegistry::setKey(const int key,const GLFWkeyfun newCallbackFunc) {
        RegisteredKey * regkey = getRegister(key);
        if(regkey!=nullptr)regkey->callbackFunc=newCallbackFunc;
    }
    void InputKeyRegistry::setKeyMode(const int key,const bool mode) {
        RegisteredKey * regkey = getRegister(key);
        if(regkey!=nullptr)regkey->keyInputMode=mode;
    }
    void InputKeyRegistry::addKey(const int key,const GLFWkeyfun callbackFunc,const bool mode) {
        RegisteredKey * regkey=getRegister(key);
        if( regkey==nullptr) {
            pimpl->reg.push_back(new RegisteredKey(key,callbackFunc,mode));
        } else {
            regkey->callbackFunc=callbackFunc;
        }
    }



    bool InputKeyRegistry::executeKey(GLFWwindow* window, int key, int scancode, int action, int mods) const {
        RegisteredKey*rk= getRegister(key);
        if(rk==nullptr)return false;
        rk->lastAction=action;
        rk->lastMods=mods;
        rk->lastScancode=scancode;
        if(rk->keyInputMode==CONTINOUS_KEY_INPUT_MODE)return false;
        const GLFWkeyfun callbackFunc = rk->callbackFunc;
        if(callbackFunc==nullptr)return false;
        callbackFunc( window, key, scancode, action, mods);
        return true;
    }

    void  InputKeyRegistry::updateKeys(GLFWwindow* window)const {
        for(RegisteredKey* rk:pimpl->reg) {
            if(rk->keyInputMode==CONTINOUS_KEY_INPUT_MODE
                    && rk->lastAction!=GLFW_RELEASE
                    && rk->callbackFunc!=nullptr)
            {
                (rk->callbackFunc)( window, rk->key, rk->lastScancode,  GLFW_PRESS, rk->lastMods);
            }
        }
    }

    InputKeyRegistry::InputKeyRegistry():pimpl(new Pimpl)
    {

    }

    InputKeyRegistry::~InputKeyRegistry()
    {
        for(RegisteredKey * regkey:pimpl->reg) {
            delete regkey;
        }
        delete pimpl;
    }
}
