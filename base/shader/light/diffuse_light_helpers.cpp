#include <GL/glew.h>
#include "diffuse_light_helpers.h"
#include "diffuse_light_data.h"
#include "diffuse_light_uniforms.h"
namespace gle {

     void setDiffuseLightShaderInputLocation(
        DiffuseLightUniforms & uniforms,
        const GLuint program,
        const  GLchar *const colorInputLocation,
        const  GLchar *const positionInputLocation)
    {
        uniforms.m_shaderDiffuseLightColorUniformLocation=glGetUniformLocation(program,colorInputLocation);
        uniforms.m_shaderDiffuseLightPositionUniformLocation=glGetUniformLocation(program,positionInputLocation);
    }

    void bind(const DiffuseLightData & data,const DiffuseLightUniforms & uniforms) {
        if(uniforms.m_shaderDiffuseLightColorUniformLocation>-1) {
            glUniform3fv(uniforms.m_shaderDiffuseLightColorUniformLocation,1,uniforms.m_diffuseLightColor.getArray());
        }
        if(uniforms.m_shaderDiffuseLightPositionUniformLocation>-1) {
            glUniform3fv(uniforms.m_shaderDiffuseLightPositionUniformLocation,1,uniforms.m_diffuseLightPosition.getArray());
        }
    }
}
