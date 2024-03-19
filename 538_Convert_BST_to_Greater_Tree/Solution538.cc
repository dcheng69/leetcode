#include <iostream>
#include <vector>
#include <stack>
#include "Solution538.h"
#include "TreeNode.h"
using namespace std;

TreeNode* Solution::convertBST(TreeNode* root) {
    if (!root)
        return nullptr;

    int sum = 0;
    stack<TreeNode*> t_stk;
    TreeNode* temp = root;
    while (temp || !t_stk.empty()) {
        while (temp) {
            t_stk.push(temp);
            temp = temp->right;
        }

        temp = t_stk.top();
        t_stk.pop();
        sum += temp->val;
        temp->val = sum; // update the value from here
        temp = temp->left;
    }

    return root;
}

/**
 * Nonrecursive reverse inorder Traversal (right, root, left)
 */
vector<int> Solution::reverseInorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root)
        return i_vec;

    stack<TreeNode*> t_stk;
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->right;
        }

        root = t_stk.top();
        t_stk.pop();
        i_vec.push_back(root->val);
        root = root->left;
    }
    return i_vec;
}
