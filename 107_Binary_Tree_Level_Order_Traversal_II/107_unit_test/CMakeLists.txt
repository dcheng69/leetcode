# add test for 107_Binary_Tree_Level_Order_Traversal_II
add_executable(Test107
    Test107.cc
    )

target_link_libraries(Test107 PUBLIC
    GTest::gtest_main
    gmock_main
    107_solution
    tools
    )

target_include_directories(Test107 PUBLIC
     "${PROJECT_SOURCE_DIR}/107_Binary_Tree_Level_Order_Traversal_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test107)

# add debug for 107_Binary_Tree_Level_Order_Traversal_II
add_executable(Debug107
    Debug107.cc
    )

target_link_libraries(Debug107 PUBLIC
    107_solution
    tools
    )

target_include_directories(Debug107 PUBLIC
     "${PROJECT_SOURCE_DIR}/107_Binary_Tree_Level_Order_Traversal_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

