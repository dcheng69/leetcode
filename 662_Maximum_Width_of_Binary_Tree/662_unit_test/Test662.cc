#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution662.h"
using namespace std;

TEST(Test662, CheckTestCases) {
    Solution s;
    vector<string> s_vec;

    // null
    {
        EXPECT_THAT(s.widthOfBinaryTree(nullptr), -1);
    }
    // test case 1
    {
        s_vec.clear();
        s_vec.assign({"1", "3", "2", "5", "3", "null", "9"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));

        EXPECT_THAT(s.widthOfBinaryTree(st.GetRootNodePointer()), 4);
        st.~SmartTreeNode();
    }
    // test case 2
    {
        s_vec.clear();
        s_vec.assign({"1",
                "3", "2",
                "5", "null", "null", "9",
                "6", "null", "null", "null", "null", "null", "7"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));

        EXPECT_THAT(s.widthOfBinaryTree(st.GetRootNodePointer()), 7);
        st.~SmartTreeNode();
    }
}
