cmake_minimum_required(VERSION 3.5)
project(Graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lGLU -lglut")

#head file path
INCLUDE_DIRECTORIES(include)

#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(main ${DIR_SRCS} test/main.cpp)

add_executable(star ${DIR_SRCS} test/main_star.cpp)
add_executable(qube src/qube.cpp src/primitive.cpp test/main_qube.cpp)
add_executable(teapot ${DIR_SRCS} test/main_teapot.cpp)

add_executable(hello test/hello.cpp)
add_executable(double test/double.cpp)
add_executable(light test/light.cpp)
add_executable(perspective test/perspective.cpp)
