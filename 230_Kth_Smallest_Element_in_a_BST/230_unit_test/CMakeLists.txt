# add test for 230_Kth_Smallest_Element_in_a_BST
add_executable(Test230
    Test230.cc
    )

target_link_libraries(Test230 PUBLIC
    GTest::gtest_main
    gmock_main
    230_solution
    tools
    )

target_include_directories(Test230 PUBLIC
     "${PROJECT_SOURCE_DIR}/230_Kth_Smallest_Element_in_a_BST"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test230)

# add debug for 230_Kth_Smallest_Element_in_a_BST
add_executable(Debug230
    Debug230.cc
    )

target_link_libraries(Debug230 PUBLIC
    230_solution
    tools
    )

target_include_directories(Debug230 PUBLIC
     "${PROJECT_SOURCE_DIR}/230_Kth_Smallest_Element_in_a_BST"
     "${PROJECT_SOURCE_DIR}/tools"
    )

