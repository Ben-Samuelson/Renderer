#include "Shader.hpp"

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string &fileName, GLenum type)
{
    std::ifstream file;
    file.open(fileName);
    std::ostringstream sourceStream;
    sourceStream << file.rdbuf();
    file.close();
    std::string source = sourceStream.str();
    const char *sourceCString = source.data();

    m_handle = glCreateShader(type);
    glShaderSource(m_handle, 1, &sourceCString, nullptr);
    glCompileShader(m_handle);

    GLchar infoLog[LOG_LENGTH];
    GLint compilationStatus;
    glGetShaderiv(m_handle, GL_COMPILE_STATUS, &compilationStatus);
    if (compilationStatus != GL_TRUE)
    {
        glGetShaderInfoLog(m_handle, LOG_LENGTH, nullptr, infoLog);
        std::cerr << "Error: " << infoLog << std::endl;
    }
}

Shader::~Shader()
{
    glDeleteShader(m_handle);
}

GLuint Shader::handle() const
{
    return m_handle;
}
