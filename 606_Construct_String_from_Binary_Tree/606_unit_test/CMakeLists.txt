# add test for 606_Construct_String_from_Binary_Tree
add_executable(Test606
    Test606.cc
    )

target_link_libraries(Test606 PUBLIC
    GTest::gtest_main
    gmock_main
    606_solution
    tools
    )

target_include_directories(Test606 PUBLIC
     "${PROJECT_SOURCE_DIR}/606_Construct_String_from_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test606)

# add debug for 606_Construct_String_from_Binary_Tree
add_executable(Debug606
    Debug606.cc
    )

target_link_libraries(Debug606 PUBLIC
    606_solution
    tools
    )

target_include_directories(Debug606 PUBLIC
     "${PROJECT_SOURCE_DIR}/606_Construct_String_from_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

