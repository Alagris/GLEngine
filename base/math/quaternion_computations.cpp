#include "quaternion_computations.h"
#include "vector_helpers.h"
#include <math.h>
namespace gle {



    void generateQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle, Vec3 & outputQuaternion,const GLfloat sinAngle) {
        const GLfloat l = getVec3Length(x,y,z);
        outputQuaternion.w = std::cos(angle/2);
        outputQuaternion.x = x*sinAngle/l ;
        outputQuaternion.y = y*sinAngle/l ;
        outputQuaternion.z = z*sinAngle/l ;
    }

    void generateQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle, Vec3 & outputQuaternion) {
        generateQuaternion( x, y, z, angle,  outputQuaternion,std::sin( angle/2 ));
    }

    void generateReverseQuaternion(const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle, Vec3 & outputQuaternion) {
        generateQuaternion( x, y, z, angle,  outputQuaternion,-std::sin( angle/2 ));
    }

    void reverseQuaternion(Vec3 & quaternion) {
        quaternion.x = -quaternion.x;
        quaternion.y = -quaternion.y;
        quaternion.z = -quaternion.z;
    }



    void normalizeQuaternion(Vec3 & quaternion) {
        GLfloat length = std::sqrt(quaternion.x*quaternion.x+quaternion.y*quaternion.y+quaternion.z*quaternion.z+quaternion.w*quaternion.w);
        quaternion.x/=length;
        quaternion.y/=length;
        quaternion.z/=length;
        quaternion.w/=length;
    }

    void multiplyQuaternions(
                             const GLfloat lhsx,const GLfloat lhsy,const GLfloat lhsz,const GLfloat lhsw,
                             const GLfloat rhsx,const GLfloat rhsy,const GLfloat rhsz,const GLfloat rhsw,
                             Vec3 & output ) {
        output.x = ( lhsx * rhsw + lhsy * rhsz - lhsz * rhsy + lhsw * rhsx);
        output.y = (-lhsx * rhsz + lhsy * rhsw + lhsz * rhsx + lhsw * rhsy);
        output.z = ( lhsx * rhsy - lhsy * rhsx + lhsz * rhsw + lhsw * rhsz);
        output.w = (-lhsx * rhsx - lhsy * rhsy - lhsz * rhsz + lhsw * rhsw);
    }

    void rotateVec3WithQuaternion(Vec3 & rotatedPoint,const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle) {
        Vec3 quaternion;
        generateQuaternion(x,y,z,angle,quaternion);
        rotateVec3WithQuaternion(rotatedPoint,quaternion);
    }
    void rotateVec3WithQuaternion(Vec3 & rotatedPoint,const Vec3 & quaternion) {
        Vec3 tmp;
        multiplyQuaternions(quaternion,rotatedPoint,tmp);
        multiplyQuaternionsReverseRight(tmp,quaternion,rotatedPoint);
    }
    void rotateVec3WithReversedQuaternion(Vec3 & rotatedPoint,const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle) {
        Vec3 quaternion;
        generateQuaternion(x,y,z,angle,quaternion);
        rotateVec3WithReversedQuaternion(rotatedPoint,quaternion);
    }
    void rotateVec3WithReversedQuaternion(Vec3 & rotatedPoint,const Vec3 & quaternion) {
        Vec3 tmp;
        multiplyQuaternionsReverseLeft(quaternion,rotatedPoint,tmp);
        multiplyQuaternions(tmp,quaternion,rotatedPoint);

    }






}
