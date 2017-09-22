#ifndef ASSIMP_SUM_AND_MAX_COUNTERS_H
#define ASSIMP_SUM_AND_MAX_COUNTERS_H
//#include <assimp/scene.h>
//namespace gle {
//    ////////////////
//    //vertices
//    ////////////////
//
//    void countSumAndMaxVerticesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum);
//    void countSumAndMaxVerticesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum);
//
//    ////////////////
//    //indices
//    ////////////////
//
//    void countSumAndMaxIndicesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum);
//    void countSumAndMaxIndicesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum);
//
//    ////////////////
//    //colors
//    ////////////////
//    void countSumAndMaxColorVerticesInMeshInElements(
//        const aiMesh*const mesh, unsigned int & max, unsigned int & sum);
//    void countSumAndMaxColorVerticesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum);
//    void countSumAndMaxColorVerticesInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum);
//    ////////////////
//    //vertex normals
//    ////////////////
//
//    inline void countSumAndMaxVertexNormalsInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum) {
//        //because there are exactly as many normals as vertices (and both cosist of equal number of elements),
//        //the max and sum is also always the same
//        return countSumAndMaxVerticesInMeshesOfSceneInElements(scene,max,sum);
//    }
//    inline void countSumAndMaxVertexNormalsInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum) {
//        //because there are exactly as many normals as vertices (and both cosist of equal number of elements),
//        //the max and sum is also always the same
//        return countSumAndMaxVerticesInMeshesOfScenesInElements(scenes, scenesCount,max,sum);
//    }
//    ////////////////
//    //textures
//    ////////////////
//    void countSumAndMaxTextureVerticesInMeshInElements(
//        const aiMesh*const mesh, unsigned int & max, unsigned int & sum);
//    void countSumAndMaxTextureVerticesInMeshesOfSceneInElements(
//        const aiScene*const scene,const unsigned int & max,const unsigned int & sum);
//    void countSumAndMaxTextureVerticesInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum);
//    ////////////////
//    //mixed
//    ////////////////
//    /**finds max among all textures, colors and vertices*/
//    void countSumAndMaxTexColVerNorInMeshInElements(
//        const aiMesh*const mesh, unsigned int & max, unsigned int & sum);
//    /**finds max among all textures, colors and vertices*/
//    void countSumAndMaxTexColVerNorInMeshesOfSceneInElements(
//        const aiScene*const scene, unsigned int & max, unsigned int & sum);
//    /**finds max among all textures, colors and vertices*/
//    void countSumAndMaxTexColVerNorInMeshesOfScenesInElements(
//        const aiScene*const*const scenes,const unsigned int scenesCount, unsigned int & max, unsigned int & sum);
//}

#endif // ASSIMP_SUM_AND_MAX_COUNTERS_H
