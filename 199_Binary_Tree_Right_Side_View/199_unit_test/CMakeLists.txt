# add test for 199_Binary_Tree_Right_Side_View
add_executable(Test199
    Test199.cc
    )

target_link_libraries(Test199 PUBLIC
    GTest::gtest_main
    gmock_main
    199_solution
    tools
    )

target_include_directories(Test199 PUBLIC
     "${PROJECT_SOURCE_DIR}/199_Binary_Tree_Right_Side_View"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test199)

# add debug for 199_Binary_Tree_Right_Side_View
add_executable(Debug199
    Debug199.cc
    )

target_link_libraries(Debug199 PUBLIC
    199_solution
    tools
    )

target_include_directories(Debug199 PUBLIC
     "${PROJECT_SOURCE_DIR}/199_Binary_Tree_Right_Side_View"
     "${PROJECT_SOURCE_DIR}/tools"
    )

