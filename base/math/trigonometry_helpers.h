#ifndef TRIGONOMETRY_HELPERS_H
#define TRIGONOMETRY_HELPERS_H
#include <GLFW/glfw3.h>
namespace gle {

    GLfloat getSinFromCos(const GLfloat cos);

    inline GLfloat getCosFromSin(const GLfloat sin) {
        return getSinFromCos(sin);
    }

    /**Returns sin(-angle) for given sin(angle)*/
    inline  GLfloat getSinOfNegativeAngle(const GLfloat sin) {
        return -sin;
    }

    /**Returns cos(-angle) for given cos(angle)*/
    inline GLfloat getCosOfNegativeAngle(const GLfloat cos) {
        return cos;
    }

    /**Returns tan(-angle) for given tan(angle)*/
    inline GLfloat getTanOfNegativeAngle(const GLfloat tan) {
        return -tan;
    }



    inline GLfloat sinOfSummedAngles(const GLfloat sin1,const GLfloat sin2,const GLfloat cos1,const GLfloat cos2) {
        return sin1*cos2+cos1*sin2;
    }
    inline GLfloat sinOfSummedAngles(const GLfloat sin1,const GLfloat sin2) {
        return sinOfSummedAngles(sin1,sin2,getCosFromSin(sin1),getCosFromSin(sin2));
    }


    inline GLfloat cosOfSummedAngles(const GLfloat cos1,const GLfloat cos2, const GLfloat sin1,const GLfloat sin2) {
        return cos1*cos2-sin1*sin2;
    }
    inline GLfloat cosOfSummedAngles(const GLfloat cos1,const GLfloat cos2) {
        return cosOfSummedAngles(cos1,cos2,getSinFromCos(cos1),getSinFromCos(cos2));
    }





}
#endif // TRIGONOMETRY_HELPERS_H
