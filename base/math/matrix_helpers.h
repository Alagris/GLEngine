#ifndef MATRIX_HELPERS_H
#define MATRIX_HELPERS_H
#include "matrix_math_types.h"
namespace gle {
    /**This files contains functions that facilitate access to propeties of Mat4*/

    inline unsigned int getCellIndexOfMat4(const unsigned int x,const unsigned int y) {
        return y*4+x;
    }
    /** row major order. x=0 y=0 points to upper left corner (cell index 0)*/
    inline GLfloat * accessCellOfMat4(Mat4 matrix,const unsigned int x,const unsigned int y) {
        return matrix + getCellIndexOfMat4(x,y);
    }
    inline GLfloat & accessByReferenceCellOfMat4(Mat4 matrix,const unsigned int x,const unsigned int y) {
        return matrix[getCellIndexOfMat4(x,y)];
    }

    inline bool isMat4EqualMat4(const Mat4 matrix0,const Mat4 matrix1) {
        for(unsigned char i=0; i<16; i++)
            if(matrix0[i]!=matrix1[i])return false;
        return true;
    }

    void transposeMat4(Mat4 matrix);

    void printMat4(const Mat4 matrix);
}
#endif // MATRIX_HELPERS_H
