#ifndef MODEL_BASE_H
#define MODEL_BASE_H
#include "matrix_math_types.h"
#include <GLFW/glfw3.h>
namespace gle {

    class ModelBase
    {
      public:
        ModelBase() {}
        virtual ~ModelBase() {}
        virtual void updateModelMatrix(){}

        inline const GLfloat * getModelMatrix() const {
            return m_modelMatrix;
        }
        inline GLfloat * getModelMatrix() {
            return m_modelMatrix;
        }
      protected:
        Mat4 m_modelMatrix;
      private:
    };
}
#endif // MODEL_BASE_H
