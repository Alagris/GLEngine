#include "element_buffer_object.h"
#include "assimp_helpers.h"
namespace gle {
    ElementBufferObject::ElementBufferObject():
        elementArraySize(0),
        elementArrayOffset(0) {}

    ElementBufferObject::ElementBufferObject(const aiMesh*const mesh):
        type(GL_UNSIGNED_INT),
        elementArraySize(countIndicesInMesh(mesh)),
        elementArrayOffset(0) {}


}
