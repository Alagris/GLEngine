#ifndef RENDER_READY_ROOT_NODE_H
#define RENDER_READY_ROOT_NODE_H
#include <memory>
namespace gle {
    class ModelNode;
    class ShaderLightingData;
    class RenderReadyRootNode
    {
      public:
          /////////////////////////////
        //constructor
        /////////////////////////////
        RenderReadyRootNode();
        RenderReadyRootNode(const std::shared_ptr<ModelNode> & root);
        virtual ~RenderReadyRootNode() {}
        /////////////////////////////
        //getters & setters
        /////////////////////////////
        std::shared_ptr<ModelNode> & get();
        const std::shared_ptr<ModelNode> & get()const;
        const float getDefaultColorR()const;
        const float getDefaultColorG()const;
        const float getDefaultColorB()const;
        const float getDefaultColorA()const;
        void setDefaultColorR(const float f);
        void setDefaultColorG(const float f);
        void setDefaultColorB(const float f);
        void setDefaultColorA(const float f);
        void setDefaultColor(const float r,const float g,const float b,const float a);
        ShaderLightingData & getLightingData();
        const ShaderLightingData & getLightingData() const;
        /////////////////////////////
        //other
        /////////////////////////////
        const RenderReadyRootNode clone()const {
            return RenderReadyRootNode(pimpl);
        }
      protected:

      private:

        class Pimpl;
        std::shared_ptr<Pimpl> pimpl;
        RenderReadyRootNode(const std::shared_ptr<Pimpl> & p);
    };
}

#endif // RENDER_READY_ROOT_NODE_H
