add_library(107_solution Solution107.cc)

target_link_libraries(107_solution PUBLIC
        tools
        )

target_include_directories(107_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/107_Binary_Tree_Level_Order_Traversal_II"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(107_unit_test)
