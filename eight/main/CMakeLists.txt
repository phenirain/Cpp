cmake_minimum_required(VERSION 3.28)
project(main)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        ../lib/library.cpp)
