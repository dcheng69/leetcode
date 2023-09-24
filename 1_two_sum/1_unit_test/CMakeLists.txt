# add test for 1_two_sum
add_executable(Test1
    Test1.cc
    )

target_link_libraries(Test1 PUBLIC
    GTest::gtest_main
    gmock_main
    1_solution
    tools
    )

target_include_directories(Test1 PUBLIC
    "${PROJECT_SOURCE_DIR}/1_two_sum"
    "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test1)

# add debug code for 1_two_sum
add_executable(Debug1 
    Debug1.cc
    )

target_link_libraries(Debug1 PUBLIC
    1_solution
    tools
    )

target_include_directories(Debug1 PUBLIC
    "${PROJECT_SOURCE_DIR}/1_two_sum"
    "${PROJECT_SOURCE_DIR}/tools"
    )
