cmake_minimum_required(VERSION 3.19)
project(bloom_filter_exec C)

set(CMAKE_C_STANDARD 11)

add_executable(bloom_filter_exec main.c bloom_filter/bloom_filter.h bloom_filter/bloom_filter.c test/test.c test/test.h)