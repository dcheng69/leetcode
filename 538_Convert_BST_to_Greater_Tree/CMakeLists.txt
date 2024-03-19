add_library(538_solution Solution538.cc)

target_link_libraries(538_solution PUBLIC
        tools
        )

target_include_directories(538_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/538_Convert_BST_to_Greater_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(538_unit_test)
