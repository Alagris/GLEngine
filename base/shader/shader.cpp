#include "shader_compiler.h"
#include "shader.h"


namespace gle {


    void Shader::tryToDestroyProgram() const {
        if((*m_referenceCount)==0) {
            glDeleteProgram(m_shaderProgram);
            delete m_referenceCount;
        }
    }

    Shader::Shader():
        m_shaderProgram(0),
        m_referenceCount(nullptr)
    {
    }

    Shader::Shader(const char * const vertexShaderFilePath,const char * const fragmentShaderFilePath):
        m_shaderProgram(buildProgram(vertexShaderFilePath,fragmentShaderFilePath)),
        m_referenceCount(new unsigned int(1))
    {
    }

    Shader::Shader( const Shader &s):
        m_shaderProgram(s.m_shaderProgram),
        m_referenceCount(s.m_referenceCount)
    {
        addReference(1);
    }
    Shader & Shader::operator=( const Shader &s) {
        m_shaderProgram=s.m_shaderProgram;

        addReference(-1);
        tryToDestroyProgram();
        m_referenceCount=s.m_referenceCount;
        addReference(1);

        return *this;
    }


    void  Shader::addReference(const unsigned int count) const {
        if(m_referenceCount!=nullptr) {
            (*m_referenceCount)+=count;
        }
    }

    bool Shader::load(const char * const vertexShaderFilePath,const char * const fragmentShaderFilePath) {
        if(m_shaderProgram==0&&m_referenceCount==nullptr) {
            m_shaderProgram=buildProgram(vertexShaderFilePath,fragmentShaderFilePath);
            m_referenceCount=new unsigned int(1);
            return true;
        } else {

            return false;
        }
    }

    void Shader::bind() {
        glUseProgram(m_shaderProgram);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }

    Shader::~Shader()
    {
        addReference(-1);
        tryToDestroyProgram();
    }
}
