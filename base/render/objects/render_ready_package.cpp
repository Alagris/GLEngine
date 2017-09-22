#include "model_base.h"
#include "render_ready_package.h"
#include "vao_vbo_ebo_package_helpers.h"
#include "vao_vbo_ebo_package.h"
#include "vertex_buffer_object.h"
#include <vector>
#include "render_ready_root_node.h"
//#include "model_node.h"
//#include "shader_lighting_data.h"
#include "shader_lighting_uniforms.h"
namespace gle {


    /////////////////////////////////
    /////////////////////////////////
    //PIMPL
    /////////////////////////////////
    /////////////////////////////////

    class RenderReadyPackage::Pimpl {
      public:
        /////////////////////////////
        //constructor
        /////////////////////////////
        Pimpl(
            const VaoVboEboPackage & pack,
            const set_index defaultColorSet,
            const set_index defaultTextureSet,
            const mandatory_shader_location shaderVertexInputLocation,
            const shader_location shaderColorInputLocation,
            const shader_location shaderTextureInputLocation,
            const shader_location shaderNormalInputLocation,
            const shader_location shaderModelViewProjectionMatrixLocation):
            m_package(pack),
            m_shaderVertexInputLocation(shaderVertexInputLocation),
            m_shaderColorInputLocation(shaderColorInputLocation),
            m_shaderTextureInputLocation(shaderTextureInputLocation),
            m_shaderNormalInputLocation(shaderNormalInputLocation),
            m_defaultColorSet(defaultColorSet),
            m_defaultTextureSet(defaultTextureSet),
//            m_rootNode(nullptr),
            m_shaderModelViewProjectionMatrixLocation(shaderModelViewProjectionMatrixLocation)
        {}

        Pimpl(const Pimpl & p):
            m_package(p.m_package),
            m_shaderVertexInputLocation(p.m_shaderVertexInputLocation),
            m_shaderColorInputLocation(p.m_shaderColorInputLocation),
            m_shaderTextureInputLocation(p.m_shaderTextureInputLocation),
            m_shaderNormalInputLocation(p.m_shaderNormalInputLocation),
            m_defaultColorSet(p.m_defaultColorSet),
            m_defaultTextureSet(p.m_defaultTextureSet),
            m_colorSetIndexPerVBO(p.m_colorSetIndexPerVBO),
            m_textureSetIndexPerVBO(p.m_textureSetIndexPerVBO),
            m_shaderModelViewProjectionMatrixLocation(p.m_shaderModelViewProjectionMatrixLocation),
            m_roots()
        {
            m_roots.reserve(p.m_roots.size());
            for(unsigned int i=0; i<p.m_roots.size(); i++) {
                m_roots.push_back(p.m_roots[i].clone());
            }
        }


        virtual ~Pimpl() {}
        /////////////////////////////
        //getters & setters
        /////////////////////////////

        inline const  VaoVboEboPackage & getData()const {
            return m_package;
        }
        inline  VaoVboEboPackage & getData() {
            return m_package;
        }
        inline void setData(const VaoVboEboPackage & pack) {
            m_package=pack;
        }
        inline const mandatory_shader_location getShaderVertexInputLocation()const {
            return m_shaderVertexInputLocation;
        }
        inline void setShaderVertexInputLocation(const mandatory_shader_location inputLocation) {
            m_shaderVertexInputLocation=inputLocation;
        }
        inline const shader_location getShaderColorInputLocation()const {
            return m_shaderColorInputLocation;
        }
        inline void setShaderColorInputLocation(const shader_location inputLocation) {
            m_shaderColorInputLocation=inputLocation;
        }
        inline const  shader_location getShaderTextureInputLocation()const {
            return m_shaderTextureInputLocation;
        }
        inline void setShaderTextureInputLocation(const shader_location inputLocation) {
            m_shaderTextureInputLocation=inputLocation;
        }
        inline const shader_location getShaderNormalInputLocation()const {
            return m_shaderNormalInputLocation;
        }
        inline void setShaderNormalInputLocation(const shader_location inputLocation) {
            m_shaderNormalInputLocation=inputLocation;
        }
        inline void setDefaultColorSetIndexUsedByVBOs(const set_index setIndex) {
            m_defaultColorSet=setIndex;
        }
        inline void setDefaultTextureSetIndexUsedByVBOs(const set_index setIndex) {
            m_defaultTextureSet=setIndex;
        }
//        inline std::shared_ptr<ModelNode> & getRootNode() {
//            return m_rootNode;
//        }
//        inline const std::shared_ptr<ModelNode> & getRootNode()const {
//            return m_rootNode;
//        }
        inline const shader_location getShaderModelViewProjectionMatrixLocation()const {
            return m_shaderModelViewProjectionMatrixLocation;
        }
        inline void setShaderModelViewProjectionMatrixLocation(const shader_location  mvpLocation) {
            m_shaderModelViewProjectionMatrixLocation=mvpLocation;
        }

