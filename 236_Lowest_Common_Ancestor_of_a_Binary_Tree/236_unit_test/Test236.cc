#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution236.h"
#include "PrintX.h"
using namespace std;
TEST(Test236, CheckLCA) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"3","5","1","6","2","0","8","null","null","7","4"});
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
        s_vec.assign({"3","5","1","6","2","0","8","null","null","7","4"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        TreeNode* p = st->GetRootNodePointer()->left;
        TreeNode* q = p->right->right;
        TreeNode* p_node_ret = p;
        EXPECT_EQ(s.lowestCommonAncestor(st->GetRootNodePointer(), p, q), p_node_ret);
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"1","2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());
        TreeNode* p = st->GetRootNodePointer();
        TreeNode* q = st->GetRootNodePointer()->left;
        TreeNode* p_node_ret = p;
        EXPECT_EQ(s.lowestCommonAncestor(st->GetRootNodePointer(), p, q), p_node_ret);
        delete st;
    }
}
