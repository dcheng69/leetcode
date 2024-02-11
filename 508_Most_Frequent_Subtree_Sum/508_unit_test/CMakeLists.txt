# add test for 508_Most_Frequent_Subtree_Sum
add_executable(Test508
    Test508.cc
    )

target_link_libraries(Test508 PUBLIC
    GTest::gtest_main
    gmock_main
    508_solution
    tools
    )

target_include_directories(Test508 PUBLIC
     "${PROJECT_SOURCE_DIR}/508_Most_Frequent_Subtree_Sum"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test508)

# add debug for 508_Most_Frequent_Subtree_Sum
add_executable(Debug508
    Debug508.cc
    )

target_link_libraries(Debug508 PUBLIC
    508_solution
    tools
    )

target_include_directories(Debug508 PUBLIC
     "${PROJECT_SOURCE_DIR}/508_Most_Frequent_Subtree_Sum"
     "${PROJECT_SOURCE_DIR}/tools"
    )

