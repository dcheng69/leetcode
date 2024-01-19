add_library(199_solution Solution199.cc)

target_link_libraries(199_solution PUBLIC
        tools
        )

target_include_directories(199_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/199_Binary_Tree_Right_Side_View"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(199_unit_test)
