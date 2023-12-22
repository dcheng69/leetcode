cmake_minimum_required(VERSION 3.14)
project(leetcode)

# ccls condifuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# add Debug symbols
set(CMAKE_BUILD_TYPE Debug)

# GoogleTest requires at least c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch the google test dependencies
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_subdirectory(tools)
add_subdirectory(1_two_sum)
add_subdirectory(144_Binary_Tree_Preorder_Traversal)
add_subdirectory(145_Binary_Tree_Postorder_Traversal)
add_subdirectory(129_Sum_Root_to_Leaf_Numbers)
add_subdirectory(102_Binary_Tree_Level_Order_Traversal)
add_subdirectory(96_Unique_Binary_Search_Trees)
add_subdirectory(95_Unique_Binary_Search_Trees_II)
add_subdirectory(107_Binary_Tree_Level_Order_Traversal_II)
add_subdirectory(106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal)
add_subdirectory(105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal)
