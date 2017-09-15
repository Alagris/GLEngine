#ifndef GENERATABLE_H
#define GENERATABLE_H
#include <GLFW/glfw3.h>
namespace gle {
    class Generatable
    {
      public:
        Generatable();
        virtual ~Generatable();
        virtual const GLuint generate(const GLenum usage)  ;
        virtual const GLuint generate(const GLuint reservedID,const GLenum usage) =0 ;
      protected:

      private:
    };
}
#endif // GENERATABLE_H
