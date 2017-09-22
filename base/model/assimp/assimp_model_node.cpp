#include "assimp_model_node.h"
#include "assimp_model.h"
#include <assimp/scene.h>
#include <assimp/mesh.h>
namespace gle {

    AssimpModelNode::AssimpModelNode(const aiNode * const node,const unsigned int meshIndexOffset):
        ModelNode(AssimpModel(node->mTransformation))
    {
        m_vboIndexArray.reserve(node->mNumMeshes);
        for(unsigned int i=0; i<node->mNumMeshes; i++) {
            m_vboIndexArray.push_back(meshIndexOffset+node->mMeshes[i]);
        }


        m_children.reserve(node->mNumChildren);
        for(unsigned int i=0; i<node->mNumChildren; i++) {
            m_children.push_back(std::shared_ptr<ModelNode>( new AssimpModelNode(node->mChildren[i],meshIndexOffset)));
        }
    }

}
