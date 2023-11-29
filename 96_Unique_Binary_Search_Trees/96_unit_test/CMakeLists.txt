# add test for 96_Unique_Binary_Search_Trees
add_executable(Test96
    Test96.cc
    )

target_link_libraries(Test96 PUBLIC
    GTest::gtest_main
    gmock_main
    96_solution
    tools
    )

target_include_directories(Test96 PUBLIC
     "${PROJECT_SOURCE_DIR}/96_Unique_Binary_Search_Trees"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test96)

# add debug for 96_Unique_Binary_Search_Trees
add_executable(Debug96
    Debug96.cc
    )

target_link_libraries(Debug96 PUBLIC
    96_solution
    tools
    )

target_include_directories(Debug96 PUBLIC
     "${PROJECT_SOURCE_DIR}/96_Unique_Binary_Search_Trees"
     "${PROJECT_SOURCE_DIR}/tools"
    )

