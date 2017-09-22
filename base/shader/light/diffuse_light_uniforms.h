#ifndef DIFFUSE_LIGHT_UNIFORMS_H
#define DIFFUSE_LIGHT_UNIFORMS_H
#include <GLFW/glfw3.h>
#include "matrix_math_types.h"
namespace gle {
    struct DiffuseLightUniforms
    {
        DiffuseLightUniforms():
            m_diffuseLightPosition(0,0,0,1),
            m_diffuseLightColor(1,1,1,1),
            m_shaderDiffuseLightColorUniformLocation(-1),
            m_shaderDiffuseLightPositionUniformLocation(-1)
        {}


        Vec3 m_diffuseLightPosition;
        Vec3 m_diffuseLightColor;
        GLint m_shaderDiffuseLightColorUniformLocation;
        GLint m_shaderDiffuseLightPositionUniformLocation;
    };
}
#endif // DIFFUSE_LIGHT_UNIFORMS_H
