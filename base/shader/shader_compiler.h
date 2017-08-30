#ifndef SHADER_COMPILER_H
#define SHADER_COMPILER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace gle {
    /**Returns id of shader (not entire program)*/
    GLuint compileShaderFile(const char * const filePath,const GLenum shaderType);
    /**Returns id of shader (not entire program)*/
    GLuint compileShaderSource(const char * const shaderSource,const GLenum shaderType);
    /**Returns id of program*/
    GLuint linkShaders(const GLuint vertexShader,const GLuint fragmentShader);
    /**calls compileShaderFile() and compileProgram() and then destroys loaded GLSL source code.Returns program id*/
    GLuint buildProgram(const char * const vertexShaderFilePath,const char * const fragmentShaderFilePath);
    /**calls compileShaderSource() and compileProgram() and then destroys loaded GLSL source code.Returns program id*/
    GLuint compileProgram(const char * const vertexShaderSource,const char * const fragmentShaderSource);
}
#endif // SHADER_COMPILER_H
