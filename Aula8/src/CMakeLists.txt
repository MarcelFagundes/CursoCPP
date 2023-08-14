cmake_minimum_required(VERSION 3.15)
project(fixed_length_vector CXX)

add_executable(fixed_length_vector)

target_sources(
    fixed_length_vector
    PRIVATE
        fixed_length_vector.hpp
        fixed_length_vector.cpp
        main.cpp
)

target_compile_features(
  fixed_length_vector
  PRIVATE
      cxx_std_17
  )
