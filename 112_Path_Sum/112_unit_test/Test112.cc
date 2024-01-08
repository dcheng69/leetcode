#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution112.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test112, Check) {
    Solution s;
    vector<string> s_vec;

    {
        /**
         *             null
         **/
        s_vec.clear();
        s_vec = {};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        EXPECT_EQ(s.hasPathSum(st_compare.GetRootNodePointer(), 0), false);
    }
    {
        /**
         *             1
         *        2        3
         **/
        s_vec.clear();
        s_vec = {"1", "2", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        EXPECT_EQ(s.hasPathSum(st_compare.GetRootNodePointer(), 5), false);
    }
    {
        /**
         *                  5
         *            4           8
         *      11            13      4
         *    7   2                       1
         **/
        s_vec.clear();
        s_vec = {"5",
            "4", "8",
        "11", "null", "13", "4",
        "7", "2", "null", "null", "null", "null", "null", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        EXPECT_EQ(s.hasPathSum(st_compare.GetRootNodePointer(), 22), true);
    }
}
