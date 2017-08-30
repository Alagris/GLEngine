#ifndef COMPOUND_MATRIX_TRANSFORMATIONS_H
#define COMPOUND_MATRIX_TRANSFORMATIONS_H
#include "matrix_math_types.h"
#include "degree_radians_conversion.h"
namespace gle {
    void rotateMat4AboutAxesXYZ(
        Mat4 matrix,
        const GLfloat radiansAboutX,
        const GLfloat radiansAboutY,
        const GLfloat radiansAboutZ);

    inline void rotateDegreesMat4AboutAxesXYZ(
        Mat4 matrix,
        const GLfloat degreesAboutX,
        const GLfloat degreesAboutY,
        const GLfloat degreesAboutZ) {
        rotateMat4AboutAxesXYZ(matrix,degreeToRad(degreesAboutX),degreeToRad(degreesAboutY),degreeToRad(degreesAboutZ));
    }
    void rotateMat4AboutArbitraryAxisAndScale(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d,
        const GLfloat radians) ;
    inline void rotateMat4AboutArbitraryAxisAndScale(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat scale,
        const GLfloat radians) {
        rotateMat4AboutArbitraryAxisAndScale(matrix,axisX,axisY,axisZ,scale,scale,scale,radians);
    }
    inline void rotateDegreesMat4AboutArbitraryAxisAndScale(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat scale,
        const GLfloat degrees) {
        rotateMat4AboutArbitraryAxisAndScale(matrix,axisX,axisY,axisZ,scale,scale,scale,degreeToRad(degrees));
    }
    inline void rotateDegreesMat4AboutArbitraryAxisAndScale(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d,
        const GLfloat degrees) {
        rotateMat4AboutArbitraryAxisAndScale(matrix,axisX,axisY,axisZ,w,h,d,degreeToRad(degrees));
    }

    void rotateMat4AboutArbitraryAxis_deprecated(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat radians);

    inline void rotateDegreesMat4AboutArbitraryAxis_deprecated(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat degrees) {
        rotateMat4AboutArbitraryAxis_deprecated(matrix,axisX,axisY,axisZ,degreeToRad(degrees));
    }
}

#endif // COMPOUND_MATRIX_TRANSFORMATIONS_H
