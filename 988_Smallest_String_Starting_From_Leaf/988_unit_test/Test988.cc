#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution988.h"
#include "TreeNode.h"
using namespace std;

TEST(Test988, CheckStandardTestCase) {
    Solution s;
    vector<string> s_vec;
    {
        s_vec.clear();
        s_vec = {"0","1","2","3","4","3","4"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.smallestFromLeaf(st.GetRootNodePointer()), "dba");
    }
    {
        s_vec.clear();
        s_vec = {"25","1","3","1","3","0","2"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.smallestFromLeaf(st.GetRootNodePointer()), "adz");
    }
    {
        s_vec.clear();
        s_vec = {"2","2","1","null","1","0","null","0"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        EXPECT_THAT(s.smallestFromLeaf(st.GetRootNodePointer()), "abc");
    }
}
