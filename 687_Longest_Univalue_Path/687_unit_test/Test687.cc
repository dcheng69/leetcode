#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution687.h"
#include "TreeNode.h"
using namespace std;

TEST(Test687, CheckTestCase1) {
    Solution s;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"5",
                "4", "5",
                "1", "1", "#", "5"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        EXPECT_THAT(s.longestUnivaluePath(st.GetRootNodePointer()), 2);
    }
    {
        s_vec.clear();
        s_vec.assign({"5",
                "4", "5",
                "1", "1", "#", "5"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        EXPECT_THAT(s.longestUnivaluePath(st.GetRootNodePointer()), 2);
    }
}
