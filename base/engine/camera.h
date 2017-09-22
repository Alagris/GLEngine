#ifndef CAMERA_H
#define CAMERA_H
#include "model_data.h"
namespace gle {
    class Camera:public ModelData
    {
      public:
        Camera(const GLfloat left,
               const GLfloat right,
               const GLfloat top,
               const GLfloat bottom,
               const GLfloat zNear,
               const GLfloat zFar,
               const bool isPerspectiveOtherwiseOrthographic=true);
        virtual ~Camera();



        /////////////////////////
        //setters
        /////////////////////////


        /////////////////////////
        //operations
        /////////////////////////
        void updateViewMatrix();

        inline virtual void updateModelMatrix(){
            updateViewMatrix();
        }

        void setPerspectiveProjection(const GLfloat left,
                                      const GLfloat right,
                                      const GLfloat top,
                                      const GLfloat bottom,
                                      const GLfloat zNear,
                                      const GLfloat zFar);
        void setOrthographicProjection(const GLfloat left,
                                       const GLfloat right,
                                       const GLfloat top,
                                       const GLfloat bottom,
                                       const GLfloat zNear,
                                       const GLfloat zFar);



        /**Make sure that view matrix is up to date, before calling this function*/
        void updateViewProjectionMatrix();



        /////////////////////////
        //const getters
        /////////////////////////


        const GLfloat * getViewProjectionMatrix()const{
            return m_viewProjection;
        }

        /////////////////////////
        //non-const getters
        /////////////////////////



        /////////////////////////
        //debug
        /////////////////////////


        void printViewProjectionMatrix()const;
        void printProjectionMatrix()const;
        void printViewMatrix()const;
      protected:

      private:
//        Mat4 m_viewMatrix;
        Mat4 m_projection;
        Mat4 m_viewProjection;
    };
}

#endif // CAMERA_H
