cmake_minimum_required(VERSION 3.19)
project(bloom_filter_exec C)

set(CMAKE_C_STANDARD 11)

add_executable(bloom_filter_exec main.c bloom_filter.h bloom_filter.c test.c test.h)