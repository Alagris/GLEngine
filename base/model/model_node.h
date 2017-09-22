#ifndef MODEL_NODE_H
#define MODEL_NODE_H
#include <vector>
#include <memory>
#include "model_base.h"
namespace gle {
//    class ModelBase;

    class ModelNode
    {
      public:
        ModelNode() {}
        ModelNode(const ModelBase & modelMatrix):m_modelMatrix(modelMatrix) {}
        virtual ~ModelNode() {}
        inline const unsigned int getVboIndex(unsigned int i)const {
            return m_vboIndexArray[i];
        }
        inline const unsigned int getVboIndexArraySize() const{
            return m_vboIndexArray.size();
        }
        inline ModelBase & getModelMatrix() {
            return m_modelMatrix;
        }
        inline const ModelBase & getModelMatrix() const {
            return m_modelMatrix;
        }
        inline const unsigned int getChildrenCount() const{
            return m_children.size();
        }
        inline std::shared_ptr<ModelNode> getChild(unsigned int index) {
            return m_children[index];
        }
        inline const std::shared_ptr<ModelNode> getChild(unsigned int index) const{
            return m_children[index];
        }
      protected:
        std::vector<std::shared_ptr<ModelNode>> m_children;
        std::vector<unsigned int> m_vboIndexArray;
        ModelBase m_modelMatrix;
      private:

    };
}

#endif // MODEL_NODE_H
