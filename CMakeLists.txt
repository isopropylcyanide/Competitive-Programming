# This file is only required for CMake. You can run the programs as is on the command line
cmake_minimum_required(VERSION 3.19)
project(Competitive_Programming)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(code-c)
include_directories(code-cpp)

# To rebuild cmake-build-debug : Root -> Reload CMake project
# C++ Single file execution: https://plugins.jetbrains.com/plugin/8352-c-c--single-file-execution
add_executable(deepestLeavesLCA code-cpp/deepestLeavesLCA.cpp)
add_executable(waiterStack code-cpp/waiterStack.cpp)