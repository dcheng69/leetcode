add_library(105_solution Solution105.cc)

target_link_libraries(105_solution PUBLIC
        tools
        )

target_include_directories(105_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(105_unit_test)
