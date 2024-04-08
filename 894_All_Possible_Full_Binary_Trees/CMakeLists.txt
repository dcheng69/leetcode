add_library(894_solution Solution894.cc)

target_link_libraries(894_solution PUBLIC
        tools
        )

target_include_directories(894_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/894_All_Possible_Full_Binary_Trees"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(894_unit_test)
