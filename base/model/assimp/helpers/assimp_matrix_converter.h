#ifndef ASSIMP_MATRIX_CONVERTER_H
#define ASSIMP_MATRIX_CONVERTER_H
#include <assimp/matrix4x4.h>
#include "matrix_math_types.h"
namespace gle{
    void convertAssimpMatrix4x4ToMat4(const aiMatrix4x4 & m4x4, Mat4 m);
}

#endif // ASSIMP_MATRIX_CONVERTER_H
