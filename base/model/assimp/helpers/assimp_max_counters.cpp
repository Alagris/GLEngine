#include "assimp_max_counters.h"
#include "assimp_counters.h"
//#include "assimp_converters.h"
#include "max.h"
namespace gle {
    namespace {
        typedef const unsigned int(*countMaxInSceneFunc)(const aiScene*const scene);


        template<countMaxInSceneFunc f>
        const unsigned int genericCountMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
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
    namespace index {
        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene) {
            return genericCountMaxInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
            return genericCountMaxInMeshesOfScenes<countMaxInMeshesOfScene>(scenes,scenesCount);
        }
    }

    namespace vertex {

        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene) {
            return genericCountMaxInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
            return genericCountMaxInMeshesOfScenes<countMaxInMeshesOfScene>(scenes,scenesCount);
        }
    }
    namespace color {

        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene) {
            return genericCountMaxInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
            return genericCountMaxInMeshesOfScenes<countMaxInMeshesOfScene>(scenes,scenesCount);
        }
    }
//    namespace normal {
//        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene) {
//            return genericCountMaxInMeshesOfScene<countInMesh>(scene);
//        }
//        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
//            return genericCountMaxInMeshesOfScenes<countMaxInMeshesOfScene>(scenes,scenesCount);
//        }
//    }
    namespace mixed {
        /**finds max among all textures, colors,normals and vertices*/
        const unsigned int countMaxInMeshesOfScene(const aiScene*const scene) {
            return max<unsigned int>(::gle::vertex::countMaxInMeshesOfScene(scene),::gle::color::countMaxInMeshesOfScene(scene));
        }

        /**finds max among all textures, colors,normals and vertices*/
        const unsigned int countMaxInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount) {
            return genericCountMaxInMeshesOfScenes<countMaxInMeshesOfScene>(scenes,scenesCount);
        }
    }



}
