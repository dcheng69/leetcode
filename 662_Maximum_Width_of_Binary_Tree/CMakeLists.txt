add_library(662_solution Solution662.cc)

target_link_libraries(662_solution PUBLIC
        tools
        )

target_include_directories(662_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/662_Maximum_Width_of_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(662_unit_test)
