#include "matrix_helpers.h"
#include <iostream>

namespace gle {
    void printMat4(const Mat4 matrix) {
        for(unsigned char i=0,k=0; i<4; i++) {
            for(unsigned char j=0; j<4; j++,k++) {
                std::cout<<matrix[k]<<"\t";
            }
            std::cout<<"\n";
        }
    }

    void transposeMat4(Mat4 matrix){
        for(int x=1;x<4;x++){
            for(int y=0;y<x;y++){
                GLfloat & i = accessByReferenceCellOfMat4(matrix,x,y);
                GLfloat tmp=i;
                GLfloat & j =accessByReferenceCellOfMat4(matrix,y,x);
                i=j;
                j=tmp;
            }
        }
    }
}
