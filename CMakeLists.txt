cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 14)

OPTION(DEFINE_DEBUG
        "Build the project using debugging code"
        OFF)
IF (DEFINE_DEBUG)
    MESSAGE("Adding Debug flag...")
    ADD_DEFINITIONS(-DDEBUG)
    SET(CMAKE_BUILD_TYPE Debug)
    MESSAGE("Build type is " ${CMAKE_BUILD_TYPE})
ENDIF (DEFINE_DEBUG)

add_executable(task_1 task_1.cpp)
add_executable(task_4 task_4.cpp)
