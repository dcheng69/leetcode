# add test for 958_Check_Completeness_of_a_Binary_Tree
add_executable(Test958
    Test958.cc
    )

target_link_libraries(Test958 PUBLIC
    GTest::gtest_main
    gmock_main
    958_solution
    tools
    )

target_include_directories(Test958 PUBLIC
     "${PROJECT_SOURCE_DIR}/958_Check_Completeness_of_a_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test958)

# add debug for 958_Check_Completeness_of_a_Binary_Tree
add_executable(Debug958
    Debug958.cc
    )

target_link_libraries(Debug958 PUBLIC
    958_solution
    tools
    )

target_include_directories(Debug958 PUBLIC
     "${PROJECT_SOURCE_DIR}/958_Check_Completeness_of_a_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

