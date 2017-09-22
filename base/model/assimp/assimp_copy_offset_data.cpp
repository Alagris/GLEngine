#include "assimp_copy_offset_data.h"
#include <assimp/mesh.h>


namespace gle {


//    const unsigned int copyVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination,const unsigned int offset ) {
//        unsigned int j=0;
//        for(unsigned int i=0; i<numVertices; i++,j+=3) {
//            destination[j]=meshVertices[i].x;
//            destination[j+1]=meshVertices[i].y;
//            destination[j+2]=meshVertices[i].z;
//        }
//        return j;
//    }
//
//    const unsigned int copyColorVertices(const aiColor4D *const meshColors,const unsigned int numVertices,GLfloat *const destination,const unsigned int offset ) {
//        unsigned int j=0;
//        for(unsigned int i=0; i<numVertices; i++,j+=4) {
//            destination[j]=meshColors[i].r;
//            destination[j+1]=meshColors[i].g;
//            destination[j+2]=meshColors[i].b;
//            destination[j+3]=meshColors[i].a;
//        }
//        return j;
//    }


    const unsigned int copyIndices(const aiFace *const meshFaces,const unsigned int numFaces,const unsigned int numIndicesPerFace,GLuint *const destination,const unsigned int offset) {
        unsigned int j=0;
        for(unsigned int i=0; i<numFaces; i++) {
            if(meshFaces[i].mNumIndices==numIndicesPerFace) {
                unsigned int * indices =meshFaces[i].mIndices;
                for(unsigned int k=0; k<numIndicesPerFace; k++,j++) {
                    destination[j]=offset+indices[k];
                }
            }
        }
        return j;
    }




//    const unsigned int copyTexture2DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination,const unsigned int offset ) {
//        unsigned int j=0;
//        for(unsigned int i=0,j=0; i<numVertices; i++,j+=2) {
//            destination[j]=meshVertices[i].x;
//            destination[j+1]=meshVertices[i].y;
//        }
//        return j;
//    }
//
//    const unsigned int copyTexture1DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination,const unsigned int offset ) {
//        unsigned int i=0;
//        for(; i<numVertices; i++) {
//            destination[i]=meshVertices[i].x;
//        }
//        return  i;
//    }

}
