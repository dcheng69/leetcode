#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution1.h"
using namespace std;
using testing::UnorderedElementsAreArray;

TEST(Test1, CheckTwoInput) {
    Solution s;
    vector<int> i_vec{3, 3};
    EXPECT_THAT(s.twoSum(i_vec, 6), UnorderedElementsAreArray({0, 1}));
}

TEST(Test1, CheckThreeInput) {
    Solution s;
    vector<int> i_vec{3, 2, 4};
    EXPECT_THAT(s.twoSum(i_vec, 5), UnorderedElementsAreArray({0, 1}));
    EXPECT_THAT(s.twoSum(i_vec, 7), UnorderedElementsAreArray({0, 2}));
    EXPECT_THAT(s.twoSum(i_vec, 6), UnorderedElementsAreArray({1, 2}));
}

TEST(Test1, CheckFourInput) {
    Solution s;
    vector<int> i_vec{2, 7, 11, 5};
    EXPECT_THAT(s.twoSum(i_vec, 9), UnorderedElementsAreArray({0, 1}));
    EXPECT_THAT(s.twoSum(i_vec, 13), UnorderedElementsAreArray({0, 2}));
    EXPECT_THAT(s.twoSum(i_vec, 7), UnorderedElementsAreArray({0, 3}));
    EXPECT_THAT(s.twoSum(i_vec, 18), UnorderedElementsAreArray({1, 2}));
    EXPECT_THAT(s.twoSum(i_vec, 12), UnorderedElementsAreArray({1, 3}));
    EXPECT_THAT(s.twoSum(i_vec, 16), UnorderedElementsAreArray({2, 3}));
}
