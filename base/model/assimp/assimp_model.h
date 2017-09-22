#ifndef ASSIMP_MODEL_H
#define ASSIMP_MODEL_H
#include "model_base.h"
#include <assimp/matrix4x4.h>
namespace gle{
class AssimpModel:public ModelBase
{
    public:
        /**Default constructor uses identity matrix*/
        AssimpModel();
        AssimpModel(const aiMatrix4x4 & matrix);
        virtual ~AssimpModel(){}

    protected:

    private:
};
}
#endif // ASSIMP_MODEL_H
