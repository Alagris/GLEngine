#include "assimp_elements_counters.h"
#include "assimp_counters.h"
#include "assimp_converters.h"
namespace gle {
    ////////////////
    //vertices
    ////////////////
    const unsigned int countVerticesElementsInMesh(const aiMesh*const mesh) {
        return convertVerticesNumberToElementsNumber(countVerticesInMesh(mesh));
    }
    const unsigned int countVerticesElementsInMeshesOfScene(const aiScene*const scene) {
        return convertVerticesNumberToElementsNumber(countVerticesInMeshesOfScene(scene));
    }
    const unsigned int countVerticesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return convertVerticesNumberToElementsNumber(countVerticesInMeshesOfScenes(scenes,scenesCount));
    }
    ////////////////
    //indices
    ////////////////
    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScenes(scenes,scenesCount));
    }
    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene) {
        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScene(scene));
    }
    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh) {
        return convertIndicesNumberToElementsNumber(countIndicesInMesh(mesh));
    }

    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) {
        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScenes(scenes,scenesCount,numIndicesPerFace));
    }
    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) {
        return convertIndicesNumberToElementsNumber(countIndicesInMeshesOfScene(scene,numIndicesPerFace));
    }
    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) {
        return convertIndicesNumberToElementsNumber(countIndicesInMesh(mesh,numIndicesPerFace));
    }
    ////////////////
    //colors
    ////////////////
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return convertColorVerticesNumberToElementsNumber(countColorVerticesInMeshesOfScenes(scenes,scenesCount));
    }
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorElementsInMeshesOfScene(const aiScene*const scene) {
        return convertColorVerticesNumberToElementsNumber(countColorVerticesInMeshesOfScene(scene));
    }
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorElementsInMesh(const aiMesh*const mesh) {
        return convertColorVerticesNumberToElementsNumber(countColorVerticesInMesh(mesh));
    }
    ////////////////
    //textures
    ////////////////
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureElementsInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) {
//        instead of:
//        const unsigned int uvNum=mesh->mNumUVComponents[textureSetIndex];
//        if(uvNum==1)return convertTexture1DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
//        if(uvNum==2)return convertTexture2DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
//        if(uvNum==3)return convertTexture3DVerticesNumberToElementsNumber(countTextureVerticesInMesh(mesh));
//        return 0;
//        we can just do:
        return countTextureVerticesInMesh(mesh)*(mesh->mNumUVComponents[textureSetIndex]);
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureElementsInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) {
        unsigned int  out=0;
        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
            out+=countTextureElementsInMesh(scene->mMeshes[i],textureSetIndex);
        }
        return out;
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) {
        unsigned int  out=0;
        for(unsigned int i=0; i<scenesCount; i++) {
            out+=countTextureElementsInMeshesOfScene(scenes[i],textureSetIndex);
        }
        return out;
    }
}
