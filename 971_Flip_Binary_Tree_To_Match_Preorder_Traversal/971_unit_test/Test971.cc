#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution971.h"
#include "TreeNode.h"
using namespace std;

TEST(Test971, CheckUseCases) {
    Solution s;
    vector<string> s_vec;
    {
        s_vec.clear();
        s_vec.assign({"1", "2"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        vector<int> voyage{2,1};
        EXPECT_THAT(s.flipMatchVoyage(st.GetRootNodePointer(), voyage), testing::ElementsAreArray({-1}));
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "3"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        vector<int> voyage{1,3,2};
        EXPECT_THAT(s.flipMatchVoyage(st.GetRootNodePointer(), voyage), testing::ElementsAreArray({1}));
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "3"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        vector<int> voyage{1,2,3};
        EXPECT_THAT(s.flipMatchVoyage(st.GetRootNodePointer(), voyage).size(), 0);
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "null", "2"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
        vector<int> voyage{1,2};
        EXPECT_THAT(s.flipMatchVoyage(st.GetRootNodePointer(), voyage).size(), 0);
    }
}
