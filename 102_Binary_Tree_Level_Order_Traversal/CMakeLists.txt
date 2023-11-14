add_library(102_solution Solution102.cc)

target_link_libraries(102_solution PUBLIC
        tools
        )

target_include_directories(102_solution PUBLIC
        "${PROJECT_SOURCE_DIR}/102_Binary_Tree_Level_Order_Traversal"
        "${PROJECT_SOURCE_DIR}/tools"
        )

add_subdirectory(102_unit_test)
