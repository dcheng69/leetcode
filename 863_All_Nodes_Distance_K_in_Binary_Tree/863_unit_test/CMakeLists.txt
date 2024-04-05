# add test for 863_All_Nodes_Distance_K_in_Binary_Tree
add_executable(Test863
    Test863.cc
    )

target_link_libraries(Test863 PUBLIC
    GTest::gtest_main
    gmock_main
    863_solution
    tools
    )

target_include_directories(Test863 PUBLIC
     "${PROJECT_SOURCE_DIR}/863_All_Nodes_Distance_K_in_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test863)

# add debug for 863_All_Nodes_Distance_K_in_Binary_Tree
add_executable(Debug863
    Debug863.cc
    )

target_link_libraries(Debug863 PUBLIC
    863_solution
    tools
    )

target_include_directories(Debug863 PUBLIC
     "${PROJECT_SOURCE_DIR}/863_All_Nodes_Distance_K_in_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

