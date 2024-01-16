add_library(116_solution Solution116.cc)

target_link_libraries(116_solution PUBLIC
        tools
        )

target_include_directories(116_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/116_Populating_Next_Right_Pointers_in_Each_Node"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(116_unit_test)
