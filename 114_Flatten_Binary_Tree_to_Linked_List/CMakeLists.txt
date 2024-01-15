add_library(114_solution Solution114.cc)

target_link_libraries(114_solution PUBLIC
        tools
        )

target_include_directories(114_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/114_Flatten_Binary_Tree_to_Linked_List"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(114_unit_test)
