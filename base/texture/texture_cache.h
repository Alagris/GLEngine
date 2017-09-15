#ifndef TEXTURE_CACHE_H
#define TEXTURE_CACHE_H
#include <FreeImage.h>
namespace gle {
    class Texture;
    class SharedString;

    const int findIndexOfCachedTexturePath(const char *const path,const unsigned int pathStrLength);
    const int findIndexOfCachedTexturePath(const char *const path);
    SharedString * const getCachedTexturePath(const int index);
    Texture * const getCachedTexture(const int index);
    inline const Texture * const getCachedTexture(const char *const path) {
        return getCachedTexture(findIndexOfCachedTexturePath(path));
    }

    void addCachedTexture(const char *const path,const unsigned int pathStrLength,const Texture & texture);
    void addCachedTexture(const char *const path,const Texture & texture);
    void addCachedTexture(const SharedString & path,const Texture & texture);
    void purgeTextureCache();
    void removeCachedTexture(const int index);
    inline void removeCachedTexture(const char *const path) {
        return removeCachedTexture(findIndexOfCachedTexturePath(path));
    }
    Texture getCachedTextureOrGenerateNew(const char *const path,const FREE_IMAGE_FORMAT formatToUseInCaseTheTextureIsNotCached);

}
#endif // TEXTURE_CACHE_H
