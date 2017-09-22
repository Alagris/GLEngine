#include "mouse_input_helper.h"
#include "quaternion_computations.h"
#include "vector_helpers.h"

#include "GLFW/glfw3.h"
namespace gle {

    void rotateQuaternionAccordingToMouseMovement(const double movementX,const double movementY,const double sensitivityInRadiansPerPixel,Vec3 & quaternion) {
        Vec3 multiplicationOutput;
        Vec3 tmpQuat;

        generateQuaternion(0,1,0,movementX*sensitivityInRadiansPerPixel,tmpQuat);
        multiplyQuaternions(quaternion, tmpQuat,multiplicationOutput);
        setVec3(quaternion,multiplicationOutput);

        generateQuaternion(1,0,0,movementY*sensitivityInRadiansPerPixel,tmpQuat);
        multiplyQuaternions(quaternion, tmpQuat,multiplicationOutput);
        setVec3(quaternion,multiplicationOutput);
    }

    void rotateQuaternionAccordingToMouseMovementLockAxes(const double movementX,const double movementY,const double sensitivityInRadiansPerPixel,Vec3 & quaternion) {

        Vec3 multiplicationOutput;
        Vec3 tmpQuat;
        Vec3 lockedAxis(0,1,0);
        if(movementX!=0) {
            rotateVec3WithReversedQuaternion(lockedAxis,quaternion);
            generateQuaternion(lockedAxis,movementX*sensitivityInRadiansPerPixel,tmpQuat);
            multiplyQuaternions(quaternion, tmpQuat,multiplicationOutput);
            setVec3(quaternion,multiplicationOutput);
        }
        if(movementY!=0) {
            setVec3(lockedAxis,1,0,0);
            rotateVec3WithQuaternion(lockedAxis,quaternion);
            if(lockedAxis.y==0) {
                lockedAxis.x=1;
                lockedAxis.z=0;
            } else {
                lockedAxis.y=0;
                rotateVec3WithReversedQuaternion(lockedAxis,quaternion);
            }
            generateQuaternion(lockedAxis,movementY*sensitivityInRadiansPerPixel,tmpQuat);
            multiplyQuaternions(quaternion, tmpQuat,multiplicationOutput);
            setVec3(quaternion,multiplicationOutput);
        }

    }
}
