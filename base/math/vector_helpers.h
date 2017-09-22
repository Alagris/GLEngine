#ifndef VECTOR_HELPERS_H
#define VECTOR_HELPERS_H
#include "matrix_math_types.h"
namespace gle {
    GLfloat getVec3Length(const GLfloat  x,const GLfloat  y,const GLfloat  z);
    inline GLfloat getVec3Length(const Vec3 & vector) {
        return getVec3Length(vector.x,vector.y,vector.z);
    }

    void normalizeVec3(GLfloat & x,GLfloat & y,GLfloat & z,const GLfloat desiredLength=1);
    inline void normalizeVec3(Vec3 & vector,const GLfloat desiredLength=1) {
        normalizeVec3(vector.x,vector.y,vector.z,desiredLength);
    }

    GLfloat getVec4Length(const GLfloat  x,const GLfloat  y,const GLfloat  z,const GLfloat  w);
    inline GLfloat getVec4Length(const Vec3 & vector) {
        return getVec4Length(vector.x,vector.y,vector.z,vector.w);
    }

    void normalizeVec4(GLfloat & x,GLfloat & y,GLfloat & z,GLfloat & w,const GLfloat desiredLength=1);
    inline void normalizeVec4(Vec3 & vector,const GLfloat desiredLength=1) {
        normalizeVec4(vector.x,vector.y,vector.z,vector.w,desiredLength);
    }

    void setVec3( Vec3 & vector,const GLfloat x=0,const GLfloat y=0,const GLfloat z=0,const GLfloat w=1);
    inline void setVec3( Vec3 & destinationVector,const Vec3 & sourceVector){
        setVec3(destinationVector,sourceVector.x,sourceVector.y,sourceVector.z,sourceVector.w);
    }

}

#endif // VECTOR_HELPERS_H
