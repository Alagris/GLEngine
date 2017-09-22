#ifndef MODEL_DATA_H
#define MODEL_DATA_H
#include "matrix_math_types.h"
#include "model_base.h"

namespace gle {

    class ModelData:public ModelBase
    {
      public:
        ModelData();
        virtual ~ModelData();

        /////////////////////////
        //setters
        /////////////////////////

        inline void addLocation(const Vec3 & locationVector) {
            setLocation(m_location.x+locationVector.x,m_location.y+locationVector.y,m_location.z+locationVector.z);
        }
        inline void setLocation(const Vec3 & locationVector) {
            setLocation(locationVector.x,locationVector.y,locationVector.z);
        }
        inline void setRotationQuaternion(const Vec3 & rotationQuaternion) {
            setRotationQuaternion(rotationQuaternion.x,rotationQuaternion.y,rotationQuaternion.z,rotationQuaternion.w);
        }
        inline void setScale(const Vec3 & scaleVector) {
            setScale(scaleVector.x,scaleVector.y,scaleVector.z);
        }
        void setLocation(const GLfloat x,const GLfloat y,const GLfloat z) ;
        void setLocationX(const GLfloat x);
        void setLocationY(const GLfloat y);
        void setLocationZ(const GLfloat z);

        void setScale(const GLfloat width,const GLfloat height,const GLfloat depth) ;
        inline void setScale(const GLfloat scale) {
            setScale(scale,scale,scale);
        }
        void setScaleWidth(const GLfloat width) ;
        void setScaleHeight(const GLfloat height);
        void setScaleDepth(const GLfloat depth);
        /////////////////////////
        //operations
        /////////////////////////
        void rotateFirstByQuaternionThenByCurrentRotation(const Vec3 & rotationQuaternion);
        void rotateFirstByCurrentRotationThenByQuaternion(const Vec3 & rotationQuaternion);

        void moveAccordingToRotation(const GLfloat initialDirectionX=1,const GLfloat initialDirectionY=0,const GLfloat initialDirectionZ=0);

        void rotateAccordingToMouseMovementLockAxes(const double movementX,const double movementY,const double sensitivityInRadiansPerPixel);
        void rotateDegreesAccordingToMouseMovementLockAxes(const double movementX,const double movementY,const double sensitivityInDegreesPerPixel);

        void setAnotherModelPositionRelativelyToThisOne(ModelData & another, Vec3  relativePosition) const;
        inline void setAnotherModelPositionRelativelyToThisOne(ModelData & another,const GLfloat relativePositionX,const GLfloat relativePositionY,const GLfloat relativePositionZ) const {
            setAnotherModelPositionRelativelyToThisOne(another,Vec3(relativePositionX,  relativePositionY, relativePositionZ));
        }
        /////////////////////////
        //const getters
        /////////////////////////

        inline const GLfloat  getLocationX() const {
            return m_location.x;
        }
        inline const GLfloat getLocationY() const {
            return  m_location.y;
        }
        inline const GLfloat  getLocationZ() const {
            return m_location.z;
        }
        inline const GLfloat getScaleWidth() const {
            return m_scale.x;
        }
        inline const GLfloat getScaleHeight() const {
            return m_scale.y;
        }
        inline const GLfloat getScaleDepth() const {
            return m_scale.z;
        }
        inline const bool hasBeenModified() const {
            return m_hasBeenModified;
        }
        inline const Vec3 & getLocation()const {
            return m_location;
        }
        inline const Vec3 & getScale()const {
            return m_scale;
        }
        inline const Vec3 & getRotation()const {
            return m_rotation;
        }
      protected:


      private:
        void setRotationQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat w);

        bool m_hasBeenModified;
        Vec3 m_location;
        /**Rotation is a quaternion*/
        Vec3 m_rotation;
        Vec3 m_scale;
    };
}

#endif // MODEL_DATA_H
