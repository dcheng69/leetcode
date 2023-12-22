#include <iostream>
#include <stack>
#include "Solution105.h"
using namespace std;

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = nullptr;
    if (preorder.size() != inorder.size()) {
        cerr << "Check input size!" << endl;
        return root;
    }  else if (preorder.size() == 0) {
        return root;
    }

    stack<TreeNode*> nodes;
    root = new TreeNode(preorder[0]);
    nodes.push(root);
    int inorder_index = 0;
    int preorder_index = 1;
    while (preorder_index < preorder.size()) {
        TreeNode* curr = nullptr;
        while (!nodes.empty() && nodes.top()->val == inorder[inorder_index]) {
            curr = nodes.top();
            nodes.pop();
            inorder_index++;
        }

        if (curr) {
            curr->right = new TreeNode(preorder[preorder_index]);
            nodes.push(curr->right);
        } else {
            nodes.top()->left = new TreeNode(preorder[preorder_index]);
            nodes.push(nodes.top()->left);
        }
        preorder_index++;
    }

    return root;
}
