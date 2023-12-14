#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Solution95.h"
#include "PrintX.h"
#include "TreeNode.h"
using namespace std;
using testing::UnorderedElementsAreArray;

vector<vector<string>> get2DResult(vector<TreeNode*> trees) {
    vector<vector<string>> ret;
    for (int i=0; i<trees.size(); i++) {
        TreeNode* root = trees[i];
        vector<string> s_vec = ConstructVector(root);
        ret.push_back(s_vec);
        Print("vector generated", s_vec);
    }
    return ret;
}

TEST(Test95, CheckSize) {
    Solution s;
    ASSERT_EQ(s.generateTrees(0).size(), 1);
    ASSERT_EQ(s.generateTrees(1).size(), 1);
    ASSERT_EQ(s.generateTrees(2).size(), 2);
    ASSERT_EQ(s.generateTrees(3).size(), 5);
}

TEST(Test95, CheckOneResult) {
    Solution s;
    vector<vector<string>> s_vec;

    s_vec.clear();
    s_vec = {{"1"}};
    EXPECT_THAT(get2DResult(s.generateTrees(1)), UnorderedElementsAreArray(s_vec));
}

TEST(Test95, CheckTwoResult) {
    Solution s;
    vector<vector<string>> s_vec;

    s_vec.clear();
    s_vec = {
        {"2", "1", "null"},
        {"1", "null", "2"}};
    EXPECT_THAT(get2DResult(s.generateTrees(2)), UnorderedElementsAreArray(s_vec));
}


TEST(Test95, CheckThreeResult) {
    Solution s;
    vector<vector<string>> s_vec;

    s_vec.clear();
    s_vec = {
        {"2", "1", "3"},
        {"1", "null", "2", "null", "null", "null", "3"},
        {"1", "null", "3", "null", "null", "2", "null"},
        {"3", "1", "null", "null", "2", "null", "null"},
        {"3", "2", "null", "1", "null", "null", "null"}};
    EXPECT_THAT(get2DResult(s.generateTrees(3)), UnorderedElementsAreArray(s_vec));
}
