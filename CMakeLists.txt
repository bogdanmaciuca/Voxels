cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Voxels VERSION 1.0 LANGUAGES CXX C)

file(GLOB SRCS src/*.cpp)

add_executable(Voxels ${SRCS})

set(GLW_BUILD_EXAMPLES OFF CACHE BOOL "Disable submodule examples")
add_subdirectory(extern/glw)

target_link_libraries(Voxels PRIVATE glw)

