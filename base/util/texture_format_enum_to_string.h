#ifndef TEXTURE_FORMAT_ENUM_TO_STRING_H
#define TEXTURE_FORMAT_ENUM_TO_STRING_H
#include <FreeImage.h>
#include <string>
namespace gle{
    bool getNameOfEnum(const FREE_IMAGE_FORMAT format,std::string & outputDestination);
}

#endif // TEXTURE_FORMAT_ENUM_TO_STRING_H
