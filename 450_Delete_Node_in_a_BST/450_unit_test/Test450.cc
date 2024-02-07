#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution450.h"
#include "TreeNode.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test450, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_EQ(s.inorderTraversal(p_root).size(), 0);
    }
}


TEST(Test450, CheckOneNode) {
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

TEST(Test450, CheckTwoNode) {
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

TEST(Test450, CheckThreeNode) {
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

TEST(Test450, CheckFourNode) {
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

TEST(Test450, CheckMultipleNode) {
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

TEST(Test450, CheckDeleteLeafNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 2)), ElementsAreArray({3,4,5,6,7}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 4)), ElementsAreArray({2,3,5,6,7}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 7)), ElementsAreArray({2,3,4,5,6}));
        st.~SmartTreeNode();
    }
}


TEST(Test450, CheckDeleteOneChildNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 6)), ElementsAreArray({2,3,4,5,7}));
        st.~SmartTreeNode();
    }
}

TEST(Test450, CheckDeleteTwoChildNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 3)), ElementsAreArray({2,4,5,6,7}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 5)), ElementsAreArray({2,3,4,6,7}));
        st.~SmartTreeNode();
    }
}


TEST(Test450, CheckDeleteBoundaries) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"5",
                "3", "6",
            "2", "4", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(s.deleteNode(st.GetRootNodePointer(), 8)), ElementsAreArray({2,3,4,5,6,7}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_EQ(s.deleteNode(st.GetRootNodePointer(), 5),nullptr); 
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"5"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_EQ(s.deleteNode(st.GetRootNodePointer(), 5),nullptr); 
        st.~SmartTreeNode();
    }
}
