add_library(109_solution Solution109.cc)

target_link_libraries(109_solution PUBLIC
        tools
        )

target_include_directories(109_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/109_Convert_Sorted_List_to_Binary_Search_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(109_unit_test)
