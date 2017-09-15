#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <FreeImage.h>
namespace gle {
    bool loadTexture(const FREE_IMAGE_FORMAT format,const char * const textureFilePath) ;
}

#endif // TEXTURE_LOADER_H
