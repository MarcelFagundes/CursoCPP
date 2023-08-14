cmake_minimum_required(VERSION 3.15)
project(school CXX)

add_library(school)

target_sources(
school
  PUBLIC
	functions.hpp
	student.hpp

  PRIVATE
	functions.cpp
	student.cpp
)
target_include_directories(
	school
  PUBLIC
    	$(CMAKE_CURRENT_SOURCE_DIR)
)
