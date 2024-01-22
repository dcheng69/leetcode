add_library(230_solution Solution230.cc)

target_link_libraries(230_solution PUBLIC
        tools
        )

target_include_directories(230_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/230_Kth_Smallest_Element_in_a_BST"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(230_unit_test)
