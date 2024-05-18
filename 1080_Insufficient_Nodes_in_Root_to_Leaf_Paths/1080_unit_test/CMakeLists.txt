# add test for 1080_Insufficient_Nodes_in_Root_to_Leaf_Paths
add_executable(Test1080
    Test1080.cc
    )

target_link_libraries(Test1080 PUBLIC
    GTest::gtest_main
    gmock_main
    1080_solution
    tools
    )

target_include_directories(Test1080 PUBLIC
     "${PROJECT_SOURCE_DIR}/1080_Insufficient_Nodes_in_Root_to_Leaf_Paths"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test1080)

# add debug for 1080_Insufficient_Nodes_in_Root_to_Leaf_Paths
add_executable(Debug1080
    Debug1080.cc
    )

target_link_libraries(Debug1080 PUBLIC
    1080_solution
    tools
    )

target_include_directories(Debug1080 PUBLIC
     "${PROJECT_SOURCE_DIR}/1080_Insufficient_Nodes_in_Root_to_Leaf_Paths"
     "${PROJECT_SOURCE_DIR}/tools"
    )

