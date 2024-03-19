#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution513.h"
using namespace std;

TEST(Test513, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;

    EXPECT_EQ(s.findBottomLeftValue(p_root), -1);
}

TEST(Test513, CheckThreeNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"2", "1", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_EQ(s.findBottomLeftValue(st.GetRootNodePointer()), 1);
        st.~SmartTreeNode();
    }
}

TEST(Test513, CheckSevenNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"1",
                "2", "3",
                "4", "null", "5", "6",
                "null", "null", "null", "null", "7"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_EQ(s.findBottomLeftValue(st.GetRootNodePointer()), 7);
        st.~SmartTreeNode();
    }
}
