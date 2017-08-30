#ifndef MATRIX_PROJECTION_COMPUTATIONS_H
#define MATRIX_PROJECTION_COMPUTATIONS_H
#include "matrix_math_types.h"

namespace gle {
    void generatePerspectiveProjectionMat4(
        const GLfloat left,
        const GLfloat right,
        const GLfloat top,
        const GLfloat bottom,
        const GLfloat zNear,
        const GLfloat zFar,
        Mat4 outputMatrix);

    void generateOrthographicProjectionMat4(
        const GLfloat left,
        const GLfloat right,
        const GLfloat top,
        const GLfloat bottom,
        const GLfloat zNear,
        const GLfloat zFar,
        Mat4 outputMatrix);
}

#endif // MATRIX_PROJECTION_COMPUTATIONS_H
