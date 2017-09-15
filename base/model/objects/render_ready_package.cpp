#include "render_ready_package.h"
#include "vao_vbo_ebo_package.h"
#include "vertex_buffer_object.h"
namespace gle {
//    RenderReadyPackage::RenderReadyPackage()
//    {
//        //ctor
//    }

    bool RenderReadyPackage::isValidColorSetIndex(const int setIndex,const unsigned int vboIndex) {
        return 0<=setIndex && setIndex<m_package.getVBO(vboIndex).getColorSetsNumber();
    }
    bool RenderReadyPackage::isValidTextureSetIndex(const int setIndex,const unsigned int vboIndex) {
        return 0<=setIndex && setIndex<m_package.getVBO(vboIndex).getTextureSetsNumber();
    }
    void RenderReadyPackage::setTextureSetIndex(const int setIndex,const unsigned int vboIndex) {
        m_textureSetIndexPerVBO[vboIndex]=isValidTextureSetIndex(setIndex,vboIndex)?setIndex:-1;
    }
    void RenderReadyPackage::setColorSetIndex(const int setIndex,const unsigned int vboIndex) {
        m_colorSetIndexPerVBO[vboIndex]=isValidColorSetIndex(setIndex,vboIndex)?setIndex:-1;
    }

    const int RenderReadyPackage::getTextureSetIndexUsedByVBO(const unsigned int vboIndex)const {
        const VaoVboEboPackage & pack =m_package;
        if(vboIndex>=m_textureSetIndexPerVBO.size())return m_defaultTextureSet;
        if(vboIndex>pack.getVBOsNumber())return m_defaultTextureSet;
        const int out=m_textureSetIndexPerVBO[vboIndex];
        if(out<0)return m_defaultTextureSet;
        if(out>pack.getVBO(vboIndex).getTextureSetsNumber())return m_defaultTextureSet;
        return out;
    }

    const int RenderReadyPackage::getColorSetIndexUsedByVBO(const unsigned int vboIndex)const {
        const VaoVboEboPackage & pack =m_package;
        if(vboIndex>=m_colorSetIndexPerVBO.size())return m_defaultColorSet;
        if(vboIndex>pack.getVBOsNumber())return m_defaultColorSet;
        const int out=m_colorSetIndexPerVBO[vboIndex];
        if(out<0)return m_defaultColorSet;
        if(out>pack.getVBO(vboIndex).getColorSetsNumber())return m_defaultColorSet;
        return out;
    }

    void RenderReadyPackage::setTextureSetIndexUsedByVBO(const int setIndex,const unsigned int vboIndex) {
        const VaoVboEboPackage & pack =m_package;
        if(vboIndex>=pack.getVBOsNumber())return;
        if(vboIndex>=m_textureSetIndexPerVBO.size()) {
            m_textureSetIndexPerVBO.resize(vboIndex+1);
        }
        setTextureSetIndex(setIndex,vboIndex);
    }
    void RenderReadyPackage::setColorSetIndexUsedByVBO(const int setIndex,const unsigned int vboIndex) {
        const VaoVboEboPackage & pack =m_package;
        if(vboIndex>=pack.getVBOsNumber())return;
        if(vboIndex>=m_colorSetIndexPerVBO.size()) {
            m_colorSetIndexPerVBO.resize(vboIndex+1);
        }
        setColorSetIndex(setIndex,vboIndex);
    }

}
