#include "render_ready_root_node.h"
#include "shader_lighting_data.h"
namespace gle {

    /////////////////////////////////
    /////////////////////////////////
    //PIMPL
    /////////////////////////////////
    /////////////////////////////////

    class RenderReadyRootNode::Pimpl {
      public:
        /////////////////////////////
        //constructor
        /////////////////////////////
        Pimpl() {}
        Pimpl(const std::shared_ptr<ModelNode> & root):m_rootNode(root) {}
        Pimpl(const Pimpl & p):
            m_rootNode(p.m_rootNode),
            m_defaultColorR(p.m_defaultColorR),
            m_defaultColorG(p.m_defaultColorG),
            m_defaultColorB(p.m_defaultColorB),
            m_defaultColorA(p.m_defaultColorA),
            m_lighting(p.m_lighting)
        {}
        /////////////////////////////
        //getters & setters
        /////////////////////////////
        inline std::shared_ptr<ModelNode> & get() {
            return m_rootNode;
        }
        inline const std::shared_ptr<ModelNode> & get()const {
            return m_rootNode;
        }
        inline const float getDefaultColorR()const {
            return m_defaultColorR;
        }
        inline const float getDefaultColorG()const {
            return m_defaultColorG;
        }
        inline const float getDefaultColorB()const {
            return m_defaultColorB;
        }
        inline const float getDefaultColorA()const {
            return m_defaultColorA;
        }
        inline void setDefaultColorR(const float f) {
            m_defaultColorR=f;
        }
        inline void setDefaultColorG(const float f) {
            m_defaultColorG=f;
        }
        inline void setDefaultColorB(const float f) {
            m_defaultColorB=f;
        }
        inline void setDefaultColorA(const float f) {
            m_defaultColorA=f;
        }
        inline void setDefaultColor(const float r,const float g,const float b,const float a) {
            setDefaultColorR(r);
            setDefaultColorG(g);
            setDefaultColorB(b);
            setDefaultColorA(a);
        }
        inline ShaderLightingData & getLightingData() {
            return m_lighting;
        }
        inline const ShaderLightingData & getLightingData() const {
            return m_lighting;
        }
      protected:
      private:
        std::shared_ptr<ModelNode> m_rootNode;
        float m_defaultColorR=0;
        float m_defaultColorG=1;
        float m_defaultColorB=0;
        float m_defaultColorA=1;
        ShaderLightingData m_lighting;
    };

    /////////////////////////////////
    /////////////////////////////////
    //RenderReadyRootNode
    /////////////////////////////////
    /////////////////////////////////


    /////////////////////////////
    //constructor
    /////////////////////////////

    RenderReadyRootNode::RenderReadyRootNode():pimpl(new Pimpl()) {}

    RenderReadyRootNode::RenderReadyRootNode(const std::shared_ptr<Pimpl> & p):pimpl(new Pimpl(*(p.get()))) {}

    RenderReadyRootNode::RenderReadyRootNode(const std::shared_ptr<ModelNode> & root):pimpl(new Pimpl(root)) {}

    /////////////////////////////
    //getters & setters
    /////////////////////////////

    std::shared_ptr<ModelNode> & RenderReadyRootNode::get() {
        return pimpl->get();
    }
    const std::shared_ptr<ModelNode> & RenderReadyRootNode::get()const {
        const Pimpl *const p=pimpl.get();
        return p->get();
    }
    const float RenderReadyRootNode::getDefaultColorR()const {
        return pimpl->getDefaultColorR();
    }
    const float RenderReadyRootNode::getDefaultColorG()const {
        return RenderReadyRootNode::pimpl->getDefaultColorG();
    }
    const float RenderReadyRootNode::getDefaultColorB()const {
        return pimpl->getDefaultColorB();
    }
    const float RenderReadyRootNode::getDefaultColorA()const {
        return pimpl->getDefaultColorA();
    }
    void RenderReadyRootNode::setDefaultColorR(const float f) {
        pimpl->setDefaultColorR(f);
    }
    void RenderReadyRootNode::setDefaultColorG(const float f) {
        pimpl->setDefaultColorG(f);
    }
    void RenderReadyRootNode::setDefaultColorB(const float f) {
        pimpl->setDefaultColorB(f);
    }
    void RenderReadyRootNode::setDefaultColorA(const float f) {
        pimpl->setDefaultColorA(f);
    }
    void RenderReadyRootNode::setDefaultColor(const float r,const float g,const float b,const float a) {
        pimpl->setDefaultColor(r,g,b,a);
    }
    ShaderLightingData & RenderReadyRootNode::getLightingData() {
        return  pimpl->getLightingData();
    }
    const ShaderLightingData & RenderReadyRootNode::getLightingData() const {
        return  pimpl->getLightingData();
    }
}
