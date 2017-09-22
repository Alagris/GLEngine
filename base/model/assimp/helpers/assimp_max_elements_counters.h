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
    //vertex normals
    ////////////////

    inline const unsigned int countMaxVertexNormalsInMeshesOfSceneInElements(const aiScene*const scene){
        //because there are exactly as many normals as vertices (and both cosist of equal number of elements),
        //the max is also always the same
        return countMaxVerticesInMeshesOfSceneInElements(scene);
    }
    inline const unsigned int countMaxVertexNormalsInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount){
        //because there are exactly as many normals as vertices (and both cosist of equal number of elements),
        //the max is also always the same
        return countMaxVerticesInMeshesOfScenesInElements(scenes, scenesCount);
    }
    ////////////////
    //textures
    ////////////////
    const unsigned int countMaxTextureVerticesInMeshesOfSceneInElements(const aiScene*const scene);
    const unsigned int countMaxTextureVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);
    ////////////////
    //mixed
    ////////////////
    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerNorInMeshesOfSceneInElements(const aiScene*const scene);
    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerNorInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount);
}

#endif // ASSIMP_MAX_ELEMENTS_COUNTERS_H
