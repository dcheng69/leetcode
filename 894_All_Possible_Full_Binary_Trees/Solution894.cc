#include "Solution894.h"
#include "TreeNode.h"
using namespace std;

std::vector<TreeNode*> Solution::allPossibleFBT(int n) {
    vector<TreeNode*> tree_p_vec;
    if (n%2 == 0)
        return tree_p_vec;

    if (hash_map.find(n) != hash_map.end()) {
        return hash_map[n];
    }

    if (n == 1) {
        TreeNode* root = new TreeNode(0);
        tree_p_vec.push_back(root);
        return hash_map[1] = tree_p_vec;
    }

    for (int i=1; i<n; i+=2) {
        auto left_tree_p_vec = allPossibleFBT(i);
        auto right_tree_p_vec = allPossibleFBT(n-i-1);
        for (int j=0; j<left_tree_p_vec.size(); j++) {
            for (int k=0; k<right_tree_p_vec.size(); k++) {
                TreeNode* new_root = new TreeNode(0);
                new_root->left = left_tree_p_vec[j];
                new_root->right = right_tree_p_vec[k];
                tree_p_vec.push_back(new_root);
            }
        }
    }

    return hash_map[n] = tree_p_vec;
}
