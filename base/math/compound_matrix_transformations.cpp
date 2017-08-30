#include "compound_matrix_transformations.h"
#include "matrix_generators.h"
#include "matrix_computations.h"
#include "basic_matrix_transformations.h"
#include <math.h>
#include "trigonometry_helpers.h"


namespace gle {
    void rotateMat4AboutAxesXYZ(
        Mat4 matrix,
        const GLfloat radiansAboutX,
        const GLfloat radiansAboutY,
        const GLfloat radiansAboutZ) {
        rotateMat4AboutAxisX(matrix,radiansAboutX);
        Mat4 tmpMatrix;

        rotateMat4AboutAxisY(tmpMatrix,radiansAboutY);
        multiplyMat4ByMat4OutputToLeft(matrix,tmpMatrix);

        rotateMat4AboutAxisZ(tmpMatrix,radiansAboutZ);
        multiplyMat4ByMat4OutputToLeft(matrix,tmpMatrix);
    }

    void rotateMat4AboutArbitraryAxisAndScale(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat w,
        const GLfloat h,
        const GLfloat d,
        const GLfloat radians) {

        rotateMat4AboutArbitraryAxis(matrix,axisX,axisY,axisZ,radians);

        Mat4 tmpMatrix;
        scaleMat4(tmpMatrix,w,h,d);
        multiplyMat4ByMat4OutputToLeft(matrix,tmpMatrix);
    }


    void rotateMat4AboutArbitraryAxis_deprecated(
        Mat4 matrix,
        const GLfloat axisX,
        const GLfloat axisY,
        const GLfloat axisZ,
        const GLfloat radians) {


        if(radians==0)return;
        if(axisZ==0) { //checking for special cases
            if(axisY==0) {
                if(axisX!=0)rotateMat4AboutAxisX(matrix,radians);
                return;
            }
            if(axisX==0) {
                rotateMat4AboutAxisY(matrix,radians);
                return;
            }
        }

        //Rotation about arbitrary axis is achieved by
        //following algorithm:
        //def P - point that defines the rotation axis
        //1. rotate about x (angle Alpha) so that P is on plane yz
        //2. rotate about y (angle Beta) so that P is on axis z
        //3. rotate about z (angle Gamma) which is the actual rotation
        //4. reverse to 2.
        //5. reverse to 1.

        GLfloat distanceToAxisX = std::sqrt(axisY*axisY+axisZ*axisZ);
        GLfloat sinX= axisY/distanceToAxisX;
        GLfloat cosX= axisZ/distanceToAxisX;

        GLfloat sinY= std::sqrt(axisX*axisX+distanceToAxisX*distanceToAxisX);
        GLfloat cosY= distanceToAxisX/sinY;
        sinY=axisX/sinY;

        sinY=getSinOfNegativeAngle(sinY);
        cosY=getCosOfNegativeAngle(cosY);

        GLfloat sinGamma=std::sin(radians);
        GLfloat cosGamma=std::cos(radians);



        Mat4 tmp;
        identityMat4(matrix);

        clearMat4(tmp);
        rotateMat4AboutAxisX(tmp,sinX,cosX);
        multiplyMat4ByMat4OutputToRight(tmp,matrix);

        clearMat4(tmp);
        rotateMat4AboutAxisY(tmp,sinY,cosY);
        multiplyMat4ByMat4OutputToRight(tmp,matrix);

        clearMat4(tmp);
        rotateMat4AboutAxisZ(tmp,sinGamma,cosGamma);
        multiplyMat4ByMat4OutputToRight(tmp,matrix);

        clearMat4(tmp);
        rotateMat4AboutAxisY(tmp,getSinOfNegativeAngle(sinY),getCosOfNegativeAngle(cosY));
        multiplyMat4ByMat4OutputToRight(tmp,matrix);

        clearMat4(tmp);
        rotateMat4AboutAxisX(tmp,getSinOfNegativeAngle(sinX),getCosOfNegativeAngle(cosX));
        multiplyMat4ByMat4OutputToRight(tmp,matrix);
    }
}
