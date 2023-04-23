cmake_minimum_required(VERSION 3.22)
project(ejercicio_12 C)

set(CMAKE_C_STANDARD 23)

add_executable(ejercicio_12 main.c "librerias/pilas.c" "librerias/listas.c")
