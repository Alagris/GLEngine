#include "matrix_computations.h"
namespace gle {


    void multiplyMat4ByVec3(const Mat4 matrix,const Vec3 & vector,Vec3 & outputVector) {
        outputVector.x=
            matrix[0]*vector.x +
            matrix[1]*vector.y +
            matrix[2]*vector.z +
            matrix[3]*vector.w;

        outputVector.y=
            matrix[4]*vector.x +
            matrix[5]*vector.y +
            matrix[6]*vector.z +
            matrix[7]*vector.w;

        outputVector.z=
            matrix[8]*vector.x +
            matrix[9]*vector.y +
            matrix[10]*vector.z +
            matrix[11]*vector.w;

        outputVector.w=
            matrix[12]*vector.x +
            matrix[13]*vector.y +
            matrix[14]*vector.z +
            matrix[15]*vector.w;
    }

    void multiplyMat4ByMat4(const Mat4 leftSideMatrix,const Mat4 rightSideMatrix,Mat4 outputMatrix) {
        for(unsigned char lr=0,i=0; lr<4; lr++) { //left matrix row
            for(unsigned char rc=0; rc<4; rc++) { //right matrix column
                GLfloat & cell = outputMatrix[i++]=0;
                for(unsigned char li=lr*4,ri=rc; ri<16; li++,ri+=4) {
                    cell+= leftSideMatrix[li]*rightSideMatrix[ri];
                }
            }
        }
    }


    void multiplyMat4ByMat4OutputToLeft(Mat4 leftSideMatrix,const Mat4 rightSideMatrix) {
        for(unsigned char lr=0,i=0; lr<4; lr++) { //left matrix row
            unsigned char lr4 = lr*4;
            GLfloat a = leftSideMatrix[lr4];
            GLfloat b = leftSideMatrix[lr4+1];
            GLfloat c = leftSideMatrix[lr4+2];
            GLfloat d = leftSideMatrix[lr4+3];
            for(unsigned char rc=0; rc<4; rc++) { //right matrix column
                leftSideMatrix[i++]=
                    a*rightSideMatrix[rc]+
                    b*rightSideMatrix[rc+4]+
                    c*rightSideMatrix[rc+8]+
                    d*rightSideMatrix[rc+12];
            }
        }
    }

    void multiplyMat4ByMat4OutputToRight(const Mat4 leftSideMatrix,Mat4 rightSideMatrix) {
        for(unsigned char rc =0; rc<4; rc++) { //right matrix column
            GLfloat a = rightSideMatrix[rc];
            GLfloat b = rightSideMatrix[rc+4];
            GLfloat c = rightSideMatrix[rc+8];
            GLfloat d = rightSideMatrix[rc+12];
            for(unsigned char lr=0; lr<16; lr+=4) { //left matrix row
                rightSideMatrix[lr+rc]=
                    a*leftSideMatrix[lr]+
                    b*leftSideMatrix[lr+1]+
                    c*leftSideMatrix[lr+2]+
                    d*leftSideMatrix[lr+3];
            }
        }
    }
}
