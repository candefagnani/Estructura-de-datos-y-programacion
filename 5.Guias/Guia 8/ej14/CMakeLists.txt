cmake_minimum_required(VERSION 3.22)
project(ej14 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ej14
        colas.c
        colas.h
        ej14.c)
