#include "assimp_copy_data.h"


namespace gle {

    namespace primitive {
        const unsigned int copy3DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination ) {
            unsigned int j=0;
            for(unsigned int i=0; i<numVertices; i++,j+=3) {
                destination[j]=meshVertices[i].x;
                destination[j+1]=meshVertices[i].y;
                destination[j+2]=meshVertices[i].z;
            }
            return j;
        }
        const unsigned int copy2DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination ) {
            unsigned int j=0;
            for(unsigned int i=0,j=0; i<numVertices; i++,j+=2) {
                destination[j]=meshVertices[i].x;
                destination[j+1]=meshVertices[i].y;
            }
            return j;
        }
        const unsigned int copy1DVertices(const aiVector3D *const meshVertices,const unsigned int numVertices,GLfloat *const destination ) {
            unsigned int i=0;
            for(; i<numVertices; i++) {
                destination[i]=meshVertices[i].x;
            }
            return  i;
        }


        const unsigned int copyColorVertices(const aiColor4D *const meshColors,const unsigned int numVertices,GLfloat *const destination ) {
            unsigned int j=0;
            for(unsigned int i=0; i<numVertices; i++,j+=4) {
                destination[j]=meshColors[i].r;
                destination[j+1]=meshColors[i].g;
                destination[j+2]=meshColors[i].b;
                destination[j+3]=meshColors[i].a;
            }
            return j;
        }


        const unsigned int copyIndices(const aiFace *const meshFaces,const unsigned int numFaces,const unsigned int numIndicesPerFace,GLuint *const destination) {
            unsigned int j=0;
            for(unsigned int i=0; i<numFaces; i++) {
                if(meshFaces[i].mNumIndices==numIndicesPerFace) {
                    unsigned int * indices =meshFaces[i].mIndices;
                    for(unsigned int k=0; k<numIndicesPerFace; k++,j++) {
                        destination[j]=indices[k];
                    }
                }
            }
            return j;
        }
    }

}
