# add test for 145_Binary_Tree_Postorder_Traversal
add_executable(Test145
    Test145.cc
    )

target_link_libraries(Test145 PUBLIC
    GTest::gtest_main
    gmock_main
    145_solution
    tools
    )

target_include_directories(Test145 PUBLIC
     "${PROJECT_SOURCE_DIR}/145_Binary_Tree_Postorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test145)

# add debug for 145_Binary_Tree_Postorder_Traversal
add_executable(Debug145
    Debug145.cc
    )

target_link_libraries(Debug145 PUBLIC
    145_solution
    tools
    )

target_include_directories(Debug145 PUBLIC
     "${PROJECT_SOURCE_DIR}/145_Binary_Tree_Postorder_Traversal"
     "${PROJECT_SOURCE_DIR}/tools"
    )

