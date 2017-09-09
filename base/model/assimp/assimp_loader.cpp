#include "GL/glew.h"
#include "assimp_loader.h"
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <iostream>
#include "vertex_array_object.h"
#include "assimp_vertex_array_object_generators.h"
#include "assimp_texture_helpers.h"
namespace gle {

    bool importModel( const char * pFile,VertexArrayObject & vaoOutput)
    {
        // Create an instance of the Importer class
        Assimp::Importer importer;
        // And have it read the given file with some example postprocessing
        // Usually - if speed is not the most important aspect for you - you'll
        // propably to request more postprocessing than we do in this example.
        const aiScene *const scene = importer.ReadFile( pFile,
                                     aiProcess_CalcTangentSpace       |
                                     aiProcess_Triangulate            |
                                     aiProcess_JoinIdenticalVertices  |
                                     aiProcess_SortByPType);
        forEveryTexturePathDo(scene,[](const aiString & p) {
            std::cout<<p.C_Str()<<"\n";
        });
        // If the import failed, report it
        if( !scene)
        {
            std::cerr<< importer.GetErrorString()<<"\n";
            return false;
        }

        if(scene->HasMeshes()) {
            vaoOutput= generateVAO(scene->mMeshes[0],GL_STATIC_DRAW);
        }
        // Now we can access the file's contents.
        // We're done. Everything will be cleaned up by the importer destructor
        return true;
    }



}
