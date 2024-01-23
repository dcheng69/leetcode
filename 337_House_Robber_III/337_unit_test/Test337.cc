#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution337.h"
#include "PrintX.h"
using namespace std;

TEST(Test337, CheckHourseRobber) {
    Solution s;
    vector<string> s_vec;

    {
        s_vec.clear();
        s_vec.assign({"3", "2", "3", "#", "3", "#", "1"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        PrintTree(st.GetRootNodePointer());
        EXPECT_EQ(s.rob(st.GetRootNodePointer()), 7);
    }
    {
        s_vec.clear();
        s_vec.assign({"3", "4", "5", "1", "3", "#", "1"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        PrintTree(st.GetRootNodePointer());
        EXPECT_EQ(s.rob(st.GetRootNodePointer()), 9);
    }
    {
        s_vec.clear();
        s_vec.assign({"4",
                "1", "#",
                "2", "#", "#", "#",
                "3"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        PrintTree(st.GetRootNodePointer());
        EXPECT_EQ(s.rob(st.GetRootNodePointer()), 7);
    }
    {
        s_vec.clear();
        s_vec.assign({"2",
                "1", "3",
                "#", "4"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "#"));
        PrintTree(st.GetRootNodePointer());
        EXPECT_EQ(s.rob(st.GetRootNodePointer()), 7);
    }
}
