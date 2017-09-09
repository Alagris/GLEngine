#ifndef QUATERNION_COMPUTATIONS_H
#define QUATERNION_COMPUTATIONS_H
#include "matrix_math_types.h"
#include "degree_radians_conversion.h"
namespace gle {
    void generateQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle, Vec3 & outputQuaternion);
    inline void generateDegreesQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angleInDegrees, Vec3 & outputQuaternion) {
        generateQuaternion(x,y,z,degreeToRad(angleInDegrees),outputQuaternion);
    }
    void generateReverseQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle, Vec3 & outputQuaternion);
    inline void generateReverseQuaternionDegrees(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angleInDegrees, Vec3 & outputQuaternion) {
        generateReverseQuaternion(x,y,z,degreeToRad(angleInDegrees),outputQuaternion);
    }
    void reverseQuaternion(Vec3 & quaternion);

    inline void generateQuaternion(const Vec3 & rotationAxis,const GLfloat angle, Vec3 & outputQuaternion) {
        generateQuaternion(rotationAxis.x,rotationAxis.y,rotationAxis.z,angle,outputQuaternion);
    }
    inline void generateDegreesQuaternion(const Vec3 & rotationAxis,const GLfloat angleInDegrees, Vec3 & outputQuaternion) {
        generateQuaternion(rotationAxis,degreeToRad(angleInDegrees),outputQuaternion);
    }
    void multiplyQuaternions(
        const GLfloat lhsx,const GLfloat lhsy,const GLfloat lhsz,const GLfloat lhsw,
        const GLfloat rhsx,const GLfloat rhsy,const GLfloat rhsz,const GLfloat rhsw,
        Vec3 & output ) ;

    inline void multiplyQuaternions(const Vec3 & lhs,const Vec3 & rhs,Vec3 & output ) {
        multiplyQuaternions(lhs.x,lhs.y,lhs.z,lhs.w,rhs.x,rhs.y,rhs.z,rhs.w,output);
    }
    inline void multiplyQuaternions(const GLfloat lhsx,const GLfloat lhsy,const GLfloat lhsz,const GLfloat lhsw,const Vec3 & rhs,Vec3 & output ) {
        multiplyQuaternions(lhsx,lhsy,lhsz,lhsw,rhs.x,rhs.y,rhs.z,rhs.w,output);
    }
    inline void multiplyQuaternions(const Vec3 & lhs,const GLfloat rhsx,const GLfloat rhsy,const GLfloat rhsz,const GLfloat rhsw,Vec3 & output ) {
        multiplyQuaternions(lhs.x,lhs.y,lhs.z,lhs.w,rhsx,rhsy,rhsz,rhsw,output);
    }
    inline void multiplyQuaternionsReverseLeft(const Vec3 & lhs,const Vec3 & rhs,Vec3 & output ) {
        multiplyQuaternions(-lhs.x,-lhs.y,-lhs.z,lhs.w,rhs,output);
    }
    inline void multiplyQuaternionsReverseRight(const Vec3 & lhs,const Vec3 & rhs,Vec3 & output ) {
        multiplyQuaternions(lhs,-rhs.x,-rhs.y,-rhs.z,rhs.w,output);
    }
    inline void multiplyQuaternionsOutputToLeft( Vec3 & lhs,const Vec3 & rhs ) {
        multiplyQuaternions(lhs,rhs,lhs);
    }
    inline void multiplyQuaternionsOutputToRight(const Vec3 & lhs, Vec3 & rhs ) {
        multiplyQuaternions(lhs,rhs,rhs);
    }


    void normalizeQuaternion(Vec3 & quaternion);


    void rotateVec3WithReversedQuaternion(Vec3 & rotatedPoint,const Vec3 & quaternion);

    void rotateVec3WithReversedQuaternion(Vec3 & rotatedPoint,const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle);

    void rotateVec3WithQuaternion(Vec3 & rotatedPoint,const Vec3 & quaternion);

    void rotateVec3WithQuaternion(Vec3 & rotatedPoint,const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle);
}
#endif // QUATERNION_COMPUTATIONS_H
