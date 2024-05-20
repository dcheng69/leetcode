add_library(971_solution Solution971.cc)

target_link_libraries(971_solution PUBLIC
        tools
        )

target_include_directories(971_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/971_Flip_Binary_Tree_To_Match_Preorder_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(971_unit_test)
