#ifndef BASIC_MATRIX_TRANSFORMATIONS_H
#define BASIC_MATRIX_TRANSFORMATIONS_H
#include "matrix_math_types.h"
#include "degree_radians_conversion.h"
namespace gle {
    /**In this file are sotres function that provide 3 basic matrix operations: translation, scaling and rotation*/

    ///////////////////
    //TRANSLATION
    ///////////////////
    void translateMat4(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z);

    inline void translateMat4(
        Mat4 matrix,
        const Vec3 & translationVector) {
        translateMat4(matrix,translationVector.x,translationVector.y,translationVector.z);
    }
    ///////////////////
    //SCALING
    ///////////////////
    void scaleMat4(
        Mat4 matrix,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d);

    inline void scaleMat4(
        Mat4 matrix,
        const GLfloat scale) {
        scaleMat4(matrix,scale,scale,scale);
    }

    inline void scaleMat4(
        Mat4 matrix,
        const Vec3 & scaleVector) {
        scaleMat4(matrix,scaleVector.x,scaleVector.y,scaleVector.z);
    }

    ///////////////////
    //ROTATION
    ///////////////////
    void rotateMat4AboutAxisX(
        Mat4 matrix,
        const GLfloat radians);

    void rotateMat4AboutAxisX(
        Mat4 matrix,
        const GLfloat angleSin,
        const GLfloat angleCos);

    inline void rotateDegreesMat4AboutAxisX(
        Mat4 matrix,
        const GLfloat degrees) {
        rotateMat4AboutAxisX(matrix,degreeToRad(degrees));
    }

    void rotateMat4AboutAxisY(
        Mat4 matrix,
        const GLfloat radians);

    void rotateMat4AboutAxisY(
        Mat4 matrix,
        const GLfloat angleSin,
        const GLfloat angleCos);

    inline void rotateDegreesMat4AboutAxisY(
        Mat4 matrix,
        const GLfloat degrees) {
        rotateMat4AboutAxisY(matrix,degreeToRad(degrees));
    }
    void rotateMat4AboutAxisZ(
        Mat4 matrix,
        const GLfloat radians);

     void rotateMat4AboutAxisZ(
        Mat4 matrix,
        const GLfloat angleSin,
        const GLfloat angleCos);

    inline void rotateDegreesMat4AboutAxisZ(
        Mat4 matrix,
        const GLfloat degrees) {
        rotateMat4AboutAxisZ(matrix,degreeToRad(degrees));
    }

    void rotateMat4AboutArbitraryAxis(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat radians);

    inline void rotateDegreesMat4AboutArbitraryAxis(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat degrees) {
        rotateMat4AboutArbitraryAxis(matrix,axisX,axisY,axisZ,degreeToRad(degrees));
    }

    void rotateMat4WithQuaternion(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z,
        const GLfloat w);

    inline void rotateMat4WithQuaternion(
        Mat4 matrix,
        const Vec3 & quaternion) {
        rotateMat4WithQuaternion(matrix,quaternion.x,quaternion.y,quaternion.z,quaternion.w);
    }

    ///////////////////
    //OTHER
    ///////////////////
    void scaleThenTranslateMat4(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d);

    inline void scaleThenTranslateMat4(
        Mat4 matrix,
        const Vec3 & translationVector,
        const Vec3 & scaleVector) {
        scaleThenTranslateMat4(matrix,translationVector.x,translationVector.y,translationVector.z,scaleVector.x,scaleVector.y,scaleVector.z);
    }

     void translateThenScaleMat4(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d);

    inline void translateThenScaleMat4(
        Mat4 matrix,
        const Vec3 & translationVector,
        const Vec3 & scaleVector) {
        translateThenScaleMat4(matrix,translationVector.x,translationVector.y,translationVector.z,scaleVector.x,scaleVector.y,scaleVector.z);
    }


}

#endif // BASIC_MATRIX_TRANSFORMATIONS_H
