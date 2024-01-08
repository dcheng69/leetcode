add_library(112_solution Solution112.cc)

target_link_libraries(112_solution PUBLIC
        tools
        )

target_include_directories(112_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/112_Path_Sum"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(112_unit_test)
