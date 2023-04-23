cmake_minimum_required(VERSION 3.22)
project(ejercicio_13 C)

set(CMAKE_C_STANDARD 23)

add_executable(ejercicio_13 main.c "librerias/listas.c" "librerias/pilas.c")
