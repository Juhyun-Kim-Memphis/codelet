cmake_minimum_required(VERSION 2.8)

project(codelet)

include_directories($ENV{gtest_SOURCE_DIR}/include $ENV{gtest_SOURCE_DIR})
include_directories($ENV{BOOST_HOME})
include_directories(cpp_skills/TemplateMetaProgramming)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES gof/Adapter.cpp gof/gtest_main.cpp cpp_skills/MoveSemantics.cpp cpp_skills/ReturnTuple.cpp gof/NullObject.cpp cpp_skills/ReturnObject.cpp cpp_skills/TemplateMethod.cpp cpp_skills/Decltype.cpp cpp_skills/Thread.cpp kata/MovieRental/Movie.cpp kata/MovieRental/tests.cpp kata/MovieRental/Movie.hpp kata/MovieRental/Customer.cpp kata/MovieRental/Customer.hpp kata/MovieRental/Rental.cpp kata/MovieRental/Rental.hpp cpp_skills/CheckMethodExist.cpp cpp_skills/TemplateMetaProgramming/switch.cpp cpp_skills/TemplateMetaProgramming/switch.hpp cpp_skills/TemplateMetaProgramming/switch_impl.hpp cpp_skills/constexpr.cpp cpp_skills/SmartPointer.cpp cpp_skills/ClassTemplate.cpp)

link_directories($ENV{gtest_SOURCE_DIR})
link_directories($ENV{BOOST_HOME}/build/lib)

add_executable(codelet ${SOURCE_FILES})

target_link_libraries(codelet gtest gtest_main)