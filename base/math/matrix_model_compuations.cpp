#include "matrix_model_compuations.h"
#include "matrix_generators.h"
#include "basic_matrix_transformations.h"
#include "matrix_computations.h"
#include "compound_matrix_transformations.h"
#include "quaternion_computations.h"


#include "matrix_helpers.h"
namespace gle {
    void calculateRadiansAboutArbitraryAxisFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat rotationAxisX
        ,const GLfloat rotationAxisY
        ,const GLfloat rotationAxisZ
        ,const GLfloat rotationRadians
        ,Mat4 outputMatrix) {
        //first rotating
        rotateMat4AboutArbitraryAxis(
            outputMatrix,
            rotationAxisX,
            rotationAxisY,
            rotationAxisZ,
            rotationRadians);
        //then scaling then translating
        Mat4 tmpMatrix;
        scaleThenTranslateMat4(tmpMatrix,x,y,z,w,h,d);
        //here:
        //tmpMatrix=translationMatrix*scalingMatrix
        //outputMatrix=rotationMatrix
        //execute:
        //tmpMatrix*outputMatrix = translationMatrix*scalingMatrix*rotationMatrix
        multiplyMat4ByMat4OutputToRight(tmpMatrix,outputMatrix);
        //so:
        //outputMatrix = translationMatrix*scalingMatrix*rotationMatrix

    }

    void calculateRadiansFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const GLfloat rotationAboutAxisX
        ,const GLfloat rotationAboutAxisY
        ,const GLfloat rotationAboutAxisZ
        ,Mat4 outputMatrix) {
        //first rotating
        rotateDegreesMat4AboutAxesXYZ(
            outputMatrix,
            rotationAboutAxisX,
            rotationAboutAxisY,
            rotationAboutAxisZ);

        //then scaling then translating
        Mat4 tmpMatrix;
        scaleThenTranslateMat4(tmpMatrix,x,y,z,w,h,d);
        //here:
        //tmpMatrix=translationMatrix*scalingMatrix
        //outputMatrix=rotationMatrix
        //execute:
        //tmpMatrix*outputMatrix = translationMatrix*scalingMatrix*rotationMatrix
        multiplyMat4ByMat4OutputToRight(tmpMatrix,outputMatrix);
        //so:
        //outputMatrix = translationMatrix*scalingMatrix*rotationMatrix

    }



    void calculateQuaternionFinalModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {
        //first rotating
        rotateMat4WithQuaternion(outputMatrix,quaternion);

        //then scaling then translating
        Mat4 tmpMatrix;
        scaleThenTranslateMat4(tmpMatrix,x,y,z,w,h,d);
        //here:
        //tmpMatrix=translationMatrix*scalingMatrix
        //outputMatrix=rotationMatrix
        //execute:
        //tmpMatrix*outputMatrix = translationMatrix*scalingMatrix*rotationMatrix
        multiplyMat4ByMat4OutputToRight(tmpMatrix,outputMatrix);
        //so:
        //outputMatrix = translationMatrix*scalingMatrix*rotationMatrix

    }



    void calculateQuaternionFinalReversedModelMatrix(
        const GLfloat x
        ,const GLfloat y
        ,const GLfloat z
        ,const GLfloat w
        ,const GLfloat h
        ,const GLfloat d
        ,const Vec3 & quaternion
        ,Mat4 outputMatrix) {

         //first translating then scaling
        Mat4 tmpMatrix;
        translateThenScaleMat4(tmpMatrix,x,y,z,w,h,d);

        //and rotating
        rotateMat4WithQuaternion(outputMatrix,quaternion);


        //here:
        //tmpMatrix=scalingMatrix*translationMatrix
        //outputMatrix=rotationMatrix
        //execute:
        //outputMatrix*tmpMatrix = rotationMatrix*scalingMatrix*translationMatrix
        multiplyMat4ByMat4OutputToLeft(outputMatrix,tmpMatrix);
        //so:
        //outputMatrix = rotationMatrix*scalingMatrix*translationMatrix

    }
}
