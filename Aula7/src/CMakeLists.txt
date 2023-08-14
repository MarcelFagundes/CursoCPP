cmake_minimum_required(VERSION 3.15)
project(linked_list CXX)

add_executable(linked_list)

target_sources(
    linked_list
    PRIVATE
        linked_list.hpp
        linked_list.cpp
        main.cpp
)
