cmake_minimum_required(VERSION 3.8)
project(ArgumentParser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ArgumentParser.cpp
        ArgumentParser.h
        testcases.cpp catch.hpp catch_include.cpp)

add_executable(ArgumentParser ${SOURCE_FILES})