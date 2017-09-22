#include "assimp_max_elements_counters.h"
#include "assimp_counters.h"
#include "assimp_elements_counters.h"
#include "assimp_max_counters.h"
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


    }
    namespace index {

        const unsigned int countMaxElementsMeshesOfScene(const aiScene*const scene) {
            return convertIndicesNumberToElementsNumber(countMaxInMeshesOfScene(scene));
        }
        const unsigned int countMaxElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertIndicesNumberToElementsNumber(countMaxInMeshesOfScenes(scenes,scenesCount));
        }
    }

    namespace vertex {

        const unsigned int countMaxElementsMeshesOfScene(const aiScene*const scene) {
            return convertVerticesNumberToElementsNumber(countMaxInMeshesOfScene(scene));
        }
        const unsigned int countMaxElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertVerticesNumberToElementsNumber(countMaxInMeshesOfScenes(scenes,scenesCount));
        }
    }


//    /////////////////
//    //indices
//    /////////////////
//
//    const unsigned int countMaxIndicesInMeshesOfSceneInElements(const aiScene*const scene) {
//        return convertIndicesNumberToElementsNumber(countMaxIndicesInMeshesOfScene(scene));
//    }
//    const unsigned int countMaxIndicesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertIndicesNumberToElementsNumber(countMaxIndicesInMeshesOfScenes(scenes,scenesCount));
//    }

    namespace color {

        const unsigned int countMaxElementsMeshesOfScene(const aiScene*const scene) {
            return convertColorVerticesNumberToElementsNumber(countMaxInMeshesOfScene(scene));
        }
        const unsigned int countMaxElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertColorVerticesNumberToElementsNumber(countMaxInMeshesOfScenes(scenes,scenesCount));
        }
    }

//    /////////////////
//    //colors
//    /////////////////
//
//
//    const unsigned int countMaxColorVerticesInMeshesOfSceneInElements(const aiScene*const scene) {
//        return convertColorVerticesNumberToElementsNumber(countMaxColorVerticesInMeshesOfScene(scene));
//    }
//    const unsigned int countMaxColorVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertColorVerticesNumberToElementsNumber(countMaxColorVerticesInMeshesOfScenes(scenes,scenesCount));
//    }

    namespace texture {
        const unsigned int countMaxElementsMeshesOfScene(const aiScene*const scene) {
            unsigned int max=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                const unsigned int verticesNum=countInMesh(scene->mMeshes[i]);
                const unsigned int textureMaxDimentionality=findBiggestDimentionalityInMesh(scene->mMeshes[i]);
                const unsigned int elementsMaxNumber=verticesNum*textureMaxDimentionality;
                compareMax<unsigned int>(elementsMaxNumber,max);
            }
            return max;
        }
        const unsigned int countMaxElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountMaxInMeshesOfScenes<countMaxElementsMeshesOfScene>(scenes,scenesCount);
        }
    }

    namespace mixed {
        /**finds max among all textures, colors and vertices*/
        const unsigned int countMaxElementsMeshesOfScene(const aiScene*const scene) {
            unsigned int max=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                const bool hasColors=::gle::color::hasAtLeastOneActiveSetInMesh(scene->mMeshes[i]);
                const unsigned int verticesNum=::gle::vertex::countInMesh(scene->mMeshes[i]);
                const unsigned int elementsMaxNumber=verticesNum*(hasColors?SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS:SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS);
                compareMax<unsigned int>(elementsMaxNumber,max);
            }
            return max;
        }

        /**finds max among all textures, colors and vertices*/
        const unsigned int countMaxElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountMaxInMeshesOfScenes<countMaxElementsMeshesOfScene>(scenes,scenesCount);
        }
    }



}
