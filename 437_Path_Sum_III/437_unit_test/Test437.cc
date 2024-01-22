#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution437.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test437, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.postorderTraversal(p_root).size(), 0);
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
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({0}));
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
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
        delete st;
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode* st = new SmartTreeNode(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.postorderTraversal(st->GetRootNodePointer()), ElementsAreArray({1, 0}));
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

TEST(Test144, CheckFourNode) {
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

TEST(Test437, CheckPathSum) {
    Solution s;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"10","5","-3","3","2","null","11","3","-2","null","1"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_EQ(s.pathSum(st.GetRootNodePointer(), 8), 3);
    }
    {
        s_vec.clear();
        s_vec.assign({"5","4","8","11","null","13","4","7","2","null", "null","5", "1"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_EQ(s.pathSum(st.GetRootNodePointer(), 22), 3);
    }
}
