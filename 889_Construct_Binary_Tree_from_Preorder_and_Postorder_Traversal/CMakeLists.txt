add_library(889_solution Solution889.cc)

target_link_libraries(889_solution PUBLIC
        tools
        )

target_include_directories(889_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(889_unit_test)
