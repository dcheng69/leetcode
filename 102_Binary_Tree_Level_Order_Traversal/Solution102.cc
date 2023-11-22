#include <iostream>
#include <queue>
#include "Solution102.h"
using namespace std;

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (root == nullptr)
        return ret;

    queue<TreeNode*> tree_que;
    tree_que.push(root);
    while (!tree_que.empty()) {
        int size = tree_que.size();
        vector<int> i_vec;
        for (int i=0; i<size; i++) {
            root = tree_que.front();
            tree_que.pop();
            i_vec.push_back((root->val));

            if (root->left) {
                tree_que.push(root->left);
            }
            if (root->right) {
                tree_que.push(root->right);
            }
        }
        ret.push_back(i_vec);
    }
    return ret;
}
