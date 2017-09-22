#ifndef AMBIENT_LIGHT_UNIFORMS_H
#define AMBIENT_LIGHT_UNIFORMS_H
#include <GLFW/glfw3.h>
namespace gle {
    struct AmbientLightUniforms
    {
        AmbientLightUniforms():
            m_shaderAmbientLightColorUniformLocation(-1),
            m_shaderAmbientLightStrengthUniformLocation(-1)
            {}

        GLint m_shaderAmbientLightColorUniformLocation;
        GLint m_shaderAmbientLightStrengthUniformLocation;
    };
}
#endif // AMBIENT_LIGHT_UNIFORMS_H
