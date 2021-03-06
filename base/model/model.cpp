#include "model.h"
#include "matrix_model_compuations.h"
#include "quaternion_computations.h"
namespace gle {
    Model::Model()
    {
        //ctor
    }

    Model::~Model()
    {
        //dtor
    }

    void Model::updateModelMatrix() {
        if(hasBeenModified())calculateQuaternionFinalModelMatrix(getLocation(),getScale(),getRotation(),m_modelMatrix);
    }

}
