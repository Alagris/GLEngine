#ifndef SHADER_LIGHTING_DATA_H
#define SHADER_LIGHTING_DATA_H
#include "ambient_light_data.h"
#include "diffuse_light_data.h"
namespace gle {

    struct ShaderLightingData
    {
        AmbientLightData ambient;
        DiffuseLightData diffuse;
    };

}
#endif // SHADER_LIGHTING_DATA_H
