#include "texture_cache.h"
#include <vector>
#include "shared_string.h"
#include "shared_string_helpers.h"
#include "texture.h"
#include "cstring"
namespace gle {

    struct CachedItem {
        CachedItem():m_path(),m_tex(){}
        CachedItem(const SharedString & path,const Texture & tex):m_path(path),m_tex(tex) {}
        SharedString m_path;
        Texture m_tex;
    };


    std::vector<CachedItem> cache;

    const bool isValidIndex(const  int index) {
        return index>-1&&index<cache.size();
    }
    SharedString * const getCachedTexturePath(const  int index) {
        return isValidIndex(index)?&(cache[index].m_path):nullptr;
    }
    Texture * const getCachedTexture(const  int index) {
        return isValidIndex(index)?&(cache[index].m_tex):nullptr;
    }

    void addCachedTexture(const char *const path,const Texture & texture){
        addCachedTexture(path,std::strlen(path),texture);
    }
    void addCachedTexture(const char *const path,const unsigned int pathStrLength,const Texture & texture){
        addCachedTexture(SharedString(pathStrLength,path),texture);
    }
    void addCachedTexture(const SharedString & path,const Texture & texture) {
        cache.push_back(CachedItem(path,texture));
    }

    const int findIndexOfCachedTexturePath(const char *const path,const unsigned int pathStrLength) {
        for(unsigned int i=0; i<cache.size(); i++) {
            if(compare(cache[i].m_path,path,pathStrLength))return static_cast<int>(i);
        }
        return -1;
    }
    const int findIndexOfCachedTexturePath(const char *const path) {
        return findIndexOfCachedTexturePath(path,std::strlen(path));
    }
    void purgeTextureCache() {
        cache.clear();
    }
    void removeCachedTexture(const int index) {
        if(isValidIndex(index))
            cache.erase(cache.begin()+index);
    }

    Texture getCachedTextureOrGenerateNew(const char *const path,const FREE_IMAGE_FORMAT formatToUseInCaseTheTextureIsNotCached) {
        const unsigned int pathLen=std::strlen(path);
        const int index=findIndexOfCachedTexturePath(path,pathLen);
        if(index==-1) {
            Texture tex(formatToUseInCaseTheTextureIsNotCached,path);
            addCachedTexture(SharedString(pathLen,path),tex);
            return tex;
        } else {
            return *getCachedTexture(index);
        }
    }
}
