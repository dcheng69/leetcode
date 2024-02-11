#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution508.h"
using namespace std;
using testing::ElementsAreArray;
using testing::UnorderedElementsAreArray;

TEST(Test508, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    {
        EXPECT_EQ(s.inorderTraversal(p_root).size(), 0);
        EXPECT_EQ(s.calSubTreeSum(p_root), 0);
    }
}


TEST(Test508, CheckOneNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0}));
        EXPECT_EQ(s.calSubTreeSum(p_root), 0);
        st.~SmartTreeNode();
    }
}

TEST(Test508, CheckTwoNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0}));
        EXPECT_EQ(s.calSubTreeSum(st.GetRootNodePointer()), 1);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0,1}));
        EXPECT_EQ(s.calSubTreeSum(st.GetRootNodePointer()), 1);
        st.~SmartTreeNode();
    }
}

TEST(Test508, CheckThreeNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,0,2}));
        EXPECT_EQ(s.calSubTreeSum(st.GetRootNodePointer()), 3);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({2,1,0}));
        EXPECT_EQ(s.calSubTreeSum(st.GetRootNodePointer()), 3);
        st.~SmartTreeNode();
    }
}

TEST(Test508, CheckFourNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.inorderTraversal(st.GetRootNodePointer()), ElementsAreArray({1,3,0,2}));
        EXPECT_EQ(s.calSubTreeSum(st.GetRootNodePointer()), 6);
        st.~SmartTreeNode();
    }
}

TEST(Test508, CheckMultipleNode) {
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
        EXPECT_EQ(s.calSubTreeSum(st.GetRootNodePointer()), 118);
        st.~SmartTreeNode();
    }
}

TEST(Test508, CheckSubTreeSum) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test two nodes input
    {
        s_vec.clear();
        s_vec.assign({"5", "2", "-3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.findFrequentTreeSum(st.GetRootNodePointer()), UnorderedElementsAreArray({2,-3,4}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"5", "2", "-5"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.findFrequentTreeSum(st.GetRootNodePointer()), UnorderedElementsAreArray({2}));
        st.~SmartTreeNode();
    }
}
