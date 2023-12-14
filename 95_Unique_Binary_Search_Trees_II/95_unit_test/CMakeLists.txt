# add test for 95_Unique_Binary_Search_Trees_II
add_executable(Test95
    Test95.cc
    )

target_link_libraries(Test95 PUBLIC
    GTest::gtest_main
    gmock_main
    95_solution
    tools
    )

target_include_directories(Test95 PUBLIC
     "${PROJECT_SOURCE_DIR}/95_Unique_Binary_Search_Trees_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test95)

# add debug for 95_Unique_Binary_Search_Trees_II
add_executable(Debug95
    Debug95.cc
    )

target_link_libraries(Debug95 PUBLIC
    95_solution
    tools
    )

target_include_directories(Debug95 PUBLIC
     "${PROJECT_SOURCE_DIR}/95_Unique_Binary_Search_Trees_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

