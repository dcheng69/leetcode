# add test for 655_Print_Binary_Tree
add_executable(Test655
    Test655.cc
    )

target_link_libraries(Test655 PUBLIC
    GTest::gtest_main
    gmock_main
    655_solution
    tools
    )

target_include_directories(Test655 PUBLIC
     "${PROJECT_SOURCE_DIR}/655_Print_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test655)

# add debug for 655_Print_Binary_Tree
add_executable(Debug655
    Debug655.cc
    )

target_link_libraries(Debug655 PUBLIC
    655_solution
    tools
    )

target_include_directories(Debug655 PUBLIC
     "${PROJECT_SOURCE_DIR}/655_Print_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

