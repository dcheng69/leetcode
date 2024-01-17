add_library(117_solution Solution117.cc)

target_link_libraries(117_solution PUBLIC
        tools
        )

target_include_directories(117_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/117_Populating_Next_Right_Pointers_in_Each_Node_II"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(117_unit_test)
