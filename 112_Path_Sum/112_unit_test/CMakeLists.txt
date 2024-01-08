# add test for 112_Path_Sum
add_executable(Test112
    Test112.cc
    )

target_link_libraries(Test112 PUBLIC
    GTest::gtest_main
    gmock_main
    112_solution
    tools
    )

target_include_directories(Test112 PUBLIC
     "${PROJECT_SOURCE_DIR}/112_Path_Sum"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test112)

# add debug for 112_Path_Sum
add_executable(Debug112
    Debug112.cc
    )

target_link_libraries(Debug112 PUBLIC
    112_solution
    tools
    )

target_include_directories(Debug112 PUBLIC
     "${PROJECT_SOURCE_DIR}/112_Path_Sum"
     "${PROJECT_SOURCE_DIR}/tools"
    )

