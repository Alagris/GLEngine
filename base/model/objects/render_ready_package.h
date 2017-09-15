#ifndef RENDER_READY_PACKAGE_H
#define RENDER_READY_PACKAGE_H
//#include <GLFW/glfw3.h>
#include <vector>
#include "vao_vbo_ebo_package.h"
namespace gle {
    /**Copying this object is potentially expensive. It contains 2 arrays and every copy of this object is a deep copy*/
    class RenderReadyPackage
    {
      public:
        RenderReadyPackage(
            const VaoVboEboPackage & pack,
            const int defaultColorSet=-1,
            const int defaultTextureSet=-1,
            const unsigned int shaderVertexInputLocation=0,
            const int shaderColorInputLocation=-1,
            const int shaderTextureInputLocation=-1):
            m_package(pack),
            m_shaderVertexInputLocation(shaderVertexInputLocation),
            m_shaderColorInputLocation(shaderColorInputLocation),
            m_shaderTextureInputLocation(shaderTextureInputLocation),
            m_defaultColorSet(defaultColorSet),
            m_defaultTextureSet(defaultTextureSet) {}

        RenderReadyPackage(
            const int defaultColorSet=-1,
            const int defaultTextureSet=-1,
            const unsigned int shaderVertexInputLocation=0,
            const int shaderColorInputLocation=-1,
            const int shaderTextureInputLocation=-1):
            RenderReadyPackage(
                VaoVboEboPackage(),
                defaultColorSet,
                defaultTextureSet,
                shaderVertexInputLocation,
                shaderColorInputLocation,
                shaderTextureInputLocation) {}

        virtual ~RenderReadyPackage() {}
        inline const  VaoVboEboPackage & getData()const {
            return m_package;
        }
        inline  VaoVboEboPackage & getData() {
            return m_package;
        }
        inline void setData(const VaoVboEboPackage & pack) {
            m_package=pack;
        }
        inline const unsigned int getShaderVertexInputLocation()const {
            return m_shaderVertexInputLocation;
        }
        inline void setShaderVertexInputLocation(const unsigned int inputLocation) {
            m_shaderVertexInputLocation=inputLocation;
        }
        inline const unsigned int getShaderColorInputLocation()const {
            return m_shaderColorInputLocation;
        }
        inline void setShaderColorInputLocation(const unsigned int inputLocation) {
            m_shaderColorInputLocation=inputLocation;
        }
        inline const unsigned int getShaderTextureInputLocation()const {
            return m_shaderTextureInputLocation;
        }
        inline void setShaderTextureInputLocation(const unsigned int inputLocation) {
            m_shaderTextureInputLocation=inputLocation;
        }
        inline void setDefaultColorSetIndexUsedByVBOs(const int setIndex) {
            m_defaultColorSet=setIndex;
        }
        inline void setDefaultTextureSetIndexUsedByVBOs(const int setIndex) {
            m_defaultTextureSet=setIndex;
        }
        const int getTextureSetIndexUsedByVBO(const unsigned int vboIndex)const;
        void setTextureSetIndexUsedByVBO(const int setIndex,const unsigned int vboIndex);
        void setColorSetIndexUsedByVBO(const int setIndex,const unsigned int vboIndex);
        const int getColorSetIndexUsedByVBO(const unsigned int vboIndex)const;
      protected:
      private:
        void setTextureSetIndex(const int setIndex,const unsigned int vboIndex);
        void setColorSetIndex(const int setIndex,const unsigned int vboIndex);
        bool isValidColorSetIndex(const int setIndex,const unsigned int vboIndex);
        bool isValidTextureSetIndex(const int setIndex,const unsigned int vboIndex);

        VaoVboEboPackage m_package;
        unsigned int m_shaderVertexInputLocation;
        int m_shaderColorInputLocation;
        int m_shaderTextureInputLocation;
        int m_defaultColorSet;
        int m_defaultTextureSet;
        std::vector<int> m_colorSetIndexPerVBO;
        std::vector<int> m_textureSetIndexPerVBO;
    };
}
#endif // RENDER_READY_PACKAGE_H
