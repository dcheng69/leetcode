# add test for 889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal
add_executable(Test889
    Test889.cc
    )

target_link_libraries(Test889 PUBLIC
    GTest::gtest_main
    gmock_main
    889_solution
    tools
    )

target_include_directories(Test889 PUBLIC
     "${PROJECT_SOURCE_DIR}/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test889)

# add debug for 889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal
add_executable(Debug889
    Debug889.cc
    )

target_link_libraries(Debug889 PUBLIC
    889_solution
    tools
    )

target_include_directories(Debug889 PUBLIC
     "${PROJECT_SOURCE_DIR}/889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

