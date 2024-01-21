add_library(235_solution Solution235.cc)

target_link_libraries(235_solution PUBLIC
        tools
        )

target_include_directories(235_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(235_unit_test)
