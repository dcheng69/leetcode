# add test for 652_Find_Duplicate_Subtrees
add_executable(Test652
    Test652.cc
    )

target_link_libraries(Test652 PUBLIC
    GTest::gtest_main
    gmock_main
    652_solution
    tools
    )

target_include_directories(Test652 PUBLIC
     "${PROJECT_SOURCE_DIR}/652_Find_Duplicate_Subtrees"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test652)

# add debug for 652_Find_Duplicate_Subtrees
add_executable(Debug652
    Debug652.cc
    )

target_link_libraries(Debug652 PUBLIC
    652_solution
    tools
    )

target_include_directories(Debug652 PUBLIC
     "${PROJECT_SOURCE_DIR}/652_Find_Duplicate_Subtrees"
     "${PROJECT_SOURCE_DIR}/tools"
    )

