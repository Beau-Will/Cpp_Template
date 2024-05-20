cmake_minimum_required(VERSION 3.28)
project(Cpp_Template)

set(CMAKE_CXX_STANDARD 26)

add_executable(Cpp_Template main.cpp
        common_math.h
        data_structure.h
        advanced_math.h
        big_integer.h)
