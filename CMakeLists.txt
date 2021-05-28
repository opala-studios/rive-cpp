cmake_minimum_required(VERSION 3.12)

project(RIVE)

set(CMAKE_CXX_STANDARD 17)

set(RIVE_SOURCES)

file(GLOB_RECURSE RIVE_SOURCES src/*.cpp)

add_library(rive STATIC ${RIVE_SOURCES})
if (WIN32)
    target_compile_definitions(rive PUBLIC _USE_MATH_DEFINES)
endif ()
target_include_directories(rive PUBLIC include)