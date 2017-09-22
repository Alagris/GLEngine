#ifndef ASSIMP_MAX_COUNTERS_H
#define ASSIMP_MAX_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    namespace index {

        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount);
        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene);
    }
    namespace vertex {

        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene);
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount);
    }

    namespace color {

        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount);
        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene);
    }
    namespace normal {

        inline const unsigned int countMaxInMeshesOfScene(const aiScene*const scene) {
            //because there are exactly as many normals as vertices,
            //the max is also always the same
            return ::gle::vertex::countMaxInMeshesOfScene(scene);
        }
        inline const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
            //because there are exactly as many normals as vertices,
            //the max is also always the same
            return ::gle::vertex::countMaxInMeshesOfScenes(scenes,scenesCount);
        }
    }
    namespace texture {

        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene);
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount);
    }
    namespace mixed {

        /**finds max among all textures, colors, normals and vertices*/
        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene);
        /**finds max among all textures, colors, normals and vertices*/
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount);
    }
}


#endif // ASSIMP_MAX_COUNTERS_H