        const set_index getTextureSetIndexUsedByVBO(const unsigned int vboIndex)const {
            const VaoVboEboPackage & pack =m_package;
            if(!isTextureSetSpecifiedForVBO(vboIndex)) {
                //in this case return default set
                return m_defaultTextureSet;
            }
            if(vboExists(vboIndex)) {
                //in this case it's an error
                return -1;
            }
            const set_index out=m_textureSetIndexPerVBO[vboIndex];
            if(out<0) {
                //in this case return default set
                return m_defaultTextureSet;
            }
            if(!isTextureSetValidForVBO(vboIndex,out)) {
                //in this case let's fall back to default one
                return m_defaultTextureSet;
            }
            return out;
        }

        const set_index getColorSetIndexUsedByVBO(const unsigned int vboIndex)const {
            const VaoVboEboPackage & pack =m_package;
            if(!isColorSetSpecifiedForVBO(vboIndex)) {
                //in this case return default set
                return m_defaultColorSet;
            }
            if(vboExists(vboIndex)) {
                //in this case it's an error
                return -1;
            }
            const set_index out=m_colorSetIndexPerVBO[vboIndex];
            if(out<0) {
                //in this case return default set
                return m_defaultColorSet;
            }
            if(!isColorSetValidForVBO(vboIndex,out)) {
                //in this case let's fall back to default one
                return m_defaultColorSet;
            }
            return out;
        }

        void setTextureSetIndexUsedByVBO(const set_index setIndex,const unsigned int vboIndex) {
            const VaoVboEboPackage & pack =m_package;
            if(vboIndex>=pack.getVBOsNumber())return;
            if(vboIndex>=m_textureSetIndexPerVBO.size()) {
                if(!isValidTextureSetIndex(setIndex,vboIndex))return;
                m_textureSetIndexPerVBO.reserve(vboIndex+1);
                while(m_textureSetIndexPerVBO.size()<vboIndex)m_textureSetIndexPerVBO.push_back(-1);
                m_textureSetIndexPerVBO.push_back(setIndex);
            } else {
                setTextureSetIndex(setIndex,vboIndex);
            }
        }
        void setColorSetIndexUsedByVBO(const set_index setIndex,const unsigned int vboIndex) {
            const VaoVboEboPackage & pack =m_package;
            if(vboIndex>=pack.getVBOsNumber())return;
            if(vboIndex>=m_colorSetIndexPerVBO.size()) {
                if(!isValidColorSetIndex(setIndex,vboIndex))return;
                m_colorSetIndexPerVBO.reserve(vboIndex+1);
                while(m_colorSetIndexPerVBO.size()<vboIndex)m_colorSetIndexPerVBO.push_back(-1);
                m_colorSetIndexPerVBO.push_back(setIndex);
            } else {
                setColorSetIndex(setIndex,vboIndex);
            }
        }

//        inline const float getDefaultColorR()const {
//            return m_defaultColorR;
//        }
//        inline const float getDefaultColorG()const {
//            return m_defaultColorG;
//        }
//        inline const float getDefaultColorB()const {
//            return m_defaultColorB;
//        }
//        inline const float getDefaultColorA()const {
//            return m_defaultColorA;
//        }
//        inline void setDefaultColorR(const float f) {
//            m_defaultColorR=f;
//        }
//        inline void setDefaultColorG(const float f) {
//            m_defaultColorG=f;
//        }
//        inline void setDefaultColorB(const float f) {
//            m_defaultColorB=f;
//        }
//        inline void setDefaultColorA(const float f) {
//            m_defaultColorA=f;
//        }
//        inline void setDefaultColor(const float r,const float g,const float b,const float a) {
//            setDefaultColorR(r);
//            setDefaultColorG(g);
//            setDefaultColorB(b);
//            setDefaultColorA(a);
//        }
//        inline ShaderLightingData & getLightingData() {
//            return m_lighting;
//        }
//        inline const ShaderLightingData & getLightingData() const {
//            return m_lighting;
//        }
        inline unsigned int getRootsSize() const {
            return m_roots.size();
        }
        inline RenderReadyRootNode getRootNode(unsigned int index) const {
            return m_roots[index];
        }
        inline void setRootNode(const RenderReadyRootNode & root,unsigned int index ) {
            m_roots[index]=root;
        }
        inline void addRootNode(const RenderReadyRootNode & root ) {
            m_roots.push_back(root);
        }
        inline void addRootNode(const std::shared_ptr<ModelNode> & root ) {
            m_roots.push_back(RenderReadyRootNode(root));
        }
        inline void reserveRootNodesCapacity(const unsigned int capacity) {
            m_roots.reserve(capacity);
        }
        inline const ShaderLightingUniforms & getLighting()const {
            return m_lighting;
        }
        inline ShaderLightingUniforms & getLighting() {
            return m_lighting;
        }
      private:
        VaoVboEboPackage m_package;
        mandatory_shader_location m_shaderVertexInputLocation;
        shader_location m_shaderColorInputLocation;
        shader_location m_shaderTextureInputLocation;
        shader_location m_shaderNormalInputLocation;
        set_index m_defaultColorSet;
        set_index m_defaultTextureSet;
        std::vector<set_index> m_colorSetIndexPerVBO;
        std::vector<set_index> m_textureSetIndexPerVBO;
        shader_location m_shaderModelViewProjectionMatrixLocation;
        std::vector<RenderReadyRootNode> m_roots;
        ShaderLightingUniforms m_lighting;


