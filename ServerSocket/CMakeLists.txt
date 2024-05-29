cmake_minimum_required(VERSION 3.28)
project(ServerSocket)

set(CMAKE_CXX_STANDARD 17)

add_executable(ServerSocket main.cpp)
target_link_libraries(ServerSocket ws2_32)
