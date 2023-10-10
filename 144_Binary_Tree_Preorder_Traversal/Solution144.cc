#include <iostream>
#include <stack>
#include "Solution144.h"
using namespace std;

vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    stack<TreeNode*> tree_stk;
    if (root == nullptr) {
        return i_vec;
    }

    // use stack to mock recursive, push right before the left, so left will be traversed ahead
    tree_stk.push(root);
    while (!tree_stk.empty()) {
        TreeNode* temp = tree_stk.top();
        tree_stk.pop();
        i_vec.push_back(temp->val);
        if(temp->right != nullptr) {
            tree_stk.push(temp->right);
        }
        if(temp->left != nullptr) {
            tree_stk.push(temp->left);
        }
    }
    return i_vec;
}
