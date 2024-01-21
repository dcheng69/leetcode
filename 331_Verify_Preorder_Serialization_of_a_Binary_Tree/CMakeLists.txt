add_library(331_solution Solution331.cc)

target_link_libraries(331_solution PUBLIC
        tools
        )

target_include_directories(331_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/331_Verify_Preorder_Serialization_of_a_Binary_Tree"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(331_unit_test)
