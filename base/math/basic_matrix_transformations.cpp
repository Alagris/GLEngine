#include "basic_matrix_transformations.h"
#include "matrix_helpers.h"
#include "vector_helpers.h"
#include <math.h>
namespace gle {
    void translateMat4(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z) {

        accessByReferenceCellOfMat4(matrix,0,0)=1;
        accessByReferenceCellOfMat4(matrix,1,0)=0;
        accessByReferenceCellOfMat4(matrix,2,0)=0;
        accessByReferenceCellOfMat4(matrix,3,0)=x;

        accessByReferenceCellOfMat4(matrix,0,1)=0;
        accessByReferenceCellOfMat4(matrix,1,1)=1;
        accessByReferenceCellOfMat4(matrix,2,1)=0;
        accessByReferenceCellOfMat4(matrix,3,1)=y;

        accessByReferenceCellOfMat4(matrix,0,2)=0;
        accessByReferenceCellOfMat4(matrix,1,2)=0;
        accessByReferenceCellOfMat4(matrix,2,2)=1;
        accessByReferenceCellOfMat4(matrix,3,2)=z;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }

    void scaleMat4(
        Mat4 matrix,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d) {
        accessByReferenceCellOfMat4(matrix,0,0)=w;
        accessByReferenceCellOfMat4(matrix,1,0)=0;
        accessByReferenceCellOfMat4(matrix,2,0)=0;
        accessByReferenceCellOfMat4(matrix,3,0)=0;

        accessByReferenceCellOfMat4(matrix,0,1)=0;
        accessByReferenceCellOfMat4(matrix,1,1)=h;
        accessByReferenceCellOfMat4(matrix,2,1)=0;
        accessByReferenceCellOfMat4(matrix,3,1)=0;

        accessByReferenceCellOfMat4(matrix,0,2)=0;
        accessByReferenceCellOfMat4(matrix,1,2)=0;
        accessByReferenceCellOfMat4(matrix,2,2)=d;
        accessByReferenceCellOfMat4(matrix,3,2)=0;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }

    void scaleThenTranslateMat4(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d) {

        accessByReferenceCellOfMat4(matrix,0,0)=w;
        accessByReferenceCellOfMat4(matrix,1,0)=0;
        accessByReferenceCellOfMat4(matrix,2,0)=0;
        accessByReferenceCellOfMat4(matrix,3,0)=x;

        accessByReferenceCellOfMat4(matrix,0,1)=0;
        accessByReferenceCellOfMat4(matrix,1,1)=h;
        accessByReferenceCellOfMat4(matrix,2,1)=0;
        accessByReferenceCellOfMat4(matrix,3,1)=y;

        accessByReferenceCellOfMat4(matrix,0,2)=0;
        accessByReferenceCellOfMat4(matrix,1,2)=0;
        accessByReferenceCellOfMat4(matrix,2,2)=d;
        accessByReferenceCellOfMat4(matrix,3,2)=z;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }

     void translateThenScaleMat4(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d) {

        accessByReferenceCellOfMat4(matrix,0,0)=w;
        accessByReferenceCellOfMat4(matrix,1,0)=0;
        accessByReferenceCellOfMat4(matrix,2,0)=0;
        accessByReferenceCellOfMat4(matrix,3,0)=x*w;

        accessByReferenceCellOfMat4(matrix,0,1)=0;
        accessByReferenceCellOfMat4(matrix,1,1)=h;
        accessByReferenceCellOfMat4(matrix,2,1)=0;
        accessByReferenceCellOfMat4(matrix,3,1)=y*h;

        accessByReferenceCellOfMat4(matrix,0,2)=0;
        accessByReferenceCellOfMat4(matrix,1,2)=0;
        accessByReferenceCellOfMat4(matrix,2,2)=d;
        accessByReferenceCellOfMat4(matrix,3,2)=z*d;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }

    void rotateMat4AboutAxisX(
        Mat4 matrix,
        const GLfloat sin,
        const GLfloat cos) {
        accessByReferenceCellOfMat4(matrix,0,0)=1;
        accessByReferenceCellOfMat4(matrix,1,0)=0;
        accessByReferenceCellOfMat4(matrix,2,0)=0;
        accessByReferenceCellOfMat4(matrix,3,0)=0;

        accessByReferenceCellOfMat4(matrix,0,1)=0;
        accessByReferenceCellOfMat4(matrix,1,1)=cos;
        accessByReferenceCellOfMat4(matrix,2,1)=-sin;
        accessByReferenceCellOfMat4(matrix,3,1)=0;

        accessByReferenceCellOfMat4(matrix,0,2)=0;
        accessByReferenceCellOfMat4(matrix,1,2)=sin;
        accessByReferenceCellOfMat4(matrix,2,2)=cos;
        accessByReferenceCellOfMat4(matrix,3,2)=0;


        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }

    void rotateMat4AboutAxisY(
        Mat4 matrix,
        const GLfloat sin,
        const GLfloat cos) {

        accessByReferenceCellOfMat4(matrix,0,0)=cos;
        accessByReferenceCellOfMat4(matrix,1,0)=0;
        accessByReferenceCellOfMat4(matrix,2,0)=sin;
        accessByReferenceCellOfMat4(matrix,3,0)=0;

        accessByReferenceCellOfMat4(matrix,0,1)=0;
        accessByReferenceCellOfMat4(matrix,1,1)=1;
        accessByReferenceCellOfMat4(matrix,2,1)=0;
        accessByReferenceCellOfMat4(matrix,3,1)=0;

        accessByReferenceCellOfMat4(matrix,0,2)=-sin;
        accessByReferenceCellOfMat4(matrix,1,2)=0;
        accessByReferenceCellOfMat4(matrix,2,2)=cos;
        accessByReferenceCellOfMat4(matrix,3,2)=0;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }

