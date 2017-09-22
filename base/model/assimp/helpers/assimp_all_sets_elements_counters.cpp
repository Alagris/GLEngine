#include "assimp_all_sets_elements_counters.h"
//#include "assimp_counters.h"
//#include "assimp_converters.h"
namespace gle {
//    ////////////////
//    //colors
//    ////////////////
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorAllSetsElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertColorVerticesNumberToElementsNumber(countColorVerticesAllSetsInMeshesOfScenes(scenes,scenesCount));
//    }
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorAllSetsElementsInMeshesOfScene(const aiScene*const scene) {
//        return convertColorVerticesNumberToElementsNumber(countColorVerticesAllSetsInMeshesOfScene(scene));
//    }
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorAllSetsElementsInMesh(const aiMesh*const mesh) {
//        return convertColorVerticesNumberToElementsNumber(countColorVerticesAllSetsInMesh(mesh));
//    }
//    ////////////////
//    //textures
//    ////////////////
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureAllSetsElementsInMesh(const aiMesh*const mesh) {
//        return countSumOfTextureDimentionalitiesInMesh(mesh)*(mesh->mNumVertices);
//    }
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureAllSetsElementsInMeshesOfScene(const aiScene*const scene) {
//        unsigned int  out=0;
//        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
//            out+=countTextureAllSetsElementsInMesh(scene->mMeshes[i]);
//        }
//        return out;
//    }
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureAllSetsElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        unsigned int  out=0;
//        for(unsigned int i=0; i<scenesCount; i++) {
//            out+=countTextureAllSetsElementsInMeshesOfScene(scenes[i]);
//        }
//        return out;
//    }

}
