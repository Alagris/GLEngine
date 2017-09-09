#ifndef VERTEX_ARRAY_OBJECT_RENDERER_H
#define VERTEX_ARRAY_OBJECT_RENDERER_H

namespace gle{
    struct VertexArrayObject;
    struct VertexBufferObject;
    struct ElementBufferObject;

    void renderVAO(const GLenum mode,const VertexArrayObject & vao,const GLenum type=GL_UNSIGNED_INT);
    void renderEBO(const GLenum mode,const ElementBufferObject & ebo,const GLenum type=GL_UNSIGNED_INT);
}

#endif // VERTEX_ARRAY_OBJECT_RENDERER_H
