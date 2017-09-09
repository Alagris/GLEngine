#ifndef ASSIMP_TEXTURE_HELPERS_H
#define ASSIMP_TEXTURE_HELPERS_H
#include <assimp/types.h>
#include <assimp/scene.h>
namespace gle{
    typedef void (*texture_func)(const aiString & texturePath);
    unsigned int forEveryTexturePathDo(const aiScene *const scene,const texture_func func);
    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiTextureType type,const texture_func func);
}

#endif // ASSIMP_TEXTURE_HELPERS_H
