cmake_minimum_required(VERSION 3.15)
project(exercise3 CXX)

option(WARNINGS_AS_ERRORS "Treat compiler warning as errors." ON)

add_library(
	project_options
	INTERFACE
)

target_compile_features(
	project_options
	PRIVATE
		cxx_std_17
)

target_compile_options(
	project_options
	PRIVATE
		-Wall
		-Wextra
		-Wpedantic
		-Wmisleading-indentation
)

if(WARNINGS_AS_ERRORS)
    target_compile_options(
	project_options
	PRIVATE
		-Werror
)

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
  		project_options
  		school
)
endif()
