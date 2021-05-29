# This file is only required for CMake. You can run the programs as is on the command line
cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Competitive_Programming)

include_directories(.)
include_directories(code-c)
include_directories(code-cpp)

# To rebuild cmake-build-debug : Root -> Reload CMake project
# C++ Single file execution: https://plugins.jetbrains.com/plugin/8352-c-c--single-file-execution
add_executable(deepestLeavesLCA code-cpp/deepestLeavesLCA.cpp)
add_executable(waiterStack code-cpp/waiterStack.cpp)
add_executable(crackingSafe code-cpp/crackingSafe.cpp)