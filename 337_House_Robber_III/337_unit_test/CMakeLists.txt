# add test for 337_House_Robber_III
add_executable(Test337
    Test337.cc
    )

target_link_libraries(Test337 PUBLIC
    GTest::gtest_main
    gmock_main
    337_solution
    tools
    )

target_include_directories(Test337 PUBLIC
     "${PROJECT_SOURCE_DIR}/337_House_Robber_III"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test337)

# add debug for 337_House_Robber_III
add_executable(Debug337
    Debug337.cc
    )

target_link_libraries(Debug337 PUBLIC
    337_solution
    tools
    )

target_include_directories(Debug337 PUBLIC
     "${PROJECT_SOURCE_DIR}/337_House_Robber_III"
     "${PROJECT_SOURCE_DIR}/tools"
    )

