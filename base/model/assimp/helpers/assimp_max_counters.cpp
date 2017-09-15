#include "assimp_max_counters.h"
#include "assimp_counters.h"
#include "assimp_converters.h"
#include "max.h"
namespace gle {
    namespace {
        typedef const unsigned int(*countMaxInSceneFunc)(const aiScene*const scene);


        template<countMaxInSceneFunc f>
        const unsigned int genericCountMaxInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            unsigned int max=0;
            for(unsigned int i=0; i<scenesCount; i++) {
                compareMax<unsigned int>( f(scenes[i]),max);
            }
            return max;
        }

        typedef const unsigned int(*countInMeshFunc)(const aiMesh*const mesh);

        template<countInMeshFunc f>
        const unsigned int genericCountMaxInMeshesOfScene(const aiScene*const scene) {
            unsigned int max=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                compareMax<unsigned int>(f(scene->mMeshes[i]),max);
            }
            return max;
        }
    }
    /////////////////
    //vertices
    /////////////////

    const unsigned int countMaxVerticesInMeshesOfScene(const aiScene*const scene) {
        return genericCountMaxInMeshesOfScene<countVerticesInMesh>(scene);
    }
    const unsigned int countMaxVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxVerticesInMeshesOfScene>(scenes,scenesCount);
    }

    /////////////////
    //indices
    /////////////////

    const unsigned int countMaxIndicesInMeshesOfScene(const aiScene*const scene) {
        return genericCountMaxInMeshesOfScene<countIndicesInMesh>(scene);
    }
    const unsigned int countMaxIndicesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxIndicesInMeshesOfScene>(scenes,scenesCount);
    }

    /////////////////
    //colors
    /////////////////


    const unsigned int countMaxColorVerticesInMeshesOfScene(const aiScene*const scene) {
        return genericCountMaxInMeshesOfScene<countColorVerticesInMesh>(scene);
    }
    const unsigned int countMaxColorVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxColorVerticesInMeshesOfScene>(scenes,scenesCount);
    }

    /////////////////
    //textures
    /////////////////
    const unsigned int countMaxTextureVerticesInMeshesOfScene(const aiScene*const scene) {
        return genericCountMaxInMeshesOfScene<countTextureVerticesInMesh>(scene);
    }
    const unsigned int countMaxTextureVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxTextureVerticesInMeshesOfScene>(scenes,scenesCount);
    }

    ////////////////
    //mixed
    ////////////////

    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxTexColVerInMeshesOfScene>(scenes,scenesCount);
    }




}
