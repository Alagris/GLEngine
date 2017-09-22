#ifndef AMBIENT_LIGHT_HELPERS_H
#define AMBIENT_LIGHT_HELPERS_H
#include "shader_types.h"
#include "matrix_math_types.h"
namespace gle {
    struct AmbientLightData;
    struct AmbientLightUniforms;

    void setAmbientLightShaderInputLocation(
        AmbientLightUniforms & data,
        const GLuint program,
        const  GLchar *const colorInputLocation,
        const  GLchar *const strengthInputLocation);
    /**Binds ambient color to vertex uniforms*/
    void bind(const AmbientLightData & data,const AmbientLightUniforms & uniforms);
    /**Precomputes ambient color and binds it to color vertex attribute*/
    void bind(const AmbientLightData & data,const Vec3 surfaceColor,const shader_location shaderColorInputLocation);
    /**Precomputes ambient color and binds it to color vertex attribute*/
    void bind(const AmbientLightData & data,const Vec3 surfaceColor,const mandatory_shader_location shaderColorInputLocation);
    void getColor(const AmbientLightData & data,const Vec3 surfaceColor,Vec3 outputAmbientSurfaceColor);

    const GLfloat getColorR(const AmbientLightData & data,const GLfloat surfaceColorR );
    const GLfloat getColorG(const AmbientLightData & data,const GLfloat surfaceColorG);
    const GLfloat getColorB(const AmbientLightData & data,const GLfloat surfaceColorB);
    const GLfloat getColorA(const AmbientLightData & data,const GLfloat surfaceColorA);
    inline const GLfloat getColorR(const AmbientLightData & data,const Vec3 surfaceColor) {
        return getColorR(data,surfaceColor.x);
    }
    inline const GLfloat getColorG(const AmbientLightData & data,const Vec3 surfaceColor) {
        return getColorG(data,surfaceColor.y);
    }
    inline const GLfloat getColorB(const AmbientLightData & data,const Vec3 surfaceColor) {
        return getColorB(data,surfaceColor.z);
    }
    inline const GLfloat getColorA(const AmbientLightData & data,const Vec3 surfaceColor) {
        return getColorA(data,surfaceColor.w);
    }
}
#endif // AMBIENT_LIGHT_HELPERS_H
