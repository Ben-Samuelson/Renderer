#include "ShaderProgram.hpp"

#include "Shader.hpp"

#include <GL/glew.h>

#include <iostream>

ShaderProgram::ShaderProgram(Shader vertex, Shader fragment)
{
    m_handle = glCreateProgram();
    glAttachShader(m_handle, vertex.handle());
    glAttachShader(m_handle, fragment.handle());
    glLinkProgram(m_handle);

    GLchar infoLog[LOG_LENGTH];
    GLint linkingStatus;
    glGetProgramiv(m_handle, GL_LINK_STATUS, &linkingStatus);
    if (linkingStatus != GL_TRUE)
    {
        glGetProgramInfoLog(m_handle, LOG_LENGTH, nullptr, infoLog);
        std::cerr << "Error: " << infoLog << std::endl;
    }
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_handle);
}

GLuint ShaderProgram::handle() const
{
    return m_handle;
}

void ShaderProgram::use() const
{
    glUseProgram(m_handle);
}
