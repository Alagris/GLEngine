#ifndef ASSIMP_TEXTURE_HELPERS_H
#define ASSIMP_TEXTURE_HELPERS_H
#include <assimp/types.h>
#include <assimp/scene.h>
namespace gle {
    typedef void (*texture_func)(const aiString & texturePath,const aiTextureType type,const aiMaterial * const material);
    unsigned int forEveryTexturePathDo(const aiScene *const scene,const texture_func func);
    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiTextureType type,const texture_func func);

    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiMaterial * const material,const texture_func func);
    inline unsigned int forEveryTexturePathDo(const aiScene *const scene,const unsigned int materialIndex,const texture_func func) {
        return forEveryTexturePathDo(scene,scene->mMaterials[materialIndex],func);
    }
    inline unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiMesh * const mesh,const texture_func func) {
        return forEveryTexturePathDo(scene,mesh->mMaterialIndex,func);
    }
    inline unsigned int forEveryTexturePathInMeshDo(const aiScene *const scene,const unsigned int meshIndex,const texture_func func) {
        return forEveryTexturePathDo(scene,scene->mMeshes[meshIndex],func);
    }

    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiMaterial * const material,const aiTextureType type,const texture_func func) ;
    inline unsigned int forEveryTexturePathDo(const aiScene *const scene,const unsigned int materialIndex,const aiTextureType type,const texture_func func) {
        return forEveryTexturePathDo(scene,scene->mMaterials[materialIndex],type,func);
    }
    inline unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiMesh *const mesh,const aiTextureType type,const texture_func func) {
        return forEveryTexturePathDo(scene,mesh->mMaterialIndex,type,func);
    }
    inline unsigned int forEveryTexturePathInMeshDo(const aiScene *const scene,const unsigned int meshIndex,const aiTextureType type,const texture_func func) {
        return forEveryTexturePathDo(scene,scene->mMeshes[meshIndex],type,func);
    }

    void getTexturePath(const aiScene *const scene,const aiMaterial * const material,aiString & out);
    inline void getTexturePath(const aiScene *const scene,const unsigned int materialIndex,aiString & out) {
        return getTexturePath(scene,scene->mMaterials[materialIndex],out);
    }
    inline void getTexturePath(const aiScene *const scene,const aiMesh * const mesh,aiString & out) {
        return getTexturePath(scene,mesh->mMaterialIndex,out);
    }
    inline void getTexturePathInMesh(const aiScene *const scene,const unsigned int meshIndex,aiString & out) {
        return getTexturePath(scene,scene->mMeshes[meshIndex],out);
    }

    void getTexturePath(const aiScene *const scene,const aiMaterial * const material,const aiTextureType type,aiString & out) ;
    inline void getTexturePath(const aiScene *const scene,const unsigned int materialIndex,const aiTextureType type,aiString & out) {
        return getTexturePath(scene,scene->mMaterials[materialIndex],type,out);
    }
    inline void getTexturePath(const aiScene *const scene,const aiMesh *const mesh,const aiTextureType type,aiString & out) {
        return getTexturePath(scene,mesh->mMaterialIndex,type,out);
    }
    inline void getTexturePathInMesh(const aiScene *const scene,const unsigned int meshIndex,const aiTextureType type,aiString & out) {
        return getTexturePath(scene,scene->mMeshes[meshIndex],type,out);
    }
}

#endif // ASSIMP_TEXTURE_HELPERS_H
