#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "Solution144.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test144, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.preorderTraversal(p_root).size(), 0);
}

TEST(Test144, CheckOneNode) {
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

TEST(Test144, CheckTwoNode) {
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

TEST(Test144, CheckThreeNode) {
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

TEST(Test144, CheckFourNode) {
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
