#include "texture_error_callbacks.h"
#include <FreeImage.h>
#include <iostream>
#include "texture_format_enum_to_string.h"
namespace gle {
    void freeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message) {
        std::cout << "---------------------FreeImage begin-----------" << std::endl;
        std::cout << "message: "<< message << std::endl;
        std::string val;
        getNameOfEnum(fif,val);
        std::cout << "format: "<<val<<std::endl;
        std::cout << "---------------------FreeImage end-------------" << std::endl;
    }

    void registerTextureErrorCallback() {
        FreeImage_SetOutputMessage(freeImageErrorHandler);
    }
}
