#include <GL/glew.h>
#include "texture_loader.h"
#include "texture.h"
#include "texture_cache.h"
#include <iostream>
namespace gle {
    bool loadTexture(const FREE_IMAGE_FORMAT format,const char * const textureFilePath) {
        Texture tex=getCachedTextureOrGenerateNew(textureFilePath,format);
        if (!tex.get()) return false;

        GLuint textureID;
        glGenTextures(1, &textureID);

        glBindTexture(GL_TEXTURE_2D, textureID);

//        FIBITMAP *pImage = FreeImage_ConvertTo32Bits(bitmap);
        int nWidth = FreeImage_GetWidth(tex.get());
        int nHeight = FreeImage_GetHeight(tex.get());
        std::cout<<nWidth<<"x"<<nHeight<<"\n";
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, nWidth, nHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(tex.get()));

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        return true;
    }
}
