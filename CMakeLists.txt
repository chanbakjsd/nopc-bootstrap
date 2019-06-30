cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(nopc)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(nopc src/main.cpp)