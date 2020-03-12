cmake_minimum_required(VERSION 3.15)
project(forcelines)

set(CMAKE_CXX_STANDARD 14)

add_executable(forcelines main.cpp vec2.cpp)
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

target_link_libraries(forcelines
        PUBLIC
        sfml-graphics sfml-audio sfml-window sfml-system )