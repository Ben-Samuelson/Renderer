#pragma once

#include "Shader.hpp"

#include <GL/glew.h>

class ShaderProgram
{
    private:
        constexpr static auto LOG_LENGTH = std::size_t(512);

        GLuint m_handle;

    public:
        ShaderProgram(Shader vertex, Shader fragment);
        ~ShaderProgram();

        GLuint handle() const;
        void use() const;
};
