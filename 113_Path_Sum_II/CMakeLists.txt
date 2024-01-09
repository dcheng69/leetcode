add_library(113_solution Solution113.cc)

target_link_libraries(113_solution PUBLIC
        tools
        )

target_include_directories(113_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/113_Path_Sum_II"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(113_unit_test)
