#ifndef DEGREE_RADIANS_CONVERSION_H_INCLUDED
#define DEGREE_RADIANS_CONVERSION_H_INCLUDED
#include <GL/glew.h>
namespace gle {
    /**This header conatins constants and a few small
    and frequently used funtions that could be easily
    used as constant expressions*/
    const float PI = 3.14159265358979f;

    inline GLfloat degreeToRad(const GLfloat degrees) {
        return PI/180*degrees;
    }
    inline GLfloat radToDegree(const GLfloat radians) {
        return 180*radians/PI;
    }
}


#endif // DEGREE_RADIANS_CONVERSION_H_INCLUDED
