add_library(606_solution Solution606.cc)

target_link_libraries(606_solution PUBLIC
        tools
        )

target_include_directories(606_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/606_Construct_String_from_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(606_unit_test)
