cmake_minimum_required(VERSION 3.5)
project(Graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lGLU -lglut")

#head file path
INCLUDE_DIRECTORIES(include)

#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(star ${DIR_SRCS})

add_executable(hello test/hello.cpp)
add_executable(double test/double.cpp)
