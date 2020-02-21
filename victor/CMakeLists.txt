cmake_minimum_required(VERSION 3.15)
project(victor)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(victor
        main.cpp
        vec2.cpp
        vec2.h)
