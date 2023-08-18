add_executable(test_operations)

target_sources(test_operations
    PUBLIC
        main.cpp
)

target_link_libraries(test_operations
    PRIVATE
        project_options
        operations
        CONAN_PKG::catch2
)

add_test(NAME test_operations COMMAND test_operations)