cmake_minimum_required(VERSION 3.17)
project(Constant_Malloc)

set(CMAKE_CXX_STANDARD 14)

add_executable(Constant_Malloc SimpleMemoryAllocator.cpp ConcurrentMemoryAllocator.cpp main.cpp)

find_package(Boost COMPONENTS thread system REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(Constant_Malloc ${Boost_LIBRARIES})