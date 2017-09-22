#ifndef SHADER_LIGHTING_UNIFORMS_H
#define SHADER_LIGHTING_UNIFORMS_H
#include "ambient_light_uniforms.h"
#include "diffuse_light_uniforms.h"
namespace gle {

    struct ShaderLightingUniforms
    {
        AmbientLightUniforms ambient;
        DiffuseLightUniforms diffuse;
    };


}


#endif // SHADER_LIGHTING_UNIFORMS_H
