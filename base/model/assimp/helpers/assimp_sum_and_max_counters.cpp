#include "assimp_sum_and_max_counters.h"
//#include "max.h"
//#include "assimp_counters.h"
//#include "assimp_elements_counters.h"
//#include "assimp_all_sets_elements_counters.h"
//
//
//
//namespace gle {
//
//
//    namespace {
//        typedef void(*countInSceneFunc)(const aiScene*const scene, unsigned int & max, unsigned int & sum);
//
//        template<countInSceneFunc f>
//        void genericCountInMeshesOfScenes(const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//            for(unsigned int i=0; i<scenesCount; i++) {
//                f(scenes[i],max,sum);
//            }
//        }
//
//        typedef const unsigned int(*countInMeshFunc)(const aiMesh*const mesh);
//
//        template<countInMeshFunc f>
//        void genericCountInMeshesOfScene(const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
//                unsigned int inMesh=f(scene->mMeshes[i]);
//                sum+=inMesh;
//                compareMax<unsigned int>( inMesh,max);
//            }
//        }
//
//
//        typedef void(*countInMeshFunc1)(const aiMesh*const mesh, unsigned int & max, unsigned int & sum);
//
//        template<countInMeshFunc1 f>
//        void genericCountInMeshesOfScene1(const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
//                f(scene->mMeshes[i],max,sum);
//            }
//        }
//    }
//
//    ////////////////
//    //vertices
//    ////////////////
//
//    void countSumAndMaxVerticesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScene<countVerticesElementsInMesh>(scene,max,sum);
//    }
//    void countSumAndMaxVerticesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScenes<countSumAndMaxVerticesInMeshesOfSceneInElements>(scenes,scenesCount,max,sum);
//    }
//
//    ////////////////
//    //indices
//    ////////////////
//
//    void countSumAndMaxIndicesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScene<countIndicesElementsInMesh>(scene,max,sum);
//    }
//
//    void countSumAndMaxIndicesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScenes<countSumAndMaxIndicesInMeshesOfSceneInElements>(scenes,scenesCount,max,sum);
//    }
//
//
//    ////////////////
//    //colors
//    ////////////////
//
//    void countSumAndMaxColorVerticesInMeshInElements(
//        const aiMesh*const mesh, unsigned int & max, unsigned int & sum)
//    {
//        unsigned int inMesh=countColorElementsInMesh(mesh);
//        sum+=inMesh*countActiveColorSetsInMesh(mesh);
//        compareMax<unsigned int>( inMesh,max);
//    }
//
//    void countSumAndMaxColorVerticesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScene1<countSumAndMaxColorVerticesInMeshInElements>(scene,max,sum);
//    }
//    void countSumAndMaxColorVerticesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScenes<countSumAndMaxColorVerticesInMeshesOfSceneInElements>(scenes,scenesCount,max,sum);
//    }
//
//    ////////////////
//    //textures
//    ////////////////
//    void countSumAndMaxTextureVerticesInMeshInElements(
//        const aiMesh*const mesh, unsigned int & max, unsigned int & sum)
//    {
//        for(unsigned int set=0; set<countActiveTextureSetsInMesh(mesh); set++) {
//            unsigned int inSet=countTextureElementsInMesh(mesh,set);
//            sum+=inSet;
//            compareMax<unsigned int>( inSet,max);
//        }
//    }
//    void countSumAndMaxTextureVerticesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum)
//    {
//        genericCountInMeshesOfScene1<countSumAndMaxTextureVerticesInMeshInElements>(scene,max,sum);
//    }
//    void countSumAndMaxTextureVerticesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScenes<countSumAndMaxTextureVerticesInMeshesOfSceneInElements>(scenes,scenesCount,max,sum);
//    }
//    ////////////////
//    //mixed
//    ////////////////
//    /**finds max among all textures, colors and vertices*/
//    void countSumAndMaxTexColVerNorInMeshInElements(
//        const aiMesh*const mesh, unsigned int & max, unsigned int & sum) {
//        unsigned int vertices = countVerticesElementsInMesh(mesh);
//        sum+=vertices+
//             countVertexNormalsElementsInMesh(mesh)+
//             countTextureAllSetsElementsInMesh(mesh);;
//        unsigned int colors = countColorElementsInMesh(mesh);
//        sum+=colors*countActiveColorSetsInMesh(mesh);
//        if(colors>vertices) {
//            compareMax(colors,max);
//        } else {
//            compareMax(vertices,max);
//        }
//    }
//
//    /**finds max among all textures, colors and vertices*/
//    void countSumAndMaxTexColVerNorInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScene1<countSumAndMaxTexColVerNorInMeshInElements>(scene,max,sum);
//    }
//    /**finds max among all textures, colors and vertices*/
//    void countSumAndMaxTexColVerNorInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//        genericCountInMeshesOfScenes<countSumAndMaxTexColVerNorInMeshesOfSceneInElements>(scenes,scenesCount,max,sum);
//    }
//}
