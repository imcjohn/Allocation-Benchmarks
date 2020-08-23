cmake_minimum_required(VERSION 3.17)
project(Constant_Malloc)

set(CMAKE_CXX_STANDARD 14)

add_executable(Constant_Malloc SimpleMemoryAllocator.cpp main.cpp)