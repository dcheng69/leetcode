# add test for 538_Convert_BST_to_Greater_Tree
add_executable(Test538
    Test538.cc
    )

target_link_libraries(Test538 PUBLIC
    GTest::gtest_main
    gmock_main
    538_solution
    tools
    )

target_include_directories(Test538 PUBLIC
     "${PROJECT_SOURCE_DIR}/538_Convert_BST_to_Greater_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test538)

# add debug for 538_Convert_BST_to_Greater_Tree
add_executable(Debug538
    Debug538.cc
    )

target_link_libraries(Debug538 PUBLIC
    538_solution
    tools
    )

target_include_directories(Debug538 PUBLIC
     "${PROJECT_SOURCE_DIR}/538_Convert_BST_to_Greater_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

