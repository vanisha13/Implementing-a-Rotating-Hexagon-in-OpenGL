#include "ShaderUtils.h"
#include <iostream>

GLuint CompileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength, ' ');
        glGetShaderInfoLog(shader, logLength, &logLength, &log[0]);
        std::cerr << "Shader compilation error: " << log << std::endl;
    }
    return shader;
}

GLuint LinkShaders(GLuint vertexShader, GLuint fragmentShader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // Check for linking errors
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        std::string log(logLength, ' ');
        glGetProgramInfoLog(program, logLength, &logLength, &log[0]);
        std::cerr << "Program linking error: " << log << std::endl;
    }
    return program;
}

void CheckShaderErrors(GLuint shader) {
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        std::string infoLog(infoLogLength, '\0');
        glGetShaderInfoLog(shader, infoLogLength, &infoLogLength, &infoLog[0]);
        std::cerr << "Shader compile error: " << infoLog << std::endl;
    }
}
