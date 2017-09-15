#ifndef VERTEX_ARRAY_OBJECT_HELPERS_H
#define VERTEX_ARRAY_OBJECT_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle {
    class VertexArrayObject;
    const bool hasVAO(const VertexArrayObject & vao);
    const bool hasVBO(const VertexArrayObject & vao);
    const bool hasEBO(const VertexArrayObject & vao);
    void bindEBO(const VertexArrayObject & vao);
    void bindVBO(const VertexArrayObject & vao);
    void bindVAO(const VertexArrayObject & vao);
    /**binds VBO and EBO with corresponding VAO*/
    void bindVAOTogether(const VertexArrayObject & vao);
}

#endif // VERTEX_ARRAY_OBJECT_HELPERS_H
