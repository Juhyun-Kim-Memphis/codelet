cmake_minimum_required(VERSION 3.8)
project(network)

set(CMAKE_CXX_STANDARD 11)

set(CLIENT_SOURCE_FILES client.cpp util.hpp)
set(SERVER_SOURCE_FILES server.cpp util.hpp)

add_executable(server ${SERVER_SOURCE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES})

