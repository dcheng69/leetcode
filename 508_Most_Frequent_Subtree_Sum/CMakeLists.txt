add_library(508_solution Solution508.cc)

target_link_libraries(508_solution PUBLIC
        tools
        )

target_include_directories(508_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/508_Most_Frequent_Subtree_Sum"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(508_unit_test)
