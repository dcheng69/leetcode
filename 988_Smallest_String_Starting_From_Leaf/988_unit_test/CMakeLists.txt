# add test for 988_Smallest_String_Starting_From_Leaf
add_executable(Test988
    Test988.cc
    )

target_link_libraries(Test988 PUBLIC
    GTest::gtest_main
    gmock_main
    988_solution
    tools
    )

target_include_directories(Test988 PUBLIC
     "${PROJECT_SOURCE_DIR}/988_Smallest_String_Starting_From_Leaf"
     "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(Test988)

# add debug for 988_Smallest_String_Starting_From_Leaf
add_executable(Debug988
    Debug988.cc
    )

target_link_libraries(Debug988 PUBLIC
    988_solution
    tools
    )

target_include_directories(Debug988 PUBLIC
     "${PROJECT_SOURCE_DIR}/988_Smallest_String_Starting_From_Leaf"
     "${PROJECT_SOURCE_DIR}/tools"
    )

