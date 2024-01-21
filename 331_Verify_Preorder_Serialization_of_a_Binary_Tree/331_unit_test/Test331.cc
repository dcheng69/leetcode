#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Solution331.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(Test331, CheckZeroNode) {
    Solution s;

    // test nullptr input
    EXPECT_EQ(s.isValidSerialization("#"), true);
}

TEST(Test331, CheckMultipleNode) {
    Solution s;

    {
        EXPECT_EQ(s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"), true);
    }
    {
        EXPECT_EQ(s.isValidSerialization("1,#"), false);
    }
    {
        EXPECT_EQ(s.isValidSerialization("9,#,#,1"), false);
    }
}
