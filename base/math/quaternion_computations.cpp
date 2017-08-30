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

    void multiplyQuaternions(const Vec3 & lhs,const Vec3 & rhs,Vec3 & output ) {
        output.x = ( lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y + lhs.w * rhs.x);
        output.y = (-lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x + lhs.w * rhs.y);
        output.z = ( lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w + lhs.w * rhs.z);
        output.w = (-lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z + lhs.w * rhs.w);
    }
    void multiplyQuaternionsOutputToLeft(Vec3 & lhs,const Vec3 & rhs ) {
        Vec3 tmp;
        multiplyQuaternions(lhs,rhs,tmp);
        setVec3(lhs,tmp);
    }
    void multiplyQuaternionsOutputToRight(const Vec3 & lhs,Vec3 & rhs ) {
        Vec3 tmp;
        multiplyQuaternions(lhs,rhs,tmp);
        setVec3(rhs,tmp);
    }


    void rotateVec3WithQuaternion(Vec3 & rotatedPoint,Vec3 & quaternion) {
        Vec3 tmp;
        multiplyQuaternions(quaternion,rotatedPoint,tmp);
        reverseQuaternion(quaternion);
        multiplyQuaternions(tmp,quaternion,rotatedPoint);
        reverseQuaternion(quaternion);
    }

    void rotateVec3WithQuaternion(Vec3 & rotatedPoint,const GLfloat x,const GLfloat y,const GLfloat z,const GLfloat angle) {
        Vec3 quaternion;
        generateQuaternion(x,y,z,angle,quaternion);
        rotateVec3WithQuaternion(rotatedPoint,quaternion);
    }




}
