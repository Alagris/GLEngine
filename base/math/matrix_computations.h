#ifndef MATRIX_COMPUTATIONS_H
#define MATRIX_COMPUTATIONS_H
#include "matrix_math_types.h"

namespace gle {
    /**works like:
	outputVector = matrix * vector
	*/
	void multiplyMat4ByVec3(const Mat4 matrix,const Vec3 & vector,Vec3 & outputVector);
	/**works like:
	outputMatrix = leftSideMatrix * rightSideMatrix
	*/
	void multiplyMat4ByMat4(const Mat4 leftSideMatrix,const Mat4 rightSideMatrix,Mat4 outputMatrix);
	/**works like:
	leftSideMatrix := leftSideMatrix * rightSideMatrix
	*/
	void multiplyMat4ByMat4OutputToLeft(Mat4 leftSideMatrix,const Mat4 rightSideMatrix);
	/**works like:
	rightSideMatrix := leftSideMatrix * rightSideMatrix
	*/
	void multiplyMat4ByMat4OutputToRight(const Mat4 leftSideMatrix, Mat4 rightSideMatrix);

    inline void multiplyMat4ByFloat(Mat4 matrix, GLfloat value) {
        for(unsigned char i=0; i<16; i++)
            matrix[i]*=value;
    }
}
#endif // MATRIX_COMPUTATIONS_H
