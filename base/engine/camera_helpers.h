#ifndef CAMERA_HELPERS_H
#define CAMERA_HELPERS_H
#include "matrix_math_types.h"
namespace gle{
    class Camera;
    void getModelViewProjectionMatrix(const Camera & cam,const Mat4 modelMatrix,Mat4  outputModelViewProjection);
}
#endif // CAMERA_HELPERS_H
