#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution1080.h"
#include "TreeNode.h"
using namespace std;

TEST(Test1080, Check) {
    Solution s;
    vector<string> s_vec;
    vector<string> s_vec_cmp;
    {
        s_vec.clear();
        s_vec_cmp.clear();
        s_vec = {"1","2","3","4","-99","-99","7","8","9","-99","-99","12","13","-99","14"};
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        s_vec_cmp = {"1",
                    "2","3",
                    "4","null","null","7",
                    "8","9","null", "null", "null", "null", "null", "14"};
        SmartTreeNode st_cmp(ConstructTreeNode(s_vec_cmp, "null"));
        EXPECT_THAT(ConstructVector(s.sufficientSubset(st.GetRootNodePointer(), 1)),
                ConstructVector(st_cmp.GetRootNodePointer()));
    }
}
