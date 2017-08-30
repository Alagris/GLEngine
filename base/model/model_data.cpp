#include "model_data.h"

#include "matrix_model_compuations.h"
#include "quaternion_computations.h"
#include "vector_helpers.h"
#include "iostream"
namespace gle {
    ModelData::ModelData():m_scale(Vec3(1,1,1,1))
    {
        //ctor
    }

    ModelData::~ModelData()
    {
        //dtor
    }

    void ModelData::setLocation(const GLfloat x,const GLfloat y,const GLfloat z) {
        setLocationX(x);
        setLocationY(y);
        setLocationZ(z);
    }

    void ModelData::setScale(const GLfloat width,const GLfloat height,const GLfloat depth) {
        setScaleWidth(width);
        setScaleHeight(height);
        setScaleDepth(depth);
    }

    void ModelData::moveAccordingToRotation(const GLfloat initialDirectionX,const GLfloat initialDirectionY,const GLfloat initialDirectionZ) {
        Vec3 direction(initialDirectionX,initialDirectionY,initialDirectionZ,0);
        rotateVec3WithQuaternion(direction,m_rotation);
        setLocation(getLocationX()+direction.x,getLocationY()+direction.y,getLocationZ()+direction.z);
    }

    void ModelData::rotateByQuaternion(const Vec3 & rotationQuaternion) {
        Vec3 tmp;
        multiplyQuaternions(m_rotation,rotationQuaternion,tmp);
        setRotationQuaternion(tmp);
    }


    void ModelData::setRotationQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat w) {
        m_hasBeenModified=true;
        m_rotation.x=x;
        m_rotation.y=y;
        m_rotation.z=z;
        m_rotation.w=w;
    }

    void  ModelData::setLocationX(const GLfloat x) {
        m_hasBeenModified=true;
        m_location.x=x;
    }
    void  ModelData::setLocationY(const GLfloat y) {
        m_hasBeenModified=true;
        m_location.y=y;
    }
    void  ModelData::setLocationZ(const GLfloat z) {
        m_hasBeenModified=true;
        m_location.z=z;
    }
    void  ModelData::setScaleWidth(const GLfloat width) {
        m_hasBeenModified=true;
        m_scale.x=width;
    }
    void  ModelData::setScaleHeight(const GLfloat height) {
        m_hasBeenModified=true;
        m_scale.y=height;
    }
    void  ModelData::setScaleDepth(const GLfloat depth) {
        m_hasBeenModified=true;
        m_scale.z=depth;
    }
}
