cmake_minimum_required(VERSION 3.14)
project(GTestTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(COMMON_SRCS
    tests.cpp
    ../tasks/task_3.cpp
    ../tasks/task_4.cpp
    ../tasks/task_5.cpp
    ../tasks/task_6.cpp
    ../tasks/task_7.cpp
    ../tasks/task_8.cpp
)

add_executable(tests ${COMMON_SRCS})
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(tests PUBLIC gtest gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND tests)