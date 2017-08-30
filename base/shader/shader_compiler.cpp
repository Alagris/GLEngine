#include "shader_compiler.h"
#include <string>
#include <iostream>
#include "gl_enum_to_string.h"
#include "file_reader.h"
namespace gle {
    GLuint compileShaderFile(const char * const filePath,const GLenum shaderType) {
        std::string shaderSource;
        if(!readWholeFile(filePath,shaderSource)) {
            std::cerr<<"Failed to read shader file! ("<<filePath<<")\n";
        }
        return compileShaderSource(shaderSource.c_str(),shaderType);
    }

    GLuint compileShaderSource(const char * const shaderSource,const GLenum shaderType) {
        GLuint shaderID = glCreateShader(shaderType);

        glShaderSource(shaderID,1,&shaderSource,nullptr);
        glCompileShader(shaderID);

        GLint result = GL_FALSE;
        GLint infoLogLength =0;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(result==GL_FALSE) {
            std::string shaderTypeName;
            getNameOfEnum(shaderType,shaderTypeName);
            std::cerr<<"Shader compilation failed! ("<<shaderTypeName<<") \n";
        }
        if ( infoLogLength > 1 ) {
            GLchar * shaderErrorMessage = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(shaderID, infoLogLength, NULL, shaderErrorMessage);
            std::cerr << "SHADER COMPILER LOG: "<<shaderErrorMessage<<std::endl;
            delete[] shaderErrorMessage;
        }
        return shaderID;
    }


    GLuint linkShaders(const GLuint vertexShader,const GLuint fragmentShader) {
        GLuint programID = glCreateProgram();
        glAttachShader(programID, vertexShader);
        glAttachShader(programID, fragmentShader);
        glLinkProgram(programID);

        GLint result = GL_FALSE;
        GLint infoLogLength =0;
        glGetProgramiv(programID, GL_LINK_STATUS, &result);
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(result==GL_FALSE) {
            std::cerr<<"Shader linking failed!\n";
        }
        if ( infoLogLength > 1 ) {
            GLchar * programErrorMessage = new GLchar[infoLogLength+1];
            glGetProgramInfoLog(programID, infoLogLength, NULL, programErrorMessage);
            std::cerr <<"SHADER LINKER LOG: "<< programErrorMessage<<std::endl;
            delete[] programErrorMessage;
        }
        glDetachShader(programID, vertexShader);
        glDetachShader(programID, fragmentShader);
        return programID;
    }

    GLuint compileProgram(
        const char * const vertexShaderSource,
        const char * const fragmentShaderSource) {
        GLuint vertexShaderID =compileShaderSource(vertexShaderSource,GL_VERTEX_SHADER);
        GLuint fragmentShaderID =compileShaderSource(fragmentShaderSource,GL_FRAGMENT_SHADER);
        GLuint programID= linkShaders(vertexShaderID,fragmentShaderID);
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
        return programID;
    }

    GLuint buildProgram(
        const char * const vertexShaderFilePath,
        const char * const fragmentShaderFilePath) {

        GLuint vertexShaderID =compileShaderFile(vertexShaderFilePath,GL_VERTEX_SHADER);
        GLuint fragmentShaderID =compileShaderFile(fragmentShaderFilePath,GL_FRAGMENT_SHADER);
        GLuint programID= linkShaders(vertexShaderID,fragmentShaderID);
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
        return programID;
    }
}
