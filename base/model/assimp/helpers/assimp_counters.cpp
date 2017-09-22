#include "assimp_counters.h"
#include <assimp/scene.h>
namespace gle {
    namespace {
        typedef const unsigned int(*countInSceneFunc)(const aiScene*const scene);

        template<countInSceneFunc f>
        const unsigned int genericCountInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            unsigned int out=0;
            for(unsigned int i=0; i<scenesCount; i++) {
                out+=f(scenes[i]);
            }
            return out;
        }

        typedef const unsigned int(*countInMesheFunc)(const aiMesh*const mesh);

        template<countInMesheFunc f>
        const unsigned int genericCountInMeshesOfScene(const aiScene*const scene) {
            unsigned int out=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                out+=f(scene->mMeshes[i]);
            }
            return out;
        }
    }


    namespace index {
        const unsigned int countInMesh(const aiMesh*const mesh) {
            unsigned int out=0;
            for(unsigned int i=0; i< mesh->mNumFaces; i++) {
                out+=mesh->mFaces[i].mNumIndices;
            }
            return out;

        }
        const unsigned int countInMeshesOfScene(const aiScene*const scene) {
            return genericCountInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountInMeshesOfScenes<countInMeshesOfScene>(scenes,scenesCount);
        }


        const unsigned int countInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) {
            unsigned int out=0;
            for(unsigned int i=0; i< mesh->mNumFaces; i++) {
                if(mesh->mFaces[i].mNumIndices==numIndicesPerFace) {
                    out+=numIndicesPerFace;
                }
            }
            return out;

        }
        const unsigned int countInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) {
            unsigned int out=0;
            for(unsigned int i=0; i<scene->mNumMeshes; i++) {
                out+=countInMesh(scene->mMeshes[i],numIndicesPerFace);
            }
            return out;
        }
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) {
            unsigned int out=0;
            for(unsigned int i=0; i<scenesCount; i++) {
                out+=countInMeshesOfScene(scenes[i],numIndicesPerFace);
            }
            return out;
        }
    }

    namespace vertex {
        const unsigned int countInMesh(const aiMesh*const mesh) {
            return mesh->mNumVertices;
        }
        const unsigned int countInMeshesOfScene(const aiScene*const scene) {
            return genericCountInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountInMeshesOfScenes<countInMeshesOfScene>(scenes,scenesCount);
        }
    }

    namespace color {
        const unsigned int countInMeshesOfScene(const aiScene*const scene) {
            return genericCountInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountInMeshesOfScenes<countInMeshesOfScene>(scenes,scenesCount);
        }

        const unsigned int countAllSetsInMeshesOfScene(const aiScene*const scene) {
            return genericCountInMeshesOfScene<countAllSetsInMesh>(scene);
        }
        const unsigned int countAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountInMeshesOfScenes<countAllSetsInMeshesOfScene>(scenes,scenesCount);
        }
    }

    namespace texture {

        const unsigned int countInMeshesOfScene(const aiScene*const scene) {
            return genericCountInMeshesOfScene<countInMesh>(scene);
        }
        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountInMeshesOfScenes<countInMeshesOfScene>(scenes,scenesCount);
        }

        const unsigned int countAllSetsInMeshesOfScene(const aiScene*const scene) {
            return genericCountInMeshesOfScene<countAllSetsInMesh>(scene);
        }
        const unsigned int countAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
            return genericCountInMeshesOfScenes<countAllSetsInMeshesOfScene>(scenes,scenesCount);
        }

        const unsigned int findBiggestDimentionalityInMesh(const aiMesh*const mesh) {
            unsigned int max=0;
            for(unsigned int i=0; i<AI_MAX_NUMBER_OF_TEXTURECOORDS&&mesh->mTextureCoords[i]; i++) {
                const unsigned int c=mesh->mNumUVComponents[i];
                if(c>max) {
                    if(c==3)return 3;
                    max=c;
                }
            }
            return max;
        }

//        /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//        const unsigned int countInMesh(const aiMesh*const mesh) {
//            if(hasAtLeastOneActiveTextureSetInMesh(mesh))
//                return mesh->mNumVertices;
//            else return 0;
//        }
//        /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//        const unsigned int countInMeshesOfScene(const aiScene*const scene) {
//            return genericCountInMeshesOfScene<countTextureVerticesInMesh>(scene);
//        }
//        /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//        const unsigned int countInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//            return genericCountInMeshesOfScenes<countTextureVerticesInMeshesOfScene>(scenes,scenesCount);
//        }
//
//
//        /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//        const unsigned int countAllSetsInMeshesOfScene(const aiScene*const scene) {
//            return genericCountInMeshesOfScene<countTextureVerticesAllSetsInMesh>(scene);
//        }
//        /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
//        const unsigned int countAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
//            return genericCountInMeshesOfScenes<countTextureVerticesAllSetsInMeshesOfScene>(scenes,scenesCount);
//        }


        /** sums number of UV components from all texture channels/sets */
        const unsigned int countSumOfDimentionalitiesInMesh(const aiMesh*const mesh) {
            unsigned int out=0;
            unsigned int n = 0;
            while (n < AI_MAX_NUMBER_OF_TEXTURECOORDS && mesh->mTextureCoords[n]) {
                out+=mesh->mNumUVComponents[n];
                ++n;
            }
            return out;
        }
    }
    /////////////////
    //other
    /////////////////
    const unsigned int countMeshesInScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        unsigned int  out=0;
        for(unsigned int i=0; i<scenesCount; i++)
        {
            out+=scenes[i]->mNumMeshes;
        }
        return out;
    }



}
