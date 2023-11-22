# add test for 102_Binary_Tree_Level_Order_Traversal
add_executable(Test102
    Test102.cc
    )

target_link_libraries(Test102 PUBLIC
    GTest::gtest_main
    gmock_main
    102_solution
    tools
    )

target_include_directories(Test102 PUBLIC
     "${PROJECT_SOURCE_DIR}/102_Binary_Tree_Level_Order_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test102)

# add debug for 102_Binary_Tree_Level_Order_Traversal
add_executable(Debug102
    Debug102.cc
    )

target_link_libraries(Debug102 PUBLIC
    102_solution
    tools
    )

target_include_directories(Debug102 PUBLIC
     "${PROJECT_SOURCE_DIR}/102_Binary_Tree_Level_Order_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

