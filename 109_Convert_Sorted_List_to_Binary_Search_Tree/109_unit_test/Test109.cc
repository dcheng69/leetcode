#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution109.h"
#include "PrintX.h"
using namespace std;

TEST(Test109, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.sortedListToBST(p_node), nullptr);
}

TEST(Test109, CheckOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;
    vector<int> i_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        i_vec.clear();
        i_vec.assign({0});
        SmartListNode* sl = new SmartListNode(ConstructListNode(i_vec));
        PrintList(sl->GetHeadNodePointer());

        vector<string> ret_vec = ConstructVector(s.sortedListToBST(sl->GetHeadNodePointer()));
        vector<string> cmp_vec = ConstructVector(st->GetRootNodePointer());
        EXPECT_THAT(ret_vec, cmp_vec);
        delete st;
        delete sl;
    }
}

TEST(Test109, CheckTwoNodes) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;
    vector<int> i_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"1", "0", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        i_vec.clear();
        i_vec.assign({0, 1});
        SmartListNode* sl = new SmartListNode(ConstructListNode(i_vec));
        PrintList(sl->GetHeadNodePointer());

        vector<string> ret_vec = ConstructVector(s.sortedListToBST(sl->GetHeadNodePointer()));
        vector<string> cmp_vec = ConstructVector(st->GetRootNodePointer());
        EXPECT_THAT(ret_vec, cmp_vec);
        delete st;
        delete sl;
    }
}

TEST(Test109, CheckThreeNodes) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;
    vector<int> i_vec;

    // test three node input
    {
        s_vec.clear();
        s_vec.assign({"1", "0", "2"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        i_vec.clear();
        i_vec.assign({0, 1, 2});
        SmartListNode* sl = new SmartListNode(ConstructListNode(i_vec));
        PrintList(sl->GetHeadNodePointer());

        vector<string> ret_vec = ConstructVector(s.sortedListToBST(sl->GetHeadNodePointer()));
        vector<string> cmp_vec = ConstructVector(st->GetRootNodePointer());
        EXPECT_THAT(ret_vec, cmp_vec);
        delete st;
        delete sl;
    }
}

TEST(Test109, CheckFourNodes) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;
    vector<int> i_vec;

    // test four node input
    {
        s_vec.clear();
        s_vec.assign({"2", "1", "3", "0", "null", "null", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        i_vec.clear();
        i_vec.assign({0, 1, 2, 3});
        SmartListNode* sl = new SmartListNode(ConstructListNode(i_vec));
        PrintList(sl->GetHeadNodePointer());

        TreeNode* p_tree_ret = s.sortedListToBST(sl->GetHeadNodePointer());
        vector<string> ret_vec = ConstructVector(p_tree_ret);
        vector<string> cmp_vec = ConstructVector(st->GetRootNodePointer());
        EXPECT_THAT(ret_vec, cmp_vec);
        Print("ret_vec:", ret_vec);
        Print("cmp_vec:", cmp_vec);
        delete st;
        delete sl;
    }
}


TEST(Test109, CheckFiveNodes) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;
    vector<int> i_vec;

    // test five node input
    {
        s_vec.clear();
        s_vec.assign({"2", "1", "4", "0", "null", "3", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        i_vec.clear();
        i_vec.assign({0, 1, 2, 3, 4});
        SmartListNode* sl = new SmartListNode(ConstructListNode(i_vec));
        PrintList(sl->GetHeadNodePointer());

        TreeNode* p_tree_ret = s.sortedListToBST(sl->GetHeadNodePointer());
        vector<string> ret_vec = ConstructVector(p_tree_ret);
        vector<string> cmp_vec = ConstructVector(st->GetRootNodePointer());
        EXPECT_THAT(ret_vec, cmp_vec);
        Print("ret_vec:", ret_vec);
        Print("cmp_vec:", cmp_vec);
        delete st;
        delete sl;
    }
}

TEST(Test109, CheckSixNodes) {
    Solution s;
    TreeNode* p_root = nullptr;
    ListNode* p_node = nullptr;
    vector<string> s_vec;
    vector<int> i_vec;

    // test six node input
    {
        s_vec.clear();
        s_vec.assign({"3", "1", "5", "0", "2", "4", "null"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        PrintTree(st->GetRootNodePointer());

        i_vec.clear();
        i_vec.assign({0, 1, 2, 3, 4, 5});
        SmartListNode* sl = new SmartListNode(ConstructListNode(i_vec));
        PrintList(sl->GetHeadNodePointer());

        TreeNode* p_tree_ret = s.sortedListToBST(sl->GetHeadNodePointer());
        vector<string> ret_vec = ConstructVector(p_tree_ret);
        vector<string> cmp_vec = ConstructVector(st->GetRootNodePointer());
        EXPECT_THAT(ret_vec, cmp_vec);
        Print("ret_vec:", ret_vec);
        Print("cmp_vec:", cmp_vec);
        delete st;
        delete sl;
    }
}
