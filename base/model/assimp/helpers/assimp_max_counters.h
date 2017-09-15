#ifndef ASSIMP_MAX_COUNTERS_H
#define ASSIMP_MAX_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //vertices
    ////////////////

    const unsigned int countMaxVerticesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countMaxVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);

    ////////////////
    //indices
    ////////////////

    const unsigned int countMaxIndicesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countMaxIndicesInMeshesOfScene(const aiScene*const scene);

    ////////////////
    //colors
    ////////////////

    const unsigned int countMaxColorVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countMaxColorVerticesInMeshesOfScene(const aiScene*const scene);
    ////////////////
    //textures
    ////////////////
    const unsigned int countMaxTextureVerticesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countMaxTextureVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    ////////////////
    //mixed
    ////////////////
    /**finds max among all textures, colors and vertices*/
    inline const unsigned int countMaxTexColVerInMeshesOfScene(const aiScene*const scene) {
        //no need for counting textures and colors because count of vertices is always bigger or equal
        return countMaxVerticesInMeshesOfScene(scene);
    }
    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);

}


#endif // ASSIMP_MAX_COUNTERS_H
