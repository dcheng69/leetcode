add_library(236_solution Solution236.cc)

target_link_libraries(236_solution PUBLIC
        tools
        )

target_include_directories(236_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/236_Lowest_Common_Ancestor_of_a_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(236_unit_test)
