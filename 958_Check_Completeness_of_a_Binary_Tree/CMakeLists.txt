add_library(958_solution Solution958.cc)

target_link_libraries(958_solution PUBLIC
        tools
        )

target_include_directories(958_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/958_Check_Completeness_of_a_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(958_unit_test)
