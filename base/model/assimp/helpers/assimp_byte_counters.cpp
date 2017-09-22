#include "assimp_byte_counters.h"
#include "assimp_elements_counters.h"
#include "assimp_converters.h"
namespace gle {

    namespace index {
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertIndexElementsNumberToBytesNumber(countElementsInMeshesOfScenes(scenes,scenesCount));
        }
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene) {
            return convertIndexElementsNumberToBytesNumber(countElementsInMeshesOfScene(scene));
        }
        const unsigned int countBytesInMesh(const aiMesh*const mesh) {
            return convertIndexElementsNumberToBytesNumber(countElementsInMesh(mesh));
        }
    }
    namespace vertex {
        const unsigned int countBytesInMesh(const aiMesh*const mesh) {
            return convertVboElementsNumberToBytesNumber(countElementsInMesh(mesh));
        }
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene) {
            return convertVboElementsNumberToBytesNumber(countElementsInMeshesOfScene(scene));
        }
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertVboElementsNumberToBytesNumber(countElementsInMeshesOfScenes(scenes,scenesCount));
        }
    }
    namespace color {
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return convertVboElementsNumberToBytesNumber(countElementsInMeshesOfScenes(scenes,scenesCount));
        }
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene) {
            return convertVboElementsNumberToBytesNumber(countElementsInMeshesOfScene(scene));
        }
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countBytesInMesh(const aiMesh*const mesh) {
            return convertVboElementsNumberToBytesNumber(countElementsInMesh(mesh));
        }
    }
    namespace normal {
    }
    namespace texture {
        const unsigned int countBytesInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) {
            return convertVboElementsNumberToBytesNumber(countElementsInMesh(mesh,textureSetIndex));
        }
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) {
            return convertVboElementsNumberToBytesNumber(countElementsInMeshesOfScene(scene,textureSetIndex));
        }
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) {
            return convertVboElementsNumberToBytesNumber(countElementsInMeshesOfScenes(scenes,scenesCount,textureSetIndex));
        }
    }


//    ////////////////
//    //vertices
//    ////////////////
//    const unsigned int countVerticesBytesInMesh(const aiMesh*const mesh) {
//        return convertVertexElementsNumberToBytesNumber(countVerticesElementsInMesh(mesh));
//    }
//    const unsigned int countVerticesBytesInMeshesOfScene(const aiScene*const scene) {
//        return convertVertexElementsNumberToBytesNumber(countVerticesElementsInMeshesOfScene(scene));
//    }
//    const unsigned int countVerticesBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertVertexElementsNumberToBytesNumber(countVerticesElementsInMeshesOfScenes(scenes,scenesCount));
//    }
//    ////////////////
//    //indices
//    ////////////////
//    const unsigned int countIndicesBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertIndexElementsNumberToBytesNumber(countIndicesElementsInMeshesOfScenes(scenes,scenesCount));
//    }
//    const unsigned int countIndicesBytesInMeshesOfScene(const aiScene*const scene) {
//        return convertIndexElementsNumberToBytesNumber(countIndicesElementsInMeshesOfScene(scene));
//    }
//    const unsigned int countIndicesBytesInMesh(const aiMesh*const mesh) {
//        return convertIndexElementsNumberToBytesNumber(countIndicesElementsInMesh(mesh));
//    }
//    ////////////////
//    //colors
//    ////////////////
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//        return convertColorElementsNumberToBytesNumber(countColorElementsInMeshesOfScenes(scenes,scenesCount));
//    }
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorBytesInMeshesOfScene(const aiScene*const scene) {
//        return convertColorElementsNumberToBytesNumber(countColorElementsInMeshesOfScene(scene));
//    }
//    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
//    const unsigned int countColorBytesInMesh(const aiMesh*const mesh) {
//        return convertColorElementsNumberToBytesNumber(countColorElementsInMesh(mesh));
//    }
//    ////////////////
//    //textures
//    ////////////////
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureBytesInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) {
//        return  convertTextureElementsNumberToBytesNumber(countTextureElementsInMesh(mesh,textureSetIndex));
//    }
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureBytesInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) {
//        return  convertTextureElementsNumberToBytesNumber(countTextureElementsInMeshesOfScene(scene,textureSetIndex));
//    }
//    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//    const unsigned int countTextureBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) {
//        return  convertTextureElementsNumberToBytesNumber(countTextureElementsInMeshesOfScenes(scenes,scenesCount,textureSetIndex));
//    }


}
