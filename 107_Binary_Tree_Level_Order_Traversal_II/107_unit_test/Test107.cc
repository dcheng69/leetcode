#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution107.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test145, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.levelOrderBottom(p_root).size(), 0);
}

TEST(Test144, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        vector<vector<int>> expected_ret = {{0}};
        EXPECT_THAT(s.levelOrderBottom(st->GetRootNodePointer()), ElementsAreArray(expected_ret));
        delete st;
    }
}

TEST(Test144, CheckTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        vector<vector<int>> expected_ret = {{1},{0}};
        EXPECT_THAT(s.levelOrderBottom(st->GetRootNodePointer()), ElementsAreArray(expected_ret));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        vector<vector<int>> expected_ret = {{1},{0}};
        EXPECT_THAT(s.levelOrderBottom(st->GetRootNodePointer()), ElementsAreArray(expected_ret));
        delete st;
    }
}


TEST(Test144, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        vector<vector<int>> expected_ret = {{1, 2},{0}};
        EXPECT_THAT(s.levelOrderBottom(st->GetRootNodePointer()), ElementsAreArray(expected_ret));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        vector<vector<int>> expected_ret = {{2},{1},{0}};
        EXPECT_THAT(s.levelOrderBottom(st->GetRootNodePointer()), ElementsAreArray(expected_ret));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        vector<vector<int>> expected_ret = {{2},{1},{0}};
        EXPECT_THAT(s.levelOrderBottom(st->GetRootNodePointer()), ElementsAreArray(expected_ret));
        delete st;
    }
}
