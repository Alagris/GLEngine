#ifndef ASSIMP_ELEMENTS_COUNTERS_H
#define ASSIMP_ELEMENTS_COUNTERS_H
#include <assimp/scene.h>
namespace gle {

    namespace index {
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene);
        const unsigned int countElementsInMesh(const aiMesh*const mesh);

        const unsigned int countElementsInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace);
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace);
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace);
    }
    namespace vertex {
        const unsigned int countElementsInMesh(const aiMesh*const mesh);
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene);
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    }


    namespace color {
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) ;
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene) ;
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countElementsInMesh(const aiMesh*const mesh) ;
        const unsigned int countElementsAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) ;
        const unsigned int countElementsAllSetsInMeshesOfScene(const aiScene*const scene) ;
        const unsigned int countElementsAllSetsInMesh(const aiMesh*const mesh) ;
    }
    namespace normal {
        inline const unsigned int countElementsInMesh(const aiMesh*const mesh) {
            return ::gle::vertex::countElementsInMesh(mesh);
        }
        inline const unsigned int countElementsInMeshesOfScene(const aiScene*const scene) {
            return ::gle::vertex::countElementsInMeshesOfScene( scene);
        }
        inline const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return ::gle::vertex::countElementsInMeshesOfScenes(scenes, scenesCount);
        }
    }
    namespace texture {


        const unsigned int countElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) ;
        const unsigned int countElementsInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) ;
        const unsigned int countElementsInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) ;

        const unsigned int countElementsAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) ;
        const unsigned int countElementsAllSetsInMeshesOfScene(const aiScene*const scene) ;
        const unsigned int countElementsAllSetsInMesh(const aiMesh*const mesh) ;
    }

//    ////////////////
//    //vertices
//    ////////////////
//    const unsigned int countVerticesElementsInMesh(const aiMesh*const mesh);
//    const unsigned int countVerticesElementsInMeshesOfScene(const aiScene*const scene);
//    const unsigned int countVerticesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
//    ////////////////
//    //indices
//    ////////////////
//    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
//    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene);
//    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh);
//
//    const unsigned int countIndicesElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) ;
//    const unsigned int countIndicesElementsInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) ;
//    const unsigned int countIndicesElementsInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) ;
//    ////////////////
//    //colors
//    ////////////////
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorElementsInMeshesOfScene(const aiScene*const scene);
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorElementsInMesh(const aiMesh*const mesh);
//    ////////////////
//    //normals
//    ////////////////
//    inline const unsigned int countVertexNormalsElementsInMesh(const aiMesh*const mesh){
//        return countVerticesElementsInMesh(mesh);
//    }
//    inline const unsigned int countVertexNormalsElementsInMeshesOfScene(const aiScene*const scene){
//        return countVerticesElementsInMeshesOfScene(scene);
//    }
//    inline const unsigned int countVertexNormalsElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount){
//        return countVerticesElementsInMeshesOfScenes(scenes,scenesCount);
//    }
//    ////////////////
//    //textures
//    ////////////////
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureElementsInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex);
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureElementsInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex);
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureElementsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex);
}
#endif // ASSIMP_ELEMENTS_COUNTERS_H
