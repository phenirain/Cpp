cmake_minimum_required(VERSION 3.28)
project(ClientSocket)

set(CMAKE_CXX_STANDARD 17)

add_executable(ClientSocket main.cpp)
target_link_libraries(ClientSocket ws2_32)