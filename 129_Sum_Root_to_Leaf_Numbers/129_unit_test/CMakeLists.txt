# add test for 129_Sum_Root_to_Leaf_Numbers
add_executable(Test129
    Test129.cc
    )

target_link_libraries(Test129 PUBLIC
    GTest::gtest_main
    gmock_main
    129_solution
    tools
    )

target_include_directories(Test129 PUBLIC
     "${PROJECT_SOURCE_DIR}/129_Sum_Root_to_Leaf_Numbers"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test129)

# add debug for 129_Sum_Root_to_Leaf_Numbers
add_executable(Debug129
    Debug129.cc
    )

target_link_libraries(Debug129 PUBLIC
    129_solution
    tools
    )

target_include_directories(Debug129 PUBLIC
     "${PROJECT_SOURCE_DIR}/129_Sum_Root_to_Leaf_Numbers"
     "${PROJECT_SOURCE_DIR}/tools"
    )

