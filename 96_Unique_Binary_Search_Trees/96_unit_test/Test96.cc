#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution96.h"
using namespace std;

TEST(Test96, CheckBasicInput) {
    Solution s;
    ASSERT_THAT(s.numTrees(0), 1);
    ASSERT_THAT(s.numTrees(1), 1);
    ASSERT_THAT(s.numTrees(2), 2);
    ASSERT_THAT(s.numTrees(3), 5);
}
