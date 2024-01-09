#include <iostream>
#include <vector>
#include "Solution113.h"
using namespace std;

vector<vector<int>> Solution::pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> i_vvec;
    if (!root) {
        return i_vvec;
    }

    vector<TreeNode*> t_vec;
    long long sum = 0;
    TreeNode* last_visited = nullptr;

    t_vec.push_back(root);
    sum+=root->val;
    while (!t_vec.empty()) {
        root = t_vec.back();
        if (last_visited && last_visited == root->right) {
            last_visited = root;
            sum-=t_vec.back()->val;
            t_vec.pop_back();
            continue;
        }

        while (root->left && root->left != last_visited) {
            t_vec.push_back(root->left);
            sum+=root->left->val;
            root = root->left;
        }

        if (root->right && root->right != last_visited) {
            t_vec.push_back(root->right);
            sum+=root->right->val;
            continue;
        }

        if (!root->left && !root->right && sum == targetSum) {
            vector<int> i_vec;
            for (auto t : t_vec) {
                i_vec.push_back(t->val);
            }
            i_vvec.push_back(i_vec);
        }
        last_visited = root;
        sum-=t_vec.back()->val;
        t_vec.pop_back();
    }


    return i_vvec;
}
