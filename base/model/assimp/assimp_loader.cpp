#include "GL/glew.h"
#include "assimp_loader.h"
#include <assimp/Importer.hpp>      // C++ importer interface
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
namespace gle {


    bool importModel(
        const char * pFile,
//        VertexArrayObject & output,
        RenderReadyPackage & output,
        const GLenum usage,
        const GLuint program,
        const GLchar *const vertexInputLocation,
        const GLchar *const colorInputLocation,
        const GLchar *const textureInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA)
    {
        GLint vertexInputLoc=-1;
        GLint colorInputLoc=-1;
        GLint textureInputLoc=-1;
        if(findInputLocations(program,vertexInputLocation,colorInputLocation,textureInputLocation,vertexInputLoc,colorInputLoc,textureInputLoc)) {
            return importModel(pFile,output,usage,static_cast<GLuint>(vertexInputLoc),colorInputLoc,textureInputLoc,defaultColorR,defaultColorG,defaultColorB,defaultColorA);
        }
        return false;
    }

    bool importModel(
        const char * pFile,
        RenderReadyPackage & output,
        const GLenum usage,
        const GLuint vertexInputLocation,
        const GLint colorInputLocation,
        const GLint textureInputLocation,
        const GLfloat defaultColorR,
        const GLfloat defaultColorG,
        const GLfloat defaultColorB,
        const GLfloat defaultColorA)
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
            output=RenderReadyPackage(out,0,0,vertexInputLocation,colorInputLocation,textureInputLocation);

            forEveryTexturePathInMeshDo(scene,meshIndex,[](const aiString & p,const aiTextureType t,const aiMaterial * const m) {
                std::cout<<p.C_Str()<<" -> "<<t<<"\n";
            } );
            if(output.getData().getVBOsNumber()!=0) {
                aiString str;
                getTexturePathInMesh(scene,meshIndex,str);
                const SharedString textureFile=swapFileNameInPath(pFile,str.C_Str());
                std::cout<<textureFile.getArrayPtr()<<"\n";
                loadTexture(FIF_JPEG, textureFile.getArrayPtr());

            }
        }
        return true;
    }



}
