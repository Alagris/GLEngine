#ifndef ASSIMP_MAX_ELEMENTS_COUNTERS_H
#define ASSIMP_MAX_ELEMENTS_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //vertices
    ////////////////

    const unsigned int countMaxVerticesInMeshesOfSceneInElements(const aiScene*const scene);
    const unsigned int countMaxVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);

    ////////////////
    //indices
    ////////////////

    const unsigned int countMaxIndicesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countMaxIndicesInMeshesOfSceneInElements(const aiScene*const scene);

    ////////////////
    //colors
    ////////////////

    const unsigned int countMaxColorVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countMaxColorVerticesInMeshesOfSceneInElements(const aiScene*const scene);
    ////////////////
    //textures
    ////////////////
    const unsigned int countMaxTextureVerticesInMeshesOfSceneInElements(const aiScene*const scene);
    const unsigned int countMaxTextureVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);
    ////////////////
    //mixed
    ////////////////
    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerInMeshesOfSceneInElements(const aiScene*const scene);
    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);
}

#endif // ASSIMP_MAX_ELEMENTS_COUNTERS_H
