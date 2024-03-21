#include <iostream>
#include <stack>
#include "Solution652.h"
using namespace std;

std::vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root) {
    // clear the variable
    hash_map.clear();
    t_vec.clear();
    tree2str(root);
    return t_vec;
}

string Solution::tree2str(TreeNode* root) {
    if (!root)
        return string();

    string str_ret = to_string(root->val);
    string str_left, str_right;

    if (!root->left && !root->right) {
        // do nothing
    } else if (root->left && !root->right) {
        // only left
        str_left = tree2str(root->left);
        str_ret = str_ret + "(" + str_left + ")";
    } else {
        // both left and right
        str_left = tree2str(root->left);
        str_right = tree2str(root->right);
        str_ret = str_ret + "(" + str_left + ")(" + str_right + ")";
    }

    hash_map[str_ret]++;
    if (hash_map[str_ret] == 2)
        t_vec.push_back(root);
    return str_ret;
}

std::vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root)
        return i_vec;

    stack<TreeNode*> t_stk;
    t_stk.push(root);
    while (!t_stk.empty()) {
        root = t_stk.top();
        t_stk.pop();
        i_vec.push_back(root->val);
        if (root->right)
            t_stk.push(root->right);
        if (root->left)
            t_stk.push(root->left);
    }
    return i_vec;
}
