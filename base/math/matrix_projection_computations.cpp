#include "matrix_projection_computations.h"
#include "matrix_helpers.h"
namespace gle {
    void generatePerspectiveProjectionMat4(
        const GLfloat left,
        const GLfloat right,
        const GLfloat top,
        const GLfloat bottom,
        const GLfloat zNear,
        const GLfloat zFar,
        Mat4 matrix) {
        accessByReferenceCellOfMat4(matrix,0,0)=2*zNear/(right-left);
        accessByReferenceCellOfMat4(matrix,2,0)=(right+left)/(right-left);
        accessByReferenceCellOfMat4(matrix,1,1)=2*zNear/(top-bottom );
        accessByReferenceCellOfMat4(matrix,2,1)=(top+bottom)/(top-bottom);
        accessByReferenceCellOfMat4(matrix,2,2)=(zFar+zNear)/(zNear-zFar);
        accessByReferenceCellOfMat4(matrix,3,2)=2*zFar*zNear/(zNear-zFar);
        accessByReferenceCellOfMat4(matrix,2,3)=-1;
    }


    void generateOrthographicProjectionMat4(
        const GLfloat left,
        const GLfloat right,
        const GLfloat top,
        const GLfloat bottom,
        const GLfloat zNear,
        const GLfloat zFar,
        Mat4 matrix) {
        accessByReferenceCellOfMat4(matrix,0,0)=2/(right-left);
        accessByReferenceCellOfMat4(matrix,3,0)=(right+left)/(left-right);
        accessByReferenceCellOfMat4(matrix,1,1)=2/(top-bottom );
        accessByReferenceCellOfMat4(matrix,3,1)=(top+bottom)/(bottom-top);
        accessByReferenceCellOfMat4(matrix,3,2)=(zFar+zNear)/(zNear-zFar);
        accessByReferenceCellOfMat4(matrix,2,2)=2/(zNear-zFar);
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }
}
