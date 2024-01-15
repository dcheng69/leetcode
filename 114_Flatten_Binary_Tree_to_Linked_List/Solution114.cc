#include <iostream>
#include <stack>
#include "Solution114.h"
using namespace std;

void Solution::flatten(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> t_stk;
    t_stk.push(root);
    TreeNode* last_root = nullptr;
    while (!t_stk.empty()) {
        root = t_stk.top();
        t_stk.pop();

        if (last_root) {
            last_root->right = root;
            last_root->left = nullptr;
        }
        last_root = root;

        if (root->right)
            t_stk.push(root->right);

        if (root->left)
            t_stk.push(root->left);
    }
}
