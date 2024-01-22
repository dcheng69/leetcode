# add test for 437_Path_Sum_III
add_executable(Test437
    Test437.cc
    )

target_link_libraries(Test437 PUBLIC
    GTest::gtest_main
    gmock_main
    437_solution
    tools
    )

target_include_directories(Test437 PUBLIC
     "${PROJECT_SOURCE_DIR}/437_Path_Sum_III"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test437)

# add debug for 437_Path_Sum_III
add_executable(Debug437
    Debug437.cc
    )

target_link_libraries(Debug437 PUBLIC
    437_solution
    tools
    )

target_include_directories(Debug437 PUBLIC
     "${PROJECT_SOURCE_DIR}/437_Path_Sum_III"
     "${PROJECT_SOURCE_DIR}/tools"
    )

