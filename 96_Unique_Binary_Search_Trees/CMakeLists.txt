add_library(96_solution Solution96.cc)

target_link_libraries(96_solution PUBLIC
        tools
        )

target_include_directories(96_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/96_Unique_Binary_Search_Trees"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(96_unit_test)
