#include <GL/glew.h>
#include "ambient_light_helpers.h"
#include "ambient_light_data.h"
#include "ambient_light_uniforms.h"
#include "vector_helpers.h"
#include "vector_computations.h"
#include "vertex_attrib_helpers.h"
namespace gle {
    void setAmbientLightShaderInputLocation(
        AmbientLightUniforms & uniforms,
        const GLuint program,
        const  GLchar *const colorInputLocation,
        const  GLchar *const strengthInputLocation)
    {
        uniforms.m_shaderAmbientLightColorUniformLocation=glGetUniformLocation(program,colorInputLocation);
        uniforms.m_shaderAmbientLightStrengthUniformLocation=glGetUniformLocation(program,strengthInputLocation);
    }

    /**Binds ambient color to vertex uniforms*/
    void bind(const AmbientLightData & data,const AmbientLightUniforms & uniforms) {
        if(uniforms.m_shaderAmbientLightColorUniformLocation>-1) {
            glUniform3fv(uniforms.m_shaderAmbientLightColorUniformLocation,1,data.m_ambientLightColor.getArray());
        }
        if(uniforms.m_shaderAmbientLightStrengthUniformLocation>-1) {
            glUniform1f(uniforms.m_shaderAmbientLightStrengthUniformLocation,data.m_ambientLightStrength);
        }
    }
    /**Precomputes ambient color and binds it to color vertex attribute*/
    void bind(const AmbientLightData & data,const Vec3 surfaceColor,const shader_location shaderColorInputLocation) {
        if(shaderColorInputLocation>-1) {
            bind(data,surfaceColor,static_cast<mandatory_shader_location>(shaderColorInputLocation));
        }
    }
    /**Precomputes ambient color and binds it to color vertex attribute*/
    void bind(const AmbientLightData & data,const Vec3 surfaceColor,const mandatory_shader_location shaderColorInputLocation) {
        glVertexAttrib<4,float>(
            shaderColorInputLocation,
            getColorR(data,surfaceColor),
            getColorG(data,surfaceColor),
            getColorB(data,surfaceColor),
            getColorA(data,surfaceColor));
        glDisableVertexAttribArray(shaderColorInputLocation);
    }

    void getColor(const AmbientLightData & data,const Vec3 surfaceColor,Vec3 outputAmbientSurfaceColor) {
        setVec3(outputAmbientSurfaceColor,data.m_ambientLightColor);
        multiplyVec3ByFloat(outputAmbientSurfaceColor,data.m_ambientLightStrength);
        dotVec3OutputToRight(data.m_ambientLightColor,outputAmbientSurfaceColor);
    }


    const GLfloat getColorR(const AmbientLightData & data,const GLfloat surfaceColorR ) {
        return data.m_ambientLightColor.x*surfaceColorR*data.m_ambientLightStrength;
    }
    const GLfloat getColorG(const AmbientLightData & data,const GLfloat surfaceColorG) {
        return data.m_ambientLightColor.y*surfaceColorG*data.m_ambientLightStrength;
    }
    const GLfloat getColorB(const AmbientLightData & data,const GLfloat surfaceColorB) {
        return data.m_ambientLightColor.z*surfaceColorB*data.m_ambientLightStrength;
    }
    const GLfloat getColorA(const AmbientLightData & data,const GLfloat surfaceColorA) {
        return data.m_ambientLightColor.w*surfaceColorA*data.m_ambientLightStrength;
    }


}
