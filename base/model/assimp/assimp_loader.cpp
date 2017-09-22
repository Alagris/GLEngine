#include "GL/glew.h"
#include "assimp_loader.h"
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/cimport.h>
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <iostream>
#include "assimp_scene_vao_vbo_ebo_package.h"
#include "assimp_vao_vbo_ebo_package.h"
#include "assimp_texture_helpers.h"
#include "vertex_attrib_pointer_setup.h"
#include "texture_loader.h"
#include "vertex_array_object_helpers.h"
#include "file_path_concatenation.h"
#include "shared_string.h"
#include "vao_vbo_ebo_package_helpers.h"
#include "render_ready_package.h"
#include "render_ready_package_helpers.h"
#include "assimp_model_node.h"
#include <vector>
#include "assimp_scenes_vao_vbo_ebo_package.h"
#include "render_ready_root_node.h"
#include <memory>

namespace gle {
    namespace {
        class ScenesHolder {
          public:
            ~ScenesHolder() {
                for(unsigned int i=0; i<size(); i++) {
                    aiReleaseImport(scenes[i]);
                }
            }
            const aiScene * const * const getArray() {
                return &(scenes[0]);
            }
            void reserve(const unsigned int n) {
                scenes.reserve(n);
            }
            const unsigned int size() {
                return scenes.size();
            }
            const bool empty() {
                return size()==0;
            }
            void push_back(const aiScene * const scene) {
                scenes.push_back(scene);
            }
            const aiScene * const operator[](const unsigned int n) {
                return scenes[n];
            }
          protected:

          private:
            std::vector<const aiScene *> scenes;

        };
    }


    void debug(aiNode * n) {
        std::cout<<(n->mName.C_Str())<<"\n";
        for(unsigned int i=0; i<n->mNumChildren; i++) {
            debug(n->mChildren[i]);
        }
    }


    const RenderReadyPackage importModels(
        const char ** sourceFiles,
        const unsigned int filesNumber,
        const GLenum usage) {

        ScenesHolder holder;
        holder.reserve(filesNumber);

        for(unsigned int i=0; i<filesNumber; i++) {
            const aiScene *const scene = aiImportFile( sourceFiles[i],
                                         aiProcess_CalcTangentSpace       |
                                         aiProcess_Triangulate            |
                                         aiProcess_JoinIdenticalVertices  |
                                         aiProcess_SortByPType            |
                                         aiProcess_LimitBoneWeights);

            if( !scene)
            {
                std::cerr<< aiGetErrorString()<<"\n";
                continue;
            }
            holder.push_back(scene);
        }
        {
            unsigned int meshIndex=2;
            debug(holder[meshIndex]->mRootNode);
            if(holder[meshIndex]->HasAnimations()){
                std::cout<<"HAS@@@@@@!!!!\n";
            }
            std::cout<<(holder[meshIndex]->mNumAnimations)<<"  HAS1@@@@@@!!!!\n";
            aiAnimation * a =holder[meshIndex]->mAnimations[0];
            std::cout<<(a->mNumChannels)<<"  HAS2@@@@@@!!!!\n";
            for(unsigned int i=0; i<a->mNumChannels; i++) {
                std::cout<<(a->mChannels[i]->mNodeName.C_Str())<<"\n";
            }
//
        }

        unsigned int meshIndex=0;
        if(!holder.empty()) {
            AssimpScenesVaoVboEboPackage out=AssimpScenesVaoVboEboPackage(holder.getArray(),holder.size());
            out.generate(usage);
            RenderReadyPackage output(out,0,0);
            output.reserveRootNodesCapacity(holder.size());
            for(unsigned int i=0,meshIndexOffset=0; i<holder.size(); i++) {
                AssimpModelNode * node = new AssimpModelNode(holder[i],meshIndexOffset);
                output.addRootNode(std::shared_ptr<ModelNode>(node));
                meshIndexOffset+=holder[i]->mNumMeshes;
            }
            forEveryTexturePathInMeshDo(holder[0],meshIndex,[](const aiString & p,const aiTextureType t,const aiMaterial * const m) {
                std::cout<<p.C_Str()<<" -> "<<t<<"\n";
            } );
            if(output.getData().getVBOsNumber()!=0) {
                aiString str;
                getTexturePathInMesh(holder[0],meshIndex,str);
                const SharedString textureFile=swapFileNameInPath(sourceFiles[0],str.C_Str());
                std::cout<<textureFile.getArrayPtr()<<"\n";
                loadTexture(FIF_JPEG, textureFile.getArrayPtr());

            }
            return output;
        }

        return RenderReadyPackage();
    }


    const RenderReadyPackage importModel(
        const char * sourceFile,
        const GLenum usage)
    {
        // Create an instance of the Importer class
        Assimp::Importer importer;
        // And have it read the given file with some example postprocessing
        // Usually - if speed is not the most important aspect for you - you'll
        // propably to request more postprocessing than we do in this example.
        const aiScene *const scene = importer.ReadFile( sourceFile,
                                     aiProcess_CalcTangentSpace       |
                                     aiProcess_Triangulate            |
                                     aiProcess_JoinIdenticalVertices  |
                                     aiProcess_SortByPType);

        // If the import failed, report it
        if( !scene)
        {
            std::cerr<< importer.GetErrorString()<<"\n";
            return false;
        }

        unsigned int meshIndex=0;
        if(scene->HasMeshes()) {
            AssimpSceneVaoVboEboPackage out=AssimpSceneVaoVboEboPackage(scene);
            out.generate(usage);
            RenderReadyPackage output(out,0,0);
            output.addRootNode(std::shared_ptr<ModelNode>(new AssimpModelNode(scene)));
            std::cout<<output.getRootsSize()<<" =size| "<<(*output.getRootNode(0).get().get()).getChildrenCount()<<"\n";
            forEveryTexturePathInMeshDo(scene,meshIndex,[](const aiString & p,const aiTextureType t,const aiMaterial * const m) {
                std::cout<<p.C_Str()<<" -> "<<t<<"\n";
            } );
            if(output.getData().getVBOsNumber()!=0) {
                aiString str;
                getTexturePathInMesh(scene,meshIndex,str);
                const SharedString textureFile=swapFileNameInPath(sourceFile,str.C_Str());
                std::cout<<textureFile.getArrayPtr()<<"\n";
                loadTexture(FIF_JPEG, textureFile.getArrayPtr());

            }
            return output;
        }
        return RenderReadyPackage();
    }



}
