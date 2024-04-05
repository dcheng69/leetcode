add_library(863_solution Solution863.cc)

target_link_libraries(863_solution PUBLIC
        tools
        )

target_include_directories(863_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/863_All_Nodes_Distance_K_in_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(863_unit_test)
