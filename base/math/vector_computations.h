#ifndef VECTOR_COMPUTATIONS_H
#define VECTOR_COMPUTATIONS_H
#include "matrix_math_types.h"
namespace gle{
    void multiplyVec3ByFloat( Vec3 & vector,const GLfloat f);

    void sumVec3AndFloat( Vec3 & vector,const GLfloat f);

    void dotVec3(const Vec3 & v1,const Vec3 & v2,Vec3 output);

    void dotVec3OutputToRight(const Vec3 & v1,Vec3 & v2);

    void crossVec3(const Vec3 & v1,const Vec3 & v2,Vec3 output);

    void crossVec3OutputToRight(const Vec3 & v1,Vec3 & v2);
}
#endif // VECTOR_COMPUTATIONS_H
