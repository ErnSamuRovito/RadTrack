cmake_minimum_required(VERSION 3.28.3)

project(RadTrack)

set(CMAKE_CXX_STANDARD 11)

# Find the required libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

#include_directories(glad/include)
add_executable(RadTrack src/main.cpp src/glad.h src/glad.c)

target_link_libraries(main OpenGL::GL glfw)
