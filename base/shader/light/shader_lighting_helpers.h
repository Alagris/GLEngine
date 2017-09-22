#ifndef SHADER_LIGHTING_HELPERS_H
#define SHADER_LIGHTING_HELPERS_H
namespace gle {
    struct ShaderLightingData;
    struct ShaderLightingUniforms;
    void bind(const ShaderLightingData & data,const ShaderLightingUniforms & uniforms);
}
#endif // SHADER_LIGHTING_HELPERS_H
