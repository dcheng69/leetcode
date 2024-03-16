#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution449.h"
#include "TreeNode.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test449, CheckSerialZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_THAT(s.serialize(p_root), "");
    }
}

TEST(Test449, CheckSerialOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        st.GetRootNodePointer();
        EXPECT_THAT(s.serialize(st.GetRootNodePointer()), "0$0");
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckSerialTwoNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        st.GetRootNodePointer();
        EXPECT_THAT(s.serialize(st.GetRootNodePointer()), "1,0$1,0");
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_EQ(s.inorderTraversal(p_root).size(), 0);
    }
}

TEST(Test449, CheckInorderOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderTwoNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0,1}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderThreeNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0,2}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({2,1,0}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderFourNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,3,0,2}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckInorderMultipleNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"15",
                "null", "20",
            "null", "null", "18", "30",
    "null", "null","null", "null", "16", "19"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({15,16,18,19,20,30}));
        st.~SmartTreeNode();
    }
}

TEST(Test449, CheckPostOneNode) {
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

TEST(Test449, CheckPostTwoNode) {
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

TEST(Test449, CheckPostThreeNode) {
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

TEST(Test449, CheckPostFourNode) {
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
