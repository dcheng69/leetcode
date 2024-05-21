#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution958.h"
#include "TreeNode.h"
using namespace std;

TEST(Test958, CheckTestCase) {
    Solution s;
    vector<string> s_vec;
    {
        s_vec.clear();
        s_vec.assign({"1", "2"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.isCompleteTree(st.GetRootNodePointer()), true);
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "null", "2"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.isCompleteTree(st.GetRootNodePointer()), false);
    }
}
