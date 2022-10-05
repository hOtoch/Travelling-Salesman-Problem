cmake_minimum_required(VERSION 3.19)
project(Travelling_Salesman_Problem C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Travelling_Salesman_Problem
        main.c
        node.c
        node.h
        MST.c
        MST.h)
