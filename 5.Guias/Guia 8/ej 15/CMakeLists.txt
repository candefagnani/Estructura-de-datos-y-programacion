cmake_minimum_required(VERSION 3.22)
project(ej_15 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ej_15
        ej15.c
        listas.c
        listas.h)
