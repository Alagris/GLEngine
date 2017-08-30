#ifndef MODEL_H
#define MODEL_H
#include "model_data.h"
namespace gle {

    class Model:public ModelData
    {
      public:
        Model();
        virtual ~Model();


        /////////////////////////
        //operations
        /////////////////////////
        void updateModelMatrix();


        /////////////////////////
        //non-const getters
        /////////////////////////

        inline GLfloat * getModelMatrix() {
            return m_modelMatrix;
        }


        /////////////////////////
        //const getters
        /////////////////////////


        inline const GLfloat * getModelMatrix() const {
            return m_modelMatrix;
        }


      protected:

      private:
        Mat4 m_modelMatrix;
    };
}
#endif // MODEL_H
