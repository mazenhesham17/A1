cmake_minimum_required(VERSION 3.21)
project(A1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Problem 2")

add_executable(A1
        "Problem 2/Fraction.cpp"
        "Problem 2/Fraction.h"
        "Problem 2/main.cpp")
