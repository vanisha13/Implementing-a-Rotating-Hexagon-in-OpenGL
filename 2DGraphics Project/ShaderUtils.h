#ifndef SHADERUTILS_H
#define SHADERUTILS_H

#include <GL/glew.h>  // Or #include <glad/glad.h> if using glad

GLuint CompileShader(GLenum type, const char* source);
GLuint LinkShaders(GLuint vertexShader, GLuint fragmentShader);
void CheckShaderErrors(GLuint shader);

#endif // SHADERUTILS_H
