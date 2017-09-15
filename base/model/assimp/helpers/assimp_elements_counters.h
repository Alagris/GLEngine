#ifndef ASSIMP_ELEMENTS_COUNTERS_H
#define ASSIMP_ELEMENTS_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //vertices
    ////////////////
    const unsigned int countVerticesElementsInMesh(const aiMesh*const mesh);
    const unsigned int countVerticesElementsInMeshesOfScene(const aiScene*const scene);
    const unsigned int countVerticesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    ////////////////
    //indices
    ////////////////
    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene);
    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh);

    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) ;
    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) ;
    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) ;
    ////////////////
    //colors
    ////////////////
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorElementsInMeshesOfScene(const aiScene*const scene);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorElementsInMesh(const aiMesh*const mesh);
    ////////////////
    //textures
    ////////////////
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureElementsInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureElementsInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex);
}
#endif // ASSIMP_ELEMENTS_COUNTERS_H
