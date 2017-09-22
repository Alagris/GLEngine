#ifndef AMBIENT_LIGHT_DATA_H
#define AMBIENT_LIGHT_DATA_H
#include "matrix_math_types.h"
namespace gle {
    struct AmbientLightData
    {
        AmbientLightData():
            m_ambientLightStrength(1),
            m_ambientLightColor(1,1,1,1)
        {}

        GLfloat m_ambientLightStrength;
        Vec3 m_ambientLightColor;
    };
}
#endif // AMBIENT_LIGHT_DATA_H
