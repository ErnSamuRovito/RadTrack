cmake_minimum_required(VERSION 3.28.3)

project(RadTrack)

set(CMAKE_CXX_STANDARD 23)

# Find the required libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
include_directories(glad/include)

# Automatically add all .cpp and .h files in the src directory
file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp" "src/*.h")

# Add executable with all source files
add_executable(RadTrack ${SOURCES})

# Link libraries
target_link_libraries(RadTrack 
    OpenGL::GL 
    glfw
)
