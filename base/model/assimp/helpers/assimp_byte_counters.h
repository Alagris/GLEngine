#ifndef ASSIMP_BYTE_COUNTERS_H
#define ASSIMP_BYTE_COUNTERS_H
#include <assimp/scene.h>
#include <assimp/mesh.h>
namespace gle {
    namespace index {
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene);
        const unsigned int countBytesInMesh(const aiMesh*const mesh);
    }
    namespace vertex {
        const unsigned int countBytesInMesh(const aiMesh*const mesh);
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene);
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    }
    namespace color {
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene);
        /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
        const unsigned int countBytesInMesh(const aiMesh*const mesh);
    }
    namespace normal {
        inline const unsigned int countBytesInMesh(const aiMesh*const mesh) {
            return ::gle::vertex::countBytesInMesh(mesh);
        }
        inline const unsigned int countBytesInMeshesOfScene(const aiScene*const scene) {
            return ::gle::vertex::countBytesInMeshesOfScene(scene);
        }
        inline const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return ::gle::vertex::countBytesInMeshesOfScenes(scenes,scenesCount);
        }
    }
    namespace texture {
        const unsigned int countBytesInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex);
        const unsigned int countBytesInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex);
        const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex);
    }
    namespace mixed {
        inline const unsigned int countBytesInMesh(const aiMesh*const mesh,const unsigned int textureSetIndex) {
            return
                gle::texture::countBytesInMesh(mesh,textureSetIndex)+
                gle::vertex::countBytesInMesh(mesh)+
                gle::color::countBytesInMesh(mesh)+
                gle::normal::countBytesInMesh(mesh);
        }
        inline const unsigned int countBytesInMeshesOfScene(const aiScene*const scene,const unsigned int textureSetIndex) {
            return
                gle::texture::countBytesInMeshesOfScene(scene,textureSetIndex)+
                gle::vertex::countBytesInMeshesOfScene(scene)+
                gle::color::countBytesInMeshesOfScene(scene)+
                gle::normal::countBytesInMeshesOfScene(scene);
        }
        inline const unsigned int countBytesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int textureSetIndex) {
            return
                gle::texture::countBytesInMeshesOfScenes(scenes,scenesCount,textureSetIndex)+
                gle::vertex::countBytesInMeshesOfScenes(scenes,scenesCount)+
                gle::color::countBytesInMeshesOfScenes(scenes,scenesCount)+
                gle::normal::countBytesInMeshesOfScenes(scenes,scenesCount);
        }
    }
}
#endif // ASSIMP_BYTE_COUNTERS_H
