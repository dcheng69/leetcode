# add test for 113_Path_Sum_II
add_executable(Test113
    Test113.cc
    )

target_link_libraries(Test113 PUBLIC
    GTest::gtest_main
    gmock_main
    113_solution
    tools
    )

target_include_directories(Test113 PUBLIC
     "${PROJECT_SOURCE_DIR}/113_Path_Sum_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test113)

# add debug for 113_Path_Sum_II
add_executable(Debug113
    Debug113.cc
    )

target_link_libraries(Debug113 PUBLIC
    113_solution
    tools
    )

target_include_directories(Debug113 PUBLIC
     "${PROJECT_SOURCE_DIR}/113_Path_Sum_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

