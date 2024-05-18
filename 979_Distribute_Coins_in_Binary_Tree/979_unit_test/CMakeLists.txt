# add test for 979_Distribute_Coins_in_Binary_Tree
add_executable(Test979
    Test979.cc
    )

target_link_libraries(Test979 PUBLIC
    GTest::gtest_main
    gmock_main
    979_solution
    tools
    )

target_include_directories(Test979 PUBLIC
     "${PROJECT_SOURCE_DIR}/979_Distribute_Coins_in_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test979)

# add debug for 979_Distribute_Coins_in_Binary_Tree
add_executable(Debug979
    Debug979.cc
    )

target_link_libraries(Debug979 PUBLIC
    979_solution
    tools
    )

target_include_directories(Debug979 PUBLIC
     "${PROJECT_SOURCE_DIR}/979_Distribute_Coins_in_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

