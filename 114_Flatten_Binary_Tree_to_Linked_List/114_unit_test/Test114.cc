#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution114.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

vector<int> linkRightTree(TreeNode* root) {
    vector<int> i_vec;
    while (root) {
        i_vec.push_back(root->val);
        root = root->right;
    }
    return i_vec;
}

TEST(Test144, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    s.flatten(p_root);
    EXPECT_EQ(p_root, nullptr);
}

TEST(Test144, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0}));
        st.~SmartTreeNode();
    }
}

TEST(Test144, CheckTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0, 1}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0, 1}));
        st.~SmartTreeNode();
    }
}

TEST(Test144, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        st.~SmartTreeNode();
    }
}

TEST(Test144, CheckFourNode) {
    Solution s;
    vector<string> s_vec;

    // test four node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        s.flatten(st.GetRootNodePointer());
        EXPECT_THAT(linkRightTree(st.GetRootNodePointer()), ElementsAreArray({0, 1, 3, 2}));
        st.~SmartTreeNode();
    }
}