        inline const bool isValidColorSetIndex(const set_index setIndex,const unsigned int vboIndex) const {
            return 0<=setIndex && setIndex<getVBO(m_package,vboIndex).getColorSetsNumber();
        }
        inline const bool isValidTextureSetIndex(const set_index setIndex,const unsigned int vboIndex)const {
            return 0<=setIndex && setIndex<getVBO(m_package,vboIndex).getTextureSetsNumber();
        }
        inline void setTextureSetIndex(const set_index setIndex,const unsigned int vboIndex) {
            m_textureSetIndexPerVBO[vboIndex]=isValidTextureSetIndex(setIndex,vboIndex)?setIndex:-1;
        }
        inline void setColorSetIndex(const set_index setIndex,const unsigned int vboIndex) {
            m_colorSetIndexPerVBO[vboIndex]=isValidColorSetIndex(setIndex,vboIndex)?setIndex:-1;
        }

        inline const bool isTextureSetValidForVBO(const unsigned int vboIndex,const int textureSet) const {
            return textureSet<getVBO(m_package,vboIndex).getTextureSetsNumber();
        }
        inline const bool isTextureSetSpecifiedForVBO(const unsigned int vboIndex) const {
            return vboIndex<m_textureSetIndexPerVBO.size();
        }
        inline const bool vboExists(const unsigned int vboIndex)const {
            return vboIndex<m_package.getVBOsNumber();
        }
        inline const bool isColorSetValidForVBO(const unsigned int vboIndex,const int colorSet)const {
            return colorSet<getVBO(m_package,vboIndex).getColorSetsNumber();
        }
        inline const bool isColorSetSpecifiedForVBO(const unsigned int vboIndex)const {
            return vboIndex<m_colorSetIndexPerVBO.size();
        }


    };

    /////////////////////////////////
    /////////////////////////////////
    //RenderReadyPackage
    /////////////////////////////////
    /////////////////////////////////


    /////////////////////////////
    //constructor
    /////////////////////////////


    RenderReadyPackage::RenderReadyPackage(
        const VaoVboEboPackage & pack,
        const set_index defaultColorSet,
        const set_index defaultTextureSet,
        const mandatory_shader_location shaderVertexInputLocation,
        const shader_location shaderColorInputLocation,
        const shader_location shaderTextureInputLocation,
        const shader_location shaderNormalInputLocation,
        const shader_location shaderModelViewProjectionMatrixLocation):
        pimpl(
            new Pimpl(
                pack,
                defaultColorSet,
                defaultTextureSet,
                shaderVertexInputLocation,
                shaderColorInputLocation,
                shaderTextureInputLocation,
                shaderNormalInputLocation,
                shaderModelViewProjectionMatrixLocation
            )
        ) {}

    RenderReadyPackage::RenderReadyPackage(
        const set_index defaultColorSet,
        const set_index defaultTextureSet,
        const mandatory_shader_location shaderVertexInputLocation,
        const shader_location shaderColorInputLocation,
        const shader_location shaderTextureInputLocation,
        const shader_location shaderNormalInputLocation,
        const shader_location shaderModelViewProjectionMatrixLocation):
        RenderReadyPackage(
            VaoVboEboPackage(),
            defaultColorSet,
            defaultTextureSet,
            shaderVertexInputLocation,
            shaderColorInputLocation,
            shaderTextureInputLocation,
            shaderNormalInputLocation,
            shaderModelViewProjectionMatrixLocation) {}

