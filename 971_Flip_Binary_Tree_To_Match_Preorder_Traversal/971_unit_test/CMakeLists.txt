# add test for 971_Flip_Binary_Tree_To_Match_Preorder_Traversal
add_executable(Test971
    Test971.cc
    )

target_link_libraries(Test971 PUBLIC
    GTest::gtest_main
    gmock_main
    971_solution
    tools
    )

target_include_directories(Test971 PUBLIC
     "${PROJECT_SOURCE_DIR}/971_Flip_Binary_Tree_To_Match_Preorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test971)

# add debug for 971_Flip_Binary_Tree_To_Match_Preorder_Traversal
add_executable(Debug971
    Debug971.cc
    )

target_link_libraries(Debug971 PUBLIC
    971_solution
    tools
    )

target_include_directories(Debug971 PUBLIC
     "${PROJECT_SOURCE_DIR}/971_Flip_Binary_Tree_To_Match_Preorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

