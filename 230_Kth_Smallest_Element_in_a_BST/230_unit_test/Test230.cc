#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution230.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test230, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr
    EXPECT_EQ(s.inorderTraversal(p_root).size(), 0);
}

TEST(Test230, CheckOneNode) {
    Solution s;
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

TEST(Test230, CheckTwoNode) {
    Solution s;
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

TEST(Test230, CheckThreeNode) {
    Solution s;
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

TEST(Test230, CheckFourNode) {
    Solution s;
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

TEST(Test230, CheckFiveNode) {
    Solution s;
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

TEST(Test230, CheckBST) {
    Solution s;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec = {"3", "1", "4", "#", "2"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 1), 1);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 2), 2);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 3), 3);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 4), 4);
    }
    {
        s_vec.clear();
        s_vec = {"5", "3", "6", "2", "4", "#", "#", "1"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 1), 1);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 2), 2);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 3), 3);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 4), 4);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 5), 5);
        EXPECT_EQ(s.kthSmallest(st.GetRootNodePointer(), 6), 6);
    }
}
