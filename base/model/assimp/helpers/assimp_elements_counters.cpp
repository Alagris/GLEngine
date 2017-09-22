#include "assimp_elements_counters.h"
#include "assimp_counters.h"
#include "assimp_converters.h"
namespace gle {

    namespace index {
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertIndicesNumberToElementsNumber(countInMeshesOfScenes(scenes, scenesCount));
        }
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene) {
            return convertIndicesNumberToElementsNumber(countInMeshesOfScene(scene));
        }
        const unsigned int countElementsInMesh(const aiMesh*const mesh) {
            return convertIndicesNumberToElementsNumber(countInMesh(mesh));
        }

        const unsigned int countElementsInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) {
            return convertIndicesNumberToElementsNumber(countInMesh(mesh,numIndicesPerFace));
        }
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) {
            return convertIndicesNumberToElementsNumber(countInMeshesOfScene(scene,numIndicesPerFace));
        }
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) {
            return convertIndicesNumberToElementsNumber(countInMeshesOfScenes(scenes, scenesCount,numIndicesPerFace));
        }
    }
    namespace vertex {
        const unsigned int countElementsInMesh(const aiMesh*const mesh) {
            return convertVerticesNumberToElementsNumber(countInMesh(mesh));
        }
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene) {
            return convertVerticesNumberToElementsNumber(countInMeshesOfScene(scene));
        }
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertVerticesNumberToElementsNumber(countInMeshesOfScenes(scenes, scenesCount));
        }
    }


    namespace color {
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertColorVerticesNumberToElementsNumber(countInMeshesOfScenes(scenes, scenesCount));
        }
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene) {
            return convertColorVerticesNumberToElementsNumber(countInMeshesOfScene(scene));
        }
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countElementsInMesh(const aiMesh*const mesh) {
            return convertColorVerticesNumberToElementsNumber(countInMesh(mesh));
        }

        const unsigned int countElementsAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertColorVerticesNumberToElementsNumber(countAllSetsInMeshesOfScenes(scenes, scenesCount));
        }
        const unsigned int countElementsAllSetsInMeshesOfScene(const aiScene*const scene) {
            return convertColorVerticesNumberToElementsNumber(countAllSetsInMeshesOfScene( scene));
        }
        const unsigned int countElementsAllSetsInMesh(const aiMesh*const mesh) {
            return convertColorVerticesNumberToElementsNumber(countAllSetsInMesh(mesh));
        }
    }

    namespace normal {
    }

    namespace texture {

        const unsigned int countElementsInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) {
            return countInMesh(mesh)*getDimentionality(mesh,textureSetIndex);
        }
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) {
            unsigned int  out=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                out+=countElementsInMesh(scene->mMeshes[i],textureSetIndex);
            }

            return out;
        }
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) {
            unsigned int  out=0;
            for(unsigned int i=0; i<scenesCount; i++) {
                out+=countElementsInMeshesOfScene(scenes[i],textureSetIndex);
            }
            return out;
        }




        const unsigned int countElementsAllSetsInMesh(const aiMesh*const mesh) {
            return countInMesh(mesh)*countSumOfDimentionalitiesInMesh(mesh);
        }
        const unsigned int countElementsAllSetsInMeshesOfScene(const aiScene*const scene) {
            unsigned int  out=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                out+=countElementsAllSetsInMesh(scene->mMeshes[i]);
            }
            return out;
        }
        const unsigned int countElementsAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            unsigned int  out=0;
            for(unsigned int i=0; i<scenesCount; i++) {
                out+=countElementsAllSetsInMeshesOfScene(scenes[i]);
            }
            return out;
        }

//        inline const unsigned int countElementsAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//            return countInMeshesOfScenes(scenes, scenesCount) * countActiveSetsInMesh(mesh);
//        }
//        inline const unsigned int countElementsAllSetsInMeshesOfScene(const aiScene*const scene) {
//            return countInMeshesOfScene( scene)* countActiveSetsInMesh(mesh);
//        }
//        inline const unsigned int countElementsAllSetsInMesh(const aiMesh*const mesh) {
//            return countInMesh(mesh)* countActiveSetsInMesh(mesh);
//        }
    }




//    ////////////////
//    //vertices
//    ////////////////
//    const unsigned int countVerticesElementsInMesh(const aiMesh*const mesh) {
//        return convertVerticesNumberToElementsNumber(countVerticesInMesh(mesh));
//    }
//    const unsigned int countVerticesElementsInMeshesOfScene(const aiScene*const scene) {
//        return convertVerticesNumberToElementsNumber(countVerticesInMeshesOfScene(scene));
//    }
//    const unsigned int countVerticesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertVerticesNumberToElementsNumber(countVerticesInMeshesOfScenes(scenes,scenesCount));
//    }
//    ////////////////
//    //indices
//    ////////////////
//    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScenes(scenes,scenesCount));
//    }
//    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene) {
//        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScene(scene));
//    }
//    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh) {
//        return convertIndicesNumberToElementsNumber(countIndicesInMesh(mesh));
//    }
//
//    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) {
//        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScenes(scenes,scenesCount,numIndicesPerFace));
//    }
//    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) {
//        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScene(scene,numIndicesPerFace));
//    }
//    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) {
//        return convertIndicesNumberToElementsNumber(countIndicesInMesh(mesh,numIndicesPerFace));
//    }
//    ////////////////
//    //colors
//    ////////////////
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertColorVerticesNumberToElementsNumber(countColorVerticesInMeshesOfScenes(scenes,scenesCount));
//    }
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorElementsInMeshesOfScene(const aiScene*const scene) {
//        return convertColorVerticesNumberToElementsNumber(countColorVerticesInMeshesOfScene(scene));
//    }
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorElementsInMesh(const aiMesh*const mesh) {
//        return convertColorVerticesNumberToElementsNumber(countColorVerticesInMesh(mesh));
//    }
//    ////////////////
//    //textures
//    ////////////////
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureElementsInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) {
////        instead of:
////        const unsigned int uvNum=mesh->mNumUVComponents[textureSetIndex];
////        if(uvNum==1)return convertTexture1DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
////        if(uvNum==2)return convertTexture2DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
////        if(uvNum==3)return convertTexture3DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
////        return 0;
////        we can just do:
//        return countTextureVerticesInMesh(mesh)*(mesh->mNumUVComponents[textureSetIndex]);
//    }
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureElementsInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) {
//        unsigned int  out=0;
//        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
//            out+=countTextureElementsInMesh(scene->mMeshes[i],textureSetIndex);
//        }
//        return out;
//    }
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) {
//        unsigned int  out=0;
//        for(unsigned int i=0; i<scenesCount; i++) {
//            out+=countTextureElementsInMeshesOfScene(scenes[i],textureSetIndex);
//        }
//        return out;
//    }
}
