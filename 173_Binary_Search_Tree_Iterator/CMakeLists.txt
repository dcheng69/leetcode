add_library(173_solution Solution173.cc)

target_link_libraries(173_solution PUBLIC
        tools
        )

target_include_directories(173_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/173_Binary_Search_Tree_Iterator"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(173_unit_test)
