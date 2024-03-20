#include <iostream>
#include <stack>
#include "Solution606.h"
using namespace std;

std::string Solution::tree2str(TreeNode* root) {
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

    return str_ret;
}
