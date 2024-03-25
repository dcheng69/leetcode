#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Solution655.h"
#include "TreeNode.h"
using namespace std;
using testing::UnorderedElementsAreArray;

TEST(Test655, CheckTestCases) {
    Solution s;
    vector<string> s_vec;

    // null
    {
        vector<vector<string>> s_vec_vec = s.printTree(nullptr);
        vector<vector<string>> s_vec_vec_cmp = {};
        EXPECT_THAT(s_vec_vec, UnorderedElementsAreArray(s_vec_vec_cmp));
    }
    // two nodes
    {
        s_vec.clear();
        s_vec.assign({"1", "2"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));

        vector<vector<string>> s_vec_vec = s.printTree(st.GetRootNodePointer());
        vector<vector<string>> s_vec_vec_cmp = {{"", "1", ""},{"2", "", ""}};
        EXPECT_THAT(s_vec_vec, UnorderedElementsAreArray(s_vec_vec_cmp));
        st.~SmartTreeNode();
    }

    // Four nodes
    {
        s_vec.clear();
        s_vec.assign({"1", "2", "3", "null", "4"});
        SmartTreeNode st(ConstructTreeNode(s_vec, "null"));

        vector<vector<string>> s_vec_vec = s.printTree(st.GetRootNodePointer());
        vector<vector<string>> s_vec_vec_cmp = {{"","","","1","","",""},{"","2","","","","3",""}, {"","","4","","","",""}};
        EXPECT_THAT(s_vec_vec, UnorderedElementsAreArray(s_vec_vec_cmp));
        st.~SmartTreeNode();
    }
}
