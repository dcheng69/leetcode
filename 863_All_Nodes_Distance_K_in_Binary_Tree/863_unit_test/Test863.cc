#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution863.h"
using namespace std;
using testing::UnorderedElementsAreArray;

TEST(Test863, CheckTestCase1) {
    Solution s;
    vector<string> s_vec;
    {
    s_vec.assign({"3",
            "5", "1",
            "6", "2", "0", "8",
            "null", "null", "7", "4"});
    SmartTreeNode st(ConstructTreeNode(s_vec, "null"));
    TreeNode* root = st.GetRootNodePointer();
    TreeNode* target = root->left;
    EXPECT_THAT(s.distanceK(root, target, 0), UnorderedElementsAreArray({5}));
    EXPECT_THAT(s.distanceK(root, target, 1), UnorderedElementsAreArray({6, 2, 3}));
    EXPECT_THAT(s.distanceK(root, target, 2), UnorderedElementsAreArray({1, 4, 7}));
    EXPECT_THAT(s.distanceK(root, target, 3), UnorderedElementsAreArray({0, 8}));
    EXPECT_EQ(s.distanceK(root, target, 4).size(), 0);
    }
}
