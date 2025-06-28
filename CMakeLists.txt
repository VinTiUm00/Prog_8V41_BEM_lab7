cmake_minimum_required(VERSION 3.10.0)
project(lab7 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

include(CTest)
enable_testing()

add_subdirectory(assert)
add_subdirectory(ctest)
add_subdirectory(gtest)

add_executable(lab7 main.cpp)
