#ifndef ASSIMP_ALL_SETS_BYTE_COUNTERS_H
#define ASSIMP_ALL_SETS_BYTE_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //colors
    ////////////////
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorAllSetsBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorAllSetsBytesInMeshesOfScene(const aiScene*const scene);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorAllSetsBytesInMesh(const aiMesh*const mesh);
    ////////////////
    //textures
    ////////////////
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureAllSetsBytesInMesh(const aiMesh*const mesh);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureAllSetsBytesInMeshesOfScene(const aiScene*const scene);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureAllSetsBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    ////////////////
    //mixed
    ////////////////
    const unsigned int countTexColVerNorAllSetsBytesInMesh(const aiMesh*const mesh);
    const unsigned int countTexColVerNorAllSetsBytesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countTexColVerNorAllSetsBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
}
#endif // ASSIMP_ALL_SETS_BYTE_COUNTERS_H
