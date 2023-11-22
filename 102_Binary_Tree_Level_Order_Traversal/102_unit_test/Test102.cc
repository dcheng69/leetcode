#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution102.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test145, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.levelOrder(p_root).size(), 0);
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
        vector<vector<int>> ret = s.levelOrder(st->GetRootNodePointer());
        EXPECT_THAT(ret[0], ElementsAreArray({0}));
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
        vector<vector<int>> ret = s.levelOrder(st->GetRootNodePointer());
        EXPECT_THAT(ret[0], ElementsAreArray({0}));
        EXPECT_THAT(ret[1], ElementsAreArray({1}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        vector<vector<int>> ret = s.levelOrder(st->GetRootNodePointer());
        EXPECT_THAT(ret[0], ElementsAreArray({0}));
        EXPECT_THAT(ret[1], ElementsAreArray({1}));
        delete st;
    }
}

TEST(Test144, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        vector<vector<int>> ret = s.levelOrder(st->GetRootNodePointer());
        EXPECT_THAT(ret[0], ElementsAreArray({0}));
        EXPECT_THAT(ret[1], ElementsAreArray({1, 2}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        vector<vector<int>> ret = s.levelOrder(st->GetRootNodePointer());
        EXPECT_THAT(ret[0], ElementsAreArray({0}));
        EXPECT_THAT(ret[1], ElementsAreArray({1}));
        EXPECT_THAT(ret[2], ElementsAreArray({2}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        vector<vector<int>> ret = s.levelOrder(st->GetRootNodePointer());
        EXPECT_THAT(ret[0], ElementsAreArray({0}));
        EXPECT_THAT(ret[1], ElementsAreArray({1}));
        EXPECT_THAT(ret[2], ElementsAreArray({2}));
        delete st;
    }
}
