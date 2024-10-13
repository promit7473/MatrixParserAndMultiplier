cmake_minimum_required(VERSION 3.29)
project(matrix_multiplier)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        matrix_multiplier
        main.cpp
        cmake-build-debug/input1.txt
        cmake-build-debug/input2.txt
        cmake-build-debug/matrixoutput.txt
)
