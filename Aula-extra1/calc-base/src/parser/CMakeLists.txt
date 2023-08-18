add_library(parser)

target_sources(parser
    PUBLIC
        parser.hpp
    PRIVATE
        parser.cpp
)

target_link_libraries(
    parser
    PUBLIC
        project_options
        operations
)

target_include_directories(parser
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)