# add test for 106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal
add_executable(Test106
    Test106.cc
    )

target_link_libraries(Test106 PUBLIC
    GTest::gtest_main
    gmock_main
    106_solution
    tools
    )

target_include_directories(Test106 PUBLIC
     "${PROJECT_SOURCE_DIR}/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test106)

# add debug for 106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal
add_executable(Debug106
    Debug106.cc
    )

target_link_libraries(Debug106 PUBLIC
    106_solution
    tools
    )

target_include_directories(Debug106 PUBLIC
     "${PROJECT_SOURCE_DIR}/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

