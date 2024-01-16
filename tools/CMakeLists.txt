add_library(tools
    PrintX.cc
    TreeNode.cc
    ListNode.cc
    Node.cc
    )

target_include_directories( tools PUBLIC
    "${PROJECT_SOURCE_DIR}/tools"
    )

# add the unit test directory
add_subdirectory(unit_test)
