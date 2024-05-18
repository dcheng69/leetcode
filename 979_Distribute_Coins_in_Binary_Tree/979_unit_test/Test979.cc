#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution979.h"
#include "TreeNode.h"
using namespace std;

TEST(Test979, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;
    {
        s_vec.clear();
        s_vec = {"3", "0", "0"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.distributeCoins(st.GetRootNodePointer()), 2);
    }
    {
        s_vec.clear();
        s_vec = {"0", "3", "0"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.distributeCoins(st.GetRootNodePointer()), 3);
    }
}
