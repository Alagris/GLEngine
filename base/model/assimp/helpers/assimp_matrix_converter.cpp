#include "assimp_matrix_converter.h"
#include "matrix_helpers.h"
namespace gle {
    void convertAssimpMatrix4x4ToMat4(const aiMatrix4x4 & m4x4, Mat4 m) {

         accessByReferenceCellOfMat4(m,0,0)=m4x4.a1;
         accessByReferenceCellOfMat4(m,1,0)=m4x4.a2;
         accessByReferenceCellOfMat4(m,2,0)=m4x4.a3;
         accessByReferenceCellOfMat4(m,3,0)=m4x4.a4;

         accessByReferenceCellOfMat4(m,0,1)=m4x4.b1;
         accessByReferenceCellOfMat4(m,1,1)=m4x4.b2;
         accessByReferenceCellOfMat4(m,2,1)=m4x4.b3;
         accessByReferenceCellOfMat4(m,3,1)=m4x4.b4;

         accessByReferenceCellOfMat4(m,0,2)=m4x4.c1;
         accessByReferenceCellOfMat4(m,1,2)=m4x4.c2;
         accessByReferenceCellOfMat4(m,2,2)=m4x4.c3;
         accessByReferenceCellOfMat4(m,3,2)=m4x4.c4;

         accessByReferenceCellOfMat4(m,0,3)=m4x4.d1;
         accessByReferenceCellOfMat4(m,1,3)=m4x4.d2;
         accessByReferenceCellOfMat4(m,2,3)=m4x4.d3;
         accessByReferenceCellOfMat4(m,3,3)=m4x4.d4;
    }

}
