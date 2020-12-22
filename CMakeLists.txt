cmake_minimum_required(VERSION 3.16)
project(bst C)

set(CMAKE_C_STANDARD 11)

add_executable(bst main.c bst.c bst.h)