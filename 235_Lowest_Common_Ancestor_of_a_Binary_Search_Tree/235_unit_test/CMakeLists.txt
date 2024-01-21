# add test for 235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree
add_executable(Test235
    Test235.cc
    )

target_link_libraries(Test235 PUBLIC
    GTest::gtest_main
    gmock_main
    235_solution
    tools
    )

target_include_directories(Test235 PUBLIC
     "${PROJECT_SOURCE_DIR}/235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test235)

# add debug for 235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree
add_executable(Debug235
    Debug235.cc
    )

target_link_libraries(Debug235 PUBLIC
    235_solution
    tools
    )

target_include_directories(Debug235 PUBLIC
     "${PROJECT_SOURCE_DIR}/235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

