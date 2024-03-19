#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution538.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test538, CheckReverseInorderTraversalZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_EQ(s.reverseInorderTraversal(p_root).size(), 0);
    }
}

TEST(Test538, CheckReverseInorderTraversalOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0}));
        st.~SmartTreeNode();
    }

}

TEST(Test538, CheckReverseInorderTraversalTwoNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0,1}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0}));
        st.~SmartTreeNode();
    }
}

TEST(Test538, CheckReverseInorderTraversalThreeNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({2,0,1}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0,1,2}));
        st.~SmartTreeNode();
    }
}

TEST(Test538, CheckReverseInorderTraversalFourNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({2,0,3,1}));
        st.~SmartTreeNode();
    }
}

TEST(Test538, CheckReverseInorderTraversalMultipleNode) {
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
        EXPECT_THAT(s.reverseInorderTraversal(st.GetRootNodePointer()), ElementsAreArray({30,20,19,18,16,15}));
        st.~SmartTreeNode();
    }
}

TEST(Test538, CheckConvertZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;

    EXPECT_EQ(s.convertBST(p_root), nullptr);
}

TEST(Test538, CheckConvertCase1) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;
    vector<string> s_vec_ret;

    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        s_vec_ret.clear();
        s_vec_ret.assign({"1", "null", "1"});
        SmartTreeNode st_ret{ConstructTreeNode(s_vec_ret, "null")};
        EXPECT_THAT(ConstructVector(s.convertBST(st.GetRootNodePointer())),\
                ConstructVector(st_ret.GetRootNodePointer()));
        st.~SmartTreeNode();
    }

}

TEST(Test538, CheckConvertCase2) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;
    vector<string> s_vec_ret;

    {
        s_vec.clear();
        s_vec.assign({"4",
                "1", "6",
                "0", "2", "5", "7",
                "null", "null", "null", "3", "null", "null", "null", "8"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        s_vec_ret.clear();
        s_vec_ret.assign({"30",
                "36", "21",
                "36", "35", "26", "15",
                "null", "null", "null", "33", "null", "null", "null", "8"});
        SmartTreeNode st_ret{ConstructTreeNode(s_vec_ret, "null")};
        EXPECT_THAT(ConstructVector(s.convertBST(st.GetRootNodePointer())),\
                ConstructVector(st_ret.GetRootNodePointer()));
        st.~SmartTreeNode();
    }
}
