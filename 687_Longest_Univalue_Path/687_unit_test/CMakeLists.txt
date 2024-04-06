# add test for 687_Longest_Univalue_Path
add_executable(Test687
    Test687.cc
    )

target_link_libraries(Test687 PUBLIC
    GTest::gtest_main
    gmock_main
    687_solution
    tools
    )

target_include_directories(Test687 PUBLIC
     "${PROJECT_SOURCE_DIR}/687_Longest_Univalue_Path"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test687)

# add debug for 687_Longest_Univalue_Path
add_executable(Debug687
    Debug687.cc
    )

target_link_libraries(Debug687 PUBLIC
    687_solution
    tools
    )

target_include_directories(Debug687 PUBLIC
     "${PROJECT_SOURCE_DIR}/687_Longest_Univalue_Path"
     "${PROJECT_SOURCE_DIR}/tools"
    )

