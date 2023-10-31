add_library(145_solution Solution145.cc)

target_link_libraries(145_solution PUBLIC
        tools
        )

target_include_directories(145_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/145_Binary_Tree_Postorder_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(145_unit_test)
