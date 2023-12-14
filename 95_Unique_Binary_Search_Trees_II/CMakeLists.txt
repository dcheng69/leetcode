add_library(95_solution Solution95.cc)

target_link_libraries(95_solution PUBLIC
        tools
        )

target_include_directories(95_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/95_Unique_Binary_Search_Trees_II"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(95_unit_test)
