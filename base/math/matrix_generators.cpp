#include "matrix_generators.h"
namespace gle {
    void identityMat4(Mat4 matrix) {
        clearMat4(matrix);
        for(unsigned char i=0; i<16; i+=5) {
            matrix[i]=1;
        }
    }

    void copyMat4(const Mat4 from,Mat4 to) {
        for(unsigned char i=0; i<16; i++) {
            to[i]=from[i];
        }
    }

    void fillMat4(Mat4 matrix,const GLfloat value) {
        for(unsigned char i=0; i<16; i++) {
            matrix[i]=value;
        }
    }
}
