#ifndef DIFFUSE_LIGHT_HELPERS_H
#define DIFFUSE_LIGHT_HELPERS_H

namespace gle{
    struct DiffuseLightData;
    struct DiffuseLightUniforms;
    void setDiffuseLightShaderInputLocation(
        DiffuseLightUniforms & uniforms,
        const GLuint program,
        const  GLchar *const colorInputLocation,
        const  GLchar *const positionInputLocation);

    void bind(const DiffuseLightData & data,const DiffuseLightUniforms & uniforms);
}

#endif // DIFFUSE_LIGHT_HELPERS_H
