# add test for 513_Find_Bottom_Left_Tree_Value
add_executable(Test513
    Test513.cc
    )

target_link_libraries(Test513 PUBLIC
    GTest::gtest_main
    gmock_main
    513_solution
    tools
    )

target_include_directories(Test513 PUBLIC
     "${PROJECT_SOURCE_DIR}/513_Find_Bottom_Left_Tree_Value"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test513)

# add debug for 513_Find_Bottom_Left_Tree_Value
add_executable(Debug513
    Debug513.cc
    )

target_link_libraries(Debug513 PUBLIC
    513_solution
    tools
    )

target_include_directories(Debug513 PUBLIC
     "${PROJECT_SOURCE_DIR}/513_Find_Bottom_Left_Tree_Value"
     "${PROJECT_SOURCE_DIR}/tools"
    )

