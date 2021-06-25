cmake_minimum_required(VERSION 3.19)
project(lsoftcons)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp msoftcon.cpp)

add_library(msoftcon ${SOURCE_FILES})