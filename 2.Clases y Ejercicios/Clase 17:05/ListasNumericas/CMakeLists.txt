cmake_minimum_required(VERSION 3.22)
project(ListasNumericas C)

set(CMAKE_C_STANDARD 23)

add_executable(ListasNumericas main.c ../librerias/listas.c  ../librerias/pilas.h ../librerias/pilas.c)
