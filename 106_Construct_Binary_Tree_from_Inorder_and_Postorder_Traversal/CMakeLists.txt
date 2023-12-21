add_library(106_solution Solution106.cc)

target_link_libraries(106_solution PUBLIC
        tools
        )

target_include_directories(106_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(106_unit_test)
