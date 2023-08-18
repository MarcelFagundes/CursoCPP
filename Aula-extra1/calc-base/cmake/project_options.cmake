include_guard()

add_library(
    project_options
        INTERFACE
)

target_compile_features(
    project_options
        INTERFACE
            cxx_std_20
)