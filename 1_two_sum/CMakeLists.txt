add_library(1_solution
    Solution1.cc
    )

target_link_libraries(1_solution PUBLIC
    tools
    )

target_include_directories(1_solution PUBLIC
    "${PROJECT_SOURCE_DIR}/1_two_sum"
    "${PROJECT_SOURCE_DIR}/tools"
    )

add_subdirectory(1_unit_test)
