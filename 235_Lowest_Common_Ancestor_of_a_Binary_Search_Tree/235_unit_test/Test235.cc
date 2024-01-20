#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution235.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test235, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.postorderTraversal(p_root).size(), 0);
}

TEST(Test245, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({0}));
        delete st;
    }
}

TEST(Test245, CheckTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
        delete st;
    }
}

TEST(Test245, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 2, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 0}));
        delete st;
    }
}

TEST(Test245, CheckFourNode) {
    Solution s;
    vector<string> s_vec;

    // test four node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({3, 1, 2, 0}));
        delete st;
    }
    // test four node
    {
        s_vec.clear();
        s_vec.assign({"3","2", "4", "null", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({2, 1, 4, 3}));
        delete st;
    }
}

TEST(Test235, CheckLCA) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"6","2","8","0","4","7","9","null","null","3","5"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        TreeNode* p = st->GetRootNodePointer()->left;
        TreeNode* q = st->GetRootNodePointer()->right;
        TreeNode* p_node_ret = st->GetRootNodePointer();
        EXPECT_EQ(s.lowestCommonAncestor(st->GetRootNodePointer(), p, q), p_node_ret);
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"6","2","8","0","4","7","9","null","null","3","5"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        TreeNode* p = st->GetRootNodePointer()->left;
        TreeNode* q = p->right;
        TreeNode* p_node_ret = p;
        EXPECT_EQ(s.lowestCommonAncestor(st->GetRootNodePointer(), p, q), p_node_ret);
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"2","1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        TreeNode* p = st->GetRootNodePointer();
        TreeNode* q = st->GetRootNodePointer()->left;
        TreeNode* p_node_ret = st->GetRootNodePointer();
        EXPECT_EQ(s.lowestCommonAncestor(st->GetRootNodePointer(), p, q), p_node_ret);
        delete st;
    }
}
