cmake_minimum_required(VERSION 3.6)
project(MyDataStructures)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

set(SOURCE_FILES
        main.cpp
        MyList.cpp
        MyList.h
    )

add_executable(
        MyDataStructures
        ${SOURCE_FILES})
