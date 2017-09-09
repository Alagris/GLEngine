#include "assimp_texture_helpers.h"

namespace gle {


    unsigned int forEveryTexturePathDo(const aiScene *const scene,const texture_func func) {
        unsigned int out=0;
        for(int i=0; i<scene->mNumMaterials; i++) {
            const aiMaterial * const material=scene->mMaterials[i];
            for(int j=0; j<AI_TEXTURE_TYPE_MAX; j++) {
                const aiTextureType type=static_cast<aiTextureType>(j);
                for(int k=0; k< (material->GetTextureCount( type) ); k++) {
                    aiString path;
                    if(material->GetTexture(type,k,&path)==AI_SUCCESS) {
                        func(path);
                        out++;
                    }
                }
            }
        }
        return out;
    }

    unsigned int forEveryTexturePathDo(const aiScene *const scene,const aiTextureType type,const texture_func func) {
        unsigned int out=0;
        for(int i=0; i<scene->mNumMaterials; i++) {
            const aiMaterial * const material=scene->mMaterials[i];
            for(int k=0; k< (material->GetTextureCount( type) ); k++) {
                aiString path;
                if(material->GetTexture(type,k,&path)==AI_SUCCESS) {
                    func(path);
                    out++;
                }
            }
        }
        return out;
    }
}
