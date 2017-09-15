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
    /////////////////
    //vertices
    /////////////////

    const unsigned int countMaxVerticesInMeshesOfSceneInElements(const aiScene*const scene) {
        return convertVerticesNumberToElementsNumber(countMaxVerticesInMeshesOfScene(scene));
    }
    const unsigned int countMaxVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
        return convertVerticesNumberToElementsNumber(countMaxVerticesInMeshesOfScenes(scenes,scenesCount));
    }

    /////////////////
    //indices
    /////////////////

    const unsigned int countMaxIndicesInMeshesOfSceneInElements(const aiScene*const scene) {
        return convertIndicesNumberToElementsNumber(countMaxIndicesInMeshesOfScene(scene));
    }
    const unsigned int countMaxIndicesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
        return convertIndicesNumberToElementsNumber(countMaxIndicesInMeshesOfScenes(scenes,scenesCount));
    }

    /////////////////
    //colors
    /////////////////


    const unsigned int countMaxColorVerticesInMeshesOfSceneInElements(const aiScene*const scene) {
        return convertColorVerticesNumberToElementsNumber(countMaxColorVerticesInMeshesOfScene(scene));
    }
    const unsigned int countMaxColorVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
        return convertColorVerticesNumberToElementsNumber(countMaxColorVerticesInMeshesOfScenes(scenes,scenesCount));
    }

    /////////////////
    //textures
    /////////////////
    const unsigned int countMaxTextureVerticesInMeshesOfSceneInElements(const aiScene*const scene) {
        unsigned int max=0;
        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
            const unsigned int verticesNum=countTextureVerticesInMesh(scene->mMeshes[i]);
            const unsigned int textureMaxDimentionality=findBiggestTextureDimentionalityInMesh(scene->mMeshes[i]);
            const unsigned int elementsMaxNumber=verticesNum*textureMaxDimentionality;
            compareMax<unsigned int>(elementsMaxNumber ,max);
        }
        return max;
    }
    const unsigned int countMaxTextureVerticesInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxTextureVerticesInMeshesOfSceneInElements>(scenes,scenesCount);
    }

    ////////////////
    //mixed
    ////////////////

    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerInMeshesOfSceneInElements(const aiScene*const scene) {
        unsigned int max=0;
        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
            const bool hasColors=hasAtLeastOneActiveColorSetInMesh(scene->mMeshes[i]);
            const unsigned int verticesNum=countVerticesInMesh(scene->mMeshes[i]);
            const unsigned int elementsMaxNumber=verticesNum*(hasColors?SIZE_OF_ASSIMP_COLOR_TYPE_IN_ELEMENTS:SIZE_OF_ASSIMP_VERTEX_TYPE_IN_ELEMENTS);
            compareMax<unsigned int>(elementsMaxNumber ,max);
        }
        return max;
    }

    /**finds max among all textures, colors and vertices*/
    const unsigned int countMaxTexColVerInMeshesOfScenesInElements(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountMaxInMeshesOfScenes<countMaxTexColVerInMeshesOfSceneInElements>(scenes,scenesCount);
    }




}
