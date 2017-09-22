#ifndef VAO_VBO_PACKAGE_H
#define VAO_VBO_PACKAGE_H
#include <memory>
#include <GLFW/glfw3.h>
namespace gle {
    class VertexArrayObject;
    class VertexBufferObject;
    class ElementBufferObject;
    /**This object is super cheap to copy. It has only 1 field: shared pointer**/
    class VaoVboEboPackage
    {
      public:
        VaoVboEboPackage(const GLenum eboType=GL_UNSIGNED_INT,const bool deleteAutomatically=true);
        VaoVboEboPackage(const VertexArrayObject  & vao,const std::shared_ptr<VertexBufferObject>  &vbo,const ElementBufferObject & ebo);
        VaoVboEboPackage(const VertexArrayObject  & vao,const ElementBufferObject & ebo,const unsigned int vboCount);
        virtual ~VaoVboEboPackage() {}
        const VertexArrayObject & getVAO()const;
        const ElementBufferObject & getEBO()const;
        const std::shared_ptr<VertexBufferObject>  & getVBO(const unsigned int index)const;
        const unsigned int getVBOsNumber()const;
        virtual void generate(const GLenum usage) {};
      protected:
        void setVAO(const VertexArrayObject &vao);
        void setVBO(const std::shared_ptr<VertexBufferObject>  &vbo,const unsigned int index);
        void setEBO(const ElementBufferObject &ebo);
        void addVBO(const std::shared_ptr<VertexBufferObject>  &vbo);
        void reserveVBOsCapacity(const unsigned int capacity);
        VertexArrayObject & getVAORef();
        ElementBufferObject & getEBORef();
        std::shared_ptr<VertexBufferObject>  & getVBORef(const unsigned int index);
        std::shared_ptr<VertexBufferObject>  *const getVBOPtr();
        const std::shared_ptr<VertexBufferObject>  *const getVBOPtr()const;
      private:
        struct Pimpl;
        std::shared_ptr<Pimpl> pimpl;
    };
}
#endif // VAO_VBO_PACKAGE_H
