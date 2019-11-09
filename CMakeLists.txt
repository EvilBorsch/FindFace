cmake_minimum_required(VERSION 3.15)
project(backend)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)

add_executable(backend main.cpp)
