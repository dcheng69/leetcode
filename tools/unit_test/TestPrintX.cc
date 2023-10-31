#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "TreeNode.h"
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

TEST(Test,PrintTree) {
    // test nullptr input
    TreeNode* p_root = nullptr;
    PrintTree(p_root);
    cout << endl;

    // construct a one node TreeNode
    p_root = new TreeNode(0);
    PrintTree(p_root);
    cout << endl;

    // construct a two node TreeNode with left child
    TreeNode* p_left_child = new TreeNode(1);
    p_root->left = p_left_child;
    PrintTree(p_root);
    cout << endl;

    // construct a two node TreeNode with right child
    TreeNode* p_right_child = new TreeNode(2);
    p_root->left = nullptr; // remove the left child
    p_root->right = p_right_child;
    PrintTree(p_root);
    cout << endl;

    // construct a tree with 3 node TreeNode
    p_root->left = p_left_child;
    PrintTree(p_root);
    cout << endl;

    // construct a tree with 4 node
    TreeNode* p_left_left_child= new TreeNode(3);
    p_left_child->left = p_left_left_child;
    PrintTree(p_root);
    cout << endl;

    // construct a tree with 4 node
    p_left_child->left = nullptr;
    TreeNode* p_left_right_child= new TreeNode(4);
    p_left_child->right = p_left_right_child;
    PrintTree(p_root);
    cout << endl;

    // construct a tree with 5 node
    p_left_child->left = p_left_left_child;
    PrintTree(p_root);
    cout << endl;

    // construct a tree with 5 node
    p_root->left->left= nullptr;
    p_root->left->right= nullptr;
    TreeNode* p_right_left_child = new TreeNode(5);
    p_right_child->left = p_right_left_child;
    PrintTree(p_root);
    cout << endl;

    // cleanning up, take care of mem leak!
    free(p_right_left_child);
    p_right_left_child = nullptr;
    free(p_left_right_child);
    p_left_right_child = nullptr;
    free(p_left_left_child);
    p_left_left_child = nullptr;
    free(p_right_child);
    p_right_child = nullptr;
    free(p_left_child);
    p_left_child = nullptr;
    free(p_root);
    p_root = nullptr;
}
