#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TreeNode.h"
#include "PrintX.h"
using namespace std;
using testing::ElementsAreArray;

TEST(TestTreeNode, TestConstructVector) {
    // test nullptr input
    TreeNode* p_root = nullptr;
    ASSERT_EQ(ConstructVector(p_root).size(), 0);

    // construct a one node TreeNode
    p_root = new TreeNode(0);
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0"}));

    // construct a two node TreeNode with left child
    TreeNode* p_left_child = new TreeNode(1);
    p_root->left = p_left_child;
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "null"}));

    // construct a two node TreeNode with right child
    TreeNode* p_right_child = new TreeNode(2);
    p_root->left = nullptr; // remove the left child
    p_root->right = p_right_child;
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "null", "2"}));

    // construct a tree with 3 node TreeNode
    p_root->left = p_left_child;
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "2"}));

    // construct a tree with 4 node
    TreeNode* p_left_left_child= new TreeNode(3);
    p_left_child->left = p_left_left_child;
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "2", "3", "null", "null", "null"}));

    // construct a tree with 4 node
    p_left_child->left = nullptr;
    TreeNode* p_left_right_child= new TreeNode(4);
    p_left_child->right = p_left_right_child;
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "2", "null", "4", "null", "null"}));

    // construct a tree with 5 node
    p_left_child->left = p_left_left_child;
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "2", "3", "4", "null", "null"}));

    // cleanning up, take care of mem leak!
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

TEST(TestTreeNode, TestConstructTreeNode) {
    TreeNode* p_root = nullptr;
    vector<string> s_vec;
    // test null input
    p_root = ConstructTreeNode(s_vec, "null");
    ASSERT_EQ(p_root, nullptr);

    // construct Tree with one node
    p_root = nullptr;
    s_vec.clear();  // content cleared, capacity remains
    s_vec.assign({"0", "null", "null"});
    p_root = ConstructTreeNode(s_vec, "null");
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0"}));

    // construct two node Tree with left child
    p_root = nullptr;
    s_vec.clear();  // content cleared, capacity remains
    s_vec.assign({"0", "1", "null"});
    p_root = ConstructTreeNode(s_vec, "null");
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "null"}));

    // construct two node Tree with right child
    p_root = nullptr;
    s_vec.clear();  // content cleared, capacity remains
    s_vec.assign({"0", "null", "1"});
    p_root = ConstructTreeNode(s_vec, "null");
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0","null", "1"}));

    // construct three node Tree with left and right child
    p_root = nullptr;
    s_vec.clear();  // content cleared, capacity remains
    s_vec.assign({"0", "1", "2"});
    p_root = ConstructTreeNode(s_vec, "null");
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "2"}));

    // construct three node Tree with left and right child
    p_root = nullptr;
    s_vec.clear();  // content cleared, capacity remains
    s_vec.assign({"0", "null", "1", "null", "null", "2"});
    p_root = ConstructTreeNode(s_vec, "null");
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "null", "1", "null", "null", "2", "null"}));

    // construct four node Tree with last layer has only left child
    p_root = nullptr;
    s_vec.clear();  // content cleared, capacity remains
    s_vec.assign({"0", "1", "2", "3", "null", "null", "null"});
    p_root = ConstructTreeNode(s_vec, "null");
    PrintTree(p_root); cout << endl;
    ASSERT_THAT(ConstructVector(p_root), ElementsAreArray({"0", "1", "2", "3", "null", "null", "null"}));
}

TEST(TestTreeNode, TestSmartTreeNode) {
    vector<string> s_vec{"0", "1", "2", "3", "null", "null", "null"};
    TreeNode* p_root = ConstructTreeNode(s_vec, "null");
    SmartTreeNode s_tree_node(p_root);
    ASSERT_EQ(s_tree_node.GetRootNodePointer(), p_root);

    TreeNode* p_root_need_free = s_tree_node.RebindRootPointer(nullptr);
    ASSERT_EQ(s_tree_node.GetRootNodePointer(), nullptr);

    SmartTreeNode::FreeTree(p_root_need_free);
    p_root_need_free = nullptr;
}

TEST(TestTreeNode, TestMaxTreeDepth) {
    // test nullptr input
    TreeNode* p_root = nullptr;
    ASSERT_THAT(MaxTreeDepth(p_root), 0);

    // construct a one node TreeNode
    p_root = new TreeNode(0);
    ASSERT_THAT(MaxTreeDepth(p_root), 1);
    SmartTreeNode* st = new SmartTreeNode(p_root);

    // construct a two node TreeNode with left child
    TreeNode* p_left_child = new TreeNode(1);
    p_root->left = p_left_child;
    ASSERT_THAT(MaxTreeDepth(p_root), 2);

    // construct a two node TreeNode with right child
    TreeNode* p_right_child = new TreeNode(2);
    p_root->left = nullptr; // remove the left child
    p_root->right = p_right_child;
    ASSERT_THAT(MaxTreeDepth(p_root), 2);

    // construct a tree with 3 node TreeNode
    p_root->left = p_left_child;
    ASSERT_THAT(MaxTreeDepth(p_root), 2);

    // construct a tree with 4 node
    TreeNode* p_left_left_child= new TreeNode(3);
    p_left_child->left = p_left_left_child;
    ASSERT_THAT(MaxTreeDepth(p_root), 3);

    // construct a tree with 4 node
    p_left_child->left = nullptr;
    TreeNode* p_left_right_child= new TreeNode(4);
    p_left_child->right = p_left_right_child;
    ASSERT_THAT(MaxTreeDepth(p_root), 3);

    // construct a tree with 5 node
    p_left_child->left = p_left_left_child;
    ASSERT_THAT(MaxTreeDepth(p_root), 3);

    delete st;
    p_root = nullptr;
}


TEST(TestTreeNode, TestMaxTreeValue) {
    // test nullptr input
    TreeNode* p_root = nullptr;
    ASSERT_THAT(MaxTreeValue(p_root), 0);

    // construct a one node TreeNode
    p_root = new TreeNode(0);
    ASSERT_THAT(MaxTreeValue(p_root), 0);
    SmartTreeNode* st = new SmartTreeNode(p_root);

    // construct a two node TreeNode with left child
    TreeNode* p_left_child = new TreeNode(1);
    p_root->left = p_left_child;
    ASSERT_THAT(MaxTreeValue(p_root), 1);

    // construct a two node TreeNode with right child
    TreeNode* p_right_child = new TreeNode(2);
    p_root->left = nullptr; // remove the left child
    p_root->right = p_right_child;
    ASSERT_THAT(MaxTreeValue(p_root), 2);

    // construct a tree with 3 node TreeNode
    p_root->left = p_left_child;
    ASSERT_THAT(MaxTreeValue(p_root), 2);

    // construct a tree with 4 node
    TreeNode* p_left_left_child= new TreeNode(3);
    p_left_child->left = p_left_left_child;
    ASSERT_THAT(MaxTreeValue(p_root), 3);

    // construct a tree with 4 node
    p_left_child->left = nullptr;
    TreeNode* p_left_right_child= new TreeNode(4);
    p_left_child->right = p_left_right_child;
    ASSERT_THAT(MaxTreeValue(p_root), 4);

    // construct a tree with 5 node
    p_left_child->left = p_left_left_child;
    ASSERT_THAT(MaxTreeValue(p_root), 4);

    // cleanning up, take care of mem leak!
    delete st;
    p_root = nullptr;
}
