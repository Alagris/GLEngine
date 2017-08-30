#ifndef SHADER_H
#define SHADER_H
#include "bindable.h"
#include "GLFW/glfw3.h"
namespace gle {
    class Shader:public Bindable
    {
      public:
        Shader();
        Shader(const char * const vertexShaderFilePath,const char * const fragmentShaderFilePath);
        Shader(const Shader &);
        Shader & operator=( const Shader &);

        virtual ~Shader();
        virtual void bind();
        virtual void unbind();
        bool load(const char * const vertexShaderFilePath,const char * const fragmentShaderFilePath);
        inline const GLuint getID() const{
            return m_shaderProgram;
        }
      protected:

      private:
        void addReference(const unsigned int count) const;
        void tryToDestroyProgram() const;

        GLuint m_shaderProgram;
        unsigned int * m_referenceCount;
    };
}
#endif // SHADER_H
