#include "vector_helpers.h"
#include <math.h>
namespace gle {

    GLfloat getVec4Length(const GLfloat  x,const GLfloat  y,const GLfloat  z,const GLfloat  w) {
        return std::sqrt(x*x+y*y+z*z+w*w);
    }

    GLfloat getVec3Length(const GLfloat  x,const GLfloat  y,const GLfloat  z) {
        return std::sqrt(x*x+y*y+z*z);
    }

    void normalizeVec3(GLfloat & x,GLfloat & y,GLfloat & z,const GLfloat desiredLength) {
        const GLfloat ratio =desiredLength/getVec3Length(x,y,z);
        x*=ratio;
        y*=ratio;
        z*=ratio;

    }

    void normalizeVec4(GLfloat & x,GLfloat & y,GLfloat & z,GLfloat & w,const GLfloat desiredLength) {
        const GLfloat ratio =desiredLength/getVec4Length(x,y,z,w);
        x*=ratio;
        y*=ratio;
        z*=ratio;
        w*=ratio;
    }


    void setVec3( Vec3 & vector,const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat w) {
        vector.x=x;
        vector.y=y;
        vector.z=z;
        vector.w=w;
    }


}