    void rotateMat4AboutAxisZ(
        Mat4 matrix,
        const GLfloat sin,
        const GLfloat cos) {
        accessByReferenceCellOfMat4(matrix,0,0)=cos;
        accessByReferenceCellOfMat4(matrix,1,0)=-sin;
        accessByReferenceCellOfMat4(matrix,2,0)=0;
        accessByReferenceCellOfMat4(matrix,3,0)=0;

        accessByReferenceCellOfMat4(matrix,0,1)=sin;
        accessByReferenceCellOfMat4(matrix,1,1)=cos;
        accessByReferenceCellOfMat4(matrix,2,1)=0;
        accessByReferenceCellOfMat4(matrix,3,1)=0;

        accessByReferenceCellOfMat4(matrix,0,2)=0;
        accessByReferenceCellOfMat4(matrix,1,2)=0;
        accessByReferenceCellOfMat4(matrix,2,2)=1;
        accessByReferenceCellOfMat4(matrix,3,2)=0;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;
    }




    void rotateMat4AboutAxisX(
        Mat4 matrix,
        const GLfloat radians) {
        rotateMat4AboutAxisX(matrix,std::sin(radians),std::cos(radians));
    }

    void rotateMat4AboutAxisY(
        Mat4 matrix,
        const GLfloat radians) {
        rotateMat4AboutAxisY(matrix,std::sin(radians),std::cos(radians));
    }

    void rotateMat4AboutAxisZ(
        Mat4 matrix,
        const GLfloat radians) {
        rotateMat4AboutAxisZ(matrix,std::sin(radians),std::cos(radians));
    }





    void rotateMat4AboutArbitraryAxis(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat radians) {
        if(radians==0)return;



//shortened form of the algorithm at the bottom of this function body

        const GLfloat sin=std::sin(radians);
        const GLfloat cos=std::cos(radians);
        GLfloat u = axisX;
        GLfloat v = axisY;
        GLfloat w = axisZ;
        normalizeVec3(u,v,w,1);
        const GLfloat u2 = u*u;
        const GLfloat v2 = v*v;
        const GLfloat w2 = w*w;
        accessByReferenceCellOfMat4(matrix,0,0)=u2+(v2+w2)*cos;
        accessByReferenceCellOfMat4(matrix,1,0)=u*v*(1-cos)-w*sin;
        accessByReferenceCellOfMat4(matrix,2,0)=u*w*(1-cos)+v*sin;
        accessByReferenceCellOfMat4(matrix,3,0)=0;

        accessByReferenceCellOfMat4(matrix,0,1)=u*v*(1-cos)+w*sin;
        accessByReferenceCellOfMat4(matrix,1,1)=v2+(u2+w2)*cos;
        accessByReferenceCellOfMat4(matrix,2,1)=v*w*(1-cos)-u*sin;
        accessByReferenceCellOfMat4(matrix,3,1)=0;

        accessByReferenceCellOfMat4(matrix,0,2)=u*w*(1-cos)-v*sin;
        accessByReferenceCellOfMat4(matrix,1,2)=v*w*(1-cos)+u*sin;
        accessByReferenceCellOfMat4(matrix,2,2)=w2+(u2+v2)*cos;
        accessByReferenceCellOfMat4(matrix,3,2)=0;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;


    }

    void rotateMat4WithQuaternion(
        Mat4 matrix,
        const GLfloat x,
        const GLfloat y,
        const GLfloat z,
        const GLfloat w) {
        const GLfloat x2=x*x;
        const GLfloat y2=y*y;
        const GLfloat z2=z*z;
        const GLfloat w2=w*w;
        const GLfloat _2xy =2*x*y;
        const GLfloat _2xz =2*x*z;
        const GLfloat _2wz =2*w*z;
        const GLfloat _2wy =2*w*y;
        const GLfloat _2yz =2*y*z;
        const GLfloat _2wx =2*w*x;
        accessByReferenceCellOfMat4(matrix,0,0)=w2+x2-y2-z2;
        accessByReferenceCellOfMat4(matrix,1,0)=_2xy-_2wz;
        accessByReferenceCellOfMat4(matrix,2,0)=_2xz+_2wy;
        accessByReferenceCellOfMat4(matrix,3,0)=0;

        accessByReferenceCellOfMat4(matrix,0,1)=_2xy+_2wz;
        accessByReferenceCellOfMat4(matrix,1,1)=w2-x2+y2-z2;
        accessByReferenceCellOfMat4(matrix,2,1)=_2yz-_2wx;
        accessByReferenceCellOfMat4(matrix,3,1)=0;

        accessByReferenceCellOfMat4(matrix,0,2)=_2xz-_2wy;
        accessByReferenceCellOfMat4(matrix,1,2)=_2yz+_2wx;
        accessByReferenceCellOfMat4(matrix,2,2)=w2-x2-y2+z2;
        accessByReferenceCellOfMat4(matrix,3,2)=0;

        accessByReferenceCellOfMat4(matrix,0,3)=0;
        accessByReferenceCellOfMat4(matrix,1,3)=0;
        accessByReferenceCellOfMat4(matrix,2,3)=0;
        accessByReferenceCellOfMat4(matrix,3,3)=1;


    }


}
