# add test for 331_Verify_Preorder_Serialization_of_a_Binary_Tree
add_executable(Test331
    Test331.cc
    )

target_link_libraries(Test331 PUBLIC
    GTest::gtest_main
    gmock_main
    331_solution
    tools
    )

target_include_directories(Test331 PUBLIC
     "${PROJECT_SOURCE_DIR}/331_Verify_Preorder_Serialization_of_a_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test331)

# add debug for 331_Verify_Preorder_Serialization_of_a_Binary_Tree
add_executable(Debug331
    Debug331.cc
    )

target_link_libraries(Debug331 PUBLIC
    331_solution
    tools
    )

target_include_directories(Debug331 PUBLIC
     "${PROJECT_SOURCE_DIR}/331_Verify_Preorder_Serialization_of_a_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

