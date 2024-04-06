add_library(687_solution Solution687.cc)

target_link_libraries(687_solution PUBLIC
        tools
        )

target_include_directories(687_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/687_Longest_Univalue_Path"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(687_unit_test)
