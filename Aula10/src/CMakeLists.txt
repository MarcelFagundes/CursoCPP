cmake_minimum_required(VERSION 3.15)

project(vector CXX)

  add_library(vector)

add_executable(vector_test)

target_sources(
  vector
  PUBLIC
    vector.hpp
  PRIVATE
    vector.cpp        
)

target_compile_features(
  vector
  PUBLIC
      cxx_std_20
  )

target_sources(
  vector_test
  PRIVATE
    vector_test.cpp
  )

