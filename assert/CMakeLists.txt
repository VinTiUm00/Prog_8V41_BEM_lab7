cmake_minimum_required(VERSION 3.10)
project(AssertTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    "../headers"
    ${CMAKE_SOURCE_DIR}
)

file(GLOB TASK_SOURCES "../tasks/*.cpp")

add_executable(AssertTests 
    main.cpp 
    ${TASK_SOURCES}
)

if(WIN32)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()