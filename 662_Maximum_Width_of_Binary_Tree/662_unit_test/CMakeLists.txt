# add test for 662_Maximum_Width_of_Binary_Tree
add_executable(Test662
    Test662.cc
    )

target_link_libraries(Test662 PUBLIC
    GTest::gtest_main
    gmock_main
    662_solution
    tools
    )

target_include_directories(Test662 PUBLIC
     "${PROJECT_SOURCE_DIR}/662_Maximum_Width_of_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test662)

# add debug for 662_Maximum_Width_of_Binary_Tree
add_executable(Debug662
    Debug662.cc
    )

target_link_libraries(Debug662 PUBLIC
    662_solution
    tools
    )

target_include_directories(Debug662 PUBLIC
     "${PROJECT_SOURCE_DIR}/662_Maximum_Width_of_Binary_Tree"
     "${PROJECT_SOURCE_DIR}/tools"
    )

