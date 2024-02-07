# add test for 450_Delete_Node_in_a_BST
add_executable(Test450
    Test450.cc
    )

target_link_libraries(Test450 PUBLIC
    GTest::gtest_main
    gmock_main
    450_solution
    tools
    )

target_include_directories(Test450 PUBLIC
     "${PROJECT_SOURCE_DIR}/450_Delete_Node_in_a_BST"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test450)

# add debug for 450_Delete_Node_in_a_BST
add_executable(Debug450
    Debug450.cc
    )

target_link_libraries(Debug450 PUBLIC
    450_solution
    tools
    )

target_include_directories(Debug450 PUBLIC
     "${PROJECT_SOURCE_DIR}/450_Delete_Node_in_a_BST"
     "${PROJECT_SOURCE_DIR}/tools"
    )

