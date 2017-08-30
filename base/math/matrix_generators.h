#ifndef MATRIX_GENERATORS_H
#define MATRIX_GENERATORS_H
#include "matrix_math_types.h"
namespace gle {
    /**In this file are stored functions that completely erase previous contents of Mat4 and fill it with new */

    void identityMat4(Mat4 matrix);

    void copyMat4(const Mat4 from,Mat4 to);

    void fillMat4(Mat4 matrix,const GLfloat value);

    inline void clearMat4(Mat4 matrix) {
        fillMat4(matrix,0);
    }
}


#endif // MATRIX_GENERATORS_H
