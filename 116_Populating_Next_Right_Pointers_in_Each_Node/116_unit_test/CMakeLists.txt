# add test for 116_Populating_Next_Right_Pointers_in_Each_Node
add_executable(Test116
    Test116.cc
    )

target_link_libraries(Test116 PUBLIC
    GTest::gtest_main
    gmock_main
    116_solution
    tools
    )

target_include_directories(Test116 PUBLIC
     "${PROJECT_SOURCE_DIR}/116_Populating_Next_Right_Pointers_in_Each_Node"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test116)

# add debug for 116_Populating_Next_Right_Pointers_in_Each_Node
add_executable(Debug116
    Debug116.cc
    )

target_link_libraries(Debug116 PUBLIC
    116_solution
    tools
    )

target_include_directories(Debug116 PUBLIC
     "${PROJECT_SOURCE_DIR}/116_Populating_Next_Right_Pointers_in_Each_Node"
     "${PROJECT_SOURCE_DIR}/tools"
    )

