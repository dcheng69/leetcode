add_library(129_solution Solution129.cc)

target_link_libraries(129_solution PUBLIC
        tools
        )

target_include_directories(129_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/129_Sum_Root_to_Leaf_Numbers"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(129_unit_test)
