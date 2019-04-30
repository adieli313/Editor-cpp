cmake_minimum_required(VERSION 3.13)
project(Editor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Editor Editor.cpp Document.cpp main.cpp)
