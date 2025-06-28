cmake_minimum_required(VERSION 3.14)
project(CTestTests)

file(GLOB TASK_SOURCES "../tasks/*.cpp")

file(GLOB TEST_SOURCES "tests/*.cpp")

foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src} ${TASK_SOURCES})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()