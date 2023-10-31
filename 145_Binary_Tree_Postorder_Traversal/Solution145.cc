#include <iostream>
#include <stack>
#include "Solution145.h"
using namespace std;

vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (root == nullptr)
        return i_vec;

    stack<TreeNode*> tree_stk;
    tree_stk.push(root);
    TreeNode* prev = nullptr;
    bool is_right_visited = false;
    while (!tree_stk.empty()) {
        TreeNode* p_curr_root = tree_stk.top();
        while(p_curr_root->left != nullptr && prev != p_curr_root->left && !is_right_visited) {
            tree_stk.push(p_curr_root->left);
            p_curr_root = p_curr_root->left;
            is_right_visited = false;
        }

        if(p_curr_root->right == nullptr || p_curr_root->right == prev) {
            i_vec.push_back(p_curr_root->val);
            tree_stk.pop();
            prev = p_curr_root;
            is_right_visited = true;
        } else {
            tree_stk.push(p_curr_root->right);
            is_right_visited = false;
        }
    }
    return i_vec;
}
