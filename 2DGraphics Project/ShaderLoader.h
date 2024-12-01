#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <string>

class ShaderLoader {
public:
    static std::string loadShaderSource(const std::string& filename);
    static unsigned int compileShader(unsigned int type, const std::string& source);
    static unsigned int createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
};

#endif // SHADERLOADER_H
#pragma once
