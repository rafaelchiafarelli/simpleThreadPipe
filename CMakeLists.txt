cmake_minimum_required(VERSION 2.8.9)
project (th_com)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
add_executable(th_com main.cpp)