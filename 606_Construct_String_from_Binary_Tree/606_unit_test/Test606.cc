#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution606.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test606, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    // test nullptr input
    EXPECT_EQ(s.tree2str(p_root).size(), 0);
}

TEST(Test606, CheckCaseOne) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"1", "2", "3", "4"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.tree2str(st.GetRootNodePointer()), "1(2(4))(3)");
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "3", "null", "4"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.tree2str(st.GetRootNodePointer()), "1(2()(4))(3)");
    }
}
