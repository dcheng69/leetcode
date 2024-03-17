# add test for 449_Serialize_and_Deserialize_BST
add_executable(Test449
    Test449.cc
    )

target_link_libraries(Test449 PUBLIC
    GTest::gtest_main
    gmock_main
    449_solution
    tools
    )

target_include_directories(Test449 PUBLIC
     "${PROJECT_SOURCE_DIR}/449_Serialize_and_Deserialize_BST"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test449)

# add debug for 449_Serialize_and_Deserialize_BST
add_executable(Debug449
    Debug449.cc
    )

target_link_libraries(Debug449 PUBLIC
    449_solution
    tools
    )

target_include_directories(Debug449 PUBLIC
     "${PROJECT_SOURCE_DIR}/449_Serialize_and_Deserialize_BST"
     "${PROJECT_SOURCE_DIR}/tools"
    )

