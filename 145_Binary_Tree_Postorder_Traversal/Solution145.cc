#include <iostream>
#include <stack>
#include "Solution145.h"
using namespace std;
#define SOLUTION4

#ifdef SOLUTION1
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
#endif
#ifdef SOLUTION2
// traverse root, right, left, then save the output to a stack
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (root == nullptr)
        return i_vec;

    stack<TreeNode*> stk1, stk2;

    stk1.push(root);
    while(!stk1.empty()) {
        TreeNode* curr_root = stk1.top();
        stk1.pop();
        stk2.push(curr_root);

        if (curr_root->left != nullptr)
            stk1.push(curr_root->left);

        if (curr_root->right != nullptr)
            stk1.push(curr_root->right);
    }

    while (!stk2.empty()) {
        TreeNode* curr_root = stk2.top();
        stk2.pop();
        i_vec.push_back(curr_root->val);
    }
    return i_vec;
}
#endif
#ifdef SOLUTION3
// using one stack and root node
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (root == nullptr)
        return i_vec;

    stack<TreeNode*> stk;
    TreeNode* prev = nullptr;
    while (!stk.empty() || root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }

        root = stk.top();
        if (root->right && prev != root->right) {
            root = root->right;
        } else {
            root = stk.top();
            stk.pop();
            i_vec.push_back(root->val);
            prev = root;
            root = nullptr;
        }
    }
    return i_vec;
}
#endif
#ifdef SOLUTION4
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (root == nullptr)
        return i_vec;

    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* prev = nullptr;
    while(!stk.empty()){
        TreeNode* curr_root = stk.top();

        if ((!curr_root->left && !curr_root->right) || (prev && (prev == curr_root->left || prev == curr_root->right))) {
            i_vec.push_back(curr_root->val);
            stk.pop();
            prev = curr_root;
        } else {
            if (curr_root->right) {
                stk.push(curr_root->right);
            }

            if (curr_root->left) {
                stk.push(curr_root->left);
            }
        }
    }
    return i_vec;
}
#endif
