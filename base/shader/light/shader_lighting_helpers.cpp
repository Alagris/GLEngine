#include "shader_lighting_helpers.h"
#include "shader_lighting_data.h"
#include "shader_lighting_uniforms.h"
#include "ambient_light_helpers.h"
#include "diffuse_light_helpers.h"
namespace gle{
    void bind(const ShaderLightingData & data,const ShaderLightingUniforms & uniforms){
        bind(data.ambient,uniforms.ambient);
        bind(data.diffuse,uniforms.diffuse);
    }

}
