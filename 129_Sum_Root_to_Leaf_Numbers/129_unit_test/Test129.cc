#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution129.h"
using namespace std;
TEST(Test129, CheckZeroNode) {
    Solution s;
    TreeNode* p_root = nullptr;
    vector<string> s_vec;
    EXPECT_EQ(s.sumNumbers(p_root), 0);
}

TEST(Test129, CheckOneNode) {
    Solution s;
    vector<string> s_vec;

    // test one node input
    {
        s_vec.clear();
        s_vec.assign({"0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 0);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 1);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"9"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 9);
        st.~SmartTreeNode();
    }
}

TEST(Test129, CheckTwoNode) {
    Solution s;
    vector<string> s_vec;

    // test two node input
    {
        s_vec.clear();
        s_vec.assign({"0", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 1);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 1);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "null", "0"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 10);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"9", "null", "9"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 99);
        st.~SmartTreeNode();
    }
}

TEST(Test129, CheckThreeNode) {
    Solution s;
    vector<string> s_vec;

    // test three node input
    {
        s_vec.clear();
        s_vec.assign({"0", "2", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 3);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "3"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 25);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"0", "null", "2", "null", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 21);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "null", "2", "null", "null", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 121);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 121);
        st.~SmartTreeNode();
    }
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "null", "null", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 121);
        st.~SmartTreeNode();
    }
}

TEST(Test129, CheckXNode) {
    Solution s;
    vector<string> s_vec;

    // test three node input
    {
        s_vec.clear();
        s_vec.assign({"4", "9", "0", "5", "1"});
        SmartTreeNode st{ConstructTreeNode(s_vec, "null")};
        EXPECT_THAT(s.sumNumbers(st.GetRootNodePointer()), 1026);
        st.~SmartTreeNode();
    }
}
