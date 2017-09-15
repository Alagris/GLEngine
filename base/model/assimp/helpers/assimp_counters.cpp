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
    /////////////////
    //vertices
    /////////////////

    const unsigned int countVerticesInMesh(const aiMesh*const mesh) {
        return mesh->mNumVertices;
    }
    const unsigned int countVerticesInMeshesOfScene(const aiScene*const scene) {
        return genericCountInMeshesOfScene<countVerticesInMesh>(scene);
    }
    const unsigned int countVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountInMeshesOfScenes<countVerticesInMeshesOfScene>(scenes,scenesCount);
    }

    /////////////////
    //indices
    /////////////////

    const unsigned int countIndicesInMesh(const aiMesh*const mesh) {
        unsigned int out=0;
        for(unsigned int i=0; i< mesh->mNumFaces; i++) {
            out+=mesh->mFaces[i].mNumIndices;
        }
        return out;

    }
    const unsigned int countIndicesInMeshesOfScene(const aiScene*const scene) {
        return genericCountInMeshesOfScene<countIndicesInMesh>(scene);
    }
    const unsigned int countIndicesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountInMeshesOfScenes<countIndicesInMeshesOfScene>(scenes,scenesCount);
    }


    const unsigned int countIndicesInMesh(const aiMesh*const mesh,const unsigned int numIndicesPerFace) {
        unsigned int out=0;
        for(unsigned int i=0; i< mesh->mNumFaces; i++) {
            if(mesh->mFaces[i].mNumIndices==numIndicesPerFace) {
                out+=numIndicesPerFace;
            }
        }
        return out;

    }
    const unsigned int countIndicesInMeshesOfScene(const aiScene*const scene,const unsigned int numIndicesPerFace) {
        unsigned int out=0;
        for(unsigned int i=0; i<scene->mNumMeshes; i++) {
            out+=countIndicesInMesh(scene->mMeshes[i],numIndicesPerFace);
        }
        return out;
    }
    const unsigned int countIndicesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount,const unsigned int numIndicesPerFace) {
        unsigned int out=0;
        for(unsigned int i=0; i<scenesCount; i++) {
            out+=countIndicesInMeshesOfScene(scenes[i],numIndicesPerFace);
        }
        return out;
    }


    /////////////////
    //colors
    /////////////////

    const unsigned int countColorVerticesInMesh(const aiMesh*const mesh) {
        if(hasAtLeastOneActiveColorSetInMesh(mesh))
            return mesh->mNumVertices;
        else return 0;
    }
    const unsigned int countColorVerticesInMeshesOfScene(const aiScene*const scene) {
        return genericCountInMeshesOfScene<countColorVerticesInMesh>(scene);
    }
    const unsigned int countColorVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountInMeshesOfScenes<countColorVerticesInMeshesOfScene>(scenes,scenesCount);
    }


    const unsigned int countColorVerticesAllSetsInMesh(const aiMesh*const mesh) {
        return (mesh->mNumVertices)*countActiveColorSetsInMesh(mesh);
    }
    const unsigned int countColorVerticesAllSetsInMeshesOfScene(const aiScene*const scene) {
        return genericCountInMeshesOfScene<countColorVerticesAllSetsInMesh>(scene);
    }
    const unsigned int countColorVerticesAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountInMeshesOfScenes<countColorVerticesAllSetsInMeshesOfScene>(scenes,scenesCount);
    }


    /////////////////
    //textures
    /////////////////

    const unsigned int findBiggestTextureDimentionalityInMesh(const aiMesh*const mesh) {
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

    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesInMesh(const aiMesh*const mesh) {
        if(hasAtLeastOneActiveTextureSetInMesh(mesh))
            return mesh->mNumVertices;
        else return 0;
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesInMeshesOfScene(const aiScene*const scene) {
        return genericCountInMeshesOfScene<countTextureVerticesInMesh>(scene);
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountInMeshesOfScenes<countTextureVerticesInMeshesOfScene>(scenes,scenesCount);
    }

    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesAllSetsInMesh(const aiMesh*const mesh) {
        return countActiveTextureSetsInMesh(mesh)*(mesh->mNumVertices);
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesAllSetsInMeshesOfScene(const aiScene*const scene) {
        return genericCountInMeshesOfScene<countTextureVerticesAllSetsInMesh>(scene);
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesAllSetsInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount) {
        return genericCountInMeshesOfScenes<countTextureVerticesAllSetsInMeshesOfScene>(scenes,scenesCount);
    }


    /** sums number of UV components from all texture channels/sets */
    const unsigned int countSumOfTextureDimentionalitiesInMesh(const aiMesh*const mesh) {
        unsigned int out=0;
        unsigned int n = 0;
        while (n < AI_MAX_NUMBER_OF_TEXTURECOORDS && mesh->mTextureCoords[n]) {
            out+=mesh->mNumUVComponents[n];
            ++n;
        }
        return out;
    }



}
