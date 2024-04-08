# add test for 894_All_Possible_Full_Binary_Trees
add_executable(Test894
    Test894.cc
    )

target_link_libraries(Test894 PUBLIC
    GTest::gtest_main
    gmock_main
    894_solution
    tools
    )

target_include_directories(Test894 PUBLIC
     "${PROJECT_SOURCE_DIR}/894_All_Possible_Full_Binary_Trees"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test894)

# add debug for 894_All_Possible_Full_Binary_Trees
add_executable(Debug894
    Debug894.cc
    )

target_link_libraries(Debug894 PUBLIC
    894_solution
    tools
    )

target_include_directories(Debug894 PUBLIC
     "${PROJECT_SOURCE_DIR}/894_All_Possible_Full_Binary_Trees"
     "${PROJECT_SOURCE_DIR}/tools"
    )

