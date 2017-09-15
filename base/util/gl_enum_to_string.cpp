#include "gl_enum_to_string.h"
#include "switch_case_enum_to_string.h"
namespace gle {
    bool getNameOfEnum(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                ENUM_CASE(GL_COMPILE_STATUS,outputDestination);
                ENUM_CASE(GL_INFO_LOG_LENGTH,outputDestination);
                ENUM_CASE(GL_VERTEX_SHADER,outputDestination);
                ENUM_CASE(GL_FRAGMENT_SHADER,outputDestination);
                ENUM_CASE(GL_ARRAY_BUFFER,outputDestination);
                ENUM_CASE(GL_STATIC_DRAW,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }
    bool getNameOfGL_DEBUG_TYPE(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                ENUM_CASE(GL_DEBUG_TYPE_ERROR,outputDestination);
                ENUM_CASE(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,outputDestination);
                ENUM_CASE(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,outputDestination);
                ENUM_CASE(GL_DEBUG_TYPE_PORTABILITY,outputDestination);
                ENUM_CASE(GL_DEBUG_TYPE_PERFORMANCE,outputDestination);
                ENUM_CASE(GL_DEBUG_TYPE_OTHER,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }
    bool getNameOfGL_DEBUG_SEVERITY(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                ENUM_CASE(GL_DEBUG_SEVERITY_LOW,outputDestination);

#if GL_DEBUG_SEVERITY_LOW != GL_DEBUG_SEVERITY_LOW_AMD
                ENUM_CASE(GL_DEBUG_SEVERITY_LOW_AMD,outputDestination);
#endif // GL_DEBUG_SEVERITY_LOW
#if GL_DEBUG_SEVERITY_LOW != GL_DEBUG_SEVERITY_LOW_ARB
                ENUM_CASE(GL_DEBUG_SEVERITY_LOW_ARB,outputDestination);
#endif // GL_DEBUG_SEVERITY_LOW

                ENUM_CASE(GL_DEBUG_SEVERITY_MEDIUM,outputDestination);
#if GL_DEBUG_SEVERITY_MEDIUM != GL_DEBUG_SEVERITY_MEDIUM_AMD
                ENUM_CASE(GL_DEBUG_SEVERITY_MEDIUM_AMD,outputDestination);
#endif // GL_DEBUG_SEVERITY_MEDIUM
#if GL_DEBUG_SEVERITY_MEDIUM != GL_DEBUG_SEVERITY_MEDIUM_ARB
                ENUM_CASE(GL_DEBUG_SEVERITY_MEDIUM_ARB,outputDestination);
#endif // GL_DEBUG_SEVERITY_MEDIUM

                ENUM_CASE(GL_DEBUG_SEVERITY_HIGH,outputDestination);
#if GL_DEBUG_SEVERITY_HIGH != GL_DEBUG_SEVERITY_HIGH_AMD
                ENUM_CASE(GL_DEBUG_SEVERITY_HIGH_AMD,outputDestination);
#endif // GL_DEBUG_SEVERITY_HIGH
#if GL_DEBUG_SEVERITY_HIGH != GL_DEBUG_SEVERITY_HIGH_ARB
                ENUM_CASE(GL_DEBUG_SEVERITY_HIGH_ARB,outputDestination);
#endif // GL_DEBUG_SEVERITY_HIGH
                ENUM_CASE(GL_DEBUG_SEVERITY_NOTIFICATION,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }


    bool getNameOfGLFW_KeyAction(const GLenum glenum,std::string & outputDestination) {
        switch(glenum) {
                ENUM_CASE(GLFW_PRESS,outputDestination);
                ENUM_CASE(GLFW_RELEASE,outputDestination);
                ENUM_CASE(GLFW_REPEAT,outputDestination);
            default:
                outputDestination="unknown GLenum";
                return false;
        }
        return true;
    }
}
