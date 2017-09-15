#ifndef VERTEX_ARRAY_OBJECT_H
#define VERTEX_ARRAY_OBJECT_H
#include <GLFW/glfw3.h>
#include "bindable.h"
#include <memory>
namespace gle {
    class VertexBufferObject;
    /**This object is really cheap to copy. It has only 1 fields which is a pointer (thanks to pimpl)*/
    class VertexArrayObject :public Bindable {
      public:
        VertexArrayObject(const bool destroyAutomatically=true);
        virtual ~VertexArrayObject(){}
        ////bind
        virtual void bind();
        virtual void unbind();
        ////get
        const GLuint getVAO()const;
        const GLuint getVBO()const;
        const GLuint getEBO()const;
        ////EBO functions
        void destroy();
        void generate();
      protected:
      private:
        class Pimpl;
        std::shared_ptr<Pimpl> pimpl;
    };
}


#endif // VERTEX_ARRAY_OBJECT_H
