#include <stack>
#include <iostream>
#include "Solution230.h"
using namespace std;

vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if(!root) {
        return i_vec;
    }

    stack<TreeNode*> t_stk;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        i_vec.push_back(root->val);
        root = root->right;
    }
    return i_vec;
}

int Solution::kthSmallest(TreeNode* root, int k) {
    int ret = 0;
    stack<TreeNode*> t_stk;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        ret = root->val;
        root = root->right;
        if (--k == 0) {
            break;
        }
    }
    return ret;
}
