# add test for 236_Lowest_Common_Ancestor_of_a_Binary_Tree
add_executable(Test236
    Test236.cc
    )

target_link_libraries(Test236 PUBLIC
    GTest::gtest_main
    gmock_main
    236_solution
    tools
    )

target_include_directories(Test236 PUBLIC
     "${PROJECT_SOURCE_DIR}/236_Lowest_Common_Ancestor_of_a_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test236)

# add debug for 236_Lowest_Common_Ancestor_of_a_Binary_Tree
add_executable(Debug236
    Debug236.cc
    )

target_link_libraries(Debug236 PUBLIC
    236_solution
    tools
    )

target_include_directories(Debug236 PUBLIC
     "${PROJECT_SOURCE_DIR}/236_Lowest_Common_Ancestor_of_a_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

