cmake_minimum_required(VERSION 3.23)
project(AES)

set(CMAKE_CXX_STANDARD 14)

add_executable(AES main.cpp AES.cpp AES.h GF28MULT.h test.h)
