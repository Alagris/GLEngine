#ifndef ASSIMP_COUNTERS_H
#define ASSIMP_COUNTERS_H
#include <assimp/scene.h>
#include "assimp_helpers.h"
namespace gle {
    namespace index {
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countInMeshesOfScene(const aiScene*const scene);
        const unsigned int countInMesh(const aiMesh*const mesh);

        const unsigned int countInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace);
        const unsigned int countInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace);
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace);
    }
    namespace vertex {
        const unsigned int countInMesh(const aiMesh*const mesh);
        const unsigned int countInMeshesOfScene(const aiScene*const scene);
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    }


    namespace color {
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countInMeshesOfScene(const aiScene*const scene);
        inline const unsigned int countInMesh(const aiMesh*const mesh) {
            if(!hasAtLeastOneActiveSetInMesh(mesh))return 0;
            return gle::vertex::countInMesh(mesh);
        }

        const unsigned int countAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countAllSetsInMeshesOfScene(const aiScene*const scene);
        inline const unsigned int countAllSetsInMesh(const aiMesh*const mesh) {
            return countInMesh(mesh)* countActiveSetsInMesh(mesh);
        }
    }
    namespace normal {
        inline const unsigned int countInMesh(const aiMesh*const mesh) {
            return gle::vertex::countInMesh(mesh);
        }
        inline const unsigned int countInMeshesOfScene(const aiScene*const scene) {
            return gle::vertex::countInMeshesOfScene( scene);
        }
        inline const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return gle::vertex::countInMeshesOfScenes(scenes, scenesCount);
        }
    }
    namespace texture {


        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countInMeshesOfScene(const aiScene*const scene);
        inline const unsigned int countInMesh(const aiMesh*const mesh) {
            if(!hasAtLeastOneActiveSetInMesh(mesh))return 0;
            return gle::vertex::countInMesh(mesh);
        }

        const unsigned int countAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countAllSetsInMeshesOfScene(const aiScene*const scene);
        inline const unsigned int countAllSetsInMesh(const aiMesh*const mesh) {
            return countInMesh(mesh)* countActiveSetsInMesh(mesh);
        }

        const unsigned int findBiggestDimentionalityInMesh(const aiMesh*const mesh);

        /** sums number of UV components from all texture channels/sets */
        const unsigned int countSumOfDimentionalitiesInMesh(const aiMesh*const mesh);
    }
    ////////////////
    //other
    ////////////////
    const unsigned int countMeshesInScenes(const aiScene*const*const scenes,unsigned int scenesCount);
}

#endif // ASSIMP_COUNTERS_H
