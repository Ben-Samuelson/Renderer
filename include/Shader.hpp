#pragma once

#include <GL/glew.h>

#include <string>

class Shader
{
    private:
        constexpr static auto LOG_LENGTH = std::size_t(512);

        GLuint m_handle;

    public:
        Shader(const std::string &sourceFile, GLenum type);
        ~Shader();

        GLuint handle() const;
};
