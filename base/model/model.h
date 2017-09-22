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


      protected:

      private:

    };
}
#endif // MODEL_H
