# add test for 117_Populating_Next_Right_Pointers_in_Each_Node_II
add_executable(Test117
    Test117.cc
    )

target_link_libraries(Test117 PUBLIC
    GTest::gtest_main
    gmock_main
    117_solution
    tools
    )

target_include_directories(Test117 PUBLIC
     "${PROJECT_SOURCE_DIR}/117_Populating_Next_Right_Pointers_in_Each_Node_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test117)

# add debug for 117_Populating_Next_Right_Pointers_in_Each_Node_II
add_executable(Debug117
    Debug117.cc
    )

target_link_libraries(Debug117 PUBLIC
    117_solution
    tools
    )

target_include_directories(Debug117 PUBLIC
     "${PROJECT_SOURCE_DIR}/117_Populating_Next_Right_Pointers_in_Each_Node_II"
     "${PROJECT_SOURCE_DIR}/tools"
    )

