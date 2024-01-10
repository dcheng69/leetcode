# add test for PrintX
add_executable(TestPrintX TestPrintX.cc)

target_link_libraries(TestPrintX PUBLIC
    GTest::gtest_main
    gmock_main
    tools
    )

target_include_directories(TestPrintX PUBLIC
    "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(TestPrintX)

# add debug for PrintX
add_executable(DebugPrintX DebugPrintX.cc)

target_link_libraries(DebugPrintX PUBLIC
    tools
    )

target_include_directories(DebugPrintX PUBLIC
    "${PROJECT_SOURCE_DIR}/tools"
    )

# add test for TreeNode
add_executable(TestTreeNode TestTreeNode.cc)

target_link_libraries(TestTreeNode PUBLIC
    GTest::gtest_main
    gmock_main
    tools
    )

target_include_directories(TestTreeNode PUBLIC
    "${PROJECT_SOURCE_DIR}/tools"
    )

# add test for ListNode
add_executable(TestListNode TestListNode.cc)

target_link_libraries(TestListNode PUBLIC
    GTest::gtest_main
    gmock_main
    tools
    )

target_include_directories(TestListNode PUBLIC
    "${PROJECT_SOURCE_DIR}/tools"
    )

include(GoogleTest)
gtest_discover_tests(TestTreeNode)

# add debug for TreeNode
add_executable(DebugTreeNode DebugTreeNode.cc)

target_link_libraries(DebugTreeNode PUBLIC
    tools
    )

target_include_directories(DebugTreeNode PUBLIC
    "${PROJECT_SOURCE_DIR}/tools"
    )
