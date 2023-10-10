add_library(144_solution Solution144.cc)

target_link_libraries(144_solution PUBLIC
        tools
        )

target_include_directories(144_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/144_Binary_Tree_Preorder_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(144_unit_test)
