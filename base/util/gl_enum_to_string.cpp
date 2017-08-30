#include "gl_enum_to_string.h"

#define GL_ENUM_CASE(glenum,output) case (glenum): \
									output=#glenum;\
									break;
namespace gle {
    bool getNameOfEnum(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                GL_ENUM_CASE(GL_COMPILE_STATUS,outputDestination);
                GL_ENUM_CASE(GL_INFO_LOG_LENGTH,outputDestination);
                GL_ENUM_CASE(GL_VERTEX_SHADER,outputDestination);
                GL_ENUM_CASE(GL_FRAGMENT_SHADER,outputDestination);
                GL_ENUM_CASE(GL_ARRAY_BUFFER,outputDestination);
                GL_ENUM_CASE(GL_STATIC_DRAW,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }
    bool getNameOfGL_DEBUG_TYPE(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                GL_ENUM_CASE(GL_DEBUG_TYPE_ERROR,outputDestination);
                GL_ENUM_CASE(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,outputDestination);
                GL_ENUM_CASE(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,outputDestination);
                GL_ENUM_CASE(GL_DEBUG_TYPE_PORTABILITY,outputDestination);
                GL_ENUM_CASE(GL_DEBUG_TYPE_PERFORMANCE,outputDestination);
                GL_ENUM_CASE(GL_DEBUG_TYPE_OTHER,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }
    bool getNameOfGL_DEBUG_SEVERITY(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_LOW,outputDestination);

#if GL_DEBUG_SEVERITY_LOW != GL_DEBUG_SEVERITY_LOW_AMD
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_LOW_AMD,outputDestination);
#endif // GL_DEBUG_SEVERITY_LOW
#if GL_DEBUG_SEVERITY_LOW != GL_DEBUG_SEVERITY_LOW_ARB
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_LOW_ARB,outputDestination);
#endif // GL_DEBUG_SEVERITY_LOW

                GL_ENUM_CASE(GL_DEBUG_SEVERITY_MEDIUM,outputDestination);
#if GL_DEBUG_SEVERITY_MEDIUM != GL_DEBUG_SEVERITY_MEDIUM_AMD
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_MEDIUM_AMD,outputDestination);
#endif // GL_DEBUG_SEVERITY_MEDIUM
#if GL_DEBUG_SEVERITY_MEDIUM != GL_DEBUG_SEVERITY_MEDIUM_ARB
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_MEDIUM_ARB,outputDestination);
#endif // GL_DEBUG_SEVERITY_MEDIUM

                GL_ENUM_CASE(GL_DEBUG_SEVERITY_HIGH,outputDestination);
#if GL_DEBUG_SEVERITY_HIGH != GL_DEBUG_SEVERITY_HIGH_AMD
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_HIGH_AMD,outputDestination);
#endif // GL_DEBUG_SEVERITY_HIGH
#if GL_DEBUG_SEVERITY_HIGH != GL_DEBUG_SEVERITY_HIGH_ARB
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_HIGH_ARB,outputDestination);
#endif // GL_DEBUG_SEVERITY_HIGH
                GL_ENUM_CASE(GL_DEBUG_SEVERITY_NOTIFICATION,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }


    bool getNameOfGLFW_KeyAction(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                GL_ENUM_CASE(GLFW_PRESS,outputDestination);
                GL_ENUM_CASE(GLFW_RELEASE,outputDestination);
                GL_ENUM_CASE(GLFW_REPEAT,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }
}
