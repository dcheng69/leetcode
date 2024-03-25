add_library(655_solution Solution655.cc)

target_link_libraries(655_solution PUBLIC
        tools
        )

target_include_directories(655_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/655_Print_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(655_unit_test)
