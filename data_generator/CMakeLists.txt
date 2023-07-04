cmake_minimum_required(VERSION 3.10)
project(ROSPO)
set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3 REQUIRED)

include_directories(/usr/include/eigen3)
include_directories($ENV{HOME}/programs/roboptim/include)


add_executable(rospo main.cpp)
