#include <iostream>
#include <vector>
#include <string>
#include "PrintX.h"
#include "TreeNode.h"
using namespace std;

int main(int argc, char* argv[]) {
    // test nullptr input
    TreeNode* p_root = nullptr;
    MaxTreeValue(p_root);

    // construct a one node TreeNode
    p_root = new TreeNode(0);
    MaxTreeValue(p_root);

    // construct a two node TreeNode with left child
    TreeNode* p_left_child = new TreeNode(1);
    p_root->left = p_left_child;
    MaxTreeValue(p_root);

    // construct a two node TreeNode with right child
    TreeNode* p_right_child = new TreeNode(2);
    p_root->left = nullptr; // remove the left child
    p_root->right = p_right_child;
    MaxTreeValue(p_root);

    // construct a tree with 3 node TreeNode
    p_root->left = p_left_child;
    MaxTreeValue(p_root);

    // construct a tree with 4 node
    TreeNode* p_left_left_child= new TreeNode(3);
    p_left_child->left = p_left_left_child;
    MaxTreeValue(p_root);

    // construct a tree with 4 node
    p_left_child->left = nullptr;
    TreeNode* p_left_right_child= new TreeNode(4);
    p_left_child->right = p_left_right_child;
    MaxTreeValue(p_root);

    // construct a tree with 5 node
    p_left_child->left = p_left_left_child;
    MaxTreeValue(p_root);

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
    return 0;
}
