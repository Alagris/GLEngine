#ifndef ASSIMP_ALL_SETS_ELEMENTS_COUNTERS_H
#define ASSIMP_ALL_SETS_ELEMENTS_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //colors
    ////////////////
    const unsigned int countColorAllSetsElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countColorAllSetsElementsInMeshesOfScene(const aiScene*const scene);
    const unsigned int countColorAllSetsElementsInMesh(const aiMesh*const mesh);
    ////////////////
    //textures
    ////////////////
    const unsigned int countTextureAllSetsElementsInMesh(const aiMesh*const mesh);
    const unsigned int countTextureAllSetsElementsInMeshesOfScene(const aiScene*const scene);
    const unsigned int countTextureAllSetsElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
}
#endif // ASSIMP_ALL_SETS_ELEMENTS_COUNTERS_H
