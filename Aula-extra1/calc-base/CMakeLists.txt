#cmake_minimum_required(VERSION 3.25)
cmake_minimum_required(VERSION 3.15)

project(calc CXX)

include(cmake/conan.cmake)
include(cmake/project_options.cmake)




# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()


conan_cmake_run(REQUIRES Catch2/2.6.0@catchorg/stable
                BASIC_SETUP CMAKE_TARGETS)

add_subdirectory(src)