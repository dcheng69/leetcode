#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution652.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;
using testing::UnorderedElementsAreArray;

TEST(Test652, CheckDuplicateTestCases) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test case 1
    {
        s_vec.clear();
        s_vec.assign({"1",
                "2", "3",
                "4", "null", "2", "4",
                "null", "null", "null", "null", "4"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        vector<TreeNode*> t_vec = s.findDuplicateSubtrees(st.GetRootNodePointer());
        vector<vector<int>> vec_vec_i;
        for (int i=0; i<t_vec.size(); i++) {
            vec_vec_i.push_back(s.preorderTraversal(t_vec[i]));
        }
        st.~SmartTreeNode();
        vector<vector<int>> vec_vec_i_cmp{{2,4}, {4}};
        EXPECT_THAT(vec_vec_i, UnorderedElementsAreArray(vec_vec_i_cmp));
    }
}

TEST(Test652, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.preorderTraversal(p_root).size(), 0);
}

TEST(Test652, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0}));
        st.~SmartTreeNode();
    }
}

TEST(Test652, CheckTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0, 1}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0, 1}));
        st.~SmartTreeNode();
    }
}

TEST(Test652, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1", "null", "null", "null", "2"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        PrintTree(st.GetRootNodePointer());
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0, 1, 2}));
        st.~SmartTreeNode();
    }
}

TEST(Test652, CheckFourNode) {
    Solution s;
    vector<string> s_vec;

    // test four node
    {
        s_vec.clear();
        s_vec.assign({"0", "1", "2", "null", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.preorderTraversal(st.GetRootNodePointer()), ElementsAreArray({0, 1, 3, 2}));
        st.~SmartTreeNode();
    }
}
