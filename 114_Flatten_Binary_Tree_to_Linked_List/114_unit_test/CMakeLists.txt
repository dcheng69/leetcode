# add test for 114_Flatten_Binary_Tree_to_Linked_List
add_executable(Test114
    Test114.cc
    )

target_link_libraries(Test114 PUBLIC
    GTest::gtest_main
    gmock_main
    114_solution
    tools
    )

target_include_directories(Test114 PUBLIC
     "${PROJECT_SOURCE_DIR}/114_Flatten_Binary_Tree_to_Linked_List"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test114)

# add debug for 114_Flatten_Binary_Tree_to_Linked_List
add_executable(Debug114
    Debug114.cc
    )

target_link_libraries(Debug114 PUBLIC
    114_solution
    tools
    )

target_include_directories(Debug114 PUBLIC
     "${PROJECT_SOURCE_DIR}/114_Flatten_Binary_Tree_to_Linked_List"
     "${PROJECT_SOURCE_DIR}/tools"
    )

