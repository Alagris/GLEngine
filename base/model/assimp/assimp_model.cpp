#include "assimp_model.h"
#include "assimp_matrix_converter.h"
#include "matrix_generators.h"
namespace gle {
    AssimpModel::AssimpModel(){
        identityMat4(m_modelMatrix);
    }
    AssimpModel::AssimpModel(const aiMatrix4x4 & matrix)
    {
        convertAssimpMatrix4x4ToMat4(matrix,m_modelMatrix);
    }

}
