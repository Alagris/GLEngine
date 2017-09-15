#include "assimp_texture_helpers.h"

namespace gle {


    unsigned int forEveryTexturePathDo(const aiScene *const scene,const texture_func func) {
        unsigned int out=0;
        for(int j=0; j<AI_TEXTURE_TYPE_MAX; j++) {
            out+=forEveryTexturePathDo(scene,static_cast<aiTextureType>(j),func);
        }
        return out;
    }

    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiMaterial * const material,const texture_func func) {
        unsigned int out=0;
        for(int j=0; j<AI_TEXTURE_TYPE_MAX; j++) {
            out+=forEveryTexturePathDo(scene,material,static_cast<aiTextureType>(j),func);
        }
        return out;
    }

    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiTextureType type,const texture_func func) {
        unsigned int out=0;
        for(int i=0; i<scene->mNumMaterials; i++) {
            out+=forEveryTexturePathDo(scene,i,type,func);
        }
        return out;
    }

    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiMaterial * const material,const aiTextureType type,const texture_func func) {
        unsigned int out=0;
        for(int k=0; k< (material->GetTextureCount( type) ); k++) {
            aiString path;
            if(material->GetTexture(type,k,&path)==AI_SUCCESS) {
                func(path,type,material);
                out++;
            }
        }
        return out;
    }

    namespace {
        bool getTexturePath_internal(const aiScene *const scene,const aiMaterial * const material,const aiTextureType type, aiString & out) {
            for(int k=0; k< (material->GetTextureCount( type) ); k++) {
                if(material->GetTexture(type,k,&out)==AI_SUCCESS) return true;
            }
            return false;
        }
    }


    void getTexturePath(const aiScene *const scene,const aiMaterial * const material,aiString & out) {
        for(int j=0; j<AI_TEXTURE_TYPE_MAX; j++) {
            if(getTexturePath_internal(scene,material,static_cast<aiTextureType>(j),out))return;
        }
    }
    void getTexturePath(const aiScene *const scene,const aiMaterial * const material,const aiTextureType type, aiString & out) {
        getTexturePath_internal(scene, material, type, out);
    }


}
