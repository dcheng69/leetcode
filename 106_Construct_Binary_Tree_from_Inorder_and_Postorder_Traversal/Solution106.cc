#include <iostream>
#include "Solution106.h"
using namespace std;

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
