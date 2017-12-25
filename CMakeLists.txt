cmake_minimum_required(VERSION 2.8)

project(codelet)

include_directories($ENV{gtest_SOURCE_DIR}/include $ENV{gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -fno-elide-constructors")

set(SOURCE_FILES gof/Adapter.cpp gof/gtest_main.cpp cpp_skills/MoveSemantics.cpp cpp_skills/ReturnTuple.cpp gof/NullObject.cpp cpp_skills/ReturnObject.cpp cpp_skills/TemplateMethod.cpp)

link_directories($ENV{gtest_SOURCE_DIR})

add_executable(codelet ${SOURCE_FILES})

target_link_libraries(codelet gtest gtest_main)