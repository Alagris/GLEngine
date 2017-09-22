#include "vector_computations.h"
namespace gle {
    void multiplyVec3ByFloat( Vec3 & vector,const GLfloat f) {
        vector.x*=f;
        vector.y*=f;
        vector.z*=f;
        vector.w*=f;
    }

    void sumVec3AndFloat( Vec3 & vector,const GLfloat f) {
        vector.x+=f;
        vector.y+=f;
        vector.z+=f;
        vector.w+=f;
    }

    void dotVec3(const Vec3 & v1,const Vec3 & v2,Vec3 output) {
        output.x=v1.x*v2.x;
        output.y=v1.y*v2.y;
        output.z=v1.z*v2.z;
        output.w=v1.w*v2.w;
    }
    void dotVec3OutputToRight(const Vec3 & v1,Vec3 & v2) {
        v2.x*=v1.x;
        v2.y*=v1.y;
        v2.z*=v1.z;
        v2.w*=v1.w;
    }

//TODO: add cross product
//    void crossVec3(const Vec3 & v1,const Vec3 & v2,Vec3 output){
//
//    }
//
//    void crossVec3OutputToRight(const Vec3 & v1,Vec3 & v2){
//    }
}
