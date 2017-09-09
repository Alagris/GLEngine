#ifndef MATRIX_MODEL_COMPUATIONS_H
#define MATRIX_MODEL_COMPUATIONS_H
#include "matrix_math_types.h"
#include "degree_radians_conversion.h"
namespace gle {
    /////////////////////////
    //ARBITRARY AXIS
    /////////////////////////

    void calculateRadiansAboutArbitraryAxisFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat rotationAxisX
        ,const GLfloat rotationAxisY
        ,const GLfloat rotationAxisZ
        ,const GLfloat rotationRadians
        ,Mat4 outputMatrix);
    inline void calculateDegreesAboutArbitraryAxisFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat rotationAxisX
        ,const GLfloat rotationAxisY
        ,const GLfloat rotationAxisZ
        ,const GLfloat rotationDegrees
        ,Mat4 outputMatrix) {
        calculateRadiansAboutArbitraryAxisFinalModelMatrix(x,y,z,w,h,d,rotationAxisX,rotationAxisY,rotationAxisZ,degreeToRad(rotationDegrees),outputMatrix);
    }
    /////////////////////////
    //EULER ANGLES ROTATION
    /////////////////////////

    void calculateRadiansFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat rotationAboutAxisX
        ,const GLfloat rotationAboutAxisY
        ,const GLfloat rotationAboutAxisZ
        ,Mat4 outputMatrix);
    inline void calculateDegreesFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat rotationAboutAxisX
        ,const GLfloat rotationAboutAxisY
        ,const GLfloat rotationAboutAxisZ
        ,Mat4 outputMatrix) {
        calculateRadiansFinalModelMatrix(x,y,z,w,h,d,degreeToRad(rotationAboutAxisX),degreeToRad(rotationAboutAxisY),degreeToRad(rotationAboutAxisZ),outputMatrix);
    }
    /////////////////////////
    //QUATERNIONS
    /////////////////////////
    void calculateQuaternionFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix);

    inline void calculateQuaternionFinalModelMatrix(
        const Vec3 & position
        ,const Vec3 & scale
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        calculateQuaternionFinalModelMatrix(position.x,position.y,position.z,scale.x,scale.y,scale.z,quaternion,outputMatrix);
    }
    inline void calculateQuaternionFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const Vec3 & scale
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        calculateQuaternionFinalModelMatrix(x,y,z,scale.x,scale.y,scale.z,quaternion,outputMatrix);
    }
    inline void calculateQuaternionFinalModelMatrix(
        const Vec3 & position
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        calculateQuaternionFinalModelMatrix(position.x,position.y,position.z,w,h,d,quaternion,outputMatrix);
    }


    /////////////////////////
    //REVERSED (first translation, then scaling and rotation)
    /////////////////////////

    void calculateQuaternionFinalReversedModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat quaternionX
        ,const GLfloat quaternionY
        ,const GLfloat quaternionZ
        ,const GLfloat quaternionW
        ,Mat4 outputMatrix);

    inline void calculateQuaternionFinalReversedModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix){
        calculateQuaternionFinalReversedModelMatrix(x,y,z,w,h,d,quaternion.x,quaternion.y,quaternion.z,quaternion.w,outputMatrix);
    }

    inline void calculateQuaternionFinalReversedModelMatrix(
        const Vec3 & position
        ,const Vec3 & scale
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        calculateQuaternionFinalReversedModelMatrix(position.x,position.y,position.z,scale.x,scale.y,scale.z,quaternion,outputMatrix);
    }
    inline void calculateQuaternionFinalReversedModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const Vec3 & scale
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        calculateQuaternionFinalReversedModelMatrix(x,y,z,scale.x,scale.y,scale.z,quaternion,outputMatrix);
    }
    inline void calculateQuaternionFinalReversedModelMatrix(
        const Vec3 & position
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        calculateQuaternionFinalReversedModelMatrix(position.x,position.y,position.z,w,h,d,quaternion,outputMatrix);
    }
}

#endif // MATRIX_MODEL_COMPUATIONS_H
