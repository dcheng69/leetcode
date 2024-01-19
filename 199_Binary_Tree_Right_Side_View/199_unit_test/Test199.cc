#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution199.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test199, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;

    // test nullptr input
    EXPECT_EQ(s.rightSideView(p_root).size(), 0);
}

TEST(Test199, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        EXPECT_THAT(s.rightSideView(st->GetRootNodePointer()), ElementsAreArray({0}));
        delete st;
    }
}


TEST(Test199, CheckTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        EXPECT_THAT(s.rightSideView(st->GetRootNodePointer()), ElementsAreArray({0, 1}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        EXPECT_THAT(s.rightSideView(st->GetRootNodePointer()), ElementsAreArray({0, 1}));
        delete st;
    }
}

TEST(Test199, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        EXPECT_THAT(s.rightSideView(st->GetRootNodePointer()), ElementsAreArray({0, 2}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        EXPECT_THAT(s.rightSideView(st->GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        EXPECT_THAT(s.rightSideView(st->GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        delete st;
    }
}