    RenderReadyPackage::RenderReadyPackage(const std::shared_ptr<Pimpl> & p):pimpl(new Pimpl(*(p.get()))) {}


    /////////////////////////////
    //getters & setters
    /////////////////////////////


    const  VaoVboEboPackage & RenderReadyPackage::getData()const {
        return pimpl->getData();
    }
    VaoVboEboPackage & RenderReadyPackage::getData() {
        return pimpl->getData();
    }
    void RenderReadyPackage::setData(const VaoVboEboPackage & pack) {
        pimpl->setData(pack);
    }
    const mandatory_shader_location RenderReadyPackage::getShaderVertexInputLocation()const {
        return pimpl->getShaderVertexInputLocation();
    }
    void RenderReadyPackage::setShaderVertexInputLocation(const mandatory_shader_location inputLocation) {
        pimpl->setShaderVertexInputLocation(inputLocation);
    }
    const shader_location RenderReadyPackage::getShaderColorInputLocation()const {
        return pimpl->getShaderColorInputLocation();
    }
    void RenderReadyPackage::setShaderColorInputLocation(const shader_location inputLocation) {
        pimpl->setShaderColorInputLocation(inputLocation);
    }
    const shader_location RenderReadyPackage::getShaderTextureInputLocation()const {
        return pimpl->getShaderTextureInputLocation();
    }
    void RenderReadyPackage::setShaderTextureInputLocation(const shader_location inputLocation) {
        pimpl->setShaderTextureInputLocation(inputLocation);
    }
    const shader_location RenderReadyPackage::getShaderNormalInputLocation()const {
        return pimpl->getShaderNormalInputLocation();
    }
    void RenderReadyPackage::setShaderNormalInputLocation(const shader_location inputLocation) {
        pimpl->setShaderNormalInputLocation(inputLocation);
    }
    void RenderReadyPackage::setDefaultColorSetIndexUsedByVBOs(const set_index setIndex) {
        pimpl->setDefaultColorSetIndexUsedByVBOs(setIndex);
    }
    void RenderReadyPackage::setDefaultTextureSetIndexUsedByVBOs(const set_index setIndex) {
        pimpl->setDefaultTextureSetIndexUsedByVBOs(setIndex);
    }
    const set_index RenderReadyPackage::getTextureSetIndexUsedByVBO(const unsigned int vboIndex)const {
        return  pimpl->getTextureSetIndexUsedByVBO(vboIndex);
    }
    const set_index RenderReadyPackage::getColorSetIndexUsedByVBO(const unsigned int vboIndex)const {
        return  pimpl->getColorSetIndexUsedByVBO(vboIndex);
    }
    void RenderReadyPackage::setTextureSetIndexUsedByVBO(const set_index setIndex,const unsigned int vboIndex) {
        pimpl->setTextureSetIndexUsedByVBO(setIndex,vboIndex);
    }
    void RenderReadyPackage::setColorSetIndexUsedByVBO(const set_index setIndex,const unsigned int vboIndex) {
        pimpl->setColorSetIndexUsedByVBO(setIndex,vboIndex);
    }

    const shader_location RenderReadyPackage::getShaderModelViewProjectionMatrixLocation()const {
        return pimpl->getShaderModelViewProjectionMatrixLocation();
    }
    void RenderReadyPackage::setShaderModelViewProjectionMatrixLocation(const shader_location  mvpLocation) {
        pimpl->setShaderModelViewProjectionMatrixLocation(mvpLocation);
    }

    unsigned int RenderReadyPackage::getRootsSize() const {
        return pimpl->getRootsSize();
    }
    void RenderReadyPackage::addRootNode(const RenderReadyRootNode & root ) {
        pimpl->addRootNode(root);
    }
    void RenderReadyPackage::addRootNode(const std::shared_ptr<ModelNode> & root ) {
        pimpl->addRootNode(root);
    }
    RenderReadyRootNode RenderReadyPackage::getRootNode(unsigned int index) const {
        return pimpl->getRootNode(index);
    }
    void RenderReadyPackage::setRootNode(const RenderReadyRootNode & root,unsigned int index ) {
        pimpl->setRootNode(root,index);
    }
    void RenderReadyPackage::reserveRootNodesCapacity(const unsigned int capacity) {
        pimpl->reserveRootNodesCapacity(capacity);
    }

    const ShaderLightingUniforms & RenderReadyPackage::getLighting()const {
        return pimpl->getLighting();
    }
    ShaderLightingUniforms & RenderReadyPackage::getLighting(){
        return pimpl->getLighting();
    }
}
