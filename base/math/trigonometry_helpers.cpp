#include "trigonometry_helpers.h"
#include <math.h>
namespace gle{

    GLfloat getSinFromCos(const GLfloat cos){
        return std::sqrt(1-cos*cos);
    }

}
