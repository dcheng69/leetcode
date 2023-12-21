#include <iostream>
#include <stack>
#include "Solution106.h"
using namespace std;
#define SOLUTION_2

#ifdef SOLUTION_1
TreeNode* subBuildTree(vector<int>& inorder, int in_s, int in_e, \
        vector<int>& postorder, int po_s, int po_e) {
    if (in_s > in_e && po_s > po_e)
        return nullptr;

    if (in_s == in_e && po_s == po_e)
        return new TreeNode(inorder[in_s]);

    if (in_e - in_s != po_e - po_s) {
        cerr << "inorder vector does not match postorder size!";
        return nullptr;
    }

    TreeNode* root = new TreeNode(postorder[po_e]);

    int root_index_inorder = -1;
    for (int i=0; i<inorder.size(); ++i) {
        if (inorder[i] == postorder[po_e])
            root_index_inorder = i;
    }
    if (root_index_inorder == -1) {
        cerr << "could not find the index of value:" << postorder[po_e] << "!" << endl;
        return nullptr;
    }

    // left child tree
    int left_in_s = in_s;
    int left_in_e = root_index_inorder - 1;
    int left_size = left_in_e - left_in_s + 1;
    int left_po_s = po_s;
    int left_po_e = po_s + left_size - 1;

    // right child tree
    int right_size = in_e - root_index_inorder;
    int right_in_s = root_index_inorder + 1;
    int right_in_e = in_e;
    int right_po_s = po_e - right_size;
    int right_po_e = po_e - 1;

    root->left = subBuildTree(inorder, left_in_s, left_in_e, \
            postorder, left_po_s, left_po_e);
    root->right = subBuildTree(inorder, right_in_s, right_in_e, \
            postorder, right_po_s, right_po_e);

    return root;
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    return subBuildTree(inorder, 0, inorder.size() - 1, \
            postorder, 0, postorder.size() - 1 );
}
#endif

#ifdef SOLUTION_2
TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) {
        return nullptr;
    }

    int in_size = inorder.size();
    int po_size = postorder.size();

    TreeNode* root = new TreeNode(postorder[po_size - 1]);
    stack<TreeNode*> nodes;
    nodes.push(root);

    int inIndex = in_size - 1;
    int poIndex = po_size - 2;

    while (poIndex >= 0) {
        TreeNode* curr = nullptr;
        while (!nodes.empty() && nodes.top()->val == inorder[inIndex]) {
            curr = nodes.top();
            nodes.pop();
            inIndex--;
        }

        TreeNode* newNode = new TreeNode(postorder[poIndex]);
        if (curr) {
            curr->left = newNode;
        } else {
            nodes.top()->right = newNode;
        }

        nodes.push(newNode);
        poIndex--;
    }

    return root;
}
#endif
