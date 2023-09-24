#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "PrintX.h"
using namespace std;

TEST(TestPrintX, TestOuputFormat) {
    string name{"test"};
    vector<int> i_vec{3, 4, 2};
    EXPECT_THAT(PrintToString(name, i_vec), testing::StrEq("test:\t3 4 2 \n"));
}

TEST(TestPrintX, TestFloatInput) {
    string name{"test"};
    vector<float> f_vec{1.2, 3.4};
    EXPECT_THAT(PrintToString(name, f_vec), testing::StrEq("test:\t1.2 3.4 \n"));
}

TEST(TestPrintX, TestDoubleInput) {
    string name{"test"};
    vector<double> d_vec{1.2, 3.4};
    EXPECT_THAT(PrintToString(name, d_vec), testing::StrEq("test:\t1.2 3.4 \n"));
}

TEST(TestPrintX, TestStringInput) {
    string name{"test"};
    vector<string> s_vec{"abc", "def"};
    EXPECT_THAT(PrintToString(name, s_vec), testing::StrEq("test:\tabc def \n"));
}

TEST(TestPrintX, TestCharInput) {
    string name{"test"};
    vector<char> c_vec{'a', 'b', 'c'};
    EXPECT_THAT(PrintToString(name, c_vec), testing::StrEq("test:\ta b c \n"));
}

TEST(TestPrintX, TestEmptyInput) {
    string name;
    vector<int> i_vec;
    EXPECT_THAT(PrintToString(name, i_vec), testing::StrEq(""));
}
