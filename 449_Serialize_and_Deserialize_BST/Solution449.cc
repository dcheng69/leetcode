#include <stack>
#include <iostream>
#include <string>
#include "Solution449.h"
using namespace std;

// Encodes a tree to a single string.
std::string Solution::serialize(TreeNode* root) {
    string str;
    if (!root)
        return str;

    TreeNode* temp_root = root;

    stack<TreeNode*> t_stk;
    // inorderTraversal save to string
    while (root || !t_stk.empty()) {
        while (root) {
            t_stk.push(root);
            root = root->left;
        }

        root = t_stk.top();
        t_stk.pop();
        str += to_string(root->val);
        str += ",";
        root = root->right;
    }

    // seperator $, replace the last comma
    str.pop_back();
    str += "$";

    // restore the root value
    root = temp_root;
    stack<int> i_stk;
    // postorderTraversal save to string
    t_stk.push(root);
    while (!t_stk.empty()) {
        root = t_stk.top();
        t_stk.pop();
        i_stk.push(root->val);

        if (root->left) {
            t_stk.push(root->left);
        }
        if (root->right) {
            t_stk.push(root->right);
        }
    }

    while (!i_stk.empty()) {
        str += to_string(i_stk.top());
        str += ",";
        i_stk.pop();
    }

    // remove the comma at the end
    str.pop_back();

    return str;
}

// Decodes your encoded data to tree.
//TreeNode* deserialize(std::string data);


std::vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if(!root)
        return i_vec;

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

std::vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> i_vec;
    if (!root)
        return i_vec;

    stack<int> i_stk;
    stack<TreeNode*> t_stk;
    t_stk.push(root);
    while (!t_stk.empty()) {
        root = t_stk.top();
        t_stk.pop();
        i_stk.push(root->val);

        if (root->left) {
            t_stk.push(root->left);
        }
        if (root->right) {
            t_stk.push(root->right);
        }
    }

    while (!i_stk.empty()) {
        i_vec.push_back(i_stk.top());
        i_stk.pop();
    }
    return i_vec;
}
