#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "Solution173.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test173, CheckZeroNode) {
    BSTIterator s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr
    EXPECT_EQ(s.inorderTraversal(p_root).size(), 0);
}

TEST(Test173, CheckOneNode) {
    BSTIterator s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({0}));
        delete st;
    }
}

TEST(Test173, CheckTwoNode) {
    BSTIterator s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
        delete st;
    }

    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({0, 1}));
        delete st;
    }
}

TEST(Test173, CheckThreeNode) {
    BSTIterator s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test three node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0, 2}));
        delete st;
    }

    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 0}));
        delete st;
    }
}

TEST(Test173, CheckFourNode) {
    BSTIterator s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test four node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 3, 0, 2}));
        delete st;
    }

    {
        s_vec.clear();
        s_vec.assign({"3", "2", "4", "null", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 3, 1, 4}));
        delete st;
    }
}

TEST(Test173, CheckFiveNode) {
    BSTIterator s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test five node input
    {
        s_vec.clear();
        s_vec.assign({"0",
                    "1", "2",
                "null", "null", "null", "3",
            "null", "null", "null", "null", "null", "null", "null", "4"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.inorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0, 2, 3, 4}));
        delete st;
    }
}
