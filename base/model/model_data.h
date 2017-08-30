#ifndef MODEL_DATA_H
#define MODEL_DATA_H

#include "matrix_math_types.h"
namespace gle {

    class ModelData
    {
      public:
        ModelData();
        virtual ~ModelData();

        /////////////////////////
        //setters
        /////////////////////////

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
        void rotateByQuaternion(const Vec3 & rotationQuaternion);
        void updateModelMatrix();

        void moveAccordingToRotation(const GLfloat initialDirectionX=1,const GLfloat initialDirectionY=0,const GLfloat initialDirectionZ=0);



        /////////////////////////
        //const getters
        /////////////////////////

        inline const Vec3 getRotationQuaternion() const {
            return m_rotation;
        }
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
        inline const bool hasBeenModified() const{
            return m_hasBeenModified;
        }

      protected:
        inline  Vec3 & getRotationQuaternionByRef()  {
            return m_rotation;
        }
        inline const Vec3 & getRotationQuaternionByRef() const {
            return m_rotation;
        }
      private:
        void setRotationQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat w);

        bool m_hasBeenModified=false;
        Vec3 m_location;
        /**Rotation is a quaternion*/
        Vec3 m_rotation;
        Vec3 m_scale;
    };
}

#endif // MODEL_DATA_H
