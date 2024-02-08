add_library(450_solution Solution450.cc)

target_link_libraries(450_solution PUBLIC
        tools
        )

target_include_directories(450_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/450_Delete_Node_in_a_BST"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(450_unit_test)
