cmake_minimum_required(VERSION 3.15)

project(Renderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file (GLOB SOURCE "source/*.cpp")

add_executable(Renderer ${SOURCE})
target_include_directories(Renderer PRIVATE include)
target_link_libraries(Renderer PRIVATE
    glfw
    GLEW
    GL)
