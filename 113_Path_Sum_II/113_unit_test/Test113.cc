#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution113.h"
using namespace std;
using testing::UnorderedElementsAreArray;

TEST(Test112, Check) {
    Solution s;
    vector<string> s_vec;
    vector<vector<int>> i_vvec;

    {
        /**
         *             null
         **/
        s_vec.clear();
        s_vec = {};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        i_vvec.clear();
        ASSERT_EQ(s.pathSum(st_compare.GetRootNodePointer(), 0).size(), 0);
        EXPECT_THAT(s.pathSum(st_compare.GetRootNodePointer(), 0), UnorderedElementsAreArray(i_vvec));
    }
    {
        /**
         *             1
         **/
        s_vec.clear();
        s_vec = {"1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        i_vvec.clear();
        i_vvec = {
            {1}
        };
        ASSERT_EQ(s.pathSum(st_compare.GetRootNodePointer(), 1).size(), 1);
        EXPECT_THAT(s.pathSum(st_compare.GetRootNodePointer(), 1), UnorderedElementsAreArray(i_vvec));
    }
    {
        /**
         *             1
         *        2        3
         **/
        s_vec.clear();
        s_vec = {"1", "2", "3"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        i_vvec.clear();
        ASSERT_EQ(s.pathSum(st_compare.GetRootNodePointer(), 5).size(), 0);
        EXPECT_THAT(s.pathSum(st_compare.GetRootNodePointer(), 5), UnorderedElementsAreArray(i_vvec));
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
        "7", "2", "null", "null", "null", "null", "5", "1"};
        SmartTreeNode st_compare(ConstructTreeNode(s_vec, "null"));
        i_vvec.clear();
        i_vvec = {
            {5, 4, 11, 2},
            {5, 8, 4, 5}
        };
        ASSERT_EQ(s.pathSum(st_compare.GetRootNodePointer(), 22).size(), 2);
        EXPECT_THAT(s.pathSum(st_compare.GetRootNodePointer(), 22), UnorderedElementsAreArray(i_vvec));
    }
}
