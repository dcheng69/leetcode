# add test for 144_Binary_Tree_Preorder_Traversal
add_executable(Test144
    Test144.cc
    )

target_link_libraries(Test144 PUBLIC
    GTest::gtest_main
    gmock_main
    144_solution
    tools
    )

target_include_directories(Test144 PUBLIC
     "${PROJECT_SOURCE_DIR}/144_Binary_Tree_Preorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test144)

# add debug for 144_Binary_Tree_Preorder_Traversal
add_executable(Debug144
    Debug144.cc
    )

target_link_libraries(Debug144 PUBLIC
    144_solution
    tools
    )

target_include_directories(Debug144 PUBLIC
     "${PROJECT_SOURCE_DIR}/144_Binary_Tree_Preorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

