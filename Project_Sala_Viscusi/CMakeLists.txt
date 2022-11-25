cmake_minimum_required(VERSION 3.23)
project(Project_Sala_Viscusi)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project_Sala_Viscusi main.cpp fparser.cc fpoptimizer.cc)
include_directories(fparser4.5.2)