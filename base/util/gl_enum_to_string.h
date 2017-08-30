#ifndef GL_ENUM_TO_STRING_H
#define GL_ENUM_TO_STRING_H
#include <string>
#include <GLFW/glfw3.h>
namespace gle{
	bool getNameOfEnum(const GLenum glenum,std::string & outputDestination);
	bool getNameOfGL_DEBUG_SEVERITY(const GLenum glenum,std::string & outputDestination);
	bool getNameOfGL_DEBUG_TYPE(const GLenum glenum,std::string & outputDestination);
	bool getNameOfGLFW_KeyAction(const GLenum glenum,std::string & outputDestination);
}

#endif // GL_ENUM_TO_STRING_H
