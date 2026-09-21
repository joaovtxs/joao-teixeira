cmake_minimum_required(VERSION 4.3)
project(C_TEST C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_TEST
        hmi.c
        hmi.h
        main.c
        op.c
        op.h)
