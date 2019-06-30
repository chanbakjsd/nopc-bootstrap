cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(nopc)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# clang is the only good compiler :)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

# general output dirs
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${LLVM_INCLUDE_DIRS}
		${PROJECT_SRC_DIR}/src)

add_definitions(${LLVM_DEFINITIONS})

add_executable(nopc src/main.cpp)

llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(nopc ${llvm_libs})
