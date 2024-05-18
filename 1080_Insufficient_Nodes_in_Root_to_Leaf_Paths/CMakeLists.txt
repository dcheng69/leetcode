add_library(1080_solution Solution1080.cc)

target_link_libraries(1080_solution PUBLIC
        tools
        )

target_include_directories(1080_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/1080_Insufficient_Nodes_in_Root_to_Leaf_Paths"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(1080_unit_test)
