cmake_minimum_required(VERSION 3.15)
project(exercise3 CXX)

add_subdirectory(school)

add_executable(exercise3)

target_sources(
	exercise3
  PRIVATE
  	main.cpp
)
 
target_link_libraries(
  	exercise3
  PRIVATE
  	school
)
