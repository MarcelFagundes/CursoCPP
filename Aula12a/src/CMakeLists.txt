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

target_sources(
  vector_test
  PRIVATE
    vector_test.cpp
  )

  target_link_libraries(
    vector_test
    PRIVATE
      vector
  )

  add_executable(linked_test)

  target_sources(
    linked_test
    PRIVATE
      linked_list.cpp
      linked_list.hpp
      main.cpp
  )

  target_compile_features(
    linked_test
    PRIVATE
      cxx_std_20
  )