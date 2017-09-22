#ifndef ASSIMP_MODEL_NODE_H
#define ASSIMP_MODEL_NODE_H
#include "model_node.h"
#include <assimp/scene.h>
namespace gle {
//    class ModelBase;
    class AssimpModelNode:public ModelNode
    {
      public:
        AssimpModelNode(const aiScene * const scene,const unsigned int meshIndexOffset=0):AssimpModelNode(scene->mRootNode,meshIndexOffset){}
        virtual ~AssimpModelNode(){}
      protected:
      private:
        AssimpModelNode(const aiNode * const node,const unsigned int meshIndexOffset);
    };
}
#endif // ASSIMP_MODEL_NODE_H
