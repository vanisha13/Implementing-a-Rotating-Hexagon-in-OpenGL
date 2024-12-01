#include <GL/glew.h> // For GLEW functions
#include <GLFW/glfw3.h> // For GLFW functions
#include "ShaderLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Function to load shader source code from a file
std::string ShaderLoader::loadShaderSource(const std::string& filename) {
    std::ifstream shaderFile(filename);
    if (!shaderFile.is_open()) {
        std::cerr << "Failed to open shader file: " << filename << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << shaderFile.rdbuf();
    return buffer.str();
}

// Function to compile a shader
unsigned int ShaderLoader::compileShader(unsigned int type, const std::string& source) {
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Error: " << infoLog << std::endl;
    }

    return shader;
}

// Function to create a shader program
unsigned int ShaderLoader::createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexSource = loadShaderSource(vertexPath);
    std::string fragmentSource = loadShaderSource(fragmentPath);

    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader Program Linking Error: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
