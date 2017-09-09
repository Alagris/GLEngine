#ifndef VERTEX_ARRAY_OBJECT_H
#define VERTEX_ARRAY_OBJECT_H
#include <GLFW/glfw3.h>
#include <assimp/scene.h>
#include "bindable.h"
#include <vector>
#include <memory>
namespace gle {
    typedef intptr_t ebo_offset;

    struct VertexBufferObject;
    /**This object is really cheap to copy. It has only a
    single field which is a shared_ptr (thanks to pimpl!!!)*/
    class VertexArrayObject :public Bindable {
      public:
        VertexArrayObject();
        VertexArrayObject(const aiMesh * const mesh);
        VertexArrayObject(const aiMesh * const * const meshes,const unsigned int meshesNum);
        VertexArrayObject(const aiScene* const scene);
        ~VertexArrayObject();
        void bind();
        void bindEBO();
        void bindVBO();
        inline void bindVAO() {
            bind();
        }
        void unbind();
        static void unbindEBO();
        static void unbindVBO();
        inline void unbindVAO() {
            unbind();
        }
        const GLuint getVAO()const;
        const GLuint getVBO()const;
        const GLuint getEBO()const;
        inline const bool hasVAO()const{
            return getVAO()!=0;
        }
        inline const bool hasVBO()const{
            return getVBO()!=0;
        }
        inline const bool hasEBO()const{
            return getEBO()!=0;
        }
        const unsigned int size() const;
        inline bool empty() const {
            return size()==0;
        }
        const VertexBufferObject & getVBO(unsigned int index)const;
        const GLsizei getEBOArraySize(unsigned int index)const;
        const ebo_offset getEBOArrayOffset(unsigned int index)const;
        const GLenum getEBOArrayType()const;
        void renderEBO(const GLenum mode,unsigned int index)const;
        void renderAllEBO(const GLenum mode)const;
        void destroy();
      protected:
      private:
        void generateID();
        void push_back(const aiMesh * const mesh);
        class Pimpl;
        std::shared_ptr<Pimpl> pimpl;
    };
}


#endif // VERTEX_ARRAY_OBJECT_H
