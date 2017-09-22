#ifndef RENDER_READY_PACKAGE_H
#define RENDER_READY_PACKAGE_H
#include <memory>
#include "shader_types.h"
namespace gle {

    typedef int8_t set_index;
    class ModelNode;
    class VaoVboEboPackage;
    class RenderReadyRootNode;
    struct ShaderLightingUniforms;
    /**Copying this object is very cheap*/
    class RenderReadyPackage
    {
      public:
        /////////////////////////////
        //constructor
        /////////////////////////////
        RenderReadyPackage(
            const VaoVboEboPackage & pack,
            const set_index defaultColorSet=-1,
            const set_index defaultTextureSet=-1,
            const mandatory_shader_location shaderVertexInputLocation=0,
            const shader_location shaderColorInputLocation=-1,
            const shader_location shaderTextureInputLocation=-1,
            const shader_location shaderNormalInputLocation=-1,
            const shader_location shaderModelViewProjectionMatrixLocation=-1);

        RenderReadyPackage(
            const set_index defaultColorSet=-1,
            const set_index defaultTextureSet=-1,
            const mandatory_shader_location shaderVertexInputLocation=0,
            const shader_location shaderColorInputLocation=-1,
            const shader_location shaderTextureInputLocation=-1,
            const shader_location shaderNormalInputLocation=-1,
            const shader_location shaderModelViewProjectionMatrixLocation=-1);

        virtual ~RenderReadyPackage() {}
        /////////////////////////////
        //getters & setters
        /////////////////////////////
        const  VaoVboEboPackage & getData()const ;
        VaoVboEboPackage & getData() ;
        void setData(const VaoVboEboPackage & pack) ;
        const mandatory_shader_location getShaderVertexInputLocation()const ;
        void setShaderVertexInputLocation(const mandatory_shader_location inputLocation) ;
        const shader_location getShaderColorInputLocation()const ;
        void setShaderColorInputLocation(const shader_location inputLocation) ;
        const shader_location getShaderTextureInputLocation()const ;
        void setShaderTextureInputLocation(const shader_location inputLocation);
        const shader_location getShaderNormalInputLocation()const;
        void setShaderNormalInputLocation(const shader_location inputLocation);
        void setDefaultColorSetIndexUsedByVBOs(const set_index setIndex) ;
        void setDefaultTextureSetIndexUsedByVBOs(const set_index setIndex) ;
        const set_index getTextureSetIndexUsedByVBO(const unsigned int vboIndex)const;
        void setTextureSetIndexUsedByVBO(const set_index setIndex,const unsigned int vboIndex);
        void setColorSetIndexUsedByVBO(const set_index setIndex,const unsigned int vboIndex);
        const set_index getColorSetIndexUsedByVBO(const unsigned int vboIndex)const;
        const shader_location getShaderModelViewProjectionMatrixLocation()const;
        void setShaderModelViewProjectionMatrixLocation(const shader_location  mvpLocation);
        RenderReadyRootNode getRootNode(unsigned int index) const;
        void setRootNode(const RenderReadyRootNode & root ,unsigned int index);
        unsigned int getRootsSize() const;
        void addRootNode(const RenderReadyRootNode & root );
        void addRootNode(const std::shared_ptr<ModelNode> & root );
        void reserveRootNodesCapacity(const unsigned int capacity);
        const ShaderLightingUniforms & getLighting()const ;
        ShaderLightingUniforms & getLighting();
        /////////////////////////////
        //other
        /////////////////////////////
        const RenderReadyPackage clone()const {
            return RenderReadyPackage(pimpl);
        }
      protected:
      private:
        class Pimpl;
        std::shared_ptr<Pimpl> pimpl;
        RenderReadyPackage(const std::shared_ptr<Pimpl> & pimpl);


    };
}
#endif // RENDER_READY_PACKAGE_H
