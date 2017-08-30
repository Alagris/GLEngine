#include "camera.h"
#include "matrix_projection_computations.h"
#include "matrix_computations.h"
#include "matrix_model_compuations.h"
#include "matrix_helpers.h"
#include "quaternion_computations.h"
namespace gle {
    Camera::Camera(const GLfloat left,
                   const GLfloat right,
                   const GLfloat top,
                   const GLfloat bottom,
                   const GLfloat zNear,
                   const GLfloat zFar,
                   const bool isPerspectiveOtherwiseOrthographic):m_projection{}
    {
        if( isPerspectiveOtherwiseOrthographic) {
            setPerspectiveProjection(left, right,  top, bottom, zNear,zFar);
        } else {
            setOrthographicProjection(left, right,  top, bottom, zNear,zFar);
        }
    }

    Camera::~Camera()
    {
        //dtor
    }

    void Camera::updateViewMatrix(){
        reverseQuaternion(getRotationQuaternionByRef());
        calculateQuaternionFinalReversedModelMatrix(-getLocationX(),-getLocationY(),-getLocationZ(),1/getScaleWidth(),1/getScaleHeight(),1/getScaleDepth(),getRotationQuaternionByRef(),m_viewMatrix);
        reverseQuaternion(getRotationQuaternionByRef());
    }

    void Camera::setPerspectiveProjection(const GLfloat left,
                                          const GLfloat right,
                                          const GLfloat top,
                                          const GLfloat bottom,
                                          const GLfloat zNear,
                                          const GLfloat zFar) {
        generatePerspectiveProjectionMat4(left, right,  top, bottom, zNear,zFar,m_projection);
    }

    void Camera::setOrthographicProjection(const GLfloat left,
                                           const GLfloat right,
                                           const GLfloat top,
                                           const GLfloat bottom,
                                           const GLfloat zNear,
                                           const GLfloat zFar) {
        generateOrthographicProjectionMat4(left, right,  top, bottom, zNear,zFar,m_projection);
    }


    void Camera::updateViewProjectionMatrix() {
        multiplyMat4ByMat4(m_projection,m_viewMatrix,m_viewProjection);
    }

    void Camera::getModelViewProjectionMatrix(const Mat4 modelMatrix,Mat4  outputModelViewProjection) const {
        multiplyMat4ByMat4( m_viewProjection,modelMatrix,outputModelViewProjection);
    }

    void Camera::printViewProjectionMatrix()const {
        printMat4(m_viewProjection);
    }
    void Camera::printProjectionMatrix()const {
        printMat4(m_projection);
    }
    void Camera::printViewMatrix()const {
        printMat4(m_viewMatrix);
    }
}
