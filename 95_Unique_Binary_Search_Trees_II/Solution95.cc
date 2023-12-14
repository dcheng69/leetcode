#include <iostream>
#include "Solution95.h"
using namespace std;

vector<TreeNode*> subGenerateTrees(vector<int> &i_vec, int start, int end) {
    vector<TreeNode*> t_vec;
    if (end == start) {
        t_vec.push_back(nullptr);
        return t_vec;
    }

    if (end - start == 1) {
        t_vec.push_back(new TreeNode(i_vec[start]));
        return t_vec;
    }

    // genearte tree
    for (int i = start; i < end; i++) {
        vector<TreeNode*> left_vec = subGenerateTrees(i_vec, start, i);
        vector<TreeNode*> right_vec = subGenerateTrees(i_vec, i + 1, end);

        // generate root node for each combination
        for (int j = 0; j < left_vec.size(); j++) {
            for (int k=0; k < right_vec.size(); k++) {
                TreeNode* root = new TreeNode(i_vec[i]);
                root->left = left_vec[j];
                root->right = right_vec[k];
                t_vec.push_back(root);
            }
        }
    }

    return t_vec;

}

vector<TreeNode*> Solution::generateTrees(int n) {
    vector<int> i_vec(n);
    for (int i=0; i<n; ++i)
        i_vec[i] = i+1;
    return subGenerateTrees(i_vec, 0, i_vec.size());
}

