cmake_minimum_required(VERSION 3.12)
project(ROSPO)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Eigen3 REQUIRED)

include_directories(/usr/include/eigen3)
include_directories($ENV{HOME}/programs/roboptim/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(rospo main.cpp)
target_compile_options(rospo PRIVATE -Wall)
add_subdirectory(src)
