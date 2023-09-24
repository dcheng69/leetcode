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
