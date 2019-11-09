cmake_minimum_required(VERSION 3.14)
project(CPProject)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Google_tests)
add_executable(CPProject main.cpp ContainerView.cpp ContainerView.h View.cpp View.h Page.cpp Page.h )
