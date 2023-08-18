add_library(operations)

target_sources(operations
    PUBLIC
        expression.hpp
        operations.hpp
    PRIVATE
        expression.cpp
        operations.cpp
)

target_link_libraries(operations
    PRIVATE
        project_options
)

target_include_directories(operations
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(tests)