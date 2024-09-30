cmake_minimum_required(VERSION 3.29)
project(undo_stack)

set(CMAKE_CXX_STANDARD 20)

add_executable(undo_stack
        StringList.cpp
        StringListTest.cpp
        test.cpp
        test.h)
