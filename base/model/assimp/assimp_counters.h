#ifndef ASSIMP_COUNTERS_H
#define ASSIMP_COUNTERS_H
#include <assimp/scene.h>
namespace gle {
    ////////////////
    //vertices
    ////////////////

    const unsigned int countVerticesInMesh(const aiMesh*const mesh);
    const unsigned int countVerticesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);

    ////////////////
    //indices
    ////////////////

    const unsigned int countIndicesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    const unsigned int countIndicesInMeshesOfScene(const aiScene*const scene);
    const unsigned int countIndicesInMesh(const aiMesh*const mesh);

    ////////////////
    //colors
    ////////////////

    inline const bool hasAtLeastOneActiveColorSetInMesh(const aiMesh*const mesh) {
        return mesh->HasVertexColors(0);
    }

    inline const unsigned int countActiveColorSetsInMesh(const aiMesh*const mesh) {
        return mesh->GetNumColorChannels();
    }

    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorVerticesInMeshesOfScene(const aiScene*const scene);
    /**This actually counts only color vertices of single set. If you need all sum of sets then multiply it times the output of countActiveColorSetsInMesh() */
    const unsigned int countColorVerticesInMesh(const aiMesh*const mesh);
    ////////////////
    //textures
    ////////////////
    inline const bool hasAtLeastOneActiveTextureSetInMesh(const aiMesh*const mesh) {
        return mesh->HasTextureCoords(0);
    }
    inline const unsigned int countActiveTextureSetsInMesh(const aiMesh*const mesh) {
        return mesh->GetNumUVChannels();
    }
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesInMeshesOfScenes(const aiScene*const*const scenes,unsigned int scenesCount);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesInMeshesOfScene(const aiScene*const scene);
    /**This actually counts only texture vertices of single set. If you need all sum of sets then multiply it times the output of countActiveTextureSetsInMesh() */
    const unsigned int countTextureVerticesInMesh(const aiMesh*const mesh);

}

#endif // ASSIMP_COUNTERS_H
