#ifndef MOUSE_INPUT_HELPER_H
#define MOUSE_INPUT_HELPER_H
#include "matrix_math_types.h"
#include "degree_radians_conversion.h"
namespace gle{
    void rotateQuaternionAccordingToMouseMovement(const double movementX,const double movementY,const double sensitivityInRadiansPerPixel,Vec3 & quaternion);
    inline void rotateDegreesQuaternionAccordingToMouseMovement(const double movementX,const double movementY,const double sensitivityInDegreesPerPixel,Vec3 & quaternion){
        rotateQuaternionAccordingToMouseMovement(movementX,movementY,degreeToRad(sensitivityInDegreesPerPixel),quaternion);
    }

    void rotateQuaternionAccordingToMouseMovementLockAxes(const double movementX,const double movementY,const double sensitivityInRadiansPerPixel,Vec3 & quaternion);
    inline void rotateDegreesQuaternionAccordingToMouseMovementLockAxes(const double movementX,const double movementY,const double sensitivityInDegreesPerPixel,Vec3 & quaternion){
        rotateQuaternionAccordingToMouseMovementLockAxes(movementX,movementY,degreeToRad(sensitivityInDegreesPerPixel),quaternion);
    }
}

#endif // MOUSE_INPUT_HELPER_H
