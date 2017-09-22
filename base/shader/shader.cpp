#include <GL/glew.h>
#include "shader_compiler.h"
#include "shader.h"


namespace gle {



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
        (*m_referenceCount)++;
    }
    Shader & Shader::operator=( const Shader &s) {
        if (this == &s) return *this;
        commonDestructor();
        m_shaderProgram=s.m_shaderProgram;
        m_referenceCount=s.m_referenceCount;
        (*m_referenceCount)++;
        return *this;
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
        commonDestructor();
    }

    void Shader::commonDestructor() {
        if(m_referenceCount) {
            (*m_referenceCount)--;
            if((*m_referenceCount)==0) {
                glDeleteProgram(m_shaderProgram);
                delete m_referenceCount;
            }
        }
    }
}
