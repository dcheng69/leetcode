# add test for 173_Binary_Search_Tree_Iterator
add_executable(Test173
    Test173.cc
    )

target_link_libraries(Test173 PUBLIC
    GTest::gtest_main
    gmock_main
    173_solution
    tools
    )

target_include_directories(Test173 PUBLIC
     "${PROJECT_SOURCE_DIR}/173_Binary_Search_Tree_Iterator"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test173)

# add debug for 173_Binary_Search_Tree_Iterator
add_executable(Debug173
    Debug173.cc
    )

target_link_libraries(Debug173 PUBLIC
    173_solution
    tools
    )

target_include_directories(Debug173 PUBLIC
     "${PROJECT_SOURCE_DIR}/173_Binary_Search_Tree_Iterator"
     "${PROJECT_SOURCE_DIR}/tools"
    )

