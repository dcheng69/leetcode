# add test for 105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
add_executable(Test105
    Test105.cc
    )

target_link_libraries(Test105 PUBLIC
    GTest::gtest_main
    gmock_main
    105_solution
    tools
    )

target_include_directories(Test105 PUBLIC
     "${PROJECT_SOURCE_DIR}/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test105)

# add debug for 105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
add_executable(Debug105
    Debug105.cc
    )

target_link_libraries(Debug105 PUBLIC
    105_solution
    tools
    )

target_include_directories(Debug105 PUBLIC
     "${PROJECT_SOURCE_DIR}/105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

