# add test for 109_Convert_Sorted_List_to_Binary_Search_Tree
add_executable(Test109
    Test109.cc
    )

target_link_libraries(Test109 PUBLIC
    GTest::gtest_main
    gmock_main
    109_solution
    tools
    )

target_include_directories(Test109 PUBLIC
     "${PROJECT_SOURCE_DIR}/109_Convert_Sorted_List_to_Binary_Search_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test109)

# add debug for 109_Convert_Sorted_List_to_Binary_Search_Tree
add_executable(Debug109
    Debug109.cc
    )

target_link_libraries(Debug109 PUBLIC
    109_solution
    tools
    )

target_include_directories(Debug109 PUBLIC
     "${PROJECT_SOURCE_DIR}/109_Convert_Sorted_List_to_Binary_Search_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

