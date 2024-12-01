#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void checkCompileErrors(GLuint shader, std::string type);

private:
    GLuint vertex, fragment;
    void compileShader(const char* shaderCode, GLenum shaderType, GLuint& shader);
};

#endif
