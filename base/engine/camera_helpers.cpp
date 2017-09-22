#include "camera_helpers.h"
#include "camera.h"
#include "matrix_computations.h"
namespace gle {
    void getModelViewProjectionMatrix(const Camera & cam,const Mat4 modelMatrix,Mat4  outputModelViewProjection) {
        multiplyMat4ByMat4( cam.getViewProjectionMatrix(),modelMatrix,outputModelViewProjection);
    }
}
