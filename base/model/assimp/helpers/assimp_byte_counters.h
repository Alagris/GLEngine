#ifndef ASSIMP_BYTE_COUNTERS_H
#define ASSIMP_BYTE_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //vertices
    ////////////////
    const unsigned int countVerticesBytesInMesh(const aiMesh*const mesh);
    const unsigned int countVerticesBytesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countVerticesBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    ////////////////
    //indices
    ////////////////
    const unsigned int countIndicesBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countIndicesBytesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countIndicesBytesInMesh(const aiMesh*const mesh);
    ////////////////
    //colors
    ////////////////
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorBytesInMeshesOfScene(const aiScene*const scene);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorBytesInMesh(const aiMesh*const mesh);
    ////////////////
    //textures
    ////////////////
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureBytesInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureBytesInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex);
    ////////////////
    //mixed
    ////////////////
    inline const unsigned int countTexColVerBytesInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex){
        return countTextureBytesInMesh(mesh,textureSetIndex)+countColorBytesInMesh(mesh)+countVerticesBytesInMesh(mesh);
    }
    inline const unsigned int countTexColVerBytesInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex){
        return countTextureBytesInMeshesOfScene(scene,textureSetIndex)+countColorBytesInMeshesOfScene(scene)+countVerticesBytesInMeshesOfScene(scene);
    }
    inline const unsigned int countTexColVerBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex){
        return countTextureBytesInMeshesOfScenes(scenes,scenesCount,textureSetIndex)+countColorBytesInMeshesOfScenes(scenes,scenesCount)+countVerticesBytesInMeshesOfScenes(scenes,scenesCount);
    }
}
#endif // ASSIMP_BYTE_COUNTERS_H
