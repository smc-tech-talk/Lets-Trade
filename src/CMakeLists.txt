cmake_minimum_required(VERSION 3.19.2)
project(lets-trade-test)

#add_subdirectory(<MORE FOLDERS>)
set(SOURCE_FILES main.cpp)

add_executable(lets-trade ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")